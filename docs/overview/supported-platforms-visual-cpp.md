---
title: Plataformas com suporte (Visual C++)
ms.date: 12/02/2019
ms.technology: cpp-tools
helpviewer_keywords:
- Visual C++, platforms supported
- platforms [C++]
ms.assetid: 0d893056-4008-411a-b3d1-5f57fd7da95c
ms.openlocfilehash: 049b28d23c7f5f5f023f3b2964577b75992c2998
ms.sourcegitcommit: 5f276064779d90a4cfda758f89e0c0f1e4d1a188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/09/2020
ms.locfileid: "75793824"
---
# <a name="supported-platforms-visual-c"></a>Plataformas com suporte (Visual C++)

Os aplicativos criados com o Visual Studio podem ser direcionados a várias plataformas, como as seguintes.

|Sistema operacional|x86|x64|{1&gt;{2&gt;ARM&lt;2}&lt;1}|ARM64\*\*\*\*|
|----------------------|---------|---------|---------|---------|
|Windows XP|X\*|X\*|||
|Windows Server 2003|X\*|X\*|||
|Windows Vista|X|X|||
|Windows Server 2008|X|X|||
|Windows 7|X|X|||
|Windows Server 2012 R2|X|X|||
|Windows 8|X|X|X||
|Windows 8.1|X|X|X||
|Windows 10|X|X|X|X|
|Android \*\*|X|X|X|X|
|iOS \*\*|X|X|X|X|
|Linux \*\*\*|X|X|X|X|

\* você pode usar o conjunto de ferramentas da plataforma Windows XP incluído no Visual Studio 2017, no Visual Studio 2015, no Visual Studio 2013 e no Visual Studio 2012 atualização 1 para compilar projetos do Windows XP e do Windows Server 2003. Para obter informações sobre como usar esse conjunto de ferramentas da plataforma, consulte [Configuring Programs for Windows XP (Configurando programas para Windows XP)](../build/configuring-programs-for-windows-xp.md). Para obter mais informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../build/how-to-modify-the-target-framework-and-platform-toolset.md).

\*\* É possível instalar a carga de trabalho **Desenvolvimento Móvel com C++** no instalador do Visual Studio 2017 e posterior. Na instalação do Visual Studio 2015, escolha o componente opcional **Visual C++ para Desenvolvimento Móvel da Plataforma Cruzada** para direcionar plataformas iOS ou Android. Para obter mais informações, consulte [Instalar o Visual C++ para Desenvolvimento Móvel da Plataforma Cruzada](/visualstudio/cross-platform/install-visual-cpp-for-cross-platform-mobile-development). Para compilar o código do iOS, é necessário ter um computador Mac e atender a outros requisitos. Para obter uma lista de pré-requisitos e instruções de instalação, consulte [Instalar e configurar ferramentas de build usando o iOS](/visualstudio/cross-platform/install-and-configure-tools-to-build-using-ios). É possível compilar código x86 ou ARM para coincidir com o hardware de destino. Use configurações x86 para compilar no simulador de iOS, no Emulador do Microsoft Visual Studio para Android e em alguns dispositivos Android. Use configurações ARM para compilar em dispositivos iOS e na maioria dos dispositivos Android.

\*\*\* É possível instalar a carga de trabalho **Desenvolvimento para Linux com C++** no instalador do Visual Studio 2017 e posterior para direcionar plataformas Linux. Para obter instruções, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](../linux/download-install-and-setup-the-linux-development-workload.md). Esse conjunto de ferramentas compila o executável no computador de destino, permitindo builds para qualquer arquitetura com suporte.

\*\*\*\* O suporte a ARM64 está disponível no Visual Studio 2017 e posterior.

Para obter informações de como definir a configuração da plataforma de destino, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md) (Como configurar projetos do Visual C++ para plataformas x64 de 64 bits de destino).

## <a name="see-also"></a>Veja também

- [Ferramentas e recursos do Visual C++ em edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md)
- [Introdução](/visualstudio/ide/getting-started-with-cpp-in-visual-studio)
