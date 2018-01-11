---
title: scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- wscanf_s
- _wscanf_s_l
- scanf_s
- _scanf_s_l
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
- wscanf_s
- _tscanf_s_l
- _wscanf_s_l
- scanf_s
- _tscanf_s
- _scanf_s_l
dev_langs: C++
helpviewer_keywords:
- reading data [C++], from input streams
- buffers [C++], buffer overruns
- _scanf_s_l function
- _wscanf_s_l function
- tscanf_s_l function
- tscanf_s function
- scanf_s function
- data [C++], reading from input stream
- wscanf_s function
- _tscanf_s_l function
- _tscanf_s function
- scanf_s_l function
- formatted data [C++], from input streams
- wscanf_s_l function
- buffers [C++], avoiding overruns
ms.assetid: 42cafcf7-52d6-404a-80e4-b056a7faf2e5
caps.latest.revision: "33"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 721946d36158abccfc07a4aba262a34dd1f63d20
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="scanfs-scanfsl-wscanfs-wscanfsl"></a>scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l
Lê dados formatados do fluxo de entrada padrão. Essas versões de [scanf, _scanf_l, wscanf, _wscanf_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int scanf_s(  
   const char *format [,  
   argument]...   
);  
int _scanf_s_l(  
   const char *format,  
   locale_t locale [,  
   argument]...   
);  
int wscanf_s(  
   const wchar_t *format [,  
   argument]...   
);  
int _wscanf_s_l(  
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
 Retorna o número de campos convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. O valor retornado será `EOF` para um erro ou se o caractere de final de arquivo ou o caractere de fim de cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se `format` for um ponteiro `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `scanf_s` e `wscanf_s` retornarão `EOF` e definirão `errno` como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `scanf_s` lê dados do fluxo de entrada padrão `stdin` e grava os dados no local fornecido por `argument`. Cada `argument` deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 A função `wscanf_s` é uma versão de caractere largo da função `scanf_s`; o argumento `format` para `wscanf_s` é uma cadeia de caracteres larga. `wscanf_s` e `scanf_s` terão comportamento idêntico se o fluxo for aberto no modo ANSI. Atualmente, `scanf_s` não dá suporte à entrada de um fluxo UNICODE.  
  
 As versões dessas funções que têm o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade que é informado em vez da localidade do thread atual.  
  
 Ao contrário de `scanf` e `wscanf`, `scanf_s` e `wscanf_s` exigem que o tamanho do buffer seja especificado para todos os parâmetros de entrada do tipo `c`, `C`, `s`, `S` ou conjuntos de controles de cadeia de caracteres que são incluídos em `[]`. O tamanho do buffer em caracteres é passado como um parâmetro adicional imediatamente após o ponteiro para o buffer ou variável. Por exemplo, se você estiver lendo uma cadeia de caracteres, o tamanho do buffer para essa cadeia de caracteres será passado conforme demonstrado a seguir:  
  
 `char s[10];`  
  
 `scanf_s("%9s", s, (unsigned)_countof(s)); // buffer size is 10, width specification is 9`  
  
 O tamanho do buffer inclui o nulo de terminação. Você pode usar um campo de especificação de largura para garantir que o token lido caiba no buffer. Se nenhum campo de especificação de largura for usado e o token lido for muito grande para caber no buffer, nada será gravado no buffer.  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, não `size_t`. Use uma conversão estática para converter um valor `size_t` em `unsigned` para configurações de build de 64 bits.  
  
 O exemplo a seguir mostra que o parâmetro de tamanho do buffer descreve o número máximo de caracteres, não de bytes. Na chamada para `wscanf_s`, a largura de caractere indicada pelo tipo de buffer não corresponde à largura de caractere indicada pelo especificador de formato.  
  
```  
wchar_t ws[10];  
wscanf_s(L"%9S", ws, (unsigned)_countof(ws));  
```  
  
 O especificador de formato `S` indica o uso da largura de caractere que é "oposta" à largura padrão que tem suporte pela função. A largura do caractere é de um byte, mas a função dá suporte a caracteres de dois bytes. Este exemplo lê uma cadeia de caracteres de até 9 caracteres com um byte de largura e coloca-os em um buffer de caracteres com dois bytes de largura. Os caracteres são tratados como valores de byte único; os dois primeiros caracteres são armazenados em `ws[0]`, os próximos dois são armazenados em `ws[1]` e assim por diante.  
  
 No caso de caracteres, um único caractere pode ser lido como demonstrado a seguir:  
  
 `char c;`  
  
 `scanf_s("%c", &c, 1);`  
  
 Quando vários caracteres para cadeias de caracteres terminadas em não nulo são lidos, inteiros são usados como a especificação de largura e o tamanho do buffer.  
  
 `char c[4];`  
  
 `scanf_s("%4c", &c, (unsigned)_countof(c)); // not null terminated`  
  
 Para obter mais informações, consulte [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tscanf_s`|`scanf_s`|`scanf_s`|`wscanf_s`|  
|`_tscanf_s_l`|`_scanf_s_l`|`_scanf_s_l`|`_wscanf_s_l`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`scanf_s`, `_scanf_s_l`|\<stdio.h>|  
|`wscanf_s`, `_wscanf_s_l`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_scanf_s.c  
// This program uses the scanf_s and wscanf_s functions  
// to read formatted input.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int      i,  
            result;  
   float    fp;  
   char     c,  
            s[80];  
   wchar_t  wc,  
            ws[80];  
  
   result = scanf_s( "%d %f %c %C %s %S", &i, &fp, &c, 1,  
                     &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws) );  
   printf( "The number of fields input is %d\n", result );  
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c,  
           wc, s, ws);  
   result = wscanf_s( L"%d %f %hc %lc %S %ls", &i, &fp, &c, 2,  
                      &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws) );  
   wprintf( L"The number of fields input is %d\n", result );  
   wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp,  
            c, wc, s, ws);  
}  
```  
  
 Este programa produz a seguinte saída quando recebe essa entrada:  
  
 `71 98.6 h z Byte characters`  
  
 `36 92.3 y n Wide characters`  
  
```Output  
The number of fields input is 6  
The contents are: 71 98.599998 h z Byte characters  
The number of fields input is 6  
The contents are: 36 92.300003 y n Wide characters  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [fscanf, _fscanf_l, fwscanf, _fwscanf_l](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)   
 [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [sscanf, _sscanf_l, swscanf, _swscanf_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)