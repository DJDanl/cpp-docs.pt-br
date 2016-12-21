---
title: "Cadeias de caracteres de idioma | Microsoft Docs"
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
  - "cadeias de caracteres de idioma"
ms.assetid: bbee63b1-af0b-4e44-9eaf-dd3e265c05fd
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Cadeias de caracteres de idioma
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções de `setlocale` e de `_create_locale` podem usar os idiomas com suporte de API NLS do windows em sistemas operacionais que não usam a página de código de Unicode.  Para obter uma lista dos idiomas com suporte na versão do sistema operacional, [Referência \(NLS\) a API do suporte ao idioma nacional](http://msdn.microsoft.com/goglobal/bb896001.aspx)consulte.  A cadeia de caracteres de idioma pode ser qualquer um dos valores nas colunas de **Idioma** e de **Abreviação do nome do idioma** da lista de idiomas com suporte.  A implementação da biblioteca de tempo de execução C também oferece suporte a essas cadeias de caracteres de linguagem:  
  
|Cadeia de caracteres de idioma|Nome da localidade equivalente|  
|------------------------------------|------------------------------------|  
|americano|pt\-BR|  
|inglês americano|pt\-BR|  
|americano\-inglês|pt\-BR|  
|australiano|AU pt\-br|  
|belga|É NL\-|  
|canadense|Pt\-br CA|  
|chh|zh\-HK|  
|qui|Zh\-sg|  
|chinês|zh|  
|chinês Hong Kong|zh\-HK|  
|chinês simplificado|zh\-CN|  
|chinês cingapura|Zh\-sg|  
|chinês tradicional|Zh\-TW|  
|holandês\-belga|É NL\-|  
|inglês americano|pt\-BR|  
|portuguese \- aus|AU pt\-br|  
|inglês Belize|Pt\-br BZ|  
|inglês pode|Pt\-br CA|  
|inglês caribe|en\-029|  
|inglês ire|Pt\-br o IE|  
|inglês Jamaica|Pt\-br JM|  
|portuguese \- nz|en\-NZ|  
|inglês sul África|en\-ZA|  
|inglês trinidad y tobago|en\-TT|  
|inglês\-Reino Unido|en\-GB|  
|nós em inglês|pt\-BR|  
|inglês\-EUA|pt\-BR|  
|francês\-belga|É franco\-|  
|francês\-canadense|Franco\-CA|  
|francês\-Luxemburgo|Franco\-LU|  
|francês\-suíço|Franco\-CH|  
|alemão\-austríaco|Eliminação de ON|  
|alemão\-lichtenstein|Eliminação de LI|  
|alemão\-Luxemburgo|Eliminação de LU|  
|alemão\-suíço|Eliminação de CH|  
|irlandês\-inglês|Pt\-br o IE|  
|italiano\-suíço|\-CH|  
|norueguês|não|  
|norueguês\-bokmal|NB\-NO \- NONE.|  
|norueguês\-nynorsk|Nn\-no|  
|português\- português|pt\-BR|  
|espanhol\-Argentina|Es\- aérea|  
|espanhol\-Bolívia|Es\-BO|  
|espanhol\-pimentão|Es\-CL|  
|espanhol\-Colômbia|Es\-CO|  
|sofisticada de espanhol\- costela|Es\-CR|  
|república espanhol\-dominiquense|Es\-FAÇA|  
|espanhol\-Equador|Es\-EC|  
|espanhol\-EL Salvador|Es\-SV|  
|espanhol\-Guatemala|Es\-GT|  
|espanhol\-Honduras|Es\-HN|  
|espanhol\-mexicano|Es\-MX|  
|espanhol\-moderno|Es\-es|  
|espanhol\-Nicarágua|Es\-NI|  
|espanhol\-Panamá|Es\-PA|  
|espanhol\-Paraguai|Es\-PY|  
|espanhol\-Peru|Es\-PE|  
|avançado puerto \- espanhol|es\-PR|  
|espanhol\-Uruguai|Es\-UY|  
|espanhol\-Venezuela|Es\-VE|  
|sueco\- finlândia|SV\-FI|  
|suíço|Eliminação de CH|  
|uk|en\-GB|  
|us|pt\-BR|  
|EUA|pt\-BR|  
  
## Consulte também  
 [Nomes de localidades, idiomas e cadeias de caracteres de país\/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Cadeias de caracteres de país\/região](../c-runtime-library/country-region-strings.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [\_create\_locale, \_wcreate\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)