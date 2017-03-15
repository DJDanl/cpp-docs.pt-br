---
title: Plataformas com suporte (Visual C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, platforms supported
- platforms [C++]
ms.assetid: 0d893056-4008-411a-b3d1-5f57fd7da95c
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: 0192e9bd6ef9d93e274c43c24137a27e5aa53dab
ms.openlocfilehash: c0c209c16ad4a264b851321a2879104112da81f2
ms.lasthandoff: 02/25/2017

---
# <a name="supported-platforms-visual-c"></a>Plataformas com suporte (Visual C++)
Os aplicativos compilados com o [!INCLUDE[vsprvs](assembler/masm/includes/vsprvs_md.md)] podem ser direcionados para várias plataformas, como se segue.  
  
|Sistema operacional|x86|x64|ARM|  
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
  
 \* É possível usar o conjunto de ferramentas da plataforma do Windows XP incluído no Visual Studio 2015, Visual Studio 2013 e Visual Studio 2012 Atualização 1 ou mais recente para compilar projetos [!INCLUDE[WinXPSvr](build/includes/winxpsvr_md.md)] e do Windows XP. Para obter informações sobre como usar esse conjunto de ferramentas da plataforma, consulte [Configuring Programs for Windows XP (Configurando programas para Windows XP)](build/configuring-programs-for-windows-xp.md). Para obter mais informações sobre como alterar o conjunto de ferramentas da plataforma, consulte [Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](build/how-to-modify-the-target-framework-and-platform-toolset.md).  
  
 ** É possível instalar o componente Visual C++ para Desenvolvimento Móvel da Plataforma Cruzada na instalação do Visual Studio 2015 para definir como destino as plataformas iOS ou Android. Para obter mais informações, consulte [Instalar o Visual C++ para Desenvolvimento Móvel da Plataforma Cruzada](/visualstudio/cross-platform/install-visual-cpp-for-cross-platform-mobile-development). Para compilar o código do iOS, é necessário ter um computador Mac e atender a outros requisitos. Para obter uma lista de pré-requisitos e instruções de instalação, consulte [Instalar e configurar ferramentas de build usando o iOS](/visualstudio/cross-platform/install-and-configure-tools-to-build-using-ios). É possível compilar código x86 ou ARM para coincidir com o hardware de destino. Use configurações x86 para compilar no simulador de iOS, no Emulador do Microsoft Visual Studio para Android e em alguns dispositivos Android. Use configurações ARM para compilar em dispositivos iOS e na maioria dos dispositivos Android.  
  
 Para obter informações sobre como definir a configuração da plataforma de destino, consulte [Como: configurar projetos Visual C++ para plataformas de 64 bits de destino](build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas e recursos do Visual C++ em edições do Visual Studio](ide/visual-cpp-tools-and-features-in-visual-studio-editions.md)   
 [Introdução](/visualstudio/ide/getting-started-with-visual-cpp-in-visual-studio)
