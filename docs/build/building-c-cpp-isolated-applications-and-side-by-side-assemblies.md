---
title: Compilando aplicativos isolados do C/C++ e assemblies lado a lado
ms.date: 05/06/2019
helpviewer_keywords:
- isolated applications [C++]
- WinSxS [C++]
- native assembly cache [C++]
- builds [C++], isolated applications
- side-by-side applications [C++]
- builds [C++], side-by-side assemblies
ms.assetid: 9465904e-76f7-48bd-bb3f-c55d8f1699b6
ms.openlocfilehash: db2978c054362b6c329fb786d0f7da322d4c9201
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169871"
---
# <a name="building-cc-isolated-applications-and-side-by-side-assemblies"></a>Compilando aplicativos isolados do C/C++ e assemblies lado a lado

O Visual Studio dá suporte a um modelo de implantação para aplicativos cliente do Windows com base na ideia de [aplicativos isolados](/windows/win32/SbsCs/isolated-applications) e assemblies lado a [lado](/windows/win32/SbsCs/about-side-by-side-assemblies-). Por padrão, o Visual Studio compila todos os aplicativos nativos C/C++ como aplicativos isolados que usam [manifestos](/windows/win32/sbscs/manifests) para descrever suas dependências em bibliotecas de Visual C++.

A compilação de programas do C/C++ como aplicativos isolados apresenta muitas vantagens. Por exemplo, um aplicativo isolado não é afetado quando outros aplicativos do C/C++ instalam ou desinstalam bibliotecas do Visual C++. Visual C++ bibliotecas usadas por aplicativos isolados ainda podem ser redistribuídas na pasta local do aplicativo ou por instalação no cache de assembly nativo (WinSxS); no entanto, a manutenção de bibliotecas de Visual C++ para aplicativos já implantados pode ser simplificada usando um [arquivo de configuração de Publicador](/windows/win32/SbsCs/publisher-configuration). O modelo de implantação do aplicativo isolado facilita a garantia de que os aplicativos do C/C++ em execução em um computador específico usam a versão mais recente das bibliotecas do Visual C++, enquanto mantém aberta a possibilidade dos administradores de sistema e dos autores de aplicativos controlarem a associação de versão explícita dos aplicativos para suas DLLs dependentes.

Esta seção aborda como é possível compilar o aplicativo do C/C++ como um aplicativo isolado e garantir que ele seja associado a bibliotecas do Visual C++ com um manifesto. As informações nesta seção se aplicam principalmente a aplicativos C++ nativos ou não gerenciados. Para obter informações sobre como implantar aplicativos C++ nativos criados com o Visual Studio, consulte [redistribuindo Visual C++ arquivos](../windows/redistributing-visual-cpp-files.md).

## <a name="in-this-section"></a>Nesta seção

[Conceitos de aplicativos isolados e assemblies lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)

[Criando aplicativos isolados C/C++](building-c-cpp-isolated-applications.md)

[Compilando assemblies lado a lado do C/C++](building-c-cpp-side-by-side-assemblies.md)

[Como compilar componentes COM sem registro](how-to-build-registration-free-com-components.md)

[Como compilar aplicativos isolados para consumir componentes COM](how-to-build-isolated-applications-to-consume-com-components.md)

[Entendendo a geração de manifesto para programas C/C++](understanding-manifest-generation-for-c-cpp-programs.md)

[Solução de problemas de aplicativos isolados C/C++ e assemblies lado a lado](troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)

## <a name="related-sections"></a>Seções relacionadas

[Aplicativos isolados e assemblies lado a lado](/windows/win32/SbsCs/isolated-applications-and-side-by-side-assemblies-portal)

[Implantando aplicativos da área de trabalho](../windows/deploying-native-desktop-applications-visual-cpp.md)
