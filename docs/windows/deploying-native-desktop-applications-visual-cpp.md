---
title: Implantando aplicativos da área de trabalho nativos (Visual C++)
ms.date: 05/11/2018
helpviewer_keywords:
- deploying applications [C++]
- application deployment [C++]
- Visual C++, application deployment
- application deployment [C++], about application deployment
- deploying applications [C++], about deploying applications
- distributing applications [C++]
ms.assetid: 37f1691e-d67c-41e4-926e-528a237a9bac
ms.topic: overview
ms.openlocfilehash: af3141a8fd626a909de93b219bf3b6d8186f0623
ms.sourcegitcommit: 7750e4c291d56221c8893120c56a1fe6c9af60d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "71274753"
---
# <a name="deploying-native-desktop-applications-visual-c"></a>Implantando aplicativos da área de trabalho nativos (Visual C++)

Implantação é o processo pelo qual você distribui um componente ou aplicativo concluído para ser instalado em outros computadores. O planejamento da implantação começa quando um aplicativo é criado no computador de um desenvolvedor. A implantação termina quando o aplicativo é instalado e está pronto para ser executado no computador de um usuário.

O Visual Studio fornece tecnologias diferentes para a implantação de aplicativos do Windows. Elas incluem a implantação do ClickOnce e a implantação do Windows Installer.

- O ClickOnce pode ser usado para implantar aplicativos do C++ direcionados ao CLR (Common Language Runtime) – assemblies mistos, puros e verificáveis. Embora você possa usar o Windows Installer para implantar um aplicativo gerenciado, recomendamos que você use o ClickOnce, porque ele aproveita as funcionalidades de segurança do .NET Framework, como a autenticação de manifesto. O ClickOnce não dá suporte à implantação de aplicativos do C++ nativo. Para obter mais informações, confira [Implantação do ClickOnce para aplicativos do Visual C++](clickonce-deployment-for-visual-cpp-applications.md).

- A tecnologia do Windows Installer pode ser usada para implantar aplicativos do C++ nativo ou aplicativos do C++ direcionados ao CLR.

Os artigos desta seção da documentação descrevem como garantir que um aplicativo nativo do Visual C++ seja executado em qualquer computador que forneça uma plataforma de destino compatível, quais arquivos precisam ser incluídos em um pacote de instalação e as maneiras recomendadas para redistribuir os componentes dos quais o aplicativo depende.

## <a name="in-this-section"></a>Nesta seção

- [Implantação no Visual C++](deployment-in-visual-cpp.md)

- [Conceitos de implantação](deployment-concepts.md)

- [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md)

- [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md)

- [Escolhendo um método de implantação](choosing-a-deployment-method.md)

- [Implantação do CRT Universal](universal-crt-deployment.md).

- [Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md)

- [Exemplos de implantação](deployment-examples.md)

- [Redistribuindo aplicativos de cliente Web](redistributing-web-client-applications.md)

- [Implantação de ClickOnce para aplicativos do Visual C++](clickonce-deployment-for-visual-cpp-applications.md)

- [Executando um aplicativo do C++ /clr em uma versão de tempo de execução anterior](running-a-cpp-clr-application-on-a-previous-runtime-version.md)

## <a name="related-sections"></a>Seções relacionadas

- [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)

- [Implantação](/dotnet/framework/deployment/index)

- [Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)