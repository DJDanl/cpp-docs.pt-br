---
title: _get_tzname
ms.date: 10/22/2018
apiname:
- _get_tzname
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _get_tzname
- get_tzname
helpviewer_keywords:
- _get_tzname function
- time zones
- get_tzname function
ms.assetid: df0065ff-095f-4237-832c-2fe9ab913875
ms.openlocfilehash: c173832efb866eed133a908b5f2b72266fd3798a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452228"
---
# <a name="gettzname"></a>_get_tzname

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

*pReturnValue*<br/>
O comprimento da cadeia de caracteres de *timeZoneName* incluindo um terminador nulo.

*timeZoneName*<br/>
O endereço de uma cadeia de caracteres para a representação do nome do fuso horário ou nome do fuso horário de verão (DST), dependendo do *índice*.

*sizeInBytes*<br/>
O tamanho do *timeZoneName* cadeia de caracteres em bytes.

*index*<br/>
O índice de um dos dois nomes de fuso horário a serem recuperados.

|*index*|Conteúdo de *timeZoneName*|*timeZoneName* valor padrão|
|-|-|-|
|0|Nome do fuso horário|"PST"|
|1|O nome do fuso horário com horário de verão|"PDT"|
|> 1 ou < 0|**errno** definido como **EINVAL**|não modificado|

A menos que os valores sejam alterados explicitamente durante o tempo de execução, os valores padrão serão "PST" e "PDT" respectivamente.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido, caso contrário, uma **errno** tipo de valor.

Se qualquer um dos *timeZoneName* é **nulo**, ou *sizeInBytes* for zero ou menor que zero (mas não ambos), um manipulador de parâmetro inválido será invocado, conforme descrito em [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retorna **EINVAL**.

### <a name="error-conditions"></a>Condições de Erro

|*pReturnValue*|*timeZoneName*|*sizeInBytes*|*index*|Valor retornado|Conteúdo de *timeZoneName*|
|--------------------|--------------------|-------------------|-------------|------------------|--------------------------------|
|tamanho do nome do FH|**NULL**|0|0 ou 1|0|não modificado|
|tamanho do nome do FH|qualquer|> 0|0 ou 1|0|Nome do FH|
|não modificado|**NULL**|> 0|qualquer|**EINVAL**|não modificado|
|não modificado|qualquer|zero|qualquer|**EINVAL**|não modificado|
|não modificado|qualquer|> 0|> 1|**EINVAL**|não modificado|

## <a name="remarks"></a>Comentários

O **get_tzname** função recupera a representação de cadeia de caracteres do nome do fuso horário atual ou o nome do fuso horário de verão (DST) no endereço de *timeZoneName* dependendo a valor, junto com o tamanho da cadeia de caracteres de índice *pReturnValue*. Se *timeZoneName* é **nulo** e *sizeInBytes* é zero, o tamanho da cadeia de caracteres necessário para manter o fuso horário especificado e um nulo de terminação em bytes é retornado no *pReturnValue*. Os valores de índice devem ser a 0 para o fuso horário padrão ou 1 para o fuso horário padrão de horário de verão; todos os outros valores de *índice* têm resultados indeterminados.

## <a name="example"></a>Exemplo

Este exemplo chama **get_tzname** obter o tamanho do buffer necessário para exibir o nome de zona de horário padrão verão atual, aloca um buffer desse tamanho, chamadas **get_tzname** novamente para o nome na carga de armazenar em buffer e o exibe no console.

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

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
[_get_daylight](get-daylight.md)<br/>
[_get_dstbias](get-dstbias.md)<br/>
[_get_timezone](get-timezone.md)<br/>
