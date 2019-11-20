---
title: Microsoft C++ porting and upgrading guide
description: Upgrade Microsoft C++ code to the latest version of Visual Studio.
ms.date: 11/18/2019
ms.assetid: f5fbcc3d-aa72-41a6-ad9a-a706af2166fb
ms.topic: overview
ms.openlocfilehash: 88b5b31428979d26bbbf810c4c04c99f411dbcbb
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74189334"
---
# <a name="microsoft-c-porting-and-upgrading-guide"></a>Microsoft C++ porting and upgrading guide

This article provides a guide for upgrading Microsoft C++ code to the latest version of Visual Studio. For projects created in Visual Studio 2010 through 2015, just open the project in Visual Studio 2019. You can upgrade a Visual Studio 2008 or earlier project in two steps. Use Visual Studio 2010 to convert the project to MSBuild format first. Then open the project in Visual Studio 2019. For complete instructions, see [Upgrading C++ projects from earlier versions of Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md).

The toolsets in Visual Studio 2015, Visual Studio 2017, and Visual Studio 2019 are binary-compatible. Now you can upgrade to a more recent version of the compiler without having to upgrade your library dependencies. For more information, see [C++ binary compatibility 2015-2019](binary-compat-2015-2017.md).

When upgrading projects that use open-source libraries or are meant to run on multiple platforms, we recommended migrating to a CMake-based project. For more information, see [CMake projects in Visual Studio](../build/cmake-projects-in-visual-studio.md)

## <a name="reasons-to-upgrade-c-code"></a>Reasons to upgrade C++ code

If a legacy application is running satisfactorily, in a secure environment, and isn't under active development, there might not be much incentive to upgrade it. However, consider an upgrade in these cases: Your application requires ongoing maintenance. Or, you're doing new feature development, or making performance or security improvements. An upgrade brings these benefits:

- The same code can run faster, because we've improved compiler optimizations.

- Modern C++ features and programming practices eliminate many common causes of bugs, and produce code that's far easier to maintain than older C-style idioms.

- Build times are faster, because of performance improvements in the compiler and linker.

- Better standards conformance. The [/permissive-](../build/reference/permissive-standards-conformance.md) compiler option helps you identify code that doesn't conform to the current C++ standard.

- Better run-time security, including more secure [C Runtime library]() features. And, compiler features such as [guard checking](../build/reference/guard-enable-guard-checks.md) and address sanitizers (new in Visual Studio 2019 version 16.4).

## <a name="multitargeting-vs-upgrading"></a>Multitargeting vs. upgrading

Perhaps upgrading your code base to a new toolset isn't an option for you. You can still use the latest Visual Studio to build and edit projects that use older toolsets and libraries. In Visual Studio 2019, you can take advantage of features such as:

- modern static analysis tools, including the C++ Core Guidelines checkers and Clang-Tidy, to help identify potential problems in your source code.

- automatic formatting according to your choice of modern styles can help make legacy code much more readable.

Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md).

## <a name="in-this-section"></a>Nesta seção

|Título|Descrição|
|-----------|-----------------|
|[Upgrading C++ projects from earlier versions of Visual Studio](upgrading-projects-from-earlier-versions-of-visual-cpp.md)|How to upgrade your code base to Visual Studio 2019 and v142 of the compiler.|
|[IDE tools for upgrading C++ code](ide-tools-for-upgrading-code.md)|Useful IDE features that help in the upgrade process.|
|[C++ binary compatibility 2015-2019](binary-compat-2015-2017.md)|Consume v140 and v141 libraries as-is from v142 projects.|
|[Usar direcionamento múltiplo nativo no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md)|Use Visual Studio 2019 with older compilers and libraries.|
|[Histórico de alterações de 2003 a 2015 do Visual C++](visual-cpp-change-history-2003-2015.md)|A list of all the changes in the Microsoft C++ libraries and build tools from Visual Studio 2003 through 2015 that might require changes in your code.|
|[O que há de novo no Visual C++ de 2003 até 2015](visual-cpp-what-s-new-2003-through-2015.md)|All the "what's new" information for Microsoft C++ from Visual Studio 2003 through Visual Studio 2015.|
|[Portabilidade e atualização: exemplos e estudos de caso](porting-and-upgrading-examples-and-case-studies.md)|Nessa seção, portamos e atualizamos vários exemplos e aplicativos e discutimos as experiências e os resultados. These articles give you a sense of what's involved in the porting and upgrading process. Durante o processo, discutimos a respeito de dicas e truques para a atualização e mostramos como erros específicos foram corrigidos.|
|[Portabilidade para a Plataforma Universal do Windows](porting-to-the-universal-windows-platform-cpp.md)|Contém informações sobre como fazer portabilidade de código para o Windows 10|
|[Introdução ao Visual C++ para usuários do UNIX](introduction-to-visual-cpp-for-unix-users.md)|Fornece informações para usuários do UNIX novatos no Visual C++ e que desejam tornar-se produtivos com ele.|
|[Running Linux programs on Windows](porting-from-unix-to-win32.md)|Discute as opções para migrar aplicativos UNIX para o Windows.|

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)<br/>
[Novidades do compilador C++ no Visual Studio](../overview/what-s-new-for-visual-cpp-in-visual-studio.md)<br/>
[Aprimoramentos de conformidade do C++ no Visual Studio](../overview/cpp-conformance-improvements.md)<br/>
