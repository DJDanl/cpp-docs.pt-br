---
title: clearerr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: clearerr
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
f1_keywords: clearerr
dev_langs: C++
helpviewer_keywords:
- error indicator for streams
- resetting stream error indicator
- clearerr function
ms.assetid: a9711cd4-3335-43d4-a018-87bbac5b3bac
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 35fafbe762780ace0fbd255f905307f7793d4c04
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clearerr"></a>clearerr
Redefine o indicador de erro para um fluxo. Uma versão mais segura dessa função está disponível. Consulte [clearerr_s](../../c-runtime-library/reference/clearerr-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void clearerr(  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="remarks"></a>Comentários  
 A função `clearerr` redefine o indicador de erro e o indicador de final de arquivo como `stream`. Indicadores de erro não são removidos automaticamente; quando o indicador de erro para um fluxo especificado é definido, as operações naquele fluxo continuam a retornar um valor de erro até `clearerr`, `fseek`, `fsetpos` ou `rewind` ser chamado.  
  
 Se `stream` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará. Para obter mais informações sobre `errno` e códigos de erro, consulte [Constantes errno](../../c-runtime-library/errno-constants.md).  
  
 Uma versão mais segura dessa função está disponível. Consulte [clearerr_s](../../c-runtime-library/reference/clearerr-s.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`clearerr`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_clearerr.c  
// This program creates an error  
// on the standard input stream, then clears  
// it so that future reads won't fail.  
  
#include <stdio.h>  
  
int main( void )  
{  
   int c;  
   // Create an error by writing to standard input.  
   putc( 'c', stdin );  
   if( ferror( stdin ) )  
   {  
      perror( "Write error" );  
      clearerr( stdin );  
   }  
  
   // See if read causes an error.  
   printf( "Will input cause an error? " );  
   c = getc( stdin );  
   if( ferror( stdin ) )  
   {  
      perror( "Read error" );  
      clearerr( stdin );  
   }  
   else  
      printf( "No read error\n" );  
}  
```  
  
```Output  
  
n  
  
```  
  
```Output  
  
      nWrite error: No error  
Will input cause an error? n  
No read error  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de erro](../../c-runtime-library/error-handling-crt.md)   
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_eof](../../c-runtime-library/reference/eof.md)   
 [feof](../../c-runtime-library/reference/feof.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [perror, _wperror](../../c-runtime-library/reference/perror-wperror.md)