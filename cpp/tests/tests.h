#ifndef TESTS_H
#define TESTS_H

#include <sstream>

#include "../core/global.h"
#include "../core/logger.h"
#include "../core/rand.h"
#include "../core/test.h"
#include "../game/board.h"
#include "../game/rules.h"
#include "../game/boardhistory.h"

class NNEvaluator;

namespace Tests {
  //testboardbasic.cpp
  void runBoardIOTests();
  void runBoardBasicTests();
  void runBoardUndoTest();
  void runBoardHandicapTest();
  void runBoardStressTest();
  void runBoardReplayTest();


  //testboardarea.cpp
  void runBoardAreaTests();

  //testrules.cpp
  void runRulesTests();

  //testscore.cpp
  void runScoreTests();

  //testsgf.cpp
  void runSgfTests();
  void runSgfFileTests();

  //testnninputs.cpp
  void runNNInputsV3V4Tests();

  //testsymmetries.cpp
  void runBasicSymmetryTests();
  void runBoardSymmetryTests();
  void runSymmetryDifferenceTests();

  //testsearchnonn.cpp
  void runNNLessSearchTests();
  //testsearch.cpp
  void runSearchTests(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, int symmetry, bool useFP16);
  //testsearchv3.cpp
  void runSearchTestsV3(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, int symmetry, bool useFP16);
  //testsearchv8.cpp
  void runSearchTestsV8(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, bool useFP16);
  //testsearchv9.cpp
  void runSearchTestsV9(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, bool useFP16);

  //testsearchmisc.cpp
  void runNNOnTinyBoard(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, int symmetry, bool useFP16);
  void runNNSymmetries(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, bool useFP16);
  void runNNOnManyPoses(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, int symmetry, bool useFP16, const std::string& comparisonFile);
  void runNNBatchingTest(const std::string& modelFile, bool inputsNHWC, bool cudaNHWC, bool useFP16);

  //testtime.cpp
  void runTimeControlsTests();

  //testtrainingwrite.cpp
  void runTrainingWriteTests();
  void runSelfplayInitTestsWithNN(const std::string& modelFile);
  void runSekiTrainWriteTests(const std::string& modelFile);
  void runMoreSelfplayTestsWithNN(const std::string& modelFile);
  void runSelfplayStatTestsWithNN(const std::string& modelFile);

  //testnn.cpp
  void runNNLayerTests();
  void runNNSymmetryTests();

  //testownership.cpp
  void runOwnershipTests(const std::string& configFile, const std::string& modelFile);

  //testnnevalcanary.cpp
  void runCanaryTests(NNEvaluator* nnEval, int symmetry, bool print);
  bool runBackendErrorTest(
    NNEvaluator* nnEval,
    NNEvaluator* nnEval32,
    Logger& logger,
    const std::string& boardSizeDataset,
    int maxBatchSizeCap,
    bool verbose,
    bool quickTest,
    double policyOptimismForTest,
    double pdaForTest,
    double nnPolicyTemperatureForTest,
    bool& fp32BatchSuccessBuf,
    //Values on disk to compare correctness. We consider the pure-cpu float32 Eigen implementation of the neural network
    //to be the source of truth, since it is more likely to be stable and doesn't depend special hardware or drivers like
    //GPUs or other accelerators.
    //When running with Eigen backend, will overwrite this file with Eigen's results.
    const std::string& referenceFileName
  );

  //testconfig.cpp
  void runInlineConfigTests();
  void runConfigTests(const std::vector<std::string>& args);
  void runParseAllConfigsTest();
  void runTaskParsingTests();

  //testmisc.cpp
  void runCollectFilesTests();
  void runLoadModelTests();

  //testbook.cpp
  void runBookTests();
}

namespace TestCommon {
  bool boardsSeemEqual(const Board& b1, const Board& b2);

  constexpr int MIN_BENCHMARK_SGF_DATA_SIZE = 7;
  constexpr int MAX_BENCHMARK_SGF_DATA_SIZE = 19;
  constexpr int DEFAULT_BENCHMARK_SGF_DATA_SIZE = std::min(Board::DEFAULT_LEN,MAX_BENCHMARK_SGF_DATA_SIZE);
  std::string getBenchmarkSGFData(int boardSize);

  std::vector<std::string> getMultiGameSize9Data();
  std::vector<std::string> getMultiGameSize13Data();
  std::vector<std::string> getMultiGameSize19Data();
  std::vector<std::string> getMultiGameSize10x14Data();
  std::vector<std::string> getMultiGameRectangleData();

  void overrideForBackends(bool& inputsNHWC, bool& useNHWC);
}

#endif
