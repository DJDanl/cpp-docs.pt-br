---
title: Estruturas de dados de sincronização
ms.date: 11/04/2016
helpviewer_keywords:
- synchronization data structures
ms.assetid: d612757d-e4b7-4019-a627-f853af085b8b
ms.openlocfilehash: 244aaac9bd40c83d0bbec3c360bdf7351da54baf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231657"
---
# <a name="synchronization-data-structures"></a>Estruturas de dados de sincronização

O Tempo de Execução de Simultaneidade fornece várias estruturas de dados que permitem sincronizar o acesso a dados compartilhados de vários threads. Essas estruturas de dados são úteis quando você tem dados compartilhados que são modificados com pouca frequência. Um objeto de sincronização, por exemplo, uma seção crítica, faz com que outros threads aguardem até que o recurso compartilhado esteja disponível. Portanto, se você usar esse objeto para sincronizar o acesso aos dados que são usados com frequência, poderá perder a escalabilidade em seu aplicativo. A [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) fornece a classe [Concurrency:: combinável](../../parallel/concrt/reference/combinable-class.md) , que permite compartilhar um recurso entre vários threads ou tarefas sem a necessidade de sincronização. Para obter mais informações sobre a `combinable` classe, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="sections"></a><a name="top"></a>As

Este tópico descreve os seguintes tipos de bloco de mensagens assíncronas em detalhes:

