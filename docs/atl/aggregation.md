---
title: "Agregado | Microsoft Docs"
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
  - "objetos agregados [C++]"
  - "agregação [C++]"
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Agregado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há vezes quando o realizador de um objeto de deseja aproveitar os serviços oferecidos por outros, objeto de prebuilt.  Além de isso, gostaria do segundo objeto de aparecer como uma parte natural do primeiro.  Obtém COM ambas essas metas com a retenção e a agregação.  
  
 A agregação significa que o objeto recipiente \(externo\) cria o objeto contido \(interno\) como parte do processo de criação e interfaces interno do objeto são expostos pelo externo.  Um objeto permite\-se que é aggregatable ou não.  Se é, então deve seguir determinadas regras para que a agregação funcione corretamente.  
  
 Primeiro, qualquer método de **IUnknown** chama o objeto deve delegar contido no objeto contêiner.  
  
## Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Reusing Objects](http://msdn.microsoft.com/library/windows/desktop/ms678443)