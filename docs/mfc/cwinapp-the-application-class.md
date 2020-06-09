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
ms.openlocfilehash: e8327cf55606131d43201aa1f4f51526bcba147a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617061"
---
# <a name="cwinapp-the-application-class"></a>CWinApp: a classe do aplicativo

A classe de aplicativo principal no MFC encapsula a inicialização, execução e encerramento de um aplicativo para o sistema operacional Windows. Um aplicativo criado com base na estrutura deve ter apenas um objeto de uma classe derivada de [CWinApp](reference/cwinapp-class.md). Esse objeto é construído antes que o Windows seja criado.

`CWinApp`é derivado de `CWinThread` , que representa o thread principal de execução para seu aplicativo, que pode ter um ou mais threads. Nas versões recentes do MFC, as `InitInstance` funções de membro, **executar**, e, na `ExitInstance` verdade, `OnIdle` estão na classe `CWinThread` . Essas funções são discutidas aqui como se fossem `CWinApp` Membros em vez disso, porque a discussão se refere à função do objeto como objeto de aplicativo, e não como thread principal.

> [!NOTE]
> Sua classe de aplicativo constitui o thread principal de execução do seu aplicativo. Usando funções de API do Win32, você também pode criar threads secundários de execução. Esses threads podem usar a biblioteca do MFC. Para obter mais informações, consulte [multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Como qualquer programa para o sistema operacional Windows, seu aplicativo de estrutura tem uma `WinMain` função. No entanto, em um aplicativo de estrutura, você não escreve `WinMain` . Ele é fornecido pela biblioteca de classes e é chamado quando o aplicativo é iniciado. `WinMain`executa serviços padrão, como registrar classes de janela. Em seguida, ele chama as funções de membro do objeto de aplicativo para inicializar e executar o aplicativo. (Você pode personalizar `WinMain` substituindo as `CWinApp` funções de membro que o `WinMain` chama.)

Para inicializar o aplicativo, `WinMain` chama o objeto de aplicativo `InitApplication` e as `InitInstance` funções de membro. Para executar o loop de mensagem do aplicativo, `WinMain` chama a função de membro **Run** . Ao término, `WinMain` chama a função de membro do objeto de aplicativo `ExitInstance` .

> [!NOTE]
> Os nomes mostrados em **negrito** nesta documentação indicam os elementos fornecidos pelo biblioteca MFC e Visual C++. Os nomes mostrados no `monospaced` tipo indicam os elementos que você cria ou substitui.

## <a name="see-also"></a>Consulte também

[Tópicos MFC gerais](general-mfc-topics.md)<br/>
[CWinApp e o Assistente de aplicativo MFC](cwinapp-and-the-mfc-application-wizard.md)<br/>
[Funções de membro CWinApp substituíveis](overridable-cwinapp-member-functions.md)<br/>
[Serviços CWinApp especiais](special-cwinapp-services.md)
