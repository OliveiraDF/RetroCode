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

#ifdef _DEBUG

    CPPUNIT_NS::CompilerOutputter CplOutputter(&Result, CPPUNIT_NS::stdCOut());
    CplOutputter.write();

#else

    std::ofstream file("result.xml");

    CPPUNIT_NS::XmlOutputter XmlOutputter(&Result, file);
    XmlOutputter.write();

    file.close();

#endif

    return Result.wasSuccessful() ? EXIT_SUCCESS : EXIT_FAILURE;
}