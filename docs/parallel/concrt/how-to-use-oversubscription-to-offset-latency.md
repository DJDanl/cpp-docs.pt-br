---
title: 'Como: Usar excesso de assinatura para deslocar latência'
ms.date: 11/04/2016
helpviewer_keywords:
- oversubscription, using [Concurrency Runtime]
- using oversubscription [Concurrency Runtime]
ms.assetid: a1011329-2f0a-4afb-b599-dd4043009a10
ms.openlocfilehash: d74a081f71f044cab90a8e6fdc64530eaaf87ed8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62159932"
---
# <a name="how-to-use-oversubscription-to-offset-latency"></a>Como: Usar excesso de assinatura para deslocar latência

Excesso de assinatura pode melhorar a eficiência geral de alguns aplicativos que contêm as tarefas que têm uma grande quantidade de latência. Este tópico ilustra como usar excesso de assinatura para deslocar a latência causada por leitura de dados de uma conexão de rede.

## <a name="example"></a>Exemplo

Este exemplo usa o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) para baixar arquivos de servidores HTTP. O `http_reader` classe deriva [concurrency::agent](../../parallel/concrt/reference/agent-class.md) e usos da mensagem passando para ler os nomes de URL para baixar de forma assíncrona.

O `http_reader` classe usa o [Concurrency:: task_group](reference/task-group-class.md) classe simultaneamente ler cada arquivo. Cada tarefa chama o [concurrency::Context::Oversubscribe](reference/context-class.md#oversubscribe) método com o `_BeginOversubscription` parâmetro definido como **true** para habilitar assinaturas em excesso no contexto atual. Cada tarefa, em seguida, usa o Microsoft Foundation Classes (MFC) [CInternetSession](../../mfc/reference/cinternetsession-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) classes para baixar o arquivo. Por fim, cada tarefa chama `Context::Oversubscribe` com o `_BeginOversubscription` parâmetro definido como **falso** para desabilitar o excesso de assinatura.

Quando o excesso de assinaturas estiver habilitado, o tempo de execução cria um thread adicional no qual executar tarefas. Cada um desses threads pode também substituir o contexto atual e, assim, criar threads adicionais. O `http_reader` classe usa um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto para limitar o número de threads que o aplicativo usa. O agente inicializa o buffer com um número fixo de valores do token. Para cada operação de download, o agente lê um valor de token do buffer antes que a operação inicia e, em seguida, grava esse valor de volta no buffer após a conclusão da operação. Quando o buffer está vazio, o agente espera uma das operações de download para gravar um valor de volta para o buffer.

O exemplo a seguir limita o número de tarefas simultâneas para duas vezes o número de threads de hardware disponíveis. Esse valor é um bom ponto de partida para usar ao experimentar o excesso de assinatura. Você pode usar um valor que se ajusta a um ambiente de processamento específico ou alterar dinamicamente esse valor para responder a carga de trabalho real.

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

O exemplo a pode executar mais rapidamente ao excesso de assinatura foi habilitado porque tarefas adicionais são executadas enquanto outras tarefas de espera para concluir uma operação de latente.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `download-oversubscription.cpp` e, em seguida, execute um dos seguintes comandos em um **Prompt de comando do Visual Studio** janela.

**cl.exe /EHsc /MD /D "_AFXDLL" download-oversubscription.cpp**

**cl.exe de /EHsc /MT download-oversubscription.cpp**

## <a name="robust-programming"></a>Programação robusta

Sempre desabilite o excesso de assinatura depois que você não precisar. Considere uma função que não trata uma exceção que é lançada por outra função. Se você não desabilitar o excesso de assinatura antes da função retorna, qualquer trabalho paralelo adicional também serão subscrever o contexto atual.

Você pode usar o *recurso de aquisição é inicialização* padrão (RAII) para limitar o excesso de assinatura para um determinado escopo. Sob o padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Portanto, os recursos são gerenciados corretamente quando uma exceção é lançada ou quando uma função contém várias `return` instruções.

O exemplo a seguir define uma estrutura que é denominada `scoped_blocking_signal`. O construtor do `scoped_blocking_signal` estrutura permite que o excesso de assinatura e o destruidor desabilita o excesso de assinaturas.

[!code-cpp[concrt-download-oversubscription#2](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_2.cpp)]

O exemplo a seguir modifica o corpo do `download` método usar RAII para garantir que esse excesso de assinatura está desabilitado antes da função retorna. Essa técnica garante que o `download` método é à prova de exceções.

[!code-cpp[concrt-download-oversubscription#3](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_3.cpp)]

## <a name="see-also"></a>Consulte também

[Contextos](../../parallel/concrt/contexts.md)<br/>
[Método Context:: oversubscribe](reference/context-class.md#oversubscribe)
