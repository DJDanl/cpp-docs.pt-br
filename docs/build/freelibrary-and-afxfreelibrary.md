---
title: "FreeLibrary e AfxFreeLibrary | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "FreeLibrary"
  - "AfxFreeLibrary"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Descarregamento de DLLs de extensão [C++]"
  - "Método AfxFreeLibrary"
  - "descarregando DLLs"
  - "Método FreeLibrary"
  - "DLLs [C++], vinculando"
  - "vinculando explicitamente [C++]"
  - "DLLs [C++], descarregando"
ms.assetid: 4a48d290-3971-43e9-8e97-ba656cd0c8f8
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# FreeLibrary e AfxFreeLibrary
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Processos que vinculam explicitamente a um DLL chamada da [FreeLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259188) função quando o módulo DLL é mais necessário.  Essa função diminui a contagem e, se a contagem de referência for zero, os unmaps de referência do módulo no espaço de endereço do processo.  
  
 Em um aplicativo de MFC, use [AfxFreeLibrary](../Topic/AfxFreeLibrary.md) em vez de `FreeLibrary` para descarregar uma DLL da extensão.  A interface \(protótipo de função\) para `AfxFreeLibrary` é a mesma que `FreeLibrary`.  
  
## O que você deseja fazer?  
  
-   [Link implicitamente](../Topic/Linking%20Implicitly.md)  
  
-   [Determine o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
## Que você deseja saber mais?  
  
-   [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
  
-   [GetProcAddress](../build/getprocaddress.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)   
 [FreeLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259188)   
 [AfxFreeLibrary](../Topic/AfxFreeLibrary.md)