---
title: "Interfaces duais e eventos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces duais, eventos"
  - "eventos [C++], interfaces duais"
ms.assetid: bb382f7c-e885-4274-bf07-83f3602615d2
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interfaces duais e eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Embora seja possível criar uma interface de evento como um double, há um número bons motivos de design não fazer isso.  A principal motivo é que a origem do evento acionará somente o evento através de vtable ou através de `Invoke`, não ambos.  Se a fonte do evento aciona o evento como uma chamada vtable direto do método, os métodos de `IDispatch` serão usados e nunca é claro que a interface deve ter sido uma interface vtable pura.  Se a fonte do evento aciona o evento como uma chamada a `Invoke`, os métodos vtable serão usados e nunca é claro que a interface deve ter sido um dispinterface.  Se você definir o evento interface como duals, você irá requerer clientes implementar a parte de uma interface que nunca é usada.  
  
> [!NOTE]
>  Esse argumento não se aplica às interfaces duais, em geral.  De a perspectiva da implementação, duals é uma maneira rápida, conveniente, e bem suporte de implementar as interfaces que são acessíveis para uma ampla variedade de clientes.  
  
 Há motivos mais adiante evitar interfaces duais do evento; nem nem o Visual Basic Internet Explorer suportar\-los.  
  
## Consulte também  
 [Interfaces duais e ATL](../atl/dual-interfaces-and-atl.md)