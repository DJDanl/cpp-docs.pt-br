---
title: "Servidores de automa&#231;&#227;o: problemas de tempo de vida do objeto | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Servidores de automação, vida útil do objeto"
  - "tempo de vida, servidor de automação"
  - "objetos [C++], tempo de vida"
  - "servidores, tempo de vida da Automação"
ms.assetid: 342baacf-4015-4a0e-be2f-321424f1cb43
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores de automa&#231;&#227;o: problemas de tempo de vida do objeto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um cliente de automação cria ou ativa um item OLE, o servidor passa o cliente um ponteiro para esse objeto.  O cliente estabelece uma referência ao objeto com uma chamada à função do OLE [IUnknown::AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379).  Essa referência é em vigor até que o cliente chama [IUnknown::Release](http://msdn.microsoft.com/library/windows/desktop/ms682317). \(Os aplicativos cliente gravados com as classes com OLE DB da biblioteca de classes do Microsoft não precisam fazer essas chamadas; a estrutura faz isso.\) O sistema OLE e o próprio servidor podem estabelecer referências ao objeto.  Um servidor não deve ser destruído um objeto como as referências externas ao objeto permanecem aplicado.  
  
 A estrutura interna mantém uma contagem do número de referências a qualquer objeto de servidor derivado de [CCmdTarget](../Topic/CCmdTarget%20Class.md).  Esta contagem é atualizada quando um cliente de automação ou outra entidade adicionam ou liberam uma referência ao objeto.  
  
 Quando a contagem de referência se tornar 0, a estrutura chama a função virtual [CCmdTarget::OnFinalRelease](../Topic/CCmdTarget::OnFinalRelease.md).  A implementação padrão desse chamadas de função do operador **delete** para excluir esse objeto.  
  
 A biblioteca de classes do Microsoft fornece recursos adicionais para o comportamento do aplicativo de controle quando os clientes externas têm referências para objetos de aplicativo.  Além de manter uma contagem das referências para cada objeto, os servidores mantêm uma contagem global de objetos ativas.  As funções [AfxOleLockApp](../Topic/AfxOleLockApp.md) globais e [AfxOleUnlockApp](../Topic/AfxOleUnlockApp.md) atualiza a contagem de aplicativo de objetos ativas.  Se essa contagem é diferente de zero, o aplicativo não encerra quando o usuário escolhe o final do menu do sistema ou a saída do menu arquivo.  Em vez disso, a janela principal do aplicativo está oculta \(mas não destruído\) até que todas as solicitações de cliente pendentes sejam concluídas.  Normalmente, `AfxOleLockApp` e `AfxOleUnlockApp` são chamados nos construtores e em destruidores, respectivamente, das classes a automação de suporte.  
  
 Às vezes as circunstâncias força o servidor para encerrar quando um cliente ainda não tiver uma referência a um objeto.  Por exemplo, um recurso em que o servidor depende pode ficar indisponível, fazendo com que o servidor encontrar um erro.  O usuário também pode fechar um documento de servidor que contém os objetos que outros aplicativos têm referências.  
  
 Em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)], consulte `IUnknown::AddRef` e `IUnknown::Release`.  
  
## Consulte também  
 [Servidores de automação](../mfc/automation-servers.md)   
 [AfxOleCanExitApp](../Topic/AfxOleCanExitApp.md)