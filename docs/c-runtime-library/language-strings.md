---
title: Cadeias de caracteres de idioma
ms.date: 11/04/2016
f1_keywords:
- c.strings
helpviewer_keywords:
- language strings
ms.assetid: bbee63b1-af0b-4e44-9eaf-dd3e265c05fd
ms.openlocfilehash: a9e6eaa65516b5b49022526f24e220dec83b2c26
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500068"
---
# <a name="language-strings"></a>Cadeias de caracteres de idioma

As funções [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) e [_create_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md) podem usar idiomas com suporte pela API NLS do Windows em sistemas operacionais que não usam a página de código Unicode. Para obter uma lista dos idiomas que tem suporte pela versão do sistema operacional, confira [Apêndice A: Comportamento do produto](https://msdn.microsoft.com/library/cc233982.aspx) no [MS-LCID]: Referência do Windows Language Code Identifier (LCID). A cadeia de caracteres de idioma pode ser qualquer um dos valores nas colunas **Idioma** e **Marcação do idioma** da lista de idiomas com suporte. Para obter um exemplo de código que enumera os nomes de localidades disponíveis e valores relacionados, confira [NLS: exemplo de APIs com base no nome](/windows/win32/intl/nls--name-based-apis-sample).

## <a name="additional-supported-language-strings"></a>Cadeias de caracteres de idioma com suporte adicional

A implementação da biblioteca em tempo de execução C da Microsoft também dá suporte a estas cadeias de caracteres de idioma:

|Cadeia de caracteres de idioma|Nome da Localidade Equivalente|
|---------------------|----------------------------|
|american|en-US|
|american english|en-US|
|american-english|en-US|
|australian|en-AU|
|belgian|nl-BE|
|canadian|en-CA|
|chh|zh-HK|
|chi|zh-SG|
|chinese|zh|
|chinese-hongkong|zh-HK|
|chinese-simplified|zh-CN|
|chinese-singapore|zh-SG|
|chinese-traditional|zh-TW|
|dutch-belgian|nl-BE|
|english-american|en-US|
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
|english-us|en-US|
|english-usa|en-US|
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
|norwegian|no|
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
|swiss|de-CH|
|uk|en-GB|
|us|en-US|
|usa|en-US|

## <a name="see-also"></a>Consulte também

[Nomes de localidades, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
[Cadeias de caracteres de país/região](../c-runtime-library/country-region-strings.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)
