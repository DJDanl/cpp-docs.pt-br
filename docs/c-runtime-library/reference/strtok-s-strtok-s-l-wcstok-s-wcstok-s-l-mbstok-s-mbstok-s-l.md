---
title: strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: 9be62937a5c687c93f0280a8f3ca9d8acc955567
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strtoks-strtoksl-wcstoks-wcstoksl-mbstoks-mbstoksl"></a>strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l

Localiza o próximo token em uma cadeia de caracteres, usando a localidade atual ou uma localidade específica que é informada. Essas versões de [strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> **mbstok_s** e **mbstok_s_l** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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
Uma cadeia de caracteres que contém o token ou os tokens de localizar.

*Delimitadores*<br/>
O conjunto de caracteres de delimitador a ser usado.

*context*<br/>
Usado para armazenar informações de posição entre as chamadas para a função.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o próximo token encontrado no *str*. Retorna **nulo** quando não há mais tokens forem encontrados. Cada chamada modifica *str* substituindo um **nulo** caracteres para o primeiro delimitador que ocorre após o token retornado.

### <a name="error-conditions"></a>Condições de Erro

|*str*|*Delimitadores*|*context*|Valor retornado|**errno**|
|----------------|------------------|---------------|------------------|-------------|
|**NULL**|qualquer|ponteiro para um ponteiro nulo|**NULL**|**EINVAL**|
|qualquer|**NULL**|qualquer|**NULL**|**EINVAL**|
|qualquer|qualquer|**NULL**|**NULL**|**EINVAL**|

Se *str* é **nulo** mas *contexto* é um ponteiro para um ponteiro de contexto válido, não há nenhum erro.

## <a name="remarks"></a>Comentários

O **strtok_s** família de funções localiza o próximo token em *str*. O conjunto de caracteres em *delimitadores* Especifica possíveis delimitadores de token a ser localizado na *str* na chamada atual. **wcstok_s** e **mbstok_s** são versões de caracteres largos e caracteres multibyte **strtok_s**. Os argumentos e valores de retorno de **wcstok_s** e **wcstok_s_l** são caracteres largos cadeias de caracteres; desses **mbstok_s** e **mbstok_s_l**são cadeias de caracteres multibyte. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Se ocorrer uma condição de erro, como na tabela de Condições de Erro, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções definido **errno** para **EINVAL** e retornar **nulo**.

Na primeira chamada para **strtok_s** a função ignora delimitadores à esquerda e retorna um ponteiro para o primeiro token no *str*, encerrando o token com um caractere nulo. Tokens mais podem ser divididas fora o restante do *str* por uma série de chamadas para **strtok_s**. Cada chamada para **strtok_s** modifica *str* inserindo um caractere nulo após o token retornado pela chamada. O *contexto* ponteiro mantém o controle de cadeia de caracteres que está sendo lido e onde o próximo token na cadeia de caracteres é a ser lido. Para ler o próximo token de *str*, chame **strtok_s** com um **nulo** valor para o *str* argumento e passar o mesmo  *contexto* parâmetro. O **nulo** *str* faz com que o argumento **strtok_s** para procurar o próximo token em modificada *str*. O *delimitadores* argumento pode ter qualquer valor de uma chamada para a próxima para que o conjunto de delimitadores pode variar.

Como o *contexto* parâmetro substitui os buffers estáticos usados em **strtok** e **strtok_l**, é possível analisar as duas cadeias de caracteres simultaneamente no mesmo thread.

O valor de saída é afetado pela configuração do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o **_l** sufixo usam a localidade do thread atual para este comportamento dependente de localidade. As versões com o **_l** sufixo são idênticos, exceto que, em vez disso, eles usam o *localidade* parâmetro. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtok_s**|\<string.h>|
|**_strtok_s_l**|\<string.h>|
|**wcstok_s**,<br />**_wcstok_s_l**|\<string.h> ou \<wchar.h>|
|**mbstok_s**,<br />**_mbstok_s_l**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|_UNICODE definido|
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
