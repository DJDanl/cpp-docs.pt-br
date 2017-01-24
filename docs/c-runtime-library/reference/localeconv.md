---
title: "localeconv | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "localeconv"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "localeconv"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Tipo lconv"
  - "Função localeconv"
  - "localidades, obtendo informações sobre"
ms.assetid: 7ecdb1f2-88f5-4037-a0e7-c754ab003660
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# localeconv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém informações detalhadas sobre as configurações de localidade.  
  
## Sintaxe  
  
```  
  
struct lconv *localeconv( void );  
```  
  
## Valor de retorno  
 `localeconv` retorna um ponteiro para um objeto preenchido do tipo [lconv da estrutura](../../c-runtime-library/standard-types.md).  Os valores contidos no objeto podem ser substituídos por chamadas subsequentes a `localeconv` e não modifica diretamente o objeto.  As chamadas a [setlocale](../Topic/setlocale,%20_wsetlocale.md) com valores de `category` de `LC_ALL`, de `LC_MONETARY`, ou de `LC_NUMERIC` substituir o conteúdo da estrutura.  
  
## Comentários  
 A função de `localeconv` obtém informações detalhadas sobre a formatação numérica da localidade atual.  Essas informações são armazenadas em uma estrutura de tipo **lconv**.  A estrutura de **lconv** , definida em LOCALE.H, contém os seguintes membros:  
  
 `char *decimal_point, wchar_t *_W_decimal_point`  
 Caractere de ponto decimal para quantidades nonmonetary.  
  
 `char *thousands_sep, wchar_t *_W_thousands_sep`  
 Caractere que separa grupos de dígitos à esquerda do ponto decimal para quantidades nonmonetary.  
  
 `char *grouping`  
 Tamanho de cada grupo de dígitos em volumes nonmonetary.  
  
 `char *int_curr_symbol, wchar_t *_W_int_curr_symbol`  
 Símbolo de moeda internacional da localidade atual.  Os três primeiros caracteres especificam o símbolo de moeda internacional alfabético conforme definido *no ISO 4217 para a representação códigos de moeda e os fundos* padrão.  O quarto caractere \(imediatamente antes do caractere nulo\) separar o símbolo de moeda internacional da quantidade de moeda.  
  
 `char *currency_symbol, wchar_t *_W_currency_symbol`  
 Símbolo de moeda local para a localidade atual.  
  
 `char *mon_decimal_point, wchar_t *_W_mon_decimal_point`  
 Caractere de ponto decimal para quantidades monetárias.  
  
 `char *mon_thousands_sep, wchar_t *_W_mon_thousands_sep`  
 Separador para grupos de dígitos à esquerda da casa decimal em volumes monetárias.  
  
 `char *mon_grouping`  
 Tamanho de cada grupo de dígitos em volumes monetárias.  
  
 `char *positive_sign, wchar_t *_W_positive_sign`  
 Cadeia de caracteres que indica o sinal para quantidades monetárias não negativo.  
  
 `char *negative_sign, wchar_t *_W_negative_sign`  
 Cadeia de caracteres que indica o sinal para quantidades monetárias negativas.  
  
 `char int_frac_digits`  
 Número de dígitos à direita da casa decimal em volumes monetárias internacional formatados.  
  
 `char frac_digits`  
 Número de dígitos à direita da casa decimal em volumes monetárias formatados.  
  
 `char p_cs_precedes`  
 Defina como 1 se o símbolo de moeda precede o valor da quantidade de moeda formatada não negativo.  Defina como 0 se o símbolo segue o valor.  
  
 `char p_sep_by_space`  
 Defina como 1 se o símbolo de moeda é separado por espaço de valor para a quantidade de moeda formatada não negativo.  Defina como 0 se não houver nenhuma divisão de espaço.  
  
 `char n_cs_precedes`  
 Defina como 1 se o símbolo de moeda precede o valor da quantidade de moeda formatada negativa.  Defina como 0 se o símbolo êxito o valor.  
  
 `char n_sep_by_space`  
 Defina como 1 se o símbolo de moeda é separado por espaço de valor para a quantidade de moeda formatada negativa.  Defina como 0 se não houver nenhuma divisão de espaço.  
  
 `char p_sign_posn`  
 A posição do positivo se conecta quantidades monetárias formatados não negativo.  
  
 `char n_sign_posn`  
 A posição do positivo se conecta quantidades monetárias formatados negativas.  
  
 Os membros da estrutura que têm `char` `*` e versões de `wchar_t *` são ponteiros em cadeias de caracteres.  Qualquer um que `""` iguais \(ou `L""` para `wchar_t *`\) é de comprimento zero ou não suporte na localidade atual.  Observe que `decimal_point` e `_W_decimal_point` sempre têm suporte e de comprimento diferente de zero.  
  
 Os membros de `char` da estrutura são números não negativo pequenos, não caracteres.  Qualquer um que iguais **CHAR\_MAX** não é suportado na localidade atual.  
  
 Os elementos de **grouping** e de **mon\_grouping** são interpretados de acordo com as regras a seguir.  
  
 **CHAR\_MAX**  
 Não executa nenhum agrupamento adicional.  
  
 0  
 Use o elemento anterior para cada um de dígitos restantes.  
  
 *n*  
 Número de dígitos que compõem o grupo atual.  O próximo elemento está verificado para determinar o tamanho do próximo grupo de dígitos antes de cluster atual.  
  
 Os valores para **int\_curr\_symbol** são interpretados de acordo com as seguintes regras:  
  
-   Os três primeiros caracteres especificam o símbolo de moeda internacional alfabético conforme definido *no ISO 4217 para a representação códigos de moeda e os fundos* padrão.  
  
-   O quarto caractere \(imediatamente antes do caractere nulo\) separar o símbolo de moeda internacional da quantidade de moeda.  
  
 Os valores para **p\_cs\_precedes** e **n\_cs\_precedes** são interpretados de acordo com as regras a seguir \(a regra de **n\_cs\_precedes** está entre parênteses\):  
  
 0  
 O símbolo de moeda segue o valor para não negativo \(negativo\) formatou o valor monetário.  
  
 1  
 O símbolo de moeda precede o valor de não negativo \(negativo\) formatou o valor monetário.  
  
 Os valores para **p\_sep\_by\_space** e **n\_sep\_by\_space** são interpretados de acordo com as regras a seguir \(a regra de **n\_sep\_by\_space** está entre parênteses\):  
  
 0  
 O símbolo de moeda é separado do valor por espaço para o valor monetário formatado \(negativo\) não negativo.  
  
 1  
 Não há separação de espaço entre o símbolo de moeda e o valor para o valor monetário formatado \(negativo\) não negativo.  
  
 Os valores para **p\_sign\_posn** e **n\_sign\_posn** são interpretados de acordo com as seguintes regras:  
  
 0  
 Quantidade de trechos de parênteses e símbolo de moeda.  
  
 1  
 A cadeia de caracteres de sinal precede o símbolo de quantidade e de moeda.  
  
 2  
 A cadeia de caracteres de sinal segue o símbolo de quantidade e de moeda.  
  
 3  
 A cadeia de caracteres de sinal precede imediatamente o símbolo de moeda.  
  
 4  
 A cadeia de caracteres de sinal logo após o símbolo de moeda.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`localeconv`|\<locale.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [setlocale](../../preprocessor/setlocale.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strftime, wcsftime, \_strftime\_l, \_wcsftime\_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)