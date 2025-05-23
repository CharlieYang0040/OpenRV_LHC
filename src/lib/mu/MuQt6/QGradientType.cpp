//*****************************************************************************
// Copyright (c) 2024 Autodesk, Inc.
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//
//*****************************************************************************

// IMPORTANT: This file (not the template) is auto-generated by qt2mu.py script.
//            The prefered way to do a fix is to handrolled it or modify the
//            qt2mu.py script. If it is not possible, manual editing is ok but
//            it could be lost in future generations.

#include <MuQt6/qtUtils.h>
#include <MuQt6/QGradientType.h>
#include <MuQt6/QActionType.h>
#include <MuQt6/QWidgetType.h>
#include <Mu/Alias.h>
#include <Mu/BaseFunctions.h>
#include <Mu/ClassInstance.h>
#include <Mu/Exception.h>
#include <Mu/Function.h>
#include <Mu/MemberFunction.h>
#include <Mu/MemberVariable.h>
#include <Mu/Node.h>
#include <Mu/ParameterVariable.h>
#include <Mu/ReferenceType.h>
#include <Mu/SymbolicConstant.h>
#include <Mu/Thread.h>
#include <Mu/Value.h>
#include <MuLang/MuLangContext.h>
#include <MuLang/StringType.h>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>
#include <QtSvg/QtSvg>
#include <QSvgWidget>
#include <QtNetwork/QtNetwork>
#include <MuQt6/QColorType.h>

namespace Mu
{
    using namespace std;

    QGradientType::Instance::Instance(const Class* c)
        : ClassInstance(c)
    {
    }

    QGradientType::QGradientType(Context* c, const char* name, Class* super)
        : Class(c, name, super)
    {
    }

    QGradientType::~QGradientType() {}

    static NODE_IMPLEMENTATION(__allocate, Pointer)
    {
        QGradientType::Instance* i =
            new QGradientType::Instance((Class*)NODE_THIS.type());
        QGradientType::registerFinalizer(i);
        NODE_RETURN(i);
    }

    void QGradientType::registerFinalizer(void* o)
    {
        GC_register_finalizer(o, QGradientType::finalizer, 0, 0, 0);
    }

    void QGradientType::finalizer(void* obj, void* data)
    {
        QGradientType::Instance* i =
            reinterpret_cast<QGradientType::Instance*>(obj);
        delete i;
    }

    //----------------------------------------------------------------------
    //  PRE-COMPILED FUNCTIONS

