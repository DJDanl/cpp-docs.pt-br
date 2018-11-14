---
title: 'Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- recordsets, selecting records
- record selection, ODBC recordsets
- SQL statements, recordset
- records, selecting
- recordsets, constructing SQL statements
- ODBC recordsets, selecting records
ms.assetid: 343a6a91-aa4c-4ef7-b21f-2f2bfd0d3787
ms.openlocfilehash: 7e7bbaad949b5f4456ce4c8aea60099792deb786
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51329457"
---
# <a name="recordset-how-recordsets-select-records-odbc"></a>Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Este tópico explica:

- [Sua função e suas opções na seleção de registros](#_core_your_options_in_selecting_records).

- [Como um conjunto de registros constrói sua instrução SQL e seleciona os registros](#_core_how_a_recordset_constructs_its_sql_statement).

- [O que você pode fazer para personalizar a seleção](#_core_customizing_the_selection).

Conjuntos de registros selecionam registros da fonte de dados por meio de um driver ODBC por meio do envio de instruções SQL para o driver. O SQL enviado depende de como projetar e abra sua classe de conjunto de registros.

##  <a name="_core_your_options_in_selecting_records"></a> As opções na seleção de registros

A tabela a seguir mostra as opções disponíveis na seleção de registros.

### <a name="how-and-when-you-can-affect-a-recordset"></a>Como e quando você pode afetar um conjunto de registros

|Quando você|É possível|
|--------------|-------------|
|Declarar sua classe de conjunto de registros com o **Adicionar classe** Assistente|Especifica qual tabela selecionem.<br /><br /> Especifique quais colunas deseja incluir.<br /><br /> Ver [adicionando um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).|
|Conclua sua implementação de classe do conjunto de registros|Substituir funções de membro, como `OnSetOptions` (Avançado) para definir opções específicas do aplicativo ou para alterar os padrões. Se você quiser que um conjunto de registros com parâmetros, especifique os membros de dados do parâmetro.|
|Construir um objeto de conjunto de registros (antes de chamar `Open`)|Especificar um critério de pesquisa (possivelmente composto) para uso em um **onde** cláusula que filtra os registros. Ver [conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).<br /><br /> Especificar uma ordem de classificação para uso em um **ORDER BY** cláusula que classifica os registros. Ver [conjunto de registros: Classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md).<br /><br /> Especifica valores de parâmetro para quaisquer parâmetros que você adicionou à classe. Ver [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).|

| Execute a consulta do conjunto de registros chamando `Open`| Especifique uma cadeia de caracteres SQL personalizada para substituir a cadeia de caracteres do padrão SQL configurada pelo assistente. Ver [{1&gt;crecordset::Open&lt;1](../../mfc/reference/crecordset-class.md#open) na *referência de biblioteca de classes* e [SQL: Personalizando a instrução de SQL do seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md). |

| Chamar `Requery` para repetir a consulta de conjunto de registros com os valores mais recentes na fonte de dados | Especifique novos parâmetros, filtrar ou classificar. Ver [conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md). |

##  <a name="_core_how_a_recordset_constructs_its_sql_statement"></a> Como um conjunto de registros constrói sua instrução SQL

Quando você chama um objeto de conjunto de registros [aberto](../../mfc/reference/crecordset-class.md#open) função de membro, `Open` constrói uma instrução SQL usando alguns ou todos os componentes a seguir:

- O *lpszSQL* parâmetro passado para `Open`. Se não for NULL, esse parâmetro especifica uma cadeia de caracteres SQL personalizada ou parte de um. O framework analisa a cadeia de caracteres. Se a cadeia de caracteres for um SQL **selecionar** instrução ou um ODBC **chamar** instrução, a estrutura usa a cadeia de caracteres como instrução de SQL do conjunto de registros. Se a cadeia de caracteres começa com "SELECT" ou "{CALL", a estrutura usa o que é fornecido para construir um SQL **FROM** cláusula.

- A cadeia de caracteres retornada por [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql). Por padrão, esse é o nome da tabela especificada para o conjunto de registros no assistente, mas você pode alterar a função retorna. A estrutura chama `GetDefaultSQL` — se a cadeia de caracteres começa com "SELECT" ou "{CALL", supõe-se para ser um nome de tabela, que é usado para construir uma cadeia de caracteres SQL.


- Os membros de dados campo do conjunto de registros, que devem ser associados a colunas específicas da tabela. O framework associa colunas de registro para os endereços desses membros, usá-los como buffers. A estrutura determina a correlação de membros de dados de campo para colunas da tabela das [RFX](../../data/odbc/record-field-exchange-using-rfx.md) ou chamadas de função de RFX em massa no conjunto de registros [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange ](../../mfc/reference/crecordset-class.md#dofieldexchange) função de membro.

- O [filtro](../../data/odbc/recordset-filtering-records-odbc.md) para o conjunto de registros, se houver, contidos na [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) membro de dados. A estrutura usa essa cadeia de caracteres para construir um SQL **onde** cláusula.

- O [sort](../../data/odbc/recordset-sorting-records-odbc.md) a ordem de conjunto de registros, se houver, contido na [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort) membro de dados. A estrutura usa essa cadeia de caracteres para construir um SQL **ORDER BY** cláusula.

   > [!TIP]
   > Para usar o SQL **GROUP BY** cláusula (e, possivelmente, o **HAVING** cláusula), as cláusulas de acréscimo ao final da cadeia de caracteres de filtro.

- Os valores de qualquer [membros de dados do parâmetro](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) especificar para a classe. Definir valores de parâmetro antes de chamar `Open` ou `Requery`. O framework associa os valores de parâmetro para "?" espaços reservados na cadeia de caracteres SQL. Em tempo de compilação, você pode especificar a cadeia de caracteres com espaços reservados. Em tempo de execução, o framework preenche os detalhes com base nos valores de parâmetro que você passe.

`Open` constrói um SQL **selecionar** instrução from esses ingredientes. Ver [Personalizando a seleção](#_core_customizing_the_selection) para obter detalhes sobre como a estrutura usa os ingredientes.

Depois de construir a instrução `Open` envia o SQL para o Gerenciador de Driver ODBC (e a biblioteca de cursores ODBC, se ele estiver na memória), que envia para o driver ODBC para o DBMS específico. O driver se comunica com o DBMS para realizar a seleção na fonte de dados e busca o primeiro registro. O framework carrega o registro para os membros de dados do campo do conjunto de registros.

Você pode usar uma combinação dessas técnicas para abrir [tabelas](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md) e para construir uma consulta com base em um [junção](../../data/odbc/recordset-performing-a-join-odbc.md) de várias tabelas. Com a personalização adicional, você pode chamar [predefinidos de consultas](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md) (procedimentos armazenados), não é conhecidas em tempo de design de colunas da tabela de select e [associar](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md) -los aos campos do conjunto de registros ou você podem realizar a maioria das outras tarefas de acesso a dados. Tarefas que você não pode realizar Personalizando conjuntos de registros podem ser realizadas por [chamando funções de API do ODBC](../../data/odbc/odbc-calling-odbc-api-functions-directly.md) ou diretamente executando instruções SQL com [CDatabase::](../../mfc/reference/cdatabase-class.md#executesql).

##  <a name="_core_customizing_the_selection"></a> Personalizando a seleção

Além de fornecer um filtro, uma ordem de classificação ou parâmetros, você pode executar as seguintes ações para personalizar a seleção do seu conjunto de registros:

- Passar uma cadeia de caracteres SQL personalizada no *lpszSQL* quando você chama [abrir](../../mfc/reference/crecordset-class.md#open) para o conjunto de registros. Qualquer coisa que você passe *lpsqSQL* prevalece sobre o que o [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql) retorna da função de membro.

   Para obter mais informações, consulte [SQL: SQL instrução (ODBC Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md), que descreve os tipos de instruções SQL (ou declarações parciais), você pode passar para `Open` e o que a estrutura faz com eles.

    > [!NOTE]
    >  Se a cadeia de caracteres personalizada que você passe não começa com "SELECT" ou "{CALL", o MFC pressupõe que ele contém um nome de tabela. Isso também se aplica para o próximo item.

- Alterar a cadeia de caracteres que o assistente grava em seu conjunto de registros `GetDefaultSQL` função de membro. Edite o código de função para alterar o que ele retorna. Por padrão, o assistente grava um `GetDefaultSQL` função que retorna um nome de tabela única.

   Você pode ter `GetDefaultSQL` retornar qualquer um dos itens que você pode passar a *lpszSQL* parâmetro `Open`. Se você não passar uma cadeia de caracteres SQL personalizada no *lpszSQL*, a estrutura usa a cadeia de caracteres que `GetDefaultSQL` retorna. No mínimo, `GetDefaultSQL` deve retornar um nome de tabela única. Mas você pode fazer com que ele retorne vários nomes de tabela, uma completa **selecionar** instrução ODBC **chamar** instrução e assim por diante. Para obter uma lista dos quais você pode passar para *lpszSQL* — ou ter `GetDefaultSQL` retornar — consulte [SQL: SQL instrução (ODBC Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

   Se você estiver executando uma junção de duas ou mais tabelas, reescreva `GetDefaultSQL` para personalizar a lista de tabela usada no SQL **FROM** cláusula. Para obter mais informações, consulte [conjunto de registros: executando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).


- Vincule manualmente os membros de dados do campo adicional, talvez com base nas informações de que você obter sobre o esquema da fonte de dados em tempo de execução. Adicionar membros de dados do campo à classe, o conjunto de registros [RFX](../../data/odbc/record-field-exchange-using-rfx.md) chamadas de função RFX em massa para que eles ou o [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) função de membro, e inicializações dos membros de dados no construtor da classe. Para obter mais informações, consulte [conjunto de registros: dinamicamente associando dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

- Substituir funções de membro do conjunto de registros, tal como `OnSetOptions`, defina opções específicas do aplicativo ou substituir os padrões.

Se você deseja basear o conjunto de registros em uma instrução SQL complexa, você precisa usar uma combinação dessas técnicas de personalização. Por exemplo, talvez você queira usar cláusulas SQL e palavras-chave não tem suportadas direto por conjuntos de registros ou talvez você estão ingressando várias tabelas.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)<br/>
[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)<br/>
[SQL](../../data/odbc/sql.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)