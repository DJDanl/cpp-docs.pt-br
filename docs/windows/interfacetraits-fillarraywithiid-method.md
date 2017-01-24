---
title: "M&#233;todo InterfaceTraits::FillArrayWithIid | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::InterfaceTraits::FillArrayWithIid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FillArrayWithIid"
ms.assetid: 73583177-adc9-4fcb-917d-fa7e6d07c990
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo InterfaceTraits::FillArrayWithIid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
__forceinline static void FillArrayWithIid(  
   _Inout_ unsigned long &index,  
   _In_ IID* iids  
);  
  
```  
  
#### Parâmetros  
 `index`  
 Ponteiro para um campo que contém um valor de índice de base zero.  
  
 `iids`  
 Uma matriz de IDs da interface.  
  
## Comentários  
 Atribui a ID da interface de `Base` ao elemento da matriz especificado pelo argumento de índice.  
  
 O contador ao nome desta API, apenas um elemento da matriz é alterado; não a matriz inteira.  
  
 Para obter mais informações sobre como `Base`, consulte a seção pública de Typedefs em [Estrutura InterfaceTraits](../windows/interfacetraits-structure.md).  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)