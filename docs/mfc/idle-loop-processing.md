---
title: Processamento de loop ocioso
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, background processing
- PeekMessage method [MFC], elsewhere than message loop
- PeekMessage method [MFC]
- MFC, messages
- messages [MFC], loops
- OnIdle method [MFC]
- processing [MFC], background
- idle loop processing [MFC]
- idle processing [MFC]
- threading [MFC], alternatives to multithreading
- processing, during idle loop
- processing [MFC]
- background processing [MFC]
ms.assetid: 5c7c46c1-6107-4304-895f-480983bb1e44
ms.openlocfilehash: 9579d4bb8768b0227453af401d6fdc8a8bd482b4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376010"
---
# <a name="idle-loop-processing"></a>Processamento de loop ocioso

Muitos aplicativos realizam processamento demorado "em segundo plano". Às vezes, considerações de desempenho ditam o uso de multithreading para tal trabalho. Os threads envolvem sobrecarga de desenvolvimento extra, por isso não são recomendados para tarefas simples como o trabalho de tempo ocioso que o MFC faz na função [OnIdle.](../mfc/reference/cwinthread-class.md#onidle) Este artigo foca no processamento ocioso. Para obter mais informações sobre multithreading, consulte [Multithreading Topics](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Alguns tipos de processamento em segundo plano são feitos adequadamente durante intervalos que o usuário não está interagindo de outra forma com o aplicativo. Em um aplicativo desenvolvido para o sistema operacional Microsoft Windows, um aplicativo pode realizar processamento de tempo ocioso dividindo um processo demorado em muitos pequenos fragmentos. Depois de processar cada fragmento, o aplicativo produz o controle de execução para o Windows usando um loop [PeekMessage.](/windows/win32/api/winuser/nf-winuser-peekmessagew)

Este artigo explica duas maneiras de fazer processamento ocioso em sua aplicação:

- Usando **peekmessage** no loop de mensagem principal do MFC.

- Incorporando outro loop **PeekMessage** em outro lugar do aplicativo.

## <a name="peekmessage-in-the-mfc-message-loop"></a><a name="_core_peekmessage_in_the_mfc_message_loop"></a>PeekMessage no loop de mensagem do MFC

Em um aplicativo desenvolvido com o MFC, o loop de mensagem principal da `CWinThread` classe contém um loop de mensagem que chama a API [PeekMessage](/windows/win32/api/winuser/nf-winuser-peekmessagew) Win32. Este loop também `OnIdle` chama `CWinThread` a função membro de entre mensagens. Um aplicativo pode processar mensagens neste tempo `OnIdle` ocioso substituindo a função.

> [!NOTE]
> `Run`, `OnIdle`e certas outras funções de `CWinThread` membros são `CWinApp`agora membros de classe e não de classe. `CWinApp`é derivado `CWinThread`de .

Para obter mais informações sobre a realização de processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na *referência MFC*.

## <a name="peekmessage-elsewhere-in-your-application"></a><a name="_core_peekmessage_elsewhere_in_your_application"></a>PeekMessage em outro lugar em seu aplicativo

Outro método para realizar o processamento ocioso em um aplicativo envolve incorporar um loop de mensagem em uma de suas funções. Este loop de mensagem é muito semelhante ao loop de mensagem principal do MFC, encontrado em [CWinThread::Run](../mfc/reference/cwinthread-class.md#run). Isso significa que esse loop em um aplicativo desenvolvido com MFC deve executar muitas das mesmas funções que o loop de mensagem principal. O fragmento de código a seguir demonstra a escrita de um loop de mensagem compatível com o MFC:

[!code-cpp[NVC_MFCDocView#8](../mfc/codesnippet/cpp/idle-loop-processing_1.cpp)]

Este código, incorporado em uma função, faz loops enquanto houver processamento ocioso para fazer. Dentro desse loop, um loop `PeekMessage`aninhado chama repetidamente . Desde que essa chamada retorne um valor `CWinThread::PumpMessage` não zero, o loop é chamado para realizar a tradução e o envio normais de mensagens. Embora `PumpMessage` não esteja documentado, você pode examinar seu código-fonte no arquivo ThrdCore.Cpp no diretório \atlmfc\src\mfc da instalação Visual C++.

Uma vez que o loop interno termina, o loop `OnIdle`externo executa o processamento ocioso com uma ou mais chamadas para . A primeira chamada é para os propósitos do MFC. Você pode fazer `OnIdle` chamadas adicionais para fazer seu próprio trabalho de fundo.

Para obter mais informações sobre a realização de processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na Referência da Biblioteca Do MFC.

## <a name="see-also"></a>Confira também

[Tópicos MFC gerais](../mfc/general-mfc-topics.md)
