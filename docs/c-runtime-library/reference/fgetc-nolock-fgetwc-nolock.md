---
title: _fgetc_nolock, _fgetwc_nolock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _fgetc_nolock
- _fgetwc_nolock
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
- _fgetwc_nolock
- fgettc_nolock
- fgetwc_nolock
- _fgetc_nolock
- _fgettc_nolock
- fgetc_nolock
dev_langs:
- C++
helpviewer_keywords:
- fgetc_nolock function
- fgetwc_nolock function
- _fgetwc_nolock function
- characters, reading
- _fgetc_nolock function
- streams, reading characters from
- fgettc_nolock function
- reading characters from streams
- _fgettc_nolock function
ms.assetid: fb8e7c5b-4503-493a-879e-6a1db75aa114
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 475693126cbc33b16710bf260d342c5c5f079540
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fgetcnolock-fgetwcnolock"></a>_fgetc_nolock, _fgetwc_nolock
Lê um caractere de um fluxo sem bloquear o thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _fgetc_nolock(   
   FILE *stream   
);  
wint_t _fgetwc_nolock(   
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 Consulte [fgetc, fgetwc](../../c-runtime-library/reference/fgetc-fgetwc.md).  
  
## <a name="remarks"></a>Comentários  
 `_fgetc_nolock` e `_fgetwc_nolock` são idênticas a `fgetc` e `fgetwc`, respectivamente, exceto pelo fato de não serem protegidas contra interferência de outros threads. Elas podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_fgettc_nolock`|`_fgetc_nolock`|`_fgetc_nolock`|`_fgetwc_nolock`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fgetc_nolock`|\<stdio.h>|  
|`_fgetwc_nolock`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fgetc_nolock.c  
// This program uses getc to read the first  
// 80 input characters (or until the end of input)  
// and place them into a string named buffer.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   FILE *stream;  
   char buffer[81];  
   int  i, ch;  
  
   // Open file to read line from:   
   if( fopen_s( &stream, "crt_fgetc_nolock.txt", "r" ) != 0 )  
      exit( 0 );  
  
   // Read in first 80 characters and place them in "buffer":  
   ch = fgetc( stream );  
   for( i=0; (i < 80 ) && ( feof( stream ) == 0 ); i++ )  
   {  
      buffer[i] = (char)ch;  
      ch = _fgetc_nolock( stream );  
   }  
  
   // Add null to end string   
   buffer[i] = '\0';  
   printf( "%s\n", buffer );  
   fclose( stream );  
}  
```  
  
## <a name="input-crtfgetcnolocktxt"></a>Entrada: crt_fgetc_nolock.txt  
  
```  
Line one.  
Line two.  
```  
  
### <a name="output"></a>Saída  
  
```  
Line one.  
Line two.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)