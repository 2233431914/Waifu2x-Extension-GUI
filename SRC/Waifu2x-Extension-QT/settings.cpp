﻿/*
    Copyright (C) 2020  Aaron Feng

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    My Github homepage: https://github.com/AaronFeng753
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
保存设置
删除原设置文件,保存设置
*/
int MainWindow::Settings_Save()
{
    QString settings_ini = Current_Path+"/settings.ini";
    QFile::remove(settings_ini);
    //=================
    QSettings *configIniWrite = new QSettings(settings_ini, QSettings::IniFormat);
    configIniWrite->setIniCodec(QTextCodec::codecForName("UTF-8"));
    //================= 添加警告 =========================
    configIniWrite->setValue("/Warning/EN", "Do not modify this file! It may cause the program to crash! If problems occur after the modification, delete this article and restart the program.");
    //==================== 存储版本识别 ==================================
    configIniWrite->setValue("/settings/VERSION", VERSION);
    //=======  存储放大值和降噪值  =================================
    configIniWrite->setValue("/settings/ImageScaleRatio", ui->spinBox_ScaleRatio_image->value());
    configIniWrite->setValue("/settings/GIFScaleRatio", ui->spinBox_ScaleRatio_gif->value());
    configIniWrite->setValue("/settings/VideoScaleRatio", ui->spinBox_ScaleRatio_video->value());
    configIniWrite->setValue("/settings/ImageDenoiseLevel", ui->spinBox_DenoiseLevel_image->value());
    configIniWrite->setValue("/settings/GIFDenoiseLevel", ui->spinBox_DenoiseLevel_gif->value());
    configIniWrite->setValue("/settings/VideoDenoiseLevel", ui->spinBox_DenoiseLevel_video->value());
    //============ 存储自定义宽度和高度及设置 ============================
    configIniWrite->setValue("/settings/CustResWidth", ui->spinBox_CustRes_width->value());
    configIniWrite->setValue("/settings/CustResHeight", ui->spinBox_CustRes_height->value());
    configIniWrite->setValue("/settings/CustResAspectRatioMode", ui->comboBox_AspectRatio_custRes->currentIndex());
    //============ 存储线程数量 ====================================
    configIniWrite->setValue("/settings/ImageThreadNum", ui->spinBox_ThreadNum_image->value());
    configIniWrite->setValue("/settings/GIFThreadNum", ui->spinBox_ThreadNum_gif->value());
    configIniWrite->setValue("/settings/GIFThreadNumInternal", ui->spinBox_ThreadNum_gif_internal->value());
    configIniWrite->setValue("/settings/VideoThreadNum", ui->spinBox_ThreadNum_video->value());
    configIniWrite->setValue("/settings/VideoThreadNumInternal", ui->spinBox_ThreadNum_video_internal->value());
    //================== 存储引擎设置 =========================
    configIniWrite->setValue("/settings/ImageEngine", ui->comboBox_Engine_Image->currentIndex());
    configIniWrite->setValue("/settings/GIFEngine", ui->comboBox_Engine_GIF->currentIndex());
    configIniWrite->setValue("/settings/VideoEngine", ui->comboBox_Engine_Video->currentIndex());
    configIniWrite->setValue("/settings/ImageStyle", ui->comboBox_ImageStyle->currentIndex());
    configIniWrite->setValue("/settings/ModelVulkan", ui->comboBox_model_vulkan->currentIndex());
    configIniWrite->setValue("/settings/TileSize", ui->spinBox_TileSize->value());
    configIniWrite->setValue("/settings/BlockSizeConverter", ui->spinBox_BlockSize_converter->value());
    configIniWrite->setValue("/settings/DisableGPUConverter", ui->checkBox_DisableGPU_converter->checkState());
    configIniWrite->setValue("/settings/ForceOpenCLConverter", ui->checkBox_ForceOpenCL_converter->checkState());
    //================== 存储 扩展名 =================================
    configIniWrite->setValue("/settings/ImageEXT", ui->Ext_image->text());
    configIniWrite->setValue("/settings/VideoEXT", ui->Ext_video->text());
    //=================== 存储 杂项设置 =================================
    configIniWrite->setValue("/settings/SaveAsJPG", ui->checkBox_SaveAsJPG->checkState());
    configIniWrite->setValue("/settings/CompressJPG", ui->checkBox_CompressJPG->checkState());
    configIniWrite->setValue("/settings/DelOriginal", ui->checkBox_DelOriginal->checkState());
    configIniWrite->setValue("/settings/OptGIF", ui->checkBox_OptGIF->checkState());
    configIniWrite->setValue("/settings/NFSound", ui->checkBox_NfSound->checkState());
    configIniWrite->setValue("/settings/ReProFinFiles", ui->checkBox_ReProcFinFiles->checkState());
    configIniWrite->setValue("/settings/ShowInterPro", ui->checkBox_ShowInterPro->checkState());
    configIniWrite->setValue("/settings/AutoCheckUpdate", ui->checkBox_autoCheckUpdate->checkState());
    configIniWrite->setValue("/settings/FileListAutoScroll", ui->checkBox_FileListAutoSlide->checkState());
    configIniWrite->setValue("/settings/AutoSaveSettings", ui->checkBox_AutoSaveSettings->checkState());
    configIniWrite->setValue("/settings/AlwaysHideInput", ui->checkBox_AlwaysHideInput->checkState());
    configIniWrite->setValue("/settings/AlwaysHideSettings", ui->checkBox_AlwaysHideSettings->checkState());
    configIniWrite->setValue("/settings/AlwaysHideTextBrowser", ui->checkBox_AlwaysHideTextBrowser->checkState());
    configIniWrite->setValue("/settings/JPGCompressedQuality", ui->spinBox_JPGCompressedQuality->value());
    //===================== 存储 textbrowser 设置 =====================
    configIniWrite->setValue("/settings/TextBrowserFontSize", ui->spinBox_textbrowser_fontsize->value());
    //===================== 存储语言设置 ================================
    configIniWrite->setValue("/settings/Language", ui->comboBox_language->currentIndex());
    //================== 存储全局字体 =========================
    configIniWrite->setValue("/settings/GlobalFontSize", ui->spinBox_GlobalFontSize->value());
    configIniWrite->setValue("/settings/CustFont", ui->fontComboBox_CustFont->currentFont());
    configIniWrite->setValue("/settings/CustFont_isEnabled", ui->checkBox_isCustFontEnable->checkState());
    //=================== 存储视频设置 ===========================
    configIniWrite->setValue("/settings/EncoderVideo", ui->lineEdit_encoder_vid->text());
    configIniWrite->setValue("/settings/EncoderAudio", ui->lineEdit_encoder_audio->text());
    configIniWrite->setValue("/settings/PixelFormat", ui->lineEdit_pixformat->text());
    configIniWrite->setValue("/settings/BitrateVideo", ui->spinBox_bitrate_vid->value());
    configIniWrite->setValue("/settings/BitrateAudio", ui->spinBox_bitrate_audio->value());
    //==========
    Send_TextBrowser_NewMessage(tr("Settings saved successfully!"));
    return 0;
}
/*
读取&应用设置
如果设置文件不存在则生成默认设置文件,读取设置,应用设置
*/
int MainWindow::Settings_Read_Apply()
{
    QString settings_ini = Current_Path+"/settings.ini";
    if(!file_isFileExist(settings_ini))
    {
        Settings_Save();
        //======
        CustRes_SetToScreenRes();
        //========================
        on_comboBox_language_currentIndexChanged(0);
        //====================================================
        on_checkBox_SaveAsJPG_stateChanged(0);
        on_checkBox_ReProcFinFiles_stateChanged(0);
        on_checkBox_AlwaysHideInput_stateChanged(0);
        on_checkBox_AlwaysHideSettings_stateChanged(0);
        on_checkBox_AlwaysHideTextBrowser_stateChanged(0);
        //====
        on_comboBox_GPUID_currentIndexChanged(0);
        on_comboBox_Engine_GIF_currentIndexChanged(0);
        on_comboBox_Engine_Image_currentIndexChanged(0);
        on_comboBox_Engine_Video_currentIndexChanged(0);
        on_comboBox_ImageStyle_currentIndexChanged(0);
        on_comboBox_model_vulkan_currentIndexChanged(0);
        //=====
        on_spinBox_textbrowser_fontsize_valueChanged(0);
        //===
        on_comboBox_AspectRatio_custRes_currentIndexChanged(0);
        //====
        on_spinBox_ThreadNum_gif_valueChanged(0);
        on_spinBox_ThreadNum_gif_internal_valueChanged(0);
        on_spinBox_ThreadNum_video_valueChanged(0);
        on_spinBox_ThreadNum_video_internal_valueChanged(0);
        //=====
        Init_Table();
        //========================
        return 0;
    }
    else
    {
        QSettings *configIniRead_ver = new QSettings(settings_ini, QSettings::IniFormat);
        configIniRead_ver->setIniCodec(QTextCodec::codecForName("UTF-8"));
        QString Settings_VERSION = configIniRead_ver->value("/settings/VERSION").toString();
        if(Settings_VERSION!=VERSION)
        {
            Settings_Save();
            //======
            CustRes_SetToScreenRes();
            //========================
            on_comboBox_language_currentIndexChanged(0);
            //====================================================
            on_checkBox_SaveAsJPG_stateChanged(0);
            on_checkBox_ReProcFinFiles_stateChanged(0);
            on_checkBox_AlwaysHideInput_stateChanged(0);
            on_checkBox_AlwaysHideSettings_stateChanged(0);
            on_checkBox_AlwaysHideTextBrowser_stateChanged(0);
            //====
            on_comboBox_GPUID_currentIndexChanged(0);
            on_comboBox_Engine_GIF_currentIndexChanged(0);
            on_comboBox_Engine_Image_currentIndexChanged(0);
            on_comboBox_Engine_Video_currentIndexChanged(0);
            on_comboBox_ImageStyle_currentIndexChanged(0);
            on_comboBox_model_vulkan_currentIndexChanged(0);
            //=====
            on_spinBox_textbrowser_fontsize_valueChanged(0);
            //===
            on_comboBox_AspectRatio_custRes_currentIndexChanged(0);
            //====
            on_spinBox_ThreadNum_gif_valueChanged(0);
            on_spinBox_ThreadNum_gif_internal_valueChanged(0);
            on_spinBox_ThreadNum_video_valueChanged(0);
            on_spinBox_ThreadNum_video_internal_valueChanged(0);
            //=====
            Init_Table();
            //========================
            return 0;
        }
    }
    //=================
    QSettings *configIniRead = new QSettings(settings_ini, QSettings::IniFormat);
    configIniRead->setIniCodec(QTextCodec::codecForName("UTF-8"));
    //=================== 加载全局字体设置 =========================
    ui->spinBox_GlobalFontSize->setValue(configIniRead->value("/settings/GlobalFontSize").toInt());
    ui->fontComboBox_CustFont->setCurrentFont(configIniRead->value("/settings/CustFont").value<QFont>());
    ui->checkBox_isCustFontEnable->setChecked(configIniRead->value("/settings/CustFont_isEnabled").toBool());
    Set_Font_fixed();
    //=======  加载放大值和降噪值  ======
    ui->spinBox_ScaleRatio_image->setValue(configIniRead->value("/settings/ImageScaleRatio").toInt());
    ui->spinBox_ScaleRatio_gif->setValue(configIniRead->value("/settings/GIFScaleRatio").toInt());
    ui->spinBox_ScaleRatio_video->setValue(configIniRead->value("/settings/VideoScaleRatio").toInt());
    //============= 加载自定义宽度和高度 ============================
    ui->spinBox_CustRes_width->setValue(configIniRead->value("/settings/CustResWidth").toInt());
    ui->spinBox_CustRes_height->setValue(configIniRead->value("/settings/CustResHeight").toInt());
    ui->comboBox_AspectRatio_custRes->setCurrentIndex(configIniRead->value("/settings/CustResAspectRatioMode").toInt());
    //============ 加载 线程数量 ==================================
    ui->spinBox_ThreadNum_image->setValue(configIniRead->value("/settings/ImageThreadNum").toInt());
    ui->spinBox_ThreadNum_gif->setValue(configIniRead->value("/settings/GIFThreadNum").toInt());
    ui->spinBox_ThreadNum_gif_internal->setValue(configIniRead->value("/settings/GIFThreadNumInternal").toInt());
    ui->spinBox_ThreadNum_video->setValue(configIniRead->value("/settings/VideoThreadNum").toInt());
    ui->spinBox_ThreadNum_video_internal->setValue(configIniRead->value("/settings/VideoThreadNumInternal").toInt());
    //================ 加载 引擎设置 ================================
    ui->comboBox_Engine_Image->setCurrentIndex(configIniRead->value("/settings/ImageEngine").toInt());
    ui->comboBox_Engine_GIF->setCurrentIndex(configIniRead->value("/settings/GIFEngine").toInt());
    ui->comboBox_Engine_Video->setCurrentIndex(configIniRead->value("/settings/VideoEngine").toInt());
    ui->comboBox_ImageStyle->setCurrentIndex(configIniRead->value("/settings/ImageStyle").toInt());
    ui->comboBox_model_vulkan->setCurrentIndex(configIniRead->value("/settings/ModelVulkan").toInt());
    ui->spinBox_TileSize->setValue(configIniRead->value("/settings/TileSize").toInt());
    ui->spinBox_BlockSize_converter->setValue(configIniRead->value("/settings/BlockSizeConverter").toInt());
    ui->checkBox_DisableGPU_converter->setChecked(configIniRead->value("/settings/DisableGPUConverter").toBool());
    ui->checkBox_ForceOpenCL_converter->setChecked(configIniRead->value("/settings/ForceOpenCLConverter").toBool());
    //================= 加载 扩展名 ===========================
    ui->Ext_image->setText(configIniRead->value("/settings/ImageEXT").toString());
    ui->Ext_video->setText(configIniRead->value("/settings/VideoEXT").toString());
    //================== 加载 杂项设置 ==================================
    ui->checkBox_SaveAsJPG->setChecked(configIniRead->value("/settings/SaveAsJPG").toBool());
    ui->checkBox_CompressJPG->setChecked(configIniRead->value("/settings/CompressJPG").toBool());
    ui->checkBox_DelOriginal->setChecked(configIniRead->value("/settings/DelOriginal").toBool());
    ui->checkBox_OptGIF->setChecked(configIniRead->value("/settings/OptGIF").toBool());
    ui->checkBox_NfSound->setChecked(configIniRead->value("/settings/NFSound").toBool());
    ui->checkBox_ReProcFinFiles->setChecked(configIniRead->value("/settings/ReProFinFiles").toBool());
    ui->checkBox_ShowInterPro->setChecked(configIniRead->value("/settings/ShowInterPro").toBool());
    ui->checkBox_autoCheckUpdate->setChecked(configIniRead->value("/settings/AutoCheckUpdate").toBool());
    ui->checkBox_FileListAutoSlide->setChecked(configIniRead->value("/settings/FileListAutoScroll").toBool());
    ui->checkBox_AutoSaveSettings->setChecked(configIniRead->value("/settings/AutoSaveSettings").toBool());
    ui->checkBox_AlwaysHideInput->setChecked(configIniRead->value("/settings/AlwaysHideInput").toBool());
    ui->checkBox_AlwaysHideSettings->setChecked(configIniRead->value("/settings/AlwaysHideSettings").toBool());
    ui->checkBox_AlwaysHideTextBrowser->setChecked(configIniRead->value("/settings/AlwaysHideTextBrowser").toBool());
    ui->spinBox_JPGCompressedQuality->setValue(configIniRead->value("/settings/JPGCompressedQuality").toInt());
    //=================== 加载 textbrowser 设置 ==========================
    ui->spinBox_textbrowser_fontsize->setValue(configIniRead->value("/settings/TextBrowserFontSize").toInt());
    //=================== 加载视频设置 ===========================
    ui->lineEdit_encoder_vid->setText(configIniRead->value("/settings/EncoderVideo").toString());
    ui->lineEdit_encoder_audio->setText(configIniRead->value("/settings/EncoderAudio").toString());
    ui->lineEdit_pixformat->setText(configIniRead->value("/settings/PixelFormat").toString());
    ui->spinBox_bitrate_vid->setValue(configIniRead->value("/settings/BitrateVideo").toInt());
    ui->spinBox_bitrate_audio->setValue(configIniRead->value("/settings/BitrateAudio").toInt());
    //==================== 加载语言设置 =====================
    ui->comboBox_language->setCurrentIndex(configIniRead->value("/settings/Language").toInt());
    on_comboBox_language_currentIndexChanged(0);
    //====================================================
    on_checkBox_SaveAsJPG_stateChanged(0);
    on_checkBox_ReProcFinFiles_stateChanged(0);
    on_checkBox_AlwaysHideInput_stateChanged(0);
    on_checkBox_AlwaysHideSettings_stateChanged(0);
    on_checkBox_AlwaysHideTextBrowser_stateChanged(0);
    //====
    on_comboBox_GPUID_currentIndexChanged(0);
    on_comboBox_Engine_GIF_currentIndexChanged(0);
    on_comboBox_Engine_Image_currentIndexChanged(0);
    on_comboBox_Engine_Video_currentIndexChanged(0);
    on_comboBox_ImageStyle_currentIndexChanged(0);
    on_comboBox_model_vulkan_currentIndexChanged(0);
    ui->spinBox_DenoiseLevel_image->setValue(configIniRead->value("/settings/ImageDenoiseLevel").toInt());
    ui->spinBox_DenoiseLevel_gif->setValue(configIniRead->value("/settings/GIFDenoiseLevel").toInt());
    ui->spinBox_DenoiseLevel_video->setValue(configIniRead->value("/settings/VideoDenoiseLevel").toInt());
    //=====
    on_spinBox_textbrowser_fontsize_valueChanged(0);
    //===
    on_comboBox_AspectRatio_custRes_currentIndexChanged(0);
    //====
    on_spinBox_ThreadNum_gif_valueChanged(0);
    on_spinBox_ThreadNum_gif_internal_valueChanged(0);
    on_spinBox_ThreadNum_video_valueChanged(0);
    on_spinBox_ThreadNum_video_internal_valueChanged(0);
    //=====
    Init_Table();
    //==================================
    return 0;
}
/*
保存设置pushbutton
保存设置,弹窗
*/
void MainWindow::on_pushButton_SaveSettings_clicked()
{
    Settings_Save();
    QMessageBox *MSG = new QMessageBox();
    MSG->setWindowTitle(tr("Notification"));
    MSG->setText(tr("Settings saved successfully!"));
    MSG->setIcon(QMessageBox::Information);
    MSG->setModal(false);
    MSG->show();
}
/*
重置设置
删除设置文件,重置标记=true,弹窗
*/
void MainWindow::on_pushButton_ResetSettings_clicked()
{
    QString settings_ini = Current_Path+"/settings.ini";
    QFile::remove(settings_ini);
    Settings_isReseted = true;
    QMessageBox *MSG = new QMessageBox();
    MSG->setWindowTitle(tr("Notification"));
    MSG->setText(tr("The settings file has been reset, please restart the software manually for the default settings to take effect."));
    MSG->setIcon(QMessageBox::Information);
    MSG->setModal(false);
    MSG->show();
}
