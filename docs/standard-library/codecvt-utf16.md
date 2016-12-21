---
title: "codecvt_utf16 | Microsoft Docs"
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
  - "codecvt/std::codecvt_utf16"
  - "std::codecvt_utf16"
  - "std.codecvt_utf16"
  - "codecvt_utf16"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe codecvt_utf16"
ms.assetid: a9897f98-f84d-4db6-90ad-858b2727570c
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# codecvt_utf16
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma [localidade](../standard-library/locale-class.md) faceta converte entre caracteres largos codificados como UCS\-2 ou UCS\-4 e um fluxo de bytes codificado como UTF\-16LE ou UTF\-16BE.  
  
## Sintaxe  
  
```  
template<  
    class Elem,  
    unsigned long Maxcode = 0x10ffff,  
    codecvt_mode Mode = (codecvt_mode)0  
>  
class codecvt_utf16 : public std::codecvt<Elem, char, StateType>  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`Elem`|O tipo de elemento de caractere largo.|  
|`Maxcode`|O número máximo de caracteres para a faceta de localidade.|  
|`Mode`|Informações de configuração para a faceta de localidade.|  
  
## Comentários  
 Essa classe de modelo converte entre caracteres largos codificados como UCS\-2 ou UCS\-4 e um fluxo de bytes codificado como UTF\-16LE, se `Mode & little_endian`, ou caso contrário, o UTF\-16BE.  
  
 O fluxo de bytes deve ser gravado em um arquivo binário. ele pode estar corrompido se gravado em um arquivo de texto.  
  
## Requisitos  
 **Cabeçalho:** \< codecvt \>  
  
 **Namespace:** std