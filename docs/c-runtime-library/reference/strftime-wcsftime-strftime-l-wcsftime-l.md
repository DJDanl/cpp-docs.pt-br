---
title: strftime, wcsftime, _strftime_l, _wcsftime_l
ms.date: 4/2/2020
api_name:
- strftime
- _wcsftime_l
- _strftime_l
- wcsftime
- _o__strftime_l
- _o__wcsftime_l
- _o_strftime
- _o_wcsftime
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
- _tcsftime
- strftime
- wcsftime
- _strftime_l
- _wcsftime_l
helpviewer_keywords:
- _strftime_l function
- strftime function
- tcsftime function
- _wcsftime_l function
- wcsftime function
- _tcsftime function
- time strings
ms.assetid: 6330ff20-4729-4c4a-82af-932915d893ea
ms.openlocfilehash: 5da2c128c54fd88bb874b360f5a966f17b14a935
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350006"
---
# <a name="strftime-wcsftime-_strftime_l-_wcsftime_l"></a>strftime, wcsftime, _strftime_l, _wcsftime_l

Formate uma cadeia de caracteres de hora.

## <a name="syntax"></a>Sintaxe

```C
size_t strftime(
   char *strDest,
   size_t maxsize,
   const char *format,
   const struct tm *timeptr
);
size_t _strftime_l(
   char *strDest,
   size_t maxsize,
   const char *format,
   const struct tm *timeptr,
   _locale_t locale
);
size_t wcsftime(
   wchar_t *strDest,
   size_t maxsize,
   const wchar_t *format,
   const struct tm *timeptr
);
size_t _wcsftime_l(
   wchar_t *strDest,
   size_t maxsize,
   const wchar_t *format,
   const struct tm *timeptr,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Strdest*<br/>
Cadeia de caracteres de saída.

*Maxsize*<br/>
Tamanho do *buffer strDest,* medido em caracteres **(char** ou **wchar_t).**

*format*<br/>
Cadeia de caracteres de controle de formato.

*timeptr*<br/>
estrutura de dados **tm.**

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

**strftime** retorna o número de caracteres colocados em *strDest* e **wcsftime** retorna o número correspondente de caracteres largos.

Se o número total de caracteres, incluindo o nulo final, for mais do que *maxsize,* tanto **o strftime** quanto o **wcsftime** return 0 e o conteúdo do *strDest* são indeterminados.

O número de caracteres em *strDest* é igual ao número de caracteres literais em *formato,* bem como quaisquer caracteres que podem ser adicionados ao *formato* através de códigos de formatação. A terminação nula de uma cadeia de caracteres não será contada no valor retornado.

## <a name="remarks"></a>Comentários

As funções **strftime** e **wcsftime** formatam o valor do tempo **tm** no *timeptr* de acordo com o argumento de *formato* fornecido e armazenam o resultado no *buffer strDest*. No máximo, os caracteres *maxsize* são colocados na seqüência. Para obter uma descrição dos campos na estrutura do *timeptr,* consulte [asctime](asctime-wasctime.md). **wcsftime** é o equivalente de amplo caráter **do strftime;** seu argumento de ponteiro de string aponta para uma seqüência de caracteres amplos. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Se *strDest,* *formato*ou *timeptr* for um ponteiro nulo, ou se a estrutura de dados **tm** endereçada pelo *timeptr* for inválida (por exemplo, se contiver valores fora do alcance para a hora ou data), ou se a seqüência de *formato* contiver um código de formatação inválido, o manipulador de parâmetros inválido sao invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna 0 e define **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsftime**|**strftime**|**strftime**|**wcsftime**|

O argumento de *formato* consiste em um ou mais códigos; como em **printf,** os códigos de formatação**%** são precedidos por um sinal percentual (). Os caracteres que **%** não começam são copiados inalterados para *strDest*. A **LC_TIME** categoria do local atual afeta a formatação de saída **do strftime**. (Para obter mais informações sobre **LC_TIME,** consulte [setlocale](setlocale-wsetlocale.md).) As funções **strftime** e **wcsftime** usam o local definido no momento. As **versões _strftime_l** e **_wcsftime_l** dessas funções são idênticas, exceto que eles tomam o local como parâmetro e usam isso em vez do local atualmente definido. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

As funções **strftime** suportam esses códigos de formatação:

|||
|-|-|
|Código|Cadeia de caracteres de substituição|
|**%a**|Nome abreviado durante a semana no local|
|**%A**|Nome completo do dia da semana no local|
|**%b**|Nome do mês abreviado no local|
|**%B**|Nome do mês completo no local|
|**%c**|Representação de data e hora apropriada para a localidade|
|**%C**|O ano dividido por 100 e truncado para um inteiro, como um número decimal (00-99)|
|**%d**|Dia do mês como número decimal (01 - 31)|
|**%D**|Equivalente a **%m/%d/%y**|
|**%e**|Dia do mês como um número decimal (1 - 31), onde dígitos únicos são precedidos por um espaço|
|**%F**|Equivalente a **%Y-%m-%d**|
|**%g**|Os últimos 2 dígitos do ano de semana ISO 8601 como um número decimal (00 - 99)|
|**%G**|O ano da semana ISO 8601 como um número decimal|
|**%h**|Nome do mês abreviado (equivalente a **%b**)|
|**%H**|Hora em formato 24 horas (00 - 23)|
|**%I**|Hora em formato de 12 horas (01 - 12)|
|**%j**|Dia do ano como um número decimal (001 - 366)|
|**%m**|Mês como número decimal (01 - 12)|
|**%M**|Minuto como um número decimal (00 - 59)|
|**%n**|Um caractere newline **(\n)**|
|**%p**|O local é A.M./P.M. Indicador para relógio de 12 horas|
|**%r**|O horário de 12 horas do local|
|**%R**|Equivalente a **%H:%M**|
|**%S**|Segundo como número decimal (00 - 59)|
|**%t**|Um caractere de guia horizontal **(\t)**|
|**%T**|Equivalente a **%H:%M:%S**, o formato de tempo ISO 8601|
|**%u**|ISO 8601 dia da semana como um número decimal (1 - 7; Segunda-feira é 1)|
|**%U**|Número da semana do ano como um número decimal (00 - 53), onde o primeiro domingo é o primeiro dia da semana 1|
|**%V**|Número da semana ISO 8601 como um número decimal (00 - 53)|
|**%w**|Dia da semana como um número decimal (0 - 6; Domingo é 0)|
|**%W**|Número da semana do ano como um número decimal (00 - 53), onde a primeira segunda-feira é o primeiro dia da semana 1|
|**%x**|Representação de data para o local|
|**%X**|Representação de tempo para o local|
|**%y**|Ano sem século, como número decimal (00 - 99)|
|**%Y**|Ano com século, como o número decimal|
|**%z**|O deslocamento da UTC no formato ISO 8601; sem caracteres se fuso horário é desconhecido|
|**%Z**|Nome do fuso horário do local ou abreviação de fuso horário, dependendo das configurações do registro; sem caracteres se fuso horário é desconhecido|
|**%%**|Símbolo de porcentagem|

Como na função **printf,** o **#** sinalizador pode prefixar qualquer código de formatação. Nesse caso, o significado do código de formatação é alterado da seguinte maneira.

|Código de formatação|Significado|
|-----------------|-------------|
|**%#a**, **%#A**, **%#b**, **%#B**, **%#g**, #h **%#G**, **%#n**, **%#p**, **%#h** **%#t #u**, **%#w**, **%#X**, **%#z**, **%#Z**, **%#t****%#%**|**#** bandeira é ignorada.|
|**%#c**|Longa representação de data e hora, apropriada para o local. Por exemplo: "Terça-feira, 14 de março de 1995, 12:41:29".|
|**%#x**|Representação de data longa, apropriada para o local. Por exemplo: "Terça-feira, 14 de março de 1995".|
|**%#d**, **%#D**, **%#e**, **%#F**, **%#Y** **%#H #I**, **%#j**, **%#m**, **%#M**, **%#R #r**, **%#I** **%#S**, **%#T**, **#U %#V**, **%#W**, **%#S** **%#y #Y** **%#V**|Remova os zeros ou os espaços principais (se houver).|

A ISO 8601 semana e ano de semana produzida por **%V**, **%g**, e **%G**, usa uma semana que começa na segunda-feira, onde a semana 1 é a semana que contém 4 de janeiro, que é a primeira semana que inclui pelo menos quatro dias do ano. Se a primeira segunda-feira do ano for a 2ª, 3ª ou 4ª, os dias anteriores fazem parte da última semana do ano anterior. Para esses dias, **%V** é substituído por 53, e **ambos %g** e **%G** são substituídos pelos dígitos do ano anterior.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strftime**|\<time.h>|
|**wcsftime**|\<time.h> ou \<wchar.h>|
|**_strftime_l**|\<time.h>|
|**_wcsftime_l**|\<time.h> ou \<wchar.h>|

As funções **_strftime_l** e **_wcsftime_l** são específicas da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [time](time-time32-time64.md).

## <a name="see-also"></a>Confira também

[Localidade](../../c-runtime-library/locale.md) <br/>
[Gerenciamento de tempo](../../c-runtime-library/time-management.md) <br/>
[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md) <br/>
[localeconv](localeconv.md) <br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md) <br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md) <br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
