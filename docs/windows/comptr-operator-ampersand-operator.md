---
title: "Operador ComPtr::operator&amp; | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::operator&"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador operator&"
ms.assetid: 2d77fda6-f4b2-45c1-8a0e-fbc355013531
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador ComPtr::operator&amp;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Libera a interface associada a este objeto de `ComPtr` e recupera o endereço do objeto de `ComPtr` .  
  
## Sintaxe  
  
```cpp  
Details::ComPtrRef<WeakRef> operator&()  
  
const Details::ComPtrRef<const WeakRef> operator&() const  
```  
  
## Valor de Retorno  
 Uma referência da `ComPtr`atual.  
  
## Comentários  
 Esse método é diferente de [ComPtr::GetAddressOf](../Topic/ComPtr::GetAddressOf%20Method.md) que esse método libera uma referência ao ponteiro da interface.  Use `ComPtr::GetAddressOf` quando você precisar o endereço do ponteiro de interface mas o não desejar liberar essa interface.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)