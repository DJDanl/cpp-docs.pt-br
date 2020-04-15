---
title: asctime_s, _wasctime_s
ms.date: 4/2/2020
api_name:
- _wasctime_s
- asctime_s
- _o__wasctime_s
- _o_asctime_s
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
- asctime_s
- _wasctime_s
- _tasctime_s
helpviewer_keywords:
- tasctime_s function
- _tasctime_s function
- time structure conversion
- wasctime_s function
- time, converting
- _wasctime_s function
- asctime_s function
ms.assetid: 17ad9b2b-a459-465d-976a-42822897688a
ms.openlocfilehash: 52391eb1237e4c1d7ef320dacd211b603a21ab8b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81334219"
---
# <a name="asctime_s-_wasctime_s"></a>asctime_s, _wasctime_s

Converta uma estrutura de tempo **tm** em uma seqüência de caracteres. Essas funções são versões de [asctime, wasctime](asctime-wasctime.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t asctime_s(
   char* buffer,
   size_t numberOfElements,
   const struct tm *tmSource
);
errno_t _wasctime_s(
   wchar_t* buffer,
   size_t numberOfElements
   const struct tm *tmSource
);
template <size_t size>
errno_t asctime_s(
   char (&buffer)[size],
   const struct tm *tmSource
); // C++ only
template <size_t size>
errno_t _wasctime_s(
   wchar_t (&buffer)[size],
   const struct tm *tmSource
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Buffer*<br/>
Um ponteiro para um buffer para armazenar o resultado da seqüência de caracteres. Esta função assume um ponteiro para um local de memória válido com um tamanho especificado por *numberOfElements*.

*Numberofelements*<br/>
O tamanho do buffer usado para armazenar o resultado.

*tmFonte*<br/>
Estrutura de hora/data. Esta função assume um ponteiro para um objeto **tm** **de estrutura** válida.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido. Se houver uma falha, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, o valor retornado será um código de erro. Códigos de erro são definidos em ERRNO.H. Para obter mais informações, consulte [Constantes errno](../../c-runtime-library/errno-constants.md). Os códigos de erro reais retornados para cada condição de erro são mostrados na tabela a seguir.

### <a name="error-conditions"></a>Condições de erro

|*Buffer*|*Numberofelements*|*tmFonte*|Retorno|Valor em *buffer*|
|--------------|------------------------|----------|------------|-----------------------|
|**NULO**|Qualquer|Qualquer|**Einval**|Não modificado|
|Não **NULL** (pontos para memória válida)|0|Qualquer|**Einval**|Não modificado|
|Não **nulo**|0< tamanho < 26|Qualquer|**Einval**|cadeia de caracteres vazia|
|Não **nulo**|>= 26|**NULO**|**Einval**|cadeia de caracteres vazia|
|Não **nulo**|>= 26|Estrutura de hora inválida ou valores fora do intervalo para os componentes da hora|**Einval**|cadeia de caracteres vazia|

> [!NOTE]
> As condições de erro para **wasctime_s** são semelhantes às **asctime_s** com a exceção de que o limite de tamanho é medido em palavras.

## <a name="remarks"></a>Comentários

A função **asctime** converte um tempo armazenado como uma estrutura para uma seqüência de caracteres. O valor *tmSource* geralmente é obtido a partir de uma chamada para **gmtime** ou **localtime**. Ambas as funções podem ser usadas para preencher uma estrutura **tm,** conforme definido em TIME. H.

|membro timeptr|Valor|
|--------------------|-----------|
|**tm_hour**|Horários desde a meia-noite (0-23)|
|**Tm_isdst**|Positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status de horário de verão for desconhecido. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão).|
|**tm_mday**|Dia do mês (1-31)|
|**tm_min**|Minutos após hora (0-59)|
|**tm_mon**|Mês (0-11; Janeiro = 0)|
|**tm_sec**|Segundos após minuto (0-59)|
|**tm_wday**|Dia da semana (0-6; Domingo = 0)|
|**tm_yday**|Dia do ano (0-365; Janeiro 1 = 0)|
|**tm_year**|Ano (ano atual menos 1900)|

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Consulte as funções [time, _time32, _time64](time-time32-time64.md), [_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md) e [localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md) para informações sobre a configuração da hora local e a função [_tzset](tzset.md) para informações sobre a definição do ambiente de fuso horário e variáveis globais.

O resultado da **asctime_s** seqüência produzida por asctime_s `Wed Jan 02 02:03:55 1980\n\0`contém exatamente 26 caracteres e tem a forma . Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha e o caractere nulo ocupam as duas últimas posições da cadeia de caracteres. O valor passado como o segundo parâmetro deve ser pelo menos desse tamanho. Se for menor, um código de erro, **EINVAL,** será devolvido.

**_wasctime_s** é uma versão de grande caráter de **asctime_s**. **_wasctime_s** e **asctime_s** se comportam de forma idêntica.

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tasctime_s**|**asctime_s**|**asctime_s**|**_wasctime_s**|

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**asctime_s**|\<time.h>|
|**_wasctime_s**|\<time.h> ou \<wchar.h>|

## <a name="security"></a>Segurança

Se o ponteiro de buffer não for **NULO** e o ponteiro não apontar para um buffer válido, a função substituirá o que estiver no local. Isso também pode resultar em uma violação de acesso.

O [estouro de buffer](/windows/win32/SecBP/avoiding-buffer-overruns) poderá ocorrer se o argumento de tamanho passado for maior que o tamanho real do buffer.

## <a name="example"></a>Exemplo

Este programa coloca o tempo do sistema no **relógio**inteiro longo, traduz-o para a estrutura **newtime** e, em seguida, converte-o em forma de corda para saída, usando a função **asctime_s.**

```C
// crt_asctime_s.c
#include <time.h>
#include <stdio.h>

struct tm newtime;
__time32_t aclock;

int main( void )
{
   char buffer[32];
   errno_t errNum;
   _time32( &aclock );   // Get time in seconds.
   _localtime32_s( &newtime, &aclock );   // Convert time to struct tm form.

   // Print local time as a string.

   errNum = asctime_s(buffer, 32, &newtime);
   if (errNum)
   {
       printf("Error code: %d", (int)errNum);
       return 1;
   }
   printf( "Current date and time: %s", buffer );
   return 0;
}
```

```Output
Current date and time: Wed May 14 15:30:17 2003
```

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
