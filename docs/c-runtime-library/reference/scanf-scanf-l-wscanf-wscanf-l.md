---
title: scanf, _scanf_l, wscanf, _wscanf_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wscanf_l
- scanf
- _scanf_l
- wscanf
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
- _tscanf
- _scanf_l
- wscanf
- _wscanf_l
- scanf
- _tscanf_l
dev_langs:
- C++
helpviewer_keywords:
- tscanf_l function
- _tscanf_l function
- reading data [C++], from input streams
- _tscanf function
- data [C++], reading from input stream
- scanf_l function
- scanf function
- wscanf function
- _scanf_l function
- tscanf function
- formatted data [C++], from input streams
- wscanf_l function
- _wscanf_l function
ms.assetid: 73eac607-117f-4be4-9ff0-4afd9cf3c848
caps.latest.revision: 25
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
ms.openlocfilehash: 3cfa70aa63c32abbc24254e896cdb02412f65fde
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="scanf-scanfl-wscanf-wscanfl"></a>scanf, _scanf_l, wscanf, _wscanf_l
Lê dados formatados do fluxo de entrada padrão. Versões mais seguras dessas funções estão disponíveis; consulte [scanf_s, scanf_s_l, wscanf_s, wscanf_s_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int scanf(  
   const char *format [,  
   argument]...   
);  
int _scanf_l(  
   const char *format,  
   locale_t locale [,  
   argument]...   
);  
int wscanf(  
   const wchar_t *format [,  
   argument]...   
);  
int _wscanf_l(  
   const wchar_t *format,  
   locale_t locale [,  
   argument]...   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído.  
  
 Se `format` for um ponteiro `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `scanf` lê dados do fluxo de entrada padrão `stdin` e grava os dados no local fornecido por `argument`. Cada `argument` deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Ao ler uma cadeia de caracteres com `scanf`, especifique sempre uma largura para o formato `%s` (por exemplo, `"%32s"` em vez de `"%s"`); caso contrário, entrada formatada de modo inadequado poderá facilmente causar um estouro de buffer. Como alternativa, considere o uso de [scanf_s, scanf_s_l, wscanf_s, wscanf_s_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md) ou [fgets](../../c-runtime-library/reference/fgets-fgetws.md).  
  
 A função `wscanf` é uma versão de caractere largo da função `scanf`; o argumento `format` para `wscanf` é uma cadeia de caracteres larga. `wscanf` e `scanf` terão comportamento idêntico se o fluxo for aberto no modo ANSI. Atualmente, `scanf` não dá suporte à entrada de um fluxo UNICODE.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, com a exceção de usarem o parâmetro de localidade passado, em vez da localidade do thread atual.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tscanf`|`scanf`|`scanf`|`wscanf`|  
|`_tscanf_l`|`_scanf_l`|`_scanf_l`|`_wscanf_l`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato – funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`scanf`, `_scanf_l`|\<stdio.h>|  
|`wscanf`, `_wscanf_l`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_scanf.c  
// compile with: /W3  
 /* This program uses the scanf and wscanf functions  
  * to read formatted input.  
  */  
  
#include <stdio.h>  
  
int main( void )  
{  
   int   i, result;  
   float fp;  
   char  c, s[81];  
   wchar_t wc, ws[81];  
   result = scanf( "%d %f %c %C %80s %80S", &i, &fp, &c, &wc, s, ws ); // C4996  
   // Note: scanf and wscanf are deprecated; consider using scanf_s and wscanf_s  
   printf( "The number of fields input is %d\n", result );  
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);  
   result = wscanf( L"%d %f %hc %lc %80S %80ls", &i, &fp, &c, &wc, s, ws ); // C4996  
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
