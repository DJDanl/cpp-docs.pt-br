---
title: 'Como: usar o excesso de assinatura para deslocar latência | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- oversubscription, using [Concurrency Runtime]
- using oversubscription [Concurrency Runtime]
ms.assetid: a1011329-2f0a-4afb-b599-dd4043009a10
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0c27864d040d0b6ce7b36087cff85ed750aa7ed2
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689253"
---
# <a name="how-to-use-oversubscription-to-offset-latency"></a>Como usar excesso de assinatura para deslocar latência
Excesso de assinatura pode melhorar a eficiência geral de alguns aplicativos que contêm as tarefas que têm uma grande quantidade de latência. Este tópico ilustra como usar excesso de assinatura para deslocar a latência é causada pela leitura de dados de uma conexão de rede.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa o [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md) Baixe arquivos de servidores HTTP. O `http_reader` classe derivada de [concurrency::agent](../../parallel/concrt/reference/agent-class.md) e usa passando para ler assincronamente quais nomes de URL para fazer o download da mensagem.  
  
 O `http_reader` classe usa a [concurrency::task_group](reference/task-group-class.md) classe para cada arquivo de leitura ao mesmo tempo. Cada tarefa chama o [concurrency::Context::Oversubscribe](reference/context-class.md#oversubscribe) método com o `_BeginOversubscription` parâmetro definido como `true` para habilitar o excesso de assinatura no contexto atual. Cada tarefa, em seguida, usa o Microsoft Foundation Classes (MFC) [CInternetSession](../../mfc/reference/cinternetsession-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) classes para baixar o arquivo. Por fim, cada tarefa chama `Context::Oversubscribe` com o `_BeginOversubscription` parâmetro definido como `false` para desabilitar o excesso de assinatura.  
  
 Quando o excesso de assinatura é habilitado, o tempo de execução cria um thread adicional para execução de tarefas. Cada um desses threads pode subscrever também o contexto atual e, assim, criam threads adicionais. O `http_reader` classe usa um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto para limitar o número de threads que o aplicativo usa. O agente inicializa o buffer com um número fixo de valores do token. Para cada operação de download, o agente lê um valor do token do buffer antes da operação inicia e, em seguida, grava esse valor para o buffer após a conclusão da operação. Quando o buffer está vazio, o agente espera para uma das operações de download para gravar um valor de volta para o buffer.  
  
 O exemplo a seguir limita o número de tarefas simultâneas para duas vezes o número de threads de hardware disponíveis. Esse valor é um bom ponto de partida para usar ao fazer experiências com excesso de assinatura. Você pode usar um valor que atenda a um ambiente de processamento específico ou dinamicamente altere este valor para responder à carga de trabalho real.  
  
 [!code-cpp[concrt-download-oversubscription#1](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_1.cpp)]  
  
 Este exemplo produz a saída a seguir em um computador que tem quatro processadores:  
  
```Output  
Downloading http://www.adatum.com/...  
Downloading http://www.adventure-works.com/...  
Downloading http://www.alpineskihouse.com/...  
Downloading http://www.cpandl.com/...  
Downloading http://www.cohovineyard.com/...  
Downloading http://www.cohowinery.com/...  
Downloading http://www.cohovineyardandwinery.com/...  
Downloading http://www.contoso.com/...  
Downloading http://www.consolidatedmessenger.com/...  
Downloading http://www.fabrikam.com/...  
Downloading http://www.fourthcoffee.com/...  
Downloading http://www.graphicdesigninstitute.com/...  
Downloading http://www.humongousinsurance.com/...  
Downloading http://www.litwareinc.com/...  
Downloading http://www.lucernepublishing.com/...  
Downloading http://www.margiestravel.com/...  
Downloading http://www.northwindtraders.com/...  
Downloading http://www.proseware.com/...  
Downloading http://www.fineartschool.net...  
Downloading http://www.tailspintoys.com/...  
Downloaded 1801040 bytes in 3276 ms.  
```  
  
 O exemplo pode executar mais rápido quando excesso de assinatura foi habilitado porque as tarefas adicionais executadas enquanto outras tarefas de espera para a concluir uma operação latente.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `download-oversubscription.cpp` e, em seguida, execute um dos seguintes comandos em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc /MD /D "_AFXDLL" download-oversubscription.cpp**  
  
 **cl.exe /EHsc /MT download-oversubscription.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Depois que você não precisa sempre desabilite a excesso de assinatura. Considere uma função que não lida com a exceção que é lançada por outra função. Se você não desabilitar excesso de assinatura antes que a função retorna, qualquer trabalho paralelo adicional também será subscrever o contexto atual.  
  
 Você pode usar o *recurso aquisição é inicialização* padrão (RAII) para limitar o excesso de assinatura para um determinado escopo. Em padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Portanto, o recurso é gerenciado corretamente quando uma exceção é lançada ou quando uma função contém várias `return` instruções.  
  
 O exemplo a seguir define uma estrutura denominada `scoped_blocking_signal`. O construtor do `scoped_blocking_signal` estrutura permite que o excesso de assinatura e o destruidor desabilita o excesso de assinatura.  
  
 [!code-cpp[concrt-download-oversubscription#2](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_2.cpp)]  
  
 O exemplo a seguir modifica o corpo do `download` método RAII para garantir que excesso de assinatura está desabilitado antes da função retorna. Essa técnica garante que o `download` método é segura para a exceção.  
  
 [!code-cpp[concrt-download-oversubscription#3](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Contextos](../../parallel/concrt/contexts.md)   
 [Método: oversubscribe](reference/context-class.md#oversubscribe)


