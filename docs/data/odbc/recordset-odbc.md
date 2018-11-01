---
title: Conjunto de registros (ODBC)
ms.date: 11/04/2016
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
ms.openlocfilehash: d16087722752b7bbdabd37410908c7ea2ae18ceb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50435250"
---
# <a name="recordset-odbc"></a>Conjunto de registros (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Um [CRecordset](../../mfc/reference/crecordset-class.md) objeto representa um conjunto de registros selecionados de uma fonte de dados. Os registros podem ser de:

- Uma tabela.

- Uma consulta.

- Um procedimento armazenado que acessa uma ou mais tabelas.

Um exemplo de um conjunto de registros com base em uma tabela é "todos os clientes", que acessa uma tabela de cliente. Um exemplo de uma consulta é "todas as faturas de Joe Smith." Um exemplo de um conjunto de registros com base em um procedimento armazenado (às vezes chamado de uma consulta predefinida) é "todas as contas inadimplente," que invoca um procedimento armazenado no banco de dados back-end. Um conjunto de registros pode unir duas ou mais tabelas da mesma fonte de dados, mas não as tabelas de diferentes fontes de dados.

> [!NOTE]
>  Para obter informações sobre como derivar classes de conjunto de registros com os assistentes, consulte [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) e [suporte de banco de dados, o Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md).

> [!NOTE]
>  Alguns drivers ODBC dão suporte a modos de exibição do banco de dados. Um modo de exibição nesse sentido é uma consulta criada originalmente com o SQL `CREATE VIEW` instrução. Os assistentes atualmente não dão suporte a modos de exibição, mas é possível codificar esse suporte por conta própria.

##  <a name="_core_recordset_capabilities"></a> Recursos do conjunto de registros

Todos os objetos de conjunto de registros compartilham os seguintes recursos:

- Se a fonte de dados não for somente leitura, você pode especificar que o seu conjunto de registros sejam [atualizável](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md), [appendable](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md), ou somente leitura. Se o conjunto de registros é atualizável, você pode escolher pessimista ou otimista [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) fornecidos de métodos, o driver fornece o suporte apropriado de bloqueio. Se a fonte de dados é somente leitura, o conjunto de registros será somente leitura.

- Você pode chamar funções membro [rolagem](../../data/odbc/recordset-scrolling-odbc.md) através dos registros selecionados.

- Você pode [filtro](../../data/odbc/recordset-filtering-records-odbc.md) os registros para restringir quais registros são selecionados dos que estão disponíveis.

- Você pode [classificação](../../data/odbc/recordset-sorting-records-odbc.md) os registros em ordem, crescente ou decrescente com base em uma ou mais colunas.

- Você pode [parametrizar](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) o conjunto de registros para qualificar a seleção de conjunto de registros em tempo de execução.

##  <a name="_core_snapshots_and_dynasets"></a> Instantâneos e Dynasets

