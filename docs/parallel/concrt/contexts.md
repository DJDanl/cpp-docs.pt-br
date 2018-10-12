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
ms.openlocfilehash: 9fb14544a799861053c2fdf2a5bb92f210eb5c46
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49163823"
---
# <a name="contexts"></a>Contextos

Este documento descreve a função dos contextos no tempo de execução de simultaneidade. Um thread que está anexado a um agendador é conhecido como um *contexto de execução*, ou apenas *contexto*. O [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função e a simultaneidade::[classe de contexto](../../parallel/concrt/reference/context-class.md) permitem controlar o comportamento de contextos. Use o `wait` função suspender o contexto atual por um período especificado. Use o `Context` classe quando precisar de mais controle sobre quando contextos de bloquear, desbloqueiam e produzam, ou quando você deseja substituir o contexto atual.

> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda você a ajustar o desempenho de seus aplicativos, é recomendável que você comece com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.

## <a name="the-wait-function"></a>A função de espera

O [concurrency::wait](reference/concurrency-namespace-functions.md#wait) função cooperativamente produz a execução do contexto atual para um número especificado de milissegundos. O tempo de execução usa o tempo de rendimento para realizar outras tarefas. Depois de decorrido o tempo especificado, o tempo de execução reagenda o contexto de execução. Portanto, o `wait` função pode suspender o contexto atual mais do que o valor fornecido para o `milliseconds` parâmetro.

Passando 0 (zero) para o `milliseconds` parâmetro faz com que o tempo de execução suspender o contexto atual até que todos os outros contextos de Active Directory recebem a oportunidade de executar o trabalho. Isso permite gerar uma tarefa para todas as outras tarefas do Active Directory.

### <a name="example"></a>Exemplo

Para obter um exemplo que usa o `wait` funcionar para produzir o contexto atual e, portanto, permitem outros contextos de execução, consulte [como: Use grupos de agendamento para a ordem de execução influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).

## <a name="the-context-class"></a>A classe de contexto

A simultaneidade::[classe de contexto](../../parallel/concrt/reference/context-class.md) fornece uma abstração de programação para um contexto de execução e oferece dois recursos importantes: a capacidade de forma cooperativa bloquear, desbloquear e gerar o contexto atual e a capacidade subscrever o contexto atual.

### <a name="cooperative-blocking"></a>Bloqueio cooperativo

O `Context` classe permite que você bloqueie ou gerar o contexto de execução atual. Bloquear ou resposta é útil quando o contexto atual não pode continuar porque um recurso não está disponível.

O [concurrency::Context::Block](reference/context-class.md#block) método bloqueia o contexto atual. Um contexto que está bloqueado resulta em seus recursos de processamento para que o tempo de execução poderá executar outras tarefas. O [concurrency::Context::Unblock](reference/context-class.md#unblock) método desbloqueia um contexto bloqueados. O `Context::Unblock` método deve ser chamado de um contexto diferente daquele que chamado `Context::Block`. O tempo de execução gera [concurrency::context_self_unblock](../../parallel/concrt/reference/context-self-unblock-class.md) se um contexto tenta desbloquear em si.

Para cooperativamente bloquear e desbloquear um contexto, você normalmente chama [concurrency::Context::CurrentContext](reference/context-class.md#currentcontext) para recuperar um ponteiro para o `Context` objeto que está associado com o thread atual e salve o resultado. Você, em seguida, chamar o `Context::Block` para bloquear o contexto atual. Posteriormente, chamar `Context::Unblock` de um contexto separado para desbloquear o contexto bloqueados.

Você deve corresponder cada par de chamadas para `Context::Block` e `Context::Unblock`. O tempo de execução gera [concurrency::context_unblock_unbalanced](../../parallel/concrt/reference/context-unblock-unbalanced-class.md) quando o `Context::Block` ou `Context::Unblock` método é chamado consecutivamente sem uma chamada correspondente para o outro método. No entanto, você não precisa chamar `Context::Block` antes de chamar `Context::Unblock`. Por exemplo, se um contexto chama `Context::Unblock` antes de outra chamada de contexto `Context::Block` para o mesmo contexto, esse contexto permaneça desbloqueado.

O [concurrency::Context::Yield](reference/context-class.md#yield) método produz a execução para que o tempo de execução pode executar outras tarefas e, em seguida, reagende o contexto de execução. Quando você chama o `Context::Block` método, o tempo de execução não reagendar o contexto.

#### <a name="example"></a>Exemplo

Para obter um exemplo que usa o `Context::Block`, `Context::Unblock`, e `Context::Yield` métodos para implementar uma classe de semáforo cooperativo, consulte [como: usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md).

##### <a name="oversubscription"></a>Excesso de assinatura

O agendador padrão cria o mesmo número de threads, como há threads de hardware disponíveis. Você pode usar *excesso de assinatura* para criar threads adicionais para um thread de hardware específico.

Para operações de computação intensivas, o excesso de assinaturas normalmente não escala porque ela introduz uma sobrecarga adicional. No entanto, para tarefas que têm uma grande quantidade de latência, por exemplo, ler dados do disco ou de uma conexão de rede, o excesso de assinaturas pode melhorar a eficiência geral de alguns aplicativos.

> [!NOTE]
>  Habilite o excesso de assinatura somente de um thread que foi criado pelo tempo de execução de simultaneidade. Excesso de assinatura não tem nenhum efeito quando ele é chamado de um thread que não foi criado pelo tempo de execução (incluindo o thread principal).

Para habilitar assinaturas em excesso no contexto atual, chame o [concurrency::Context::Oversubscribe](reference/context-class.md#oversubscribe) método com o `_BeginOversubscription` parâmetro definido como **true**. Quando você habilita o excesso de assinaturas em um thread que foi criado pelo tempo de execução de simultaneidade, faz com que o tempo de execução criar um thread adicional. Depois de todas as tarefas que exigem o término de excesso de assinatura, chame `Context::Oversubscribe` com o `_BeginOversubscription` parâmetro definido como **falso**.

Você pode habilitar o excesso de assinatura várias vezes do contexto atual, mas você deve desabilitar o mesmo número de vezes que você habilitá-lo. Excesso de assinatura também pode ser aninhado. ou seja, uma tarefa que é criada por outra tarefa que usa o excesso de assinatura também pode substituir seu contexto. No entanto, se uma tarefa aninhada e seu pai pertencem ao mesmo contexto, somente a chamada mais externo para `Context::Oversubscribe` faz com que a criação de um thread adicional.

> [!NOTE]
>  O tempo de execução gera [concurrency::invalid_oversubscribe_operation](../../parallel/concrt/reference/invalid-oversubscribe-operation-class.md) se o excesso de assinaturas estiver desabilitado antes que ele está habilitado.

###### <a name="example"></a>Exemplo

Para obter um exemplo que usa o excesso de assinatura para deslocar a latência causada por leitura de dados de uma conexão de rede, consulte [como: excesso de assinatura de uso à latência de deslocamento](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md).

## <a name="see-also"></a>Consulte também

[Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Como usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)<br/>
[Como usar a classe de contexto para implementar um semáforo cooperativo](../../parallel/concrt/how-to-use-the-context-class-to-implement-a-cooperative-semaphore.md)<br/>
[Como usar excesso de assinatura para compensar a latência](../../parallel/concrt/how-to-use-oversubscription-to-offset-latency.md)

