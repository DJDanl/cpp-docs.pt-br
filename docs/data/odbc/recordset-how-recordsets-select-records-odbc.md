---
title: 'Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)'
ms.date: 05/09/2019
helpviewer_keywords:
- recordsets, selecting records
- record selection, ODBC recordsets
- SQL statements, recordset
- records, selecting
- recordsets, constructing SQL statements
- ODBC recordsets, selecting records
ms.assetid: 343a6a91-aa4c-4ef7-b21f-2f2bfd0d3787
ms.openlocfilehash: 4b446d69651cb3cf52bd6c15899d85ed76b319da
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079806"
---
# <a name="recordset-how-recordsets-select-records-odbc"></a>Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Sua função e suas opções na seleção de registros](#_core_your_options_in_selecting_records).

- [Como um conjunto de registros constrói sua instrução SQL e seleciona registros](#_core_how_a_recordset_constructs_its_sql_statement).

- [O que você pode fazer para personalizar a seleção](#_core_customizing_the_selection).

Os conjuntos de registros selecionam registros de uma fonte de dados por meio de um driver ODBC enviando de instruções SQL para o driver. O SQL enviado depende de como você cria e abre sua classe de conjunto de registros.

##  <a name="your-options-in-selecting-records"></a><a name="_core_your_options_in_selecting_records"></a> Suas opções na seleção de registros

A tabela a seguir mostra suas opções na seleção de registros.

### <a name="how-and-when-you-can-affect-a-recordset"></a>Como e quando você pode afetar um conjunto de registros

|Quando você|É possível|
|--------------|-------------|
|Declara sua classe de conjunto de registros com o assistente **Adicionar Classe**|Especificar de qual tabela selecionar.<br /><br /> Especificar quais colunas incluir.<br /><br /> Confira [Como adicionar um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).|
|Conclui a implementação da sua classe de conjunto de registros|Substituir funções de membro como `OnSetOptions` (Avançado) para definir opções específicas do aplicativo ou para alterar os padrões. Especifique membros de dados de parâmetro se você desejar ter um conjunto de registros parametrizado.|
|Constrói um objeto de conjunto de registros (antes de chamar `Open`)|Especificar uma condição de pesquisa (possivelmente composta) para uso em uma cláusula **WHERE** que filtra os registros. Consulte [Recordset: Filtering Records (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).<br /><br /> Especificar uma ordem de classificação para uso em uma cláusula **ORDER BY** que classifica os registros. Consulte [conjunto de registros: classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md).<br /><br /> Especificar valores de parâmetro para quaisquer parâmetros que você adicionou à classe. Confira [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).|

|Executa a consulta do conjunto de registros chamando `Open`| Especificar uma cadeia de caracteres SQL personalizada para substituir a cadeia de caracteres SQL padrão configurada pelo assistente. Consulte [CRecordset:: Open](../../mfc/reference/crecordset-class.md#open) na *referência da biblioteca de classes* e [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md). |

|Chama `Requery` para repetir a consulta do conjunto de registros com os valores mais recentes na fonte de dados|Especificar novos parâmetro, filtrar ou classificar. Consulte [conjunto de registros: reconsultando um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md). |

##  <a name="how-a-recordset-constructs-its-sql-statement"></a><a name="_core_how_a_recordset_constructs_its_sql_statement"></a> Como um conjunto de registros constrói sua instrução SQL

Quando você chama a função de membro [Open](../../mfc/reference/crecordset-class.md#open) de um objeto de conjunto de registros, o `Open` constrói uma instrução SQL usando alguns dos seguintes ingredientes ou todos eles:

- O parâmetro *lpszSQL* passado para `Open`. Se não for NULL, este parâmetro especificará uma cadeia de caracteres SQL personalizada ou parte de uma. A estrutura analisa a cadeia de caracteres. Se a cadeia de caracteres é uma instrução **SELECT** SQL ou uma instrução **CALL** ODBC, a estrutura usa a cadeia de caracteres como a instrução SQL do conjunto de registros. Se a cadeia de caracteres não começa com “SELECT” ou "{CALL", a estrutura usa o que é fornecido para construir uma cláusula **FROM** do SQL.

- A cadeia de caracteres retornada por [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql). Por padrão, esse é o nome da tabela especificada para o conjunto de registros no assistente, mas é possível alterar o que a função retorna. A estrutura chama `GetDefaultSQL` – se a cadeia de caracteres não começa com "SELECT" ou com "{CALL", pressupõe-se que ela seja um nome de tabela, usado para construir uma cadeia de caracteres SQL.

- Os membros de dados de campo do conjunto de registros, que estão associados a colunas específicas da tabela. A estrutura associa colunas de registro aos endereços desses membros, usando-os como buffers. A estrutura determina a correlação de membros de dados de campo com colunas de tabela das chamadas de função [RFX](../../data/odbc/record-field-exchange-using-rfx.md) ou RFX em massa na função de membro [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) do conjunto de registros.

- O [filtro](../../data/odbc/recordset-filtering-records-odbc.md) do conjunto de registros, se houver, contido no membro de dados [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter). A estrutura usa a cadeia de caracteres para construir uma cláusula **WHERE** do SQL.

- A ordem de [classificação](../../data/odbc/recordset-sorting-records-odbc.md) do conjunto de registros, se houver, contida no membro de dados [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort). A estrutura usa essa cadeia de caracteres para construir uma cláusula **ORDER BY** SQL.

   > [!TIP]
   > Para usar a cláusula **GROUP BY** SQL (e, possivelmente, a cláusula **HAVING**), acrescente as cláusulas ao final de sua cadeia de caracteres de filtro.

- Os valores de quaisquer [membros de dados de parâmetro](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) que você especifica para a classe. Defina valores de parâmetro logo antes de chamar `Open` ou `Requery`. A estrutura associa os valores de parâmetro aos espaços reservados “?” na cadeia de caracteres SQL. Em tempo de compilação, especifique a cadeia de caracteres com espaços reservados. Em tempo de compilação, a estrutura preenche os detalhes com base nos valores de parâmetro passados.

`Open` constrói uma instrução **SELECT** do SQL com base nesses ingredientes. Confira [Como personalizar a seleção](#_core_customizing_the_selection) para obter detalhes sobre como a estrutura usa os ingredientes.

Após a construção da instrução, `Open` enviará o SQL para o Gerenciador e Driver ODBC (e a Biblioteca de Cursores ODBC se estiver na memória), que o envia para o driver ODBC para o DBMS específico. O driver se comunica com o DBMS para executar a seleção na fonte de dados e efetua fetch do primeiro. A estrutura carrega o registro para os membros de dados de campo do conjunto de registros.

É possível usar uma combinação dessas técnicas para abrir [tabelas](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md) e para construir uma consulta com base em uma [junção](../../data/odbc/recordset-performing-a-join-odbc.md) de várias tabelas. Com a personalização adicional, é possível chamar [consultas predefinidas](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md) (procedimentos armazenados), selecionar colunas de tabela não conhecidas em tempo de design e [associá](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)-las aos campos de conjunto de registros ou é possível realizar a maioria das outras tarefas de acesso a dados. As tarefas que você não pode realizar personalizando conjuntos de registros ainda podem ser efetuadas [chamando funções de API ODBC](../../data/odbc/odbc-calling-odbc-api-functions-directly.md) ou executando diretamente instruções SQL com [CDatabase::ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql).

##  <a name="customizing-the-selection"></a><a name="_core_customizing_the_selection"></a> Como personalizar a seleção

Além de fornecer um filtro, uma ordem de classificação ou parâmetros, é possível usar as seguintes ações para personalizar a seleção do seu conjunto de registros:

- Passe uma cadeia de caracteres SQL personalizada em *lpszSQL* quando você chama [Open](../../mfc/reference/crecordset-class.md#open) para o conjunto de registros. Qualquer coisa que você passa em *lpsqSQL* tem precedência sobre o que a função de membro [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql) retorna.

   Para obter mais informações, consulte [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md), que descreve os tipos de instruções SQL (ou instruções parciais) que você pode passar para `Open` e o que a estrutura faz com elas.

    > [!NOTE]
    >  Se a cadeia de caracteres personalizada passada não começa com "SELECT" ou "{CALL", o MFC pressupõe que ela contém um nome de tabela. Isso também se aplica ao próximo item com marcadores.

- Altere a cadeia de caracteres que o assistente escreve em sua função de membro `GetDefaultSQL` do conjunto de registros. Edite o código da função para alterar o que ela retorna. Por padrão, o assistente escreve uma função `GetDefaultSQL` que retorna um nome de tabela único.

   É possível fazer `GetDefaultSQL` retornar um dos itens que você pode passar no parâmetro *lpszSQL* para `Open`. Se você não passa uma cadeia de caracteres SQL personalizada em *lpszSQL*, a estrutura usa a cadeia de caracteres que `GetDefaultSQL` retorna. No mínimo, `GetDefaultSQL` deve retornar um nome de tabela único. Mas é possível fazer com que ele retorne vários nomes de tabela, uma instrução **SELECT** completa, uma instrução **CALL** ODBC e assim por diante. Para obter uma lista do que você pode passar para *lpszSQL* — ou ter `GetDefaultSQL` retornar — consulte [SQL: Personalizando a instrução SQL do conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

   Se você estiver executando uma junção de duas ou mais tabelas, reescreva `GetDefaultSQL` para personalizar a lista de tabelas usada na cláusula **FROM** SQL. Para obter mais informações, consulte [conjunto de registros: executando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).

- Associe membros de dados de campo adicionais manualmente, talvez com base nas informações que você obtém sobre o esquema de sua fonte de dados em tempo de execução. Adicione membros de dados de campo à classe de conjunto de registros ou às chamadas de função [RFX](../../data/odbc/record-field-exchange-using-rfx.md) ou RFX em massa para eles para a função de membro [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) e as inicializações de membros de dados na classe do construtor. Para obter mais informações, consulte [conjunto de registros: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

- Substitua funções de membro do conjunto de registros, como `OnSetOptions`, para definir opções específicas do aplicativo ou para substituir padrões.

Se deseja basear o conjunto de registros em uma instrução SQL complexa, é necessário usar um pouco da combinação dessas técnicas de personalização. Por exemplo, talvez convenha usar cláusula e palavras-chave SQL sem o suporte direto de conjuntos de registros ou talvez você esteja unindo várias tabelas.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)<br/>
[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)<br/>
[SQL](../../data/odbc/sql.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)