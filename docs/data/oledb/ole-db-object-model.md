---
title: Modelo de objeto do banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- rowsets, OLE DB object model
- OLE DB, object model
ms.assetid: 1a274a25-c310-4430-a1ec-bd2bd8120eff
ms.openlocfilehash: b37205eb91317c602010a4b568057845b2345ef0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369792"
---
# <a name="ole-db-object-model"></a>Modelo de objeto do banco de dados OLE

O modelo de objeto OLE DB é feito dos seguintes objetos ou componentes. Os quatro primeiros objetos ou componentes listados (fontes de dados, sessões, comandos e conjuntos de linhas) permitem que você se conecte a uma fonte de dados e visualize-a. O resto, começando com os acessórios, diz respeito ao trabalho com os dados quando são exibidos.

## <a name="data-sources"></a>Fontes de dados

Objetos de origem de dados permitem que você se conecte a uma fonte de dados, como um arquivo ou DBMS. Um objeto de origem de dados cria e gerencia a conexão e contém informações de permissões e autenticações (como nome de login e senha). Um objeto de origem de dados pode criar uma ou mais sessões.

## <a name="sessions"></a>Sessões

Uma sessão gerencia uma interação específica com a fonte de dados para consultar e recuperar dados. Cada sessão é uma única transação. Uma transação é uma unidade de trabalho indivisível definida pelo teste ACID. Para uma definição de ACID, consulte [Transações](#vcconoledbcomponents_transactions).

As sessões fazem tarefas importantes, como abrir conjuntos de linhas e retornar o objeto de origem de dados que o criou. As sessões também podem retornar metadados ou informações sobre a própria fonte de dados (como informações de tabela).

Uma sessão pode criar um ou mais comandos.

## <a name="commands"></a>Comandos

Os comandos executam um comando de texto, como uma declaração SQL. Se o comando de texto especificar um conjunto de linhas, como uma declaração SQL **SELECT,** o comando criará o conjunto de linhas.

Um comando é simplesmente um contêiner para um comando de texto, que é uma string (como uma declaração SQL) passada de um consumidor para um objeto de origem de dados para execução pelo armazenamento de dados subjacente do provedor. Normalmente, o comando de texto é uma declaração SQL **SELECT** (nesse caso, como o SQL **SELECT** especifica um conjunto de linhas, o comando cria automaticamente um conjunto de linhas).

## <a name="rowsets"></a>Conjuntos de linhas

Os conjuntos de linhas mostram dados em formato tabular. Um índice é um caso especial de um conjunto de linhas. Você pode criar conjuntos de linhas a partir da sessão ou do comando.

### <a name="schema-rowsets"></a>Conjuntos de linhas de esquema

Os schemas têm metadados (informações estruturais) sobre um banco de dados. Conjuntos de linhas de esquema são conjuntos de linhas que têm informações sobre esquemas. Alguns provedores OLE DB para objetos de esquema de esquema de suporte DoMBmS. Para obter mais informações sobre conjuntos de linhas de esquema, consulte [Obtenção de metadados com esquemas de linhas](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) e [classes de esquema e classes de tipodef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md).

### <a name="view-objects"></a>Exibir objetos

Um objeto de exibição define um subconjunto das linhas e colunas a partir de um conjunto de linhas. Não tem dados próprios. Os objetos de exibição não podem combinar dados de vários conjuntos de linhas.

## <a name="accessors"></a>Acessadores

Apenas o OLE DB usa o conceito de acessórios. Um acessório descreve como os dados são armazenados em um consumidor. Ele tem um conjunto de vinculações (chamado mapa de coluna) entre campos de conjunto de linhas (colunas) e membros de dados que você declara no consumidor.

## <a name="transactions"></a><a name="vcconoledbcomponents_transactions"></a>Transações

Os objetos de transação são usados ao cometer ou abortar transações aninhadas em outro nível inferior. Uma transação é uma unidade de trabalho indivisível definida pelo teste ACID. ÁCIDO significa:

- Atomicidade, não pode ser dividida em unidades de trabalho menores

- Simulta, mais de uma transação pode ocorrer de cada vez

- Isolamento, uma transação tem conhecimento limitado sobre mudanças feitas por outra

- Durabilidade, a transação faz mudanças persistentes

## <a name="enumerators"></a>Enumeradores

Enumeradores buscam fontes de dados disponíveis e outros enumeradores. Consumidores que não são personalizados para uma fonte de dados específica usam enumeradores para procurar uma fonte de dados para usar.

Um enumerador raiz, enviado no Microsoft Data Access SDK, atravessa o registro procurando fontes de dados e outros enumeradores. Outros enumeradores atravessam o registro ou pesquisa de forma específica do provedor.

## <a name="errors"></a>Errors

Qualquer interface em qualquer objeto OLE DB pode gerar erros. Os erros têm informações adicionais sobre um erro, incluindo um objeto de erro personalizado opcional. Essas informações são armazenadas em um HRESULT.

## <a name="notifications"></a>Notificações

As notificações são usadas por grupos de consumidores cooperantes compartilhando um conjunto de linhas (onde o compartilhamento significa que os consumidores estão trabalhando dentro da mesma transação). As notificações permitem que os consumidores que cooperam compartilhando um conjunto de linhas sejam informados sobre as ações no conjunto de linhas realizadas por seus pares.

## <a name="see-also"></a>Confira também

[Programação OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação de banco de dados OLE](../../data/oledb/ole-db-programming-overview.md)
