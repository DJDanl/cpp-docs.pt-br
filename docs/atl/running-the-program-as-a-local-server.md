---
title: "Executando o programa como um servidor local | Microsoft Docs"
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
  - "Serviços ATL, executar como servidores locais"
  - "depuração [ATL], serviços em execução como o servidor local"
ms.assetid: eb9701e6-e2a8-4666-897f-0c893aec8ac7
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Executando o programa como um servidor local
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se executar o programa como um serviço é incómodo, você pode temporariamente modificar o Registro de modo que o programa seja executado como um servidor local normal.  Renomear simplesmente o valor de `LocalService` em seu AppID a `_LocalService` e certifique\-se de que a chave de `LocalServer32` em seu CLSID está definida corretamente.  \(Observe que DCOMCNFG usando para especificar que seu aplicativo será executado em um computador diferente renomeia sua chave de `LocalServer32` a `_LocalServer32`.\) Executar o programa como um servidor local recebe a mais de alguns segundos na inicialização como a chamada a **StartServiceCtrlDispatcher** em `CAtlServiceModuleT::Start` tem alguns segundos antes que falhou.  
  
## Consulte também  
 [Dicas de depuração](../atl/debugging-tips.md)