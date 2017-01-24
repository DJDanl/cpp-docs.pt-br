---
title: "_CrtIsValidHeapPointer | Microsoft Docs"
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
  - "_CrtIsValidHeapPointer"
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
  - "CrtlsValidHeapPointer"
  - "_CrtIsValidHeapPointer"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtIsValidHeapPointer"
  - "Função CrtIsValidHeapPointer"
ms.assetid: caf597ce-1b05-4764-9f37-0197a982bec5
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtIsValidHeapPointer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um ponteiro especificado está em um heap alocado por alguma biblioteca em tempo de execução C, mas não necessariamente pela biblioteca de CRT do chamador.  Nas versões do CRT antes do Visual Studio 2010, isso verifica se o ponteiro especificado está no heap local \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
  
        int _CrtIsValidHeapPointer(   
   const void *userData   
);  
```  
  
#### Parâmetros  
 `userData`  
 Ponteiro para o início de um bloco de memória alocada.  
  
## Valor de retorno  
 `_CrtIsValidHeapPointer` Retorna VERDADEIRO se o ponteiro especificado está no heap compartilhado por todas as instâncias da biblioteca CRT.  Nas versões do CRT antes do Visual Studio 2010, isso retorna TRUE se o ponteiro especificado está no heap local.  Caso contrário, a função retorna FALSE.  
  
## Comentários  
 Não recomendamos que você use essa função.  A partir da biblioteca CRT de 2010 do Visual Studio, todas as bibliotecas CRT compartilham um heap do sistema operacional, o *heap de processo*.  O `_CrtIsValidHeapPointer` função informa se o ponteiro foi alocado no heap CRT, mas não foi atribuída pela biblioteca de CRT do chamador.  Por exemplo, considere um bloco alocado usando a versão do Visual Studio 2010 da biblioteca CRT.  Se o `_CrtIsValidHeapPointer` função exportada pela versão Visual Studio 2012 da biblioteca CRT testa o ponteiro, ele retorna TRUE.  Isso não é mais um teste úteis.  Nas versões da biblioteca CRT antes do Visual Studio 2010, a função é usada para garantir que um endereço de memória específica está em heap local.  Heap local refere\-se à pilha criadas e gerenciadas por uma instância específica da biblioteca em tempo de execução C.  Se uma biblioteca de vínculo dinâmico \(DLL\) contém um link estático para a biblioteca de tempo de execução, ele tem sua própria instância do heap de tempo de execução e, portanto, seu próprio heap, independente do heap local do aplicativo.  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, as chamadas a `_CrtIsValidHeapPointer` são removidas durante o pré\-processamento.  
  
 Como essa função retorna TRUE ou FALSE, ela pode ser informada a uma das macros de [\_ASSERT](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) para criar um mecanismo de tratamento de erro de depuração simples.  O exemplo a seguir faz com que uma falha de asserção se o endereço especificado não estiver localizado no heap local:  
  
```  
_ASSERTE( _CrtIsValidHeapPointer( userData ) );  
```  
  
 Para obter mais informações sobre como `_CrtIsValidHeapPointer` pode ser usado com outras funções de depuração e macros, consulte [Macros para relatórios](../Topic/Macros%20for%20Reporting.md).  Para obter informações sobre como blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtIsValidHeapPointer`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como testar se a memória é válida quando usado com bibliotecas de tempo de execução C antes do Visual Studio 2010.  Este exemplo é fornecido para usuários do código da biblioteca CRT herdado.  
  
```  
// crt_isvalid.c  
/*  
 * This program allocates a block of memory using _malloc_dbg  
 * and then tests the validity of this memory by calling   
 * _CrtIsMemoryBlock,_CrtIsValidPointer, and _CrtIsValidHeapPointer.  
 */  
  
#include <stdio.h>  
#include <string.h>  
#include <malloc.h>  
#include <crtdbg.h>  
  
#define  TRUE   1  
#define  FALSE  0  
  
int main( void )  
{  
        char *my_pointer;  
  
        /*   
         * Call _malloc_dbg to include the filename and line number  
         * of our allocation request in the header information  
         */  
        my_pointer = (char *)_malloc_dbg( sizeof(char) * 10,   
        _NORMAL_BLOCK, __FILE__, __LINE__ );  
  
        // Ensure that the memory got allocated correctly  
        _CrtIsMemoryBlock((const void *)my_pointer, sizeof(char) * 10,   
        NULL, NULL, NULL );  
  
         // Test for read/write accessibility  
        if (_CrtIsValidPointer((const void *)my_pointer,   
        sizeof(char) * 10, TRUE))  
                printf("my_pointer has read and write accessibility.\n");  
        else  
                printf("my_pointer only has read access.\n");  
  
        // Make sure my_pointer is within the local heap  
        if (_CrtIsValidHeapPointer((const void *)my_pointer))  
                printf("my_pointer is within the local heap.\n");  
        else  
                printf("my_pointer is not located within the local"  
                       " heap.\n");  
  
        free(my_pointer);  
}  
```  
  
## Saída  
  
```  
my_pointer has read and write accessibility.  
my_pointer is within the local heap.  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)