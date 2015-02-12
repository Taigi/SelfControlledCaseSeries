/*
 * @file SccsConvert.h
 *
 * This file is part of SelfControlledCaseSeries
 *
 * Copyright 2014 Observational Health Data Sciences and Informatics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SCCSCONVERTER_H_
#define SCCSCONVERTER_H_

#include <Rcpp.h>
#include "PersonDataIterator.h"
using namespace Rcpp;

namespace ohdsi {
	namespace sccs {

		struct ConcomitantEra {
			ConcomitantEra() :
					start(0), end(0) {
			}

			ConcomitantEra(Era era) {
				start = era.start;
				end = era.end;
				conceptIds.push_back(era.conceptId);
			}

			bool operator <(const ConcomitantEra &era) const {
				return (start < era.start);
			}

			bool operator ==(const ConcomitantEra &era) const {
				return (this == &era);
			}

			void print() {
				std::cout << "Start: " << start << ", end: " << end << ", size: " << conceptIds.size() << std::endl;
				for (unsigned int i = 0; i < conceptIds.size(); i++) {
					std::cout << "CID: " << conceptIds[i] << std::endl;
				}
			}

			int start;
			int end;
			std::vector<int64_t> conceptIds;
		};

		struct ConcomitantEraCovariateComparator {
			bool operator()(const ConcomitantEra& era1, const ConcomitantEra& era2) const {
				if (era1.conceptIds.size() == era2.conceptIds.size()) {
					for (unsigned int i = 0; i < era1.conceptIds.size(); i++) {
						if (era1.conceptIds[i] != era2.conceptIds[i]) {
							return (era1.conceptIds[i] < era2.conceptIds[i]);
						}
					}
					return false;
				} else
					return (era1.conceptIds.size() < era2.conceptIds.size());
			}
		};

		struct ResultStruct {

			ResultStruct() :
					rowId(0) {
				outcomeRowId = new std::vector<int64_t>;
				outcomeStratumId = new std::vector<int64_t>;
				outcomeY = new std::vector<int64_t>;
				outcomeOutcomeId = new std::vector<int64_t>;
				outcomeTime = new std::vector<int64_t>;
				eraRowId = new std::vector<int64_t>;
				eraStratumId = new std::vector<int64_t>;
				eraCovariateId = new std::vector<int64_t>;
			}

			~ResultStruct() {
				delete outcomeRowId;
				delete outcomeStratumId;
				delete outcomeY;
				delete outcomeOutcomeId;
				delete outcomeTime;
				delete eraRowId;
				delete eraStratumId;
				delete eraCovariateId;
			}

			List convertToRList() {
				DataFrame outcomes = DataFrame::create(Named("rowId") = wrap(*outcomeRowId), Named("stratumId") = wrap(*outcomeStratumId),
						Named("time") = wrap(*outcomeTime), Named("y") = wrap(*outcomeY), Named("outcomeId") = wrap(*outcomeOutcomeId));
				DataFrame covariates = DataFrame::create(Named("rowId") = wrap(*eraRowId), Named("stratumId") = wrap(*eraStratumId), Named("covariateId") =
						wrap(*eraCovariateId));
				return List::create(Named("outcomes") = outcomes, Named("covariates") = covariates);
			}

			std::vector<int64_t>* outcomeRowId;
			std::vector<int64_t>* outcomeStratumId;
			std::vector<int64_t>* outcomeY;
			std::vector<int64_t>* outcomeOutcomeId;
			std::vector<int64_t>* outcomeTime;
			std::vector<int64_t>* eraRowId;
			std::vector<int64_t>* eraStratumId;
			std::vector<int64_t>* eraCovariateId;
			int64_t rowId;
		};

		struct SccsConverter {
		public:
			static List convertToSccs(const DataFrame& cases, const DataFrame& eras, const int covariatePersistencePeriod, const int naivePeriod,
					bool firstOutcomeOnly);
		private:
			static void processPerson(PersonData& personData, ResultStruct& resultStruct, const int covariatePersistencePeriod, const int naivePeriod,
					bool firstOutcomeOnly);
			static void clipEras(std::vector<Era>& eras, const int startDay, const int endDay);
			static void removeAllButFirstOutcome(std::vector<Era>& eras);
			static std::vector<Era> mergeOverlapping(std::vector<Era>& eras);
			static std::vector<Era> extractOutcomes(std::vector<Era>& eras);
			static std::vector<ConcomitantEra> buildConcomitantEras(std::vector<Era>& eras, const int startDay, const int endDay);
			static void compareToRunningEras(ConcomitantEra& newEra, std::vector<ConcomitantEra>& runningEras);
			static void addFinishedEras(const int day, std::vector<ConcomitantEra>& runningEras, std::vector<ConcomitantEra>& concomittantEras);
			static void addNonExposure(std::vector<ConcomitantEra>& concomittantEras, const int _start, const int end);
			static void addToResult(std::vector<ConcomitantEra>& concomitantEras, std::vector<Era>& outcomes, const int64_t& observationPeriodId,
					ResultStruct& resultStruct);
			static void addToResult(const std::vector<int64_t>& conceptIds, std::map<int64_t, int>& outcomeIdToCount, const int duration,
					const int64_t& observationPeriodId, ResultStruct& resultStruct, const std::set<int64_t>& outcomeIds);
		};
	}
}

#endif /* SCCSCONVERTER_H_ */
