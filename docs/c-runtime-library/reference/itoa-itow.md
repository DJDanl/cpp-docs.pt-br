---
title: _itoa, _itow funções
ms.date: 4/2/2020
api_name:
- itoa
- _itoa
- ltoa
- _ltoa
- ultoa
- _ultoa
- _i64toa
- _ui64toa
- _itow
- _ltow
- _ultow
- _i64tow
- _ui64tow
- _o__i64toa
- _o__i64tow
- _o__itoa
- _o__itow
- _o__ltoa
- _o__ltow
- _o__ui64toa
- _o__ui64tow
- _o__ultoa
- _o__ultow
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
- api-ms-win-crt-convert-l1-1-0.dll
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _itoa
- _ltoa
- _ultoa
- _i64toa
- _ui64toa
- _itow
- _ltow
- _ultow
- _i64tow
- _ui64tow
- itoa
- ltoa
- ultoa
- i64toa
- ui64toa
- itow
- ltow
- ultow
- i64tow
- ui64tow
- itot
- _itot
- ltot
- _ltot
- ultot
- _ultot
- i64tot
- _i64tot
- ui64tot
- _ui64tot
- _MAX_ITOSTR_BASE16_COUNT
- _MAX_ITOSTR_BASE10_COUNT
- _MAX_ITOSTR_BASE8_COUNT
- _MAX_ITOSTR_BASE2_COUNT
- _MAX_LTOSTR_BASE16_COUNT
- _MAX_LTOSTR_BASE10_COUNT
- _MAX_LTOSTR_BASE8_COUNT
- _MAX_LTOSTR_BASE2_COUNT
- _MAX_ULTOSTR_BASE16_COUNT
- _MAX_ULTOSTR_BASE10_COUNT
- _MAX_ULTOSTR_BASE8_COUNT
- _MAX_ULTOSTR_BASE2_COUNT
- _MAX_I64TOSTR_BASE16_COUNT
- _MAX_I64TOSTR_BASE10_COUNT
- _MAX_I64TOSTR_BASE8_COUNT
- _MAX_I64TOSTR_BASE2_COUNT
- _MAX_U64TOSTR_BASE16_COUNT
- _MAX_U64TOSTR_BASE10_COUNT
- _MAX_U64TOSTR_BASE8_COUNT
- _MAX_U64TOSTR_BASE2_COUNT
helpviewer_keywords:
- _itot function
- ui64toa function
- _ui64toa function
- converting integers
- itot function
- _i64tow function
- _i64toa function
- _itow function
- ui64tow function
- integers, converting
- itoa function
- _ui64tow function
- i64tow function
- itow function
- i64toa function
- converting numbers, to strings
- _itoa function
ms.assetid: 46592a00-77bb-4e73-98c0-bf629d96cea6
ms.openlocfilehash: 424ee4fb732811bffc6a83c0de57cd35fe747c42
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82914663"
---
# <a name="itoa-_itoa-ltoa-_ltoa-ultoa-_ultoa-_i64toa-_ui64toa-_itow-_ltow-_ultow-_i64tow-_ui64tow"></a>itoa, _itoa, ltoa, _ltoa, ultoa, _ultoa, _i64toa, _ui64toa, _itow, _ltow, _ultow, _i64tow, _ui64tow

Converte um inteiro em uma cadeia de caracteres. Versões mais seguras dessas funções estão disponíveis; consulte [_itoa_s, _itow_s Functions](itoa-s-itow-s.md).

## <a name="syntax"></a>Sintaxe

