---
title: Implantação do ClickOnce para aplicativos do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- deploying applications [C++], ClickOnce
- application deployment [C++], ClickOnce
- ClickOnce deployment [C++], C++ applications
ms.assetid: 9988c546-0936-452c-932f-9c76daa42157
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e85ec0dfc011aab4d2b3ac835bbe71782b055000
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33332319"
---
# <a name="clickonce-deployment-for-visual-c-applications"></a>ClickOnce Implantação para aplicativos do Visual C++
O Visual Studio fornece duas tecnologias diferentes para a implantação de aplicativos do Windows: implantação do ClickOnce ou implantação do [Windows Installer](http://msdn.microsoft.com/library/cc185688).  
  
## <a name="clickonce-deployment-in-c"></a>Implantação do ClickOnce no C++  
 O ambiente de desenvolvimento do Visual C++ não dá suporte diretamente à implantação de projetos do Visual C++ com o ClickOnce, mas existem ferramentas disponíveis para usá-lo.  
  
> [!NOTE]
>  O Visual Studio dá suporte ao ClickOnce nos ambientes de desenvolvimento do Visual C# e Visual Basic. Se o projeto do Visual C++ é uma dependência de um projeto do Visual C#, você pode publicar o aplicativo (incluindo suas dependências) usando a implantação do ClickOnce por meio do ambiente de desenvolvimento do Visual C#.  
  
 Para implantar um aplicativo do Visual C++ usando o ClickOnce, primeiro, você precisa criar um [Manifesto do Aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest) e um [Manifesto de Implantação do ClickOnce](/visualstudio/deployment/clickonce-deployment-manifest) usando o [Mage.exe (Manifest Generation and Editing Tool)](/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool) ou sua versão de interface gráfica do usuário [para obter informações, confira [MageUI.exe (Manifest Generation and Editing Tool, Cliente Gráfico)](/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)].  

  
 Primeiro, use Mage.exe para criar o manifesto do aplicativo; o arquivo resultante terá a extensão .manifest. Em seguida, use Mage.exe para criar o manifesto de implantação; o arquivo resultante terá a extensão .application. Depois, assine os manifestos.  
  
 O manifesto do aplicativo precisa especificar o processador de destino (**x86**, **x64** ou **ARM**). Confira [Implantando pré-requisitos para aplicativos de 64 bits](/visualstudio/deployment/deploying-prerequisites-for-64-bit-applications) para obter informações sobre essas opções.  
  
 Além disso, o nome dos manifestos do aplicativo e de implantação precisa ser diferente do nome do aplicativo do C++. Isso evita conflitos entre o manifesto do aplicativo criado por Mage.exe e o manifesto externo que faz parte do aplicativo do C++.  
  
 A implantação precisará instalar as bibliotecas do Visual C++ das quais o aplicativo depende. Para determinar as dependências de um aplicativo específico, use depends.exe ou o utilitário DUMPBIN com a opção /DEPENDENTS. Para obter mais informações sobre dependências, confira [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md). Talvez seja necessário executar VCRedist.exe; esse utilitário instala as bibliotecas do Visual C++ no computador de destino.  
  
 Talvez você precise também criar um bootstrapper (instalador de pré-requisitos) para que o aplicativo implante componentes de pré-requisito; para obter informações sobre o bootstrapper, confira [Criando pacotes de bootstrapper](/visualstudio/deployment/creating-bootstrapper-packages).  
  
 Para obter uma descrição mais detalhada da tecnologia, confira [Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment). Para obter um exemplo detalhado da implantação do ClickOnce, confira [Passo a passo: Implantando um aplicativo ClickOnce manualmente](/visualstudio/deployment/walkthrough-manually-deploying-a-clickonce-application).  
  
## <a name="see-also"></a>Consulte também  
 [Mage.exe (Manifest Generation and Editing Tool)](/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool)   
 [MageUI.exe (Manifest Generation and Editing Tool, Cliente Gráfico)](/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)   
 [Makecert.exe (Ferramenta de Criação de Certificado)](https://msdn.microsoft.com/library/windows/desktop/aa386968)   
 [Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)   
 [Implantando aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components)   
 [Implantação do Windows Installer](http://msdn.microsoft.com/en-us/121be21b-b916-43e2-8f10-8b080516d2a0)   
 [Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment)   
 [Criando pacotes de bootstrapper](/visualstudio/deployment/creating-bootstrapper-packages)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)