    Pointer qt_QGradient_QGradient_QGradient_QGradient_int(
        Mu::Thread& NODE_THREAD, Pointer param_this, int param_preset)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        QGradient::Preset arg1 = (QGradient::Preset)(param_preset);
        setqtype<QGradientType>(param_this, QGradient(arg1));
        return param_this;
    }

    int qt_QGradient_coordinateMode_int_QGradient(Mu::Thread& NODE_THREAD,
                                                  Pointer param_this)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        const QGradient& arg0 = getqtype<QGradientType>(param_this);
        return int(arg0.coordinateMode());
    }

    void qt_QGradient_setColorAt_void_QGradient_double_QColor(
        Mu::Thread& NODE_THREAD, Pointer param_this, double param_position,
        Pointer param_color)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        QGradient& arg0 = getqtype<QGradientType>(param_this);
        qreal arg1 = (double)(param_position);
        const QColor arg2 = getqtype<QColorType>(param_color);
        arg0.setColorAt(arg1, arg2);
        setqtype<QGradientType>(param_this, arg0);
    }

    void qt_QGradient_setCoordinateMode_void_QGradient_int(
        Mu::Thread& NODE_THREAD, Pointer param_this, int param_mode)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        QGradient& arg0 = getqtype<QGradientType>(param_this);
        QGradient::CoordinateMode arg1 =
            (QGradient::CoordinateMode)(param_mode);
        arg0.setCoordinateMode(arg1);
        setqtype<QGradientType>(param_this, arg0);
    }

    void qt_QGradient_setSpread_void_QGradient_int(Mu::Thread& NODE_THREAD,
                                                   Pointer param_this,
                                                   int param_method)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        QGradient& arg0 = getqtype<QGradientType>(param_this);
        QGradient::Spread arg1 = (QGradient::Spread)(param_method);
        arg0.setSpread(arg1);
        setqtype<QGradientType>(param_this, arg0);
    }

    int qt_QGradient_spread_int_QGradient(Mu::Thread& NODE_THREAD,
                                          Pointer param_this)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        const QGradient& arg0 = getqtype<QGradientType>(param_this);
        return int(arg0.spread());
    }

    int qt_QGradient_type_int_QGradient(Mu::Thread& NODE_THREAD,
                                        Pointer param_this)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        const QGradient& arg0 = getqtype<QGradientType>(param_this);
        return int(arg0.type());
    }

    bool qt_QGradient_operatorBang_EQ__bool_QGradient_QGradient(
        Mu::Thread& NODE_THREAD, Pointer param_this, Pointer param_gradient)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        const QGradient& arg0 = getqtype<QGradientType>(param_this);
        const QGradient arg1 = getqtype<QGradientType>(param_gradient);
        return arg0.operator!=(arg1);
    }

    bool qt_QGradient_operatorEQ_EQ__bool_QGradient_QGradient(
        Mu::Thread& NODE_THREAD, Pointer param_this, Pointer param_gradient)
    {
        MuLangContext* c = static_cast<MuLangContext*>(NODE_THREAD.context());
        const QGradient& arg0 = getqtype<QGradientType>(param_this);
        const QGradient arg1 = getqtype<QGradientType>(param_gradient);
        return arg0.operator==(arg1);
    }

    static NODE_IMPLEMENTATION(_n_QGradient0, Pointer)
    {
        NODE_RETURN(qt_QGradient_QGradient_QGradient_QGradient_int(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer), NODE_ARG(1, int)));
    }

    static NODE_IMPLEMENTATION(_n_coordinateMode0, int)
    {
        NODE_RETURN(qt_QGradient_coordinateMode_int_QGradient(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer)));
    }

    static NODE_IMPLEMENTATION(_n_setColorAt0, void)
    {
        qt_QGradient_setColorAt_void_QGradient_double_QColor(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer), NODE_ARG(1, double),
            NODE_ARG(2, Pointer));
    }

    static NODE_IMPLEMENTATION(_n_setCoordinateMode0, void)
    {
        qt_QGradient_setCoordinateMode_void_QGradient_int(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer), NODE_ARG(1, int));
    }

    static NODE_IMPLEMENTATION(_n_setSpread0, void)
    {
        qt_QGradient_setSpread_void_QGradient_int(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer), NODE_ARG(1, int));
    }

    static NODE_IMPLEMENTATION(_n_spread0, int)
    {
        NODE_RETURN(qt_QGradient_spread_int_QGradient(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer)));
    }

    static NODE_IMPLEMENTATION(_n_type0, int)
    {
        NODE_RETURN(qt_QGradient_type_int_QGradient(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer)));
    }

    static NODE_IMPLEMENTATION(_n_operatorBang_EQ_0, bool)
    {
        NODE_RETURN(qt_QGradient_operatorBang_EQ__bool_QGradient_QGradient(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer), NODE_ARG(1, Pointer)));
    }

    static NODE_IMPLEMENTATION(_n_operatorEQ_EQ_0, bool)
    {
        NODE_RETURN(qt_QGradient_operatorEQ_EQ__bool_QGradient_QGradient(
            NODE_THREAD, NONNIL_NODE_ARG(0, Pointer), NODE_ARG(1, Pointer)));
    }

    //
    // Copyright (C) 2023  Autodesk, Inc. All Rights Reserved.
    //
    // SPDX-License-Identifier: Apache-2.0
    //
    static NODE_IMPLEMENTATION(setStops, void) {}

    static NODE_IMPLEMENTATION(stops, Pointer) { NODE_RETURN(Pointer(0)); }

    void QGradientType::load()
    {
        USING_MU_FUNCTION_SYMBOLS;
        MuLangContext* c = static_cast<MuLangContext*>(context());
        Module* global = globalModule();

        const string typeName = name();
        const string refTypeName = typeName + "&";
        const string fullTypeName = fullyQualifiedName();
        const string fullRefTypeName = fullTypeName + "&";
        const char* tn = typeName.c_str();
        const char* ftn = fullTypeName.c_str();
        const char* rtn = refTypeName.c_str();
        const char* frtn = fullRefTypeName.c_str();

        scope()->addSymbols(new ReferenceType(c, rtn, this),

                            new Function(c, tn, BaseFunctions::dereference,
                                         Cast, Return, ftn, Args, frtn, End),

                            EndArguments);

        addSymbols(
            new Function(c, "__allocate", __allocate, None, Return, ftn, End),

            EndArguments);

        addSymbols(
            new Alias(c, "CoordinateMode", "int"),
            new SymbolicConstant(c, "LogicalMode", "int",
                                 Value(int(QGradient::LogicalMode))),
            new SymbolicConstant(c, "ObjectMode", "int",
                                 Value(int(QGradient::ObjectMode))),
            new SymbolicConstant(c, "StretchToDeviceMode", "int",
                                 Value(int(QGradient::StretchToDeviceMode))),
            new SymbolicConstant(c, "ObjectBoundingMode", "int",
                                 Value(int(QGradient::ObjectBoundingMode))),
            new Alias(c, "Preset", "int"),
            new SymbolicConstant(c, "WarmFlame", "int",
                                 Value(int(QGradient::WarmFlame))),
            new SymbolicConstant(c, "NightFade", "int",
                                 Value(int(QGradient::NightFade))),
            new SymbolicConstant(c, "SpringWarmth", "int",
                                 Value(int(QGradient::SpringWarmth))),
            new SymbolicConstant(c, "JuicyPeach", "int",
                                 Value(int(QGradient::JuicyPeach))),
            new SymbolicConstant(c, "YoungPassion", "int",
                                 Value(int(QGradient::YoungPassion))),
            new SymbolicConstant(c, "LadyLips", "int",
                                 Value(int(QGradient::LadyLips))),
            new SymbolicConstant(c, "SunnyMorning", "int",
                                 Value(int(QGradient::SunnyMorning))),
            new SymbolicConstant(c, "RainyAshville", "int",
                                 Value(int(QGradient::RainyAshville))),
            new SymbolicConstant(c, "FrozenDreams", "int",
                                 Value(int(QGradient::FrozenDreams))),
            new SymbolicConstant(c, "WinterNeva", "int",
                                 Value(int(QGradient::WinterNeva))),
            new SymbolicConstant(c, "DustyGrass", "int",
                                 Value(int(QGradient::DustyGrass))),
            new SymbolicConstant(c, "TemptingAzure", "int",
                                 Value(int(QGradient::TemptingAzure))),
            new SymbolicConstant(c, "HeavyRain", "int",
                                 Value(int(QGradient::HeavyRain))),
            new SymbolicConstant(c, "AmyCrisp", "int",
                                 Value(int(QGradient::AmyCrisp))),
            new SymbolicConstant(c, "MeanFruit", "int",
                                 Value(int(QGradient::MeanFruit))),
            new SymbolicConstant(c, "DeepBlue", "int",
                                 Value(int(QGradient::DeepBlue))),
            new SymbolicConstant(c, "RipeMalinka", "int",
                                 Value(int(QGradient::RipeMalinka))),
            new SymbolicConstant(c, "CloudyKnoxville", "int",
                                 Value(int(QGradient::CloudyKnoxville))),
            new SymbolicConstant(c, "MalibuBeach", "int",
                                 Value(int(QGradient::MalibuBeach))),
            new SymbolicConstant(c, "NewLife", "int",
                                 Value(int(QGradient::NewLife))),
            new SymbolicConstant(c, "TrueSunset", "int",
                                 Value(int(QGradient::TrueSunset))),
            new SymbolicConstant(c, "MorpheusDen", "int",
                                 Value(int(QGradient::MorpheusDen))),
            new SymbolicConstant(c, "RareWind", "int",
                                 Value(int(QGradient::RareWind))),
            new SymbolicConstant(c, "NearMoon", "int",
                                 Value(int(QGradient::NearMoon))),
            new SymbolicConstant(c, "WildApple", "int",
                                 Value(int(QGradient::WildApple))),
            new SymbolicConstant(c, "SaintPetersburg", "int",
                                 Value(int(QGradient::SaintPetersburg))),
            new SymbolicConstant(c, "PlumPlate", "int",
                                 Value(int(QGradient::PlumPlate))),
            new SymbolicConstant(c, "EverlastingSky", "int",
                                 Value(int(QGradient::EverlastingSky))),
            new SymbolicConstant(c, "HappyFisher", "int",
                                 Value(int(QGradient::HappyFisher))),
            new SymbolicConstant(c, "Blessing", "int",
                                 Value(int(QGradient::Blessing))),
            new SymbolicConstant(c, "SharpeyeEagle", "int",
                                 Value(int(QGradient::SharpeyeEagle))),
            new SymbolicConstant(c, "LadogaBottom", "int",
                                 Value(int(QGradient::LadogaBottom))),
            new SymbolicConstant(c, "LemonGate", "int",
                                 Value(int(QGradient::LemonGate))),
            new SymbolicConstant(c, "ItmeoBranding", "int",
                                 Value(int(QGradient::ItmeoBranding))),
            new SymbolicConstant(c, "ZeusMiracle", "int",
                                 Value(int(QGradient::ZeusMiracle))),
            new SymbolicConstant(c, "OldHat", "int",
                                 Value(int(QGradient::OldHat))),
            new SymbolicConstant(c, "StarWine", "int",
                                 Value(int(QGradient::StarWine))),
            new SymbolicConstant(c, "HappyAcid", "int",
                                 Value(int(QGradient::HappyAcid))),
            new SymbolicConstant(c, "AwesomePine", "int",
                                 Value(int(QGradient::AwesomePine))),
            new SymbolicConstant(c, "NewYork", "int",
                                 Value(int(QGradient::NewYork))),
            new SymbolicConstant(c, "ShyRainbow", "int",
                                 Value(int(QGradient::ShyRainbow))),
            new SymbolicConstant(c, "MixedHopes", "int",
                                 Value(int(QGradient::MixedHopes))),
            new SymbolicConstant(c, "FlyHigh", "int",
                                 Value(int(QGradient::FlyHigh))),
            new SymbolicConstant(c, "StrongBliss", "int",
                                 Value(int(QGradient::StrongBliss))),
            new SymbolicConstant(c, "FreshMilk", "int",
                                 Value(int(QGradient::FreshMilk))),
            new SymbolicConstant(c, "SnowAgain", "int",
                                 Value(int(QGradient::SnowAgain))),
            new SymbolicConstant(c, "FebruaryInk", "int",
                                 Value(int(QGradient::FebruaryInk))),
            new SymbolicConstant(c, "KindSteel", "int",
                                 Value(int(QGradient::KindSteel))),
            new SymbolicConstant(c, "SoftGrass", "int",
                                 Value(int(QGradient::SoftGrass))),
            new SymbolicConstant(c, "GrownEarly", "int",
                                 Value(int(QGradient::GrownEarly))),
            new SymbolicConstant(c, "SharpBlues", "int",
                                 Value(int(QGradient::SharpBlues))),
            new SymbolicConstant(c, "ShadyWater", "int",
                                 Value(int(QGradient::ShadyWater))),
            new SymbolicConstant(c, "DirtyBeauty", "int",
                                 Value(int(QGradient::DirtyBeauty))),
            new SymbolicConstant(c, "GreatWhale", "int",
                                 Value(int(QGradient::GreatWhale))),
            new SymbolicConstant(c, "TeenNotebook", "int",
                                 Value(int(QGradient::TeenNotebook))),
            new SymbolicConstant(c, "PoliteRumors", "int",
                                 Value(int(QGradient::PoliteRumors))),
            new SymbolicConstant(c, "SweetPeriod", "int",
                                 Value(int(QGradient::SweetPeriod))),
            new SymbolicConstant(c, "WideMatrix", "int",
                                 Value(int(QGradient::WideMatrix))),
            new SymbolicConstant(c, "SoftCherish", "int",
                                 Value(int(QGradient::SoftCherish))),
            new SymbolicConstant(c, "RedSalvation", "int",
                                 Value(int(QGradient::RedSalvation))),
            new SymbolicConstant(c, "BurningSpring", "int",
                                 Value(int(QGradient::BurningSpring))),
            new SymbolicConstant(c, "NightParty", "int",
                                 Value(int(QGradient::NightParty))),
            new SymbolicConstant(c, "SkyGlider", "int",
                                 Value(int(QGradient::SkyGlider))),
            new SymbolicConstant(c, "HeavenPeach", "int",
                                 Value(int(QGradient::HeavenPeach))),
            new SymbolicConstant(c, "PurpleDivision", "int",
                                 Value(int(QGradient::PurpleDivision))),
            new SymbolicConstant(c, "AquaSplash", "int",
                                 Value(int(QGradient::AquaSplash))),
            new SymbolicConstant(c, "SpikyNaga", "int",
                                 Value(int(QGradient::SpikyNaga))),
            new SymbolicConstant(c, "LoveKiss", "int",
                                 Value(int(QGradient::LoveKiss))),
            new SymbolicConstant(c, "CleanMirror", "int",
                                 Value(int(QGradient::CleanMirror))),
            new SymbolicConstant(c, "PremiumDark", "int",
                                 Value(int(QGradient::PremiumDark))),
            new SymbolicConstant(c, "ColdEvening", "int",
                                 Value(int(QGradient::ColdEvening))),
            new SymbolicConstant(c, "CochitiLake", "int",
                                 Value(int(QGradient::CochitiLake))),
            new SymbolicConstant(c, "SummerGames", "int",
                                 Value(int(QGradient::SummerGames))),
            new SymbolicConstant(c, "PassionateBed", "int",
                                 Value(int(QGradient::PassionateBed))),
            new SymbolicConstant(c, "MountainRock", "int",
                                 Value(int(QGradient::MountainRock))),
            new SymbolicConstant(c, "DesertHump", "int",
                                 Value(int(QGradient::DesertHump))),
            new SymbolicConstant(c, "JungleDay", "int",
                                 Value(int(QGradient::JungleDay))),
            new SymbolicConstant(c, "PhoenixStart", "int",
                                 Value(int(QGradient::PhoenixStart))),
            new SymbolicConstant(c, "OctoberSilence", "int",
                                 Value(int(QGradient::OctoberSilence))),
            new SymbolicConstant(c, "FarawayRiver", "int",
                                 Value(int(QGradient::FarawayRiver))),
            new SymbolicConstant(c, "AlchemistLab", "int",
                                 Value(int(QGradient::AlchemistLab))),
            new SymbolicConstant(c, "OverSun", "int",
                                 Value(int(QGradient::OverSun))),
            new SymbolicConstant(c, "PremiumWhite", "int",
                                 Value(int(QGradient::PremiumWhite))),
            new SymbolicConstant(c, "MarsParty", "int",
                                 Value(int(QGradient::MarsParty))),
            new SymbolicConstant(c, "EternalConstance", "int",
                                 Value(int(QGradient::EternalConstance))),
            new SymbolicConstant(c, "JapanBlush", "int",
                                 Value(int(QGradient::JapanBlush))),
            new SymbolicConstant(c, "SmilingRain", "int",
                                 Value(int(QGradient::SmilingRain))),
            new SymbolicConstant(c, "CloudyApple", "int",
                                 Value(int(QGradient::CloudyApple))),
            new SymbolicConstant(c, "BigMango", "int",
                                 Value(int(QGradient::BigMango))),
            new SymbolicConstant(c, "HealthyWater", "int",
                                 Value(int(QGradient::HealthyWater))),
            new SymbolicConstant(c, "AmourAmour", "int",
                                 Value(int(QGradient::AmourAmour))),
            new SymbolicConstant(c, "RiskyConcrete", "int",
                                 Value(int(QGradient::RiskyConcrete))),
            new SymbolicConstant(c, "StrongStick", "int",
                                 Value(int(QGradient::StrongStick))),
            new SymbolicConstant(c, "ViciousStance", "int",
                                 Value(int(QGradient::ViciousStance))),
            new SymbolicConstant(c, "PaloAlto", "int",
                                 Value(int(QGradient::PaloAlto))),
            new SymbolicConstant(c, "HappyMemories", "int",
                                 Value(int(QGradient::HappyMemories))),
            new SymbolicConstant(c, "MidnightBloom", "int",
                                 Value(int(QGradient::MidnightBloom))),
            new SymbolicConstant(c, "Crystalline", "int",
                                 Value(int(QGradient::Crystalline))),
            new SymbolicConstant(c, "PartyBliss", "int",
                                 Value(int(QGradient::PartyBliss))),
            new SymbolicConstant(c, "ConfidentCloud", "int",
                                 Value(int(QGradient::ConfidentCloud))),
            new SymbolicConstant(c, "LeCocktail", "int",
                                 Value(int(QGradient::LeCocktail))),
            new SymbolicConstant(c, "RiverCity", "int",
                                 Value(int(QGradient::RiverCity))),
            new SymbolicConstant(c, "FrozenBerry", "int",
                                 Value(int(QGradient::FrozenBerry))),
            new SymbolicConstant(c, "ChildCare", "int",
                                 Value(int(QGradient::ChildCare))),
            new SymbolicConstant(c, "FlyingLemon", "int",
                                 Value(int(QGradient::FlyingLemon))),
            new SymbolicConstant(c, "NewRetrowave", "int",
                                 Value(int(QGradient::NewRetrowave))),
            new SymbolicConstant(c, "HiddenJaguar", "int",
                                 Value(int(QGradient::HiddenJaguar))),
            new SymbolicConstant(c, "AboveTheSky", "int",
                                 Value(int(QGradient::AboveTheSky))),
            new SymbolicConstant(c, "Nega", "int", Value(int(QGradient::Nega))),
            new SymbolicConstant(c, "DenseWater", "int",
                                 Value(int(QGradient::DenseWater))),
            new SymbolicConstant(c, "Seashore", "int",
                                 Value(int(QGradient::Seashore))),
            new SymbolicConstant(c, "MarbleWall", "int",
                                 Value(int(QGradient::MarbleWall))),
            new SymbolicConstant(c, "CheerfulCaramel", "int",
                                 Value(int(QGradient::CheerfulCaramel))),
            new SymbolicConstant(c, "NightSky", "int",
                                 Value(int(QGradient::NightSky))),
            new SymbolicConstant(c, "MagicLake", "int",
                                 Value(int(QGradient::MagicLake))),
            new SymbolicConstant(c, "YoungGrass", "int",
                                 Value(int(QGradient::YoungGrass))),
            new SymbolicConstant(c, "ColorfulPeach", "int",
                                 Value(int(QGradient::ColorfulPeach))),
            new SymbolicConstant(c, "GentleCare", "int",
                                 Value(int(QGradient::GentleCare))),
            new SymbolicConstant(c, "PlumBath", "int",
                                 Value(int(QGradient::PlumBath))),
            new SymbolicConstant(c, "HappyUnicorn", "int",
                                 Value(int(QGradient::HappyUnicorn))),
            new SymbolicConstant(c, "AfricanField", "int",
                                 Value(int(QGradient::AfricanField))),
            new SymbolicConstant(c, "SolidStone", "int",
                                 Value(int(QGradient::SolidStone))),
            new SymbolicConstant(c, "OrangeJuice", "int",
                                 Value(int(QGradient::OrangeJuice))),
            new SymbolicConstant(c, "GlassWater", "int",
                                 Value(int(QGradient::GlassWater))),
            new SymbolicConstant(c, "NorthMiracle", "int",
                                 Value(int(QGradient::NorthMiracle))),
            new SymbolicConstant(c, "FruitBlend", "int",
                                 Value(int(QGradient::FruitBlend))),
            new SymbolicConstant(c, "MillenniumPine", "int",
                                 Value(int(QGradient::MillenniumPine))),
            new SymbolicConstant(c, "HighFlight", "int",
                                 Value(int(QGradient::HighFlight))),
            new SymbolicConstant(c, "MoleHall", "int",
                                 Value(int(QGradient::MoleHall))),
            new SymbolicConstant(c, "SpaceShift", "int",
                                 Value(int(QGradient::SpaceShift))),
            new SymbolicConstant(c, "ForestInei", "int",
                                 Value(int(QGradient::ForestInei))),
            new SymbolicConstant(c, "RoyalGarden", "int",
                                 Value(int(QGradient::RoyalGarden))),
            new SymbolicConstant(c, "RichMetal", "int",
                                 Value(int(QGradient::RichMetal))),
            new SymbolicConstant(c, "JuicyCake", "int",
                                 Value(int(QGradient::JuicyCake))),
            new SymbolicConstant(c, "SmartIndigo", "int",
                                 Value(int(QGradient::SmartIndigo))),
            new SymbolicConstant(c, "SandStrike", "int",
                                 Value(int(QGradient::SandStrike))),
            new SymbolicConstant(c, "NorseBeauty", "int",
                                 Value(int(QGradient::NorseBeauty))),
            new SymbolicConstant(c, "AquaGuidance", "int",
                                 Value(int(QGradient::AquaGuidance))),
            new SymbolicConstant(c, "SunVeggie", "int",
                                 Value(int(QGradient::SunVeggie))),
            new SymbolicConstant(c, "SeaLord", "int",
                                 Value(int(QGradient::SeaLord))),
            new SymbolicConstant(c, "BlackSea", "int",
                                 Value(int(QGradient::BlackSea))),
            new SymbolicConstant(c, "GrassShampoo", "int",
                                 Value(int(QGradient::GrassShampoo))),
            new SymbolicConstant(c, "LandingAircraft", "int",
                                 Value(int(QGradient::LandingAircraft))),
            new SymbolicConstant(c, "WitchDance", "int",
                                 Value(int(QGradient::WitchDance))),
            new SymbolicConstant(c, "SleeplessNight", "int",
                                 Value(int(QGradient::SleeplessNight))),
            new SymbolicConstant(c, "AngelCare", "int",
                                 Value(int(QGradient::AngelCare))),
            new SymbolicConstant(c, "CrystalRiver", "int",
                                 Value(int(QGradient::CrystalRiver))),
            new SymbolicConstant(c, "SoftLipstick", "int",
                                 Value(int(QGradient::SoftLipstick))),
            new SymbolicConstant(c, "SaltMountain", "int",
                                 Value(int(QGradient::SaltMountain))),
            new SymbolicConstant(c, "PerfectWhite", "int",
                                 Value(int(QGradient::PerfectWhite))),
            new SymbolicConstant(c, "FreshOasis", "int",
                                 Value(int(QGradient::FreshOasis))),
            new SymbolicConstant(c, "StrictNovember", "int",
                                 Value(int(QGradient::StrictNovember))),
            new SymbolicConstant(c, "MorningSalad", "int",
                                 Value(int(QGradient::MorningSalad))),
            new SymbolicConstant(c, "DeepRelief", "int",
                                 Value(int(QGradient::DeepRelief))),
            new SymbolicConstant(c, "SeaStrike", "int",
                                 Value(int(QGradient::SeaStrike))),
            new SymbolicConstant(c, "NightCall", "int",
                                 Value(int(QGradient::NightCall))),
            new SymbolicConstant(c, "SupremeSky", "int",
                                 Value(int(QGradient::SupremeSky))),
            new SymbolicConstant(c, "LightBlue", "int",
                                 Value(int(QGradient::LightBlue))),
            new SymbolicConstant(c, "MindCrawl", "int",
                                 Value(int(QGradient::MindCrawl))),
            new SymbolicConstant(c, "LilyMeadow", "int",
                                 Value(int(QGradient::LilyMeadow))),
            new SymbolicConstant(c, "SugarLollipop", "int",
                                 Value(int(QGradient::SugarLollipop))),
            new SymbolicConstant(c, "SweetDessert", "int",
                                 Value(int(QGradient::SweetDessert))),
            new SymbolicConstant(c, "MagicRay", "int",
                                 Value(int(QGradient::MagicRay))),
            new SymbolicConstant(c, "TeenParty", "int",
                                 Value(int(QGradient::TeenParty))),
            new SymbolicConstant(c, "FrozenHeat", "int",
                                 Value(int(QGradient::FrozenHeat))),
            new SymbolicConstant(c, "GagarinView", "int",
                                 Value(int(QGradient::GagarinView))),
            new SymbolicConstant(c, "FabledSunset", "int",
                                 Value(int(QGradient::FabledSunset))),
            new SymbolicConstant(c, "PerfectBlue", "int",
                                 Value(int(QGradient::PerfectBlue))),
            new Alias(c, "Spread", "int"),
            new SymbolicConstant(c, "PadSpread", "int",
                                 Value(int(QGradient::PadSpread))),
            new SymbolicConstant(c, "RepeatSpread", "int",
                                 Value(int(QGradient::RepeatSpread))),
            new SymbolicConstant(c, "ReflectSpread", "int",
                                 Value(int(QGradient::ReflectSpread))),
            new Alias(c, "Type", "int"),
            new SymbolicConstant(c, "LinearGradient", "int",
                                 Value(int(QGradient::LinearGradient))),
            new SymbolicConstant(c, "RadialGradient", "int",
                                 Value(int(QGradient::RadialGradient))),
            new SymbolicConstant(c, "ConicalGradient", "int",
                                 Value(int(QGradient::ConicalGradient))),
            new SymbolicConstant(c, "NoGradient", "int",
                                 Value(int(QGradient::NoGradient))),
            EndArguments);

        addSymbols(
            // enums
            // member functions
            new Function(c, "QGradient", _n_QGradient0, None, Compiled,
                         qt_QGradient_QGradient_QGradient_QGradient_int, Return,
                         "qt.QGradient", Parameters,
                         new Param(c, "this", "qt.QGradient"),
                         new Param(c, "preset", "int"), End),
            new Function(c, "coordinateMode", _n_coordinateMode0, None,
                         Compiled, qt_QGradient_coordinateMode_int_QGradient,
                         Return, "int", Parameters,
                         new Param(c, "this", "qt.QGradient"), End),
            new Function(c, "setColorAt", _n_setColorAt0, None, Compiled,
                         qt_QGradient_setColorAt_void_QGradient_double_QColor,
                         Return, "void", Parameters,
                         new Param(c, "this", "qt.QGradient"),
                         new Param(c, "position", "double"),
                         new Param(c, "color", "qt.QColor"), End),
            new Function(
                c, "setCoordinateMode", _n_setCoordinateMode0, None, Compiled,
                qt_QGradient_setCoordinateMode_void_QGradient_int, Return,
                "void", Parameters, new Param(c, "this", "qt.QGradient"),
                new Param(c, "mode", "int"), End),
            new Function(c, "setSpread", _n_setSpread0, None, Compiled,
                         qt_QGradient_setSpread_void_QGradient_int, Return,
                         "void", Parameters,
                         new Param(c, "this", "qt.QGradient"),
                         new Param(c, "method", "int"), End),
            // MISSING: setStops (void; QGradient this, "const QGradientStops &"
            // stopPoints)
            new Function(c, "spread", _n_spread0, None, Compiled,
                         qt_QGradient_spread_int_QGradient, Return, "int",
                         Parameters, new Param(c, "this", "qt.QGradient"), End),
            // MISSING: stops ("QGradientStops"; QGradient this)
            new Function(c, "type", _n_type0, None, Compiled,
                         qt_QGradient_type_int_QGradient, Return, "int",
                         Parameters, new Param(c, "this", "qt.QGradient"), End),
            // static functions
            EndArguments);
        globalScope()->addSymbols(
            new Function(c, "!=", _n_operatorBang_EQ_0, Op, Compiled,
                         qt_QGradient_operatorBang_EQ__bool_QGradient_QGradient,
                         Return, "bool", Parameters,
                         new Param(c, "this", "qt.QGradient"),
                         new Param(c, "gradient", "qt.QGradient"), End),
            new Function(c, "==", _n_operatorEQ_EQ_0, Op, Compiled,
                         qt_QGradient_operatorEQ_EQ__bool_QGradient_QGradient,
                         Return, "bool", Parameters,
                         new Param(c, "this", "qt.QGradient"),
                         new Param(c, "gradient", "qt.QGradient"), End),
            EndArguments);
        scope()->addSymbols(EndArguments);

        //
        // Copyright (C) 2023  Autodesk, Inc. All Rights Reserved.
        //
        // SPDX-License-Identifier: Apache-2.0
        //

        // MISSING: setStops (void; QGradient this, "const QGradientStops &"
        // stopPoints) MISSING: stops ("QGradientStops"; QGradient this)
        //
        //  the tuple and array are created in QColorSymbols.cpp

        addSymbol(new Function(
            c, "setStops", setStops, None,
            // Compiled, QGradient_setStops_,
            Return, "int", Parameters, new Param(c, "this", "qt.QGradient"),
            new Param(c, "this", "(double,qt.QColor)[]"), End));

        addSymbol(new Function(c, "stops", stops, None,
                               // Compiled, QGradient_stops_,
                               Return, "(double,qt.QColor)[]", Parameters,
                               new Param(c, "this", "qt.QGradient"), End));
    }

} // namespace Mu
