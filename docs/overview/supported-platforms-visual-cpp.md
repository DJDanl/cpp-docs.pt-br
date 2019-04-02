---
title: Plataformas com suporte (Visual C++)
ms.date: 11/04/2016
ms.technology: cpp-tools
helpviewer_keywords:
- Visual C++, platforms supported
- platforms [C++]
ms.assetid: 0d893056-4008-411a-b3d1-5f57fd7da95c
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 39be17904f19bebdd9313a767de91a7315c3ca66
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58782050"
---
# <a name="supported-platforms-visual-c"></a>Plataformas com suporte (Visual C++)

Os aplicativos criados com o Visual Studio podem ser direcionados a várias plataformas, como as seguintes.

|Sistema operacional|x86|X64|ARM|
|----------------------|---------|---------|---------|
|Windows XP|X\*|X\*||
|Windows Server 2003|X\*|X\*||
|Windows Vista|X|X||
|Windows Server 2008|X|X||
|Windows 7|X|X||
|Windows Server 2012 R2|X|X||
|Windows 8|X|X|X|
|Windows 8.1|X|X|X|
|Windows 10|X|X|X|
|Android \*\*|X|X|X|
|iOS \*\*|X|X|X|
|Linux \*\*\*|X|X|X|

\* Você pode usar o conjunto de ferramentas da plataforma Windows XP incluído no Visual Studio 2017, no Visual Studio 2015, no Visual Studio 2013 e no Visual Studio 2012 com a Atualização 1 ou posteriores para criar projetos do Windows XP e do Windows Server 2003. Para obter informações sobre como usar esse conjunto de ferramentas da plataforma, consulte [Configuring Programs for Windows XP (Configurando programas para Windows XP)](../build/configuring-programs-for-windows-xp.md). Para obter informações adicionais sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como: Modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../build/how-to-modify-the-target-framework-and-platform-toolset.md).

\*\* Você pode instalar a carga de trabalho **Desenvolvimento Móvel com C++** no instalador do Visual Studio 2017 (ou o componente opcional **Visual C++ para Desenvolvimento Móvel Multiplataforma** na instalação do Visual Studio 2015) para direcionar às plataformas Android ou iOS. Para obter mais informações, consulte [Instalar o Visual C++ para Desenvolvimento Móvel da Plataforma Cruzada](/visualstudio/cross-platform/install-visual-cpp-for-cross-platform-mobile-development). Para compilar o código do iOS, é necessário ter um computador Mac e atender a outros requisitos. Para obter uma lista de pré-requisitos e instruções de instalação, consulte [Instalar e configurar ferramentas de build usando o iOS](/visualstudio/cross-platform/install-and-configure-tools-to-build-using-ios). É possível compilar código x86 ou ARM para coincidir com o hardware de destino. Use configurações x86 para compilar no simulador de iOS, no Emulador do Microsoft Visual Studio para Android e em alguns dispositivos Android. Use configurações ARM para compilar em dispositivos iOS e na maioria dos dispositivos Android.

\*\*\* Você pode instalar a carga de trabalho **Desenvolvimento para Linux com C++** no instalador do Visual Studio 2017 para direcionar a plataformas Linux. Para obter instruções, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](../linux/download-install-and-setup-the-linux-development-workload.md). Esse conjunto de ferramentas compila o executável no computador de destino, permitindo builds para qualquer arquitetura com suporte.

Para obter mais informações sobre como definir a configuração da plataforma de destino, consulte [Como: Configurar projetos do Visual C++ para terem plataformas x64 de 64 bits como destino](../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).

## <a name="see-also"></a>Consulte também

- [Ferramentas e recursos do Visual C++ em edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md)
- [Introdução](/visualstudio/ide/getting-started-with-cpp-in-visual-studio)
