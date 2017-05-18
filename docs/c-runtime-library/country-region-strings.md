---
title: "Cadeias de caracteres de país-região | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.strings
dev_langs:
- C++
helpviewer_keywords:
- country/region strings
ms.assetid: 5baf0ccf-0d9b-40dc-83bd-323705287930
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 708651f59ceff638482264e3fc57228e8a1822b2
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="countryregion-strings"></a>Cadeias de caracteres de país/região
Cadeias de caracteres de país e região podem ser combinadas com uma cadeia de caracteres de idioma para criar uma especificação de localidade para as funções `setlocale`, `_wsetlocale`, `_create_locale` e `_wcreate_locale`. Para obter listas de nomes de país/região que tem suporte por várias versões do sistema operacional Windows, consulte as [referência API de Suporte ao Idioma Nacional (NLS)](http://msdn.microsoft.com/goglobal/bb896001.aspx). Nas listas, a cadeia de caracteres de país/região pode ser qualquer um dos valores de país na coluna **Localidade – País/Região do idioma** ou qualquer uma das abreviações na coluna **abreviação do nome do País ou Região**.  
  
 A implementação de biblioteca em tempo de execução C também dá suporte às seguintes cadeias de caracteres adicionais de país/região e abreviações:  
  
|Cadeia de caracteres de país/região|Abreviação de|Nome da localidade equivalente|  
|----------------------------|------------------|----------------------------|  
|america|USA|pt-BR|  
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
|united-states|USA|pt-BR|  
|us|USA|pt-BR|  
  
## <a name="see-also"></a>Consulte também  
 [Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)   
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)
