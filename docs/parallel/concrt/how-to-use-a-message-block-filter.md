---
title: 'Como: usar um filtro de bloco de mensagens | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- message-block filters, using [Concurrency Runtime]
- using message-block filters [Concurrency Runtime]
ms.assetid: db6b99fb-288d-4477-96dc-b9751772ebb2
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: adcb300daa81c1325b216128b1971408a5931553
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-a-message-block-filter"></a>Como usar um filtro de bloco de mensagens
Este documento demonstra como usar uma função de filtro para habilitar um bloco de mensagens assíncronas aceitar ou rejeitar uma mensagem com base na carga da mensagem.  
  
 Quando você cria um objeto de bloqueio de mensagem, como um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md), um [concurrency::call](../../parallel/concrt/reference/call-class.md), ou um [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md), você pode fornecer um *função filter* que determina se o protocolo SMB aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil para garantir que um bloco de mensagem recebe somente determinados valores.  
  
 Funções de filtro são importantes, porque elas permitem que você para se conectar blocos de mensagens ao formulário *redes de fluxo de dados*. Em uma rede de fluxo de dados, blocos de mensagens de controlam o fluxo de dados processando apenas as mensagens que atendem a critérios específicos. Compare isso com o modelo de fluxo de controle, em que o fluxo de dados é controlado usando estruturas de controle, como instruções condicionais, loops e assim por diante.  
  
 Este documento fornece um exemplo básico de como usar um filtro de mensagem. Para obter exemplos adicionais que usam filtros de mensagem e o modelo de fluxo de dados para conectar-se o protocolo SMB, consulte [passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md) e [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md) .  
  
## <a name="example"></a>Exemplo  
 Considere a seguinte função, `count_primes`, que ilustra o uso básico de um bloco de mensagens que não filtra as mensagens de entrada. O bloco de mensagem acrescenta números primos para um [std:: Vector](../../standard-library/vector-class.md) objeto. O `count_primes` função envia vários números para o bloco de mensagens, recebe os valores de saída do protocolo SMB e imprime esses números primos no console.  
  
 [!code-cpp[concrt-primes-filter#1](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_1.cpp)]  
  
 O `transformer` objeto processa os valores de todas as entrada; no entanto, ele requer somente os valores que são o principal. Embora o aplicativo poderia ser escrito para que o remetente da mensagem envia somente os números primos, os requisitos do receptor da mensagem não podem sempre ser conhecidos.  
  
## <a name="example"></a>Exemplo  
 A função a seguir, `count_primes_filter`, executa a mesma tarefa de `count_primes` função. No entanto, o `transformer` objeto nesta versão usa uma função de filtro para aceitar apenas os valores que são o principal. A função que executa a ação recebe apenas os números primos. Portanto, não precisa chamar o `is_prime` função.  
  
 Porque o `transformer` objeto recebe apenas os números primos, a `transformer` próprio objeto pode conter os números primos. Em outras palavras, o `transformer` objeto neste exemplo não é necessário para adicionar os números primos para o `vector` objeto.  
  
 [!code-cpp[concrt-primes-filter#2](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_2.cpp)]  
  
 O `transformer` objeto agora processa apenas os valores que são o principal. No exemplo anterior, `transformer` objeto processa todas as mensagens. Portanto, o exemplo anterior deve receber o mesmo número de mensagens que ele envia. Este exemplo usa o resultado da [concurrency::send](reference/concurrency-namespace-functions.md#send) função para determinar quantas mensagens para receber o `transformer` objeto. O `send` função retorna `true` quando o buffer de mensagem aceita a mensagem e `false` quando o buffer de mensagem rejeitará a mensagem. Portanto, o número de vezes que o buffer de mensagem aceita a mensagem corresponde à contagem de números primos.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um exemplo completo. O exemplo chama ambos o `count_primes` função e o `count_primes_filter` função.  
  
 [!code-cpp[concrt-primes-filter#3](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_3.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `primes-filter.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc números primos-filter.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Cada função de filtro usa uma das seguintes formas:  
  
```Output  
bool (T)  
bool (T const &)  
```  
  
 Para eliminar o desnecessária cópia de dados, use o segundo formulário quando você tem um tipo de agregação que é transmitido por valor.  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)   
 [Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)   
 [Classe transformer](../../parallel/concrt/reference/transformer-class.md)
