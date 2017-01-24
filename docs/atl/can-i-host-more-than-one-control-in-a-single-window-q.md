---
title: "Eu hospedar mais de um controle em uma &#250;nica janela? | Microsoft Docs"
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
  - "controles [ATL], hospedagem múltipla"
  - "controles do Windows [C++], hospedagem múltipla"
ms.assetid: 3a967a1a-7e7e-42e3-8eed-f7bde912363f
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Eu hospedar mais de um controle em uma &#250;nica janela?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Não é possível hospedar mais de um controle em uma única janela host ATL. Cada janela do host deve conter exatamente um controle em um momento \(Isso permite um mecanismo simples para lidar com propriedades de ambiente reflexão e por controle de mensagem\). No entanto, se você precisar que o usuário veja vários controles em uma única janela, é uma simples questão de criar várias janelas de host como filhos dessa janela.  
  
## Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)