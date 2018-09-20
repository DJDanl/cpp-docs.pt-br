---
title: Processamento de Loop ocioso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0cad16ca383ebbcc3e24723443ab951b8c1f7ab0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429028"
---
# <a name="idle-loop-processing"></a>Processamento de loop ocioso

Muitos aplicativos executam processamento mais extenso "em segundo plano." Às vezes, considerações sobre desempenho dita o uso de multithreading para esse trabalho. Threads envolvem sobrecarga extra de desenvolvimento, portanto, eles não são recomendados para tarefas simples, como o trabalho de tempo ocioso MFC faz na [OnIdle](../mfc/reference/cwinthread-class.md#onidle) função. Este artigo se concentra em processamento ocioso. Para obter mais informações sobre multithreading, consulte [tópicos de Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Alguns tipos de processamento em segundo plano são realizados adequadamente durante intervalos de que o usuário caso contrário, não está interagindo com o aplicativo. Em um aplicativo desenvolvido para o sistema operacional Microsoft Windows, um aplicativo pode executar o processamento de tempo ocioso, dividindo um processo demorado em muitos pequenos fragmentos. Após o processamento de cada fragmento, o aplicativo transfere o controle de execução para Windows usando um [PeekMessage](https://msdn.microsoft.com/library/windows/desktop/ms644943) loop.

Este artigo descreve duas maneiras de processamento em seu aplicativo ocioso:

- Usando o **PeekMessage** no loop de mensagem principal do MFC.

- Inserir outra **PeekMessage** loop em outro lugar no aplicativo.

##  <a name="_core_peekmessage_in_the_mfc_message_loop"></a> PeekMessage no Loop de mensagem do MFC

Em um aplicativo desenvolvido com o MFC, a mensagem principal loop na `CWinThread` classe contém um loop de mensagem que chama o [PeekMessage](https://msdn.microsoft.com/library/windows/desktop/ms644943) API do Win32. Isso também loop chamadas a `OnIdle` função de membro de `CWinThread` entre as mensagens. Um aplicativo pode processar mensagens nesse tempo ocioso, substituindo o `OnIdle` função.

> [!NOTE]
>  `Run`, `OnIdle`, e outras funções de membro determinadas agora são membros da classe `CWinThread` em vez da classe `CWinApp`. `CWinApp` é derivado de `CWinThread`.

Para obter mais informações sobre o desempenho de processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na *referência da MFC*.

##  <a name="_core_peekmessage_elsewhere_in_your_application"></a> PeekMessage em outro lugar no seu aplicativo

Outro método para a execução de ociosidade de processamento em um aplicativo envolve a inserção de um loop de mensagem em uma de suas funções. Esse loop de mensagem é muito semelhante ao loop de mensagem principal do MFC, encontrado no [CWinThread::Run](../mfc/reference/cwinthread-class.md#run). Isso significa que tal um loop em um aplicativo desenvolvido com o MFC deve executar muitas das mesmas funções como o loop de mensagem principal. O fragmento de código a seguir demonstra a gravação de um loop de mensagem que é compatível com o MFC:

[!code-cpp[NVC_MFCDocView#8](../mfc/codesnippet/cpp/idle-loop-processing_1.cpp)]

Esse código, inserido em uma função, loops desde que não há processamento ocioso a fazer. Dentro do loop, um loop aninhado chama repetidamente `PeekMessage`. Desde que essa chamada retorna um valor diferente de zero, o loop chama `CWinThread::PumpMessage` para realizar a conversão de mensagem normal e expedição. Embora `PumpMessage` é documentado, você pode examinar seu código-fonte no arquivo ThrdCore.Cpp no diretório \atlmfc\src\mfc da instalação do Visual C++.

Uma vez o término de loop interno, o loop externo executa processamento ocioso com um ou mais chamadas para `OnIdle`. A primeira chamada é para fins do MFC. Você pode fazer chamadas adicionais para `OnIdle` para realizar seu próprio trabalho em segundo plano.

Para obter mais informações sobre o desempenho de processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na referência da biblioteca MFC.

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

