---
title: strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l
ms.date: 4/2/2020
api_name:
- _wcstok_s_l
- _mbstok_s_l
- _mbstok_s
- strtok_s
- wcstok_s
- _strtok_s_l
- _o__mbstok_s
- _o__mbstok_s_l
- _o_strtok_s
- _o_wcstok_s
api_location:
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _tcstok_s_l
- _wcstok_s_l
- _tcstok_s
- _mbstok_s_l
- strtok_s
- wcstok_s
- _mbstok_s
- _strtok_s_l
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
ms.openlocfilehash: 52c998f14fee080efc1d288abbba012752757632
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82912674"
---
# <a name="strtok_s-_strtok_s_l-wcstok_s-_wcstok_s_l-_mbstok_s-_mbstok_s_l"></a>strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l

Localiza o próximo token em uma cadeia de caracteres, usando a localidade atual ou uma localidade específica que é informada. Essas versões de [strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> **_mbstok_s** e **_mbstok_s_l** não podem ser usados em aplicativos que são executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
char* strtok_s(
   char* str,
   const char* delimiters,
   char** context
);

char* _strtok_s_l(
   char* str,
   const char* delimiters,
   char** context,
   _locale_t locale
);

wchar_t* wcstok_s(
   wchar_t* str,
   const wchar_t* delimiters,
   wchar_t** context
);

wchar_t *_wcstok_s_l(
   wchar_t* str,
   const wchar_t* delimiters,
   wchar_t** context,
   _locale_t locale
);

unsigned char* _mbstok_s(
   unsigned char* str,
   const unsigned char* delimiters,
   char** context
);

unsigned char* _mbstok_s_l(
   unsigned char* str,
   const unsigned char* delimiters,
   char** context,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Uma cadeia de caracteres que contém o token ou tokens a serem localizados.

*delimitadores*<br/>
O conjunto de caracteres delimitadores a ser usado.

*contexto*<br/>
Usado para armazenar informações de posição entre chamadas para a função.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o próximo token encontrado em *Str*. Retorna **NULL** quando não são encontrados mais tokens. Cada chamada modifica *Str* substituindo um caractere nulo para o primeiro delimitador que ocorre após o token retornado.

### <a name="error-conditions"></a>Condições de erro

|*Str*|*delimitadores*|*contexto*|Valor retornado|**errno**|
|----------------|------------------|---------------|------------------|-------------|
|**NULO**|any|ponteiro para um ponteiro nulo|**NULO**|**EINVAL**|
|any|**NULO**|any|**NULO**|**EINVAL**|
|any|any|**NULO**|**NULO**|**EINVAL**|

Se *Str* for **NULL** , mas *Context* for um ponteiro para um ponteiro de contexto válido, não haverá erro.

## <a name="remarks"></a>Comentários

A família de funções **strtok_s** localiza o próximo token em *Str*. O conjunto de caracteres nos *delimitadores* especifica os delimitadores possíveis do token a serem encontrados em *Str* na chamada atual. **wcstok_s** e **_mbstok_s** são versões de caractere largo e de vários caracteres de **strtok_s**. Os argumentos e valores de retorno de **wcstok_s** e **_wcstok_s_l** são cadeias de caracteres largos; os de **_mbstok_s** e **_mbstok_s_l** são cadeias de caracteres multibyte. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Quando ocorre uma condição de erro, como na tabela condições de erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** como **EINVAL** e retornarão **NULL**.

Na primeira chamada para **strtok_s**, a função ignora os delimitadores à esquerda e retorna um ponteiro para o primeiro token em *Str*, encerrando o token com um caractere nulo. Mais tokens podem ser divididos do restante do *Str* por uma série de chamadas para **strtok_s**. Cada chamada para **strtok_s** modifica *Str* inserindo um caractere nulo após o token retornado por essa chamada. O ponteiro de *contexto* mantém o controle de qual cadeia de caracteres está sendo lida e onde na cadeia de caracteres o próximo token será lido. Para ler o próximo token de *Str*, chame **strtok_s** com um valor **nulo** para o argumento *Str* e passe o mesmo parâmetro de *contexto* . O argumento *Str* **nulo** faz **strtok_s** Pesquisar o próximo token na *sequência*modificada. O argumento *delimitadores* pode usar qualquer valor de uma chamada para a próxima, de modo que o conjunto de delimitadores possa variar.

Como o parâmetro de *contexto* substitui os buffers estáticos usados em **strtok** e **_strtok_l**, é possível analisar duas cadeias de caracteres simultaneamente no mesmo thread.

O valor de saída é afetado pela configuração da configuração de categoria de **LC_CTYPE** da localidade. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md).

As versões dessas funções sem o sufixo **_L** usam a localidade do thread atual para esse comportamento dependente de localidade. As versões com o sufixo **_L** são idênticas, exceto pelo fato de usarem a localidade especificada pelo parâmetro *locale* . Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtok_s**|\<string.h>|
|**_strtok_s_l**|\<string.h>|
|**wcstok_s**,<br />**_wcstok_s_l**|\<string.h> ou \<wchar.h>|
|**_mbstok_s**,<br />**_mbstok_s_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definição|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstok_s**|**strtok_s**|**_mbstok_s**|**wcstok_s**|
|**_tcstok_s_l**|**_strtok_s_l**|**_mbstok_s_l**|**_wcstok_s_l**|

## <a name="example"></a>Exemplo

```C
// crt_strtok_s.c
// In this program, a loop uses strtok_s
// to print all the tokens (separated by commas
// or blanks) in two strings at the same time.

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

int main(void)
{
    printf("Tokens:\n");

    // Establish string and get the first token:
    token1 = strtok_s(string1, seps, &next_token1);
    token2 = strtok_s(string2, seps, &next_token2);

    // While there are tokens in "string1" or "string2"
    while ((token1 != NULL) || (token2 != NULL))
    {
        // Get next token:
        if (token1 != NULL)
        {
            printf(" %s\n", token1);
            token1 = strtok_s(NULL, seps, &next_token1);
        }
        if (token2 != NULL)
        {
            printf("        %s\n", token2);
            token2 = strtok_s(NULL, seps, &next_token2);
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

## <a name="see-also"></a>Confira também

[Manipulação de cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[strcspn, wcscspn, _mbscspn, _mbscspn_l](strcspn-wcscspn-mbscspn-mbscspn-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
