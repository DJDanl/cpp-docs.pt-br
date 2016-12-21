---
title: "Aviso LNK4237 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4237"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4237"
ms.assetid: 87bfec39-5241-464f-9feb-517b49f352ea
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4237 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\/SUBSYSTEM:NATIVE especificou ao importar “DLL;” Use \/SUBSYSTEM:CONSOLE ou \/SUBSYSTEM:WINDOWS.  
  
 [\/SUBSYSTEM: NATIVO](../../build/reference/subsystem-specify-subsystem.md) foi especificado ao criar um aplicativo do windows \(\) diretamente o Win32 que usa um ou mais dos seguintes:  
  
-   kernel32.dll  
  
-   gdi32.dll  
  
-   user32.dll  
  
-   um de dlls de msvcrt\*.  
  
 Resolver esse aviso não especificando **\/SUBSYSTEM:NATIVE**.