---
title: "Estruturas de dados de sincronização | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: synchronization data structures
ms.assetid: d612757d-e4b7-4019-a627-f853af085b8b
caps.latest.revision: "26"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1dd1c47cad01e0324f8027593eb4933f70cd6191
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="synchronization-data-structures"></a>Estruturas de dados de sincronização
O tempo de execução de simultaneidade fornece várias estruturas de dados que lhe permite sincronizar o acesso aos dados compartilhados de vários threads. Essas estruturas de dados são úteis quando você compartilhou dados que você pode modificar raramente. Um objeto de sincronização, por exemplo, uma seção crítica, faz com que outros threads de espera até que o recurso compartilhado está disponível. Portanto, se você usar esse tipo de objeto para sincronizar o acesso aos dados que são usados com frequência, você poderá perder escalabilidade em seu aplicativo. O [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) fornece o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe, que permite que você compartilhe um recurso, entre vários threads ou tarefas sem a necessidade de sincronização. Para obter mais informações sobre o `combinable` de classe, consulte [objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md).  
  
##  <a name="top"></a>Seções  
 Este tópico descreve os seguintes tipos de bloco de mensagens assíncronas detalhadamente:  
  
-   [CRITICAL_SECTION](#critical_section)  
  
-   [reader_writer_lock](#reader_writer_lock)  
  
-   [scoped_lock e scoped_lock_read](#scoped_lock)  
  
-   [event](#event)  
  
##  <a name="critical_section"></a>CRITICAL_SECTION  
 O [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) classe representa um objeto de exclusão mútua cooperativa que gera a outras tarefas em vez de antecipação-los. Seções críticas são úteis quando vários threads requerem exclusiva acesso de leitura e gravação aos dados compartilhados.  

 O `critical_section` classe é não reentrante. O [concurrency::critical_section::lock](reference/critical-section-class.md#lock) método lançará uma exceção do tipo [concurrency::improper_lock](../../parallel/concrt/reference/improper-lock-class.md) se ele é chamado por um thread que já possui o bloqueio.  


  
### <a name="methods-and-features"></a>Métodos e recursos  
 A tabela a seguir mostra os métodos importantes que são definidos pelo `critical_section` classe.  
  
|Método|Descrição|  
|------------|-----------------|  
|[lock](reference/critical-section-class.md#lock)|Adquire a seção crítica. Os blocos de contexto chamada até que ele adquire o bloqueio.|  
|[try_lock](reference/critical-section-class.md#try_lock)|Tenta adquirir a seção crítica, mas não bloquear.|  
|[unlock](reference/critical-section-class.md#unlock)|Libera a seção crítica.|  
  
 [[Superior](#top)]  
  
##  <a name="reader_writer_lock"></a>reader_writer_lock  
 O [concurrency::reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) classe fornece operações de leitura/gravação do thread-safe aos dados compartilhados. Use bloqueios de leitor/gravador quando vários threads requerem acesso simultâneo de leitura a um recurso compartilhado, mas raramente gravar a tal recurso compartilhado. Essa classe fornece acesso de gravação apenas um thread de um objeto a qualquer momento.  
  
 O `reader_writer_lock` classe pode executar melhor do que o `critical_section` classe porque um `critical_section` objeto adquire acesso exclusivo a um recurso compartilhado, o que impede o acesso simultâneo de leitura.  
  
 Como o `critical_section` classe, o `reader_writer_lock` classe representa um objeto de exclusão mútua cooperativa que gera a outras tarefas em vez de antecipação-los.  
  
 Quando um thread que deve gravar em um recurso compartilhado adquire um bloqueio de leitor/gravador, outros threads que também devem acessar o recurso serão bloqueados até que o gravador libera o bloqueio. O `reader_writer_lock` classe é um exemplo de um *preferência de gravação* bloqueio, que é um bloqueio que desbloqueia os gravadores de espera antes de ele desbloqueia leitores aguardando.  
  
 Como o `critical_section` classe, o `reader_writer_lock` classe é não reentrante. O [concurrency::reader_writer_lock::lock](reference/reader-writer-lock-class.md#lock) e [concurrency::reader_writer_lock::lock_read](reference/reader-writer-lock-class.md#lock_read) métodos lançam uma exceção do tipo `improper_lock` se eles são chamados por um thread que já possui o bloqueio.  


  
> [!NOTE]
>  Porque o `reader_writer_lock` classe é não reentrante, você não pode atualizar um bloqueio de somente leitura para um bloqueio de leitor/gravador ou rebaixar um bloqueio de leitor/gravador a um bloqueio de somente leitura. Executar qualquer uma dessas operações produz o comportamento não especificado.  
  
### <a name="methods-and-features"></a>Métodos e recursos  
 A tabela a seguir mostra os métodos importantes que são definidos pelo `reader_writer_lock` classe.  
  
|Método|Descrição|  
|------------|-----------------|  
|[lock](reference/reader-writer-lock-class.md#lock)|Obtém o acesso de leitura/gravação para o bloqueio.|  
|[try_lock](reference/reader-writer-lock-class.md#try_lock)|Tenta adquirir o acesso de leitura/gravação para o bloqueio, mas não bloquear.|  
|[lock_read](reference/reader-writer-lock-class.md#lock_read)|Obtém o acesso somente leitura para o bloqueio.|  
|[try_lock_read](reference/reader-writer-lock-class.md#try_lock_read)|Tenta adquirir o acesso somente leitura para o bloqueio, mas não bloquear.|  
|[unlock](reference/reader-writer-lock-class.md#unlock)|Libera o bloqueio.|  
  
 [[Superior](#top)]  
  
##  <a name="scoped_lock"></a>scoped_lock e scoped_lock_read  
 O `critical_section` e `reader_writer_lock` classes fornecem classes aninhadas auxiliares que simplificam a maneira de trabalhar com objetos de exclusão mútua. Essas classes auxiliares são conhecidas como *escopo bloqueios*.  
  
 O `critical_section` classe contém o [concurrency::critical_section::scoped_lock](reference/critical-section-class.md#critical_section__scoped_lock_class) classe. O construtor adquire acesso ao fornecido `critical_section` objeto; o acesso de versões do destruidor para esse objeto. O `reader_writer_lock` classe contém o [concurrency::reader_writer_lock::scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class) classe, que é semelhante a `critical_section::scoped_lock`, exceto que ele gerencia o acesso de gravação fornecido `reader_writer_lock` objeto. O `reader_writer_lock` classe também contém o [concurrency::reader_writer_lock::scoped_lock_read](reference/reader-writer-lock-class.md#scoped_lock_read_class) classe. Essa classe gerencia o acesso de leitura fornecido `reader_writer_lock` objeto.  

  
 Bloqueios no escopo oferecem muitos benefícios, quando você estiver trabalhando com `critical_section` e `reader_writer_lock` objetos manualmente. Normalmente, você alocar um bloqueio no escopo na pilha. Um bloqueio no escopo libera acesso ao seu objeto de exclusão mútua automaticamente quando ele é destruído; Portanto, você não desbloquear manualmente o objeto subjacente. Isso é útil quando uma função contém várias `return` instruções. Bloqueios no escopo podem ajudá-lo a escrever código de exceção-safe. Quando um `throw` instrução faz com que a pilha de desenrolar o destruidor para qualquer bloqueio escopo ativo é chamado e, portanto, o objeto de exclusão mútua é liberado sempre corretamente.  
  
> [!NOTE]
>  Quando você usa o `critical_section::scoped_lock`, `reader_writer_lock::scoped_lock`, e `reader_writer_lock::scoped_lock_read` classes, não liberar manualmente acesso ao objeto de exclusão mútua subjacente. Isso pode colocar o tempo de execução em um estado inválido.  
  
##  <a name="event"></a>evento  
 O [concurrency::event](../../parallel/concrt/reference/event-class.md) classe representa um objeto de sincronização cujo estado pode ser sinalizado ou não sinalizado. Ao contrário de objetos de sincronização, como seções críticas, cujo propósito é proteger o acesso aos dados compartilhados, eventos sincronizam o fluxo de execução.  
  
 O `event` classe é útil quando uma tarefa tiver concluído o trabalho para outra tarefa. Por exemplo, uma tarefa pode sinalizar outra tarefa que ele tem ler dados de uma conexão de rede ou de um arquivo.  
  
### <a name="methods-and-features"></a>Métodos e recursos  
 A tabela a seguir mostra os vários métodos importantes que são definidos pelo `event` classe.  
  
|Método|Descrição|  
|------------|-----------------|  
|[Aguarde](reference/event-class.md#wait)|Aguarda o evento tornou-se sinalizado.|  
|[set](reference/event-class.md#set)|Define o evento para o estado sinalizado.|  
|[reset](reference/event-class.md#reset)|Define o evento para o estado não sinalizado.|  
|[wait_for_multiple](reference/event-class.md#wait_for_multiple)|Espera por vários eventos ficar sinalizado.|  

  
### <a name="example"></a>Exemplo  
 Para obter um exemplo que mostra como usar o `event` de classe, consulte [comparando estruturas de dados de sincronização para a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md).  
  
 [[Superior](#top)]  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Comparando estruturas de dados de sincronização com a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md)  
 Compara o comportamento das estruturas de dados de sincronização aos fornecidos pela API do Windows.  
  
 [Tempo de Execução de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)  
 Descreve o tempo de execução de simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.

