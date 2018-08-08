---
title: Nomes de localidades, idiomas e cadeias de caracteres de país/região | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.strings
dev_langs:
- C++
helpviewer_keywords:
- country/region strings
- localization, locale
- locales
- setlocale function
- language strings
ms.assetid: a0e5a0c5-5602-4da0-b65f-de3d6c8530a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f28262a1402d81bd5dcd0933f943b420a37f044
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606729"
---
# <a name="locale-names-languages-and-countryregion-strings"></a>Nomes de localidades, idiomas e cadeias de caracteres de país/região

O argumento *locale* para as funções `setlocale` e `_create_locale` pode ser definido usando os nomes de localidades, idiomas, códigos de país/região e as páginas de códigos com suporte da API NLS do Windows. O argumento *locale* usa o seguinte formato:

> *locale* :: "*locale_name*"  
&nbsp;&nbsp;&nbsp;&nbsp;| "*language*\[\_*country-region*]\[.*code_page*]]"  
&nbsp;&nbsp;&nbsp;&nbsp;| ".*code_page*"  
&nbsp;&nbsp;&nbsp;&nbsp;| "C"  
&nbsp;&nbsp;&nbsp;&nbsp;| ""  
&nbsp;&nbsp;&nbsp;&nbsp;| NULL  

O formato de nome da localidade é preferido — por exemplo, use `en-US` para inglês (Estados Unidos) ou `bs-Cyrl-BA` para bósnio (cirílico, Bósnia e Herzegovina). O conjunto de nomes de localidade é descrito em [Nomes de localidade](/windows/desktop/Intl/locale-names). Para obter uma lista de nomes de locais com suporte pela versão do sistema operacional Windows, veja a coluna **Marca de idioma** da tabela no [Apêndice A: comportamento de produto](https://msdn.microsoft.com/library/cc233982.aspx) no [MS-LCID]: referência do identificador de código de idioma (LCID) do Windows. Esse recurso lista o idioma, o script e as partes da região com suporte dos nomes de localidade. Para obter informações sobre os nomes de localidades com suporte que têm ordens de classificação não padrão, consulte a coluna **Nome da localidade** em [Identificadores da ordem de classificação](/windows/desktop/Intl/sort-order-identifiers). Com o Windows 10 ou posterior, são permitidos nomes de localidade que correspondem às marcas de idioma BCP-47 válidas. Por exemplo, `jp-US` é uma marca BCP-47 válida, mas é eficaz somente `US` para a funcionalidade de localidade.

O formato *language*[_*country_region*[.*code_page*]] é armazenado na configuração de localidade da categoria quando uma cadeia de caracteres de idioma ou uma cadeia de caracteres de idioma e de país/região é usada para criar a localidade. O conjunto de cadeias de caracteres de idioma com suporte é descrito em [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md), enquanto a lista de cadeias de caracteres de país/região com suporte é listada em [Cadeias de caracteres de país/região](../c-runtime-library/country-region-strings.md). Se o idioma especificado não for associado ao país/região especificado, o idioma padrão do país/região especificado será armazenado na configuração de localidade. Não recomendamos esse formato para cadeias de caracteres de localidade inseridas no código ou serializadas para armazenamento, pois essas cadeias de caracteres são mais prováveis de serem modificadas por uma atualização do sistema operacional do que o formato do nome da localidade.

A página de código é a página de código ANSI/OEM associada à localidade. A página de código é determinada por você ao especificar uma localidade por idioma ou por idioma e país/região apenas. O valor especial `.ACP` especifica a página de código ANSI para o país/região. O valor especial `.OCP` especifica a página de código OEM para o país/região. Por exemplo, se você especificar `"Greek_Greece.ACP"` como a localidade, a localidade será armazenada como `Greek_Greece.1253` (a página de código ANSI para grego); se você especificar `"Greek_Greece.OCP"` como a localidade, ela será armazenada como `Greek_Greece.737` (a página de código OEM para grego). Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md). Para obter uma lista de páginas de código com suporte no Windows, consulte [Identificadores de páginas de código](/windows/desktop/Intl/code-page-identifiers).

Se você usar somente a página de código para especificar a localidade, o idioma padrão e o país/região do sistema serão usados. Por exemplo, se você especificar `".1254"` (turco ANSI) como a localidade em um sistema que está configurado para inglês (Estados Unidos), a localidade armazenada será `English_United States.1254`. Não recomendamos essa forma, pois isso poderia resultar em comportamento inconsistente.

Um valor do argumento *locale* de `C` especifica o ambiente em conformidade mínima com ANSI para a conversão em C. A localidade `C` pressupõe que cada tipo de dados `char` tem 1 byte e seu valor é sempre menor que 256. Se *locale* apontar para uma cadeia de caracteres vazia, a localidade será o ambiente nativo definido pela implementação.

Você pode especificar todas as categorias de localidade ao mesmo tempo para as funções `setlocale` e `_wsetlocale` usando a categoria `LC_ALL`. Todas as categorias podem ser definidas para a mesma localidade, ou você pode definir cada categoria individualmente usando um argumento de localidade que tenha esta forma:

> LC_ALL_specifier :: locale  
&nbsp;&nbsp;&nbsp;&nbsp;| [LC_COLLATE=locale][;LC_CTYPE=locale][;LC_MONETARY=locale][;LC_NUMERIC=locale][;LC_TIME=locale]

Você pode especificar vários tipos de categoria, separados por ponto-e-vírgula. Os tipos da categoria que não especificados usam a definição de localidade atual. Por exemplo, este trecho de código define a localidade atual para todas as categorias como `de-DE` e, em seguida, define as categorias `LC_MONETARY` como `en-GB` e `LC_TIME` como `es-ES`:

```C
_wsetlocale(LC_ALL, L"de-DE");
_wsetlocale(LC_ALL, L"LC_MONETARY=en-GB;LC_TIME=es-ES");
```

## <a name="see-also"></a>Consulte também

[Referência da biblioteca em tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)  
[_get_current_locale](../c-runtime-library/reference/get-current-locale.md)  
[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)  
[_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)  
[Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)  
[Cadeias de caracteres de país/região](../c-runtime-library/country-region-strings.md)  