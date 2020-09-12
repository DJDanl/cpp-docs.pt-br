---
title: Comparando estruturas de dados com a API do Windows
ms.date: 11/04/2016
helpviewer_keywords:
- synchronization data structures, compared to Windows API
- event class, example
ms.assetid: 8b0b1a3a-ef80-408c-91fa-93e6af920b4e
ms.openlocfilehash: b889570935b3a94e0cb8717c8af1783e2ce31c42
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040335"
---
# <a name="comparing-synchronization-data-structures-to-the-windows-api"></a>Comparando estruturas de dados com a API do Windows

Este tópico compara o comportamento das estruturas de dados de sincronização que são fornecidas pelo Tempo de Execução de Simultaneidade àquelas fornecidas pela API do Windows.

As estruturas de dados de sincronização fornecidas pelo Tempo de Execução de Simultaneidade seguem o *modelo de Threading cooperativo*. No modelo de Threading cooperativo, os primitivos de sincronização geram explicitamente seus recursos de processamento para outros threads. Isso difere do *modelo de Threading Preemptive*, em que os recursos de processamento são transferidos para outros threads pelo Agendador de controle ou pelo sistema operacional.

## <a name="critical_section"></a>critical_section

A classe [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md) se assemelha à estrutura do Windows `CRITICAL_SECTION` porque ela pode ser usada somente pelos threads de um processo. Para obter mais informações sobre seções críticas na API do Windows, consulte [objetos de seção crítica](/windows/win32/Sync/critical-section-objects).

## <a name="reader_writer_lock"></a>reader_writer_lock

A classe [Concurrency:: reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) se assemelha a bloqueios de SRW (Windows Slim Reader/Writer). A tabela a seguir explica as semelhanças e diferenças.

| Recurso | Classe `reader_writer_lock` | Bloqueio de SRW |
|--|--|--|
| Não reentrante | Sim | Sim |
| Pode promover um leitor para um gravador (suporte de atualização) | Não | Não |
| Pode rebaixar um gravador para um leitor (suporte de downgrade) | Não | Não |
| Bloqueio de preferência de gravação | Sim | Não |
| Acesso de PEPS a gravadores | Sim | Não |

Para obter mais informações sobre bloqueios de SRW, consulte [bloqueios de SRW (Slim Reader/Writer)](/windows/win32/sync/slim-reader-writer--srw--locks) no SDK da plataforma.

## <a name="event"></a>event

A classe [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) é semelhante a um evento sem nome, de redefinição manual do Windows. No entanto, um `event` objeto se comporta de cooperativa, enquanto um evento do Windows se comporta preemptivamente. Para obter mais informações sobre eventos do Windows, consulte [objetos de evento](/windows/win32/Sync/event-objects).

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Para entender melhor a diferença entre a `event` classe e os eventos do Windows, considere o exemplo a seguir. Este exemplo permite que o Agendador crie no máximo duas tarefas simultâneas e, em seguida, chama duas funções semelhantes que usam a `event` classe e um evento de redefinição manual do Windows. Cada função cria primeiro várias tarefas que esperam que um evento compartilhado se torne sinalizado. Cada função, em seguida, produz as tarefas em execução e, em seguida, sinaliza o evento. Em seguida, cada função aguarda o evento sinalizado.

### <a name="code"></a>Código

[!code-cpp[concrt-event-comparison#1](../../parallel/concrt/codesnippet/cpp/comparing-synchronization-data-structures-to-the-windows-api_1.cpp)]

### <a name="comments"></a>Comentários

Este exemplo produz a seguinte saída de exemplo:

```Output
Cooperative event:
    Context 0: waiting on an event.
    Context 1: waiting on an event.
    Context 2: waiting on an event.
    Context 3: waiting on an event.
    Context 4: waiting on an event.
    Setting the event.
    Context 5: received the event.
    Context 6: received the event.
    Context 7: received the event.
    Context 8: received the event.
    Context 9: received the event.
Windows event:
    Context 10: waiting on an event.
    Context 11: waiting on an event.
    Setting the event.
    Context 12: received the event.
    Context 14: waiting on an event.
    Context 15: received the event.
    Context 16: waiting on an event.
    Context 17: received the event.
    Context 18: waiting on an event.
    Context 19: received the event.
    Context 13: received the event.
```

Como a `event` classe se comporta de cooperativa, o Agendador pode realocar recursos de processamento para outro contexto quando um evento está aguardando para entrar no estado sinalizado. Portanto, mais trabalho é realizado pela versão que usa a `event` classe. Na versão que usa eventos do Windows, cada tarefa em espera deve inserir o estado sinalizado antes que a próxima tarefa seja iniciada.

Para obter mais informações sobre tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="see-also"></a>Confira também

[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)
