---
title: "Fun&#231;&#227;o de CAtlServiceModuleT::Start | Microsoft Docs"
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
  - "CServiceModule.Start"
  - "CServiceModule::Start"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de Início"
ms.assetid: b5193a23-41bc-42d2-8d55-3eb43dc62238
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de CAtlServiceModuleT::Start
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando o serviço é dirigido, **\_tWinMain** chama **CAtlServiceModuleT::WinMain**chama, que por sua vez `CAtlServiceModuleT::Start`.  
  
 `CAtlServiceModuleT::Start` configura de um vetor de estruturas de **SERVICE\_TABLE\_ENTRY** que mapeiam cada serviço para sua função de inicialização.  Essa matriz é passada à função da API do Win32, [StartServiceCtrlDispatcher](http://msdn.microsoft.com/library/windows/desktop/ms686324).  Em teoria, um EXE pode manipular vários serviços e a matriz pode ter vários frameworks de **SERVICE\_TABLE\_ENTRY** .  Atualmente, o entanto, os serviços de suporte ATL\- gerados apenas um serviço por EXE.  Portanto, o array tem uma única entrada que contém o nome e **\_ServiceMain** de serviço como a função de inicialização.  **\_ServiceMain** é uma função de membro estático de `CAtlServiceModuleT` que chama a função de membro não\-estático, `ServiceMain`.  
  
> [!NOTE]
>  A falha de **StartServiceCtrlDispatcher** \(SCM\) conectar ao gerenciador de controle de serviço provavelmente significa que o programa não estiver sendo executado como um serviço.  Em esse caso, o programa chama `CAtlServiceModuleT::Run` diretamente para que o programa possa executar como um servidor local.  Para obter mais informações sobre executar o programa como um servidor local, consulte [Dicas de depuração](../atl/debugging-tips.md).  
  
## Consulte também  
 [Serviços](../atl/atl-services.md)   
 [CAtlServiceModuleT::Start](../Topic/CAtlServiceModuleT::Start.md)