---
title: Compilando aplicativos isolados do C/C++ e assemblies lado a lado
ms.date: 11/04/2016
helpviewer_keywords:
- isolated applications [C++]
- WinSxS [C++]
- native assembly cache [C++]
- builds [C++], isolated applications
- side-by-side applications [C++]
- builds [C++], side-by-side assemblies
ms.assetid: 9465904e-76f7-48bd-bb3f-c55d8f1699b6
ms.openlocfilehash: b962796c3bf32bc312d3047535ae90a40a37094d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58772456"
---
# <a name="building-cc-isolated-applications-and-side-by-side-assemblies"></a>Compilando aplicativos isolados do C/C++ e assemblies lado a lado

Visual C++ oferece suporte a um modelo de implantação para aplicativos de cliente do Windows com base na ideia de [aplicativos isolados](/windows/desktop/SbsCs/isolated-applications) e [assemblies lado a lado](/windows/desktop/SbsCs/about-side-by-side-assemblies-). Por padrão, o Visual C++ compila todos os aplicativos C/C++ nativos como aplicativos isolados que usam [manifestos](/windows/desktop/sbscs/manifests) para descrever suas dependências em bibliotecas do Visual C++.

A compilação de programas do C/C++ como aplicativos isolados apresenta muitas vantagens. Por exemplo, um aplicativo isolado não é afetado quando outros aplicativos do C/C++ instalam ou desinstalam bibliotecas do Visual C++. Bibliotecas do Visual C++ usadas por aplicativos isolados ainda podem ser redistribuídas na pasta local do aplicativo ou pela instalação para o cache de assembly nativo (WinSxS); No entanto, a manutenção das bibliotecas do Visual C++ para aplicativos já implantados podem ser simplificados usando um [arquivo de configuração de publicador](/windows/desktop/SbsCs/publisher-configuration). O modelo de implantação do aplicativo isolado facilita a garantia de que os aplicativos do C/C++ em execução em um computador específico usam a versão mais recente das bibliotecas do Visual C++, enquanto mantém aberta a possibilidade dos administradores de sistema e dos autores de aplicativos controlarem a associação de versão explícita dos aplicativos para suas DLLs dependentes.

Esta seção aborda como é possível compilar o aplicativo do C/C++ como um aplicativo isolado e garantir que ele seja associado a bibliotecas do Visual C++ com um manifesto. As informações desta seção se aplicam principalmente a aplicativos do Visual C++ nativos ou não gerenciados. Para obter informações sobre como implantar aplicativos nativos compilados com o Visual C++, consulte [redistribuindo arquivos do Visual C++](../windows/redistributing-visual-cpp-files.md).

## <a name="in-this-section"></a>Nesta seção

[Conceitos de aplicativos isolados e assemblies lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)

[Compilando aplicativos isolados do C/C++](building-c-cpp-isolated-applications.md)

[Compilando assemblies lado a lado do C/C++](building-c-cpp-side-by-side-assemblies.md)

[Como: Compilar componentes COM sem registro](how-to-build-registration-free-com-components.md)

[Como: Compilar aplicativos isolados para consumir componentes COM](how-to-build-isolated-applications-to-consume-com-components.md)

[Noções básicas sobre o Manifest Generation para programas do C/C++](understanding-manifest-generation-for-c-cpp-programs.md)

[Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)

## <a name="related-sections"></a>Seções relacionadas

[Aplicativos isolados e Assemblies lado a lado](/windows/desktop/SbsCs/isolated-applications-and-side-by-side-assemblies-portal)

[Implantando aplicativos da área de trabalho](../windows/deploying-native-desktop-applications-visual-cpp.md)