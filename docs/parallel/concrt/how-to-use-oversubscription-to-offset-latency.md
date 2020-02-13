---
title: Como usar excesso de assinatura para deslocar latência
ms.date: 11/04/2016
helpviewer_keywords:
- oversubscription, using [Concurrency Runtime]
- using oversubscription [Concurrency Runtime]
ms.assetid: a1011329-2f0a-4afb-b599-dd4043009a10
ms.openlocfilehash: 02c72e7b7f0e3ec9727504d62341d945dcd0d957
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141948"
---
# <a name="how-to-use-oversubscription-to-offset-latency"></a>Como usar excesso de assinatura para deslocar latência

A superassinatura pode melhorar a eficiência geral de alguns aplicativos que contêm tarefas que têm uma grande quantidade de latência. Este tópico ilustra como usar a assinatura em excesso para deslocar a latência causada pela leitura de dados de uma conexão de rede.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo usa a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) para baixar arquivos de servidores http. A classe `http_reader` deriva de [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md) e usa a transmissão de mensagens para ler de forma assíncrona quais nomes de URL baixar.

A classe `http_reader` usa a classe [Concurrency:: task_group](reference/task-group-class.md) para ler simultaneamente cada arquivo. Cada tarefa chama o método [Concurrency:: Context:: Oversubscribe](reference/context-class.md#oversubscribe) com o parâmetro `_BeginOversubscription` definido como **true** para habilitar a assinatura em excesso no contexto atual. Em seguida, cada tarefa usa as classes MFC (MFC) [CInternetSession](../../mfc/reference/cinternetsession-class.md) e [CHttpFile](../../mfc/reference/chttpfile-class.md) para baixar o arquivo. Por fim, cada tarefa chama `Context::Oversubscribe` com o parâmetro `_BeginOversubscription` definido como **false** para desabilitar a assinatura em excesso.

Quando a assinatura está habilitada, o tempo de execução cria um thread adicional no qual executar tarefas. Cada um desses threads também pode cancelar a assinatura do contexto atual e, assim, criar threads adicionais. A classe `http_reader` usa um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) para limitar o número de threads que o aplicativo usa. O agente Inicializa o buffer com um número fixo de valores de token. Para cada operação de download, o agente lê um valor de token do buffer antes de a operação ser iniciada e, em seguida, grava esse valor de volta no buffer após a conclusão da operação. Quando o buffer está vazio, o agente aguarda que uma das operações de download grave um valor no buffer.

O exemplo a seguir limita o número de tarefas simultâneas a duas vezes o número de threads de hardware disponíveis. Esse valor é um bom ponto de partida a ser usado quando você experimenta a assinatura em excesso. Você pode usar um valor que se ajuste a um determinado ambiente de processamento ou alterar dinamicamente esse valor para responder à carga de trabalho real.

[!code-cpp[concrt-download-oversubscription#1](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_1.cpp)]

Este exemplo produz a seguinte saída em um computador que tem quatro processadores:

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

O exemplo pode ser executado mais rapidamente quando a assinatura está habilitada porque as tarefas adicionais são executadas enquanto outras tarefas aguardam a conclusão de uma operação latente.

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `download-oversubscription.cpp` e, em seguida, execute um dos comandos a seguir em uma janela de **prompt de comando do Visual Studio** .

```cmd
cl.exe /EHsc /MD /D "_AFXDLL" download-oversubscription.cpp
cl.exe /EHsc /MT download-oversubscription.cpp
```

## <a name="robust-programming"></a>Programação Robusta

Sempre desabilite a assinatura em excesso depois que você não precisar mais dela. Considere uma função que não trata uma exceção que é gerada por outra função. Se você não desabilitar a assinatura em excesso antes que a função seja retornada, qualquer trabalho paralelo adicional também fará a assinatura do contexto atual.

Você pode usar o padrão RAII ( *aquisição de recursos é inicialização* ) para limitar a assinatura em um determinado escopo. No padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor seja chamado antes da saída do escopo delimitador. Portanto, o recurso é gerenciado corretamente quando uma exceção é lançada ou quando uma função contém várias instruções `return`.

O exemplo a seguir define uma estrutura chamada `scoped_blocking_signal`. O construtor da estrutura de `scoped_blocking_signal` habilita a assinatura em excesso e o destruidor desabilita a assinatura em excesso.

[!code-cpp[concrt-download-oversubscription#2](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_2.cpp)]

O exemplo a seguir modifica o corpo do método `download` para usar RAII para garantir que a assinatura seja desabilitada antes que a função retorne. Essa técnica garante que o método de `download` seja seguro para exceções.

[!code-cpp[concrt-download-oversubscription#3](../../parallel/concrt/codesnippet/cpp/how-to-use-oversubscription-to-offset-latency_3.cpp)]

## <a name="see-also"></a>Consulte também

[Contextos](../../parallel/concrt/contexts.md)<br/>
[Método Context:: exsubscribe](reference/context-class.md#oversubscribe)
