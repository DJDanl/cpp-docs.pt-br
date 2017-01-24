---
title: "Compilador C4792 de aviso (n&#237;vel 3) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4792"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4792"
ms.assetid: c047ce69-a622-44e1-9425-d41aa9261c61
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4792 de aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

' função ' declarado usando sysimport e referenciada no código nativo; biblioteca de importação precisa vincular  
  
 Uma função nativa que foi importada para o programa com DllImport foi chamada de uma função não gerenciada. Portanto, você deve vincular a biblioteca de importação para a DLL.  
  
 Este aviso não pode ser resolvido no código ou alterando a maneira como você compilar. Use o [Aviso](../../preprocessor/warning.md) pragma para desabilitar esse aviso.  
  
 O exemplo a seguir gera C4792:  
  
```  
// C4792.cpp // compile with: /clr /W3 // C4792 expected using namespace System::Runtime::InteropServices; [DllImport("msvcrt")] extern "C" int __cdecl puts(const char *); int main() {} // Uncomment the following line to resolve. // #pragma warning(disable : 4792) #pragma unmanaged void func(void){ puts("test"); }  
```