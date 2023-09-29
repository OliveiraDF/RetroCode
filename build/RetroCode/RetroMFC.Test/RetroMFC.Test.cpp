#include "pch.h"

int main()
{
    CPPUNIT_NS::TestResult Controller;

    CPPUNIT_NS::TestResultCollector Result;
    Controller.addListener(&Result);

    CPPUNIT_NS::BriefTestProgressListener Progress;
    Controller.addListener(&Progress);

    CPPUNIT_NS::TestRunner Runner;

    CPPUNIT_NS::Test* pSuite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
    Runner.addTest(pSuite);
    Runner.run(Controller);

    CPPUNIT_NS::CompilerOutputter Outputter(&Result, CPPUNIT_NS::stdCOut());
    Outputter.write();

    return Result.wasSuccessful() ? EXIT_SUCCESS : EXIT_FAILURE;
}