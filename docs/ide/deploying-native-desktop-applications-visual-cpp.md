---
title: Implantando aplicativos de área de trabalho nativos (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 05/11/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- deploying applications [C++]
- application deployment [C++]
- Visual C++, application deployment
- application deployment [C++], about application deployment
- deploying applications [C++], about deploying applications
- distributing applications [C++]
ms.assetid: 37f1691e-d67c-41e4-926e-528a237a9bac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4f4aa355c132b4c94f085cbdf7aa73785357d0f0
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
---
# <a name="deploying-native-desktop-applications-visual-c"></a>Implantando aplicativos da área de trabalho nativos (Visual C++)

Implantação é o processo pelo qual você distribui um aplicativo concluído ou componente a ser instalado em outros computadores. Planejamento de implantação inicia quando um aplicativo é criado no computador de um desenvolvedor. Implantação termina quando o aplicativo está instalado e pronto para ser executado no computador do usuário.

Visual Studio fornece tecnologias diferentes para a implantação de aplicativos do Windows. Eles incluem a implantação do ClickOnce e implantação do Windows Installer.

- ClickOnce pode ser usado para implantar aplicativos C++ que o common language runtime (CLR) de destino — assemblies mistos, puros e verificáveis. Embora você possa usar o Windows Installer para implantar um aplicativo gerenciado, é recomendável usar o ClickOnce porque tira proveito dos recursos de segurança do .NET Framework como assinatura de manifesto. ClickOnce não dá suporte para implantação de aplicativos nativos do C++. Para obter mais informações, consulte [implantação de ClickOnce para aplicativos Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md).

- Tecnologia Windows Installer pode ser usada para implantar aplicativos em C++ nativo ou aplicativos C++ que visam o CLR.

Os artigos nesta seção da documentação descrevem como garantir que um aplicativo Visual C++ nativo seja executado em qualquer computador que fornece uma plataforma de destino com suporte, os arquivos que você deve incluir em um pacote de instalação e as maneiras recomendadas para redistribua os componentes que seu aplicativo depende.

## <a name="in-this-section"></a>Nesta seção

- [Implantação no Visual C++](../ide/deployment-in-visual-cpp.md)

- [Conceitos de implantação](../ide/deployment-concepts.md)

- [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md)

- [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md)

- [Escolhendo um método de implantação](../ide/choosing-a-deployment-method.md)

- [Implantação do CRT universal](universal-crt-deployment.md).

- [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)

- [Exemplos de implantação](../ide/deployment-examples.md)

- [Redistribuindo aplicativos de cliente Web](../ide/redistributing-web-client-applications.md)

- [Implantação de ClickOnce para aplicativos do Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md)

- [Executando um aplicativo C++ /clr em uma versão anterior do tempo de execução](../ide/running-a-cpp-clr-application-on-a-previous-runtime-version.md)

## <a name="related-sections"></a>Seções relacionadas

- [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)

- [Implantação](/dotnet/framework/deployment/index)

- [Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)