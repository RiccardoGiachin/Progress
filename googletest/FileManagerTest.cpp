//
// Created by giack on 30/10/18.
//

#include "gtest/gtest.h"
#include "../FileManager.h"
#include "../BarGUI.h"
#include "../ProgressBarDisplay.h"

TEST(FileManagerTest, DefaultConstructor) {
    FileManager f;
    ASSERT_EQ(0, f.getFileLoaded());
    ASSERT_EQ(0, f.getObservers().size());
}


TEST(FileManagerTest, TestSubscribe) {
    FileManager f;
    GUIProgressBar *ptr;
    f.subscribe(ptr);
    ASSERT_EQ(1, f.getObservers().size());
    f.unsubscribe(ptr);
    ASSERT_EQ(0, f.getObservers().size());
}