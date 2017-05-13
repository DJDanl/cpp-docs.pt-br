---
title: _putw | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _putw
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _putw
- putw
dev_langs:
- C++
helpviewer_keywords:
- integers, writing to streams
- putw function
- streams, writing integers to
- _putw function
ms.assetid: 83d63644-249d-4a39-87e5-3b7aa313968d
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 5e6cb1b57135502d7e75df7d0db7cb363a1fe003
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="putw"></a>_putw
Grava um valor inteiro em um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int _putw(  
   int binint,  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *binint*  
 Inteiro binário de saída.  
  
 `stream`  
 Ponteiro para a estrutura **FILE**.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o valor gravado. Um valor retornado de `EOF` pode indicar um erro. Como `EOF` também é um valor inteiro legítimo, use `ferror` para verificar se há um erro. Se `stream` for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `EOF`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_putw` grava um valor binário de tipo `int` para a posição atual do *fluxo.* `_putw` não afeta o alinhamento dos itens no fluxo, nem assume nenhum alinhamento especial. `_putw` destina-se principalmente à compatibilidade com bibliotecas anteriores. Problemas de portabilidade podem ocorrer com `_putw`, pois o tamanho de um `int` e a ordenação de bytes dentro de um `int` diferem entre sistemas.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_putw`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_putw.c  
/* This program uses _putw to write a  
 * word to a stream, then performs an error check.  
 */  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   FILE *stream;  
   unsigned u;  
   if( fopen_s( &stream, "data.out", "wb" ) )  
      exit( 1 );  
   for( u = 0; u < 10; u++ )  
   {  
      _putw( u + 0x2132, stream );   /* Write word to stream. */  
      if( ferror( stream ) )         /* Make error check. */  
      {  
         printf( "_putw failed" );  
         clearerr_s( stream );  
         exit( 1 );  
      }  
   }  
   printf( "Wrote ten words\n" );  
   fclose( stream );  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
Wrote ten words  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_getw](../../c-runtime-library/reference/getw.md)
