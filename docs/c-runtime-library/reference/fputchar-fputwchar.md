---
title: _fputchar, _fputwchar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _fputchar
- _fputwchar
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
- fputtchar
- _fputwchar
- fputwchar
- _fputtchar
- fputchar
- _fputchar
dev_langs:
- C++
helpviewer_keywords:
- fputchar function
- standard output, writing to
- _fputtchar function
- fputwchar function
- _fputwchar function
- fputtchar function
- _fputchar function
ms.assetid: b92ff600-a924-4f2b-b0e7-3097ee31bdff
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f4b7e510e978bcffb8b3744f63d5da24ec7afc5a
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fputchar-fputwchar"></a>_fputchar, _fputwchar
Grava um caractere em `stdout`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _fputchar(  
   int c   
);  
wint_t _fputwchar(  
   wchar_t c   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 O caractere a ser gravado.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna o caractere gravado. Para `_fputchar`, um valor retornado de `EOF` indica que há um erro. Para `_fputwchar`, um valor retornado de `WEOF` indica que há um erro. Se c for `NULL`, essas funções gerarão uma exceção de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, retorne `EOF` (ou `WEOF`) e defina `errno` para `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Essas duas funções gravam o `c` de caractere único em `stdout` e avançam o indicador conforme apropriado. `_fputchar` equivale a `fputc( stdout )`. Também é equivalente a `putchar`, mas implementado somente como uma função, em vez de uma função e uma macro. Diferente de `fputc` e `putchar`, essas funções não são compatíveis com o padrão ANSI.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_fputtchar`|`_fputchar`|`_fputchar`|`_fputwchar`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fputchar`|\<stdio.h>|  
|`_fputwchar`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fputchar.c  
// This program uses _fputchar  
// to send a character array to stdout.  
  
#include <stdio.h>  
  
int main( void )  
{  
    char strptr[] = "This is a test of _fputchar!!\n";  
    char *p = NULL;  
  
    // Print line to stream using _fputchar.   
    p = strptr;  
    while( (*p != '\0') && _fputchar( *(p++) ) != EOF )  
      ;  
}  
```  
  
```Output  
This is a test of _fputchar!!  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetc, fgetwc](../../c-runtime-library/reference/fgetc-fgetwc.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)