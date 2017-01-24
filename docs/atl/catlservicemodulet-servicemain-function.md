---
title: "Fun&#231;&#227;o de CAtlServiceModuleT::ServiceMain | Microsoft Docs"
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
  - "ServiceMain"
  - "CServiceModule::ServiceMain"
  - "CServiceModule.ServiceMain"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de ServiceMain"
ms.assetid: f21408c1-1919-4dec-88d8-bf5b39ac9808
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de CAtlServiceModuleT::ServiceMain
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O gerenciador \(SCM\) do controle de serviço chama `ServiceMain` quando você abre o aplicativo do painel de controle de serviços, selecione o serviço, e clique **Iniciar**.  
  
 Após SCM chama `ServiceMain`, um serviço deve dar a SCM uma função do manipulador.  Essa função deixa SCM obter o status de serviço e passar instruções específicas \(como pausar ou parar\).  SCM obter essa função quando passa **\_Handler** à função da API do Win32, [RegisterServiceCtrlHandler](http://msdn.microsoft.com/library/windows/desktop/ms685054)de serviço.  \(**\_Handler** é uma função de membro estático que chama a função de membro [manipulador](../Topic/CAtlServiceModuleT::Handler%20Function.md)de não\-estáticos.\)  
  
 Em a inicialização, um serviço deve também informar SCM de seu status atual.  Isso **SERVICE\_START\_PENDING** passando à função da API do Win32, [SetServiceStatus](http://msdn.microsoft.com/library/windows/desktop/ms686241).  
  
 `ServiceMain` então chama `CAtlExeModuleT::InitializeCom`, que chama a função [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279)da API do Win32.  Por padrão, `InitializeCom` passa o sinalizador de **COINIT\_MULTITHREADED** à função.  Este sinalizador que indica o programa é de segmentação livre ser um servidor.  
  
 Agora, `CAtlServiceModuleT::Run` é chamado para realizar o trabalho do serviço.  **Executar** continuará a ser executado até que o serviço está parado.  
  
## Consulte também  
 [Serviços](../atl/atl-services.md)   
 [CAtlServiceModuleT::ServiceMain](../Topic/CAtlServiceModuleT::ServiceMain.md)