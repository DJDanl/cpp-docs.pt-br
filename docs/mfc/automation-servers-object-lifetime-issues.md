---
title: 'Servidores de automação: Problemas de vida útil do objeto | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- objects [MFC], lifetime
- lifetime, automation server
- Automation servers, object lifetime
- servers, lifetime of Automation
ms.assetid: 342baacf-4015-4a0e-be2f-321424f1cb43
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e27812c20a64f5472c29a66298bcdec30bf4ef2b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341794"
---
# <a name="automation-servers-object-lifetime-issues"></a>Servidores de automação: problemas de tempo de vida do objeto
Quando um cliente de automação cria ou um item OLE é ativado, o servidor passa o cliente um ponteiro para o objeto. O cliente estabelece uma referência ao objeto por meio de uma chamada para a função OLE [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379). Essa referência está em vigor até que o cliente chama [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms682317). (Os aplicativos cliente escritos com classes OLE da biblioteca Microsoft Foundation Class não precisam fazer essas chamadas; a estrutura faz isso). O sistema OLE e o próprio servidor podem estabelecer referências ao objeto. Um servidor não deve destruir um objeto como referências externas ao objeto permanecem em vigor.  
  
 A estrutura mantém uma contagem interna do número de referências a qualquer objeto de servidor derivado de [CCmdTarget](../mfc/reference/ccmdtarget-class.md). Esse contador é atualizado quando um cliente de automação ou outra entidade adiciona ou libera uma referência ao objeto.  
  
 Quando a contagem de referência se torna a 0, o framework chama a função virtual [CCmdTarget::OnFinalRelease](../mfc/reference/ccmdtarget-class.md#onfinalrelease). A implementação padrão Esta função chama o **excluir** operador para excluir este objeto.  
  
 A biblioteca Microsoft Foundation Class fornece recursos adicionais para controlar o comportamento do aplicativo quando os clientes externos têm referências a objetos do aplicativo. Além de manter uma contagem de referências para cada objeto, servidores mantém uma contagem global de objetos ativos. As funções globais [AfxOleLockApp](../mfc/reference/application-control.md#afxolelockapp) e [AfxOleUnlockApp](../mfc/reference/application-control.md#afxoleunlockapp) atualizar a contagem do aplicativo de objetos ativos. Se essa conta é diferente de zero, o aplicativo não encerra quando o usuário escolhe o fechamento do menu do sistema ou sair no menu arquivo. Em vez disso, a janela do aplicativo principal é oculta (mas não destruída) até que todos os pendentes cliente solicitações foram concluídas. Normalmente, `AfxOleLockApp` e `AfxOleUnlockApp` são chamados em construtores e destruidores, respectivamente, de classes que oferecem suporte à automação.  
  
 Às vezes, circunstâncias forçar o servidor seja finalizado enquanto um cliente ainda tem uma referência a um objeto. Por exemplo, um recurso do qual depende o servidor pode se tornar indisponível, fazendo com que o servidor encontrar um erro. O usuário também pode fechar um documento do servidor que contém os objetos aos quais outros aplicativos tem referências.  
  
 No SDK do Windows, consulte `IUnknown::AddRef` e `IUnknown::Release`.  
  
## <a name="see-also"></a>Consulte também  
 [Servidores de automação](../mfc/automation-servers.md)   
 [AfxOleCanExitApp](../mfc/reference/application-control.md#afxolecanexitapp)

