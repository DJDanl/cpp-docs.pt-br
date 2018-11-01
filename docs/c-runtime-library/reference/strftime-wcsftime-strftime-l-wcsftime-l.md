---
title: strftime, wcsftime, _strftime_l, _wcsftime_l
ms.date: 03/22/2018
apiname:
- strftime
- _wcsftime_l
- _strftime_l
- wcsftime
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
ms.openlocfilehash: 932a7827ef61a5e111f86f8bc44291827843b76e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505658"
---
# <a name="strftime-wcsftime-strftimel-wcsftimel"></a>strftime, wcsftime, _strftime_l, _wcsftime_l

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

*strDest*<br/>
Cadeia de caracteres de saída.

*tamanho máximo*<br/>
Tamanho do *strDest* buffer, medido em caracteres (**char** ou **wchar_t**).

*format*<br/>
Cadeia de caracteres de controle de formato.

*timeptr*<br/>
**TM** estrutura de dados.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**STRFTIME** retorna o número de caracteres colocados em *strDest* e **wcsftime** retorna o número correspondente de caracteres largos.

Se o número total de caracteres, incluindo o nulo de terminação, é mais de *maxsize*, ambos **strftime** e **wcsftime** retornam 0 e o conteúdo de  *strDest* serão indeterminados.

O número de caracteres em *strDest* é igual ao número de caracteres literais em *formato* , bem como quaisquer caracteres que podem ser adicionados ao *formato* por meio de códigos de formatação. A terminação nula de uma cadeia de caracteres não será contada no valor retornado.

## <a name="remarks"></a>Comentários

O **strftime** e **wcsftime** formato de funções a **tm** tempo valor no *timeptr* acordo com os fornecidos  *formato* argumento e armazenam o resultado no buffer *strDest*. No máximo, *maxsize* caracteres são colocados na cadeia de caracteres. Para obter uma descrição dos campos na *timeptr* estrutura, consulte [asctime](asctime-wasctime.md). **wcsftime** é o equivalente de caractere largo de **strftime**; seu argumento de ponteiro de cadeia de caracteres aponta para uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Essa função valida seus parâmetros. Se *strDest*, *formato*, ou *timeptr* é um ponteiro nulo, ou se o **tm** estrutura de dados é tratado por *timeptr* é inválido (por exemplo, se ele contiver valores fora do intervalo para a hora ou data), ou se o *formato* cadeia de caracteres contém um código de formatação inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará 0 e definirá **errno** à **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcsftime**|**strftime**|**strftime**|**wcsftime**|

O *formato* argumento consiste em um ou mais códigos, como em **printf**, os códigos de formatação são precedidos por um sinal de porcentagem (**%**). Caracteres que não começam com **%** são copiados inalterado para *strDest*. O **LC_TIME** categoria da localidade atual afeta a formatação de saída de **strftime**. (Para obter mais informações sobre **LC_TIME**, consulte [setlocale](setlocale-wsetlocale.md).) O **strftime** e **wcsftime** funções usam atualmente definida localidade. O **strftime_l** e **wcsftime_l** versões dessas funções são idênticas, exceto que eles usam a localidade como um parâmetro e usá-lo em vez de definida atualmente localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O **strftime** funções dão suporte a esses códigos de formatação:

