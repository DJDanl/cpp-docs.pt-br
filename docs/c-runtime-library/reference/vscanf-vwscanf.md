---
title: vscanf, vwscanf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- vscanf
- vwscanf
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
- vscanf
- vwscanf
- _vtscanf
dev_langs:
- C++
ms.assetid: d1df595b-11bc-4682-9441-a92616301e3b
caps.latest.revision: 6
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
ms.openlocfilehash: 8f122fc5d04b603fa654d0515287cd0b48f51434
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="vscanf-vwscanf"></a>vscanf, vwscanf
Lê dados formatados do fluxo de entrada padrão. Estão disponíveis versões mais seguras dessas funções; consulte [vscanf_s, vwscanf_s](../../c-runtime-library/reference/vscanf-s-vwscanf-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int vscanf(  
   const char *format,  
   va_list arglist  
);  
int vwscanf(  
   const wchar_t *format,  
   va_list arglist  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `arglist`  
 Lista de argumentos variáveis.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o número de campos que são convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído.  
  
 Se `format` for um ponteiro `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `vscanf` lê dados do fluxo de entrada padrão `stdin` e grava os dados nos locais que são fornecidos pela lista de argumentos `arglist`. Cada argumento na lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Quando você usa `vscanf` para ler uma cadeia de caracteres, especifique sempre uma largura para o formato `%s` (por exemplo, `"%32s"` em vez de `"%s"`); caso contrário, entrada formatada incorretamente poderá causar um estouro de buffer. Como alternativa, você pode usar [vscanf_s, vwscanf_s](../../c-runtime-library/reference/vscanf-s-vwscanf-s.md) ou [fgets](../../c-runtime-library/reference/fgets-fgetws.md).  
  
 A função `vwscanf` é uma versão de caractere largo da função `vscanf`; o argumento `format` para `vwscanf` é uma cadeia de caracteres larga. `vwscanf` e `vscanf` terão comportamento idêntico se o fluxo for aberto no modo ANSI. `vscanf` não dá suporte à entrada de um fluxo UNICODE.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_vtscanf`|`vscanf`|`vscanf`|`vwscanf`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`vscanf`|\<stdio.h>|  
|`vwscanf`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_vscanf.c  
// compile with: /W3  
// This program uses the vscanf and vwscanf functions  
// to read formatted input.  
  
#include <stdio.h>  
#include <stdarg.h>  
  
int call_vscanf(char *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vscanf(format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int call_vwscanf(wchar_t *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vwscanf(format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int main( void )  
{  
    int   i, result;  
    float fp;  
    char  c, s[81];  
    wchar_t wc, ws[81];  
    result = call_vscanf( "%d %f %c %C %80s %80S", &i, &fp, &c, &wc, s, ws );  
    printf( "The number of fields input is %d\n", result );  
    printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);  
    result = call_vwscanf( L"%d %f %hc %lc %80S %80ls", &i, &fp, &c, &wc, s, ws );  
    wprintf( L"The number of fields input is %d\n", result );  
    wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);  
}  
  
```  
  
```Output  
  
      71 98.6 h z Byte characters  
36 92.3 y n Wide charactersThe number of fields input is 6  
The contents are: 71 98.599998 h z Byte characters  
The number of fields input is 6  
The contents are: 36 92.300003 y n Wide characters  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [fscanf, _fscanf_l, fwscanf, _fwscanf_l](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)   
 [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [sscanf, _sscanf_l, swscanf, _swscanf_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [vscanf_s, vwscanf_s](../../c-runtime-library/reference/vscanf-s-vwscanf-s.md)
