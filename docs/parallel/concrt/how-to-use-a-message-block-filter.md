---
title: "Como usar um filtro de bloco de mensagens | Microsoft Docs"
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
  - "filtros de bloco de mensagens, usando [tempo de execução de simultaneidade]"
  - "usando filtros de blocos de mensagens [Tempo de Execução de Simultaneidade]"
ms.assetid: db6b99fb-288d-4477-96dc-b9751772ebb2
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar um filtro de bloco de mensagens
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento demonstra como usar uma função de filtro para habilitar um bloco de mensagens assíncronas aceitar ou rejeitar uma mensagem com base na carga da mensagem.  
  
 Quando você cria um objeto de bloqueio de mensagem, como um [concurrency::unbounded_buffer](../Topic/unbounded_buffer%20Class.md), um [concurrency::call](../../parallel/concrt/reference/call-class.md), ou uma [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md), você pode fornecer uma *função filter* que determina se o protocolo SMB aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil para garantir que um bloco de mensagens recebe apenas determinados valores.  
  
 Funções de filtro são importantes porque elas permitem que você para se conectar blocos de mensagens ao formulário *redes de fluxo de dados*. Em uma rede de fluxo de dados, blocos de mensagens de controlam o fluxo de dados, somente as mensagens que atendam a critérios específicos de processamento. Compare isso com o modelo de fluxo de controle, em que o fluxo de dados é controlado por meio de estruturas de controle, como instruções condicionais, loops e assim por diante.  
  
 Este documento fornece um exemplo básico de como usar um filtro de mensagem. Para obter exemplos adicionais que usam filtros de mensagem e o modelo de fluxo de dados para conectar blocos de mensagens, consulte [passo a passo: Criando um agente de fluxo de dados](../Topic/Walkthrough:%20Creating%20a%20Dataflow%20Agent.md) e [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).  
  
## <a name="example"></a>Exemplo  
 Considere a seguinte função, `count_primes`, que ilustra o uso básico de um bloco de mensagens que não filtra as mensagens de entrada. O bloco de mensagem acrescenta números primos para um [std:: Vector](../../standard-library/vector-class.md) objeto. O `count_primes` função envia vários números para o bloco de mensagem, recebe os valores de saída do protocolo SMB e imprime os números primos no console.  
  
 [!CODE [concrt-primes-filter#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-primes-filter#1)]  
  
 O `transformer` objeto processa a entrada todos os valores; no entanto, ele requer somente os valores que são o principal. Embora o aplicativo poderia ser escrito para que o remetente da mensagem envia somente os números primos, os requisitos do receptor da mensagem não podem sempre ser conhecidos.  
  
## <a name="example"></a>Exemplo  
 A função a seguir, `count_primes_filter`, executa a mesma tarefa de `count_primes` função. No entanto, o `transformer` objeto nesta versão usa uma função de filtro para aceitar apenas os valores que são o principal. A função que executa a ação recebe apenas números primos; Portanto, não precisa chamar o `is_prime` função.  
  
 Porque o `transformer` objeto recebe apenas os números primos, o `transformer` objeto propriamente dito pode armazenar os números primos. Em outras palavras, o `transformer` objeto neste exemplo não é necessário adicionar os números primos para o `vector` objeto.  
  
 [!CODE [concrt-primes-filter#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-primes-filter#2)]  
  
 O `transformer` objeto agora processa apenas os valores que são o principal. No exemplo anterior, `transformer` objeto processa todas as mensagens. Portanto, o exemplo anterior deve receber o mesmo número de mensagens que ele envia. Este exemplo usa o resultado do [concurrency::send](../Topic/send%20Function.md) função para determinar quantas mensagens para receber o `transformer` objeto. O `send` função retorna `true` quando o buffer de mensagens aceita a mensagem e `false` quando o buffer de mensagens rejeitará a mensagem. Portanto, o número de vezes que o buffer de mensagens aceite a mensagem coincide com a contagem de números primos.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um exemplo completo. O exemplo chama ambos os `count_primes` função e o `count_primes_filter` função.  
  
 [!CODE [concrt-primes-filter#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-primes-filter#3)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `primes-filter.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc primes-filter.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Todas as funções de filtro usa uma das seguintes formas:  
  
```Output  
bool (T)  
bool (T const &)  
```  
  
 Para eliminar a cópia desnecessária de dados, use o segundo formulário quando você tem um tipo de agregação que é transmitido por valor.  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Passo a passo: Criando um agente de fluxo de dados](../Topic/Walkthrough:%20Creating%20a%20Dataflow%20Agent.md)   
 [Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)   
 [Classe Transformer](../../parallel/concrt/reference/transformer-class.md)
