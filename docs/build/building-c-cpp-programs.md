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
ms.openlocfilehash: 3fd4bdeb73a2b2979a93a051c3ee490659b5248b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392496"
---
# <a name="building-cc-programs"></a>Compilando programas do C/C++

Você pode compilar projetos do Visual C++ no Visual Studio ou na linha de comando. O IDE do Visual Studio usa [MSBuild](../build/msbuild-visual-cpp.md) para compilar projetos e soluções. Na linha de comando, você pode usar o compilador C/C++ (cl.exe) e o vinculador (link.exe) para compilar projetos simples. Para compilar projetos mais complexos na linha de comando, você pode usar o MSBuild ou [NMAKE](../build/nmake-reference.md). Para obter uma visão geral sobre como usar o Visual Studio para compilar projetos e soluções, consulte [compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio).

## <a name="in-this-section"></a>Nesta seção

[Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)<br/>
Discute como usar o ambiente de desenvolvimento interativo (IDE) do Visual Studio para compilar seu projeto C/C++.

[Compilar código C/C++ na linha de comando](../build/building-on-the-command-line.md)<br/>
Discute como usar o compilador da linha de comando C/C++ e as ferramentas de compilação incluídas no Visual Studio.

[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)<br/>
Descreve o modelo de implantação de aplicativos para Windows Desktop, com base na ideia de aplicativos isolados e assemblies lado a lado.

[Referência de build C/C++](../build/reference/c-cpp-building-reference.md)<br/>
Fornece links para artigos de referência sobre compilação de programa em C++, opções de compilador e vinculador, e outras ferramentas de compilação.

[Configurar o Visual C++ para destinos x64 de 64 bits](../build/configuring-programs-for-64-bit-visual-cpp.md)<br/>
Descreve como configurar o Visual Studio e a linha de comando para usar o conjunto de ferramentas de 64 bits e visar arquiteturas de 64 bits, além de discutir os problemas comuns na migração quando o código é transferido para arquiteturas de 64 bits.

[Configurar o Visual C++ para processadores ARM](../build/configuring-programs-for-arm-processors-visual-cpp.md)<br/>
Descreve as convenções usadas por processadores ARM e discute problemas comuns na migração quando o código é movido para arquiteturas ARM.

[Configurando programas para Windows XP](../build/configuring-programs-for-windows-xp.md)<br/>
Descreve como configurar o Conjunto de Ferramentas da Plataforma para visar o desenvolvimento do Windows XP.

## <a name="related-sections"></a>Seções relacionadas

[Compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio)<br/>
Descreve as ferramentas e o sistema de compilação do Visual Studio.