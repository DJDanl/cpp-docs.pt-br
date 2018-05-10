---
title: Contextos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- contexts [Concurrency Runtime]
ms.assetid: 10c1d861-8fbb-4ba0-b2ec-61876b11176e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9a8297c8a7a779140f6464f39491e73950ddaeeb
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="contexts"></a>Contextos

Este documento descreve a função de contextos no tempo de execução de simultaneidade. Um thread que está anexado a um agendador é conhecido como um *contexto de execução*, ou apenas *contexto*. O [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função e a simultaneidade::[classe de contexto](../../parallel/concrt/reference/context-class.md) permitem controlar o comportamento de contextos. Use o `wait` função suspender o contexto atual por um período especificado. Use o `Context` classe quando precisar de mais controle sobre quando contextos bloqueiam, desbloqueiam e produzem, ou quando quiser subscrever o contexto atual.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
## <a name="the-wait-function"></a>A função de espera  

 O [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função produz trabalhem de forma a execução do contexto atual para um número especificado de milissegundos. O tempo de execução usa a hora de rendimento executar outras tarefas. Depois que o tempo especificado tiver decorrido, o tempo de execução reagenda o contexto de execução. Portanto, o `wait` função pode suspender o contexto atual mais do que o valor fornecido para o `milliseconds` parâmetro.  
  
 Passando zero (0) para o `milliseconds` parâmetro faz com que o tempo de execução suspender o contexto atual até que todos os outros contextos ativos terá a oportunidade de realizar o trabalho. Isso permite gerar uma tarefa para todas as outras tarefas ativas.  
  
### <a name="example"></a>Exemplo  
 Para obter um exemplo que usa o `wait` de função para gerar o contexto atual e portanto permitem outros contextos de execução, consulte [como: usar grupos de agendamento para ordem de execução de influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).  
  
## <a name="the-context-class"></a>Classe de contexto  
 A simultaneidade::[classe de contexto](../../parallel/concrt/reference/context-class.md) fornece uma abstração de programação para um contexto de execução e oferece dois recursos importantes: a capacidade de forma cooperativa bloquear, desbloquear e gerar o contexto atual e a capacidade subscrever o contexto atual.  
  
### <a name="cooperative-blocking"></a>Bloqueio cooperativo  
 O `Context` classe permite que você bloqueie ou gera o contexto de execução atual. Bloquear ou gerando é útil quando o contexto atual não pode continuar porque um recurso não está disponível.  
  

 O [concurrency::Context::Block](reference/context-class.md#block) método bloqueia o contexto atual. Um contexto que é bloqueado resulta em seus recursos de processamento para que o tempo de execução poderá executar outras tarefas. O [concurrency::Context::Unblock](reference/context-class.md#unblock) método desbloqueia um contexto de bloqueado. O `Context::Unblock` método deve ser chamado em um contexto diferente daquele chamado `Context::Block`. O tempo de execução gera [concurrency::context_self_unblock](../../parallel/concrt/reference/context-self-unblock-class.md) se um contexto tenta desbloquear em si.  
  
 Para a forma cooperativa bloquear e desbloquear um contexto, você normalmente chama [concurrency::Context::CurrentContext](reference/context-class.md#currentcontext) para recuperar um ponteiro para o `Context` objeto que está associado com o segmento atual e salvar o resultado. Em seguida, chamar o `Context::Block` método para bloquear o contexto atual. Mais tarde, chamar `Context::Unblock` em um contexto separado para desbloquear o contexto bloqueado.  
  
 Você deve corresponder cada par de chamadas para `Context::Block` e `Context::Unblock`. O tempo de execução gera [concurrency::context_unblock_unbalanced](../../parallel/concrt/reference/context-unblock-unbalanced-class.md) quando o `Context::Block` ou `Context::Unblock` método é chamado consecutivamente sem uma chamada correspondente para o outro método. No entanto, você não precisa chamar `Context::Block` antes de chamar `Context::Unblock`. Por exemplo, se um contexto chama `Context::Unblock` antes de outra chamada de contexto `Context::Block` para o mesmo contexto, nesse contexto permanece desbloqueado.  
  
 O [concurrency::Context::Yield](reference/context-class.md#yield) método resulta em execução para que o tempo de execução pode executar outras tarefas e reagendar o contexto de execução. Quando você chama o `Context::Block` método, o tempo de execução não reagendar o contexto.  

  
#### <a name="example"></a>Exemplo  
 Para obter um exemplo que usa o `Context::Block`, `Context::Unblock`, e `Context::Yield` métodos para implementar uma classe de sinal cooperativo, consulte [como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md).  
  
##### <a name="oversubscription"></a>Excesso de assinatura  
 O agendador padrão cria o mesmo número de threads como segmentos de hardware disponíveis. Você pode usar *excesso de assinatura* para criar threads adicionais para um thread de hardware específica.  
  
 Para operações de computação intensas, excesso de assinatura geralmente não são dimensionadas porque ela introduz uma sobrecarga adicional. No entanto, para tarefas que têm uma grande quantidade de latência, por exemplo, dados de leitura de disco ou de uma conexão de rede, excesso de assinatura pode melhorar a eficiência geral de alguns aplicativos.  
  
> [!NOTE]
>  Habilite o excesso de assinatura somente de um thread que foi criado pelo tempo de execução de simultaneidade. Excesso de assinatura não tem nenhum efeito quando ele é chamado de um thread que não foi criado pelo tempo de execução (incluindo o thread principal).  
  
 Para habilitar o excesso de assinatura no contexto atual, chame o [concurrency::Context::Oversubscribe](reference/context-class.md#oversubscribe) método com o `_BeginOversubscription` parâmetro definido como `true`. Quando você habilita o excesso de assinatura em um thread que foi criado pelo tempo de execução de simultaneidade, ele faz com que o tempo de execução criar um thread adicional. Depois de todas as tarefas que exigem o término de excesso de assinatura, chamar `Context::Oversubscribe` com o `_BeginOversubscription` parâmetro definido como `false`.  

  
 Você pode habilitar o excesso de assinatura várias vezes no contexto atual, mas você deve desabilitar o mesmo número de vezes que você habilitá-la. Excesso de assinatura também pode ser aninhado. ou seja, uma tarefa que é criada por outra tarefa que usa o excesso de assinatura também pode subscrever seu contexto. No entanto, se uma tarefa aninhada e seu pai pertencerem ao mesmo contexto, somente a chamada mais externo para `Context::Oversubscribe` faz com que a criação de um thread adicional.  
  
> [!NOTE]
>  O tempo de execução gera [concurrency::invalid_oversubscribe_operation](../../parallel/concrt/reference/invalid-oversubscribe-operation-class.md) se excesso de assinatura é desabilitado antes que ele está habilitado.  
  
###### <a name="example"></a>Exemplo  
 Para obter um exemplo que usa o excesso de assinatura para deslocar a latência causada por ler dados de uma conexão de rede, consulte [como: excesso de assinatura de uso a latência de deslocamento](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Como: usar grupos de agendas para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)   
 [Como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)   
 [Como usar excesso de assinatura para compensar a latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)

