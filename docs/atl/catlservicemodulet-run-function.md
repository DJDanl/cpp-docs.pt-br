---
title: Função CAtlServiceModuleT::Run | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- CServiceModule::Run
- CServiceModule.Run
- CSecurityDescriptor
dev_langs:
- C++
helpviewer_keywords:
- ATL services, security
ms.assetid: 42c010f0-e60e-459c-a63b-a53a24cda93b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a07ad6b09fa10a81b500625531226dc18fc6281a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32355119"
---
# <a name="catlservicemoduletrun-function"></a>Função CAtlServiceModuleT::Run
**Executar** contém chamadas para `PreMessageLoop`, `RunMessageLoop`, e `PostMessageLoop`. Após a chamada, `PreMessageLoop` primeiro armazena a ID do thread. do serviço O serviço usará essa ID para se fechar enviando um **WM_QUIT** usando a função de API do Win32, [PostThreadMessage](http://msdn.microsoft.com/library/windows/desktop/ms644946).  
  
 `PreMessageLoop` em seguida, chama `InitializeSecurity`. Por padrão, `InitializeSecurity` chamadas [CoInitializeSecurity](http://msdn.microsoft.com/library/windows/desktop/ms693736) com o descritor de segurança definido como NULL, o que significa que qualquer usuário tenha acesso ao seu objeto.  
  
 Se você não quiser que o serviço para especificar sua própria segurança, substitua `PreMessageLoop` e não chamar `InitializeSecurity`, e COM, em seguida, irá determinar as configurações de segurança do registro. É uma maneira conveniente de configurar as configurações do registro com o [DCOMCNFG](../atl/dcomcnfg.md) utilitário discutido mais adiante nesta seção.  
  
 Depois que a segurança é especificada, o objeto é registrado em com para que novos clientes podem se conectar ao programa. Por fim, o programa informa o Gerenciador de controle de serviços (SCM) que está em execução e o programa inserirá um loop de mensagem. O programa permanece em execução até que ele envia uma mensagem de saída durante o desligamento do serviço.  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)   
 [Classe CSecurityDesc](../atl/reference/csecuritydesc-class.md)   
 [Classe de CSid](../atl/reference/csid-class.md)   
 [Classe CDacl](../atl/reference/cdacl-class.md)   
 [CAtlServiceModuleT::Run](../atl/reference/catlservicemodulet-class.md#run)

