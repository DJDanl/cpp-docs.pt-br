---
title: ClickOnce Implantação para aplicativos do Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- deploying applications [C++], ClickOnce
- application deployment [C++], ClickOnce
- ClickOnce deployment [C++], C++ applications
ms.assetid: 9988c546-0936-452c-932f-9c76daa42157
ms.openlocfilehash: 4408db9d129c03ee5df9b006b03c6586df02afb1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513758"
---
# <a name="clickonce-deployment-for-visual-c-applications"></a>ClickOnce Implantação para aplicativos do Visual C++

O Visual Studio fornece duas tecnologias diferentes para a implantação de aplicativos do Windows: Implantação do ClickOnce ou implantação do [Windows Installer](/windows/win32/Msi/windows-installer-portal).

## <a name="clickonce-deployment-in-c"></a>Implantação do ClickOnce no C++

O ambiente C++ de desenvolvimento Visual não oferece suporte direto à implantação de C++ projetos do Visual Studio com o ClickOnce, mas as ferramentas estão disponíveis para usá-lo.

> [!NOTE]
>  O Visual Studio dá suporte ao ClickOnce nos ambientes de desenvolvimento do Visual C# e Visual Basic. Se o seu projeto C++ do Visual Studio for uma dependência de C# um projeto Visual, você poderá publicar o aplicativo (incluindo suas dependências) usando a implantação C# do ClickOnce do ambiente de desenvolvimento Visual.

Para implantar um aplicativo do Visual C++ usando o ClickOnce, primeiro, você precisa criar um [Manifesto do Aplicativo ClickOnce](/visualstudio/deployment/clickonce-application-manifest) e um [Manifesto de Implantação do ClickOnce](/visualstudio/deployment/clickonce-deployment-manifest) usando o [Mage.exe (Manifest Generation and Editing Tool)](/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool) ou sua versão de interface gráfica do usuário [para obter informações, confira [MageUI.exe (Manifest Generation and Editing Tool, Cliente Gráfico)](/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)].

Primeiro, use Mage.exe para criar o manifesto do aplicativo; o arquivo resultante terá a extensão .manifest. Em seguida, use Mage.exe para criar o manifesto de implantação; o arquivo resultante terá a extensão .application. Depois, assine os manifestos.

O manifesto do aplicativo precisa especificar o processador de destino (**x86**, **x64** ou **ARM**). Confira [Implantando pré-requisitos para aplicativos de 64 bits](/visualstudio/deployment/deploying-prerequisites-for-64-bit-applications) para obter informações sobre essas opções.

Além disso, o nome dos manifestos do aplicativo e de implantação precisa ser diferente do nome do aplicativo do C++. Isso evita conflitos entre o manifesto do aplicativo criado por Mage.exe e o manifesto externo que faz parte do aplicativo do C++.

A implantação precisará instalar as bibliotecas do Visual C++ das quais o aplicativo depende. Para determinar as dependências de um aplicativo específico, use depends.exe ou o utilitário DUMPBIN com a opção /DEPENDENTS. Para obter mais informações sobre dependências, confira [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md). Talvez seja necessário executar VCRedist.exe; esse utilitário instala as bibliotecas do Visual C++ no computador de destino.

Talvez você precise também criar um bootstrapper (instalador de pré-requisitos) para que o aplicativo implante componentes de pré-requisito; para obter informações sobre o bootstrapper, confira [Criando pacotes de bootstrapper](/visualstudio/deployment/creating-bootstrapper-packages).

Para obter uma descrição mais detalhada da tecnologia, confira [Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment). Para obter um exemplo detalhado da implantação do ClickOnce, confira [Passo a passo: Como implantar manualmente aplicativos ClickOnce](/visualstudio/deployment/walkthrough-manually-deploying-a-clickonce-application).

## <a name="see-also"></a>Consulte também

[Mage.exe (Manifest Generation and Editing Tool)](/dotnet/framework/tools/mage-exe-manifest-generation-and-editing-tool)<br>
[MageUI.exe (Manifest Generation and Editing Tool, cliente gráfico)](/dotnet/framework/tools/mageui-exe-manifest-generation-and-editing-tool-graphical-client)<br>
[Makecert.exe (Ferramenta de Criação de Certificado)](/windows/win32/SecCrypto/makecert)<br>
[Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)<br>
[Implantando aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components)<br>
[Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment)<br>
[Criando pacotes de bootstrapper](/visualstudio/deployment/creating-bootstrapper-packages)<br>
[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br>
[Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)
