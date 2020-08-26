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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 36a84c5de41f3358adbcba42010ed8e6f3c83939
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846570"
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

### <a name="parameters"></a>parâmetros

*strDest*<br/>
Cadeia de caracteres de saída.

*MaxSize*<br/>
Tamanho do buffer *strDest* , medido em caracteres ( **`char`** ou **`wchar_t`** ).

*format*<br/>
Cadeia de caracteres de controle de formato.

*timeptr*<br/>
estrutura de dados **TM** .

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor Retornado

**strftime** retorna o número de caracteres colocados em *strDest* e **wcsftime** retorna o número correspondente de caracteres largos.

Se o número total de caracteres, incluindo o nulo de terminação, for maior que *MaxSize*, **strftime** e **wcsftime** retornarão 0 e o conteúdo de *strDest* será indeterminado.

O número de caracteres em *strDest* é igual ao número de caracteres literais no *formato* , bem como a qualquer caractere que possa ser adicionado ao *formato* por meio de códigos de formatação. A terminação nula de uma cadeia de caracteres não será contada no valor retornado.

## <a name="remarks"></a>Comentários

As funções **strftime** e **wcsftime** formatam o valor de hora **TM** em *timeptr* de acordo com o argumento de *formato* fornecido e armazenam o resultado no buffer *strDest*. No máximo, os caracteres *MaxSize* são colocados na cadeia de caracteres. Para obter uma descrição dos campos na estrutura *timeptr* , consulte [asctime](asctime-wasctime.md). **wcsftime** é o equivalente de caractere largo de **strftime**; seu argumento de ponteiro de cadeia de caracteres aponta para uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Se *strDest*, *Format*ou *timeptr* for um ponteiro NULL ou se a estrutura de dados **TM** endereçada por *timeptr* for inválida (por exemplo, se ela contiver valores fora do intervalo para a hora ou data) ou se a cadeia de caracteres de *formato* contiver um código de formatação inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará 0 e definirá **errno** como **EINVAL**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsftime**|**strftime**|**strftime**|**wcsftime**|

O argumento de *formato* consiste em um ou mais códigos; como na **printf**, os códigos de formatação são precedidos por um sinal de porcentagem ( **%** ). Os caracteres que não começam com **%** são copiados inalterados para *strDest*. A categoria de **LC_TIME** da localidade atual afeta a formatação de saída de **strftime**. (Para obter mais informações sobre **LC_TIME**, consulte [setlocale](setlocale-wsetlocale.md).) As funções **strftime** e **wcsftime** usam a localidade definida no momento. As versões **_strftime_l** e **_wcsftime_l** dessas funções são idênticas, exceto pelo fato de que elas usam a localidade como um parâmetro e usam isso em vez da localidade definida no momento. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

As funções **strftime** dão suporte a esses códigos de formatação:

