---
title: "Construtor HStringReference::HStringReference | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "corewrappers/Microsoft::WRL::Wrappers::HStringReference::HStringReference"
dev_langs: 
  - "C++"
ms.assetid: 29f5fe11-3928-4f60-9861-f0894247bfcb
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor HStringReference::HStringReference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe HStringReference.  
  
## Sintaxe  
  
```cpp  
  
    template<unsigned int sizeDest>  
    HStringReference(wchar_t const (&str)[ sizeDest]) throw();  
  
    template<unsigned int sizeDest>  
    HStringReference(wchar_t const (&str)[ sizeDest],   
unsigned int len)  
       throw();  
  
    HStringReference(HStringReference&& other) throw();  
  
```  
  
#### Parâmetros  
 `sizeDest`  
 Um parâmetro do modelo que especifica o tamanho do buffer de HStringReference de destino.  
  
 `str`  
 Uma referência a uma cadeia de caracteres de ampla caractere.  
  
 `len`  
 O comprimento máximo do buffer do parâmetro de `str` a ser usado na operação.  Se o parâmetro de `len` não for especificado, o parâmetro inteiro de `str` será usado.  Se `len` é maior que `sizeDest`, `len` está definido como `sizeDest`\-1.  
  
 `other`  
 Outro objeto de HStringReference.  
  
## Comentários  
 O primeiro construtor inicializa um novo objeto a partir desse HStringReference o mesmo tamanho que o parâmetro `str`.  
  
 O segundo construtor inicializa um novo objeto de HStringReference que o specifeid de tamanho pelo parâmetro `len`.  
  
 O terceiro construtor inicializa um novo objeto de HStringReference ao valor do parâmetro de `other`, e destruição no parâmetro de `other` .  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)