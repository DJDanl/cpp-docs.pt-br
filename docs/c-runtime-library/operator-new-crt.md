---
title: "operator new (CRT) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
apitype: "DLLExport"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "operator new"
  - "escalar novo"
ms.assetid: 4ae51618-a4e6-4172-b324-b99d86d1bdca
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# operator new (CRT)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atribui o bloco de memória heap  
  
## Sintaxe  
  
```  
  
      void *__cdecl operator new(  
   size_t count  
);  
void *__cdecl operator new(  
   size_t count,   
   void * object  
) throw();  
void *__cdecl operator new(  
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
 Esse formulário de `operator new` é conhecido como novo escalar, em contraste com o novo formulário de vetor[operador novo &#91;&#93;](../c-runtime-library/new-operator-crt.md)\(\).  
  
 O primeiro formulário desse operador é conhecido como o formulário de nonplacement.  O segundo formulário desse operador é conhecido como o formulário de posicionamento e o terceiro formulário desse operador é nonthrowing, formulário de posicionamento.  
  
 O primeiro formulário do operador é definido pelo compilador e não requer new.h ser incluído em seu programa.  
  
 [a exclusão do operador](../c-runtime-library/operator-delete-crt.md) libera memória alocada com `operator new`.  
  
 Você pode configurar se retorna nulo do operador novo ou lance uma exceção de falha.  Consulte [Operadores novos e exclusão](../cpp/new-and-delete-operators.md) para obter mais informações.  
  
 Com exceção do comportamento de reprodução ou de reprodução, o CRT `operator new` se comporta como [operador novo](../Topic/operator%20new%20\(%3Cnew%3E\).md) na biblioteca padrão C\+\+.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|**novo**|\<new.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 O exemplo a seguir mostra como usar o escalar, formulário de nonplacement de `operator new`.  
  
```  
// crt_new1.cpp  
#include <stdio.h>  
int main() {  
   int * i = new int(6);  
   printf("%d\n", *i);  
   delete i;  
}  
```  
  
 O exemplo a seguir mostra como usar o escalar, formulário de posicionamento de `operator new`.  
  
```  
// crt_new2.cpp  
#include <stdio.h>  
#include <new.h>  
int main() {  
   int * i = new int(12);  
   printf("*i = %d\n", *i);  
   // initialize existing memory (i) with, in this case, int(7)  
   int * j = new(i) int(7);   // placement new  
   printf("*j = %d\n", *j);  
   printf("*i = %d\n", *i);  
   delete i;   // or, could have deleted j  
}  
```  
  
 O exemplo a seguir mostra como usar a escalar, posição, formulário de não geram de `operator new`.  
  
```  
// crt_new3.cpp  
#include <stdio.h>  
#include <new.h>  
int main() {  
   // allocates memory, initialize (8) and if call fails, new returns null  
   int * k = new(std::nothrow) int(8);   // placement new  
   printf("%d\n", *k);  
   delete k;  
}  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../c-runtime-library/memory-allocation.md)