---
title: "Plataformas com suporte (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "plataformas [C++]"
  - "Visual C++, plataformas com suporte"
ms.assetid: 0d893056-4008-411a-b3d1-5f57fd7da95c
caps.latest.revision: 22
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Plataformas com suporte (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os aplicativos compilados com o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] podem ser direcionados para várias plataformas, como se segue.  
  
|Sistema Operacional|x86|x64|ARM|  
|-------------------------|---------|---------|---------|  
|Windows XP|X \*|X \*||  
|[!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]|X \*|X \*||  
|Windows Vista|X|X||  
|Windows Server 2008|X|X||  
|Windows 7|X|X||  
|Windows Server 2012 R2|X|X||  
|Windows 8|X|X|X|  
|Windows 8.1|X|X|X|  
|Windows 10|X|X|X|  
|Android \* \*|X|X|X|  
|iOS \* \*|X|X|X|  
  
 \* Você pode usar as ferramentas da plataforma Windows XP incluída no Visual Studio de 2015, Visual Studio 2013 e Visual Studio 2012 Update 1 ou posterior para criar o Windows XP e[!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)]projetos.  Para obter informações sobre como usar esse conjunto de ferramentas da plataforma, consulte[Configurando programas C\+\+ 11 para Windows XP](../build/configuring-programs-for-windows-xp.md).  Para obter informações adicionais sobre como alterar o conjunto de ferramentas da plataforma, consulte[Como modificar a estrutura de destino e o conjunto de ferramentas da plataforma](../build/how-to-modify-the-target-framework-and-platform-toolset.md).  
  
 \* \* Você pode instalar o Visual C\+\+ opcional para o componente de desenvolvimento de móveis de plataforma cruzada na instalação do Visual Studio de 2015 para plataformas Android ou iOS de destino.  Para obter instruções, consulte[Instalar o Visual C\+\+ para desenvolvimento móvel da plataforma cruzada](../Topic/Install%20Visual%20C++%20for%20Cross-Platform%20Mobile%20Development.md).  Para criar código iOS, você deve ter um computador Mac e atender a outros requisitos.  Para obter uma lista de pré\-requisitos e as instruções de instalação, consulte[Instalar e configurar ferramentas de compilação usando o iOS](../Topic/Install%20And%20Configure%20Tools%20to%20Build%20using%20iOS.md).  Você pode criar x86 ou código ARM para coincidir com o hardware de destino.  Configurações de uso x86 para criar para o simulador do iOS, Microsoft Visual Studio emulador para Android e alguns dispositivos Android.  Use configurações de ARM para criar para a maioria dos dispositivos com Android e iOS dispositivos.  
  
 Para obter informações sobre como definir a configuração da plataforma de destino, consulte[Como configurar projetos do Visual C\+\+ para destinar plataformas de 64 bits](../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).  
  
## Consulte também  
 [Ferramentas e modelos do Visual C\+\+ em edições do Visual Studio](../ide/visual-cpp-tools-and-templates-in-visual-studio-editions.md)   
 [Guia de Introdução](../misc/getting-started-with-visual-cpp-in-visual-studio-2015.md)