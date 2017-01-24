---
title: "Operador __uuidof | Microsoft Docs"
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
  - "__LIBID_"
  - "__LIBID_cpp"
  - "__uuidof"
  - "__uuidof_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __LIBID_ [C++]"
  - "Palavra-chave __uuidof [C++]"
ms.assetid: badfe709-809b-4b66-ad48-ee35039d25c6
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador __uuidof
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Recupera o GUID vinculado à expressão.  
  
## Sintaxe  
  
```  
  
      __uuidof (  
   expression   
)  
```  
  
## Comentários  
 The *expressão* pode ser um nome de tipo, um ponteiro, uma referência ou uma matriz desse tipo, um modelo especializado nesses tipos ou uma variável desses tipos.  O argumento é válido enquanto o compilador puder usá\-lo para localizar o GUID vinculado.  
  
 Um caso especial desse intrínseco é quando **0** ou **NULL** são fornecidos como o argumento.  Nesse caso, `__uuidof` retornará um GUID composto de zero.  
  
 Use essa palavra\-chave para extrair o GUID vinculado a:  
  
-   Um objeto pelo atributo estendido [uuid](../cpp/uuid-cpp.md).  
  
-   Um bloco de biblioteca criado com o atributo [module](../windows/module-cpp.md).  
  
> [!NOTE]
>  Em uma compilação de depuração, `__uuidof` sempre inicializa um objeto dinamicamente \(no tempo de execução\).  Em uma compilação de versão, `__uuidof` pode inicializar um objeto estaticamente \(no tempo de compilação\).  
  
## Exemplo  
 O código a seguir \(compilado com ole32.lib\) exibirá o uuid de um bloco de biblioteca criado com o atributo module:  
  
```  
// expre_uuidof.cpp  
// compile with: ole32.lib  
#include "stdio.h"  
#include "windows.h"  
  
[emitidl];  
[module(name="MyLib")];  
[export]  
struct stuff {  
   int i;  
};  
  
int main() {  
   LPOLESTR lpolestr;  
   StringFromCLSID(__uuidof(MyLib), &lpolestr);  
   wprintf_s(L"%s", lpolestr);  
   CoTaskMemFree(lpolestr);  
}  
```  
  
## Comentários  
 Em casos nos quais o nome da biblioteca não está mais no escopo, é possível usar \_\_LIBID\_ em vez de `__uuidof`.  Por exemplo:  
  
```  
StringFromCLSID(__LIBID_, &lpolestr);  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)