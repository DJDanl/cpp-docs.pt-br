---
title: Modelo de objeto do banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- rowsets, OLE DB object model
- OLE DB, object model
ms.assetid: 1a274a25-c310-4430-a1ec-bd2bd8120eff
ms.openlocfilehash: 303ad4166f0f1126182956fae9c19f513be7cfb3
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59039145"
---
# <a name="ole-db-object-model"></a>Modelo de objeto do banco de dados OLE

O modelo de objeto do OLE DB é feito dos seguintes objetos ou componentes. A primeira quatro objetos ou componentes listados (fontes de dados, sessões, comandos e conjuntos de linhas) permitem que você se conectar a uma fonte de dados e exibi-lo. O restante, começando com acessadores, estão relacionadas a trabalhar com os dados quando ele for exibido.

## <a name="data-sources"></a>Data Sources

Objetos de fonte de dados permitem que você se conectar a uma fonte de dados como um arquivo ou DBMS. Um objeto de fonte de dados cria e gerencia a conexão e contém informações de permissões e autenticações (por exemplo, nome de logon e senha). Um objeto de fonte de dados pode criar uma ou mais sessões.

## <a name="sessions"></a>Sessões

Uma sessão gerencia uma interação específica com a fonte de dados para consultar e recuperar dados. Cada sessão é uma única transação. Uma transação é uma unidade indivisível de trabalho definida pelo teste de ACID. Para uma definição de ACID, consulte [transações](#vcconoledbcomponents_transactions).

Sessões de realizar tarefas importantes como abrindo conjuntos de linhas e retornar o objeto de fonte de dados que o criou. Sessões também podem retornar metadados ou informações sobre a fonte de dados (como informações de tabela).

Uma sessão pode criar um ou mais comandos.

## <a name="commands"></a>Comandos

Comandos de executar um comando de texto como uma instrução SQL. Se o comando de texto Especifica um conjunto de linhas, como um SQL **selecionar** instrução, o comando cria o conjunto de linhas.

Um comando é simplesmente um contêiner para um comando de texto, que é uma cadeia de caracteres (por exemplo, uma instrução SQL) passada de um consumidor para um objeto de fonte de dados para execução pelo armazenamento de dados do provedor subjacente. Normalmente, o comando de texto é um SQL **selecionar** instrução (nesse caso, como SQL **selecione** Especifica um conjunto de linhas, o comando cria automaticamente um conjunto de linhas).

## <a name="rowsets"></a>Conjuntos de linhas

Conjuntos de linhas de mostram dados em formato tabular. Um índice é um caso especial de um conjunto de linhas. Você pode criar conjuntos de linhas da sessão ou o comando.

### <a name="schema-rowsets"></a>Conjuntos de linhas do esquema

Esquemas têm metadados (informações estruturais) sobre um banco de dados. Conjuntos de linhas de esquema são conjuntos de linhas que têm informações de esquema. Alguns provedores OLE DB para o DBMS dão suporte a objetos de conjunto de linhas de esquema. Para obter mais informações sobre conjuntos de linhas de esquema, consulte [obtendo metadados com conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) e [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md).

### <a name="view-objects"></a>Objetos de exibição

Um objeto de exibição define um subconjunto de linhas e colunas de um conjunto de linhas. Ele não tem dados de seu próprio. Objetos de exibição não é possível combinar dados de vários conjuntos de linhas.

## <a name="accessors"></a>Acessadores

Somente OLE DB usa o conceito de acessadores. Um acessador descreve como os dados são armazenados em um consumidor. Ele tem um conjunto de associações (chamado de um mapa de coluna) entre os campos de conjunto de linhas (colunas) e membros de dados que você declare no consumidor.

##  <a name="vcconoledbcomponents_transactions"></a> Transações

Objetos de transação são usados quando a confirmação ou anulação de transações aninhadas em que não seja o nível mais baixo. Uma transação é uma unidade indivisível de trabalho definida pelo teste de ACID. ACID significa:

- Atomicidade, não podem ser divididos em unidades menores de trabalho

- Simultaneidade, mais de uma transação pode ocorrer por vez

- Isolamento, uma transação limitou os dados de Conhecimento sobre as alterações feitas por outro

- Durabilidade, a transação faz alterações persistentes

## <a name="enumerators"></a>Enumeradores

Enumeradores pesquisar fontes de dados disponíveis e outros enumeradores. Os consumidores que não são personalizados para uma determinada fonte de dados usam enumeradores para pesquisar uma fonte de dados para usar.

Um enumerador de raiz, fornecido no Microsoft Data Access SDK atravessa o registro procurando por fontes de dados e outros enumeradores. Outros enumeradores atravessam o registro ou a pesquisa de uma maneira específica do provedor.

## <a name="errors"></a>Erros

Qualquer interface em qualquer objeto do OLE DB pode gerar erros. Erros têm informações adicionais sobre o erro, incluindo um objeto de erro personalizada opcional. Essas informações são armazenadas em um HRESULT.

## <a name="notifications"></a>Notificações

As notificações são usadas por grupos de consumidores de cooperação compartilhando um conjunto de linhas (em que o compartilhamento significa que os consumidores devem estar trabalhando dentro da mesma transação). Notificações habilitar consumidores cooperação compartilhando um conjunto de linhas ser informado sobre as ações no conjunto de linhas executadas por seus colegas.

## <a name="see-also"></a>Consulte também

[Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação de banco de dados OLE](../../data/oledb/ole-db-programming-overview.md)