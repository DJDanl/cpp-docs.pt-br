---
title: Cadeias de caracteres de idioma
ms.date: 11/04/2016
helpviewer_keywords:
- language strings
ms.assetid: bbee63b1-af0b-4e44-9eaf-dd3e265c05fd
ms.openlocfilehash: dd0c55091d3dff641993fa593e656e2825da7c73
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839238"
---
# <a name="language-strings"></a>Cadeias de caracteres de idioma

As funções [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) e [_create_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md) podem usar idiomas com suporte pela API NLS do Windows em sistemas operacionais que não usam a página de código Unicode. Para obter uma lista de idiomas com suporte pela versão do sistema operacional, consulte [o apêndice a: comportamento do produto](/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c) em \[ MS-LCID]: referência do identificador de código de idioma do Windows (LCID). A cadeia de caracteres de idioma pode ser qualquer um dos valores nas colunas **Idioma** e **Marcação do idioma** da lista de idiomas com suporte. Para obter um exemplo de código que enumera os nomes de localidades disponíveis e valores relacionados, veja [NLS: exemplo de APIs com base no nome](/windows/win32/intl/nls--name-based-apis-sample).

## <a name="additional-supported-language-strings"></a>Cadeias de caracteres de idioma com suporte adicional

A implementação da biblioteca em tempo de execução C da Microsoft também dá suporte a estas cadeias de caracteres de idioma:

|Cadeia de caracteres de idioma|Nome da Localidade Equivalente|
|---------------------|----------------------------|
|americano|pt-BR|
|american english|pt-BR|
|american-english|pt-BR|
|australiano|en-AU|
|belga|nl-BE|
|canadense|en-CA|
|chh|zh-HK|
|chi|zh-SG|
|chinês|zh|
|chinese-hongkong|zh-HK|
|chinese-simplified|zh-CN|
|chinese-singapore|zh-SG|
|chinese-traditional|zh-TW|
|dutch-belgian|nl-BE|
|english-american|pt-BR|
|english-aus|en-AU|
|english-belize|en-BZ|
|english-can|en-CA|
|english-caribbean|en-029|
|english-ire|en-IE|
|english-jamaica|en-JM|
|english-nz|en-NZ|
|english-south africa|en-ZA|
|english-trinidad y tobago|en-TT|
|english-uk|en-GB|
|english-us|pt-BR|
|english-usa|pt-BR|
|french-belgian|fr-BE|
|french-canadian|fr-CA|
|french-luxembourg|fr-LU|
|french-swiss|fr-CH|
|german-austrian|de-AT|
|german-lichtenstein|de-LI|
|german-luxembourg|de-LU|
|german-swiss|de-CH|
|irish-english|en-IE|
|italian-swiss|it-CH|
|norueguês|não|
|norwegian-bokmal|nb-NO|
|norwegian-nynorsk|nn-NO|
|portuguese-brazilian|pt-BR|
|spanish-argentina|es-AR|
|spanish-bolivia|es-BO|
|spanish-chile|es-CL|
|spanish-colombia|es-CO|
|spanish-costa rica|es-CR|
|spanish-dominican republic|es-DO|
|spanish-ecuador|es-EC|
|spanish-el salvador|es-SV|
|spanish-guatemala|es-GT|
|spanish-honduras|es-HN|
|spanish-mexican|es-MX|
|spanish-modern|es-ES|
|spanish-nicaragua|es-NI|
|spanish-panama|es-PA|
|spanish-paraguay|es-PY|
|spanish-peru|es-PE|
|spanish-puerto rico|es-PR|
|spanish-uruguay|es-UY|
|spanish-venezuela|es-VE|
|swedish-finland|sv-FI|
|suíço|de-CH|
|uk|en-GB|
|us|pt-BR|
|usa|pt-BR|

## <a name="see-also"></a>Confira também

[Nomes de localidade, idiomas e cadeias de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
[Cadeias de país/região](../c-runtime-library/country-region-strings.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)
