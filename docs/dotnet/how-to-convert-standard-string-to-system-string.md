---
title: "Como converter cadeia de caracteres padr&#227;o em System::String | Microsoft Docs"
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
  - "Biblioteca Padrão C++, convertendo cadeias de caracteres em System::String"
  - "conversão de cadeia de caracteres [C++], cadeia de caracteres de Biblioteca Padrão C++"
  - "cadeias de caracteres [C++], convertendo"
ms.assetid: 1fde79a0-9d0b-44e5-981b-e8f2676c199d
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter cadeia de caracteres padr&#227;o em System::String
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como converter uma cadeia de caracteres de biblioteca padrão \(C\+\+\)[\<string\>](../standard-library/string.md)a <xref:System.String>.  
  
## Exemplo  
  
```  
// convert_standard_string_to_system_string.cpp  
// compile with: /clr  
#include <string>  
#include <iostream>  
using namespace System;  
using namespace std;  
  
int main() {  
   string str = "test";  
   cout << str << endl;  
   String^ str2 = gcnew String(str.c_str());  
   Console::WriteLine(str2);  
  
   // alternatively  
   String^ str3 = gcnew String(str.c_str());  
   Console::WriteLine(str3);  
}  
```  
  
  **testar**  
**testar**  
**testar**   
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)