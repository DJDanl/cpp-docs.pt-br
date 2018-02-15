---
title: perror, _wperror | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _wperror
- perror
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _wperror
- _tperror
- perror
dev_langs:
- C++
helpviewer_keywords:
- _tperror function
- tperror function
- wperror function
- error messages, printing
- printing error messages
- _wperror function
- perror function
ms.assetid: 34fce792-16fd-4673-9849-cd88b54b6cd5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3929d35ac258823a70bf063f2e90e3ce8f1dfb4a
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="perror-wperror"></a>perror, _wperror
Imprima uma mensagem de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void perror(  
   const char *string   
);  
void _wperror(  
   const wchar_t *string   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string`  
 Mensagem de cadeia de caracteres para imprimir.  
  
## <a name="remarks"></a>Comentários  
 A função `perror` imprime uma mensagem de erro para `stderr`. `_wperror` é uma versão de caractere largo da função **_perror**; o argumento `string` para `_wperror` é uma cadeia de caracteres largos. Caso contrário, `_wperror` e **_perror** se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tperror`|`perror`|`perror`|`_wperror`|  
  
 `string` é impresso primeiro, seguido por dois-pontos e pela mensagem de erro do sistema para a última chamada de biblioteca que gerou o erro e, finalmente, por um caractere de nova linha. Se `string` for um ponteiro nulo ou um ponteiro para uma cadeia de caracteres nula, `perror` imprimirá somente a mensagem de erro do sistema.  
  
 O número do erro real é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) (definida em ERRNO.H). As mensagens de erro do sistema são acessadas por meio da variável [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que é uma matriz de mensagens ordenadas por número do erro. `perror` imprime a mensagem de erro apropriada usando o valor `errno` como um índice para `_sys_errlist`. O valor da variável [_sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como o número máximo de elementos na matriz `_sys_errlist`.  
  
 Para obter resultados precisos, chame `perror` imediatamente após uma rotina da biblioteca retornar um erro. Caso contrário, chamadas subsequentes podem substituir o valor `errno`.  
  
 No sistema operacional Windows, alguns valores `errno` listados no ERRNO.H não são usados. Esses valores são reservados para uso pelo sistema operacional UNIX. Consulte [_doserrno, errno, _sys_errlist, and _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter uma lista de valores `errno` usados pelo sistema operacional Windows. `perror` imprime uma cadeia de caracteres vazia para qualquer valor `errno` não usado por essas plataformas.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`perror`|\<stdio.h> ou \<stdlib.h>|  
|`_wperror`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_perror.c  
// compile with: /W3  
/* This program attempts to open a file named  
 * NOSUCHF.ILE. Because this file probably doesn't exist,  
 * an error message is displayed. The same message is  
 * created using perror, strerror, and _strerror.  
 */  
  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <io.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <share.h>  
  
int main( void )  
{  
   int  fh;  
  
   if( _sopen_s( &fh, "NOSUCHF.ILE", _O_RDONLY, _SH_DENYNO, 0 ) != 0 )  
   {  
      /* Three ways to create error message: */  
      perror( "perror says open failed" );  
      printf( "strerror says open failed: %s\n",  
         strerror( errno ) ); // C4996  
      printf( _strerror( "_strerror says open failed" ) ); // C4996  
      // Note: strerror and _strerror are deprecated; consider  
      // using strerror_s and _strerror_s instead.  
   }  
   else  
   {  
      printf( "open succeeded on input file\n" );  
      _close( fh );  
   }  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
perror says open failed: No such file or directory  
strerror says open failed: No such file or directory  
_strerror says open failed: No such file or directory  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [clearerr](../../c-runtime-library/reference/clearerr.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [strerror, _strerror, _wcserror, \__wcserror](../../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md)