---
title: "_malloca | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_malloca"
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
  - "malloca"
  - "_malloca"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _malloca"
  - "Função malloca"
  - "alocação de memória, stack"
ms.assetid: 293992df-cfca-4bc9-b313-0a733a6bb936
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _malloca
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aloca memória na pilha.  Essa é uma versão de [\_alloca](../../c-runtime-library/reference/alloca.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
void *_malloca(   
   size_t size   
);  
```  
  
#### Parâmetros  
 `size`  
 Bytes a ser atribuídos de pilha.  
  
## Valor de retorno  
 A rotina de `_malloca` retorna um ponteiro de `void` ao espaço alocado, que tem a garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Se `size` é 0, `_malloca` atribui um item de comprimento zero e retorna um ponteiro válido para o item.  
  
 Uma exceção de estouro de pilha é gerada se o espaço não pode ser atribuído.  A exceção de estouro de pilhas não é exception c; criando é uma exceção estruturados.  Em vez de usar a manipulação de exceção C\+\+, você deve usar [Manipulação de exceção estruturado](../../cpp/structured-exception-handling-c-cpp.md) \(ELA\).  
  
## Comentários  
 `_malloca` atribui bytes de `size` da pilha de programa ou heap se a solicitação excede determinado tamanho em bytes dados por `_ALLOCA_S_THRESHOLD`.  A diferença entre `_malloca` e `_alloca` é que `_alloca` atribui sempre na pilha, independentemente do tamanho.  Ao contrário de `_alloca`, que não requer nem permite uma chamada a `free` liberar a memória alocada assim, `_malloca` requer o uso de [\_freea](../../c-runtime-library/reference/freea.md) liberar a memória.  No modo de depuração, `_malloca` sempre atribui a memória heap.  
  
 Há restrições explicitamente a `_malloca` chamar em um identificador \(EH\) da exceção.  As rotinas de EH executadas em processadores de x86\-class operam em seu próprio quadro de memória: Executam as tarefas no espaço de memória que não é baseado no local atual do ponteiro de pilha da função inclusive.  As implementações mais comuns incluem expressões estruturadas o Windows NT a cláusula FROM de manipulação de exceção \(SEH\) e de captura C\+\+.  Consequentemente, chamar explicitamente `_malloca` em qualquer um dos seguintes cenários resulta na falha do programa durante o retorno para a rotina chamando de EH:  
  
-   Windows NT ELA expressão de filtro de exceção: `__except` \(`_malloca ()` \)  
  
-   Windows NT ELA manipulador final de exceção: `__finally``_malloca ()` {}  
  
-   Expressão da cláusula de captura de EH C\+\+  
  
 No entanto, `_malloca` pode ser chamado diretamente de uma rotina de EH ou de um retorno de chamada fornecido pelo aplicativo que é invocado por um dos cenários de EH listados anteriormente.  
  
> [!IMPORTANT]
>  No Windows XP, se `_malloca` é chamado dentro de um bloco try\/catch, você deve chamar [\_resetstkoflw](../Topic/_resetstkoflw.md) no bloco de captura.  
  
 Além das restrições anteriores, ao usar a opção de [\/clr \(Compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) , `_malloca` não pode ser usado em blocos de `__except` .  Para obter mais informações, consulte [Limitações do \/clr](../../build/reference/clr-restrictions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_malloca`|\<malloc.h\>|  
  
## Exemplo  
  
```  
// crt_malloca_simple.c  
#include <stdio.h>  
#include <malloc.h>  
  
void Fn()  
{  
   char * buf = (char *)_malloca( 100 );  
   // do something with buf  
   _freea( buf );  
}  
  
int main()  
{  
   Fn();  
}  
```  
  
## Exemplo  
  
```  
// crt_malloca_exception.c  
// This program demonstrates the use of  
// _malloca and trapping any exceptions  
// that may occur.  
  
#include <windows.h>  
#include <stdio.h>  
#include <malloc.h>  
  
int main()  
{  
    int     size;  
    int     numberRead = 0;  
    int     errcode = 0;  
    void    *p = NULL;  
    void    *pMarker = NULL;  
  
    while (numberRead == 0)  
    {  
        printf_s("Enter the number of bytes to allocate "  
                 "using _malloca: ");  
        numberRead = scanf_s("%d", &size);  
    }  
  
    // Do not use try/catch for _malloca,  
    // use __try/__except, since _malloca throws  
    // Structured Exceptions, not C++ exceptions.  
  
    __try  
    {  
        if (size > 0)  
        {  
            p =  _malloca( size );  
        }  
        else  
        {  
            printf_s("Size must be a positive number.");  
        }  
        _freea( p );  
    }  
  
    // Catch any exceptions that may occur.  
    __except( GetExceptionCode() == STATUS_STACK_OVERFLOW )  
    {  
        printf_s("_malloca failed!\n");  
  
        // If the stack overflows, use this function to restore.  
        errcode = _resetstkoflw();  
        if (errcode)  
        {  
            printf("Could not reset the stack!");  
            _exit(1);  
        }  
    };  
}  
```  
  
## Entrada  
  
```  
1000  
```  
  
## Saída de Exemplo  
  
```  
Enter the number of bytes to allocate using _malloca: 1000  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_resetstkoflw](../Topic/_resetstkoflw.md)