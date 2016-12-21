---
title: "Evitando exce&#231;&#245;es no desligamento do CLR durante o consumo dos objetos COM criados com /clr | Microsoft Docs"
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
  - "Opção de compilador /clr [C++], exceções de encerramento CLR"
  - "Opção de compilador /clr [C++], objetos COM"
  - "exceções de encerramento [C++]"
  - "interoperabilidade [C++], exceções de encerramento CLR"
  - "interoperabilidade [C++], exceções de encerramento CLR"
  - "assemblies mistos [C++], exceções de encerramento CLR"
ms.assetid: 41249d83-4b51-4e46-866f-27f475f2498c
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Evitando exce&#231;&#245;es no desligamento do CLR durante o consumo dos objetos COM criados com /clr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma vez que Common Language Runtime \(CLR\) entrará no modo de desligamento, as funções nativos acesso limitado aos serviços de CLR.  Ao tentar chamar a versão em um objeto COM compilado com **\/clr**CLR, faz a transição para o código nativo e faz a transição novamente no código gerenciado para atender à chamada de IUnknown::Release \(que está definido no código gerenciado\).  CLR evita a chamada de novo no código gerenciado desde que está no modo de desligamento.  
  
 Para resolver isso, verifique se os destruidores chamados dos métodos de versão contém apenas o código nativo.  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)