---
title: "codecvt_utf8_utf16 | Microsoft Docs"
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
  - "codecvt_utf8_utf16"
  - "codecvt/std::cvt_utf8_utf16"
  - "std::codecvt_utf8_utf16"
  - "std.codecvt_utf8_utf16"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe codecvt_utf8_utf16"
ms.assetid: 4c12c881-5dba-4e39-b338-0b9caff5af29
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# codecvt_utf8_utf16
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma faceta de [localidade](../standard-library/locale-class.md) que se converte entre os caracteres amplos codificados como UTF\-16 e um fluxo de bytes codificada como UTF\-8.  
  
## Sintaxe  
  
```  
template<  
    class Elem,  
    unsigned long Maxcode = 0x10ffff,  
    codecvt_mode Mode = (codecvt_mode)0  
>  
class codecvt_utf8_utf16 : public _STD codecvt<Elem, char, StateType>  
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