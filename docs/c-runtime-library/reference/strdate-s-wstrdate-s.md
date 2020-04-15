---
title: _strdate_s, _wstrdate_s
description: _strdate_s e _wstrdate_s são versões CRT seguras das funções de _strdate e _wstrdate que colocam a data atual em um buffer.
ms.date: 4/2/2020
api_name:
- _strdate_s
- _wstrdate_s
- _o__strdate_s
- _o__wstrdate_s
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _strdate_s
- wstrdate_s
- _wstrdate_s
- strdate_s
- _tstrdate_s
helpviewer_keywords:
- dates, copying
- tstrdate_s function
- wstrdate_s function
- _tstrdate_s function
- strdate_s function
- copying dates
- _strdate_s function
- _wstrdate_s function
ms.assetid: d41d8ea9-e5ce-40d4-864e-1ac29b455991
ms.openlocfilehash: b4d977ba3546eae17218c63b1786fd26c784d340
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359829"
---
# <a name="_strdate_s-_wstrdate_s"></a>_strdate_s, _wstrdate_s

Copie a data atual do sistema para um buffer. Essas funções são versões de [_strdate, _wstrdate](strdate-wstrdate.md) com melhorias de segurança descritas [nos Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _strdate_s(
   char *buffer,
   size_t size
);
errno_t _wstrdate_s(
   wchar_t *buffer,
   size_t size
);
template <size_t size>
errno_t _strdate_s(
   char (&buffer)[size]
); // C++ only
template <size_t size>
errno_t _wstrdate_s(
   wchar_t (&buffer)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Buffer*\
Um ponteiro para um buffer para colocar a seqüência de datas formatada.

*Tamanho*\
Tamanho do buffer em unidades de caracteres.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. O valor de devolução é um código de erro se houver uma falha. Códigos de erro são definidos em ERRNO.H; consulte a tabela abaixo para os erros exatos gerados por esta função. Para obter mais informações sobre códigos de erro, consulte [errno](../../c-runtime-library/errno-constants.md).

## <a name="error-conditions"></a>Condições de erro

|*Buffer*|*Tamanho*|Retorno|Conteúdo de *buffer*|
|--------------|------------------------|------------|--------------------------|
|**NULO**|(qualquer)|**Einval**|Não modificado|
|Não **NULL** (apontando para buffer válido)|0|**Einval**|Não modificado|
|Não **NULL** (apontando para buffer válido)|0 *tamanho* < < 9|**Einval**|cadeia de caracteres vazia|
|Não **NULL** (apontando para buffer válido)|*tamanho* >= 9|0|Data atual formatada conforme especificado nos comentários|

## <a name="security-issues"></a>Problemas de segurança

A aprovação de um valor inválido e não NULA para *buffer* resulta em uma violação de acesso se o parâmetro de *tamanho* for maior que nove.

Passar um valor para *tamanho* maior do que o tamanho real do *buffer* resulta em um buffer overrun.

## <a name="remarks"></a>Comentários

Essas funções fornecem versões mais seguras de **_strdate** e **_wstrdate**. A função **_strdate_s** copia a data atual do sistema para o buffer apontado pelo *buffer*. É formatado, `mm/dd/yy`onde `mm` é o mês `dd` de dois dígitos, `yy` é o dia de dois dígitos, e são os dois últimos dígitos do ano. Por exemplo, a cadeia de caracteres `12/05/99` representa 5 de dezembro de 1999. O buffer deve ter pelo menos nove caracteres.

**_wstrdate_s** é uma versão ampla de **_strdate_s;** o argumento e o valor de retorno de **_wstrdate_s** são cadeias de caracteres amplos. Caso contrário, essas funções se comportam de forma idêntica.

Quando *buffer* é um ponteiro **NULL,** ou *tamanho* é menor que nove caracteres, o manipulador de parâmetros inválido é invocado. Está descrito na [Validação de Parâmetros.](../../c-runtime-library/parameter-validation.md) Se a execução continuar, essas funções retornam -1. Eles definem **errno** para **EINVAL** se o buffer é **NULO** ou se *o tamanho* é menor ou igual a 0. Ou, eles definem **errno** para **ERANGE** se *o tamanho* for menor que 9.

Em C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir o comprimento do buffer automaticamente, o que elimina a necessidade de especificar um argumento *de tamanho.* E, eles podem substituir automaticamente funções não seguras por suas contrapartes mais novas e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento de rotina de texto genérico:

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tstrdate_s**|**_strdate_s**|**_strdate_s**|**_wstrdate_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strdate**|\<time.h>|
|**_wstrdate**|\<time.h> ou \<wchar.h>|
|**_strdate_s**|\<time.h>|

## <a name="example"></a>Exemplo

Veja o exemplo de [time](time-time32-time64.md).

## <a name="see-also"></a>Confira também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)\
[asctime_s _wasctime_s](asctime-s-wasctime-s.md)\
[ctime_s, _ctime32_s, _ctime64_s _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)\
[gmtime_s, _gmtime32_s _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)\
[localtime_s _localtime32_s _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)\
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)\
[tempo, _time32, _time64](time-time32-time64.md)\
[_tzset](tzset.md)
