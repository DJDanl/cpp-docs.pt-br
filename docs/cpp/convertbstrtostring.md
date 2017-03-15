---
title: "ConvertBSTRToString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "ConvertBSTRToString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função ConvertBSTRToString"
ms.assetid: ab6ce555-3d75-4e9c-9cb8-ada6d8ce43b1
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ConvertBSTRToString
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Converte um valor `BSTR` em um **char \***.  
  
## Sintaxe  
  
```  
  
      char* __stdcall ConvertBSTRToString(  
   BSTR pSrc  
);  
```  
  
#### Parâmetros  
 `pSrc`  
 Uma variável BSTR.  
  
## Comentários  
 `ConvertBSTRToString` aloca uma cadeia de caracteres que você deve excluir.  
  
## Exemplo  
  
```  
// ConvertBSTRToString.cpp  
#include <comutil.h>  
#include <stdio.h>  
  
#pragma comment(lib, "comsuppw.lib")  
  
int main() {  
   BSTR bstrText = ::SysAllocString(L"Test");  
   wprintf_s(L"BSTR text: %s\n", bstrText);  
  
   char* lpszText2 = _com_util::ConvertBSTRToString(bstrText);  
   printf_s("char * text: %s\n", lpszText2);  
  
   SysFreeString(bstrText);  
   delete[] lpszText2;  
}  
```  
  
  **Texto BSTR: Teste**  
**Texto char \*: Teste**   
## FIM de Específico da Microsoft  
  
## Requisitos  
 **Cabeçalho:** comutil.h.  
  
 **Bib:** comsuppw.lib ou comsuppwd.lib \(consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações\)  
  
## Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)