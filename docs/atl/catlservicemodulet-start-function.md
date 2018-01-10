---
title: "Função CAtlServiceModuleT::Start | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CServiceModule.Start
- CServiceModule::Start
dev_langs: C++
helpviewer_keywords: Start method
ms.assetid: b5193a23-41bc-42d2-8d55-3eb43dc62238
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5d4ee7899cda213bf8d8cfd529fd7609976e20d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="catlservicemoduletstart-function"></a>Função CAtlServiceModuleT::Start
Quando o serviço é executado, **twinmain** chamadas **CAtlServiceModuleT::WinMain**, que por sua vez chama `CAtlServiceModuleT::Start`.  
  
 `CAtlServiceModuleT::Start`define uma matriz de **SERVICE_TABLE_ENTRY** estruturas que mapeiam cada serviço para sua função de inicialização. Esta matriz é então passada para a função de API do Win32, [StartServiceCtrlDispatcher](http://msdn.microsoft.com/library/windows/desktop/ms686324). Em teoria, um EXE pode manipular vários serviços e a matriz pode ter vários **SERVICE_TABLE_ENTRY** estruturas. Atualmente, no entanto, um serviço gerado ATL suporta somente um serviço por EXE. Portanto, a matriz tem uma única entrada que contém o nome do serviço e **_ServiceMain** como a função de inicialização. **_ServiceMain** é uma função de membro estático do `CAtlServiceModuleT` que chama a função de membro não estático, `ServiceMain`.  
  
> [!NOTE]
>  Falha de **StartServiceCtrlDispatcher** para conectar-se ao controle de serviço manager (SCM) provavelmente significa que o programa não está em execução como um serviço. Nesse caso, o programa chama `CAtlServiceModuleT::Run` diretamente para que o programa pode ser executado como um servidor local. Para obter mais informações sobre como executar o programa como um servidor local, consulte [dicas de depuração](../atl/debugging-tips.md).  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)   
 [CAtlServiceModuleT::Start](../atl/reference/catlservicemodulet-class.md#start)

