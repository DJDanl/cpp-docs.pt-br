---
title: Classificação de byte | Microsoft Docs
ms.custom: ''
ms.date: 04/04/2018
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.types.bytes
dev_langs:
- C++
helpviewer_keywords:
- code page 932
- byte classification routines
- bytes, testing
ms.assetid: 1cb52d71-fb0c-46ca-aad7-6472c1103370
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f1051ea7b8d4cc3a3f38a5a95f015674ac3e35c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32390968"
---
# <a name="byte-classification"></a>Classificação de byte

Todas essas rotinas testam um byte especificado de um caractere multibyte para satisfação de uma condição. Salvo quando especificado, o valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Confira [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar.

> [!NOTE]
> Por definição, os caracteres ASCII entre 0 e 127 são um subconjunto de todos os conjuntos de caracteres multibyte. Por exemplo, o conjunto de caracteres japoneses de katakana inclui ASCII, bem como caracteres não ASCII.

As constantes predefinidas na tabela a seguir são definidas em \<ctype.h>.

## <a name="multibyte-character-byte-classification-routines"></a>Rotinas de classificação de byte do caractere multibyte

|Rotina|Condição de teste de byte|
|-------------|-------------------------|
|[isleadbyte, _isleadbyte_l](../c-runtime-library/reference/isleadbyte-isleadbyte-l.md)|Byte inicial. O resultado do teste depende da configuração **LC_CTYPE** da categoria da localidade atual|
|[_ismbbalnum, _ismbbalnum_l](../c-runtime-library/reference/ismbbalnum-ismbbalnum-l.md)|**isalnum** &#124;&#124; **_ismbbkalnum**|
|[_ismbbalpha, _ismbbalpha_l](../c-runtime-library/reference/ismbbalpha-ismbbalpha-l.md)|**isalpha** &#124;&#124; **_ismbbkalnum**|
|[_ismbbgraph, _ismbbgraph_l](../c-runtime-library/reference/ismbbgraph-ismbbgraph-l.md)|Mesmo que **_ismbbprint**, mas **_ismbbgraph** não inclui o caractere de espaço (0x20)|
|[_ismbbkalnum, _ismbbkalnum_l](../c-runtime-library/reference/ismbbkalnum-ismbbkalnum-l.md)|Símbolo de texto não ASCII que não seja de pontuação. Por exemplo, somente na página de código 932, **_ismbbkalnum** testa se há alfanumérico katakana|
|[_ismbbkana, _ismbbkana_l](../c-runtime-library/reference/ismbbkana-ismbbkana-l.md)|Katakana (0xA1 – 0xDF), página de código 932 apenas|
|[_ismbbkprint, _ismbbkprint_l](../c-runtime-library/reference/ismbbkprint-ismbbkprint-l.md)|Texto não ASCII ou símbolo de pontuação não ASCII. Por exemplo, somente na página de código 932, **_ismbbkprint** testa se há pontuação katakana ou alfanumérico katakana (intervalo: 0xA1 – 0xDF).|
|[_ismbbkpunct, _ismbbkpunct_l](../c-runtime-library/reference/ismbbkpunct-ismbbkpunct-l.md)|Pontuação não ASCII. Por exemplo, somente na página de código 932, **_ismbbkpunct** testa se há pontuação katakana.|
|[_ismbblead, _ismbblead_l](../c-runtime-library/reference/ismbblead-ismbblead-l.md)|Byte inicial do caractere multibyte. Por exemplo, somente na página de código 932, os intervalos válidos são 0x81 a 0x9F e 0xE0 a 0xFC.|
|[_ismbbprint, _ismbbprint_l](../c-runtime-library/reference/ismbbprint-ismbbprint-l.md)|**isprint** &#124;&#124; **_ismbbkprint**. **ismbbprint** inclui o caractere de espaço (0x20)|
|[_ismbbpunct, _ismbbpunct_l](../c-runtime-library/reference/ismbbpunct-ismbbpunct-l.md)|**ispunct** &#124;&#124; **_ismbbkpunct**|
|[_ismbbtrail, _ismbbtrail_l](../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md)|Segundo byte do caractere multibyte. Por exemplo, somente na página de código 932, os intervalos válidos são 0x40 a 0x7E e 0x80 a 0xEC.|
|[_ismbslead, _ismbslead_l](../c-runtime-library/reference/ismbslead-ismbstrail-ismbslead-l-ismbstrail-l.md)|Byte inicial (no contexto da cadeia de caracteres)|
|[ismbstrail, _ismbstrail_l](../c-runtime-library/reference/ismbslead-ismbstrail-ismbslead-l-ismbstrail-l.md)|Byte final (no contexto da cadeia de caracteres)|
|[_mbbtype, _mbbtype_l](../c-runtime-library/reference/mbbtype-mbbtype-l.md)|Tipo de byte de retorno com base no byte anterior|
|[_mbsbtype, _mbsbtype_l](../c-runtime-library/reference/mbsbtype-mbsbtype-l.md)|Tipo de retorno do byte na cadeia de caracteres|
|[mbsinit](../c-runtime-library/reference/mbsinit.md)|Controla o estado de uma conversão de caracteres de vários bytes.|

A macro **MB_LEN_MAX**, definida em \<limits.h>, expande para o comprimento máximo em bytes que qualquer caractere multibyte pode ter. **MB_CUR_MAX**, definido em \<stdlib.h>, expande para o comprimento máximo em bytes de qualquer caractere multibyte na localidade atual.

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)