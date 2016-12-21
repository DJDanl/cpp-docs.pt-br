---
title: "operator new(CRT) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
  - "msvcr120.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
f1_keywords: 
  - "new[]"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "operator new[]"
  - "vetor novo"
ms.assetid: 79682f85-6889-40f6-b8f7-9eed5176ea35
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# operator new(CRT)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atribui o bloco de memória heap  
  
## Sintaxe  
  
```  
  
      void *__cdecl operator new[](size_t count);  
void *__cdecl operator new[] (  
   size_t count,   
   void * object  
) throw();  
void *__cdecl operator new[] (  
   size_t count,   
   const std::nothrow_t&  
) throw();  
```  
  
#### Parâmetros  
 *count*  
 O tamanho da alocação.  
  
 *objeto*  
 Um ponteiro para um bloco de memória no qual o objeto será criado.  
  
## Valor de retorno  
 Um ponteiro para o mais baixo endereço de bytes de armazenamento recentemente alocado.  
  
## Comentários  
 Esse formulário de `operator new` é conhecido como o vetor nova, em contraste com o novo formulário escalar \([operador novo](../c-runtime-library/operator-new-crt.md)\).  
  
 O primeiro formulário desse operador é conhecido como o formulário de nonplacement.  O segundo formulário desse operador é conhecido como o formulário de posicionamento e o terceiro formulário desse operador é a forma nonthrowing de posicionamento.  
  
 O primeiro formulário do operador é definido pelo compilador e não requer new.h ser incluído em seu programa.  
  
 [a exclusão do operador &#91;&#93;](../Topic/operator%20delete\(%3Cnew%3E\).md) libera memória alocada com o operador novo.  
  
 Você pode configurar se `operator new[]` retorna nulo ou lance uma exceção de falha.  Consulte [Operadores novos e exclusão](../cpp/new-and-delete-operators.md) para obter mais informações.  
  
 Com exceção do comportamento de reprodução ou de reprodução, o CRT `operator new` se comporta como [operador novo &#91;&#93;](../Topic/operator%20new\(%3Cnew%3E\).md) na biblioteca padrão C\+\+.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`new[]`|\<new.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 O exemplo a seguir mostra como usar o vetor, formulário de nonplacement de `operator new`.  
  
```  
// crt_new4.cpp  
#include <stdio.h>  
int main() {  
   int * k = new int[10];  
   k[0] = 21;  
   printf("%d\n", k[0]);  
   delete [] k;  
}  
```  
  
 O exemplo a seguir mostra como usar o vetor, formulário de posicionamento de `operator new`.  
  
```  
// crt_new5.cpp  
#include <stdio.h>  
#include <new.h>  
int main() {  
   int * i = new int[10];  
   i[0] = 21;  
   printf("%d\n", i[0]);  
   // initialize existing memory (i) with, in this case, int[[10]  
   int * j = new(i) int[10];   // placement vector new  
   printf("%d\n", j[0]);  
   j[0] = 22;  
   printf("%d\n", i[0]);  
   delete [] i;   // or, could have deleted [] j   
}  
```  
  
 O exemplo a seguir mostra como usar o vetor, posição, formulário de não geram de `operator new`.  
  
```  
// crt_new6.cpp  
#include <stdio.h>  
#include <new.h>  
int main() {  
   int * k = new(std::nothrow) int[10];  
   k[0] = 21;  
   printf("%d\n", k[0]);  
   delete [] k;  
}  
```  
  
## Consulte também  
 [Alocação de memória](../c-runtime-library/memory-allocation.md)