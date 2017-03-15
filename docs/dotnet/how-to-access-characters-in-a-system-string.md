---
title: "Como acessar caracteres em um System::String | Microsoft Docs"
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
  - "caracteres [C++], acessando em System::String"
  - "exemplos [C++], cadeias de caracteres"
  - "cadeias de caracteres [C++], acessando caracteres"
ms.assetid: cfc89756-aef3-4988-907e-fb236dcb7087
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como acessar caracteres em um System::String
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode acessar caracteres de um objeto de <xref:System.String> para chamadas de alto desempenho para funções não gerenciado que usam cadeias de caracteres de `wchar_t*` .  O método produz um ponteiro dentro do primeiro caractere do objeto de <xref:System.String> .  Esse ponteiro pode ser manipulado diretamente ou fixado e passado a uma função que espera uma cadeia de caracteres comum de `wchar_t` .  
  
## Exemplo  
 `PtrToStringChars` retorna <xref:System.Char>, que é um ponteiro interior \(também conhecido como `byref`\).  Como tal, está sujeita à coleta de lixo.  Você não precisa manter esse ponteiro a menos que você esteja que o passar a uma função nativo.  
  
 Considere o seguinte código.  Fixar\-se não é necessário porque `ppchar` é um ponteiro interior, e se o coletor de lixo move a cadeia de caracteres que aponte para, também atualizará `ppchar`.  Sem [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md), o código funcionará e não terá a ocorrência de desempenho potencial causada fixando\-se.  
  
 Se você passar `ppchar` a uma função nativo, deverá ser um ponteiro fixando\-se; o coletor de lixo não poderá atualizar os ponteiros no quadro de pilhas não gerenciado.  
  
```  
// PtrToStringChars.cpp  
// compile with: /clr  
#include<vcclr.h>  
using namespace System;  
  
int main() {  
   String ^ mystring = "abcdefg";  
  
   interior_ptr<const Char> ppchar = PtrToStringChars( mystring );  
  
   for ( ; *ppchar != L'\0'; ++ppchar )  
      Console::Write(*ppchar);  
}  
```  
  
  **abcdefg**   
## Exemplo  
 Este exemplo mostra onde se for necessário manter.  
  
```  
// PtrToStringChars_2.cpp  
// compile with: /clr  
#include <string.h>  
#include <vcclr.h>  
// using namespace System;  
  
size_t getlen(System::String ^ s) {  
   // Since this is an outside string, we want to be secure.  
   // To be secure, we need a maximum size.  
   size_t maxsize = 256;  
   // make sure it doesn't move during the unmanaged call  
   pin_ptr<const wchar_t> pinchars = PtrToStringChars(s);  
   return wcsnlen(pinchars, maxsize);  
};  
  
int main() {  
   System::Console::WriteLine(getlen("testing"));  
}  
```  
  
 **7**   
## Exemplo  
 Um ponteiro interior tem todas as propriedades de um ponteiro de C\+\+ nativo.  Por exemplo, você pode usá\-lo para percorrer uma estrutura de dados vinculada e fazer inserções e exclusões usando somente um ponteiro:  
  
```  
// PtrToStringChars_3.cpp  
// compile with: /clr /LD  
using namespace System;  
ref struct ListNode {  
   Int32 elem;   
   ListNode ^ Next;  
};  
  
void deleteNode( ListNode ^ list, Int32 e ) {   
   interior_ptr<ListNode ^> ptrToNext = &list;  
   while (*ptrToNext != nullptr) {  
      if ( (*ptrToNext) -> elem == e )  
         *ptrToNext = (*ptrToNext) -> Next;   // delete node  
      else  
         ptrToNext = &(*ptrToNext) -> Next;   // move to next node  
   }  
}  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)