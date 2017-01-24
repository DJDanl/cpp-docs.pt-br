---
title: "Especificando DLLs para carga com atraso | Microsoft Docs"
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
  - "Opção de vinculador /DELAYLOAD"
  - "carregamento atrasado de DLLs"
  - "carregamento atrasado de DLLs, especificando"
  - "opção de vinculador DELAYLOAD"
ms.assetid: 94cbecfe-7a42-40d1-a618-9f2786bac0d8
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especificando DLLs para carga com atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode especificar quais DLLs de atraso de carga com o [\/delayload](../../build/reference/delayload-delay-load-import.md):`dllname` opção de vinculador.  Se você não planeja usar sua própria versão de uma função auxiliar, você também deve vincular seu programa com delayimp.lib \(para aplicativos de área de trabalho\) ou dloadhelper.lib \(para aplicativos da Windows store\).  
  
 Este é um exemplo simples de uma DLL de carregamento com atraso:  
  
```  
// cl t.cpp user32.lib delayimp.lib  /link /DELAYLOAD:user32.dll  
#include <windows.h>  
// uncomment these lines to remove .libs from command line  
// #pragma comment(lib, "delayimp")  
// #pragma comment(lib, "user32")  
  
int main() {  
   // user32.dll will load at this point  
   MessageBox(NULL, "Hello", "Hello", MB_OK);  
}  
```  
  
 Crie a versão de depuração do projeto.  Percorrer o código usando o depurador e você observará que User32. dll é carregado apenas quando você faz a chamada para `MessageBox`.  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)