|||
|-|-|
|Código|Cadeia de caracteres de substituição|
|**%a**|Nome abreviado do dia na localidade|
|**%A**|Nome completo de dia da semana na localidade|
|**%b**|Nome abreviado do mês na localidade|
|**%B**|Nome completo do mês na localidade|
|**%c**|Representação de data e hora apropriada para a localidade|
|**%C**|O ano, dividido por 100 e truncado para um inteiro, como um número decimal (00−99)|
|**%d**|Dia do mês como um número decimal (01 a 31)|
|**%D**|Equivalente a **%m/%d/%y**|
|**%e**|Dia do mês como um número decimal (1 a 31), em que os dígitos únicos são precedidos por um espaço|
|**%F**|Equivalente a **%Y %m-%d**|
|**%g**|Os 2 últimos dígitos do ano ISO 8601 com base em semana como um número decimal (00 - 99)|
|**%G**|O ISO 8601 semana com base no ano como um número decimal|
|**%h**|Nome abreviado do mês (equivalente a **%b**)|
|**%H**|Hora em formato de 24 horas (00 – 23)|
|**%I**|Hora em formato de 12 horas (01 a 12)|
|**%j**|Dia do ano como um número decimal (001-366)|
|**%m**|Mês como um número decimal (01-12)|
|**%M**|Minuto como um número decimal (00 – 59)|
|**%n**|Um caractere de nova linha (**\n**)|
|**%p**|AM/PM da localidade. Indicador para relógio de 12 horas|
|**%r**|Tempo de relógio de 12 horas da localidade|
|**%R**|Equivalente a **% h:%m %M**|
|**%S**|Segundo como um número decimal (00 – 59)|
|**%t**|Um caractere de tabulação horizontal (**\t**)|
|**%T**|Equivalente a **% h:%m: %S**, o formato de hora ISO 8601|
|**%u**|ISO 8601 dia da semana como um número decimal (1 a 7; Segunda-feira é 1)|
|**%U**|Número da semana do ano como um número decimal (00 – 53), em que o primeiro domingo é o primeiro dia da semana 1|
|**%V**|Número da semana ISO 8601 como um número decimal (00 – 53)|
|**%w**|Dia da semana como um número decimal (0 – 6; Domingo é 0)|
|**%W**|Número da semana do ano como um número decimal (00 – 53), em que a primeira segunda-feira é o primeiro dia da semana 1|
|**%x**|Representação de data para a localidade|
|**%X**|Representação de hora para a localidade|
|**%y**|Ano sem século, como um número decimal (00 - 99)|
|**%Y**|Ano com século, como o número decimal|
|**%z**|O deslocamento do UTC no formato ISO 8601. Nenhum caractere se o fuso horário é desconhecido|
|**%Z**|Nome do fuso horário a localidade ou a abreviação de fuso horário, dependendo das configurações do registro; Nenhum caractere se o fuso horário é desconhecido|
|**%%**|Símbolo de porcentagem|

Como mostra a **printf** função, o **#** sinalizador pode ser prefixo em qualquer código de formatação. Nesse caso, o significado do código de formatação é alterado da seguinte maneira.

|Código de formatação|Significado|
|-----------------|-------------|
|**% #a**, **%#A**, **%#b**, **%#B**, **%#g**, **%#G**, **%#h**, **%#n**, **%#p**, **%#t**, **%#u**, **%#w**, **%#x10** , **%#z**, **%#Z**, **%#%**|**#** sinalizador é ignorado.|
|**%#c**|Longa data e hora representação, apropriada para a localidade. Por exemplo: "Terça-feira, 14 de março de 1995, 12:41:29".|
|**%#x10**|Representação de data por extenso, apropriada à localidade. Por exemplo: "Terça-feira, 14 de março de 1995".|
|**%#d**, **%#D**, **%#e**, **%#F**, **%#H**, **% #I**, **%#j**, **%#m**, **%#M**, **%#r**, **%#R**, **%#S**, **%#T** , **%#U**, **%#V**, **%#W**, **%#y**, **%#Y**|Remova os zeros à esquerda ou espaços (se houver).|

A semana com base no ano e semana ISO 8601 produzido pelo **%V**, **%g**, e **%G**, usa uma semana em que começa na segunda-feira, onde semana 1 é a que contém 4 de janeiro, que é o primeiro semana que inclui pelo menos quatro dias do ano. Se a primeira segunda-feira do ano é o 2º, 3 ou 4 de maio, os dias anteriores fazem parte da última semana do ano anterior. Para esses dias **%V** é substituído pelo 53 e ambos **%g** e **%G** são substituídos por dígitos do ano anterior.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strftime**|\<time.h>|
|**wcsftime**|\<time.h> ou \<wchar.h>|
|**_strftime_l**|\<time.h>|
|**_wcsftime_l**|\<time.h> ou \<wchar.h>|

O **strftime_l** e **wcsftime_l** funções são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [time](time-time32-time64.md).

## <a name="see-also"></a>Consulte também

[Localidade](../../c-runtime-library/locale.md) <br/>
[Gerenciamento de Tempo](../../c-runtime-library/time-management.md) <br/>
[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md) <br/>
[localeconv](localeconv.md) <br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md) <br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md) <br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
