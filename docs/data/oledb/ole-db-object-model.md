---
title: Modelo de objeto do banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- rowsets, OLE DB object model
- OLE DB, object model
ms.assetid: 1a274a25-c310-4430-a1ec-bd2bd8120eff
ms.openlocfilehash: 192195d02b034546e50b1cb860b1f11c47dc2b65
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210113"
---
# <a name="ole-db-object-model"></a>Modelo de objeto do banco de dados OLE

O modelo de objeto OLE DB é feito dos seguintes objetos ou componentes. Os primeiros quatro objetos ou componentes listados (fontes de dados, sessões, comandos e conjuntos de linhas) permitem que você se conecte a uma fonte de dados e exiba-os. O restante, começando com acessadores, está relacionado ao trabalho com os dados quando eles são exibidos.

## <a name="data-sources"></a>Fontes de dados

Os objetos de fonte de dados permitem que você se conecte a uma fonte de dados, como um arquivo ou DBMS. Um objeto de fonte de dados cria e gerencia a conexão e contém informações de permissões e autenticações (como nome de logon e senha). Um objeto de fonte de dados pode criar uma ou mais sessões.

## <a name="sessions"></a>Sessões

Uma sessão gerencia uma interação específica com a fonte de dados para consultar e recuperar dados. Cada sessão é uma única transação. Uma transação é uma unidade de trabalho indivisível definida pelo teste ACID. Para obter uma definição de ACID, consulte [Transações](#vcconoledbcomponents_transactions).

As sessões fazem tarefas importantes, como abrir conjuntos de linhas e retornar o objeto de fonte de dados que o criou. As sessões também podem retornar metadados ou informações sobre a própria fonte de dados (como informações de tabela).

Uma sessão pode criar um ou mais comandos.

## <a name="commands"></a>Comandos

Comandos executam um comando de texto como uma instrução SQL. Se o comando de texto especificar um conjunto de linhas, como uma instrução SQL **Select** , o comando criará o conjunto de linhas.

Um comando é simplesmente um contêiner para um comando de texto, que é uma cadeia de caracteres (como uma instrução SQL) passada de um consumidor para um objeto de fonte de dados para execução pelo armazenamento de dados subjacente do provedor. Normalmente, o comando de texto é uma instrução SQL **Select** (nesse caso, como SQL **Select** especifica um conjunto de linhas, o comando cria automaticamente um conjunto de linhas).

## <a name="rowsets"></a>Conjuntos de linhas

Conjuntos de linhas mostram dados no formato tabular. Um índice é um caso especial de um conjunto de linhas. Você pode criar conjuntos de linhas da sessão ou do comando.

### <a name="schema-rowsets"></a>Conjuntos de linhas de esquema

Esquemas têm metadados (informações estruturais) sobre um banco de dados. Conjuntos de linhas de esquema são conjuntos de linhas que têm informações de esquema. Alguns provedores de OLE DB para o DBMS oferecem suporte a objetos de conjunto de linhas de esquema. Para obter mais informações sobre conjuntos de linhas de esquema, consulte [obtendo metadados com conjuntos](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) de itens de esquema e [classes de conjunto de dados de esquema e classes de typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md).

### <a name="view-objects"></a>Exibir objetos

Um objeto View define um subconjunto das linhas e colunas de um conjunto de linhas. Ele não tem nenhum dado próprio. Os objetos de exibição não podem combinar dados de vários conjuntos de linhas.

## <a name="accessors"></a>Acessadores

Somente OLE DB usa o conceito de acessadores. Um acessador descreve como os dados são armazenados em um consumidor. Ele tem um conjunto de associações (chamado de mapa de coluna) entre campos de conjunto de linhas (colunas) e membros de dados que você declara no consumidor.

##  <a name="transactions"></a><a name="vcconoledbcomponents_transactions"></a> Transactions

Os objetos de transação são usados ao confirmar ou anular transações aninhadas em outros níveis mais baixos. Uma transação é uma unidade de trabalho indivisível definida pelo teste ACID. ACID significa:

- Atomicidade, não pode ser dividida em unidades de trabalho menores

- Simultaneidade, mais de uma transação pode ocorrer por vez

- Isolamento, uma transação tem conhecimento limitado sobre as alterações feitas por outra

- Durabilidade, a transação faz alterações persistentes

## <a name="enumerators"></a>Enumeradores

Os enumeradores pesquisam fontes de dados disponíveis e outros enumeradores. Os consumidores que não são personalizados para uma determinada fonte de dados usam enumeradores para procurar uma fonte de dados a ser usada.

Um enumerador raiz, fornecido no SDK do Microsoft Data Access, atravessa o registro procurando fontes de dados e outros enumeradores. Outros enumeradores atravessam o registro ou pesquisam de maneira específica do provedor.

## <a name="errors"></a>Errors

Qualquer interface em qualquer objeto de OLE DB pode gerar erros. Os erros têm informações adicionais sobre um erro, incluindo um objeto de erro personalizado opcional. Essas informações são armazenadas em um HRESULT.

## <a name="notifications"></a>Notificações

As notificações são usadas por grupos de consumidores cooperativos que compartilham um conjunto de linhas (em que o compartilhamento significa que os consumidores devem estar trabalhando na mesma transação). As notificações permitem que os consumidores de cooperação compartilhem um conjunto de linhas para serem informados sobre ações no conjunto de linhas executado por seus colegas.

## <a name="see-also"></a>Confira também

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)
