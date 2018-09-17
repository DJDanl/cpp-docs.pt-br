---
title: Compilando programas C/C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- vcbuilding
- buildingaprogramVC
dev_langs:
- C++
helpviewer_keywords:
- builds [C++]
- Visual C++ projects, building
- projects [C++], building
- builds [C++], options
- Visual C++, build options
ms.assetid: fa6ed4ff-334a-4d99-b5e2-a1f83d2b3008
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2792b49d7d3d3f107e39931ff62e6c4137c9c5ca
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723258"
---
# <a name="building-cc-programs"></a>Compilando programas do C/C++

Você pode compilar projetos do Visual C++ no Visual Studio ou na linha de comando. O IDE do Visual Studio usa [MSBuild](../build/msbuild-visual-cpp.md) para compilar projetos e soluções. Na linha de comando, você pode usar o compilador C/C++ (cl.exe) e o vinculador (link.exe) para compilar projetos simples. Para compilar projetos mais complexos na linha de comando, você pode usar o MSBuild ou [NMAKE](../build/nmake-reference.md). Para obter uma visão geral sobre como usar o Visual Studio para compilar projetos e soluções, consulte [compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio).

## <a name="in-this-section"></a>Nesta seção

[Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md) discute como usar o IDE do Visual Studio para compilar seu projeto do C/C++.

[Compilar código C/C++ na linha de comando](../build/building-on-the-command-line.md) discute como usar o compilador de linha de comando C/C++ e criar ferramentas que estão incluídas no Visual Studio.

[Compilando aplicativos isolados do C/C++ e Assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md) descreve o modelo de implantação para aplicativos de área de trabalho do Windows, com base na ideia de aplicativos isolados e assemblies lado a lado.

[Referência de criação de C/C++](../build/reference/c-cpp-building-reference.md) fornece links para artigos de referência sobre compilação de programa em C++, o compilador e as opções do vinculador, e várias ferramentas de compilação.

[Configurar o Visual C++ para x64 de 64 bits, destinos](../build/configuring-programs-for-64-bit-visual-cpp.md) descreve como configurar o Visual Studio e a linha de comando para usar o conjunto de ferramentas de 64 bits e visar arquiteturas de 64 bits e discute problemas comuns na migração quando o código é transferido para 64 bits arquiteturas.

[Configurar o Visual C++ para processadores ARM](../build/configuring-programs-for-arm-processors-visual-cpp.md) descreve as convenções usadas por processadores ARM e discute problemas comuns na migração quando o código é transferido para arquiteturas ARM.

[Configurando programas para Windows XP](../build/configuring-programs-for-windows-xp.md) descreve como definir o conjunto de ferramentas de plataforma para direcionar o desenvolvimento do Windows XP.

## <a name="related-sections"></a>Seções relacionadas

[Compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio) descreve o Visual Studio compilar ferramentas e sistema.