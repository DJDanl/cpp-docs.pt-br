---
title: _get_tzname | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- _get_tzname function
- time zones
- get_tzname function
ms.assetid: df0065ff-095f-4237-832c-2fe9ab913875
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 182bad39b461efc18b120875432d6ce07be2a884
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
O endereço de uma cadeia de caracteres para a representação do nome do fuso horário ou o nome de zona de hora padrão de horário de verão (DST), dependendo de *índice*.

*sizeInBytes*<br/>
O tamanho do *timeZoneName* cadeia de caracteres em bytes.

*index*<br/>
O índice de um dos dois nomes de fuso horário a serem recuperados.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido, caso contrário, um **errno** tipo de valor.

Se qualquer um dos *timeZoneName* é **nulo**, ou *sizeInBytes* for zero ou menor que zero (mas não ambos), um manipulador de parâmetro inválido é invocado, conforme descrito em [ Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

### <a name="error-conditions"></a>Condições de Erro

|*pReturnValue*|*timeZoneName*|*sizeInBytes*|*index*|Valor retornado|Conteúdo de *timeZoneName*|
|--------------------|--------------------|-------------------|-------------|------------------|--------------------------------|
|tamanho do nome do FH|**NULL**|0|0 ou 1|0|não modificado|
|tamanho do nome do FH|qualquer|> 0|0 ou 1|0|Nome do FH|
|não modificado|**NULL**|> 0|qualquer|**EINVAL**|não modificado|
|não modificado|qualquer|zero|qualquer|**EINVAL**|não modificado|
|não modificado|qualquer|> 0|> 1|**EINVAL**|não modificado|

## <a name="remarks"></a>Comentários

O **get_tzname** função recupera a representação da cadeia de caracteres do nome do fuso horário ou o nome de zona de hora padrão do horário de verão (DST) no endereço de *timeZoneName* dependendo do índice valor, junto com o tamanho da cadeia de caracteres *pReturnValue*. Se *timeZoneName* é **nulo** e *sizeInBytes* for zero, o tamanho da cadeia de caracteres de horário zona em bytes é retornada no *pReturnValue*. Os valores de índice devem ser 0 para o fuso horário padrão ou 1 para o fuso horário com horário de verão; todos os outros valores de índice têm resultados indeterminados.

### <a name="index-values"></a>Valores de índice

|*index*|Conteúdo de *timeZoneName*|*timeZoneName* valor padrão|
|-------------|--------------------------------|----------------------------------|
|0|Nome do fuso horário|"PST"|
|1|O nome do fuso horário com horário de verão|"PDT"|
|> 1 ou < 0|**errno** definida como **EINVAL**|não modificado|

A menos que os valores sejam alterados explicitamente durante o tempo de execução, os valores padrão serão "PST" e "PDT" respectivamente.  Os tamanhos desses conjuntos de caracteres são administrados por **TZNAME_MAX** valor.

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
[TZNAME_MAX](../../c-runtime-library/tzname-max.md)<br/>
