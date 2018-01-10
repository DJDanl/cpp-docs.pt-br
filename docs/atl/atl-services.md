---
title: "Serviços ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CServiceModule
dev_langs: C++
helpviewer_keywords:
- CServiceModule class
- COM objects, ATL
- services, ATL
- ATL services
ms.assetid: 8c09d1a8-7548-4d2c-947c-9d795a81659b
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d13eebbe96ba57c82e3bf1c360b0cb471a6bd975
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atl-services"></a>Serviços ATL
Para criar o objeto COM do ATL para que ele seja executado em um serviço, basta selecione o serviço (EXE) da lista de opções de servidor no Assistente de projeto de ATL. O assistente irá criar uma classe derivada de `CAtlServiceModuleT` para implementar o serviço.  
  
 Quando o objeto COM da ATL é criado como um serviço, ele só será registrado como um servidor local e não aparecerão na lista de serviços no painel de controle. Isso ocorre porque é mais fácil depurar o serviço como um servidor local como um serviço. Para instalá-lo como um serviço, execute o seguinte no prompt de comando:  
  
 `YourEXE` `.exe /Service`  
  
 Para desinstalá-lo, execute o seguinte:  
  
 `YourEXE` `.exe /UnregServer`  
  
 Os quatro primeiros tópicos desta seção discutem as ações que ocorrem durante a execução de `CAtlServiceModuleT` funções de membro. Esses tópicos exibidos na mesma sequência as funções são normalmente chamadas. Para melhorar a compreensão desses tópicos, é recomendável usar o código-fonte gerado pelo Assistente de projeto de ATL como referência. Esses quatro primeiros tópicos são:  
  

-   [A função CAtlServiceModuleT::Start](../atl/reference/catlservicemodulet-class.md#start)  
  
-   [A função CAtlServiceModuleT::ServiceMain](../atl/reference/catlservicemodulet-class.md#servicemain)  
  
-   [A função CAtlServiceModuleT::Run](../atl/reference/catlservicemodulet-class.md#run)  
  
-   [A função CAtlServiceModuleT::Handler](../atl/reference/catlservicemodulet-class.md#handler)  
  
 Os três tópicos discutem conceitos relacionados para desenvolver um serviço:  
  
-   [As entradas do registro](../atl/registry-entries.md) para serviços ATL  
  
-   [DCOMCNFG](../atl/dcomcnfg.md)  
  
-   [Dicas de depuração](../atl/debugging-tips.md) para serviços ATL  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)

