---
title: "Caminho de pesquisa usado pelo Windows para localizar uma DLL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "DLLs [C++], caminho de pesquisa do Windows"
  - "localizando DLLs"
  - "pesquisas de DLL conhecidas [C++]"
  - "localizando DLLs"
  - "caminhos de pesquisa [C++]"
  - "pesquisando [C++], DLLs"
  - "Windows [C++], caminho de pesquisa DLL"
ms.assetid: 84bfb380-ad7b-4962-b2d0-51b19a45f1bb
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Caminho de pesquisa usado pelo Windows para localizar uma DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Com vincular implícita e explícita, as primeiras pesquisam o windows “por” DLL conhecidos, como Kernel32.dll e User32.dll.  As janelas pesquisam pelos DLL na seguinte sequência:  
  
1.  O diretório onde o módulo executável para o processo atual está localizado.  
  
2.  O diretório atual.  
  
3.  O diretório do sistema do windows.  A função de **GetSystemDirectory** recupera o caminho desse diretório.  
  
4.  O diretório do Windows.  A função de **GetWindowsDirectory** recupera o caminho desse diretório.  
  
5.  Os diretórios listados na variável de ambiente PATH.  
  
    > [!NOTE]
    >  A variável de ambiente de LIBPATH não é usado.  
  
## O que você deseja fazer?  
  
-   [Link implicitamente](../Topic/Linking%20Implicitly.md)  
  
-   [Link explicitamente](../build/linking-explicitly.md)  
  
-   [Determine o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)