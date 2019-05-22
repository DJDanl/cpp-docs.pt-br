---
title: Conjunto de registros (ODBC)
ms.date: 05/09/2019
helpviewer_keywords:
- recordsets, snapshots
- recordsets, creating
- dynamic recordsets
- forward-only recordsets
- recordsets, dynasets
- ODBC recordsets, CRecordset objects
- ODBC recordsets
- recordsets, about recordsets
- snapshots, ODBC recordsets
- dynasets
ms.assetid: 333337c5-575e-4d26-b5f6-47166ad7874d
ms.openlocfilehash: b043b08e13611b87bbffbe9dfb3255d5520e3359
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707830"
---
# <a name="recordset-odbc"></a>Conjunto de registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Um objeto [CRecordset](../../mfc/reference/crecordset-class.md) representa um conjunto de registros selecionados de uma fonte de dados. Os registros podem ser de:

- Uma tabela.

- Uma consulta.

- Um procedimento armazenado que acessa uma ou mais tabelas.

Um exemplo de um conjunto de registros baseado em uma tabela é “todos os clientes,” que acessa uma tabela Cliente. Um exemplo de uma consulta é “todas as faturas para Joe Smith.” Um exemplo de um conjunto de registros baseado em um procedimento armazenado (às vezes chamado de uma consulta predefinida) é “todas as contas inadimplentes,” que invoca um procedimento armazenado no banco de dados de back-end. Um conjunto de registros pode juntar duas ou mais tabelas da mesma fonte de dados, mas não tabelas de diferentes fontes de dados.

> [!NOTE]
>  Alguns drivers ODBC dão suporte a exibições do banco de dados. Nesse sentido, uma exibição é uma consulta originalmente criada com a instrução `CREATE VIEW` SQL.

##  <a name="_core_recordset_capabilities"></a> Funcionalidades do conjunto de registros

Todos os objetos do conjunto de registros compartilham as seguintes funcionalidades:

- Se a fonte de dados não for somente leitura, será possível especificar que seu conjunto de registros seja [atualizável](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md), [acrescentável](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md) ou somente leitura. Se o conjunto de registros for atualizável, você poderá escolher métodos de [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) pessimistas ou otimistas, desde que o driver forneça o suporte de bloqueio apropriado. Se a fonte de dados for somente leitura, o conjunto de registros será somente leitura.

- É possível chamar as funções de membro para [rolar](../../data/odbc/recordset-scrolling-odbc.md) até os registros selecionados.

- É possível [filtrar](../../data/odbc/recordset-filtering-records-odbc.md) os registros para restringir quais deles são selecionados dos que estão disponíveis.

- É possível [classificar](../../data/odbc/recordset-sorting-records-odbc.md) os registros em ordem crescente ou decrescente, com base em uma ou mais colunas.

- É possível [parametrizar](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) o conjunto de registros para qualificar a seleção do conjunto de registros em tempo de execução.

##  <a name="_core_snapshots_and_dynasets"></a> Instantâneos e Dynasets

