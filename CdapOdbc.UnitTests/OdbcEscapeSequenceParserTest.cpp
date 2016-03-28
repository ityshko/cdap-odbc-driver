/*
* Copyright � 2016 Cask Data, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may not
* use this file except in compliance with the License. You may obtain a copy of
* the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations under
* the License.
*/

#include "stdafx.h"
#include "ODBCEscapeSequenceParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Cask {
  namespace CdapOdbc {
    namespace Tests {

      /**
       * Tests for OdbcEscapeSequenceParser class.
       */
      TEST_CLASS(OdbcEscapeSequenceParserTest) {
      public:
        
        /**
         * Checks that date escape sequence succeeds.
         */
        TEST_METHOD(ResolveDateSucceeds) {
          auto query = std::wstring(L"SELECT {d '2007 - 01 - 01'}");
          ODBCEscapeSequenceParser parser(query);
          auto actual = parser.toString();
          Assert::AreEqual(L"SELECT DATE('2007 - 01 - 01')", actual.c_str());
        }

      };
    }
  }
}