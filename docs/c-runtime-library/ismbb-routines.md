---
title: Rotinas _ismbb | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apilocation:
- msvcr110.dll
- msvcrt.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- _ismbb
- ismbb
dev_langs:
- C++
helpviewer_keywords:
- ismbb routines
- _ismbb routines
ms.assetid: d63c232e-3fe4-4844-aafd-2133846ece4b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 86587495353090ced63d0487991f4275d3d0d5d5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092512"
---
# <a name="ismbb-routines"></a>Rotinas _ismbb

Testa o valor inteiro dado `c` para uma determinada condição, usando a localidade atual ou uma categoria de estado de conversão LC_CTYPE especificada.

|||
|-|-|
|[_ismbbalnum, _ismbbalnum_l](../c-runtime-library/reference/ismbbalnum-ismbbalnum-l.md)|[_ismbbkprint, _ismbbkprint_l](../c-runtime-library/reference/ismbbkprint-ismbbkprint-l.md)|
|[_ismbbalpha, _ismbbalpha_l](../c-runtime-library/reference/ismbbalpha-ismbbalpha-l.md)|[_ismbbkpunct, _ismbbkpunct_l](../c-runtime-library/reference/ismbbkpunct-ismbbkpunct-l.md)|
|[_ismbbblank, _ismbbblank_l](../c-runtime-library/reference/ismbbblank-ismbbblank-l.md)|[_ismbblead, _ismbblead_l](../c-runtime-library/reference/ismbblead-ismbblead-l.md)|
|[_ismbbgraph, _ismbbgraph_l](../c-runtime-library/reference/ismbbgraph-ismbbgraph-l.md)|[_ismbbprint, _ismbbprint_l](../c-runtime-library/reference/ismbbprint-ismbbprint-l.md)|
|[_ismbbkalnum, _ismbbkalnum_l](../c-runtime-library/reference/ismbbkalnum-ismbbkalnum-l.md)|[_ismbbpunct, _ismbbpunct_l](../c-runtime-library/reference/ismbbpunct-ismbbpunct-l.md)|
|[_ismbbkana, _ismbbkana_l](../c-runtime-library/reference/ismbbkana-ismbbkana-l.md)|[_ismbbtrail, _ismbbtrail_l](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md)|

## <a name="remarks"></a>Comentários

Cada rotina na família `_ismbb` testa o valor inteiro dado `c` para uma determinada condição. O resultado do teste depende da página de código multibyte que está em vigor. Por padrão, a página de código multibyte é definida para a página de código ANSI obtida do sistema operacional na inicialização do programa. Você pode usar [_getmbcp](../c-runtime-library/reference/getmbcp.md) para consultar a página de código multibyte que está em uso ou [_setmbcp](../c-runtime-library/reference/setmbcp.md) para alterá-la.

O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Consulte [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o sufixo **_l** usam a localidade atual para esse comportamento dependente de localidade; as versões com o sufixo **_l** são idênticas, exceto que, em vez disso, usam o parâmetro de localidade informado.

As rotinas na família `_ismbb` testam o inteiro dado `c` da seguinte maneira.

|Rotina|Condição de teste de byte|
|-------------|-------------------------|
|[_ismbbalnum](../c-runtime-library/reference/ismbbalnum-ismbbalnum-l.md)|`isalnum` &#124;&#124; `_ismbbkalnum`.|
|[_ismbbalpha](reference/ismbbalpha-ismbbalpha-l.md)|`isalpha` &#124;&#124; `_ismbbkalnum`.|
|[_ismbbblank](../c-runtime-library/reference/ismbbblank-ismbbblank-l.md)|`isblank`|
|[_ismbbgraph](../c-runtime-library/reference/ismbbgraph-ismbbgraph-l.md)|Mesmo que `_ismbbprint`, mas `_ismbbgraph` não inclui o caractere de espaço (0x20).|
|[_ismbbkalnum](../c-runtime-library/reference/ismbbkalnum-ismbbkalnum-l.md)|Símbolo de texto não ASCII que não seja de pontuação. Por exemplo, na página de código 932 somente, `_ismbbkalnum` testa se é katakana alfanumérico.|
|[_ismbbkana](../c-runtime-library/reference/ismbbkana-ismbbkana-l.md)|Katakana (0xA1 – 0xDF). Específico para a página de código 932.|
|[_ismbbkprint](../c-runtime-library/reference/ismbbkprint-ismbbkprint-l.md)|Texto não ASCII ou símbolo de pontuação não ASCII. Por exemplo, somente na página de código 932, `_ismbbkprint` testa se há pontuação katakana ou caracteres alfanuméricos katakana (intervalo: 0xA1 – 0xDF).|
|[_ismbbkpunct](../c-runtime-library/reference/ismbbkpunct-ismbbkpunct-l.md)|Pontuação não ASCII. Por exemplo, na página de código 932 somente, `_ismbbkpunct` testa se é uma pontuação katakana.|
|[_ismbblead](../c-runtime-library/reference/ismbblead-ismbblead-l.md)|Byte inicial do caractere multibyte. Por exemplo, somente na página de código 932, os intervalos válidos são 0x81 a 0x9F e 0xE0 a 0xFC.|
|[_ismbbprint](../c-runtime-library/reference/ismbbprint-ismbbprint-l.md)|`isprint` &#124;&#124; `_ismbbkprint`. **ismbbprint** inclui o caractere de espaço (0x20).|
|[_ismbbpunct](../c-runtime-library/reference/ismbbpunct-ismbbpunct-l.md)|`ispunct` &#124;&#124; `_ismbbkpunct`.|
|[_ismbbtrail](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md)|Segundo byte do caractere multibyte. Por exemplo, somente na página de código 932, os intervalos válidos são 0x40 a 0x7E e 0x80 a 0xEC.|

A tabela a seguir mostra os valores ORed que compõem as condições de teste para essas rotinas. As constantes de manifesto `_BLANK`, `_DIGIT`, `_LOWER`, `_PUNCT` e `_UPPER` são definidas em Ctype.h.

|Rotina|_BLANK|_DIGIT|LOWER|_PUNCT|UPPER|Não<br /><br /> ASCII<br /><br /> texto|Não<br /><br /> ASCII<br /><br /> punct|
|-------------|-------------|-------------|-----------|-------------|-----------|------------------------------|-------------------------------|
|`_ismbbalnum`|—|x|x|—|x|x|—|
|`_ismbbalpha`|—|—|x|—|x|x|—|
|`_ismbbblank`|x|—|—|—|—|—|—|
|`_ismbbgraph`|—|x|x|x|x|x|x|
|`_ismbbkalnum`|—|—|—|—|—|x|—|
|`_ismbbkprint`|—|—|—|—|—|x|x|
|`_ismbbkpunct`|—|—|—|—|—|—|x|
|`_ismbbprint`|x|x|x|x|x|x|x|
|`_ismbbpunct`|—|—|—|x|—|—|x|

As rotinas `_ismbb` são implementadas como funções e macros. Para obter informações sobre como escolher a implementação, consulte [Recomendações para escolher entre funções e macros](../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../c-runtime-library/byte-classification.md)<br/>
[Rotinas is, isw](../c-runtime-library/is-isw-routines.md)<br/>
[_mbbtombc, _mbbtombc_l](../c-runtime-library/reference/mbbtombc-mbbtombc-l.md)<br/>
[_mbctombb, _mbctombb_l](../c-runtime-library/reference/mbctombb-mbctombb-l.md)