```C
char * _itoa( int value, char *buffer, int radix );
char * _ltoa( long value, char *buffer, int radix );
char * _ultoa( unsigned long value, char *buffer, int radix );
char * _i64toa( long long value, char *buffer, int radix );
char * _ui64toa( unsigned long long value, char *buffer, int radix );

wchar_t * _itow( int value, wchar_t *buffer, int radix );
wchar_t * _ltow( long value, wchar_t *buffer, int radix );
wchar_t * _ultow( unsigned long value, wchar_t *buffer, int radix );
wchar_t * _i64tow( long long value, wchar_t *buffer, int radix );
wchar_t * _ui64tow( unsigned long long value, wchar_t *buffer, int radix );

// These POSIX versions of the functions have deprecated names:
char * itoa( int value, char *buffer, int radix );
char * ltoa( long value, char *buffer, int radix );
char * ultoa( unsigned long value, char *buffer, int radix );

// The following template functions are C++ only:
template <size_t size>
char *_itoa( int value, char (&buffer)[size], int radix );

template <size_t size>
char *_itoa( long value, char (&buffer)[size], int radix );

template <size_t size>
char *_itoa( unsigned long value, char (&buffer)[size], int radix );

template <size_t size>
char *_i64toa( long long value, char (&buffer)[size], int radix );

template <size_t size>
char * _ui64toa( unsigned long long value, char (&buffer)[size], int radix );

template <size_t size>
wchar_t * _itow( int value, wchar_t (&buffer)[size], int radix );

template <size_t size>
wchar_t * _ltow( long value, wchar_t (&buffer)[size], int radix );

template <size_t size>
wchar_t * _ultow( unsigned long value, wchar_t (&buffer)[size], int radix );

template <size_t size>
wchar_t * _i64tow( long long value, wchar_t (&buffer)[size], int radix );

template <size_t size>
wchar_t * _ui64tow( unsigned long long value, wchar_t (&buffer)[size],
   int radix );
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Número a ser convertido.

*completo*<br/>
Buffer que contém o resultado da conversão.

*Radix*<br/>
A base a ser usada para a conversão de *valor*, que deve estar no intervalo de 2-36.

*size*<br/>
Comprimento do buffer em unidades do tipo de caractere. Esse parâmetro é inferido do argumento *buffer* em C++.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro para o *buffer*. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

As funções **_itoa**, **_ltoa**, **_ultoa**, **_i64toa**e **_ui64toa** convertem os dígitos do argumento de *valor* fornecido em uma cadeia de caracteres terminada em nulo e armazenam o resultado (até 33 caracteres para **_itoa**, **_ltoa**e **_ultoa**e 65 para **_i64toa** e **_ui64toa**) no *buffer*. Se *Radix* for igual a 10 e o *valor* for negativo, o primeiro caractere da cadeia de caracteres armazenada**-** será o sinal de subtração (). As funções **_itow**, **_ltow**, **_ultow**, **_i64tow**e **_ui64tow** são versões de caractere largo de **_itoa**, **_ltoa**, **_ultoa**, **_i64toa**e **_ui64toa**, respectivamente.

> [!IMPORTANT]
> Essas funções podem gravar após o final de um buffer que é muito pequeno. Para evitar saturações de buffer, verifique se o *buffer* é grande o suficiente para manter os dígitos convertidos mais o caractere nulo à direita e um caractere de sinal. O uso indevido dessas funções pode causar sérios problemas de segurança em seu código.

Devido a seus possíveis problemas de segurança, por padrão, essas funções causam um aviso de reprovação [C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md): **essa função ou variável pode não ser segura. Considere usar** *safe_function* **em vez disso. Para desabilitar a reprovação, use _CRT_SECURE_NO_WARNINGS.** Recomendamos que você altere seu código-fonte para usar o *safe_function* sugerido pela mensagem de aviso. As funções mais seguras não gravam mais caracteres do que o tamanho do buffer especificado. Para obter mais informações, consulte [_itoa_s _itow_s funções](itoa-s-itow-s.md).

Para usar essas funções sem o aviso de reprovação, defina a macro de pré-processador de **_CRT_SECURE_NO_WARNINGS** antes de incluir todos os cabeçalhos CRT. Você pode fazer isso na linha de comando em um prompt de comando do desenvolvedor adicionando a opção **/D_CRT_SECURE_NO_WARNINGS** do compilador ao comando **CL** . Caso contrário, defina a macro em seus arquivos de origem. Se você usar cabeçalhos pré-compilados, defina a macro na parte superior do cabeçalho pré-compilado include File, *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior). Para definir a macro em seu código-fonte, use uma diretiva **#define** antes de incluir qualquer cabeçalho CRT, como neste exemplo:

```C
By default, this function's global state is scoped to the application. To change this, see [Global state in the CRT](../global-state.md).

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
```

Em C++, essas funções têm sobrecargas de modelo que invocam suas contrapartes mais seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Os nomes POSIX **itoa**, **ltoa**e **ultoa** existem como aliases para as funções **_itoa**, **_ltoa**e **_ultoa** . Os nomes POSIX são preteridos porque não seguem as convenções de nome de função global específicas da implementação do ISO C. Por padrão, essas funções causam o aviso de reprovação [C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md): **o nome POSIX deste item é preterido. Em vez disso, use o nome de conformidade ISO C e C++:** *new_name*. Recomendamos que você altere seu código-fonte para usar as versões mais seguras dessas funções, **_itoa_s**, **_ltoa_s**ou **_ultoa_s**. Para obter mais informações, consulte [_itoa_s _itow_s funções](itoa-s-itow-s.md).

Para portabilidade do código-fonte, você pode preferir manter os nomes POSIX em seu código. Para usar essas funções sem o aviso de reprovação, defina as macros de pré-processador de **_CRT_NONSTDC_NO_WARNINGS** e de **_CRT_SECURE_NO_WARNINGS** antes de incluir todos os cabeçalhos CRT. Você pode fazer isso na linha de comando em um prompt de comando do desenvolvedor adicionando as opções de compilador **/D_CRT_SECURE_NO_WARNINGS** e **/D_CRT_NONSTDC_NO_WARNINGS** ao comando **CL** . Caso contrário, defina as macros em seus arquivos de origem. Se você usar cabeçalhos pré-compilados, defina as macros na parte superior do cabeçalho pré-compilado incluir arquivo. Para definir as macros em seu código-fonte, use **#define** diretivas antes de incluir qualquer cabeçalho CRT, como neste exemplo:

```C
#define _CRT_NONSTDC_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
```

### <a name="maximum-conversion-count-macros"></a>Máximo de macros de contagem de conversão

Para ajudá-lo a criar buffers seguros para conversões, o CRT inclui algumas macros convenientes. Elas definem o tamanho do buffer necessário para converter o valor mais longo possível de cada tipo inteiro, incluindo o terminador nulo e o caractere de sinal para várias bases comuns. Para garantir que o buffer de conversão seja grande o suficiente para receber qualquer conversão na base especificada pela *base*, use uma dessas macros definidas ao alocar o buffer. Isso ajuda a evitar erros de saturação de buffer quando você converte tipos inteiros em cadeias de caracteres. Essas macros são definidas quando você inclui STDLIB. h ou WCHAR. h em sua origem.

Para usar uma dessas macros em uma função de conversão de cadeia de caracteres, declare o buffer de conversão do tipo de caractere apropriado e use o valor da macro para o tipo inteiro e base como a dimensão de buffer. Esta tabela lista as macros apropriadas para cada função para as bases listadas:

||||
|-|-|-|
|Funções|radix|Macros|
|**_itoa**, **_itow**|16<br/>10<br/>8<br/>2|**_MAX_ITOSTR_BASE16_COUNT**<br/>**_MAX_ITOSTR_BASE10_COUNT**<br/>**_MAX_ITOSTR_BASE8_COUNT**<br/>**_MAX_ITOSTR_BASE2_COUNT**|
|**_ltoa**, **_ltow**|16<br/>10<br/>8<br/>2|**_MAX_LTOSTR_BASE16_COUNT**<br/>**_MAX_LTOSTR_BASE10_COUNT**<br/>**_MAX_LTOSTR_BASE8_COUNT**<br/>**_MAX_LTOSTR_BASE2_COUNT**|
|**_ultoa**, **_ultow**|16<br/>10<br/>8<br/>2|**_MAX_ULTOSTR_BASE16_COUNT**<br/>**_MAX_ULTOSTR_BASE10_COUNT**<br/>**_MAX_ULTOSTR_BASE8_COUNT**<br/>**_MAX_ULTOSTR_BASE2_COUNT**|
|**_i64toa**, **_i64tow**|16<br/>10<br/>8<br/>2|**_MAX_I64TOSTR_BASE16_COUNT**<br/>**_MAX_I64TOSTR_BASE10_COUNT**<br/>**_MAX_I64TOSTR_BASE8_COUNT**<br/>**_MAX_I64TOSTR_BASE2_COUNT**|
|**_ui64toa**, **_ui64tow**|16<br/>10<br/>8<br/>2|**_MAX_U64TOSTR_BASE16_COUNT**<br/>**_MAX_U64TOSTR_BASE10_COUNT**<br/>**_MAX_U64TOSTR_BASE8_COUNT**<br/>**_MAX_U64TOSTR_BASE2_COUNT**|

Este exemplo usa uma macro Count de conversão para definir um buffer grande o suficiente para conter um longo longo **não assinado** na base 2:

```cpp
#include <wchar.h>
#include <iostream>
int main()
{
    wchar_t buffer[_MAX_U64TOSTR_BASE2_COUNT];
    std:wcout << _ui64tow(0xFFFFFFFFFFFFFFFFull, buffer, 2) << std::endl;
}
```

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_itot**|**_itoa**|**_itoa**|**_itow**|
|**_ltot**|**_ltoa**|**_ltoa**|**_ltow**|
|**_ultot**|**_ultoa**|**_ultoa**|**_ultow**|
|**_i64tot**|**_i64toa**|**_i64toa**|**_i64tow**|
|**_ui64tot**|**_ui64toa**|**_ui64toa**|**_ui64tow**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**itoa**, **ltoa**, **ultoa**|\<stdlib.h>|
|**_itoa**, **_ltoa**, **_ultoa**, **_i64toa**, **_ui64toa**|\<stdlib.h>|
|**_itow**, **_ltow**, **_ultow**, **_i64tow**, **_ui64tow**|\<stdlib.h> ou \<wchar.h>|

Essas funções e macros são específicas da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este exemplo demonstra o uso de algumas das funções de conversão de inteiros. Observe o uso da macro **_CRT_SECURE_NO_WARNINGS** para silenciar o aviso C4996.

```C
// crt_itoa.c
// Compile by using: cl /W4 crt_itoa.c
// This program makes use of the _itoa functions
// in various examples.

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>      // for printf
#include <string.h>     // for strnlen
#include <stdlib.h>     // for _countof, _itoa fns, _MAX_COUNT macros

