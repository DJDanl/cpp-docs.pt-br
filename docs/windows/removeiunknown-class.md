---
title: "Classe RemoveIUnknown | Microsoft Docs"
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
  - "client/Microsoft::WRL::Details::RemoveIUnknown"
dev_langs: 
  - "C++"
ms.assetid: 998e711a-7d1a-44c6-a016-e6167aa40863
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe RemoveIUnknown
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   typename T  
>  
struct RemoveIUnknown;  
  
template <  
   typename T  
>  
class RemoveIUnknown : public T;  
```  
  
#### Parâmetros  
 `T`  
 Uma classe.  
  
## Comentários  
 Faz um tipo que é equivalente a um tipo com base em `IUnknown`, mas tem `QueryInterface`nonvirtual, `AddRef`, e as funções de membro de `Release` .  
  
 Por padrão, os métodos de COM o fornecem `QueryInterface`virtual, `AddRef`, e os métodos de versão.  No entanto, `ComPtr` não requer a sobrecarga de métodos virtuais.  `RemoveIUnknown` elimina essa sobrecarga fornecendo `QueryInterface`particular, nonvirtual, `AddRef`, e os métodos de `Release` .  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`ReturnType`|Um sinônimo para um tipo que é equivalente ao parâmetro `T` do modelo mas tem membros nonvirtual IUnknown.|  
  
## Hierarquia de Herança  
 `T`  
  
 `RemoveIUnknown`  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)