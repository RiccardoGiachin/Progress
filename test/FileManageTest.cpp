//
// Created by giack on 30/10/18.
//

#include "gtest/gtest.h"
#include "../FileManager.h"
#include "../BarGUI.h"
#include "../ProgressBarDisplay.h"

//test del costruttore di default
TEST(FileManageTest, CostruttoreDefault) {
    FileManager f;
    ASSERT_EQ(0, f.getFileCaricati());
    ASSERT_EQ(0, f.getBitCaricati());
    ASSERT_EQ(0, f.getObservers().size());
}

//test di iscrizione e disiscrizione
TEST(FileManageTest, Subscribe) {
    FileManager f;
    ProgressBarDisplay *b1;
    ProgressBarDisplay *b2;
    ProgressBarDisplay *b3;
    ProgressBarDisplay *b4;
    ProgressBarDisplay *b5;
    ProgressBarDisplay *b6;
    ProgressBarDisplay *b7;
    ProgressBarDisplay *b8;
    f.subscribe(b1);
    f.subscribe(b2);
    f.subscribe(b3);
    f.subscribe(b4);
    f.subscribe(b5);
    f.subscribe(b6);
    f.subscribe(b7);
    f.subscribe(b8);
    ASSERT_EQ(8, f.getObservers().size());
    f.unsubscribe(b1);
    f.unsubscribe(b2);
    f.unsubscribe(b3);
    f.unsubscribe(b4);
    f.unsubscribe(b5);
    f.unsubscribe(b6);
    f.unsubscribe(b7);
    f.unsubscribe(b8);
    ASSERT_EQ(0, f.getObservers().size());
    f.subscribe(b1);
    f.subscribe(b2);
    f.unsubscribe(b2);
    ASSERT_EQ(1, f.getObservers().size());
}