int main(void)
{
    char buffer[_MAX_U64TOSTR_BASE2_COUNT];
    int r;

    for (r = 10; r >= 2; --r)
    {
        _itoa(-1, buffer, r);
        printf("base %d: %s (%d chars)\n", r, buffer,
            strnlen(buffer, _countof(buffer)));
    }
    printf("\n");

    for (r = 10; r >= 2; --r)
    {
        _i64toa(-1LL, buffer, r);
        printf("base %d: %s (%d chars)\n", r, buffer,
            strnlen(buffer, _countof(buffer)));
    }
    printf("\n");

    for (r = 10; r >= 2; --r)
    {
        _ui64toa(0xffffffffffffffffULL, buffer, r);
        printf("base %d: %s (%d chars)\n", r, buffer,
            strnlen(buffer, _countof(buffer)));
    }
}
```

```Output
base 10: -1 (2 chars)
base 9: 12068657453 (11 chars)
base 8: 37777777777 (11 chars)
base 7: 211301422353 (12 chars)
base 6: 1550104015503 (13 chars)
base 5: 32244002423140 (14 chars)
base 4: 3333333333333333 (16 chars)
base 3: 102002022201221111210 (21 chars)
base 2: 11111111111111111111111111111111 (32 chars)

base 10: -1 (2 chars)
base 9: 145808576354216723756 (21 chars)
base 8: 1777777777777777777777 (22 chars)
base 7: 45012021522523134134601 (23 chars)
base 6: 3520522010102100444244423 (25 chars)
base 5: 2214220303114400424121122430 (28 chars)
base 4: 33333333333333333333333333333333 (32 chars)
base 3: 11112220022122120101211020120210210211220 (41 chars)
base 2: 1111111111111111111111111111111111111111111111111111111111111111 (64 chars)

base 10: 18446744073709551615 (20 chars)
base 9: 145808576354216723756 (21 chars)
base 8: 1777777777777777777777 (22 chars)
base 7: 45012021522523134134601 (23 chars)
base 6: 3520522010102100444244423 (25 chars)
base 5: 2214220303114400424121122430 (28 chars)
base 4: 33333333333333333333333333333333 (32 chars)
base 3: 11112220022122120101211020120210210211220 (41 chars)
base 2: 1111111111111111111111111111111111111111111111111111111111111111 (64 chars)
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[_itoa_s, _itow_s funções](itoa-s-itow-s.md)<br/>
