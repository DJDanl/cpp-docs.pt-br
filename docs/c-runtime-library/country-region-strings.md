---
title: "Cadeias de caracteres de pa&#237;s/regi&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.strings"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "cadeias de caracteres de país/região"
ms.assetid: 5baf0ccf-0d9b-40dc-83bd-323705287930
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Cadeias de caracteres de pa&#237;s/regi&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As cadeias de caracteres de país e região podem ser combinadas com uma cadeia de caracteres de linguagem para criar uma especificação de localidade para `setlocale`, `_wsetlocale`, `_create_locale`, e funções de `_wcreate_locale`.  Para obter listas de país\/nomes de região que são suportadas por várias versões do sistema operacional Windows, consulte [Referência da API de suporte a linguagem nacional \(NLS\)](http://msdn.microsoft.com/goglobal/bb896001.aspx). Nas listas, o país\/cadeia de caracteres da região pode ser qualquer um dos valores de país na coluna de **Localidade – país\/região de linguagem**, ou algumas das abreviações na coluna de **Abreviação do nome do país ou da região**.  
  
 A implementação da biblioteca em tempo de execução C também oferece suporte às seguintes cadeias de caracteres e abreviações de país\/região adicionais:  
  
|Cadeia de caracteres de país\/região|Abreviação|Nome equivalente de localidade|  
|------------------------------------------|----------------|------------------------------------|  
|américa|EUA|pt\-BR|  
|grã\-bretanha|GBR|en\-GB|  
|china|CHN|zh\-CN|  
|tcheco|CZE|cs\-CZ|  
|Inglaterra|GBR|en\-GB|  
|Grã\-bretanha|GBR|en\-GB|  
|Holanda|NLD|nl\-NL|  
|hong\-kong|HKG|zh\-HK|  
|nova zelândia|NZL|en\-NZ|  
|nz|NZL|en\-NZ|  
|pr china|CHN|zh\-CN|  
|pr\-china|CHN|zh\-CN|  
|puerto rico|PRI|es\-PR|  
|eslovaco|SVK|sk\-SK|  
|áfrica do sul|ZAF|af\-ZA|  
|coreia do sul|KOR|ko\-KR|  
|áfrica do sul|ZAF|af\-ZA|  
|coreia do sul|KOR|ko\-KR|  
|trinidad & tobago|TTO|en\-TT|  
|uk|GBR|en\-GB|  
|reino unido|GBR|en\-GB|  
|estados unidos|EUA|pt\-BR|  
|us|EUA|pt\-BR|  
  
## Consulte também  
 [Nomes de localidades, idiomas e cadeias de caracteres de país\/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [\_create\_locale, \_wcreate\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)