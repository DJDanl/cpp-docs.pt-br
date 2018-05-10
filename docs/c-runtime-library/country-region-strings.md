---
title: Cadeias de caracteres de país-região | Microsoft Docs
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
ms.assetid: 5baf0ccf-0d9b-40dc-83bd-323705287930
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ffa2ac8d08e28cac4f5798868013fe9883fac5d9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="countryregion-strings"></a>Cadeias de caracteres de país/região
Cadeias de caracteres de país e região podem ser combinadas com uma cadeia de caracteres de idioma para criar uma especificação de localidade para as funções `setlocale`, `_wsetlocale`, `_create_locale` e `_wcreate_locale`. Para listas de nomes de país/região que têm suporte em várias versões do sistema operacional Windows, veja [Referência da API do suporte ao idioma nacional (NLS)](https://www.microsoft.com/resources/msdn/goglobal/default.mspx). Nas listas, a cadeia de caracteres de país/região pode ser qualquer valor na coluna **País/Região de Localidade – Idioma** ou qualquer abreviação na coluna **Abreviação de nome de país ou região**. Para obter informações adicionais de suporte de idioma no sistema operacional Windows por versão, veja [Apêndice A: comportamento de produto](http://msdn.microsoft.com/goglobal/bb896001.aspx) no [MS-LCID]: referência do identificador de código de idioma (LCID) do Windows.  
  
 A implementação de biblioteca em tempo de execução C também dá suporte às seguintes cadeias de caracteres adicionais de país/região e abreviações:  
  
|Cadeia de caracteres de país/região|Abreviação de|Nome da localidade equivalente|  
|----------------------------|------------------|----------------------------|  
|america|USA|en-US|  
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
|south korea|KOR|ko-KR|  
|south-africa|ZAF|af-ZA|  
|south-korea|KOR|ko-KR|  
|trinidad & tobago|TTO|en-TT|  
|uk|GBR|en-GB|  
|united-kingdom|GBR|en-GB|  
|united-states|USA|en-US|  
|us|USA|en-US|  
  
## <a name="see-also"></a>Consulte também  
 [Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)   
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)