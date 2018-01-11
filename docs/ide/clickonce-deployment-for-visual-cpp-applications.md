---
title: "Implantação de ClickOnce para aplicativos Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- deploying applications [C++], ClickOnce
- application deployment [C++], ClickOnce
- ClickOnce deployment [C++], C++ applications
ms.assetid: 9988c546-0936-452c-932f-9c76daa42157
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e1a036a1520a747448c5541f367f0b43711e30b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clickonce-deployment-for-visual-c-applications"></a>ClickOnce Implantação para aplicativos do Visual C++
O Visual Studio fornece duas tecnologias diferentes para a implantação de aplicativos do Windows: implantação de ClickOnce ou [do Windows Installer](http://msdn.microsoft.com/library/cc185688) implantação.  
  
## <a name="clickonce-deployment-in-c"></a>Implantação de ClickOnce em C++  
 O ambiente de desenvolvimento do Visual C++ não dá suporte diretamente a implantação de projetos do Visual C++ com o ClickOnce, mas as ferramentas estão disponíveis para usá-lo.  
  
> [!NOTE]
>  O Visual Studio oferece suporte a ClickOnce em ambientes de desenvolvimento do Visual c# e Visual Basic. Se seu projeto do Visual C++ é uma dependência de um projeto do Visual c#, você pode publicar o aplicativo (incluindo suas dependências) usando a implantação do ClickOnce do ambiente de desenvolvimento do Visual c#.  
  
 Para implantar um aplicativo do Visual C++ usando o ClickOnce, primeiro você precisa criar um [manifesto do aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest) e um [manifesto de implantação do ClickOnce](/visualstudio/deployment/clickonce-deployment-manifest) usando o [Mage.exe (manifesto Ferramenta de edição e geração)](/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool) ou sua versão de interface gráfica do usuário (para obter informações, consulte [MageUI.exe (ferramenta de edição, cliente gráfico e geração de manifesto)](/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)).  

  
 Você primeiro usar Mage.exe para criar o manifesto do aplicativo; o arquivo resultante terá o manifesto de extensão. Você, em seguida, usar Mage.exe para criar o manifesto de implantação; o arquivo resultante terá o. Application de extensão. Você então assinar os manifestos.  
  
 O manifesto do aplicativo deve especificar o processador de destino (**x86**, **x64**, ou **ARM**). Consulte [Implantando pré-requisitos para aplicativos de 64 bits](/visualstudio/deployment/deploying-prerequisites-for-64-bit-applications) para obter informações sobre essas opções.  
  
 Além disso, o nome dos manifestos de aplicativo e implantação deve ser diferente do nome do aplicativo C++. Isso evita conflitos entre o manifesto do aplicativo criado por Mage.exe e o manifesto externo que faz parte do aplicativo C++.  
  
 Sua implantação precisará instalar quaisquer bibliotecas do Visual C++ que seu aplicativo depende. Para determinar as dependências para um aplicativo específico, você pode usar depends.exe ou o utilitário DUMPBIN com a opção /DEPENDENTS. Para obter mais informações sobre dependências, consulte [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md). Talvez seja necessário executar VCRedist.exe; Esse utilitário instala as bibliotecas do Visual C++ no computador de destino.  
  
 Você também precisa criar um bootstrapper (instalador de pré-requisitos) para o aplicativo implantar componentes de pré-requisito; Para obter informações sobre o bootstrapper, consulte [criação de pacotes de Bootstrapper](/visualstudio/deployment/creating-bootstrapper-packages).  
  
 Para obter uma descrição mais detalhada da tecnologia, consulte [segurança ClickOnce e implantação](/visualstudio/deployment/clickonce-security-and-deployment). Para obter um exemplo detalhado de implantação de ClickOnce, consulte [passo a passo: Implantando manualmente um aplicativo ClickOnce](/visualstudio/deployment/walkthrough-manually-deploying-a-clickonce-application).  
  
## <a name="see-also"></a>Consulte também  
 [Mage.exe (Manifest Generation and Editing Tool)](/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool)   
 [MageUI.exe (Manifest Generation and Editing Tool, Cliente Gráfico)](/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)   
 [Makecert.exe (Ferramenta de Criação de Certificado)](https://msdn.microsoft.com/library/windows/desktop/aa386968)   
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)   
 [Implantando aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components)   
 [Implantação do Windows Installer](http://msdn.microsoft.com/en-us/121be21b-b916-43e2-8f10-8b080516d2a0)   
 [Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment)   
 [Criando pacotes de Bootstrapper](/visualstudio/deployment/creating-bootstrapper-packages)   
 [Programação do .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)