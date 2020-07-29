---
title: Nomes de localidades, idiomas e cadeias de caracteres de país–região
ms.date: 12/10/2018
helpviewer_keywords:
- country/region strings
- localization, locale
- locales
- setlocale function
- language strings
ms.assetid: a0e5a0c5-5602-4da0-b65f-de3d6c8530a2
ms.openlocfilehash: ae4b695682e00ef2f26287957400344ddd96dff4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87189669"
---
# <a name="ucrt-locale-names-languages-and-countryregion-strings"></a>Nomes de localidades, idiomas e cadeias de caracteres de país–região do UCRT

O argumento *locale* para as funções [setlocale, \_wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md), [\_create\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md) e [\_wcreate\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md) pode ser definido usando os nomes de localidades, idiomas, códigos de país/região e as páginas de códigos com suporte da API NLS do Windows. O argumento *locale* usa o seguinte formato:

> *localidade* :: "*nome da localidade*"<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\|"*idioma* \[ **\_** _país-região_ \[ __.__ *Code-Page*]] "<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\|"__.__ *página de código*"<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\| "C"<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\| ""<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\| NULL

O formato *locale-name* é uma cadeia de caracteres curta padronizada pelo IETF; por exemplo, `en-US` para inglês (Estados Unidos) ou `bs-Cyrl-BA` para bósnio (cirílico, Bósnia e Herzegovina). Esses formatos são preferenciais. Para obter uma lista de nomes de localidade com suporte pela versão do sistema operacional Windows, consulte a coluna de **marca de idioma** da tabela no [Apêndice a: comportamento do produto](https://docs.microsoft.com/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c) em \[ MS-LCID]: referência do identificador de código de idioma do Windows (LCID). Esse recurso lista o idioma, o script e as partes da região com suporte dos nomes de localidade. Para obter informações sobre os nomes de localidades com suporte que têm ordens de classificação não padrão, consulte a coluna **Nome da localidade** em [Identificadores da ordem de classificação](/windows/win32/Intl/sort-order-identifiers). No Windows 10 ou posterior, os nomes de localidade que correspondem a marcas de idioma [bcp-47](https://tools.ietf.org/html/bcp47) válidos são permitidos. Por exemplo, `jp-US` é uma marca BCP-47 válida, mas é eficaz somente `US` para a funcionalidade de localidade.

O *idioma* \[ **\_** _país-região_ \[ __.__ *página de código*]] o formulário é armazenado na configuração de localidade para uma categoria quando uma cadeia de caracteres de idioma, ou cadeia de caracteres de idioma e país ou cadeia de caracteres de região, é usada para criar a localidade. O conjunto de cadeias de caracteres de idioma com suporte é descrito em [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md), enquanto a lista de cadeias de caracteres de paí e região com suporte é listada em [Cadeias de caracteres de país/região](../c-runtime-library/country-region-strings.md). Se o idioma especificado não for associado ao país ou região especificado, o idioma padrão do país ou região especificado será armazenado na configuração de localidade. Não recomendamos esse formato para cadeias de caracteres de localidade inseridas no código ou serializadas para armazenamento, pois essas cadeias de caracteres são mais prováveis de serem modificadas por uma atualização do sistema operacional do que o formato do nome da localidade.

A *página de código* é a página de código ANSI/OEM associada à localidade. A página de código é determinada por você ao especificar uma localidade por idioma ou por idioma e país/região apenas. O valor especial `.ACP` especifica a página de código ANSI para o país/região. O valor especial `.OCP` especifica a página de código OEM para o país/região. Por exemplo, se você especificar `"Greek_Greece.ACP"` como a localidade, a localidade será armazenada como `Greek_Greece.1253` (a página de código ANSI para grego); se você especificar `"Greek_Greece.OCP"` como a localidade, ela será armazenada como `Greek_Greece.737` (a página de código OEM para grego). Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md). Para obter uma lista de páginas de código com suporte no Windows, consulte [Identificadores de páginas de código](/windows/win32/Intl/code-page-identifiers).

Se você usar somente a página de código para especificar a localidade, serão usados o idioma e o país/região padrão do usuário, relatados por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). Por exemplo, se você especificar `".1254"` (turco ANSI) como a localidade de um usuário que está configurado para inglês (Estados Unidos), a localidade armazenada será `English_United States.1254`. Não recomendamos essa forma, pois isso poderia resultar em comportamento inconsistente.

Um valor do argumento *locale* de `C` especifica o ambiente em conformidade mínima com ANSI para a conversão em C. A `C` localidade pressupõe que cada **`char`** tipo de dados é 1 byte e seu valor é sempre menor que 256. Se *locale* apontar para uma cadeia de caracteres vazia, a localidade será o ambiente nativo definido pela implementação.

Você pode especificar todas as categorias de localidade ao mesmo tempo para as funções `setlocale` e `_wsetlocale` usando a categoria `LC_ALL`. Todas as categorias podem ser definidas para a mesma localidade, ou você pode definir cada categoria individualmente usando um argumento de localidade que tenha esta forma:

> *LC-ALL-specifier* :: *locale*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\| \[**LC_COLLATE=**_locale_]\[**;LC_CTYPE=**_locale_]\[**;LC_MONETARY=**_locale_]\[**;LC_NUMERIC=**_locale_]\[**;LC_TIME=**_locale_]

Você pode especificar vários tipos de categoria, separados por ponto-e-vírgula. Os tipos da categoria que não especificados usam a definição de localidade atual. Por exemplo, este snippet de código define a localidade atual para todas as categorias como `de-DE` e, em seguida, define as categorias `LC_MONETARY` como `en-GB` e `LC_TIME` como `es-ES`:

```C
_wsetlocale(LC_ALL, L"de-DE");
_wsetlocale(LC_ALL, L"LC_MONETARY=en-GB;LC_TIME=es-ES");
```

## <a name="see-also"></a>Confira também

[Referência da biblioteca de tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)<br/>
[_get_current_locale](../c-runtime-library/reference/get-current-locale.md)<br/>
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)<br/>
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)<br/>
[Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)<br/>
[Cadeias de país/região](../c-runtime-library/country-region-strings.md)
