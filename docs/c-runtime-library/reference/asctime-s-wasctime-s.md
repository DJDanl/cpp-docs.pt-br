---
title: asctime_s, _wasctime_s
ms.date: 11/04/2016
api_name:
- _wasctime_s
- asctime_s
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
ms.openlocfilehash: 0a40dad34d607bb52b062fc2cec163dfc8b62219
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943664"
---
# <a name="asctime_s-_wasctime_s"></a>asctime_s, _wasctime_s

Converta uma estrutura de tempo **TM** em uma cadeia de caracteres. Essas funções são versões de [asctime, wasctime](asctime-wasctime.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

*buffer*<br/>
Um ponteiro para um buffer para armazenar o resultado da cadeia de caracteres. Essa função assume um ponteiro para um local de memória válido com um tamanho especificado por *numberOfElements*.

*numberOfElements*<br/>
O tamanho do buffer usado para armazenar o resultado.

*tmSource*<br/>
Estrutura de hora/data. Essa função assume um ponteiro para um objeto **struct** **TM** válido.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se houver uma falha, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, o valor retornado será um código de erro. Códigos de erro são definidos em ERRNO.H. Para obter mais informações, consulte [Constantes errno](../../c-runtime-library/errno-constants.md). Os códigos de erro reais retornados para cada condição de erro são mostrados na tabela a seguir.

### <a name="error-conditions"></a>Condições de Erro

|*buffer*|*numberOfElements*|*tmSource*|Valor de|Valor no *buffer*|
|--------------|------------------------|----------|------------|-----------------------|
|**NULL**|Any|Any|**EINVAL**|Não modificado|
|Not **NULL** (aponta para memória válida)|0|Any|**EINVAL**|Não modificado|
|Não **nulo**|0< tamanho < 26|Any|**EINVAL**|Cadeia de caracteres vazia|
|Não **nulo**|>= 26|**NULL**|**EINVAL**|Cadeia de caracteres vazia|
|Não **nulo**|>= 26|Estrutura de hora inválida ou valores fora do intervalo para os componentes da hora|**EINVAL**|Cadeia de caracteres vazia|

> [!NOTE]
> As condições de erro para **wasctime_s** são semelhantes a **asctime_s** , com a exceção de que o limite de tamanho é medido em palavras.

## <a name="remarks"></a>Comentários

A função **asctime** converte uma hora armazenada como uma estrutura em uma cadeia de caracteres. O valor de *tmSource* geralmente é obtido de uma chamada para **gmtime** ou **localtime**. Ambas as funções podem ser usadas para preencher uma estrutura **TM** , conforme definido no tempo. T.

|membro timeptr|Valor|
|--------------------|-----------|
|**tm_hour**|Horas desde a meia-noite (0-23)|
|**tm_isdst**|Positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status de horário de verão for desconhecido. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão).|
|**tm_mday**|Dia do mês (1-31)|
|**tm_min**|Minutos após a hora (0-59)|
|**tm_mon**|Mês (0-11; Janeiro = 0)|
|**tm_sec**|Segundos após o minuto (0-59)|
|**tm_wday**|Dia da semana (0-6; Domingo = 0)|
|**tm_yday**|Dia do ano (0-365; 1 de janeiro = 0)|
|**tm_year**|Ano (ano atual menos 1900)|

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Consulte as funções [time, _time32, _time64](time-time32-time64.md), [_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md) e [localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md) para informações sobre a configuração da hora local e a função [_tzset](tzset.md) para informações sobre a definição do ambiente de fuso horário e variáveis globais.

O resultado da cadeia de caracteres produzido por **asctime_s** contém exatamente 26 caracteres e `Wed Jan 02 02:03:55 1980\n\0`tem o formulário. Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha e o caractere nulo ocupam as duas últimas posições da cadeia de caracteres. O valor passado como o segundo parâmetro deve ser pelo menos desse tamanho. Se for menor, um código de erro, **EINVAL**, será retornado.

**_wasctime_s** é uma versão de caractere largo do **asctime_s**. **_wasctime_s** e **asctime_s** se comportam de outra forma.

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

Se o ponteiro do buffer não for **nulo** e o ponteiro não apontar para um buffer válido, a função substituirá tudo o que estiver no local. Isso também pode resultar em uma violação de acesso.

O [estouro de buffer](/windows/win32/SecBP/avoiding-buffer-overruns) poderá ocorrer se o argumento de tamanho passado for maior que o tamanho real do buffer.

## <a name="example"></a>Exemplo

Esse programa coloca a hora do sistema no **aclock**inteiro longo, traduz-o na estrutura **Newtime** e, em seguida, converte-o em formato de cadeia de caracteres para saída, usando a função **asctime_s** .

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

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
