---
title: 'Servidores de automação: Problemas de tempo de vida do objeto'
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], lifetime
- lifetime, automation server
- Automation servers, object lifetime
- servers, lifetime of Automation
ms.assetid: 342baacf-4015-4a0e-be2f-321424f1cb43
ms.openlocfilehash: f9dbc6e4f321ba10fdffa013c158d53b84331e30
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293570"
---
# <a name="automation-servers-object-lifetime-issues"></a>Servidores de automação: Problemas de tempo de vida do objeto

Quando um cliente de automação cria ou ativa um item OLE, o servidor passa o cliente um ponteiro para esse objeto. O cliente estabelece uma referência ao objeto por meio de uma chamada para a função OLE [IUnknown:: AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref). Essa referência está em vigor até que o cliente chama [IUnknown:: Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). (Os aplicativos cliente escritos com classes OLE da biblioteca Microsoft Foundation Class não precisam fazer essas chamadas; a estrutura faz isso). O sistema OLE e o próprio servidor podem estabelecer referências ao objeto. Um servidor não deve destruir um objeto, desde que as referências externas ao objeto permanecem em vigor.

O framework mantém uma contagem interna do número de referências a qualquer objeto de servidor derivados [CCmdTarget](../mfc/reference/ccmdtarget-class.md). Essa contagem é atualizada quando um cliente de automação ou outra entidade adiciona ou libera uma referência ao objeto.

Quando a contagem de referência se torna 0, o framework chama a função virtual [CCmdTarget::OnFinalRelease](../mfc/reference/ccmdtarget-class.md#onfinalrelease). A implementação padrão dessa função chama o **excluir** operador excluir este objeto.

A biblioteca Microsoft Foundation Class fornece recursos adicionais para controlar o comportamento do aplicativo quando os clientes externos têm referências a objetos do aplicativo. Além de manter uma contagem de referências para cada objeto, servidores de mantenham uma contagem global de objetos ativos. As funções globais [AfxOleLockApp](../mfc/reference/application-control.md#afxolelockapp) e [AfxOleUnlockApp](../mfc/reference/application-control.md#afxoleunlockapp) atualizar a contagem do aplicativo de objetos ativos. Se essa contagem é diferente de zero, o aplicativo não termina quando o usuário escolhe o fechamento do menu do sistema ou sair do menu arquivo. Em vez disso, a janela do aplicativo principal é oculta (mas não destruída) até que todos os pendentes cliente solicitações foram concluídas. Normalmente, `AfxOleLockApp` e `AfxOleUnlockApp` são chamados nos construtores e destruidores, respectivamente, de classes que oferecem suporte à automação.

Às vezes, circunstâncias forçar o servidor terminar enquanto um cliente ainda tem uma referência a um objeto. Por exemplo, um recurso do qual o servidor depende pode se tornar indisponível, fazendo com que o servidor ao encontrar um erro. O usuário também pode fechar um documento do servidor que contém os objetos aos quais outros aplicativos tem referências.

No SDK do Windows, consulte `IUnknown::AddRef` e `IUnknown::Release`.

## <a name="see-also"></a>Consulte também

[Servidores de automação](../mfc/automation-servers.md)<br/>
[AfxOleCanExitApp](../mfc/reference/application-control.md#afxolecanexitapp)
