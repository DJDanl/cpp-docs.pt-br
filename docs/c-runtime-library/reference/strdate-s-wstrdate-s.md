---
title: _strdate_s, _wstrdate_s
ms.date: 11/04/2016
api_name:
- _strdate_s
- _wstrdate_s
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
ms.openlocfilehash: fadd30ec81cff59d675212e59c8513656c7b2f35
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70940746"
---
# <a name="_strdate_s-_wstrdate_s"></a>_strdate_s, _wstrdate_s

Copie a data atual do sistema para um buffer. Estas são versões de [_strdate, _wstrdate](strdate-wstrdate.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _strdate_s(
   char *buffer,
   size_t numberOfElements
);
errno_t _wstrdate_s(
   wchar_t *buffer,
   size_t numberOfElements
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

*buffer*<br/>
Um ponteiro para um buffer que será preenchido com a cadeia de caracteres de data formatada.

*numberOfElements*<br/>
O tamanho do buffer.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em ERRNO.H; consulte a tabela abaixo para os erros exatos gerados por esta função. Para obter mais informações sobre códigos de erro, consulte [errno](../../c-runtime-library/errno-constants.md).

## <a name="error-conditions"></a>Condições de Erro

|*buffer*|*numberOfElements*|Valor de|Conteúdo do *buffer*|
|--------------|------------------------|------------|--------------------------|
|**NULL**|(qualquer)|**EINVAL**|Não modificado|
|Não **nulo** (apontando para um buffer válido)|0|**EINVAL**|Não modificado|
|Não **nulo** (apontando para um buffer válido)|0 < *numberOfElements* < 9|**EINVAL**|Cadeia de caracteres vazia|
|Não **nulo** (apontando para um buffer válido)|*numberOfElements* >= 9|0|Data atual formatada conforme especificado nos comentários|

## <a name="security-issues"></a>Problemas de segurança

A passagem de um valor não **nulo** inválido para o buffer resultará em uma violação de acesso se o parâmetro *numberOfElements* for maior que 9.

Passar valores para o tamanho maior que o tamanho real do *buffer* resultará em saturação do buffer.

## <a name="remarks"></a>Comentários

Essas funções fornecem versões mais seguras do **_strdate** e do **_wstrdate**. A **função _strdate_s** copia a data atual do sistema para o buffer apontado *pelo buffer*, formatada **mm**/**DD**/**AA**, em que **mm** é dois dígitos que representam o mês, **DD** é dois dígitos que representam o dia e **YY** são os dois últimos dígitos do ano. Por exemplo, a cadeia de caracteres **12/05/99** representa 5 de dezembro de 1999. O buffer deve ter, no mínimo, 9 caracteres de comprimento.

**_wstrdate_s** é uma versão de caractere largo do **_strdate_s**; o argumento e o valor de retorno de **_wstrdate_s** são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Se o *buffer* for um ponteiro **nulo** ou se *numberOfElements* tiver menos de 9 caracteres, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão-1 e definirá **errno** como **EINVAL** se o buffer for **nulo** ou se *numberOfElements* for menor ou igual a 0, ou definir **errno** como **ERANGE** se *NumberOfElements* é menor que 9.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico:

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

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
