---
title: Contextos
ms.date: 11/04/2016
helpviewer_keywords:
- contexts [Concurrency Runtime]
ms.assetid: 10c1d861-8fbb-4ba0-b2ec-61876b11176e
ms.openlocfilehash: 9eaf21a3d65ae891a48657de9d3e7aff78ce12b9
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142185"
---
# <a name="contexts"></a>Contextos

Este documento descreve a função de contextos no Tempo de Execução de Simultaneidade. Um thread que é anexado a um Agendador é conhecido como *contexto de execução*ou apenas *contexto*. A função [Concurrency:: Wait](reference/concurrency-namespace-functions.md#wait) e a classe Concurrency::[Context](../../parallel/concrt/reference/context-class.md) permitem controlar o comportamento de contextos. Use a função `wait` para suspender o contexto atual por um tempo especificado. Use a classe `Context` quando precisar de mais controle sobre quando os contextos são bloqueados, desbloqueados e resultantes, ou quando você deseja ininscrever o contexto atual.

> [!TIP]
> O Tempo de Execução de Simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

## <a name="the-wait-function"></a>A função Wait

A função [Concurrency:: Wait](reference/concurrency-namespace-functions.md#wait) produz cooperativamente a execução do contexto atual para um número especificado de milissegundos. O tempo de execução usa o tempo de concessão para executar outras tarefas. Depois que o tempo especificado tiver decorrido, o tempo de execução reagendará o contexto para execução. Portanto, a função `wait` pode suspender o contexto atual por mais tempo do que o valor fornecido para o parâmetro `milliseconds`.

Passar 0 (zero) para o parâmetro `milliseconds` faz com que o tempo de execução suspenda o contexto atual até que todos os outros contextos ativos recebam a oportunidade de executar o trabalho. Isso permite que você gere uma tarefa para todas as outras tarefas ativas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter um exemplo que usa a função `wait` para gerar o contexto atual e, portanto, permitir que outros contextos sejam executados, consulte [como: usar grupos de agendamento para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).

## <a name="the-context-class"></a>A classe de contexto

A classe Concurrency::[Context](../../parallel/concrt/reference/context-class.md) fornece uma abstração de programação para um contexto de execução e oferece dois recursos importantes: a capacidade de bloquear, desbloquear e gerar o contexto atual de cooperativa e a capacidade de assinar o contexto atual.

### <a name="cooperative-blocking"></a>Bloqueio cooperativo

A classe `Context` permite que você bloqueie ou gere o contexto de execução atual. O bloqueio ou o rendimento é útil quando o contexto atual não pode continuar porque um recurso não está disponível.

O método [Concurrency:: Context:: Block](reference/context-class.md#block) bloqueia o contexto atual. Um contexto que é bloqueado gera seus recursos de processamento para que o tempo de execução possa executar outras tarefas. O método [Concurrency:: Context:: desbloquear](reference/context-class.md#unblock) desbloqueia um contexto bloqueado. O método `Context::Unblock` deve ser chamado de um contexto diferente daquele que chamou `Context::Block`. O tempo de execução gera [Concurrency:: context_self_unblock](../../parallel/concrt/reference/context-self-unblock-class.md) se um contexto tenta desbloquear a si mesmo.

Para bloquear e desbloquear um contexto de forma cooperativa, você normalmente chama [Concurrency:: Context:: CurrentContext](reference/context-class.md#currentcontext) para recuperar um ponteiro para o objeto `Context` associado ao thread atual e salvar o resultado. Em seguida, você chama o método `Context::Block` para bloquear o contexto atual. Posteriormente, chame `Context::Unblock` de um contexto separado para desbloquear o contexto bloqueado.

Você deve corresponder a cada par de chamadas para `Context::Block` e `Context::Unblock`. O tempo de execução gera [Concurrency:: context_unblock_unbalanced](../../parallel/concrt/reference/context-unblock-unbalanced-class.md) quando o método `Context::Block` ou `Context::Unblock` é chamado consecutivamente sem uma chamada correspondente ao outro método. No entanto, você não precisa chamar `Context::Block` antes de chamar `Context::Unblock`. Por exemplo, se um contexto chamar `Context::Unblock` antes que outro contexto chame `Context::Block` para o mesmo contexto, esse contexto permanecerá desbloqueado.

O método [Concurrency:: Context:: yield](reference/context-class.md#yield) produz a execução para que o tempo de execução possa executar outras tarefas e, em seguida, reagendar o contexto para execução. Quando você chama o método `Context::Block`, o tempo de execução não reagenda o contexto.

#### <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter um exemplo que usa os métodos `Context::Block`, `Context::Unblock`e `Context::Yield` para implementar uma classe de semáforo cooperativo, consulte [como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md).

##### <a name="oversubscription"></a>Excesso de assinatura

O agendador padrão cria o mesmo número de threads que há threads de hardware disponíveis. Você pode usar a *assinatura em excesso* para criar threads adicionais para um determinado thread de hardware.

Para operações computacionalmente intensivas, a assinatura em excesso normalmente não é dimensionada porque apresenta sobrecarga adicional. No entanto, para tarefas que têm uma grande quantidade de latência, por exemplo, a leitura de dados do disco ou de uma conexão de rede, a assinatura excedente pode melhorar a eficiência geral de alguns aplicativos.

> [!NOTE]
> Habilite a assinatura somente de um thread que foi criado pelo Tempo de Execução de Simultaneidade. A assinatura excedente não tem efeito quando é chamada a partir de um thread que não foi criado pelo tempo de execução (incluindo o thread principal).

Para habilitar a assinatura em excesso no contexto atual, chame o método [Concurrency:: Context:: Oversubscribe](reference/context-class.md#oversubscribe) com o parâmetro `_BeginOversubscription` definido como **true**. Quando você habilita a assinatura em um thread que foi criado pelo Tempo de Execução de Simultaneidade, ele faz com que o tempo de execução crie um thread adicional. Depois de concluir todas as tarefas que exigem a conclusão da assinatura, chame `Context::Oversubscribe` com o parâmetro `_BeginOversubscription` definido como **false**.

Você pode habilitar o excesso de assinaturas várias vezes do contexto atual, mas você deve desabilitá-lo o mesmo número de vezes que habilitá-lo. A assinatura em excesso também pode ser aninhada; ou seja, uma tarefa que é criada por outra tarefa que usa a assinatura excedente também pode se inscrever em seu contexto. No entanto, se uma tarefa aninhada e seu pai pertencerem ao mesmo contexto, somente a chamada mais externa para `Context::Oversubscribe` causará a criação de um thread adicional.

> [!NOTE]
> O tempo de execução gera [Concurrency:: invalid_oversubscribe_operation](../../parallel/concrt/reference/invalid-oversubscribe-operation-class.md) se a assinatura em excesso estiver desabilitada antes de ser habilitada.

###### <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter um exemplo que usa a assinatura em excesso para deslocar a latência causada pela leitura de dados de uma conexão de rede, consulte [como: usar a superassinatura para a latência de deslocamento](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).

## <a name="see-also"></a>Consulte também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Como usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)<br/>
[Como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br/>
[Como usar excesso de assinatura para compensar a latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)
