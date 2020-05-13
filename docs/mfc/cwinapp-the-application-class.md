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
ms.openlocfilehash: 007a4e53fd9b3eae612947cd76ee352776572d4f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373531"
---
# <a name="cwinapp-the-application-class"></a>CWinApp: a classe do aplicativo

A classe principal de aplicativos no MFC encapsula a inicialização, execução e término de um aplicativo para o sistema operacional Windows. Um aplicativo construído sobre a estrutura deve ter um e apenas um objeto de uma classe derivada do [CWinApp](../mfc/reference/cwinapp-class.md). Este objeto é construído antes que as janelas sejam criadas.

`CWinApp`é derivado, `CWinThread`que representa o principal segmento de execução para sua aplicação, que pode ter um ou mais threads. Em versões recentes `InitInstance`de MFC, `OnIdle` as funções de `CWinThread` **, Run**, `ExitInstance`e membros estão realmente em sala de aula . Essas funções são discutidas aqui `CWinApp` como se fossem membros, porque a discussão diz respeito ao papel do objeto como objeto de aplicação e não como segmento principal.

> [!NOTE]
> Sua classe de aplicação constitui o principal segmento de execução do aplicativo. Usando funções de API do Win32, você também pode criar segmentos secundários de execução. Esses segmentos podem usar a Biblioteca MFC. Para obter mais informações, consulte [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Como qualquer programa para o sistema operacional `WinMain` Windows, seu aplicativo de estrutura tem uma função. Em um aplicativo de quadro, `WinMain`no entanto, você não escreve . Ele é fornecido pela biblioteca de classe e é chamado quando o aplicativo é iniciado. `WinMain`realiza serviços padrão, como registrar classes de janela. Em seguida, ele chama as funções do membro do objeto de aplicativo para inicializar e executar o aplicativo. (Você pode `WinMain` personalizar substituindo as funções de `CWinApp` membro que `WinMain` chama.)

Para inicializar o `WinMain` aplicativo, chama `InitApplication` as `InitInstance` funções do objeto de aplicativo e do membro. Para executar o loop de `WinMain` mensagem do aplicativo, chame a função **Executar** membro. No término, `WinMain` chama a `ExitInstance` função de membro do objeto de aplicativo.

> [!NOTE]
> Os nomes mostrados em **negrito** nesta documentação indicam elementos fornecidos pela Microsoft Foundation Class Library e visual C++. Os nomes `monospaced` mostrados no tipo indicam elementos que você cria ou substituí.

## <a name="see-also"></a>Confira também

[Tópicos MFC gerais](../mfc/general-mfc-topics.md)<br/>
[CWinApp e o Assistente de aplicativo MFC](../mfc/cwinapp-and-the-mfc-application-wizard.md)<br/>
[Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)<br/>
[Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)
