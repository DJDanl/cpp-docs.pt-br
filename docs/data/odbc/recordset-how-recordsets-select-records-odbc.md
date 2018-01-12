---
title: 'Conjunto de registros: Como conjuntos de registros selecionam registros (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- recordsets, selecting records
- record selection, ODBC recordsets
- SQL statements, recordset
- records, selecting
- recordsets, constructing SQL statements
- ODBC recordsets, selecting records
ms.assetid: 343a6a91-aa4c-4ef7-b21f-2f2bfd0d3787
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8664c5732c0cdf1042b6af338ea388ab29ab7863
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recordset-how-recordsets-select-records-odbc"></a>Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica:  
  
-   [Sua função e as opções de seleção de registros](#_core_your_options_in_selecting_records).  
  
-   [Como um conjunto de registros cria sua instrução SQL e seleciona os registros](#_core_how_a_recordset_constructs_its_sql_statement).  
  
-   [O que você pode fazer para personalizar a seleção](#_core_customizing_the_selection).  
  
 Conjuntos de registros selecionam registros de uma fonte de dados por meio de um driver ODBC ao enviar instruções SQL para o driver. O SQL enviado depende de como você cria e abra sua classe de conjunto de registros.  
  
##  <a name="_core_your_options_in_selecting_records"></a>As opções de seleção de registros  
 A tabela a seguir mostra as opções de seleção de registros.  
  
### <a name="how-and-when-you-can-affect-a-recordset"></a>Como e quando você pode afetar um conjunto de registros  
  
|Quando você|É possível|  
|--------------|-------------|  
|Declarar a classe de conjunto de registros com o **Adicionar classe** Assistente|Especifique qual tabela selecionem.<br /><br /> Especifique quais colunas deseja incluir.<br /><br /> Consulte [adicionando um consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).|  
|Concluir sua implementação de classe de conjunto de registros|Substituir funções de membro, como `OnSetOptions` (avançados) para definir opções específicas do aplicativo ou para alterar os padrões. Se você quiser que um conjunto de registros com parâmetros, especifique os membros de dados de parâmetro.|  
|Construir um objeto de conjunto de registros (antes de chamar **abrir**)|Especificar um critério de pesquisa (possivelmente composto) para uso em um **onde** cláusula que filtra os registros. Consulte [conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).<br /><br /> Especificar uma ordem de classificação para uso em um **ORDER BY** cláusula que classifica os registros. Consulte [conjunto de registros: Classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md).<br /><br /> Especifica valores de parâmetro para quaisquer parâmetros que você adicionou à classe. Consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).|  

| Execute a consulta do conjunto de registros chamando **abrir**| Especifique uma cadeia de caracteres SQL personalizada para substituir a cadeia de caracteres SQL padrão configurada pelo assistente. Consulte [CRecordset::Open](../../mfc/reference/crecordset-class.md#open) no *referência da biblioteca de classes* e [SQL: Personalizando a instrução SQL de seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md). |  

| Chamar **Requery** para repetir a consulta de conjunto de registros com os valores mais recentes na fonte de dados | Especifique novos parâmetros, filtrar ou classificar. Consulte [conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md). |  
  
##  <a name="_core_how_a_recordset_constructs_its_sql_statement"></a>Como um conjunto de registros constrói sua instrução SQL  
 Quando você chama um objeto de conjunto de registros [abrir](../../mfc/reference/crecordset-class.md#open) função de membro, **abrir** constrói uma instrução SQL usando alguns ou todos os componentes a seguir:  
  
-   O **lpszSQL** parâmetro passado para **abrir**. Se não **nulo**, esse parâmetro especifica uma cadeia de caracteres SQL personalizada ou parte de um. A estrutura analisa a cadeia de caracteres. Se a cadeia de caracteres for um SQL **selecione** instrução ou um ODBC **chamar** instrução, a estrutura usa a cadeia de caracteres como instrução de SQL do conjunto de registros. Se a cadeia de caracteres não começa com "SELECT" ou "{CALL", a estrutura usa o que é fornecido para construir um SQL **FROM** cláusula.  
  
-   A cadeia de caracteres retornada por [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql). Por padrão, esse é o nome da tabela especificada para o conjunto de registros no assistente, mas você pode alterar a função retorna. A estrutura chama `GetDefaultSQL` — se a cadeia de caracteres não começa com "SELECT" ou "{CALL", presume-se para ser um nome de tabela, que é usado para construir uma cadeia de caracteres SQL.  
  

-   Os campo membros de dados do conjunto de registros, que devem ser associados a colunas específicas da tabela. A estrutura associa colunas de registro para os endereços desses membros, usá-los como buffers. A estrutura determina a correlação de membros de dados de campo para colunas de tabela do [RFX](../../data/odbc/record-field-exchange-using-rfx.md) chamadas de função RFX em massa no conjunto de registros ou [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange ](../../mfc/reference/crecordset-class.md#dofieldexchange) função de membro.  
  
-   O [filtro](../../data/odbc/recordset-filtering-records-odbc.md) para o conjunto de registros, se houver, dentro de [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) membro de dados. A estrutura usa essa cadeia de caracteres para construir um SQL **onde** cláusula.  
  
-   O [classificação](../../data/odbc/recordset-sorting-records-odbc.md) ordem para o conjunto de registros, se houver, contido no [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort) membro de dados. A estrutura usa essa cadeia de caracteres para construir um SQL **ORDER BY** cláusula.  

  
    > [!TIP]
    >  Para usar o SQL **GROUP BY** cláusula (e possivelmente o **HAVING** cláusula), acrescente as cláusulas ao final da cadeia de caracteres de filtro.  
  
-   Os valores de qualquer [membros de dados do parâmetro](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) especificado para a classe. Definir valores de parâmetro antes de chamar **abrir** ou **Requery**. A estrutura associa os valores de parâmetro para "?" espaços reservados na cadeia de caracteres SQL. Em tempo de compilação, você pode especificar a cadeia de caracteres com espaços reservados. Em tempo de execução, o framework preenche os detalhes com base nos valores de parâmetro que você passa.  
  
 **Abra** constrói um SQL **selecione** instrução desses componentes. Consulte [Personalizando a seleção](#_core_customizing_the_selection) para obter detalhes sobre como a estrutura usa os componentes.  
  
 Após a criação da instrução, **abrir** envia o SQL para o Gerenciador de Driver ODBC (e a biblioteca de cursores ODBC se ele estiver na memória), que envia para o driver ODBC para o DBMS específico. O driver se comunica com o DBMS para realizar a seleção na fonte de dados e busca o primeiro registro. A estrutura carrega o registro para os membros de dados do campo do conjunto de registros.  
  
 Você pode usar uma combinação dessas técnicas para abrir [tabelas](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md) e para construir uma consulta com base em um [junção](../../data/odbc/recordset-performing-a-join-odbc.md) de várias tabelas. Com a personalização adicional, você pode chamar [predefinidos consultas](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md) (procedimentos armazenados), selecione colunas não é conhecidas em tempo de design de tabela e [associar](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md) -los para campos de conjunto de registros ou você podem executar a maioria das outras tarefas de acesso a dados. Tarefas que você não pode realizar Personalizando conjuntos de registros podem ser realizadas por [chamando funções de API de ODBC](../../data/odbc/odbc-calling-odbc-api-functions-directly.md) ou diretamente a execução de instruções SQL com [CDatabase::](../../mfc/reference/cdatabase-class.md#executesql).  
  
##  <a name="_core_customizing_the_selection"></a>Personalizando a seleção  
 Além de fornecer um filtro, uma ordem de classificação ou parâmetros, você pode executar as seguintes ações para personalizar a seleção do seu conjunto de registros:  
  
-   Passar uma cadeia de caracteres SQL personalizada em **lpszSQL** quando você chama [abrir](../../mfc/reference/crecordset-class.md#open) para o conjunto de registros. Qualquer coisa que você transmitir **lpsqSQL** tem precedência sobre o que o [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql) retorna da função de membro.  
  
     Para obter mais informações, consulte [SQL: SQL instrução (ODBC do Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md), que descreve os tipos de instruções SQL (ou parciais instruções), você pode passar para **abrir** e o que faz o framework com eles.  
  
    > [!NOTE]
    >  Se a cadeia de caracteres personalizada que você passa não começa com "SELECT" ou "{CALL", MFC pressupõe que ele contém um nome de tabela. Isso também se aplica para o próximo item.  
  
-   Alterar a cadeia de caracteres que o assistente grava em seu conjunto de registros `GetDefaultSQL` função de membro. Edite o código da função para alterar o que ele retorna. Por padrão, o assistente grava um `GetDefaultSQL` função que retorna um nome de tabela única.  
  
     Você pode ter `GetDefaultSQL` retornar qualquer um dos itens que você pode passar o **lpszSQL** parâmetro para **abrir**. Se você não passar uma cadeia de caracteres SQL personalizada em **lpszSQL**, a estrutura usa a cadeia de caracteres que `GetDefaultSQL` retorna. No mínimo, `GetDefaultSQL` deve retornar um nome de tabela única. Mas você pode colocá-lo a retornar vários nomes de tabela, uma completa **selecione** instrução ODBC **chamar** instrução e assim por diante. Para obter uma lista da qual você pode passar para **lpszSQL** — ou tem `GetDefaultSQL` retornar — consulte [SQL: SQL instrução (ODBC do Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).  
  
     Se você estiver executando uma junção de duas ou mais tabelas, reescreva `GetDefaultSQL` para personalizar a lista de tabela usada no SQL **FROM** cláusula. Para obter mais informações, consulte [conjunto de registros: executar uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).  
  

-   Vincule manualmente os membros de dados do campo adicional, talvez com base em informações que você obter sobre o esquema da fonte de dados em tempo de execução. Adicionar membros de dados de campo para a classe de conjunto de registros, [RFX](../../data/odbc/record-field-exchange-using-rfx.md) ou chamadas de função de RFX em massa para que eles o [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) ou [DoBulkFieldExchange](../../mfc/reference/crecordset-class.md#dobulkfieldexchange) função de membro, e inicializações de membros de dados no construtor da classe. Para obter mais informações, consulte [conjunto de registros: dinamicamente de associação de dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
-   Substituir funções de membro do conjunto de registros, como `OnSetOptions`, para definir opções específicas do aplicativo ou para substituir os padrões.  
  
 Se você deseja basear o conjunto de registros em uma instrução SQL complexas, você precisa usar uma combinação dessas técnicas de personalização. Por exemplo, talvez você queira usar cláusulas SQL e palavras-chave não oferece suportadas direto a conjuntos de registros ou talvez você estão ingressando várias tabelas.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)   
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)   
 [SQL](../../data/odbc/sql.md)   
 [Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)