|Código|Cadeia de caracteres de substituição|
|-|-|
|**% a**|Nome abreviado do dia da semana na localidade|
|**% A**|Nome completo do dia da semana na localidade|
|**% b**|Nome do mês abreviado na localidade|
|**% B**|Nome completo do mês na localidade|
|**% c**|Representação de data e hora apropriada para a localidade|
|**% C**|O ano dividido por 100 e truncado para um inteiro, como um número decimal (00 − 99)|
|**% d**|Dia do mês como um número decimal (01-31)|
|**% D**|Equivalente a **% m/% d/% y**|
|**% e**|Dia do mês como um número decimal (1-31), em que os dígitos únicos são precedidos por um espaço|
|**% F**|Equivalente a **% Y-% m-% d**|
|**% g**|Os últimos 2 dígitos do ano baseado em semana 8601 ISO como um número decimal (00-99)|
|**% G**|O ano baseado em ISO 8601 Week como um número decimal|
|**% h**|Nome do mês abreviado (equivalente a **% b**)|
|**% H**|Hora no formato de 24 horas (00-23)|
|**% I**|Hora no formato de 12 horas (01-12)|
|**% j**|Dia do ano como um número decimal (001-366)|
|**% m**|Mês como um número decimal (01-12)|
|**% M**|Minuto como um número decimal (00-59)|
|**% n**|Um caractere de nova linha (**\n**)|
|**% p**|/P.M. da localidade Indicador para relógio de 12 horas|
|**% r**|A hora do relógio de 12 horas da localidade|
|**% R**|Equivalente a **% H:%M**|
|**% S**|Segundo como um número decimal (00-59)|
|**% t**|Um caractere de tabulação horizontal (**\t**)|
|**% T**|Equivalente a **% H:%M:% S**, o formato de tempo ISO 8601|
|**% u**|Dia da semana ISO 8601 como um número decimal (1-7; Segunda-feira é 1)|
|**% U**|Número da semana do ano como um número decimal (00-53), em que o primeiro domingo é o primeiro dia da semana 1|
|**% V**|Número da semana ISO 8601 como um número decimal (00-53)|
|**% w**|Dia da semana como um número decimal (0-6; Domingo é 0)|
|**% W**|Número da semana do ano como um número decimal (00-53), em que a primeira segunda-feira é o primeiro dia da semana 1|
|**% x**|Representação de data para a localidade|
|**% X**|Representação de tempo para a localidade|
|**% y**|Ano sem século, como número decimal (00-99)|
|**% Y**|Ano com século, como o número decimal|
|**% z**|O deslocamento do UTC no formato ISO 8601; nenhum caractere se o fuso horário for desconhecido|
|**% Z**|O nome do fuso horário ou a abreviação de fuso horário da localidade, dependendo das configurações do registro; nenhum caractere se o fuso horário for desconhecido|
|**%%**|Símbolo de porcentagem|

Como na função **printf** , o **#** sinalizador pode prefixar qualquer código de formatação. Nesse caso, o significado do código de formatação é alterado da seguinte maneira.

|Código de formatação|Significado|
|-----------------|-------------|
|**% #a**, **% #A**, **% #b**, **% #B**, **% #g**, **% #G**, **% #h**, **% #n**, **% #p**, **% #t**, **% #u**, **% #w**, **% #X**, **% #z**, **% #Z**, **%#%**|**#** sinalizador ignorado.|
|**% #c**|Representação de data e hora por extenso, apropriada para a localidade. Por exemplo: "Terça-feira, 14 de março de 1995, 12:41:29".|
|**% #x**|Representação de data por extenso, apropriada para a localidade. Por exemplo: "Terça-feira, 14 de março de 1995".|
|**% #d**, **% #D**, **% #e**, **% #F**, **% #H**, **% #I**, **% #j**, **% #m**, **% #M**, **% #r**, **% #R**, **% #S**, **% #T**, **% #U**, **% #V**, **% #W**, **% #y**, **% #Y**|Remover zeros à esquerda ou espaços (se houver).|

A semana ISO 8601 e o ano baseado em semana produzidos por **% V**, **% g**e **% g**usam uma semana que começa na segunda-feira, em que a semana 1 é a semana que contém 1º de Janeiro, que é a primeira semana que inclui pelo menos quatro dias do ano. Se a primeira segunda-feira do ano for a 2ª, 3ª ou 4ª, os dias anteriores serão parte da última semana do ano anterior. Para esses dias, **% V** é substituído por 53, e **% g** e **% g** são substituídos pelos dígitos do ano anterior.

> [!NOTE]
> Ao usar uma das `strftime` funções com um `tm` ponteiro retornado de `gmtime` , os valores impressos por meio dos `%Z` `%z` especificadores e não serão precisos. Isso ocorre porque a `tm` struct, conforme especificado pelo padrão C, não contém as informações de nome de fuso horário nem deslocamento. Em vez disso, as informações de fuso horário são populadas por meio das variáveis globais [ `_timezone` e `_dstbias` ](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).

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
[Manipulação de cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md) <br/>
[localeconv](localeconv.md) <br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md) <br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md) <br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
