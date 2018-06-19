---
title: Comparando estruturas de dados de sincronização para a API do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- synchronization data structures, compared to Windows API
- event class, example
ms.assetid: 8b0b1a3a-ef80-408c-91fa-93e6af920b4e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d1470911b13243a7c8b3befc627801368e89f04
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33687368"
---
# <a name="comparing-synchronization-data-structures-to-the-windows-api"></a>Comparando estruturas de dados de sincronização com a API do Windows
Este tópico compara o comportamento das estruturas de dados de sincronização que são fornecidos pelo tempo de execução de simultaneidade aos fornecidos pela API do Windows.  
  
 Siga as estruturas de dados de sincronização que são fornecidas pelo tempo de execução de simultaneidade o *cooperativo modelo de threading*. No modelo de threading cooperativo, primitivos de sincronização explicitamente geram seus recursos de processamento para outros threads. Isso difere do *preemptivo modelo de threading*, onde os recursos de processamento são transferidos para outros threads pelo Agendador controlar ou sistema operacional.  
  
## <a name="criticalsection"></a>critical_section  
 O [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) é semelhante a Windows `CRITICAL_SECTION` estrutura porque ele pode ser usado somente por segmentos de um processo. Para obter mais informações sobre seções críticas na API do Windows, consulte [objetos de seção crítica](http://msdn.microsoft.com/library/windows/desktop/ms682530).  
  
## <a name="readerwriterlock"></a>reader_writer_lock  
 O [concurrency::reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) bloqueios de leitor/gravador (SRW) do Windows é semelhante. A tabela a seguir explica as semelhanças e diferenças.  
  
|Recurso|`reader_writer_lock`|Bloqueio de SRW|  
|-------------|--------------------------|--------------|  
|Não reentrante|Sim|Sim|  
|Promova um leitor para o gravador (suporte de atualização)|Não|Não|  
|Rebaixar um gravador a um leitor (suporte a downgrade)|Não|Não|  
|Bloqueio de gravação de preferência|Sim|Não|  
|Acesso de FIFO para autores|Sim|Não|  
  
 Para obter mais informações sobre os bloqueios de SRW, consulte [os bloqueios de leitor/gravador fino (SRW)](http://msdn.microsoft.com/library/windows/desktop/aa904937) no SDK da plataforma.  
  
## <a name="event"></a>evento  
 O [concurrency::event](../../parallel/concrt/reference/event-class.md) classe é semelhante a um evento de redefinição manual sem nome, do Windows. No entanto, um `event` objeto se comporta de forma cooperativa, enquanto um evento do Windows se comporta preventivamente. Para obter mais informações sobre eventos do Windows, consulte [objetos de evento](http://msdn.microsoft.com/library/windows/desktop/ms682655).  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 Para melhor compreender a diferença entre o `event` classe e eventos do Windows, considere o exemplo a seguir. Este exemplo habilita o Agendador criar no máximo duas tarefas simultâneas e, em seguida, chama semelhante duas funções que usam o `event` classe e um evento de redefinição manual do Windows. Cada função primeiro cria várias tarefas que aguardar um evento compartilhado ficar sinalizado. Cada função, em seguida, gera para as tarefas em execução e, em seguida, sinaliza o evento. Cada função, em seguida, aguarda o evento sinalizado.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-event-comparison#1](../../parallel/concrt/codesnippet/cpp/comparing-synchronization-data-structures-to-the-windows-api_1.cpp)]  
  
### <a name="comments"></a>Comentários  
 Este exemplo produz a saída de exemplo a seguir:  
  
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
  
 Porque o `event` classe se comporta de forma cooperativa, o Agendador pode realocar recursos de processamento para outro contexto quando um evento está esperando para entrar no estado sinalizado. Portanto, mais trabalho é realizado pela versão que usa o `event` classe. A versão que usa eventos do Windows, cada tarefa em espera deve inserir o estado sinalizado antes que a próxima tarefa é iniciada.  
  
 Para obter mais informações sobre tarefas, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)
