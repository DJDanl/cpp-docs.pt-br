---
title: Função CAtlServiceModuleT::Start | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- CServiceModule.Start
- CServiceModule::Start
dev_langs:
- C++
helpviewer_keywords:
- Start method
ms.assetid: b5193a23-41bc-42d2-8d55-3eb43dc62238
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: da8d7358c634416941a551c93c6a2772549a3fd2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357271"
---
# <a name="catlservicemoduletstart-function"></a>Função CAtlServiceModuleT::Start
Quando o serviço é executado, **twinmain** chamadas **CAtlServiceModuleT::WinMain**, que por sua vez chama `CAtlServiceModuleT::Start`.  
  
 `CAtlServiceModuleT::Start` define uma matriz de **SERVICE_TABLE_ENTRY** estruturas que mapeiam cada serviço para sua função de inicialização. Esta matriz é então passada para a função de API do Win32, [StartServiceCtrlDispatcher](http://msdn.microsoft.com/library/windows/desktop/ms686324). Em teoria, um EXE pode manipular vários serviços e a matriz pode ter vários **SERVICE_TABLE_ENTRY** estruturas. Atualmente, no entanto, um serviço gerado ATL suporta somente um serviço por EXE. Portanto, a matriz tem uma única entrada que contém o nome do serviço e **_ServiceMain** como a função de inicialização. **_ServiceMain** é uma função de membro estático do `CAtlServiceModuleT` que chama a função de membro não estático, `ServiceMain`.  
  
> [!NOTE]
>  Falha de **StartServiceCtrlDispatcher** para conectar-se ao controle de serviço manager (SCM) provavelmente significa que o programa não está em execução como um serviço. Nesse caso, o programa chama `CAtlServiceModuleT::Run` diretamente para que o programa pode ser executado como um servidor local. Para obter mais informações sobre como executar o programa como um servidor local, consulte [dicas de depuração](../atl/debugging-tips.md).  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)   
 [CAtlServiceModuleT::Start](../atl/reference/catlservicemodulet-class.md#start)

