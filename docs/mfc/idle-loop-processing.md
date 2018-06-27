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
ms.openlocfilehash: 20be85f7089f2a53b067d7287780159de51a8c86
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929550"
---
# <a name="idle-loop-processing"></a>Processamento de loop ocioso
Muitos aplicativos de processamento longo "em segundo plano." Às vezes, considerações sobre desempenho dita usando multithread para esse trabalho. Threads envolvem sobrecarga extra de desenvolvimento, para que eles não são recomendados para tarefas simples, como o trabalho de tempo ocioso MFC faz o [OnIdle](../mfc/reference/cwinthread-class.md#onidle) função. Este artigo se concentra em processamento ocioso. Para obter mais informações sobre multithreading, consulte [Multithreading tópicos](../parallel/multithreading-support-for-older-code-visual-cpp.md).  
  
 Alguns tipos de processamento em segundo plano são feitos adequadamente durante intervalos de que o usuário caso contrário, não está interagindo com o aplicativo. Um aplicativo desenvolvido para o sistema operacional Microsoft Windows, um aplicativo pode executar processamento de tempo ocioso dividindo-se um processo demorado em muitos pequenos fragmentos. Após o processamento de cada fragmento, o aplicativo gera o controle de execução para o Windows usando um [PeekMessage](http://msdn.microsoft.com/library/windows/desktop/ms644943) loop.  
  
 Este artigo explica as duas maneiras de ociosidade processamento em seu aplicativo:  
  
-   Usando **PeekMessage** no loop de mensagem principal do MFC.  
  
-   Inserir outra **PeekMessage** loop em outro lugar no aplicativo.  
  
##  <a name="_core_peekmessage_in_the_mfc_message_loop"></a> PeekMessage no Loop de mensagem do MFC  
 Em um aplicativo desenvolvido com MFC, a mensagem principal loop no `CWinThread` classe contém um loop de mensagem que chama o [PeekMessage](http://msdn.microsoft.com/library/windows/desktop/ms644943) API do Win32. Isso também loop chama o `OnIdle` função membro de `CWinThread` entre as mensagens. Um aplicativo pode processar mensagens nesse período ocioso, substituindo o `OnIdle` função.  
  
> [!NOTE]
>  `Run`, `OnIdle`, e outras funções de membro determinados agora são membros da classe `CWinThread` em vez da classe `CWinApp`. `CWinApp` é derivado de `CWinThread`.  
  
 Para obter mais informações sobre o desempenho de processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) no *referência MFC*.  
  
##  <a name="_core_peekmessage_elsewhere_in_your_application"></a> PeekMessage em outro lugar no seu aplicativo  
 Outro método para executar ocioso de processamento em um aplicativo envolve a incorporação de um loop de mensagem em uma de suas funções. Este loop de mensagem é muito semelhante ao loop de mensagem principal do MFC, encontrado em [CWinThread::Run](../mfc/reference/cwinthread-class.md#run). Isso significa que um loop desse tipo em um aplicativo desenvolvido com MFC deve executar muitas das mesmas funções, como o loop de mensagem principal. O fragmento de código a seguir demonstra como escrever um loop de mensagem que é compatível com MFC:  
  
 [!code-cpp[NVC_MFCDocView#8](../mfc/codesnippet/cpp/idle-loop-processing_1.cpp)]  
  
 Esse código inserido em uma função, executa um loop enquanto houver processamento ocioso fazer. Dentro do loop, um loop aninhado chama repetidamente `PeekMessage`. Como essa chamada retorna um valor diferente de zero, o loop chama `CWinThread::PumpMessage` para executar a conversão de mensagem normal e distribuição. Embora `PumpMessage` é documentado, você pode examinar o código-fonte no arquivo ThrdCore.Cpp no diretório \atlmfc\src\mfc da instalação do Visual C++.  
  
 Uma vez as extremidades do loop interno, o loop externo executa processamento ocioso com uma ou mais chamadas para `OnIdle`. A primeira chamada é para fins do MFC. Você pode fazer chamadas adicionais para `OnIdle` seu próprio trabalho em segundo plano.  
  
 Para obter mais informações sobre o desempenho de processamento ocioso, consulte [OnIdle](../mfc/reference/cwinthread-class.md#onidle) na referência de biblioteca do MFC.  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

