---
title: Mapeamentos de tipo de dados
ms.date: 11/04/2016
f1_keywords:
- _TXCHAR
- _TUCHAR
- _TINT
- _TSCHAR
- _TCHAR
- TCHAR::H
- TCHAR
- _T
- _TEXT
helpviewer_keywords:
- _TXCHAR type
- TINT type
- _TCHAR type
- TSCHAR type
- TEXT type
- TCHAR type
- TCHAR.H data types, mappings defined in
- generic-text data types
- _TINT type
- TUCHAR type
- TXCHAR type
- _TSCHAR type
- T type
- _TUCHAR type
- _TEXT type
- _T type
ms.assetid: 4e573c05-8800-468b-ae5f-76ff7409835e
ms.openlocfilehash: d77ac4fa9afcd5a6b8f86261c7a3ba466adc64a4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215147"
---
# <a name="data-type-mappings"></a>Mapeamentos de tipo de dados

Esses mapeamentos de tipo de dados são definidos em TCHAR.H e dependem se a constante `_UNICODE` ou `_MBCS` foi definida no programa.

Para obter informações relacionadas, consulte [Usando tipos de dados TCHAR.H com código _MBCS](../text/using-tchar-h-data-types-with-mbcs-code.md).

### <a name="generic-text-data-type-mappings"></a>Mapeamentos de tipo de dados de texto genérico

|Texto genérico<br /><br /> nome de tipo de dados|SBCS (_UNICODE,<br /><br /> _MBCS não<br /><br /> definido)|_MBCS<br /><br /> definido|_UNICODE<br /><br /> definido|
|--------------------------------------|----------------------------------------------------|------------------------|---------------------------|
|`_TCHAR`|**`char`**|**`char`**|**`wchar_t`**|
|`_tfinddata_t`|`_finddata_t`|`_finddata_t`|`_wfinddata_t`|
|`_tfinddata64_t`|`__finddata64_t`|`__finddata64_t`|`__wfinddata64_t`|
|`_tfinddatai64_t`|`_finddatai64_t`|`_finddatai64_t`|`_wfinddatai64_t`|
|`_TINT`|**`int`**|**`int`**|`wint_t`|
|`_TSCHAR`|**`signed char`**|**`signed char`**|**`wchar_t`**|
|`_TUCHAR`|**`unsigned char`**|**`unsigned char`**|**`wchar_t`**|
|`_TXCHAR`|**`char`**|**`unsigned char`**|**`wchar_t`**|
|`_T` ou `_TEXT`|Nenhum efeito (removido pelo pré-processador)|Nenhum efeito (removido pelo pré-processador)|`L` (converte o próximo caractere ou a próxima cadeia de caracteres no equivalente em Unicode)|

## <a name="see-also"></a>Confira também

[Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)<br/>
[Mapeamentos de variável constante e global](../c-runtime-library/constant-and-global-variable-mappings.md)<br/>
[Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)<br/>
[Um exemplo de programa de texto genérico](../c-runtime-library/a-sample-generic-text-program.md)<br/>
[Usando mapeamentos de texto genérico](../c-runtime-library/using-generic-text-mappings.md)
