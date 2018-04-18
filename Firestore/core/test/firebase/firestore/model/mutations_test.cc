/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Firestore/core/src/firebase/firestore/model/mutations.h"

#include "Firestore/core/src/firebase/firestore/model/field_value.h"
#include "Firestore/core/src/firebase/firestore/model/precondition.h"
#include "Firestore/core/src/firebase/firestore/model/snapshot_version.h"
#include "Firestore/core/test/firebase/firestore/testutil/testutil.h"
#include "absl/types/optional.h"
#include "gtest/gtest.h"

namespace firebase {
namespace firestore {
namespace model {

TEST(MutationResult, DeletedResult) {
  const MutationResult result;
  EXPECT_EQ(absl::nullopt, result.version());
  EXPECT_EQ(absl::nullopt, result.transform_results());
}

TEST(MutationResult, PatchResult) {
  const MutationResult result{testutil::Version(12345)};
  EXPECT_EQ(testutil::Version(12345), result.version());
  EXPECT_EQ(absl::nullopt, result.transform_results());
}

TEST(MutationResult, TransformResult) {
  const MutationResult result{testutil::Version(12345),
                              std::vector<FieldValue>{FieldValue::TrueValue()}};
  EXPECT_EQ(testutil::Version(12345), result.version());
  EXPECT_EQ(std::vector<FieldValue>{FieldValue::TrueValue()},
            result.transform_results());
}

}  // namespace model
}  // namespace firestore
}  // namespace firebase