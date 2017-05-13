---
title: strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wcstok_s_l
- _mbstok_s_l
- _mbstok_s
- strtok_s
- wcstok_s
- _strtok_s_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tcstok_s_l
- _wcstok_s_l
- _tcstok_s
- _mbstok_s_l
- strtok_s
- wcstok_s
- _mbstok_s
- _strtok_s_l
dev_langs:
- C++
helpviewer_keywords:
- _strtok_s_l function
- _mbstok_s_l function
- strings [C++], searching
- mbstok_s_l function
- wcstok_s_l function
- _wcstok_s_l function
- _tcstok_s function
- _tcstok_s_l function
- strtok_s_l function
- wcstok_s function
- tokens, finding in strings
- mbstok_s function
- _mbstok_s function
- strtok_s function
ms.assetid: 7696c972-f83b-4617-8c82-95973e9fdb46
caps.latest.revision: 28
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 4313f785ba5197c3659e74384b7d6ecda8e8c7be
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="strtoks-strtoksl-wcstoks-wcstoksl-mbstoks-mbstoksl"></a>strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l
Localiza o próximo token em uma cadeia de caracteres, usando a localidade atual ou uma localidade específica que é informada. Essas versões de [strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](../../c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  `_mbstok_s` e `_mbstok_s_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      char *strtok_s(  
char *strToken,  
const char *strDelimit,  
   char **context  
);  
char *_strtok_s_l(  
char *strToken,  
const char *strDelimit,  
   char **context,  
_locale_tlocale  
);  
wchar_t *wcstok_s(  
wchar_t *strToken,  
const wchar_t *strDelimit,   
   wchar_t**context  
);  
wchar_t *_wcstok_s_l(  
wchar_t *strToken,  
const wchar_t *strDelimit,   
   wchar_t**context,  
_locale_tlocale  
);  
unsigned char *_mbstok_s(  
unsigned char*strToken,  
const unsigned char *strDelimit,   
   char **context  
);  
unsigned char *_mbstok_s(  
unsigned char*strToken,  
const unsigned char *strDelimit,   
   char **context,  
_locale_tlocale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `strToken`  
 Cadeia de caracteres que contém o token ou os tokens.  
  
 `strDelimit`  
 Conjunto de caracteres delimitadores.  
  
 `context`  
 Usado para armazenar informações de posição entre as chamadas para `strtok_s`  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o próximo token encontrado em `strToken`. Retornam `NULL` quando tokens não são mais encontrados. Cada chamada modifica `strToken` substituindo um caractere `NULL` para o primeiro delimitador que ocorre após o token retornado.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`strToken`|`strDelimit`|`context`|Valor retornado|`errno`|  
|----------------|------------------|---------------|------------------|-------------|  
|`NULL`|qualquer|ponteiro para um ponteiro nulo|`NULL`|`EINVAL`|  
|qualquer|`NULL`|qualquer|`NULL`|`EINVAL`|  
|qualquer|qualquer|`NULL`|`NULL`|`EINVAL`|  
  
 Se `strToken` é `NULL`, mas contexto é um ponteiro para um ponteiro de contexto válido, não há nenhum erro.  
  
## <a name="remarks"></a>Comentários  
 A função `strtok_s` localiza o próximo token em `strToken`. O conjunto de caracteres em `strDelimit` especifica possíveis delimitadores de token a serem encontrados em `strToken` na chamada atual. `wcstok_s` e `_mbstok_s` são versões de caracteres largos e de caracteres multibyte de `strtok_s`. Os argumentos e os valores de retorno de `wcstok_s` e `_wcstok_s_l` são cadeias de caracteres largos; desses de `_mbstok_s` e `_mbstok_s_l` são cadeias de caracteres multibyte. Caso contrário, essas três funções se comportam de forma idêntica.  
  
 Essa função valida seus parâmetros. Se ocorrer uma condição de erro, como na tabela de Condições de Erro, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `NULL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcstok_s`|`strtok_s`|`_mbstok_s`|`wcstok_s`|  
|`_tcstok_s_l`|`_strtok_s_l`|`_mbstok_s_l`|`_wcstok_s_l`|  
  
 Na primeira chamada para `strtok_s`, a função ignora delimitadores à esquerda e retorna um ponteiro para o primeiro token no `strToken`, encerrando o token com um caractere nulo. Mais tokens podem ser divididos, fora o restante do `strToken` por uma série de chamadas para `strtok_s`. Cada chamada para `strtok_s` modifica `strToken` inserindo um caractere nulo após o token retornado pela chamada. O `context` ponteiro mantém controle de cadeia de caracteres que está sendo lido e no qual o próximo token na cadeia de caracteres deve ser lido. Para ler o próximo token de `strToken`, chame `strtok_s` com um valor `NULL` para o `strToken` argumento e passe o mesmo parâmetro `context`. O argumento `NULL` `strToken` faz com que o `strtok_s` pesquise o próximo token no `strToken` modificado. O argumento `strDelimit` pode assumir qualquer valor de uma chamada para o próximo, para que o conjunto de delimitadores possa variar.  
  
 Como o `context` parâmetro substitui os buffers estáticos usados em `strtok` e `_strtok_l`, é possível analisar as duas cadeias de caracteres simultaneamente no mesmo thread.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`strtok_s`|\<string.h>|  
|`_strtok_s_l`|\<string.h>|  
|`wcstok_s`,<br /><br /> `_wcstok_s_l`|\<string.h> ou \<wchar.h>|  
|`_mbstok_s`,<br /><br /> `_mbstok_s_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_strtok_s.c  
// In this program, a loop uses strtok_s  
// to print all the tokens (separated by commas  
// or blanks) in two strings at the same time.  
//  
  
#include <string.h>  
#include <stdio.h>  
  
char string1[] =  
    "A string\tof ,,tokens\nand some  more tokens";  
char string2[] =  
    "Another string\n\tparsed at the same time.";  
char seps[]   = " ,\t\n";  
char *token1 = NULL;  
char *token2 = NULL;  
char *next_token1 = NULL;  
char *next_token2 = NULL;  
  
int main( void )  
{  
    printf( "Tokens:\n" );  
  
    // Establish string and get the first token:  
    token1 = strtok_s( string1, seps, &next_token1);  
    token2 = strtok_s ( string2, seps, &next_token2);  
  
    // While there are tokens in "string1" or "string2"  
    while ((token1 != NULL) || (token2 != NULL))  
    {  
        // Get next token:  
        if (token1 != NULL)  
        {  
            printf( " %s\n", token1 );  
            token1 = strtok_s( NULL, seps, &next_token1);  
        }  
        if (token2 != NULL)  
        {  
            printf("        %s\n", token2 );  
            token2 = strtok_s (NULL, seps, &next_token2);  
        }  
    }  
}  
```  
  
```Output  
Tokens:  
 A  
        Another  
 string  
        string  
 of  
        parsed  
 tokens  
        at  
 and  
        the  
 some  
        same  
 more  
        time.  
 tokens  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcspn, wcscspn, _mbscspn, _mbscspn_l](../../c-runtime-library/reference/strcspn-wcscspn-mbscspn-mbscspn-l.md)   
 [strspn, wcsspn, _mbsspn, _mbsspn_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)
