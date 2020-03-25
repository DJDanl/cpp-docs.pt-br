---
title: 'Registrar troca de campos: como funciona RFX'
ms.date: 11/04/2016
helpviewer_keywords:
- record editing [C++], using RFX
- RFX (ODBC) [C++], updating data in recordsets
- scrolling [C++]
- ODBC [C++], RFX
- data binding [C++], DFX
- scrolling [C++], RFX
- RFX (ODBC) [C++], binding fields and parameters
ms.assetid: e647cacd-62b0-4b80-9e20-b392deca5a88
ms.openlocfilehash: 0661e61bceeedc0dd049ef47f5a0a0b71a8d82ed
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213064"
---
# <a name="record-field-exchange-how-rfx-works"></a>Registrar troca de campos: como funciona RFX

Este tópico explica o processo suporte RFX. Este é um tópico avançado que aborda:

- [SUPORTE RFX e o conjunto de registros](#_core_rfx_and_the_recordset)

- [O processo suporte RFX](#_core_the_record_field_exchange_process)

> [!NOTE]
>  Este tópico aplica-se a classes derivadas de `CRecordset` nas quais o fetch de linha em massa não foi implementado. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="rfx-and-the-recordset"></a><a name="_core_rfx_and_the_recordset"></a>SUPORTE RFX e o conjunto de registros

Os membros de dados de campo do objeto recordset, juntos, constituem um buffer de edição que contém as colunas selecionadas de um registro. Quando o conjunto de registros é aberto pela primeira vez e está prestes a ler o primeiro registro, o suporte RFX associa (associa) cada coluna selecionada ao endereço do membro de dados do campo apropriado. Quando o conjunto de registros atualiza um registro, o suporte RFX chama as funções da API do ODBC para enviar uma instrução SQL **Update** ou **Insert** para o driver. SUPORTE RFX usa seu conhecimento dos membros de dados de campo para especificar as colunas a serem gravadas.

A estrutura faz backup do buffer de edição em determinados estágios para que possa restaurar seu conteúdo, se necessário. O suporte RFX faz backup do buffer de edição antes de adicionar um novo registro e antes de editar um registro existente. Ele restaura o buffer de edição em alguns casos, por exemplo, após uma `Update` chamada a seguir `AddNew`. O buffer de edição não será restaurado se você abandonar um buffer de edição recém alterado por, por exemplo, movendo para outro registro antes de chamar `Update`.

Além de trocar dados entre a fonte de dados e os membros de dados de campo do conjunto de registros, o suporte RFX gerencia os parâmetros de associação. Quando o conjunto de registros é aberto, todos os membros de dados de parâmetro são associados na ordem dos espaços reservados "?" na instrução SQL que `CRecordset::Open` construções. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

A substituição de `DoFieldExchange` da sua classe do conjunto de registros faz todo o trabalho, movendo os dados em ambas as direções. Assim como a troca de dados de caixa de diálogo (campo DDX), o suporte RFX precisa de informações sobre os membros de dados de sua classe. O assistente fornece as informações necessárias escrevendo uma implementação específica de conjunto de registros de `DoFieldExchange` para você, com base nos nomes de membros de dados de campo e nos tipos de dados especificados com o assistente.

##  <a name="record-field-exchange-process"></a><a name="_core_the_record_field_exchange_process"></a>Gravar o processo de troca de campo

Esta seção descreve a sequência de eventos suporte RFX, uma vez que um objeto Recordset é aberto e à medida que você adiciona, atualiza e exclui registros. A [sequência de tabelas de operações de suporte RFX durante a abertura do conjunto de registros](#_core_sequence_of_rfx_operations_during_recordset_open) e a [sequência da tabela de operações do suporte RFX durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling) neste tópico mostram o processo, pois o suporte rfx processa um comando `Move` no conjunto de registros e, como suporte RFX, gerencia uma atualização. Durante esses processos, o [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) é chamado para executar várias operações diferentes. O membro de dados `m_nOperation` do objeto [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) determina qual operação é solicitada. Talvez seja útil ler [o conjunto de registros: como os conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md) e [conjunto de registros: como os Recordsets atualizam os registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) antes de ler este material.

###  <a name="rfx-initial-binding-of-columns-and-parameters"></a><a name="_mfc_rfx.3a_.initial_binding_of_columns_and_parameters"></a>SUPORTE RFX: associação inicial de colunas e parâmetros

As seguintes atividades suporte RFX ocorrem, na ordem mostrada, quando você chama a função de membro [Open](../../mfc/reference/crecordset-class.md#open) de um objeto Recordset:

- Se o conjunto de registros tiver membros de dados de parâmetro, a estrutura chamará `DoFieldExchange` para associar os parâmetros aos espaços reservados de parâmetro na cadeia de caracteres da instrução SQL do conjunto de registros. Uma representação dependente de tipo de dados do valor do parâmetro é usada para cada espaço reservado encontrado na instrução **Select** . Isso ocorre depois que a instrução SQL é preparada, mas antes de ser executada. Para obter informações sobre preparação de instrução, consulte a função `::SQLPrepare` na *referência do programador*de ODBC.

- A estrutura chama `DoFieldExchange` uma segunda vez para associar os valores das colunas selecionadas aos membros de dados de campo correspondentes no conjunto de registros. Isso estabelece o objeto Recordset como um buffer de edição que contém as colunas do primeiro registro.

- O conjunto de registros executa a instrução SQL e a fonte de dados seleciona o primeiro registro. As colunas do registro são carregadas nos membros de dados de campo do conjunto de registros.

A tabela a seguir mostra a sequência de operações suporte RFX quando você abre um conjunto de registros.

### <a name="sequence-of-rfx-operations-during-recordset-open"></a><a name="_core_sequence_of_rfx_operations_during_recordset_open"></a>Sequência de operações suporte RFX durante a abertura do conjunto de registros

|Sua operação|Operação DoFieldExchange|Operação de banco de dados/SQL|
|--------------------|-------------------------------|-----------------------------|
|1. abrir conjunto de registros.|||
||2. Crie uma instrução SQL.||
|||3. envie o SQL.|
||4. associar membros de dados de parâmetro.||
||5. associar membros de dados de campo a colunas.||
|||6. o ODBC faz a movimentação e preenche os dados.|
||7. corrija os dados para C++o.||

Os conjuntos de registros usam a execução preparada do ODBC para permitir a reconsulta rápida com a mesma instrução SQL. Para obter mais informações sobre a execução preparada, consulte a *referência do programador do* SDK do ODBC na biblioteca MSDN.

###  <a name="rfx-scrolling"></a><a name="_mfc_rfx.3a_.scrolling"></a>SUPORTE RFX: rolagem

Quando você rola de um registro para outro, a estrutura chama `DoFieldExchange` para substituir os valores armazenados anteriormente no campo membros de dados com valores para o novo registro.

A tabela a seguir mostra a sequência de operações suporte RFX quando o usuário passa de registro para registro.

### <a name="sequence-of-rfx-operations-during-scrolling"></a><a name="_core_sequence_of_rfx_operations_during_scrolling"></a>Sequência de operações suporte RFX durante a rolagem

|Sua operação|Operação DoFieldExchange|Operação de banco de dados/SQL|
|--------------------|-------------------------------|-----------------------------|
|1. chame `MoveNext` ou uma das outras funções de movimentação.|||
|||2. o ODBC faz a movimentação e preenche os dados.|
||3. corrija os dados para C++.||

###  <a name="rfx-adding-new-records-and-editing-existing-records"></a><a name="_mfc_rfx.3a_.adding_new_records_and_editing_existing_records"></a>SUPORTE RFX: adicionando novos registros e editando registros existentes

Se você adicionar um novo registro, o conjunto de registros funcionará como um buffer de edição para criar o conteúdo do novo registro. Assim como a adição de registros, a edição de registros envolve a alteração dos valores dos membros de dados de campo do conjunto de registros. Da perspectiva do suporte RFX, a sequência é a seguinte:

1. Sua chamada para a função de membro [AddNew](../../mfc/reference/crecordset-class.md#addnew) ou [Edit](../../mfc/reference/crecordset-class.md#edit) do conjunto de registros faz com que o suporte RFX armazene o buffer de edição atual para que possa ser restaurado mais tarde.

1. `AddNew` ou `Edit` prepara os campos no buffer de edição para que suporte RFX possa detectar membros de dados de campo alterados.

   Como um novo registro não tem valores anteriores para comparar os novos com, `AddNew` define o valor de cada membro de dados de campo para um valor de PSEUDO_NULL. Posteriormente, quando você chama `Update`, suporte RFX compara o valor de cada membro de dados com o valor de PSEUDO_NULL. Se houver uma diferença, o membro de dados foi definido. (PSEUDO_NULL não é o mesmo que uma coluna de registro com um valor nulo verdadeiro, nem é um dos mesmos que C++ NULL.)

   Ao contrário da chamada de `Update` para `AddNew`, a chamada de `Update` para `Edit` compara valores atualizados com valores armazenados anteriormente em vez de usar PSEUDO_NULL. A diferença é que `AddNew` não tem valores armazenados anteriormente para comparação.

1. Você define diretamente os valores dos membros de dados de campo cujos valores você deseja editar ou que você deseja que sejam preenchidos para um novo registro. Isso pode incluir a chamada de `SetFieldNull`.

1. Sua chamada para [Update](../../mfc/reference/crecordset-class.md#update) verifica os membros de dados de campo alterados, conforme descrito na etapa 2 (consulte a [sequência de tabelas de operações suporte RFX durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling)). Se nenhum tiver sido alterado, `Update` retornará 0. Se alguns membros de dados de campo foram alterados, `Update` prepara e executa uma instrução SQL **Insert** que contém valores para todos os campos atualizados no registro.

1. Por `AddNew`, `Update` é concluído restaurando os valores armazenados anteriormente do registro que era atual antes da chamada de `AddNew`. Por `Edit`, os valores novos e editados permanecem em vigor.

A tabela a seguir mostra a sequência de operações suporte RFX quando você adiciona um novo registro ou edita um registro existente.

### <a name="sequence-of-rfx-operations-during-addnew-and-edit"></a>Sequência de operações suporte RFXs durante AddNew e Edit

|Sua operação|Operação DoFieldExchange|Operação de banco de dados/SQL|
|--------------------|-------------------------------|-----------------------------|
|1. chamar `AddNew` ou `Edit`.|||
||2. faça backup do buffer de edição.||
||3. por `AddNew`, marque membros de dados de campo como "limpar" e nulo.||
|4. atribua valores aos membros de dados de campo do conjunto de registros.|||
|5. chame `Update`.|||
||6. Verifique se há campos alterados.||
||7. Compilar instrução **Insert** do SQL para `AddNew` ou instrução **Update** para `Edit`.||
|||8. envie o SQL.|
||9. por `AddNew`, restaure o buffer de edição para seu conteúdo de backup. Para `Edit`, exclua o backup.||

### <a name="rfx-deleting-existing-records"></a>SUPORTE RFX: excluindo registros existentes

Quando você exclui um registro, o suporte RFX define todos os campos como nulos como um lembrete de que o registro é excluído e você deve movê-lo. Você não precisa de nenhuma outra informação de sequência de suporte RFX.

## <a name="see-also"></a>Confira também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[CRecordset::D oFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange)
