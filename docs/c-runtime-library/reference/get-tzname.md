---
title: _get_tzname
ms.date: 4/2/2020
api_name:
- _get_tzname
- _o__get_tzname
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
- api-ms-win-crt-time-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _get_tzname
- get_tzname
helpviewer_keywords:
- _get_tzname function
- time zones
- get_tzname function
ms.assetid: df0065ff-095f-4237-832c-2fe9ab913875
ms.openlocfilehash: bf63b0ade0adc0a2dfa471bbfbeebc0cb2d04911
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919678"
---
# <a name="_get_tzname"></a>_get_tzname

Recupera a representação da cadeia de caracteres do nome do fuso horário ou do nome do fuso horário com horário de verão (DST).

## <a name="syntax"></a>Sintaxe

```C
errno_t _get_tzname(
    size_t* pReturnValue,
    char* timeZoneName,
    size_t sizeInBytes,
    int index
);
```

### <a name="parameters"></a>Parâmetros

*preativar*<br/>
O tamanho da cadeia de caracteres de *timeZoneName* incluindo um terminador nulo.

*timeZoneName*<br/>
O endereço de uma cadeia de caracteres para a representação do nome do fuso horário ou o horário de verão padrão, dependendo do *índice*.

*sizeInBytes*<br/>
O tamanho da cadeia de caracteres *timeZoneName* em bytes.

*index*<br/>
O índice de um dos dois nomes de fuso horário a serem recuperados.

|*index*|Conteúdo de *timeZoneName*|valor padrão *timeZoneName*|
|-|-|-|
|0|Nome do fuso horário|"PST"|
|1|O nome do fuso horário com horário de verão|"PDT"|
|> 1 ou < 0|**errno** definido como **EINVAL**|não modificado|

A menos que os valores sejam alterados explicitamente durante o tempo de execução, os valores padrão serão "PST" e "PDT" respectivamente.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido, caso contrário, um valor de tipo **errno** .

Se *timeZoneName* for **nulo**ou *sizeInBytes* for zero ou menor que zero (mas não ambos), um manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **EINVAL**.

### <a name="error-conditions"></a>Condições de erro

|*preativar*|*timeZoneName*|*sizeInBytes*|*index*|Valor retornado|Conteúdo de *timeZoneName*|
|--------------------|--------------------|-------------------|-------------|------------------|--------------------------------|
|tamanho do nome do FH|**NULO**|0|0 ou 1|0|não modificado|
|tamanho do nome do FH|any|> 0|0 ou 1|0|Nome do FH|
|não modificado|**NULO**|> 0|any|**EINVAL**|não modificado|
|não modificado|any|zero|any|**EINVAL**|não modificado|
|não modificado|any|> 0|> 1|**EINVAL**|não modificado|

## <a name="remarks"></a>Comentários

A função **_get_tzname** recupera a representação de cadeia de caracteres do nome do fuso horário atual ou o horário de Verão (horário padrão) para o endereço do *timeZoneName* , dependendo do valor do índice, junto com o tamanho da cadeia de caracteres em *preligávalue*. Se *timeZoneName* for **NULL** e *sizeInBytes* for zero, o tamanho da cadeia de caracteres necessária para manter o fuso horário especificado e um nulo de terminação em bytes será retornado em *pretransformvalue*. Os valores de índice devem ser 0 para o fuso horário padrão ou 1 para o fuso horário padrão de verão; quaisquer outros valores de *índice* têm resultados indeterminados.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="example"></a>Exemplo

Este exemplo chama **_get_tzname** para obter o tamanho de buffer necessário para exibir o nome do fuso horário padrão atual, aloca um buffer desse tamanho, chama **_get_tzname** novamente para carregar o nome no buffer e o imprime no console.

```C
// crt_get_tzname.c
// Compile by using: cl /W4 crt_get_tzname.c
#include <stdio.h>
#include <time.h>
#include <malloc.h>

enum TZINDEX {
    STD,
    DST
};

int main()
{
    size_t tznameSize = 0;
    char * tznameBuffer = NULL;

    // Get the size of buffer required to hold DST time zone name
    if (_get_tzname(&tznameSize, NULL, 0, DST))
        return 1;    // Return an error value if it failed

    // Allocate a buffer for the name
    if (NULL == (tznameBuffer = (char *)(malloc(tznameSize))))
        return 2;    // Return an error value if it failed

    // Load the name in the buffer
    if (_get_tzname(&tznameSize, tznameBuffer, tznameSize, DST))
        return 3;    // Return an error value if it failed

    printf_s("The current Daylight standard time zone name is %s.\n", tznameBuffer);
    return 0;
}
```

### <a name="output"></a>Saída

```Output
The current Daylight standard time zone name is PDT.
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_tzname**|\<time.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_daylight](get-daylight.md)<br/>
[_get_dstbias](get-dstbias.md)<br/>
[_get_timezone](get-timezone.md)<br/>
