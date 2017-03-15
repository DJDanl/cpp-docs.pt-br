---
title: "Como usar excesso de assinatura para deslocar lat&#234;ncia | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "excesso de assinatura, usando [tempo de execução de simultaneidade]"
  - "usando excesso de assinatura [Tempo de Execução de Simultaneidade]"
ms.assetid: a1011329-2f0a-4afb-b599-dd4043009a10
caps.latest.revision: 17
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar excesso de assinatura para deslocar lat&#234;ncia
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A sobresubscrição pode melhorar a eficiência total de alguns aplicativos que contêm as tarefas que têm uma quantidade de alta latência.  Este tópico ilustra como usar a sobresubscrição para deslocar a latência que é causado ler dados de uma conexão de rede.  
  
## Exemplo  
 Este exemplo usa [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) para baixar arquivos de servidores HTTP.  A classe de `http_reader` é derivado de [concurrency::agent](../../parallel/concrt/reference/agent-class.md) e usa a mensagem que passa de forma assíncrona à leitura dos nomes de URL para baixar.  
  
 A classe de `http_reader` usa a classe de [concurrency::task\_group](../Topic/task_group%20Class.md) para ler simultaneamente cada arquivo.  Cada tarefa chama o método de [concurrency::Context::Oversubscribe](../Topic/Context::Oversubscribe%20Method.md) com o parâmetro de `_BeginOversubscription` definido como `true` para habilitar a sobresubscrição no contexto atual.  Cada tarefa usar as classes \(MFC\) [CInternetSession](../Topic/CInternetSession%20Class.md) do Microsoft e classes de [CHttpFile](../Topic/CHttpFile%20Class.md) para baixar o arquivo.  Finalmente, cada tarefa `Context::Oversubscribe` chama com o parâmetro de `_BeginOversubscription` definido como `false` para desabilitar a sobresubscrição.  
  
 Quando a sobresubscrição é habilitada, o tempo de execução cria um thread adicional na qual executar tarefas.  Cada um desses threads pode também o oversubscribe o contexto atual e cria assim threads adicionais.  A classe de `http_reader` usa um objeto de [concurrency::unbounded\_buffer](../Topic/unbounded_buffer%20Class.md) para limitar o número de threads que o aplicativo usa.  O agente inicializa o buffer com um número fixo dos valores do token.  Para cada operação de download, o agente lê um valor de token do buffer antes do início e nas gravações de operação que avaliam de volta ao buffer após a conclusão da operação.  Quando o buffer estiver vazia, o agent espera por uma das operações de download para escrever um valor de para o buffer.  
  
 O exemplo a seguir limita o número de tarefas simultâneas a duas vezes o número de threads de hardware disponível.  Esse valor é um bom ponto inicial a ser usado quando você faz experiências com a sobresubscrição.  Você pode usar um valor que se encaixe em um ambiente específico de processamento ou alterar dinamicamente esse valor para responder à carga de trabalho atual.  
  
 [!CODE [concrt-download-oversubscription#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-download-oversubscription#1)]  
  
 Este exemplo gerencia a seguinte saída em um computador que tenha quatro processadores:  
  
  **Transferência http:\/\/www.adatum.com\/..**  
**Transferência http:\/\/www.adventure\-works.com\/..**  
**Transferência http:\/\/www.alpineskihouse.com\/..**  
**Transferência http:\/\/www.cpandl.com\/..**  
**Transferência http:\/\/www.cohovineyard.com\/..**  
**Transferência http:\/\/www.cohowinery.com\/..**  
**Transferência http:\/\/www.cohovineyardandwinery.com\/..**  
**Transferência http:\/\/www.contoso.com\/..**  
**Transferência http:\/\/www.consolidatedmessenger.com\/..**  
**Transferência http:\/\/www.fabrikam.com\/..**  
**Transferência http:\/\/www.fourthcoffee.com\/..**  
**Transferência http:\/\/www.graphicdesigninstitute.com\/..**  
**Transferência http:\/\/www.humongousinsurance.com\/..**  
**Transferência http:\/\/www.litwareinc.com\/..**  
**Transferência http:\/\/www.lucernepublishing.com\/..**  
**Transferência http:\/\/www.margiestravel.com\/..**  
**Transferência http:\/\/www.northwindtraders.com\/..**  
**Transferência http:\/\/www.proseware.com\/..**  
**Transferência http:\/\/www.fineartschool.net..**  
**Transferência http:\/\/www.tailspintoys.com\/..**  
**Baixado 1801040 bytes em 3276 ms.** O exemplo pode ser executado mais rapidamente quando a sobresubscrição está habilitada porque as tarefas adicionais são executadas quando outras tarefas aguardam uma operação latente para concluir.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `download-oversubscription.cpp` e depois executado dos comandos a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc \/MD \/D "\_AFXDLL" download\-oversubscription.cpp**  
  
 **cl.exe \/EHsc \/MT download\-oversubscription.cpp**  
  
## Programação robusta  
 Sempre sobresubscrição do depois que ele não for mais necessário.  Considere uma função que não trata uma exceção que é lançada por outra função.  Se você não desabilita a sobresubscrição antes que a função retorna, todo o trabalho adicional paralelo também oversubscribe o contexto atual.  
  
 Você pode usar o padrão *Aquisição de recurso é inicialização* \(RAII\) para limitar a sobresubscrição a um escopo fornecido.  No padrão de RAII, uma estrutura de dados é atribuída na pilha.  Se a estrutura de dados inicializa ou adquire um recurso quando é criada e destrói o ou versões esse recurso quando a estrutura de dados é destruída.  O padrão de RAII garante que o destruidor é chamado antes que o escopo inclusive encerrado.  Em virtude disso, o recurso está gerenciadas corretamente quando uma exceção é lançada quando ou uma função contém várias instruções de `return` .  
  
 O exemplo a seguir define uma estrutura denominada `scoped_blocking_signal`.  O construtor da estrutura de `scoped_blocking_signal` habilita a sobresubscrição e o destruidor desabilita a sobresubscrição.  
  
 [!CODE [concrt-download-oversubscription#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-download-oversubscription#2)]  
  
 O exemplo a seguir altera o corpo do método de `download` para usar RAII para assegurar que a sobresubscrição está desabilitada antes que a função retorna.  Essa técnica assegura que o método de `download` exceções gerais é seguro.  
  
 [!CODE [concrt-download-oversubscription#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-download-oversubscription#3)]  
  
## Consulte também  
 [Contextos](../../parallel/concrt/contexts.md)   
 [Método Context::Oversubscribe](../Topic/Context::Oversubscribe%20Method.md)