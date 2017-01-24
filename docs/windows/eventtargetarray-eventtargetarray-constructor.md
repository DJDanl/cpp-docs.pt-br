---
title: "Construtor EventTargetArray::EventTargetArray | Microsoft Docs"
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
  - "event/Microsoft::WRL::Details::EventTargetArray::EventTargetArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "EventTargetArray, o construtor"
ms.assetid: 6c6d3737-3cd3-4515-a8f6-d27901bb8ed2
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor EventTargetArray::EventTargetArray
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
EventTargetArray(  
   _Out_ HRESULT* hr,  
   size_t items  
);  
```  
  
#### Parâmetros  
 `hr`  
 Após operações deste construtor, o parâmetro `hr` indica se alocação da matriz teve sucesso ou falhou.  A tabela a seguir lista os valores possíveis para `hr`.  
  
 S\_OK  
 A operação foi bem\-sucedida.  
  
 E\_OUTOFMEMORY  
 A memória não pôde ser alocada para a matriz.  
  
 S\_FALSE  
 O parâmetro `items` é menor ou igual a zero.  
  
 `items`  
 O número de elementos da matriz a ser atribuído.  
  
## Comentários  
 Inicializa uma nova instância da classe de EventTargetArray.  
  
 EventTargetArray é usado para manter uma matriz de manipuladores de eventos em um objeto de EventSource.  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Classe EventTargetArray](../windows/eventtargetarray-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)