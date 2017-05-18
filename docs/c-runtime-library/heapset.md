---
title: _heapset | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _heapset
apilocation:
- msvcr90.dll
- msvcr80.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr120.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- _heapset
- heapset
dev_langs:
- C++
helpviewer_keywords:
- checking heap
- heapset function
- heaps, checking
- debugging [CRT], heap-related problems
- _heapset function
ms.assetid: 9667eeb0-55bc-4c19-af5f-d1fd0a142b3c
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Human Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 0bcd8094d0b07927c8f85baf81d6ae834d283d9d
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="heapset"></a>_heapset
Verifica heaps quanto à consistência mínima e configura as entradas livres com um valor especificado.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _heapset(   
   unsigned int fill   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fill`  
 Caractere de preenchimento.  
  
## <a name="return-value"></a>Valor de retorno  
 `_heapset` retorna uma das seguintes constantes de manifesto de inteiro definidas em Malloc.h.  
  
 `_HEAPBADBEGIN`  
 As informações do cabeçalho inicial são inválidas ou não foram encontradas.  
  
 `_HEAPBADNODE`  
 Heap danificado ou nó inválido encontrado.  
  
 `_HEAPEMPTY`  
 Heap não inicializado.  
  
 `_HEAPOK`  
 O heap parece ser consistente.  
  
 Além disso, se ocorrer um erro, `_heapset` definirá `errno` como `ENOSYS`.  
  
## <a name="remarks"></a>Comentários  
 A função `_heapset` mostra locais com memória livre ou nós que foram substituídos acidentalmente.  
  
 `_heapset` verifica a consistência mínima no heap e define cada byte das entradas livres do heap para o valor `fill`. Esse valor conhecido mostra quais locais de memória do heap contêm nós livres e quais contêm dados que foram gravados acidentalmente na memória liberada. Se o sistema operacional não der suporte a `_heapset` (por exemplo, Windows 98), a função retornará `_HEAPOK` e definirá `errno` como `ENOSYS`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_heapset`|\<malloc.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_heapset.c  
// This program checks the heap and  
// fills in free entries with the character 'Z'.  
  
#include <malloc.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int heapstatus;  
   char *buffer;  
  
   if( (buffer = malloc( 1 )) == NULL ) // Make sure heap is   
      exit( 0 );                        //    initialized       
   heapstatus = _heapset( 'Z' );        // Fill in free entries   
   switch( heapstatus )  
   {  
   case _HEAPOK:  
      printf( "OK - heap is fine\n" );  
      break;  
   case _HEAPEMPTY:  
      printf( "OK - heap is empty\n" );  
      break;  
   case _HEAPBADBEGIN:  
      printf( "ERROR - bad start of heap\n" );  
      break;  
   case _HEAPBADNODE:  
      printf( "ERROR - bad node in heap\n" );  
      break;  
   }  
   free( buffer );  
}  
```  
  
```Output  
OK - heap is fine  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../c-runtime-library/memory-allocation.md)   
 [_heapadd](../c-runtime-library/heapadd.md)   
 [_heapchk](../c-runtime-library/reference/heapchk.md)   
 [_heapmin](../c-runtime-library/reference/heapmin.md)   
 [_heapwalk](../c-runtime-library/reference/heapwalk.md)
