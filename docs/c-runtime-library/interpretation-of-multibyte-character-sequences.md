---
title: Interpretação de sequências de caracteres multibyte | Microsoft Docs
ms.custom: ''
ms.date: 04/11/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- c.character.multibyte
dev_langs:
- C++
helpviewer_keywords:
- MBCS [C++], locale code page
ms.assetid: da9150de-70ea-4d2f-90e6-ddb9202dd80b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d52a8b3572f398a97c902cf0bcd647a3752cee8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="interpretation-of-multibyte-character-sequences"></a>Interpretação de sequências de caracteres multibyte

A maioria das rotinas de caracteres multibyte na biblioteca em tempo de execução da Microsoft reconhecem sequências de caracteres multibyte relacionadas a uma página de código multibyte. O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar.

## <a name="locale-dependent-multibyte-routines"></a>Rotinas de Multibyte dependentes de localidade

|Rotina|Use|
|-------------|---------|
|[_mbclen, mblen, _mblen_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)|Validar e retornar número de bytes em caractere multibyte|
|[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)|Cadeias de caracteres multibyte: validar cada caractere na cadeia de caracteres; Retornar o comprimento da cadeia de caracteres. Cadeias de caracteres largos: retornar comprimento da cadeia de caracteres.|
|[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md), [mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter sequência de caracteres multibyte na sequência de caracteres largos correspondente|
|[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)|Converter caractere multibyte no caractere largo correspondente|
|[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md), [wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)|Converter sequência de caracteres largos na sequência de caracteres multibyte correspondente|
|[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md), [wctomb_s, _wctomb_s_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter um caractere largo em um caractere multibyte correspondente|
|[mbrtoc16, mbrtoc32](../c-runtime-library/reference/mbrtoc16-mbrtoc323.md)|Converter caracteres multibyte em caracteres UTF-16 ou UTF-32 equivalentes|
|[c16rtomb, c32rtomb](../c-runtime-library/reference/c16rtomb-c32rtomb1.md)|Converter caracteres UTF-16 ou UTF-32 em caracteres multibyte equivalentes|

## <a name="see-also"></a>Consulte também

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
 [Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
