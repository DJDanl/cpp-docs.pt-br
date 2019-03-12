---
title: Categorias de localidade
ms.date: 11/04/2016
f1_keywords:
- LC_MAX
- LC_MIN
- LC_MONETARY
- LC_TIME
- LC_NUMERIC
- LC_COLLATE
- LC_CTYPE
- LC_ALL
helpviewer_keywords:
- LC_MIN constant
- LC_MONETARY constant
- LC_CTYPE constant
- locale constants
- LC_MAX constant
- LC_ALL constant
- LC_TIME constant
- LC_NUMERIC constant
- LC_COLLATE constant
ms.assetid: 868f1493-fe5d-4722-acab-bfcd374a063a
ms.openlocfilehash: 434500dab0c68aa9475f54e930b91da0b1cd2fc9
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749796"
---
# <a name="locale-categories"></a>Categorias de localidade

## <a name="syntax"></a>Sintaxe

```
#include <locale.h>
```

## <a name="remarks"></a>Comentários

As categorias de localidade são constantes de manifesto usadas por rotinas de localização para especificar qual parte das informações de localidade de um programa será usada. A localidade refere-se à localidade (ou país/região) para a qual é possível personalizar alguns aspectos do programa. As áreas que dependem da localidade incluem, por exemplo, a formatação de datas ou o formato de exibição de valores monetários.

|Categoria de localidade|Partes afetadas do programa|
|---------------------|-------------------------------|
|`LC_ALL`|Todo o comportamento específico da localidade (todas as categorias)|
|`LC_COLLATE`|Comportamento das funções `strcoll` e `strxfrm`|
|`LC_CTYPE`|Comportamento das funções de manipulação de caracteres (exceto `isdigit`, `isxdigit`, `mbstowcs` e `mbtowc`, que não são afetadas)|
|`LC_MAX`|Mesmo que `LC_TIME`|
|`LC_MIN`|Mesmo que `LC_ALL`|
|`LC_MONETARY`|Informações de formatação monetária retornadas pela função `localeconv`|
|`LC_NUMERIC`|Caractere de ponto decimal para rotinas de saída formatadas (por exemplo, `printf`), para rotinas de conversão de dados e para informações de formatação não monetária retornadas pela função `localeconv`|
|`LC_TIME`|Comportamento da função `strftime`|

Consulte [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para ver um exemplo.

## <a name="see-also"></a>Consulte também

[localeconv](../c-runtime-library/reference/localeconv.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[Funções strcoll](../c-runtime-library/strcoll-functions.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
