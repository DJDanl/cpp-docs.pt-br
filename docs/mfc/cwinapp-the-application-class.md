---
title: 'CWinApp: a classe do aplicativo'
ms.date: 11/04/2016
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
ms.openlocfilehash: 8518e21a9fa6bcf5ac640cff25b17c5028046b06
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447027"
---
# <a name="cwinapp-the-application-class"></a>CWinApp: a classe do aplicativo

A classe de aplicativo principal no MFC encapsula a inicialização, execução e encerramento de um aplicativo para o sistema operacional Windows. Um aplicativo criado com base na estrutura deve ter apenas um objeto de uma classe derivada de [CWinApp](../mfc/reference/cwinapp-class.md). Esse objeto é construído antes que o Windows seja criado.

`CWinApp` é derivado de `CWinThread`, que representa o thread principal de execução para seu aplicativo, que pode ter um ou mais threads. Nas versões recentes do MFC, as funções de membro `InitInstance`, **Run**, `ExitInstance`e `OnIdle` estão na verdade na classe `CWinThread`. Essas funções são discutidas aqui como se estivessem `CWinApp` Membros, porque a discussão diz respeito à função do objeto como objeto de aplicativo, e não como thread principal.

> [!NOTE]
>  Sua classe de aplicativo constitui o thread principal de execução do seu aplicativo. Usando funções de API do Win32, você também pode criar threads secundários de execução. Esses threads podem usar a biblioteca do MFC. Para obter mais informações, consulte [multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Como qualquer programa para o sistema operacional Windows, seu aplicativo de estrutura tem uma função `WinMain`. No entanto, em um aplicativo de estrutura, você não grava `WinMain`. Ele é fornecido pela biblioteca de classes e é chamado quando o aplicativo é iniciado. `WinMain` executa serviços padrão, como o registro de classes de janela. Em seguida, ele chama as funções de membro do objeto de aplicativo para inicializar e executar o aplicativo. (Você pode personalizar `WinMain` substituindo as funções de membro de `CWinApp` que `WinMain` chamadas.)

Para inicializar o aplicativo, `WinMain` chama o `InitApplication` do seu objeto de aplicativo e `InitInstance` funções de membro. Para executar o loop de mensagem do aplicativo, `WinMain` chama a função de membro **Run** . No encerramento, `WinMain` chama a função de membro `ExitInstance` do objeto de aplicativo.

> [!NOTE]
>  Os nomes mostrados em **negrito** nesta documentação indicam os elementos fornecidos pelo biblioteca MFC e C++pelo Visual. Os nomes mostrados no tipo `monospaced` indicam os elementos que você cria ou substitui.

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)<br/>
[CWinApp e o Assistente de aplicativo MFC](../mfc/cwinapp-and-the-mfc-application-wizard.md)<br/>
[Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)<br/>
[Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)
