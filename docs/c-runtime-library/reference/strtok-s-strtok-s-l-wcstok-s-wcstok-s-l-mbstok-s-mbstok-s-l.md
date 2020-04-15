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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 9fe89fb897a5459b16c49060359b4bb40bc062a7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365215"
---
# <a name="strtok_s-_strtok_s_l-wcstok_s-_wcstok_s_l-_mbstok_s-_mbstok_s_l"></a>strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l

Localiza o próximo token em uma cadeia de caracteres, usando a localidade atual ou uma localidade específica que é informada. Essas versões de [strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> **_mbstok_s** e **_mbstok_s_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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
Uma seqüência contendo o token ou tokens para encontrar.

*Delimitadores*<br/>
O conjunto de caracteres delimitadores para usar.

*contexto*<br/>
Usado para armazenar informações de posição entre chamadas para a função.

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o próximo token encontrado em *str*. Retorna **NULO** quando não forem encontrados mais tokens. Cada chamada modifica *str* substituindo um caractere nulo pelo primeiro delimitador que ocorre após o token retornado.

### <a name="error-conditions"></a>Condições de erro

|*Str*|*Delimitadores*|*contexto*|Valor retornado|**errno**|
|----------------|------------------|---------------|------------------|-------------|
|**NULO**|any|ponteiro para um ponteiro nulo|**NULO**|**Einval**|
|any|**NULO**|any|**NULO**|**Einval**|
|any|any|**NULO**|**NULO**|**Einval**|

Se *str* é **NULL,** mas *contexto* é um ponteiro para um ponteiro de contexto válido, não há erro.

## <a name="remarks"></a>Comentários

A **strtok_s** família de funções encontra o próximo token em *str*. O conjunto de caracteres em *delimitadores* especifica possíveis delimitadores do token a ser encontrado em *str* na chamada atual. **wcstok_s** e **_mbstok_s** são versões de amplo caráter e multibytes de **strtok_s**. Os argumentos e os valores de retorno de **wcstok_s** e **_wcstok_s_l** são cadeias de caracteres amplos; os de **_mbstok_s** e **_mbstok_s_l** são cordas de caracteres multibytes. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Quando ocorre uma condição de erro, como na tabela Condições de erro, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam **NULL**.

Na primeira chamada para **strtok_s,** a função pula os principais delimitadores e retorna um ponteiro para o primeiro token em *str,* terminando o token com um caractere nulo. Mais tokens podem ser quebrados do restante do *str* por uma série de chamadas para **strtok_s**. Cada chamada para **strtok_s** modifica *o str* inserindo um caractere nulo após o token retornar por essa chamada. O ponteiro do *contexto* mantém a trilha de qual string está sendo lida e onde na seqüência o próximo token deve ser lido. Para ler o próximo token do *str,* chame **strtok_s** com um valor **NULL** para o argumento *str* e passe o mesmo parâmetro de *contexto.* O **argumento NULL** *str* faz com **que strtok_s** procurem o próximo token no *str*modificado . O argumento *de delimitadores* pode levar qualquer valor de uma chamada para a próxima, de modo que o conjunto de delimitadores possa variar.

Uma vez que o parâmetro de *contexto* substitui os buffers estáticos usados em **strtok** e **_strtok_l,** é possível analisar duas cordas simultaneamente no mesmo segmento.

O valor de saída é afetado pela configuração da configuração da categoria **LC_CTYPE** do local. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md).

As versões dessas funções sem o **sufixo _l** usam a localização atual do segmento para este comportamento dependente da localidade. As versões com o **sufixo _l** são idênticas, exceto que, em vez disso, usam o local especificado pelo parâmetro *local.* Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtok_s**|\<string.h>|
|**_strtok_s_l**|\<string.h>|
|**wcstok_s**<br />**_wcstok_s_l**|\<string.h> ou \<wchar.h>|
|**_mbstok_s**<br />**_mbstok_s_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|\_UNICODE \_& MBCS não definido|\_MBCS definido|_UNICODE definido|
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

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[strcspn, wcscspn, _mbscspn, _mbscspn_l](strcspn-wcscspn-mbscspn-mbscspn-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
