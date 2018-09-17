---
title: Criação de C/C++ de aplicativos isolados e Assemblies lado a lado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- isolated applications [C++]
- WinSxS [C++]
- native assembly cache [C++]
- builds [C++], isolated applications
- side-by-side applications [C++]
- builds [C++], side-by-side assemblies
ms.assetid: 9465904e-76f7-48bd-bb3f-c55d8f1699b6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b3327f4d0ae20b13c97ea0916e7a2c86e7006dd
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710093"
---
# <a name="building-cc-isolated-applications-and-side-by-side-assemblies"></a>Compilando aplicativos isolados do C/C++ e assemblies lado a lado

Visual C++ oferece suporte a um modelo de implantação para aplicativos de cliente do Windows com base na ideia de [aplicativos isolados](/windows/desktop/SbsCs/isolated-applications) e [assemblies lado a lado](/windows/desktop/SbsCs/about-side-by-side-assemblies-). Por padrão, o Visual C++ compila todos os aplicativos C/C++ nativos como aplicativos isolados que usam [manifestos](https://msdn.microsoft.com/library/aa375365) para descrever suas dependências em bibliotecas do Visual C++.

A compilação de programas do C/C++ como aplicativos isolados apresenta muitas vantagens. Por exemplo, um aplicativo isolado não é afetado quando outros aplicativos do C/C++ instalam ou desinstalam bibliotecas do Visual C++. Bibliotecas do Visual C++ usadas por aplicativos isolados ainda podem ser redistribuídas na pasta local do aplicativo ou pela instalação para o cache de assembly nativo (WinSxS); No entanto, a manutenção das bibliotecas do Visual C++ para aplicativos já implantados podem ser simplificados usando um [arquivo de configuração de publicador](/windows/desktop/SbsCs/publisher-configuration). O modelo de implantação do aplicativo isolado facilita a garantia de que os aplicativos do C/C++ em execução em um computador específico usam a versão mais recente das bibliotecas do Visual C++, enquanto mantém aberta a possibilidade dos administradores de sistema e dos autores de aplicativos controlarem a associação de versão explícita dos aplicativos para suas DLLs dependentes.

Esta seção aborda como é possível compilar o aplicativo do C/C++ como um aplicativo isolado e garantir que ele seja associado a bibliotecas do Visual C++ com um manifesto. As informações desta seção se aplicam principalmente a aplicativos do Visual C++ nativos ou não gerenciados. Para obter informações sobre como implantar aplicativos nativos compilados com o Visual C++, consulte [redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md).

## <a name="in-this-section"></a>Nesta seção

[Conceitos de aplicativos isolados e assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)

[Compilando aplicativos isolados do C/C++](../build/building-c-cpp-isolated-applications.md)

[Compilando assemblies lado a lado do C/C++](../build/building-c-cpp-side-by-side-assemblies.md)

[Como compilar componentes COM sem registro](../build/how-to-build-registration-free-com-components.md)

[Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)

[Noções básicas sobre o Manifest Generation para programas do C/C++](../build/understanding-manifest-generation-for-c-cpp-programs.md)

[Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)

## <a name="related-sections"></a>Seções relacionadas

[Aplicativos isolados e Assemblies lado a lado](/windows/desktop/SbsCs/isolated-applications-and-side-by-side-assemblies-portal)

[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)