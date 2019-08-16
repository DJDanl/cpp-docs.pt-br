---
title: 'Função CAtlServiceModuleT:: Run'
ms.date: 11/04/2016
helpviewer_keywords:
- ATL services, security
ms.assetid: 42c010f0-e60e-459c-a63b-a53a24cda93b
ms.openlocfilehash: 0c35020996852731a8f22c15860d4cceb7a8bdb6
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491528"
---
# <a name="catlservicemoduletrun-function"></a>Função CAtlServiceModuleT:: Run

`Run`contém chamadas para `PreMessageLoop`, `RunMessageLoop`e `PostMessageLoop`. Depois de ser chamado `PreMessageLoop` , o primeiro armazena a ID do thread do serviço. O serviço usará essa ID para se fechar enviando uma mensagem WM_QUIT usando a função de API do Win32, [PostThreadMessage](/windows/win32/api/winuser/nf-winuser-postthreadmessagew).

`PreMessageLoop`em seguida `InitializeSecurity`, chama. Por padrão, `InitializeSecurity` o chama [CoInitializeSecurity](/windows/win32/api/combaseapi/nf-combaseapi-coinitializesecurity) com o descritor de segurança definido como NULL, o que significa que qualquer usuário tem acesso ao seu objeto.

Se você não quiser que o serviço especifique sua própria segurança, substituir `PreMessageLoop` e não chamar `InitializeSecurity`, e com, o com determinará as configurações de segurança do registro. Uma maneira conveniente de definir as configurações do registro é com o utilitário [DCOMCNFG](../atl/dcomcnfg.md) discutido mais adiante nesta seção.

Depois que a segurança é especificada, o objeto é registrado com com para que novos clientes possam se conectar ao programa. Por fim, o programa informa ao Gerenciador de controle de serviço (SCM) que ele está em execução e o programa entra em um loop de mensagem. O programa permanecerá em execução até postar uma mensagem de encerramento após o desligamento do serviço.

## <a name="see-also"></a>Consulte também

[Serviços](../atl/atl-services.md)<br/>
[Classe CSecurityDesc](../atl/reference/csecuritydesc-class.md)<br/>
[Classe CSid](../atl/reference/csid-class.md)<br/>
[Classe CDacl](../atl/reference/cdacl-class.md)<br/>
[CAtlServiceModuleT::Run](../atl/reference/catlservicemodulet-class.md#run)