Há dois tipos de entidade de segurança de conjuntos de registros: [instantâneos](../../data/odbc/snapshot.md) e [dynasets](../../data/odbc/dynaset.md). A classe `CRecordset` é compatível com ambos. Cada um compartilha as características comuns de todos os conjuntos de registros, mas cada um também estende a funcionalidade comum de sua própria maneira especializada. Instantâneos fornecem uma exibição estática dos dados e são úteis para relatórios e outras situações em que você deseja ter uma exibição dos dados como eles existiam em um momento específico. Dynasets são úteis quando você deseja que as atualizações feitas por outros usuários fiquem visíveis no conjunto de registros sem ter que repetir a consulta ou atualizar o conjunto de registros. Instantâneos e dynasets podem ser atualizáveis ou somente leitura. Para refletir os registros adicionados ou excluídos por outros usuários, chame [CRecordset::Requery](../../mfc/reference/crecordset-class.md#requery).

`CRecordset` também permite dois outros tipos de conjuntos de registros: conjuntos de registros dinâmicos e conjuntos de registros de somente encaminhamento. Os conjuntos de registros dinâmicos são semelhantes aos dynasets; no entanto, os conjuntos de registros dinâmicos refletem quaisquer registros adicionados ou excluídos sem chamar `CRecordset::Requery`. Por esse motivo, conjuntos de registros dinâmicos geralmente são caros em relação ao tempo de processamento no DBMS e muitos drivers ODBC não dão suporte a eles. Em contraste, conjuntos de registros de somente encaminhamento fornecem o método de acesso a dados mais eficiente para conjuntos de registros que não exigem atualizações nem rolagem regressiva. Por exemplo, você poderia usar um conjunto de registros de somente encaminhamento para migrar dados de uma fonte de dados para outra, em que só é necessário percorrer os dados em uma direção progressiva. Para usar um conjunto de registros de somente encaminhamento, é necessário fazer o seguinte:

- Passe a opção `CRecordset::forwardOnly` como o parâmetro *nOpenType* da função de membro [Open](../../mfc/reference/crecordset-class.md#open).

- Especifique `CRecordset::readOnly` no parâmetro *dwOptions* do `Open`.

    > [!NOTE]
    >  Para saber mais sobre requisitos de driver ODBC para suporte a dynaset, confira [ODBC](../../data/odbc/odbc-basics.md). Para ver uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para saber como obter outros drivers, confira [Lista de Drivers ODBC](../../data/odbc/odbc-driver-list.md).

##  <a name="_core_your_recordsets"></a> Seus conjuntos de registros

Para cada tabela, exibição ou procedimento armazenado distinto que você deseja acessar, você normalmente define uma classe derivada de `CRecordset`. (A exceção é uma junção de banco de dados, na qual um conjunto de registros representa colunas de duas ou mais tabelas.) Ao derivar uma classe de conjunto de registros, você habilita o mecanismo RFX (troca de campo de registro) ou o mecanismo RFX em massa, que são semelhantes ao mecanismo DDX (troca de dados de diálogo). RFX e RFX em massa simplificam a transferência de dados da fonte de dados para seu conjunto de registros; além disso, a RFX transfere dados do seu conjunto de registros para a fonte de dados. Para saber mais, confira [RFX (Troca de Campo de Registro)](../../data/odbc/record-field-exchange-rfx.md) e [Conjunto de registros: como efetuar fetch de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Um objeto de conjunto de registros fornece acesso a todos os registros selecionados. Role até os vários registros selecionados usando as funções de membro `CRecordset`, como `MoveNext` e `MovePrev`. Ao mesmo tempo, um objeto de conjunto de registros representa apenas um dos registros selecionados, o registro atual. É possível examinar os campos do registro atual declarando as variáveis de membro de classe do conjunto de registros que correspondem a colunas da tabela ou dos registros resultantes da consulta de banco de dados. Para saber mais sobre membros de dados de conjunto de registros, confira [Conjunto de registros: arquitetura (ODBC)](../../data/odbc/recordset-architecture-odbc.md).

Os tópicos a seguir explicam os detalhes de como usar os objetos do conjunto de registros. Os tópicos estão listados em categorias funcionais e em uma ordem de procura natural a fim de permitir leitura sequencial.

### <a name="topics-about-the-mechanics-of-opening-reading-and-closing-recordsets"></a>Tópicos sobre a mecânica de abertura, leitura e fechamento de conjuntos de registros

- [Conjunto de registros: arquitetura (ODBC)](../../data/odbc/recordset-architecture-odbc.md)

- [Conjunto de registros: declarar uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)

- [Conjunto de registros: criar e fechar conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)

- [Conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md)

- [Conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md)

- [Conjunto de registros: filtrar registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)

- [Conjunto de registros: classificar registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md)

- [Conjunto de registros: parametrizar um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)

### <a name="topics-about-the-mechanics-of-modifying-recordsets"></a>Tópicos sobre a mecânica de modificação de conjuntos de registros

- [Conjunto de registros: adicionar, atualizar e excluir registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)

- [Conjunto de registros: bloquear registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)

- [Conjunto de registros: repetir consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)

### <a name="topics-about-somewhat-more-advanced-techniques"></a>Tópicos sobre técnicas um pouco mais avançadas

- [Conjunto de registros: realizar uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)

- [Conjunto de registros: declarar uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md)

- [Conjunto de registros: associar dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)

- [Conjunto de registros: buscar registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md)

- [Conjunto de registros: trabalhar com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)

- [Conjunto de registros: obter SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)

### <a name="topics-about-how-recordsets-work"></a>Tópicos sobre como os conjuntos de registros funcionam

- [Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)

- [Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Transação (ODBC)](../../data/odbc/transaction-odbc.md)