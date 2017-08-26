// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// convertToSccs
List convertToSccs(const List& cases, const List& eras, double outcomeId, int naivePeriod, bool firstOutcomeOnly, bool includeAge, int ageOffset, NumericMatrix ageDesignMatrix, double minAge, double maxAge, bool includeSeason, NumericMatrix seasonDesignMatrix, List& covariateSettingsList, bool eventDependentObservation, List& censorModel);
RcppExport SEXP _SelfControlledCaseSeries_convertToSccs(SEXP casesSEXP, SEXP erasSEXP, SEXP outcomeIdSEXP, SEXP naivePeriodSEXP, SEXP firstOutcomeOnlySEXP, SEXP includeAgeSEXP, SEXP ageOffsetSEXP, SEXP ageDesignMatrixSEXP, SEXP minAgeSEXP, SEXP maxAgeSEXP, SEXP includeSeasonSEXP, SEXP seasonDesignMatrixSEXP, SEXP covariateSettingsListSEXP, SEXP eventDependentObservationSEXP, SEXP censorModelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type cases(casesSEXP);
    Rcpp::traits::input_parameter< const List& >::type eras(erasSEXP);
    Rcpp::traits::input_parameter< double >::type outcomeId(outcomeIdSEXP);
    Rcpp::traits::input_parameter< int >::type naivePeriod(naivePeriodSEXP);
    Rcpp::traits::input_parameter< bool >::type firstOutcomeOnly(firstOutcomeOnlySEXP);
    Rcpp::traits::input_parameter< bool >::type includeAge(includeAgeSEXP);
    Rcpp::traits::input_parameter< int >::type ageOffset(ageOffsetSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type ageDesignMatrix(ageDesignMatrixSEXP);
    Rcpp::traits::input_parameter< double >::type minAge(minAgeSEXP);
    Rcpp::traits::input_parameter< double >::type maxAge(maxAgeSEXP);
    Rcpp::traits::input_parameter< bool >::type includeSeason(includeSeasonSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type seasonDesignMatrix(seasonDesignMatrixSEXP);
    Rcpp::traits::input_parameter< List& >::type covariateSettingsList(covariateSettingsListSEXP);
    Rcpp::traits::input_parameter< bool >::type eventDependentObservation(eventDependentObservationSEXP);
    Rcpp::traits::input_parameter< List& >::type censorModel(censorModelSEXP);
    rcpp_result_gen = Rcpp::wrap(convertToSccs(cases, eras, outcomeId, naivePeriod, firstOutcomeOnly, includeAge, ageOffset, ageDesignMatrix, minAge, maxAge, includeSeason, seasonDesignMatrix, covariateSettingsList, eventDependentObservation, censorModel));
    return rcpp_result_gen;
END_RCPP
}
// simulateSccsOutcomes
List simulateSccsOutcomes(const List& cases, const List& eras, const std::vector<double>& baselineRates, const List& eraRrs, bool includeAge, int ageOffset, std::vector<double> ageRrs, bool includeSeasonality, std::vector<double> seasonRrs);
RcppExport SEXP _SelfControlledCaseSeries_simulateSccsOutcomes(SEXP casesSEXP, SEXP erasSEXP, SEXP baselineRatesSEXP, SEXP eraRrsSEXP, SEXP includeAgeSEXP, SEXP ageOffsetSEXP, SEXP ageRrsSEXP, SEXP includeSeasonalitySEXP, SEXP seasonRrsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type cases(casesSEXP);
    Rcpp::traits::input_parameter< const List& >::type eras(erasSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type baselineRates(baselineRatesSEXP);
    Rcpp::traits::input_parameter< const List& >::type eraRrs(eraRrsSEXP);
    Rcpp::traits::input_parameter< bool >::type includeAge(includeAgeSEXP);
    Rcpp::traits::input_parameter< int >::type ageOffset(ageOffsetSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type ageRrs(ageRrsSEXP);
    Rcpp::traits::input_parameter< bool >::type includeSeasonality(includeSeasonalitySEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type seasonRrs(seasonRrsSEXP);
    rcpp_result_gen = Rcpp::wrap(simulateSccsOutcomes(cases, eras, baselineRates, eraRrs, includeAge, ageOffset, ageRrs, includeSeasonality, seasonRrs));
    return rcpp_result_gen;
END_RCPP
}
// testEwad
double testEwad(std::vector<double> p, double present, double astart, double aend, double start, double end);
RcppExport SEXP _SelfControlledCaseSeries_testEwad(SEXP pSEXP, SEXP presentSEXP, SEXP astartSEXP, SEXP aendSEXP, SEXP startSEXP, SEXP endSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<double> >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type present(presentSEXP);
    Rcpp::traits::input_parameter< double >::type astart(astartSEXP);
    Rcpp::traits::input_parameter< double >::type aend(aendSEXP);
    Rcpp::traits::input_parameter< double >::type start(startSEXP);
    Rcpp::traits::input_parameter< double >::type end(endSEXP);
    rcpp_result_gen = Rcpp::wrap(testEwad(p, present, astart, aend, start, end));
    return rcpp_result_gen;
END_RCPP
}
// testEwid
double testEwid(std::vector<double> p, double present, double astart, double aend, double start, double end);
RcppExport SEXP _SelfControlledCaseSeries_testEwid(SEXP pSEXP, SEXP presentSEXP, SEXP astartSEXP, SEXP aendSEXP, SEXP startSEXP, SEXP endSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<double> >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type present(presentSEXP);
    Rcpp::traits::input_parameter< double >::type astart(astartSEXP);
    Rcpp::traits::input_parameter< double >::type aend(aendSEXP);
    Rcpp::traits::input_parameter< double >::type start(startSEXP);
    Rcpp::traits::input_parameter< double >::type end(endSEXP);
    rcpp_result_gen = Rcpp::wrap(testEwid(p, present, astart, aend, start, end));
    return rcpp_result_gen;
END_RCPP
}
// testEgad
double testEgad(std::vector<double> p, double present, double astart, double aend, double start, double end);
RcppExport SEXP _SelfControlledCaseSeries_testEgad(SEXP pSEXP, SEXP presentSEXP, SEXP astartSEXP, SEXP aendSEXP, SEXP startSEXP, SEXP endSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<double> >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type present(presentSEXP);
    Rcpp::traits::input_parameter< double >::type astart(astartSEXP);
    Rcpp::traits::input_parameter< double >::type aend(aendSEXP);
    Rcpp::traits::input_parameter< double >::type start(startSEXP);
    Rcpp::traits::input_parameter< double >::type end(endSEXP);
    rcpp_result_gen = Rcpp::wrap(testEgad(p, present, astart, aend, start, end));
    return rcpp_result_gen;
END_RCPP
}
// testEgid
double testEgid(std::vector<double> p, double present, double astart, double aend, double start, double end);
RcppExport SEXP _SelfControlledCaseSeries_testEgid(SEXP pSEXP, SEXP presentSEXP, SEXP astartSEXP, SEXP aendSEXP, SEXP startSEXP, SEXP endSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<double> >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type present(presentSEXP);
    Rcpp::traits::input_parameter< double >::type astart(astartSEXP);
    Rcpp::traits::input_parameter< double >::type aend(aendSEXP);
    Rcpp::traits::input_parameter< double >::type start(startSEXP);
    Rcpp::traits::input_parameter< double >::type end(endSEXP);
    rcpp_result_gen = Rcpp::wrap(testEgid(p, present, astart, aend, start, end));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_SelfControlledCaseSeries_convertToSccs", (DL_FUNC) &_SelfControlledCaseSeries_convertToSccs, 15},
    {"_SelfControlledCaseSeries_simulateSccsOutcomes", (DL_FUNC) &_SelfControlledCaseSeries_simulateSccsOutcomes, 9},
    {"_SelfControlledCaseSeries_testEwad", (DL_FUNC) &_SelfControlledCaseSeries_testEwad, 6},
    {"_SelfControlledCaseSeries_testEwid", (DL_FUNC) &_SelfControlledCaseSeries_testEwid, 6},
    {"_SelfControlledCaseSeries_testEgad", (DL_FUNC) &_SelfControlledCaseSeries_testEgad, 6},
    {"_SelfControlledCaseSeries_testEgid", (DL_FUNC) &_SelfControlledCaseSeries_testEgid, 6},
    {NULL, NULL, 0}
};

RcppExport void R_init_SelfControlledCaseSeries(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