Há dois tipos de entidade de segurança de conjuntos de registros: [instantâneos](../../data/odbc/snapshot.md) e [dynasets](../../data/odbc/dynaset.md). Ambos têm suporte pela classe `CRecordset`. Cada compartilha as características comuns de todos os conjuntos de registros, mas cada um também estende a funcionalidade comum em sua própria maneira especializada. Instantâneos fornecem uma exibição estática dos dados e são úteis para relatórios e outras situações, no qual você deseja uma exibição dos dados conforme se encontravam em um momento específico. Dynasets são úteis quando você deseja atualizações feitas por outros usuários fiquem visíveis no conjunto de registros sem ter que repetir a consulta ou atualizar o conjunto de registros. Instantâneos e dynasets pode ser atualizável ou somente leitura. Para refletir os registros adicionados ou excluídos por outros usuários, chamar [CRecordset::Requery](../../mfc/reference/crecordset-class.md#requery).

`CRecordset` também permite que dois outros tipos de conjuntos de registros: conjuntos de registros dinâmicos e conjuntos de registros somente de encaminhamento. Conjuntos de registros dinâmicos são semelhantes para dynasets; No entanto, os conjuntos de registros dinâmicos refletem todos os registros adicionados ou excluídos sem chamar `CRecordset::Requery`. Por esse motivo, conjuntos de registros dinâmicos são geralmente caros em relação ao tempo de processamento para o DBMS e muitos drivers ODBC não dão suporte a eles. Em contraste, conjuntos de registros somente encaminhamento fornecem o método mais eficiente de acesso a dados para conjuntos de registros que não exigem atualizações ou para trás. Por exemplo, você pode usar um conjunto de registros somente de encaminhamento para migrar dados de uma fonte de dados para outro, em que você só precisa percorrer os dados em uma direção progressiva. Para usar um conjunto de registros somente encaminhamento, você deve fazer o seguinte:

- Passe a opção `CRecordset::forwardOnly` como o *nOpenType* parâmetro do [abrir](../../mfc/reference/crecordset-class.md#open) função de membro.

- Especificar `CRecordset::readOnly` no *dwOptions* parâmetro do `Open`.

    > [!NOTE]
    >  Para obter informações sobre os requisitos de driver ODBC para o suporte de dynaset, consulte [ODBC](../../data/odbc/odbc-basics.md). Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C++ e para obter informações sobre como obter drivers adicionais, consulte [lista de drivers ODBC](../../data/odbc/odbc-driver-list.md).

##  <a name="_core_your_recordsets"></a> Conjuntos de registros

Para cada tabela distinta, exibição ou procedimento armazenado que você deseja acessar, você normalmente define uma classe derivada de `CRecordset`. (A exceção é uma junção de banco de dados, na qual um conjunto de registros representa colunas de duas ou mais tabelas.) Quando você derivar uma classe de conjunto de registros, você habilita o mecanismo do exchange (RFX) de campos de registro ou o mecanismo do exchange (RFX em massa) de campos de registro em massa, que são semelhantes para o mecanismo de troca (DDX) de dados de caixa de diálogo. RFX e RFX em massa simplificam a transferência de dados da fonte de dados em seu conjunto de registros; Além do RFX transfere dados de seu conjunto de registros para a fonte de dados. Para obter mais informações, consulte [RFX Record Field Exchange ()](../../data/odbc/record-field-exchange-rfx.md) e [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Um objeto recordset fornece acesso a todos os registros selecionados. Role por meio de vários registros selecionados usando `CRecordset` funções de membro, como `MoveNext` e `MovePrev`. Ao mesmo tempo, um objeto recordset representa apenas um dos registros selecionados, o registro atual. Você pode examinar os campos do registro atual ao declarar variáveis de membro de classe que correspondem às colunas da tabela ou os registros que resultam da consulta de banco de dados de conjunto de registros. Para obter informações sobre membros de dados do conjunto de registros, consulte [conjunto de registros: arquitetura (ODBC)](../../data/odbc/recordset-architecture-odbc.md).

Os tópicos a seguir explicam os detalhes de como usar objetos de conjunto de registros. Os tópicos estão listados nas categorias funcionais e uma ordem natural de procurar a fim de permitir leitura sequencial.

### <a name="topics-about-the-mechanics-of-opening-reading-and-closing-recordsets"></a>Tópicos sobre a mecânica de abrir, ler e fechando conjuntos de registros

- [Conjunto de registros: arquitetura (ODBC)](../../data/odbc/recordset-architecture-odbc.md)

- [Conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)

- [Conjunto de registros: criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)

- [Conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md)

- [Conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md)

- [Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)

- [Conjunto de registros: classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md)

- [Conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)

### <a name="topics-about-the-mechanics-of-modifying-recordsets"></a>Tópicos sobre a mecânica de como modificar conjuntos de registros

- [Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)

- [Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)

- [Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)

### <a name="topics-about-somewhat-more-advanced-techniques"></a>Tópicos sobre um pouco mais avançadas técnicas

- [Conjunto de registros: realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)

- [Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md)

- [Conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)

- [Conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md)

- [Conjunto de registros: trabalhando com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)

- [Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)

### <a name="topics-about-how-recordsets-work"></a>Tópicos sobre o funcionam dos conjuntos de registros

- [Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)

- [Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Transação (ODBC)](../../data/odbc/transaction-odbc.md)