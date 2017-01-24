---
title: "atributo nonextensible | Microsoft Docs"
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
  - "nonextensible"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces duais, atributo nonextensible"
  - "atributo nonextensible"
ms.assetid: 02a4a18b-ffd3-4d53-8fd1-feb1c05ad5ac
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# atributo nonextensible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se uma interface dupla não será estendida em tempo de execução \(ou seja, você não irá fornecer métodos ou propriedades através de **IDispatch::Invoke** que não estão disponíveis através de vtable\), você deve aplicar o atributo de **nonextensible** a sua definição de interface.  Esse atributo fornece informações para idiomas de cliente \(como Visual Basic\) que podem ser usados para ativar em tempo de compilação completa a verificação de código.  Se esse atributo não for fornecido, bugs podem continuar ocultos no código do cliente até o tempo de execução.  
  
 Para obter mais informações sobre o atributo de **nonextensible** e um exemplo, consulte [nonextensible](../Topic/nonextensible.md).  
  
## Consulte também  
 [Interfaces duais e ATL](../atl/dual-interfaces-and-atl.md)