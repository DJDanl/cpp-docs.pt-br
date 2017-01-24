---
title: "codecvt_utf8 | Microsoft Docs"
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
  - "std.codecvt_utf8"
  - "std::codecvt_utf8"
  - "codecvt_utf8"
  - "codecvt/std::codecvt_utf8"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe codecvt_utf8"
ms.assetid: 2a87478f-e2d4-4b8d-ad9c-00add01d1bb0
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# codecvt_utf8
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma faceta de [localidade](../standard-library/locale-class.md) que se converte entre os caracteres amplos codificados como UCS\-2 ou o UCS\-4, e um fluxo de bytes codificada como UTF\-8.  
  
## Sintaxe  
  
```  
template<  
    class Elem,  
    unsigned long Maxcode = 0x10ffff,  
    codecvt_mode Mode = (codecvt_mode)0  
>  
class codecvt_utf8 : public std::codecvt<Elem, char, StateType>  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Elem`|O tipo de elemento de ampla caractere.|  
|`Maxcode`|O número máximo de caracteres para a faceta de localidade.|  
|`Mode`|Informações de configuração para a faceta de localidade.|  
  
## Comentários  
 O fluxo de bytes pode ser gravado em um arquivo binário ou em um arquivo de texto.  
  
## Requisitos  
 codecvt \<de**Cabeçalho:** \>  
  
 **Namespace:** std