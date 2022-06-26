#include <gtest/gtest.h>
#include <iostream>
#include <glog/logging.h>
#include "helpertools.h"
#include "spdlog/spdlog.h"

using namespace std;

TEST(Http,basicTest){
    auto resp = httpGet(string("https://www.sec.gov/Archives/edgar/full-index/sitemap.quarterlyindexes.xml"));
    EXPECT_EQ(resp.second.length(),0);
    resp = httpGet(string("https://www.sec.gov/Archives/edgar/full-index/sitemap.quarterlyindexes.xml2"));
    EXPECT_GT(resp.second.length(),0);
}


TEST(DateToolsTest, basicTest){
    DateTools dt1;
    DateTools dt2(0);
    EXPECT_EQ(dt1.getDate(), dt2.getDate());
    EXPECT_EQ(dt1.getQuarter(), dt2.getQuarter());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}