---
title: ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s
ms.date: 11/04/2016
api_name:
- _ctime64_s
- _wctime32_s
- ctime_s
- _wctime64_s
- _ctime32_s
- _wctime_s
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
- ctime64_s
- _ctime32_s
- _tctime32_s
- _ctime64_s
- _wctime_s
- _tctime_s
- _tctime64_s
- ctime_s
- ctime32_s
helpviewer_keywords:
- _wctime32_s function
- ctime64_s function
- _tctime64_s function
- _wctime_s function
- tctime_s function
- _wctime64_s function
- ctime_s function
- ctime32_s function
- _ctime64_s function
- tctime64_s function
- wctime64_s function
- wctime_s function
- _tctime_s function
- tctime32_s function
- wctime32_s function
- time, converting
- _ctime32_s function
- _tctime32_s function
ms.assetid: 36ac419a-8000-4389-9fd8-d78b747a009b
ms.openlocfilehash: a6329319be5d002c8f0a35ceb0258cb9081923f7
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73624406"
---
# <a name="ctime_s-_ctime32_s-_ctime64_s-_wctime_s-_wctime32_s-_wctime64_s"></a>ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s

Converta um valor temporal em uma cadeia de caracteres e ajuste as configurações de fuso horário local. Estas são versões de [ctime, _ctime64, _wctime, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t ctime_s(
   char* buffer,
   size_t numberOfElements,
   const time_t *sourceTime
);
errno_t _ctime32_s(
   char* buffer,
   size_t numberOfElements,
   const __time32_t *sourceTime
);
errno_t _ctime64_s(
   char* buffer,
   size_t numberOfElements,
   const __time64_t *sourceTime )
;
errno_t _wctime_s(
   wchar_t* buffer,
   size_t numberOfElements,
   const time_t *sourceTime
);
errno_t _wctime32_s(
   wchar_t* buffer,
   size_t numberOfElements,
   const __time32_t *sourceTime
);
errno_t _wctime64_s(
   wchar_t* buffer,
   size_t numberOfElements,
   const __time64_t *sourceTime
);
```

```cpp
template <size_t size>
errno_t _ctime32_s(
   char (&buffer)[size],
   const __time32_t *sourceTime
); // C++ only
template <size_t size>
errno_t _ctime64_s(
   char (&buffer)[size],
   const __time64_t *sourceTime
); // C++ only
template <size_t size>
errno_t _wctime32_s(
   wchar_t (&buffer)[size],
   const __time32_t *sourceTime
); // C++ only
template <size_t size>
errno_t _wctime64_s(
   wchar_t (&buffer)[size],
   const __time64_t *sourceTime
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Deve ser grande o suficiente para conter 26 caracteres. Um ponteiro para o resultado da cadeia de caracteres ou **NULL** se:

- *sourcetime* representa uma data anterior à meia-noite, 1º de janeiro de 1970, UTC.

- Se você usar **_ctime32_s** ou **_wctime32_s** e *sourcetime* representa uma data posterior a 23:59:59, 18 de janeiro de 2038, UTC.

- Se você usar **_ctime64_s** ou **_wctime64_s** e *sourcetime* representa uma data após 23:59:59, 31 de dezembro de 3000, UTC.

- Se você usar **_ctime_s** ou **_wctime_s**, essas funções serão wrappers para as funções anteriores. Consulte a seção Comentários.

*numberOfElements*<br/>
O tamanho do buffer.

*origemtime*<br/>
Ponteiro para a hora armazenada.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. Se houver uma falha devido a um parâmetro inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, um código de erro será retornado. Códigos de erro são definidos em ERRNO.H; para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-constants.md). Os códigos de erro reais gerados para cada condição de erro são mostrados na tabela a seguir.

## <a name="error-conditions"></a>Condições de Erro

|*buffer*|*numberOfElements*|*origemtime*|Valor de|Valor no *buffer*|
|--------------|------------------------|------------|------------|-----------------------|
|**NULL**|qualquer|qualquer|**EINVAL**|Não modificado|
|Not **NULL** (aponta para memória válida)|0|qualquer|**EINVAL**|Não modificado|
|Não **nulo**|0< tamanho < 26|qualquer|**EINVAL**|Cadeia de caracteres vazia|
|Não **nulo**|>= 26|NULL|**EINVAL**|Cadeia de caracteres vazia|
|Não **nulo**|>= 26|< 0|**EINVAL**|Cadeia de caracteres vazia|

## <a name="remarks"></a>Comentários

A função **ctime_s** converte um valor de hora armazenado como uma estrutura [time_t](../../c-runtime-library/standard-types.md) em uma cadeia de caracteres. O valor de *sourcetime* geralmente é obtido de uma chamada para [time](time-time32-time64.md), que retorna o número de segundos decorridos desde a meia-noite (00:00:00), 1 de janeiro de 1970, tempo universal coordenado (UTC). A cadeia de caracteres do valor retornado contém exatamente 26 caracteres e tem o formato:

`Wed Jan 02 02:03:55 1980\n\0`

Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha ('\n') e o caractere nulo ('\0') ocupam as duas últimas posições da cadeia de caracteres.

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Consulte as funções [time](time-time32-time64.md), [_ftime](ftime-ftime32-ftime64.md)e [localtime32_s](localtime-s-localtime32-s-localtime64-s.md) para obter informações sobre como configurar a hora local e a função [_tzset](tzset.md) para obter informações sobre como definir o ambiente de fuso horário e as variáveis globais.

**_wctime32_s** e **_wctime64_s** são a versão de caractere largo do **_ctime32_s** e do **_ctime64_s**; retornando um ponteiro para uma cadeia de caracteres largos. Caso contrário, **_ctime64_s**, **_wctime32_s**e **_wctime64_s** se comportam de forma idêntica ao **_ctime32_s**.

**ctime_s** é uma função embutida que é avaliada como **_ctime64_s** e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Isso fará com que o **ctime_s** seja avaliado para **_ctime32_s**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tctime_s**|**ctime_s**|**ctime_s**|**_wctime_s**|
|**_tctime32_s**|**_ctime32_s**|**_ctime32_s**|**_wctime32_s**|
|**_tctime64_s**|**_ctime64_s**|**_ctime64_s**|**_wctime64_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ctime_s**, **_ctime32_s**, **_ctime64_s**|\<time.h>|
|**_wctime_s**, **_wctime32_s**, **_wctime64_s**|\<time.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_wctime_s.c
// This program gets the current
// time in time_t form and then uses _wctime_s to
// display the time in string form.

#include <time.h>
#include <stdio.h>

#define SIZE 26

int main( void )
{
   time_t ltime;
   wchar_t buf[SIZE];
   errno_t err;

   time( &ltime );

   err = _wctime_s( buf, SIZE, &ltime );
   if (err != 0)
   {
      printf("Invalid Arguments for _wctime_s. Error Code: %d\n", err);
   }
   wprintf_s( L"The time is %s\n", buf );
}
```

```Output
The time is Fri Apr 25 13:03:39 2003
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
