/**
 * @file FfdfIterator.h
 *
 * This file is part of SelfControlledCaseSeries
 *
 * Copyright 2017 Observational Health Data Sciences and Informatics
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

#ifndef __FfdfIterator_h__
#define __FfdfIterator_h__

#include <Rcpp.h>

using namespace Rcpp;

namespace ohdsi {
namespace sccs {


class FfdfIterator {
public:
  FfdfIterator(const List& _ffdf, const bool &_showProgressBar);
  bool hasNext();
  List next();
private:
  List ffdf;
  List chunks;
  List progressBar;
  int cursor;
  bool showProgressBar;
};
}
}

#endif // __FfdfIterator_h__