- [critical_section](#critical_section)

- [reader_writer_lock](#reader_writer_lock)

- [scoped_lock e scoped_lock_read](#scoped_lock)

- [event](#event)

## <a name="critical_section"></a><a name="critical_section"></a>critical_section

A classe [Concurrency:: critical_section](../../parallel/concrt/reference/critical-section-class.md) representa um objeto de exclusão mútua cooperativa que produz a outras tarefas em vez de preempção delas. As seções críticas são úteis quando vários threads exigem acesso exclusivo de leitura e gravação a dados compartilhados.

A `critical_section` classe é não reentrante. O método [Concurrency:: critical_section:: Lock](reference/critical-section-class.md#lock) gera uma exceção do tipo [concurrency:: improper_lock](../../parallel/concrt/reference/improper-lock-class.md) se ele for chamado pelo thread que já possui o bloqueio.

### <a name="methods-and-features"></a>Métodos e recursos

A tabela a seguir mostra os métodos importantes que são definidos pela `critical_section` classe.

|Método|Descrição|
|------------|-----------------|
|[proprietário](reference/critical-section-class.md#lock)|Adquire a seção crítica. O contexto de chamada é bloqueado até que ele adquira o bloqueio.|
|[try_lock](reference/critical-section-class.md#try_lock)|Tenta adquirir a seção crítica, mas não bloqueia.|
|[automático](reference/critical-section-class.md#unlock)|Libera a seção crítica.|

[[Superior](#top)]

## <a name="reader_writer_lock"></a><a name="reader_writer_lock"></a>reader_writer_lock

A classe [Concurrency:: reader_writer_lock](../../parallel/concrt/reference/reader-writer-lock-class.md) fornece operações de leitura/gravação com segurança de thread para dados compartilhados. Use bloqueios de leitor/gravador quando vários threads exigem acesso de leitura simultâneo a um recurso compartilhado, mas raramente gravam nesse recurso compartilhado. Essa classe fornece apenas um acesso de gravação de thread a um objeto a qualquer momento.

A `reader_writer_lock` classe pode ter um desempenho melhor do que a `critical_section` classe porque um `critical_section` objeto adquire acesso exclusivo a um recurso compartilhado, o que impede o acesso de leitura simultâneo.

Assim como a `critical_section` classe, a `reader_writer_lock` classe representa um objeto de exclusão mútua cooperativa que produz a outras tarefas em vez de preempção delas.

Quando um thread que deve gravar em um recurso compartilhado adquire um bloqueio de leitor/gravador, outros threads que também devem acessar o recurso são bloqueados até que o gravador libere o bloqueio. A `reader_writer_lock` classe é um exemplo de um bloqueio de *preferência de gravação* , que é um bloqueio que desbloqueia os gravadores de espera antes de desbloquear os leitores em espera.

Assim como a `critical_section` classe, a `reader_writer_lock` classe é não reentrante. Os métodos [Concurrency:: reader_writer_lock:: Lock](reference/reader-writer-lock-class.md#lock) e [concurrency:: reader_writer_lock:: lock_read](reference/reader-writer-lock-class.md#lock_read) geram uma exceção do tipo `improper_lock` se eles são chamados por um thread que já possui o bloqueio.

> [!NOTE]
> Como a `reader_writer_lock` classe não é reentrante, não é possível atualizar um bloqueio somente leitura para um bloqueio de leitor/gravador ou fazer downgrade de um bloqueio de leitor/gravador para um bloqueio somente leitura. A execução de qualquer uma dessas operações produz um comportamento não especificado.

### <a name="methods-and-features"></a>Métodos e recursos

A tabela a seguir mostra os métodos importantes que são definidos pela `reader_writer_lock` classe.

|Método|Descrição|
|------------|-----------------|
|[proprietário](reference/reader-writer-lock-class.md#lock)|Adquire acesso de leitura/gravação ao bloqueio.|
|[try_lock](reference/reader-writer-lock-class.md#try_lock)|Tenta adquirir acesso de leitura/gravação ao bloqueio, mas não bloqueia.|
|[lock_read](reference/reader-writer-lock-class.md#lock_read)|Adquire acesso somente leitura ao bloqueio.|
|[try_lock_read](reference/reader-writer-lock-class.md#try_lock_read)|Tenta adquirir acesso somente leitura para o bloqueio, mas não bloqueia.|
|[automático](reference/reader-writer-lock-class.md#unlock)|Libera o bloqueio.|

[[Superior](#top)]

## <a name="scoped_lock-and-scoped_lock_read"></a><a name="scoped_lock"></a>scoped_lock e scoped_lock_read

As `critical_section` `reader_writer_lock` classes e fornecem classes auxiliares aninhadas que simplificam a maneira como você trabalha com objetos de exclusão mútua. Essas classes auxiliares são conhecidas como *bloqueios com escopo*.

A `critical_section` classe contém a classe [Concurrency:: critical_section:: scoped_lock](reference/critical-section-class.md#critical_section__scoped_lock_class) . O construtor adquire o acesso ao objeto fornecido `critical_section` ; o destruidor libera o acesso a esse objeto. A `reader_writer_lock` classe contém a classe [Concurrency:: reader_writer_lock:: scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class) , que se assemelha `critical_section::scoped_lock` , exceto que gerencia o acesso de gravação ao `reader_writer_lock` objeto fornecido. A `reader_writer_lock` classe também contém a classe [Concurrency:: reader_writer_lock:: scoped_lock_read](reference/reader-writer-lock-class.md#scoped_lock_read_class) . Essa classe gerencia o acesso de leitura ao `reader_writer_lock` objeto fornecido.

Os bloqueios com escopo fornecem vários benefícios quando você está trabalhando com `critical_section` `reader_writer_lock` objetos e manualmente. Normalmente, você aloca um bloqueio com escopo na pilha. Um bloqueio com escopo libera o acesso ao seu objeto de exclusão mútua automaticamente quando ele é destruído; Portanto, você não desbloqueia manualmente o objeto subjacente. Isso é útil quando uma função contém várias **`return`** instruções. Bloqueios com escopo também podem ajudá-lo a escrever código de exceção segura. Quando uma **`throw`** instrução faz com que a pilha fique desenrolada, o destruidor para qualquer bloqueio de escopo ativo é chamado e, portanto, o objeto de exclusão mútua é sempre liberado corretamente.

> [!NOTE]
> Quando você usa as `critical_section::scoped_lock` `reader_writer_lock::scoped_lock` classes,, e `reader_writer_lock::scoped_lock_read` não libera manualmente o acesso ao objeto de exclusão mútua subjacente. Isso pode colocar o tempo de execução em um estado inválido.

## <a name="event"></a>Evento <a name="event"></a>

A classe [Concurrency:: evento](../../parallel/concrt/reference/event-class.md) representa um objeto de sincronização cujo estado pode ser sinalizado ou não sinalizado. Ao contrário dos objetos de sincronização, como seções críticas, cuja finalidade é proteger o acesso a dados compartilhados, os eventos sincronizam o fluxo de execução.

A `event` classe é útil quando uma tarefa tiver concluído o trabalho para outra tarefa. Por exemplo, uma tarefa pode sinalizar outra tarefa que tem dados de leitura de uma conexão de rede ou de um arquivo.

### <a name="methods-and-features"></a>Métodos e recursos

A tabela a seguir mostra vários dos métodos importantes que são definidos pela `event` classe.

|Método|Descrição|
|------------|-----------------|
|[esperado](reference/event-class.md#wait)|Aguarda até que o evento se torne sinalizado.|
|[set](reference/event-class.md#set)|Define o evento para o estado sinalizado.|
|[reset](reference/event-class.md#reset)|Define o evento para o estado não sinalizado.|
|[wait_for_multiple](reference/event-class.md#wait_for_multiple)|Aguarda que vários eventos sejam sinalizados.|

### <a name="example"></a>Exemplo

Para obter um exemplo que mostra como usar a `event` classe, consulte comparando as [estruturas de dados de sincronização com a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md).

[[Superior](#top)]

## <a name="related-sections"></a>Seções relacionadas

[Comparando estruturas de dados de sincronização com a API do Windows](../../parallel/concrt/comparing-synchronization-data-structures-to-the-windows-api.md)<br/>
Compara o comportamento das estruturas de dados de sincronização com as fornecidas pela API do Windows.

[Runtime de Simultaneidade](../../parallel/concrt/concurrency-runtime.md)<br/>
Descreve o Tempo de Execução de Simultaneidade, que simplifica a programação paralela e contém links para tópicos relacionados.
