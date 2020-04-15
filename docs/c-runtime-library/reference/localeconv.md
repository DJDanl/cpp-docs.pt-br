---
title: localeconv
ms.date: 4/2/2020
api_name:
- localeconv
- _o_localeconv
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
- api-ms-win-crt-locale-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- localeconv
helpviewer_keywords:
- lconv type
- localeconv function
- locales, getting information on
ms.assetid: 7ecdb1f2-88f5-4037-a0e7-c754ab003660
ms.openlocfilehash: a617980d60b3a12c06b30aab6cd457792a1aa770
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342150"
---
# <a name="localeconv"></a>localeconv

Obtém informações detalhadas sobre configurações de localidade.

## <a name="syntax"></a>Sintaxe

```C
struct lconv *localeconv( void );
```

## <a name="return-value"></a>Valor retornado

**localeconv** retorna um ponteiro para um objeto preenchido de [lconv tipo struct](../../c-runtime-library/standard-types.md). Os valores contidos no objeto são copiados das configurações de localização no armazenamento local de thread e podem ser substituídos por chamadas subseqüentes para **localeconv**. As alterações feitas nos valores deste objeto não modificam as configurações de localização. Chamadas para [definir local](setlocale-wsetlocale.md) com valores de *categoria* de **LC_ALL,** **LC_MONETARY**ou **LC_NUMERIC** sobrepor o conteúdo da estrutura.

## <a name="remarks"></a>Comentários

A função **localeconv** obtém informações detalhadas sobre a formatação numérica para o local atual. Essas informações são armazenadas em uma estrutura do tipo **lconv**. A estrutura **lconv**, definida em LOCALE.H, contém os seguintes membros:

|Campo|Significado|
|-|-|
decimal_point.<br/>_W_decimal_point|Ponteiro para caractere de ponto decimal para quantidades não monetárias.
thousands_sep.<br/>_W_thousands_sep|Ponteiro para caractere que separa grupos de dígitos à esquerda do ponto decimal para quantidades não monetárias.
agrupamento|Ponteiro para um inteiro do tamanho de **um char**que contém o tamanho de cada grupo de dígitos em quantidades não monetárias.
int_curr_symbol,<br/>_W_int_curr_symbol|Ponteiro para símbolo de moeda internacional para locale atual. Os três primeiros caracteres especificam o símbolo de moeda alfabético internacional, conforme definido na norma *ISO 4217, Códigos para a Representação de Moedas e Fundos*. O quarto caractere (caractere nulo imediatamente anterior) separa o símbolo de moeda internacional da quantidade monetária.
currency_symbol.<br/>_W_currency_symbol|Pointer para o símbolo de moeda local para a localização atual.
mon_decimal_point<br/>_W_mon_decimal_point|Ponteiro para caractere de ponto decimal para quantidades monetárias.
mon_thousands_sep.<br/>_W_mon_thousands_sep|Ponteiro para separador para grupos de dígitos à esquerda da casa decimal em quantidades monetárias.
mon_grouping|Ponteiro para um inteiro do tamanho de **um char**que contém o tamanho de cada grupo de dígitos em quantidades monetárias.
positive_sign,<br/>_W_positive_sign|Cadeia de caracteres indicando o sinal para quantidades monetárias não negativas.
negative_sign,<br/>_W_negative_sign|Cadeia de caracteres indicando o sinal para quantidades monetárias negativas.
int_frac_digits|Número de dígitos à direita da vírgula decimal em quantidades monetárias internacionalmente formatadas.
frac_digits|Número de dígitos à direita da vírgula decimal em quantidades monetárias formatadas.
p_cs_precedes|Definido como 1 se o símbolo de moeda preceder o valor para a quantidade monetária formatada não negativa. Definido como 0 se o símbolo seguir o valor.
p_sep_by_space|Definido como 1 se o símbolo de moeda for separado por espaço do valor para a quantidade monetária formatada não negativa. Definido como 0 se não houver nenhuma separação por espaço.
N_cs_precedes|Definido como 1 se o símbolo de moeda preceder o valor para a quantidade monetária formatada negativa. Definido como 0 se o símbolo suceder o valor.
n_sep_by_space|Definido como 1 se o símbolo de moeda for separado por espaço do valor para a quantidade monetária formatada negativa. Definido como 0 se não houver nenhuma separação por espaço.
p_sign_posn|Posição do sinal positivo em quantidades monetárias formatadas não negativas.
n_sign_posn|Posição do sinal positivo em quantidades monetárias formatadas negativas.

Exceto conforme especificado, os membros da `char *` `wchar_t *` estrutura **lconv** que têm e versões são ponteiros para strings. Qualquer um desses que seja igual **a ""** (ou **L""** para **wchar_t** <strong>\*</strong>) é de comprimento zero ou não é suportado na localidade atual. Observe que **decimal_point** e **_W_decimal_point** são sempre suportados e de comprimento não zero.

Os membros **char** da estrutura são pequenos números não negativos, não caracteres. Qualquer um desses que seja igual a **CHAR_MAX** não terá suporte na localidade atual.

Os valores de **agrupamento** e **mon_grouping** são interpretados de acordo com as seguintes regras:

- **CHAR_MAX** - Não realize mais agrupamentos.

- 0 - Use o elemento anterior para cada um dos dígitos restantes.

- *n* - Número de dígitos que compõem o grupo atual. O próximo elemento é examinado para determinar o tamanho do próximo grupo de dígitos antes do grupo atual.

Os valores para **int_curr_symbol** são interpretados de acordo com as regras a seguir:

- Os três primeiros caracteres especificam o símbolo de moeda alfabético internacional, conforme definido na norma *ISO 4217, Códigos para a Representação de Moedas e Fundos*.

- O quarto caractere (caractere nulo imediatamente anterior) separa o símbolo de moeda internacional da quantidade monetária.

Os valores para **p_cs_precedes** e **n_cs_precedes** são interpretados de acordo com as regras a seguir (a regra para **n_cs_precedes** está entre parênteses):

- 0 - O símbolo da moeda segue o valor para o valor monetário formatado não negativo (negativo).

- 1 - O símbolo da moeda precede o valor para o valor monetário formatado não negativo (negativo).

Os valores para **p_sep_by_space** e **n_sep_by_space** são interpretados de acordo com as regras a seguir (a regra para **n_sep_by_space** está entre parênteses):

- 0 - O símbolo da moeda é separado de valor por espaço para valor monetário formatado não negativo (negativo).

- 1 - Não há separação de espaço entre símbolo de moeda e valor para valor monetário formatado não negativo (negativo).

Os valores para **p_sign_posn** e **n_sign_posn** são interpretados de acordo com as regras a seguir:

- 0 - Parênteses cercam quantidade e símbolo de moeda.

- 1 - A seqüência de sinais precede a quantidade e o símbolo da moeda.

- 2 - A seqüência de sinais segue quantidade e símbolo de moeda.

- 3 - A seqüência de sinais precede imediatamente o símbolo da moeda.

- 4 - A seqüência de sinais segue imediatamente o símbolo da moeda.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**localeconv**|\<locale.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Confira também

[Localidade](../../c-runtime-library/locale.md)<br/>
[Setlocale](../../preprocessor/setlocale.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
