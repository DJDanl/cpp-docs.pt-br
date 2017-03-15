---
title: "Servi&#231;os ATL | Microsoft Docs"
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
  - "CServiceModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CServiceModule"
  - "Objetos COM, ATL"
  - "serviços ATL"
  - "Serviços ATL"
ms.assetid: 8c09d1a8-7548-4d2c-947c-9d795a81659b
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servi&#231;os ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para criar o objeto COM da ATL para que ele seja executado em um serviço, basta selecione o serviço \(EXE\) da lista de opções de servidor no assistente ATL Project. O assistente irá criar uma classe derivada de `CAtlServiceModuleT` para implementar o serviço.  
  
 Quando o objeto COM da ATL é criado como um serviço, ele só será registrado como um servidor local e não aparecerá na lista de serviços no painel de controle. Isso ocorre porque é mais fácil depurar o serviço como um servidor local como um serviço. Para instalá\-lo como um serviço, execute o seguinte no prompt de comando:  
  
 `YourEXE` `.exe /Service`  
  
 Para desinstalá\-lo, execute o seguinte:  
  
 `YourEXE` `.exe /UnregServer`  
  
 Os primeiros quatro tópicos desta seção discutem as ações que ocorrem durante a execução de `CAtlServiceModuleT` funções de membro. Esses tópicos exibidos na mesma sequência as funções são normalmente chamadas. Para melhorar a compreensão desses tópicos, é uma boa idéia usar o código\-fonte gerado pelo assistente ATL Project como referência. Esses primeiros quatro tópicos são:  
  
-   [A função CAtlServiceModuleT::Start](../atl/catlservicemodulet-start-function.md)  
  
-   [A função CAtlServiceModuleT::ServiceMain](../atl/catlservicemodulet-servicemain-function.md)  
  
-   [A função CAtlServiceModuleT::Run](../atl/catlservicemodulet-run-function.md)  
  
-   [A função CAtlServiceModuleT::Handler](../Topic/CAtlServiceModuleT::Handler%20Function.md)  
  
 Os três últimos tópicos discutem os conceitos relacionados ao desenvolvimento de um serviço:  
  
-   [As entradas do registro](../atl/registry-entries.md) para serviços ATL  
  
-   [DCOMCNFG](../Topic/DCOMCNFG.md)  
  
-   [Dicas de depuração](../atl/debugging-tips.md) para serviços ATL  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)