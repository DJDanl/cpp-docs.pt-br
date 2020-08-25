---
title: Cadeias de caracteres de país–região
ms.date: 11/04/2016
helpviewer_keywords:
- country/region strings
ms.assetid: 5baf0ccf-0d9b-40dc-83bd-323705287930
ms.openlocfilehash: d5d8c10e30886c1b34bb5dc95296bc594acda1a4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831847"
---
# <a name="countryregion-strings"></a>Cadeias de caracteres de país/região

Cadeias de caracteres de país e região podem ser combinadas com uma cadeia de caracteres de idioma para criar uma especificação de localidade para as funções `setlocale`, `_wsetlocale`, `_create_locale` e `_wcreate_locale`. Para obter listas de nomes de país e região com suporte em várias versões do sistema operacional Windows, consulte as colunas **idioma**, **local**e **marca de idioma** da tabela no [Apêndice A: comportamento do produto](/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c) em \[ MS-LCID]: referência do identificador de código de idioma do Windows (LCID). Para obter um exemplo de código que enumera os nomes de localidades disponíveis e valores relacionados, veja [NLS: exemplo de APIs com base no nome](/windows/win32/intl/nls--name-based-apis-sample).

## <a name="additional-supported-country-and-region-strings"></a>Cadeias de caracteres de país e região com suporte adicional

A implementação de biblioteca em tempo de execução C da Microsoft também dá suporte às seguintes cadeias de caracteres adicionais de país/região e abreviações:

|Cadeia de caracteres de país/região|Abreviação|Nome da localidade equivalente|
|----------------------------|------------------|----------------------------|
|america|EUA|pt-BR|
|britain|GBR|en-GB|
|china|CHN|zh-CN|
|tcheco|CZE|cs-CZ|
|england|GBR|en-GB|
|great britain|GBR|en-GB|
|holland|NLD|nl-NL|
|hong-kong|HKG|zh-HK|
|new-zealand|NZL|en-NZ|
|Nz|NZL|en-NZ|
|pr china|CHN|zh-CN|
|pr-china|CHN|zh-CN|
|puerto-rico|PRI|es-PR|
|eslovaco|SVK|sk-SK|
|south africa|ZAF|af-ZA|
|coreia do sul|KOR|ko-KR|
|south-africa|ZAF|af-ZA|
|south-korea|KOR|ko-KR|
|trinidad & tobago|TTO|en-TT|
|uk|GBR|en-GB|
|united-kingdom|GBR|en-GB|
|united-states|EUA|pt-BR|
|us|EUA|pt-BR|

## <a name="see-also"></a>Confira também

[Nomes de localidade, idiomas e cadeias de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
[Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)
