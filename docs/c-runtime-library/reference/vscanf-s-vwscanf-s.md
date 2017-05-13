---
title: vscanf_s, vwscanf_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- vscanf_s
- vwscanf_s
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
- _vtscanf_s
- vscanf_s
- vwscanf_s
dev_langs:
- C++
ms.assetid: 23a1c383-5b01-4887-93ce-534a1e38ed93
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
ms.openlocfilehash: e403758253afd8778f9b9c2d96f56773cf0eb44a
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="vscanfs-vwscanfs"></a>vscanf_s, vwscanf_s
Lê dados formatados do fluxo de entrada padrão. Essas versões de [vscanf, vwscanf](../../c-runtime-library/reference/vscanf-vwscanf.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int vscanf_s(  
   const char *format,  
   va_list arglist  
);   
int vwscanf_s(  
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
 Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor retornado será `EOF` para um erro ou se o caractere de final de arquivo ou o caractere de fim de cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se `format` for um ponteiro `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `vscanf_s` e `vwscanf_s` retornarão `EOF` e definirão `errno` como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `vscanf_s` lê dados do fluxo de entrada padrão `stdin` e grava os dados nos locais que são fornecidos pela lista de argumentos `arglist`. Cada argumento na lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 A função `vwscanf_s` é uma versão de caractere largo da função `vscanf_s`; o argumento `format` para `vwscanf_s` é uma cadeia de caracteres larga. `vwscanf_s` e `vscanf_s` terão comportamento idêntico se o fluxo for aberto no modo ANSI. `vscanf_s` não dá suporte à entrada de um fluxo UNICODE.  
  
 Ao contrário de `vscanf` e `vwscanf`, `vscanf_s` e `vwscanf_s` exigem que o tamanho do buffer seja especificado para todos os parâmetros de entrada do tipo `c`, `C`, `s`, `S` ou conjuntos de controles de cadeia de caracteres que são incluídos em `[]`. O tamanho do buffer em caracteres é passado como um parâmetro adicional imediatamente após o ponteiro para o buffer ou variável. O tamanho do buffer em caracteres para uma cadeia de caracteres `wchar_t` não é o mesmo que o tamanho em bytes.  
  
 O tamanho do buffer inclui o nulo de terminação. Você pode usar um campo de especificação de largura para garantir que o token lido caiba no buffer. Se nenhum campo de especificação de largura for usado e o token lido for muito grande para caber no buffer, nada será gravado no buffer.  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, não `size_t`.  
  
 Para obter mais informações, consulte [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_vtscanf_s`|`vscanf_s`|`vscanf_s`|`vwscanf_s`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`vscanf_s`|\<stdio.h>|  
|`wscanf_s`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_vscanf_s.c  
// compile with: /W3  
// This program uses the vscanf_s and vwscanf_s functions  
// to read formatted input.  
  
#include <stdio.h>  
#include <stdarg.h>  
#include <stdlib.h>  
  
int call_vscanf_s(char *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vscanf_s(format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int call_vwscanf_s(wchar_t *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vwscanf_s(format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int main( void )  
{  
    int   i, result;  
    float fp;  
    char  c, s[81];  
    wchar_t wc, ws[81];  
    result = call_vscanf_s("%d %f %c %C %s %S", &i, &fp, &c, 1,  
                           &wc, 1, s, _countof(s), ws, _countof(ws) );  
    printf( "The number of fields input is %d\n", result );  
    printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);  
    result = call_vwscanf_s(L"%d %f %hc %lc %S %ls", &i, &fp, &c, 2,  
                            &wc, 1, s, _countof(s), ws, _countof(ws) );  
    wprintf( L"The number of fields input is %d\n", result );  
    wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);  
}  
  
```  
  
 Quando esse programa recebe a entrada no exemplo, ele produz esta saída:  
  
 `71 98.6 h z Byte characters`  
  
 `36 92.3 y n Wide characters`  
  
```Output  
The number of fields input is 6  
The contents are: 71 98.599998 h z Byte characters  
The number of fields input is 6  
The contents are: 36 92.300003 y n Wide characters  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, _scanf_l, wscanf, _wscanf_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)   
 [vscanf, vwscanf](../../c-runtime-library/reference/vscanf-vwscanf.md)
