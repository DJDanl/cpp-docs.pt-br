---
title: Conceitos de implantação
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Installer [C++]
- dependencies [C++], application deployment and
- application deployment [C++], about application deployment
- deploying applications [C++], about deploying applications
- libraries [C++], application deployment issues
ms.assetid: ebd7f246-ab54-40e8-87fa-dac02c0047b3
ms.openlocfilehash: ec472e506e78a57b65186bf6a5b801419fb141fb
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346417"
---
# <a name="deployment-concepts"></a>Conceitos de implantação

Esta seção aborda as principais considerações sobre a implantação de aplicativos do C++.

## <a name="windows-installer-deployment-in-c"></a>Implantação do Windows Installer no C++

Em geral, os projetos do Visual C++ usam a instalação tradicional do Windows Installer para implantação. Para preparar uma implantação do Windows Installer, você pode empacotar o aplicativo em um arquivo setup.exe e distribuí-lo, junto com um pacote do instalador (.msi). Em seguida, os usuários executam setup.exe para instalar o aplicativo.

Empacote o aplicativo adicionando um projeto de Instalação à solução; quando compilado, ele cria os arquivos de instalação e do pacote do instalador que você distribui para os usuários. Para obter mais informações, confira [Escolhendo um método de implantação](choosing-a-deployment-method.md).

## <a name="library-dependencies"></a>Dependências de biblioteca

Quando um aplicativo do C/C++ é compilado usando a funcionalidade fornecida pelas bibliotecas do Visual C++, ele se torna dependente da presença dessas bibliotecas em tempo de execução. Para que o aplicativo seja executado, ele precisa estar vinculado, estática ou dinamicamente, às bibliotecas do Visual C++ necessárias. Se um aplicativo está vinculado dinamicamente a uma biblioteca do Visual C++, quando ele é executado, essa biblioteca precisa estar presente para que ele possa ser carregado. Por outro lado, se o aplicativo está vinculado estaticamente a uma biblioteca do Visual C++, ele não precisa que as DLLs correspondentes estejam presentes no computador do usuário. No entanto, a vinculação estática apresenta alguns efeitos negativos, como o aumento do tamanho dos arquivos de aplicativo, além da possibilidade de dificultar ainda mais a manutenção. Para obter mais informações, confira [Vantagens do uso de DLLs](../build/dlls-in-visual-cpp.md#advantages-of-using-dlls).

## <a name="packaging-and-redistributing"></a>Empacotamento e redistribuição

As bibliotecas do Visual C++ são empacotadas como DLLs, e todas as bibliotecas necessárias para aplicativos do C/C++ são instaladas pelo Visual Studio no computador do desenvolvedor. No entanto, ao implantar seu aplicativo para os usuários, não é viável, na maioria dos casos, exigir a instalação do Visual Studio para executar o aplicativo. É importante ter a capacidade de redistribuir apenas as partes do Visual C++ necessárias para a execução correta do aplicativo.

Para obter mais informações sobre empacotamento e redistribuição, confira os seguintes tópicos:

- [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

- [Escolhendo um método de implantação](choosing-a-deployment-method.md).

- [Implantação do CRT Universal](universal-crt-deployment.md).

Para obter exemplos de implantação e sugestões sobre como solucionar problemas, confira:

- [Exemplos de implantação](deployment-examples.md).

- [Solução de problemas de aplicativos isolados e assemblies lado a lado do C/C++](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md).

## <a name="see-also"></a>Consulte também

- [Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)
- [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md)
