---
title: localeconv | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- localeconv
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
apitype: DLLExport
f1_keywords:
- localeconv
dev_langs:
- C++
helpviewer_keywords:
- lconv type
- localeconv function
- locales, getting information on
ms.assetid: 7ecdb1f2-88f5-4037-a0e7-c754ab003660
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9e93e21505a661deb470e4b31c8807ef5133a774
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="localeconv"></a>localeconv
Obtém informações detalhadas sobre configurações de localidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct lconv *localeconv( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `localeconv` retorna um ponteiro para um objeto preenchido do tipo [struct lconv](../../c-runtime-library/standard-types.md). Os valores contidos no objeto são copiados de configurações de localidade no armazenamento local de thread e pode ser substituídos por chamadas subsequentes para `localeconv`. As alterações feitas aos valores neste objeto não modifique as configurações de localidade. Chamadas para [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) com valores `category` de `LC_ALL`, `LC_MONETARY` ou `LC_NUMERIC` substituem os conteúdos da estrutura.  
  
## <a name="remarks"></a>Comentários  
 A função `localeconv` obtém informações detalhadas sobre a formatação numérica da localidade atual. Essas informações são armazenadas em uma estrutura de tipo `lconv`. O `lconv` estrutura, definido na localidade. H, contém os seguintes membros:  
  
 `char *decimal_point, wchar_t *_W_decimal_point`  
 Caractere de vírgula decimal para quantidades não monetárias.  
  
 `char *thousands_sep, wchar_t *_W_thousands_sep`  
 Caractere que separa grupos de dígitos à esquerda da vírgula decimal para quantidades não monetárias.  
  
 `char *grouping`  
 Ponteiro para um `char`-tamanho inteiro que contém o tamanho de cada grupo de dígitos em quantidades monetárias.  
  
 `char *int_curr_symbol, wchar_t *_W_int_curr_symbol`  
 Símbolo de moeda internacional para a localidade atual. Os três primeiros caracteres especificam o símbolo de moeda alfabético internacional, conforme definido na norma *ISO 4217, Códigos para a Representação de Moedas e Fundos*. O quarto caractere (caractere nulo imediatamente anterior) separa o símbolo de moeda internacional da quantidade monetária.  
  
 `char *currency_symbol, wchar_t *_W_currency_symbol`  
 Símbolo de moeda local para a localidade atual.  
  
 `char *mon_decimal_point, wchar_t *_W_mon_decimal_point`  
 Caractere de vírgula decimal para quantidades monetárias.  
  
 `char *mon_thousands_sep, wchar_t *_W_mon_thousands_sep`  
 Separador para grupos de dígitos à esquerda da casa decimal em quantidades monetárias.  
  
 `char *mon_grouping`  
 Ponteiro para um `char`-tamanho inteiro que contém o tamanho de cada grupo de dígitos em quantidades monetárias.  
  
 `char *positive_sign, wchar_t *_W_positive_sign`  
 Cadeia de caracteres indicando o sinal para quantidades monetárias não negativas.  
  
 `char *negative_sign, wchar_t *_W_negative_sign`  
 Cadeia de caracteres indicando o sinal para quantidades monetárias negativas.  
  
 `char int_frac_digits`  
 Número de dígitos à direita da vírgula decimal em quantidades monetárias internacionalmente formatadas.  
  
 `char frac_digits`  
 Número de dígitos à direita da vírgula decimal em quantidades monetárias formatadas.  
  
 `char p_cs_precedes`  
 Definido como 1 se o símbolo de moeda preceder o valor para a quantidade monetária formatada não negativa. Definido como 0 se o símbolo seguir o valor.  
  
 `char p_sep_by_space`  
 Definido como 1 se o símbolo de moeda for separado por espaço do valor para a quantidade monetária formatada não negativa. Definido como 0 se não houver nenhuma separação por espaço.  
  
 `char n_cs_precedes`  
 Definido como 1 se o símbolo de moeda preceder o valor para a quantidade monetária formatada negativa. Definido como 0 se o símbolo suceder o valor.  
  
 `char n_sep_by_space`  
 Definido como 1 se o símbolo de moeda for separado por espaço do valor para a quantidade monetária formatada negativa. Definido como 0 se não houver nenhuma separação por espaço.  
  
 `char p_sign_posn`  
 Posição do sinal positivo em quantidades monetárias formatadas não negativas.  
  
 `char n_sign_posn`  
 Posição do sinal positivo em quantidades monetárias formatadas negativas.  
  
Exceto como membros especificados, o `lconv` estrutura que têm `char *` e `wchar_t *` versões são ponteiros para cadeias de caracteres. Qualquer um desses que seja igual a `""` (ou `L""` para `wchar_t *`) terá comprimento igual a zero ou não terá suporte na localidade atual. Observe que `decimal_point` e `_W_decimal_point` sempre terão suporte e comprimento diferente de zero.  
  
Os membros `char` da estrutura são números pequenos não negativos e não caracteres. Qualquer um desses é igual a `CHAR_MAX` não há suporte para a localidade atual.  
  
Os valores de `grouping` e `mon_grouping` são interpretados de acordo com as regras a seguir:  
  
- `CHAR_MAX` -Não execute qualquer agrupamento adicional.  
  
- 0 - use o elemento anterior para cada um dos dígitos restantes.  
  
- *n* -Número de dígitos que compõem o grupo atual. O próximo elemento é examinado para determinar o tamanho do próximo grupo de dígitos antes do grupo atual.  
  
Os valores para `int_curr_symbol` são interpretados de acordo com as regras a seguir:  
  
-   Os três primeiros caracteres especificam o símbolo de moeda alfabético internacional, conforme definido na norma *ISO 4217, Códigos para a Representação de Moedas e Fundos*.  
  
-   O quarto caractere (caractere nulo imediatamente anterior) separa o símbolo de moeda internacional da quantidade monetária.  
  
Os valores para `p_cs_precedes` e `n_cs_precedes` são interpretados de acordo com as regras a seguir (o `n_cs_precedes` regra está entre parênteses):  
  
- 0 - símbolo de moeda segue o valor não negativo (negativo) formatado valor monetário.  
  
- 1 - símbolo de moeda precede o valor não negativo (negativo) formatado valor monetário.  
  
Os valores para `p_sep_by_space` e `n_sep_by_space` são interpretados de acordo com as regras a seguir (o `n_sep_by_space` regra está entre parênteses):  
  
- 0 - símbolo de moeda é separado do valor de espaço para não-negativo (negativo) formatado valor monetário.  
  
- 1 - não há separação nenhum espaço entre o símbolo de moeda e o valor não negativo (negativo) formatado valor monetário.  
  
Os valores para `p_sign_posn` e `n_sign_posn` são interpretados de acordo com as regras a seguir:  
  
- 0 - parênteses envolvem o símbolo de moeda e quantidade.  
  
- 1 - cadeia de caracteres de sign precede o símbolo de moeda e quantidade.  
  
- 2 - cadeia de caracteres de entrada segue o símbolo de moeda e quantidade.  
  
- 3 - cadeia de caracteres de entrada precede o símbolo de moeda.  
  
- 4 - sinal de cadeia de caracteres imediatamente símbolo de moeda da seguinte maneira.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`localeconv`|\<locale.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [setlocale](../../preprocessor/setlocale.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)