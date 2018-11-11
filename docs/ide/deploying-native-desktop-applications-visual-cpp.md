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
ms.openlocfilehash: ca3949c0cc2a505148da2a1edb8f07eaf1b6a1f7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50662677"
---
# <a name="deploying-native-desktop-applications-visual-c"></a>Implantando aplicativos da área de trabalho nativos (Visual C++)

Implantação é o processo pelo qual você distribui um componente ou aplicativo concluído para ser instalado em outros computadores. O planejamento da implantação começa quando um aplicativo é criado no computador de um desenvolvedor. A implantação termina quando o aplicativo é instalado e está pronto para ser executado no computador de um usuário.

O Visual Studio fornece tecnologias diferentes para a implantação de aplicativos do Windows. Elas incluem a implantação do ClickOnce e a implantação do Windows Installer.

- O ClickOnce pode ser usado para implantar aplicativos do C++ direcionados ao CLR (Common Language Runtime) – assemblies mistos, puros e verificáveis. Embora você possa usar o Windows Installer para implantar um aplicativo gerenciado, recomendamos que você use o ClickOnce, porque ele aproveita as funcionalidades de segurança do .NET Framework, como a autenticação de manifesto. O ClickOnce não dá suporte à implantação de aplicativos do C++ nativo. Para obter mais informações, confira [Implantação do ClickOnce para aplicativos do Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md).

- A tecnologia do Windows Installer pode ser usada para implantar aplicativos do C++ nativo ou aplicativos do C++ direcionados ao CLR.

Os artigos desta seção da documentação descrevem como garantir que um aplicativo nativo do Visual C++ seja executado em qualquer computador que forneça uma plataforma de destino compatível, quais arquivos precisam ser incluídos em um pacote de instalação e as maneiras recomendadas para redistribuir os componentes dos quais o aplicativo depende.

## <a name="in-this-section"></a>Nesta seção

- [Implantação no Visual C++](../ide/deployment-in-visual-cpp.md)

- [Conceitos de implantação](../ide/deployment-concepts.md)

- [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md)

- [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md)

- [Escolhendo um método de implantação](../ide/choosing-a-deployment-method.md)

- [Implantação do CRT Universal](universal-crt-deployment.md).

- [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)

- [Exemplos de implantação](../ide/deployment-examples.md)

- [Redistribuindo aplicativos de cliente Web](../ide/redistributing-web-client-applications.md)

- [Implantação de ClickOnce para aplicativos do Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md)

- [Executando um aplicativo do C++ /clr em uma versão de tempo de execução anterior](../ide/running-a-cpp-clr-application-on-a-previous-runtime-version.md)

## <a name="related-sections"></a>Seções relacionadas

- [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)

- [Implantação](/dotnet/framework/deployment/index)

- [Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)