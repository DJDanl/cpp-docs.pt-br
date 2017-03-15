---
title: "Como converter a cadeia de caracteres char * na matriz System::Byte | Microsoft Docs"
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
  - "matrizes [C++], caractere"
  - "matrizes de caracteres, convertendo em matrizes System::Byte"
  - "exemplos [C++], matrizes"
  - "exemplos [C++], cadeias de caracteres"
ms.assetid: de9bc4eb-773c-4796-a496-9b90ca986503
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter a cadeia de caracteres char * na matriz System::Byte
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira mais eficiente de converter uma cadeia de caracteres de `char *` a uma matriz de <xref:System.Byte> é usar a classe de <xref:System.Runtime.InteropServices.Marshal> .  
  
## Exemplo  
  
```  
// convert_native_string_to_Byte_array.cpp  
// compile with: /clr  
#include <string.h>  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
int main() {  
   char buf[] = "Native String";  
   int len = strlen(buf);  
  
   array< Byte >^ byteArray = gcnew array< Byte >(len + 2);  
  
   // convert native pointer to System::IntPtr with C-Style cast  
   Marshal::Copy((IntPtr)buf,byteArray, 0, len);  
  
   for ( int i = byteArray->GetLowerBound(0); i <= byteArray->GetUpperBound(0); i++ ) {  
      char dc =  *(Byte^)   byteArray->GetValue(i);  
      Console::Write((Char)dc);  
   }  
  
   Console::WriteLine();  
}  
```  
  
```  
Native String  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)