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
ms.openlocfilehash: 72491c057f3bf7c531bb5515b07f1e9d0acf35d5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508409"
---
# <a name="idle-loop-processing"></a>Processamento de loop ocioso

Muitos aplicativos executam processamento longo "em segundo plano". Às vezes, as considerações de desempenho determinam o uso de multithread para tal trabalho. Os threads envolvem sobrecarga de desenvolvimento extra e, portanto, não são recomendados para tarefas simples, como o trabalho de tempo ocioso que o MFC faz na função [OnIdle](../mfc/reference/cwinthread-class.md#onidle) . Este artigo se concentra no processamento ocioso. Para obter mais informações sobre multithreading, consulte os [Tópicos](../parallel/multithreading-support-for-older-code-visual-cpp.md)de multithreading.

Alguns tipos de processamento em segundo plano são feitos adequadamente durante intervalos que o usuário não está interagindo de outra forma com o aplicativo. Em um aplicativo desenvolvido para o sistema operacional Microsoft Windows, um aplicativo pode executar o processamento em tempo ocioso dividindo um processo longo em muitos fragmentos pequenos. Após o processamento de cada fragmento, o aplicativo gera o controle de execução para o Windows usando um loop [PeekMessage](/windows/win32/api/winuser/nf-winuser-peekmessagew) .

Este artigo explica duas maneiras de fazer o processamento ocioso em seu aplicativo:

- Usando o **PeekMessage** no loop de mensagem principal do MFC.

- Incorporando outro loop **PeekMessage** em outro lugar no aplicativo.

##  <a name="_core_peekmessage_in_the_mfc_message_loop"></a>PeekMessage no loop de mensagem do MFC

Em um aplicativo desenvolvido com MFC, o loop de mensagem principal na `CWinThread` classe contém um loop de mensagem que chama a API Win32 do [PeekMessage](/windows/win32/api/winuser/nf-winuser-peekmessagew) . Esse loop também chama a `OnIdle` função de `CWinThread` membro entre as mensagens. Um aplicativo pode processar mensagens nesse tempo ocioso substituindo a `OnIdle` função.

> [!NOTE]
>  `Run`, `OnIdle`e algumas outras funções de membro agora são membros da classe `CWinThread` , e não da `CWinApp`classe. `CWinApp`é derivado de `CWinThread`.

Para obter mais informações sobre como executar o processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na *referência do MFC*.

##  <a name="_core_peekmessage_elsewhere_in_your_application"></a>PeekMessage em outro lugar em seu aplicativo

Outro método para executar o processamento ocioso em um aplicativo envolve a inserção de um loop de mensagem em uma de suas funções. Esse loop de mensagem é muito semelhante ao loop de mensagem principal do MFC, encontrado em [CWinThread:: Run](../mfc/reference/cwinthread-class.md#run). Isso significa que um loop em um aplicativo desenvolvido com MFC deve executar muitas das mesmas funções que o loop de mensagem principal. O fragmento de código a seguir demonstra a gravação de um loop de mensagem compatível com MFC:

[!code-cpp[NVC_MFCDocView#8](../mfc/codesnippet/cpp/idle-loop-processing_1.cpp)]

Esse código, inserido em uma função, executa um loop, desde que haja processamento ocioso. Dentro desse loop, um loop aninhado chama `PeekMessage`repetidamente. Desde que essa chamada retorne um valor diferente de zero, o `CWinThread::PumpMessage` loop chama para executar a tradução e a distribuição de mensagens normais. Embora `PumpMessage` o não seja documentado, você pode examinar seu código-fonte no arquivo ThrdCore. cpp no diretório \atlmfc\src\mfc da sua instalação C++ Visual.

Quando o loop interno termina, o loop externo executa o processamento ocioso com uma ou mais chamadas `OnIdle`para. A primeira chamada é para fins do MFC. Você pode fazer chamadas adicionais para `OnIdle` para fazer seu próprio trabalho em segundo plano.

Para obter mais informações sobre como executar o processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na referência da biblioteca do MFC.

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
