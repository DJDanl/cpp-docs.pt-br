---
title: 'CWinApp: A classe do aplicativo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CWinApp
dev_langs:
- C++
helpviewer_keywords:
- application class [MFC]
- CWinApp class [MFC], CWinThread
- MFC, WinMain and
- CWinApp class [MFC], multithreading
- CWinThread class [MFC], and CWinApp
- InitApplication method [MFC]
- WinMain method [MFC]
- WinMain method [MFC], in MFC
- CWinApp class [MFC], WinMain
ms.assetid: 935822bb-d463-481b-a5f6-9719d68ed1d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c0c3641441554d73e0c7657dd220be86f0c0cab0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342999"
---
# <a name="cwinapp-the-application-class"></a>CWinApp: a classe do aplicativo
A classe principal do aplicativo MFC encapsula a inicialização, em execução e encerramento de um aplicativo para o sistema operacional Windows. Um aplicativo baseado no framework deve ter um e apenas um objeto de uma classe derivada de [CWinApp](../mfc/reference/cwinapp-class.md). Esse objeto é construído para que windows é criado.  
  
 `CWinApp` é derivado de `CWinThread`, que representa o thread principal de seu aplicativo, o que pode ter um ou mais threads de execução. Em versões recentes do MFC, o `InitInstance`, **executar**, `ExitInstance`, e `OnIdle` funções de membro são realmente na classe `CWinThread`. Essas funções são discutidas aqui como se fossem `CWinApp` membros em vez disso, porque a discussão se refere a função do objeto como objeto de aplicativo em vez de thread principal.  
  
> [!NOTE]
>  A classe do aplicativo constitui a thread principal do aplicativo de execução. Usar as funções de API do Win32, você também pode criar secundários threads de execução. Esses threads podem usar a biblioteca do MFC. Para obter mais informações, consulte [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).  
  
 Como qualquer programa para o sistema operacional Windows, seu aplicativo framework tem um `WinMain` função. Em um aplicativo do framework, no entanto, você não gravar `WinMain`. Ele é fornecido pela biblioteca de classes e é chamado quando o aplicativo é iniciado. `WinMain` executa os serviços padrão como Registrando classes de janela. Depois, ele chama membro funções do objeto de aplicativo para inicializar e executar o aplicativo. (Você pode personalizar `WinMain` , substituindo o `CWinApp` funções de membro `WinMain` chamadas.)  
  
 Para inicializar o aplicativo, `WinMain` chama seu objeto de aplicativo `InitApplication` e `InitInstance` funções de membro. Para executar o loop de mensagem do aplicativo, `WinMain` chama o **executar** função de membro. No encerramento, `WinMain` chama o objeto de aplicativo `ExitInstance` função de membro.  
  
> [!NOTE]
>  Nomes mostrados na **negrito** nesta documentação indicam elementos fornecidos pela biblioteca Microsoft Foundation Class e Visual C++. Nomes mostrados na `monospaced` tipo indicam elementos que você cria ou substituir.  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [CWinApp e o Assistente de aplicativo MFC](../mfc/cwinapp-and-the-mfc-application-wizard.md)   
 [Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)   
 [Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)

