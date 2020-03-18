---
title: Cadeias de caracteres de país–região
ms.date: 11/04/2016
helpviewer_keywords:
- country/region strings
ms.assetid: 5baf0ccf-0d9b-40dc-83bd-323705287930
ms.openlocfilehash: 8556e005618a1b69c47498a07e218284dcb1164f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443441"
---
# <a name="countryregion-strings"></a>Cadeias de caracteres de país/região

Cadeias de caracteres de país e região podem ser combinadas com uma cadeia de caracteres de idioma para criar uma especificação de localidade para as funções `setlocale`, `_wsetlocale`, `_create_locale` e `_wcreate_locale`. Para obter as listas de nomes de países e regiões compatíveis com várias versões do sistema operacional Windows, veja as colunas **Idioma**, **Localização** e **Marca de idioma** da tabela no [Apêndice A: comportamento de produto](https://msdn.microsoft.com/library/cc233982.aspx) no [MS-LCID]: referência do identificador de código de idioma (LCID) do Windows. Para obter um exemplo de código que enumera os nomes de localidades disponíveis e valores relacionados, veja [NLS: exemplo de APIs com base no nome](/windows/win32/intl/nls--name-based-apis-sample).

## <a name="additional-supported-country-and-region-strings"></a>Cadeias de caracteres de país e região com suporte adicional

A implementação de biblioteca em tempo de execução C da Microsoft também dá suporte às seguintes cadeias de caracteres adicionais de país/região e abreviações:

|Cadeia de caracteres de país/região|Abreviação de|Nome da localidade equivalente|
|----------------------------|------------------|----------------------------|
|america|EUA|en-US|
|britain|GBR|en-GB|
|china|CHN|zh-CN|
|czech|CZE|cs-CZ|
|england|GBR|en-GB|
|great britain|GBR|en-GB|
|holland|NLD|nl-NL|
|hong-kong|HKG|zh-HK|
|new-zealand|NZL|en-NZ|
|Nz|NZL|en-NZ|
|pr china|CHN|zh-CN|
|pr-china|CHN|zh-CN|
|puerto-rico|PRI|es-PR|
|slovak|SVK|sk-SK|
|south africa|ZAF|af-ZA|
|coreia do sul|KOR|ko-KR|
|south-africa|ZAF|af-ZA|
|south-korea|KOR|ko-KR|
|trinidad & tobago|TTO|en-TT|
|uk|GBR|en-GB|
|united-kingdom|GBR|en-GB|
|united-states|EUA|en-US|
|us|EUA|en-US|

## <a name="see-also"></a>Consulte também

[Nomes de localidades, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
[Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)
