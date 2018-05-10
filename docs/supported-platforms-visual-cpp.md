---
title: Plataformas com suporte (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, platforms supported
- platforms [C++]
ms.assetid: 0d893056-4008-411a-b3d1-5f57fd7da95c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b0d857a65e0a08b105d54ba574553ab4a74fd3f9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="supported-platforms-visual-c"></a>Plataformas com suporte (Visual C++)

Os aplicativos compilados com o [!INCLUDE[vsprvs](assembler/masm/includes/vsprvs_md.md)] podem ser direcionados para várias plataformas, como se segue.

|Sistema operacional|x86|X64|ARM|
|----------------------|---------|---------|---------|
|Windows XP|X*|X*||
|[!INCLUDE[WinXPSvr](build/includes/winxpsvr_md.md)]|X*|X*||
|Windows Vista|X|X||
|Windows Server 2008|X|X||
|Windows 7|X|X||
|Windows Server 2012 R2|X|X||
|Windows 8|X|X|X|
|Windows 8.1|X|X|X|
|Windows 10|X|X|X|
|Android **|X|X|X|
|iOS **|X|X|X|
|Linux ***|X|X|X|

\* Você pode usar o conjunto de ferramentas da plataforma Windows XP incluído no Visual Studio 2017, no Visual Studio 2015, no Visual Studio 2013 e no Visual Studio 2012 Atualização 1 ou posterior para criar projetos do Windows XP e do [!INCLUDE[WinXPSvr](build/includes/winxpsvr_md.md)]. Para obter informações sobre como usar esse conjunto de ferramentas da plataforma, consulte [Configuring Programs for Windows XP (Configurando programas para Windows XP)](build/configuring-programs-for-windows-xp.md). Para obter mais informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](build/how-to-modify-the-target-framework-and-platform-toolset.md).

\*\* Você pode instalar a carga de trabalho **Desenvolvimento móvel com C++** no instalador do Visual Studio (ou o componente opcional **Visual C++ para Desenvolvimento Móvel Multiplataforma** na instalação do Visual Studio 2015) para plataformas Android ou iOS de destino. Para obter mais informações, consulte [Instalar o Visual C++ para Desenvolvimento Móvel da Plataforma Cruzada](/visualstudio/cross-platform/install-visual-cpp-for-cross-platform-mobile-development). Para compilar o código do iOS, é necessário ter um computador Mac e atender a outros requisitos. Para obter uma lista de pré-requisitos e instruções de instalação, consulte [Instalar e configurar ferramentas de build usando o iOS](/visualstudio/cross-platform/install-and-configure-tools-to-build-using-ios). É possível compilar código x86 ou ARM para coincidir com o hardware de destino. Use configurações x86 para compilar no simulador de iOS, no Emulador do Microsoft Visual Studio para Android e em alguns dispositivos Android. Use configurações ARM para compilar em dispositivos iOS e na maioria dos dispositivos Android.

\*\*\* Você pode instalar a carga de trabalho **Desenvolvimento Linux com C++** no instalador do Visual Studio para plataformas Linux de destino. Para obter instruções, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](linux/download-install-and-setup-the-linux-development-workload.md). Esse conjunto de ferramentas compila o executável no computador de destino, permitindo builds para qualquer arquitetura com suporte.

Para obter informações de como definir a configuração da plataforma de destino, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md) (Como configurar projetos do Visual C++ para plataformas x64 de 64 bits de destino).

## <a name="see-also"></a>Consulte também

- [Ferramentas e recursos do Visual C++ em edições do Visual Studio](ide/visual-cpp-tools-and-features-in-visual-studio-editions.md)
- [Introdução](/visualstudio/ide/getting-started-with-visual-cpp-in-visual-studio)