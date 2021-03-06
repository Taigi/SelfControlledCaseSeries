library(SelfControlledCaseSeries)
options(fftempdir = "s:/fftemp")
settings <- createSccsSimulationSettings(includeAgeEffect = TRUE, includeSeasonality = TRUE)

sccsData <- simulateSccsData(1000, settings)

ageSettings <- createAgeSettings(includeAge = TRUE, ageKnots = 5)

seasonalitySettings <- createSeasonalitySettings(includeSeasonality = TRUE, seasonKnots = 5)
covarSettings <- createCovariateSettings(label = "Exposure of interest",
                                         includeCovariateIds = c(1, 2),
                                         start = 0,
                                         end = 0,
                                         addExposedDaysToEnd = TRUE)

sccsEraData <- createSccsEraData(sccsData,
                                 naivePeriod = 0,
                                 firstOutcomeOnly = FALSE,
                                 covariateSettings = covarSettings,
                                 ageSettings = ageSettings,
                                 seasonalitySettings = seasonalitySettings,
                                 minCasesForAgeSeason = 500)

length(unique(sccsEraData$outcomes$stratumId))

model <- fitSccsModel(sccsEraData, control = createControl(cvType = "auto",
                                                           selectorType = "byPid",
                                                           startingVariance = 0.1,
                                                           noiseLevel = "quiet",
                                                           threads = 4))

summary(model)
plotSeasonality(model)
plotAgeEffect(model)

### Plot simulated seasonality ###
estimates <- model$estimates
estimates <- estimates[estimates$covariateId >= 200 & estimates$covariateId < 300, ]
splineCoefs <- c(0, estimates$logRr)
seasonKnots <- model$metaData$seasonality$seasonKnots
season <- seq(min(seasonKnots), max(seasonKnots), length.out = 100)
seasonDesignMatrix <- cyclicSplineDesign(season, seasonKnots)
logRr <- apply(seasonDesignMatrix %*% splineCoefs, 1, sum)
logRr <- logRr - mean(logRr)
rr <- exp(logRr)
data <- data.frame(x = season, y = rr, type = "estimated")

x <- 1:365
y <- sccsData$metaData$seasonFun(x)
y <- y - mean(y)
y <- exp(y)
x <- 1 + x * 11/365
data <- rbind(data, data.frame(x = x, y = y, type = "simulated"))
breaks <- c(0.1, 0.25, 0.5, 1, 2, 4, 6, 8, 10)
seasonBreaks <- 1:12
rrLim <- c(0.1, 10)
theme <- ggplot2::element_text(colour = "#000000", size = 12)
themeRA <- ggplot2::element_text(colour = "#000000", size = 12, hjust = 1)
plot <- ggplot2::ggplot(data, ggplot2::aes(x = x, y = y, group = type, color = type)) +
        ggplot2::geom_hline(yintercept = breaks, colour = "#AAAAAA", lty = 1, size = 0.2) +
        ggplot2::geom_line(lwd = 1) +
        ggplot2::scale_x_continuous("Month", breaks = seasonBreaks, labels = seasonBreaks) +
        ggplot2::scale_y_continuous("Relative risk",
                                    lim = rrLim,
                                    trans = "log10",
                                    breaks = breaks,
                                    labels = breaks) +
        ggplot2::scale_color_manual(values = c(rgb(0.8, 0, 0, alpha = 0.5),
                                               rgb(0, 0, 0.8, alpha = 0.5))) +
        ggplot2::theme(panel.grid.minor = ggplot2::element_blank(),
                       panel.background = ggplot2::element_rect(fill = "#FAFAFA", colour = NA),
                       panel.grid.major = ggplot2::element_blank(),
                       axis.ticks = ggplot2::element_blank(),
                       axis.text.y = themeRA,
                       axis.text.x = theme,
                       strip.text.x = theme,
                       strip.background = ggplot2::element_blank(),
                       legend.title = ggplot2::element_blank(),
                       legend.position = "top")
ggplot2::ggsave("s:/temp/season.png", plot, width = 5, height = 4, dpi = 300)


### Plot simulated age effect ###
estimates <- model$estimates
estimates <- estimates[estimates$covariateId >= 100 & estimates$covariateId < 200, ]
splineCoefs <- c(0, estimates$logRr)
ageKnots <- model$metaData$age$ageKnots
age <- seq(min(ageKnots), max(ageKnots), length.out = 100)
ageDesignMatrix <- splines::bs(age,
                               knots = ageKnots[2:(length(ageKnots) - 1)],
                               Boundary.knots = ageKnots[c(1, length(ageKnots))])
logRr <- apply(ageDesignMatrix %*% splineCoefs, 1, sum)
logRr <- logRr - mean(logRr)
rr <- exp(logRr)
data <- data.frame(x = age, y = rr, type = "estimated")

x <- age
y <- sccsData$metaData$ageFun(x)
y <- y - mean(y)
y <- exp(y)
data <- rbind(data, data.frame(x = x, y = y, type = "simulated"))
breaks <- c(0.1, 0.25, 0.5, 1, 2, 4, 6, 8, 10)
ageLabels <- unique(round(age/3652.5) * 10)
ageBreaks <- ageLabels * 3652.5
rrLim <- c(0.1, 10)
theme <- ggplot2::element_text(colour = "#000000", size = 12)
themeRA <- ggplot2::element_text(colour = "#000000", size = 12, hjust = 1)
plot <- ggplot2::ggplot(data, ggplot2::aes(x = x, y = y, group = type, color = type)) +
        ggplot2::geom_hline(yintercept = breaks, colour = "#AAAAAA", lty = 1, size = 0.2) +
        ggplot2::geom_line(lwd = 1) +
        ggplot2::scale_x_continuous("Month", breaks = ageBreaks, labels = ageLabels) +
        ggplot2::scale_y_continuous("Relative risk",
                                    lim = rrLim,
                                    trans = "log10",
                                    breaks = breaks,
                                    labels = breaks) +
        ggplot2::scale_color_manual(values = c(rgb(0.8, 0, 0, alpha = 0.5),
                                               rgb(0, 0, 0.8, alpha = 0.5))) +
        ggplot2::theme(panel.grid.minor = ggplot2::element_blank(),
                       panel.background = ggplot2::element_rect(fill = "#FAFAFA", colour = NA),
                       panel.grid.major = ggplot2::element_blank(),
                       axis.ticks = ggplot2::element_blank(),
                       axis.text.y = themeRA,
                       axis.text.x = theme,
                       strip.text.x = theme,
                       strip.background = ggplot2::element_blank(),
                       legend.title = ggplot2::element_blank(),
                       legend.position = "top")
ggplot2::ggsave("s:/temp/age.png", plot, width = 5, height = 4, dpi = 300)
