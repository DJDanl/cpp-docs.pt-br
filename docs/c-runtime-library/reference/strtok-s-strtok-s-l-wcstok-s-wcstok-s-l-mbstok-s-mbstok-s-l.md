---
title: strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l
ms.date: 11/04/2016
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
ms.openlocfilehash: a8b87e0b2d4ecf9dc6fb1b52f512406a6df0622c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50517449"
---
# <a name="strtoks-strtoksl-wcstoks-wcstoksl-mbstoks-mbstoksl"></a>strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l

Localiza o próximo token em uma cadeia de caracteres, usando a localidade atual ou uma localidade específica que é informada. Essas versões de [strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> **mbstok_s** e **mbstok_s_l** não pode ser usado em aplicativos executados no tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

unsigned char* _mbstok_s(
   unsigned char* str,
   const unsigned char* delimiters,
   char** context,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Uma cadeia de caracteres que contém o token ou os tokens para localizar.

*Delimitadores*<br/>
O conjunto de caracteres de delimitador a ser usado.

*context*<br/>
Usado para armazenar informações de posição entre as chamadas para a função.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o próximo token encontrado no *str*. Retorna **nulo** quando não há mais tokens são encontradas. Cada chamada modifica *str* substituindo um caractere nulo para o primeiro delimitador que ocorre após o token retornado.

### <a name="error-conditions"></a>Condições de Erro

|*str*|*Delimitadores*|*context*|Valor retornado|**errno**|
|----------------|------------------|---------------|------------------|-------------|
|**NULL**|qualquer|ponteiro para um ponteiro nulo|**NULL**|**EINVAL**|
|qualquer|**NULL**|qualquer|**NULL**|**EINVAL**|
|qualquer|qualquer|**NULL**|**NULL**|**EINVAL**|

Se *str* é **nulo** mas *contexto* é um ponteiro para um ponteiro de contexto válido, não há nenhum erro.

## <a name="remarks"></a>Comentários

O **strtok_s** família de funções localiza o próximo token na *str*. O conjunto de caracteres em *delimitadores* Especifica possíveis delimitadores de token a ser localizado na *str* na chamada atual. **wcstok_s** e **mbstok_s** são versões de caractere largo e caracteres multibyte **strtok_s**. Os argumentos e valores de retorno de **wcstok_s** e **wcstok_s_l** são largos cadeias de caracteres; aqueles de **mbstok_s** e **mbstok_s_l**são cadeias de caracteres multibyte. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Se ocorrer uma condição de erro, como na tabela de Condições de Erro, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornar **nulo**.

Na primeira chamada para **strtok_s** a função ignora delimitadores à esquerda e retorna um ponteiro para o primeiro token no *str*, encerrando o token com um caractere nulo. Mais tokens podem ser divididos, fora o restante da *str* por uma série de chamadas para **strtok_s**. Cada chamada para **strtok_s** modifica *str* inserindo um caractere nulo após o token retornado pela chamada. O *contexto* ponteiro mantém controle de qual cadeia de caracteres está sendo lido e onde o próximo token na cadeia de caracteres é a serem lidos. Para ler o próximo token de *str*, chame **strtok_s** com um **nulo** valor para o *str* argumento e passe o mesmo  *contexto* parâmetro. O **nulo** *str* faz com que o argumento **strtok_s** para procurar o próximo token no modificado *str*. O *delimitadores* argumento pode assumir qualquer valor de uma chamada para o próximo, de modo que o conjunto de delimitadores pode variar.

Uma vez que o *contexto* parâmetro substitui os buffers estáticos usados em **strtok** e **strtok_l**, é possível analisar cadeias de caracteres de dois simultaneamente no mesmo thread.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o **l** sufixo usam a localidade do thread atual desse comportamento dependente da localidade. As versões com o **l** sufixo são idênticas, exceto pelo fato de que usam o *localidade* parâmetro. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtok_s**|\<string.h>|
|**_strtok_s_l**|\<string.h>|
|**wcstok_s**,<br />**_wcstok_s_l**|\<string.h> ou \<wchar.h>|
|**mbstok_s**,<br />**_mbstok_s_l**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|\_UNICODE & \_MBCS não definidos|\_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcstok_s**|**strtok_s**|**_mbstok_s**|**wcstok_s**|
|**tcstok_s_l**|**_strtok_s_l**|**_mbstok_s_l**|**_wcstok_s_l**|

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

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[strcspn, wcscspn, _mbscspn, _mbscspn_l](strcspn-wcscspn-mbscspn-mbscspn-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
