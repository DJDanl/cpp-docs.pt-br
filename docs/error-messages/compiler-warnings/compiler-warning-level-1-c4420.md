---
title: "Aviso do compilador (n&#237;vel 1) C4420 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4420"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4420"
ms.assetid: 44a37754-7ddd-4764-a5f7-d33e05c20091
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4420
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador “”: operador não disponível, usando o operador “” em vez; verifique em tempo de execução pode ser afetado  
  
 Esse aviso é gerado quando você usa [\/RTCv](../../build/reference/rtc-run-time-error-checks.md) \(vetor novo\/exclusão que verifica\) e quando nenhuma forma de vetor for localizado.  Nesse caso, o formulário de vetor não é usado.  
  
 \/RTCv Para que funcione corretamente, o compilador sempre deve chamar o formulário de vetor de [novo](../../cpp/new-operator-cpp.md)\/[excluir](../../cpp/delete-operator-cpp.md) se a sintaxe de vetor foi usada.