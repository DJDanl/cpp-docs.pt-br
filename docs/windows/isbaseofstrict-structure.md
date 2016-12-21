---
title: "Estrutura IsBaseOfStrict | Microsoft Docs"
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
  - "internal/Microsoft::WRL::Details::IsBaseOfStrict"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IsBaseOfStrict"
ms.assetid: 6fed7366-c8d4-4991-b4fb-43ed93f8e1bf
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IsBaseOfStrict
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   typename Base,  
   typename Derived  
>  
  
struct IsBaseOfStrict;  
template <  
   typename Base  
>  
struct IsBaseOfStrict<Base, Base>;  
```  
  
#### Parâmetros  
 `Base`  
 O tipo de base.  
  
 `Derived`  
 O tipo derivado.  
  
## Comentários  
 Testa se um tipo é a base de outro.  
  
 O primeiro modelo testa se um tipo é derivado de um tipo de base, que pode resultar **true** ou **false**.  O segundo modelo testa se um tipo é derivado do, que gerencie sempre **false**.  
  
## Membros  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante IsBaseOfStrict::value](../Topic/IsBaseOfStrict::value%20Constant.md)|Indica se um tipo é a base de outro.|  
  
## Hierarquia de Herança  
 `IsBaseOfStrict`  
  
## Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)