---
title: "Empacotamento | Microsoft Docs"
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
  - "Interfaces COM, empacotamento"
  - "empacotamento"
  - "empacotamento, Interoperabilidade COM"
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Empacotamento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A técnica de empacotamento COM permite que as interfaces expostos por um objeto em um processo para ser usado em outro processo.  Em, empacotamento COM fornece o código \(ou o usa o código fornecido pelo realizador de interface\) para empacotar ambos os parâmetros de um método em um formato que pode ser movido em processos \(bem como, através do fio processos que executam em outros computadores\) e desembalar os parâmetros no extremo oposto.  Também, COM deve executar essas mesmas etapas no retorno de chamada.  
  
> [!NOTE]
>  Empacotamento não é geralmente necessário quando uma interface fornecida por um objeto está sendo usada no mesmo processo que o objeto.  Em o entanto, empacotamento pode ser necessário entre segmentos.  
  
## Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Marshaling Details](http://msdn.microsoft.com/library/windows/desktop/ms692621)