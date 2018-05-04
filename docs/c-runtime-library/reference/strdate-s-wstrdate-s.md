---
title: _strdate_s, _wstrdate_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _strdate_s
- _wstrdate_s
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
- _strdate_s
- wstrdate_s
- _wstrdate_s
- strdate_s
- _tstrdate_s
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8e4e9ff3783fc7a89e7af42ebf283209c034c0d6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="strdates-wstrdates"></a>_strdate_s, _wstrdate_s

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

|*buffer*|*numberOfElements*|Valor de|Conteúdo de *buffer*|
|--------------|------------------------|------------|--------------------------|
|**NULL**|(qualquer)|**EINVAL**|Não modificado|
|Não **nulo** (apontando para o buffer válido)|0|**EINVAL**|Não modificado|
|Não **nulo** (apontando para o buffer válido)|0 < *numberOfElements* < 9|**EINVAL**|Cadeia de caracteres vazia|
|Não **nulo** (apontando para o buffer válido)|*numberOfElements* > = 9|0|Data atual formatada conforme especificado nos comentários|

## <a name="security-issues"></a>Problemas de segurança

Passando um inválido não **nulo** valor para o buffer resultará em uma violação de acesso se o *numberOfElements* parâmetro for maior que 9.

Passando valores para o tamanho que é maior do que o tamanho real do *buffer* resultará em um estouro de buffer.

## <a name="remarks"></a>Comentários

Essas funções fornecem versões mais seguras do **strDate** e **wstrdate**. O **strdate_s** função copia a data atual do sistema para o buffer apontado pelo *buffer*formatado **mm**/**dd** / **AA**, onde **mm** são dois dígitos que representa o mês, **dd** são dois dígitos que representa o dia e **AA**  é os dois últimos dígitos do ano. Por exemplo, a cadeia de caracteres **05/12/99** representa o dia 5 de dezembro de 1999. O buffer deve ter, no mínimo, 9 caracteres de comprimento.

**wstrdate_s** é uma versão de caractere largo de **strdate_s**; o valor de retorno e de argumento de **wstrdate_s** são cadeias de caracteres do caractere largo. Caso contrário, essas funções se comportam de forma idêntica.

Se *buffer* é um **nulo** ponteiro, ou se *numberOfElements* é menor que 9 caracteres, o manipulador de parâmetro inválido é invocado, conforme descrito em [ Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam -1 e defina **errno** para **EINVAL** se o buffer for **nulo** ou se *numberOfElements*é menor ou igual a 0 ou conjunto **errno** para **ERANGE** se *numberOfElements* é menor que 9.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico:

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tstrdate_s**|**_strdate_s**|**_strdate_s**|**_wstrdate_s**|

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
