---
title: 'Função catlservicemodulet:: Start | Microsoft Docs'
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
ms.openlocfilehash: 5ef614f4cbc3f097e6f790a49c0b599817f9b59c
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37849171"
---
# <a name="catlservicemoduletstart-function"></a>Função catlservicemodulet:: Start
Quando o serviço é executado, `_tWinMain` chamadas `CAtlServiceModuleT::WinMain`, que por sua vez chama `CAtlServiceModuleT::Start`.  
  
 `CAtlServiceModuleT::Start` define uma matriz de `SERVICE_TABLE_ENTRY` estruturas que mapeiam cada serviço para sua função de inicialização. Essa matriz é então passado para a função de API do Win32 [StartServiceCtrlDispatcher](http://msdn.microsoft.com/library/windows/desktop/ms686324). Em teoria, um EXE pudesse lidar com vários serviços e a matriz pode ter vários `SERVICE_TABLE_ENTRY` estruturas. Atualmente, no entanto, um serviço gerado pelo ATL dá suporte a apenas um serviço por EXE. Portanto, a matriz tem uma única entrada que contém o nome do serviço e `_ServiceMain` como a função de inicialização. `_ServiceMain` é uma função de membro estático do `CAtlServiceModuleT` que chama a função de membro não estático, `ServiceMain`.  
  
> [!NOTE]
>  Falha de `StartServiceCtrlDispatcher` para conectar-se para o controle do service manager (SCM) provavelmente significa que o programa não está em execução como um serviço. Nesse caso, o programa chama `CAtlServiceModuleT::Run` diretamente para que o programa pode ser executado como um servidor local. Para obter mais informações sobre como executar o programa como um servidor local, consulte [dicas de depuração](../atl/debugging-tips.md).  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)   
 [Catlservicemodulet:: Start](../atl/reference/catlservicemodulet-class.md#start)

