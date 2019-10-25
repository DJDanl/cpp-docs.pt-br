---
title: Interpretação de sequências de caracteres multibyte
ms.date: 10/22/2019
f1_keywords:
- c.character.multibyte
helpviewer_keywords:
- MBCS [C++], locale code page
ms.assetid: da9150de-70ea-4d2f-90e6-ddb9202dd80b
ms.openlocfilehash: 7431f0c63df60414af192ea38103318c775c430d
ms.sourcegitcommit: 0a5518fdb9d87fcc326a8507ac755936285fcb94
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2019
ms.locfileid: "72811081"
---
# <a name="interpretation-of-multibyte-character-sequences"></a>Interpretação de sequências de caracteres multibyte

A maioria das rotinas de caracteres multibyte na biblioteca em tempo de execução da Microsoft reconhecem sequências de caracteres multibyte relacionadas a uma página de código multibyte. O valor de saída é afetado pela configuração da configuração de categoria **LC_CTYPE** da localidade. Para obter mais informações sobre, consulte [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md). As versões dessas funções sem o sufixo **_L** usam a localidade atual para esse comportamento dependente de localidade. As versões com o sufixo **_L** são idênticas, exceto que usam o parâmetro Locale em vez da localidade atual.

## <a name="locale-dependent-multibyte-routines"></a>Rotinas multibyte dependentes de localidade

|Rotina|Use|
|-------------|---------|
|[_mbclen, mblen, _mblen_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)|Validar e retornar número de bytes em caractere multibyte|
|[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)|Cadeias de caracteres multibyte: validar cada caractere na cadeia de caracteres; Retornar o comprimento da cadeia de caracteres. Cadeias de caracteres largos: retornar comprimento da cadeia de caracteres.|
|[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md), [mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter sequência de caracteres multibyte na sequência de caracteres largos correspondente|
|[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)|Converter caractere multibyte no caractere largo correspondente|
|[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md), [wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)|Converter sequência de caracteres largos na sequência de caracteres multibyte correspondente|
|[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md), [wctomb_s, _wctomb_s_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter caractere largo no caractere multibyte correspondente|

## <a name="locale-independent-multibyte-routines"></a>Rotinas multibyte independentes de localidade

|Rotina|Use|
|-------------|---------|
|[mbrtoc16, mbrtoc32](../c-runtime-library/reference/mbrtoc16-mbrtoc323.md)|Converter um caractere UTF-8 multibyte em caracteres UTF-16 ou UTF-32 equivalentes|
|[c16rtomb, c32rtomb](../c-runtime-library/reference/c16rtomb-c32rtomb1.md)|Converter o caractere UTF-16 ou UTF-32 em um caractere multibyte UTF-8 equivalente|

## <a name="see-also"></a>Consulte também

[Internacionalização](../c-runtime-library/internationalization.md)\
[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)
