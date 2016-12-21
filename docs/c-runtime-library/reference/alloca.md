---
title: "_alloca | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_alloca"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_alloca"
  - "alloca"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _alloca"
  - "Função alloca"
  - "alocação de memória, stack"
ms.assetid: 74488eb1-b71f-4515-88e1-cdd03b6f8225
caps.latest.revision: 23
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _alloca
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aloca memória na pilha.  Esta função é substituída por uma versão mais segura estiver disponível; consulte [\_malloca](../../c-runtime-library/reference/malloca.md).  
  
## Sintaxe  
  
```  
void *_alloca(   
   size_t size   
);  
```  
  
#### Parâmetros  
 \[entrada\] `size`  
 Bytes a ser atribuídos de pilha.  
  
## Valor de retorno  
 A rotina de `_alloca` retorna um ponteiro de `void` ao espaço alocado, que tem a garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Se `size` é 0, `_alloca` atribui um item de comprimento zero e retorna um ponteiro válido para o item.  
  
 Uma exceção de estouro de pilha é gerada se o espaço não pode ser atribuído.  A exceção de estouro de pilhas não é exception c; criando é uma exceção estruturados.  Em vez de usar a manipulação de exceção C\+\+, você deve usar [Manipulação de exceção estruturado](../../cpp/structured-exception-handling-c-cpp.md) \(ELA\).  
  
## Comentários  
 `_alloca` atribui bytes de `size` da pilha de programa.  O espaço alocado será liberado automaticamente quando a função de chamada é encerrado \(não quando a alocação passa então fora do escopo\).  Consequentemente, não transmita o valor do ponteiro retornado por `_alloca` como um argumento para [livre](../../c-runtime-library/reference/free.md).  
  
 Há restrições explicitamente a `_alloca` chamar em um identificador \(EH\) da exceção.  As rotinas de EH executadas em processadores de x86\-class operam em seu próprio quadro de memória: Executam as tarefas no espaço de memória que não é baseado no local atual do ponteiro de pilha da função inclusive.  As implementações mais comuns incluem expressões estruturadas o Windows NT a cláusula FROM de manipulação de exceção \(SEH\) e de captura C\+\+.  Consequentemente, chamar explicitamente `_alloca` em qualquer um dos seguintes cenários resulta na falha do programa durante o retorno para a rotina chamando de EH:  
  
-   Windows NT ELA expressão de filtro de exceção: `__except` \(`_alloca ()` \)  
  
-   Windows NT ELA manipulador final de exceção: `__finally``_alloca ()` {}  
  
-   Expressão da cláusula de captura de EH C\+\+  
  
 No entanto, `_alloca` pode ser chamado diretamente de uma rotina de EH ou de um retorno de chamada fornecido pelo aplicativo que é invocado por um dos cenários de EH listados anteriormente.  
  
> [!IMPORTANT]
>  No Windows XP, se `_alloca` é chamado dentro de um bloco try\/catch, você deve chamar [\_resetstkoflw](../Topic/_resetstkoflw.md) no bloco de captura.  
  
 Além das restrições anteriores, ao usar a opção de[\/clr \(Compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) , `_alloca` não pode ser usado em blocos de `__except` .  Para obter mais informações, consulte [Limitações do \/clr](../../build/reference/clr-restrictions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_alloca`|\<malloc.h\>|  
  
## Exemplo  
  
```  
// crt_alloca.c  
// This program demonstrates the use of  
// _alloca and trapping any exceptions  
// that may occur.  
  
#include <windows.h>  
#include <stdio.h>  
#include <malloc.h>  
  
int main()  
{  
    int     size = 1000;  
    int     errcode = 0;  
    void    *pData = NULL;  
  
    // Note: Do not use try/catch for _alloca,  
    // use __try/__except, since _alloca throws  
    // Structured Exceptions, not C++ exceptions.  
  
    __try {  
        // An unbounded _alloca can easily result in a   
        // stack overflow.  
        // Checking for a size < 1024 bytes is recommended.  
        if (size > 0 && size < 1024)  
        {  
            pData = _alloca( size );  
            printf_s( "Allocated %d bytes of stack at 0x%p",  
                      size, pData);  
        }  
        else  
        {  
            printf_s("Tried to allocate too many bytes.\n");  
        }  
    }  
  
    // If an exception occured with the _alloca function  
    __except( GetExceptionCode() == STATUS_STACK_OVERFLOW )  
    {  
        printf_s("_alloca failed!\n");  
  
        // If the stack overflows, use this function to restore.  
        errcode = _resetstkoflw();  
        if (errcode)  
        {  
            printf_s("Could not reset the stack!\n");  
            _exit(1);  
        }  
    };  
}  
```  
  
  **Atribuído 1000 bytes da pilha em 0x0012FB50**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_resetstkoflw](../Topic/_resetstkoflw.md)   
 [\_malloca](../../c-runtime-library/reference/malloca.md)