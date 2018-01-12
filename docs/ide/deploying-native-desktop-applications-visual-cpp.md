---
title: "Implantando aplicativos de área de trabalho nativos (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- deploying applications [C++]
- application deployment [C++]
- Visual C++, application deployment
- application deployment [C++], about application deployment
- deploying applications [C++], about deploying applications
- distributing applications [C++]
ms.assetid: 37f1691e-d67c-41e4-926e-528a237a9bac
caps.latest.revision: "28"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1fe88a322314ac24fa5799735e84ff100efa2e79
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="deploying-native-desktop-applications-visual-c"></a>Implantando aplicativos da área de trabalho nativos (Visual C++)
Implantação é o processo pelo qual você distribui um aplicativo concluído ou componente a ser instalado em outros computadores. Planejamento de implantação inicia quando um aplicativo é criado no computador de um desenvolvedor. Implantação termina quando o aplicativo está instalado e pronto para ser executado no computador do usuário.  
  
 Visual Studio fornece tecnologias diferentes para a implantação de aplicativos do Windows. Eles incluem a implantação do ClickOnce e implantação do Windows Installer.  
  
-   ClickOnce pode ser usado para implantar aplicativos C++ que o common language runtime (CLR) de destino — assemblies mistos, puros e verificáveis. Embora você possa usar o Windows Installer para implantar um aplicativo gerenciado, é recomendável usar o ClickOnce porque tira proveito dos recursos de segurança do .NET Framework como assinatura de manifesto. ClickOnce não dá suporte para implantação de aplicativos nativos do C++. Para obter mais informações, consulte [implantação de ClickOnce para aplicativos Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md).  
  
-   Tecnologia Windows Installer pode ser usada para implantar aplicativos em C++ nativo ou aplicativos C++ que visam o CLR.  
  
 Os artigos nesta seção da documentação descrevem como garantir que um aplicativo Visual C++ nativo seja executado em qualquer computador que fornece uma plataforma de destino com suporte, os arquivos que você deve incluir em um pacote de instalação e as maneiras recomendadas para redistribua os componentes que seu aplicativo depende.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Implantação no Visual C++](../ide/deployment-in-visual-cpp.md)  
  
 [Conceitos de implantação](../ide/deployment-concepts.md)  
  
 [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md)  
  
 [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md)  
  
 [Escolhendo um método de implantação](../ide/choosing-a-deployment-method.md)  
  
 [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)  
  
 [Exemplos de implantação](../ide/deployment-examples.md)  
  
 [Redistribuindo aplicativos de cliente Web](../ide/redistributing-web-client-applications.md)  
  
 [Implantação de ClickOnce para aplicativos do Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md)  
  
 [Executando um aplicativo C++ /clr em uma versão anterior do tempo de execução](../ide/running-a-cpp-clr-application-on-a-previous-runtime-version.md)  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)  
  
 [Implantação](/dotnet/framework/deployment/index)  
  
 [Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)