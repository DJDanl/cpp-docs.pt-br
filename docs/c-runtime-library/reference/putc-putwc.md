---
title: putc, putwc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- putwc
- putc
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
- _puttc
- putwc
- putc
dev_langs:
- C++
helpviewer_keywords:
- streams, writing characters to
- characters, writing
- putwc function
- putc function
- _puttc function
- puttc function
ms.assetid: a37b2e82-9d88-4565-8190-ff8d04c0ddb9
caps.latest.revision: 16
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 62cc6bbb711a36a2907812593383c441202899fd
ms.lasthandoff: 02/25/2017

---
# <a name="putc-putwc"></a>putc, putwc
Grava um caractere em um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int putc(  
   int c,  
   FILE *stream   
);  
wint_t putwc(  
   wchar_t c,  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 O caractere a ser gravado.  
  
 `stream`  
 Ponteiro para a estrutura **FILE**.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o caractere gravado. Para indicar um erro ou uma condição de fim de arquivo, `putc` e `putchar` retornam `EOF`; `putwc` e `putwchar` retornam **WEOF**. Para todas as quatro rotinas, use [ferror](../../c-runtime-library/reference/ferror.md) ou [feof](../../c-runtime-library/reference/feof.md) para verificar se há um erro ou o fim do arquivo. Se um ponteiro nulo for passado para `stream`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EOF` ou **WEOF** e definirão `errno` como `EINVAL`.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.  
  
## <a name="remarks"></a>Comentários  
 A rotina `putc` grava o único caractere `c` para a saída `stream` na posição atual. Qualquer inteiro pode ser passado para `putc`, mas somente os 8 bits inferiores são gravados. A rotina `putchar` é idêntica ao **putc(** `c`**, stdout )**. Para cada rotina, se ocorrer um erro de leitura, o indicador de erro para o fluxo será definido. `putc` e `putchar` são semelhantes a `fputc` e `_fputchar`, respectivamente, mas são implementados como funções e como macros (consulte [Escolhendo entre funções e macros](../../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md)). `putwc` e `putwchar` são as versões de caractere largo de `putc` e `putchar`, respectivamente. `putwc` e `putc` terão comportamento idêntico se o fluxo for aberto no modo ANSI. Atualmente, `putc` não dá suporte para a saída em um fluxo UNICODE.  
  
 As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Para obter mais informações, consulte **_putc_nolock, _putwc_nolock**.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_puttc`|`putc`|`putc`|**putwc**|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`putc`|\<stdio.h>|  
|`putwc`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_putc.c  
/* This program uses putc to write buffer  
 * to a stream. If an error occurs, the program  
 * stops before writing the entire buffer.  
 */  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char *p, buffer[] = "This is the line of output\n";  
   int  ch;  
  
   ch = 0;  
   /* Make standard out the stream and write to it. */  
   stream = stdout;  
   for( p = buffer; (ch != EOF) && (*p != '\0'); p++ )  
      ch = putc( *p, stream );  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
This is the line of output  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
  
-   [System::IO::StreamWriter::Write](https://msdn.microsoft.com/en-us/library/system.io.streamwriter.write.aspx)  
  
-   [System::Console::Write](https://msdn.microsoft.com/en-us/library/system.console.write.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)
