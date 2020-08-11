/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MS_GRAPHDEF_TRANSFORM_H
#define MS_GRAPHDEF_TRANSFORM_H

#include <memory>
#include "tools/converter/optimizer.h"
#include "tools/converter/quantizer/quantizer.h"
#include "schema/inner/model_generated.h"
#include "tools/common/storage.h"
#include "tools/converter/converter_flags.h"

namespace mindspore {
namespace lite {
/*
 * transform GraphDef by fusion legacy_optimizer and quantizer
 * */

class GraphDefTransform {
 public:
  GraphDefTransform();
  virtual ~GraphDefTransform();
  virtual int Transform(const converter::Flags &ctx);
  void SetGraphDef(schema::MetaGraphT *dstDef);
  inline schema::MetaGraphT *GetOutput() { return graphDefT; }
  void CreateQuantizer(const converter::Flags *flags);

 protected:
  schema::MetaGraphT *graphDefT = nullptr;
  Optimizer *optimizer = nullptr;

  std::unique_ptr<quant::Quantizer> mQuantizer;
  std::unique_ptr<quant::FbQuantizer> fbQuantizer;
};
}  // namespace lite
}  // namespace mindspore

#endif

