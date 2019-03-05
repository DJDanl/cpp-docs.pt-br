---
title: 'CWinApp: A classe do aplicativo'
ms.date: 11/04/2016
f1_keywords:
- CWinApp
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
ms.openlocfilehash: d9f0d4f5ba6b6b070b23ce98ecda8c7accf44934
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258704"
---
# <a name="cwinapp-the-application-class"></a>CWinApp: A classe do aplicativo

A classe principal do aplicativo no MFC encapsula a inicialização, execução e encerramento de um aplicativo para o sistema operacional Windows. Um aplicativo criado no framework deve ter um e apenas um objeto de uma classe derivada de [CWinApp](../mfc/reference/cwinapp-class.md). Esse objeto é construído antes de janelas são criadas.

`CWinApp` é derivado de `CWinThread`, que representa o thread principal de execução para o seu aplicativo, que pode ter um ou mais threads. Em versões recentes do MFC, o `InitInstance`, **execute**, `ExitInstance`, e `OnIdle` funções de membro, na verdade, estão na classe `CWinThread`. Essas funções são discutidas aqui, como se fossem `CWinApp` membros em vez disso, porque a discussão se refere a função do objeto como objeto de aplicativo em vez de thread primário.

> [!NOTE]
>  Sua classe de aplicativo constitui o thread principal do aplicativo de execução. Usando funções de API do Win32, você também pode criar threads de execução secundários. Esses threads podem usar a biblioteca do MFC. Para obter mais informações, consulte [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Como qualquer programa do sistema operacional Windows, seu aplicativo framework tem um `WinMain` função. Em um aplicativo do framework, no entanto, você não gravar `WinMain`. Ele é fornecido pela biblioteca de classes e é chamado quando o aplicativo é iniciado. `WinMain` executa os serviços padrão como Registrando classes de janela. Depois, ele chama membro funções do objeto application para inicializar e executar o aplicativo. (Você pode personalizar `WinMain` substituindo as `CWinApp` funções de membro `WinMain` chamadas.)

Para inicializar o aplicativo `WinMain` chama o seu objeto de aplicativo `InitApplication` e `InitInstance` funções de membro. Para executar o loop de mensagem do aplicativo, `WinMain` chamadas a **executar** função de membro. Após o encerramento, `WinMain` chama o objeto de aplicativo `ExitInstance` função de membro.

> [!NOTE]
>  Nomes mostrados na **negrito** nesta documentação indicar elementos fornecidos pela biblioteca Microsoft Foundation Class e Visual C++. Nomes mostrados na `monospaced` tipo indicam os elementos que você cria ou substituir.

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[CWinApp e o Assistente de aplicativo MFC](../mfc/cwinapp-and-the-mfc-application-wizard.md)<br/>
[Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)<br/>
[Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)
