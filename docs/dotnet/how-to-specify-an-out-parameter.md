---
title: "Como especificar um par&#226;metro out | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "parâmetros de função"
  - "parâmetros out"
ms.assetid: 02862448-603c-4e9d-a5c5-b45fe38446e3
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como especificar um par&#226;metro out
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como especificar que um parâmetro de função é um parâmetro de saída e como chamar a função de um programa C\#.  
  
 Um parâmetro de saída for especificado no Visual C\+\+ com <xref:System.Runtime.InteropServices.OutAttribute> .  
  
## Exemplo  
 A primeira parte deste exemplo é uma DLL do Visual C\+\+ com um tipo que contém uma função com um parâmetro de saída.  
  
```  
// cpp_out_param.cpp  
// compile with: /LD /clr:safe  
using namespace System;  
public value struct TestStruct {  
   static void Test([Runtime::InteropServices::Out] String^ %s) {  
      s = "a string";  
   }  
};  
```  
  
## Exemplo  
 Este é um cliente C\# que consome o componente Visual C\+\+ criado no exemplo anterior.  
  
```  
// cpp_out_param_2.cs  
// compile with: /reference:cpp_out_param.dll  
using System;  
class TestClass {  
   public static void Main() {  
      String t;  
      TestStruct.Test(out t);  
      System.Console.WriteLine(t);  
   }  
}  
```  
  
  **uma cadeia de caracteres**   
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)