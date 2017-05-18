---
title: fprintf, _fprintf_l, fwprintf, _fwprintf_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fwprintf
- fprintf
- _fprintf_l
- _fwprintf_l
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
apitype: DLLExport
f1_keywords:
- fprintf
- fwprintf
- _ftprintf
dev_langs:
- C++
helpviewer_keywords:
- _fwprintf_l function
- fprintf function
- fprintf_l function
- _fprintf_l function
- _ftprintf function
- fwprintf function
- ftprintf_l function
- ftprintf function
- _ftprintf_l function
- print formatted data to streams
- fwprintf_l function
ms.assetid: 34a87e1c-6e4d-4d48-a611-58314dd4dc4b
caps.latest.revision: 24
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: d0f921aa46915220bb92f8ed1834f4c0e28ed57d
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="fprintf-fprintfl-fwprintf-fwprintfl"></a>fprintf, _fprintf_l, fwprintf, _fwprintf_l
Imprimir dados formatados em um fluxo. Versões mais seguras dessas funções estão disponíveis; consulte [fprintf_s, _fprintf_s_l, fwprintf_s, _fwprintf_s_l](../../c-runtime-library/reference/fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fprintf(   
   FILE *stream,  
   const char *format [,  
   argument ]...  
);  
int _fprintf_l(   
   FILE *stream,  
   const char *format,  
   locale_t locale [,  
   argument ]...  
);  
int fwprintf(   
   FILE *stream,  
   const wchar_t *format [,  
   argument ]...  
);  
int _fwprintf_l(   
   FILE *stream,  
   const wchar_t *format,  
   locale_t locale [,  
   argument ]...  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `fprintf` retorna o número de bytes gravados. `fwprintf` retorna o número de caracteres largos gravados. Cada uma dessas funções retorna um valor negativo quando ocorre um erro de saída. Se `stream` ou `format` for `NULL`, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e definirão `errno` como `EINVAL`. A cadeia de caracteres de formato não é verificada quanto a caracteres de formatação válidos da forma que é ao usar `fprintf_s` ou `fwprintf_s`.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.  
  
## <a name="remarks"></a>Comentários  
 `fprintf` formata e imprime uma série de caracteres e valores para a saída `stream`. Cada função `argument` (se houver) é convertida e gerada de acordo com a especificação de formato correspondente em `format`. Para `fprintf`, o argumento `format` tem a mesma sintaxe e uso que tem em `printf`.  
  
 `fwprintf` é uma versão de caractere largo de `fprintf`; em `fwprintf`, `format` é uma cadeia de caracteres largos. Essas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. Atualmente, `fprintf` não dá suporte à saída em um fluxo UNICODE.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de usarem o parâmetro de localidade passado, em vez da localidade do thread atual.  
  
> [!IMPORTANT]
>  Verifique se `format` não é uma cadeia de caracteres definida pelo usuário.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_ftprintf`|`fprintf`|`fprintf`|`fwprintf`|  
|`_ftprintf_l`|`_fprintf_l`|`_fprintf_l`|`_fwprintf_l`|  
  
 Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fprintf`, `_fprintf_l`|\<stdio.h>|  
|`fwprintf`, `_fwprintf_l`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fprintf.c  
/* This program uses fprintf to format various  
 * data and print it to the file named FPRINTF.OUT. It  
 * then displays FPRINTF.OUT on the screen using the system  
 * function to invoke the operating-system TYPE command.  
 */  
  
#include <stdio.h>  
#include <process.h>  
  
FILE *stream;  
  
int main( void )  
{  
   int    i = 10;  
   double fp = 1.5;  
   char   s[] = "this is a string";  
   char   c = '\n';  
  
   fopen_s( &stream, "fprintf.out", "w" );  
   fprintf( stream, "%s%c", s, c );  
   fprintf( stream, "%d\n", i );  
   fprintf( stream, "%f\n", fp );  
   fclose( stream );  
   system( "type fprintf.out" );  
}  
```  
  
```Output  
this is a string  
10  
1.500000  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_cprintf, _cprintf_l, _cwprintf, _cwprintf_l](../../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)   
 [fscanf, _fscanf_l, fwscanf, _fwscanf_l](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)   
 [sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)
