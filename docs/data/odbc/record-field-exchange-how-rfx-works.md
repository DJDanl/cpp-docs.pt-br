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
ms.openlocfilehash: 903acf4f55fb2708f4998a2babf3f143c895429b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367168"
---
# <a name="record-field-exchange-how-rfx-works"></a>Registrar troca de campos: como funciona RFX

Este tópico explica o processo RFX. Este é um tópico avançado que abrange:

- [RFX e o conjunto de registros](#_core_rfx_and_the_recordset)

- [O processo RFX](#_core_the_record_field_exchange_process)

> [!NOTE]
> Este tópico aplica-se a classes derivadas de `CRecordset` nas quais o fetch de linha em massa não foi implementado. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="rfx-and-the-recordset"></a><a name="_core_rfx_and_the_recordset"></a>RFX e o Conjunto de Registros

Os membros de dados de campo do objeto recordset, juntos, constituem um buffer de edição que contém as colunas selecionadas de um registro. Quando o conjunto de registros é aberto pela primeira vez e está prestes a ler o primeiro registro, o RFX vincula (associados) cada coluna selecionada ao endereço do membro de dados de campo apropriado. Quando o conjunto de registros atualiza um registro, o RFX chama as funções da API ODBC para enviar uma **instrução** SQL UPDATE ou **INSERT** para o driver. O RFX usa seu conhecimento dos membros de dados de campo para especificar as colunas a serem escritas.

A estrutura faz backup do buffer de edição em certos estágios para que ele possa restaurar seu conteúdo, se necessário. O RFX apoia o buffer de edição antes de adicionar um novo registro e antes de editar um registro existente. Ele restaura o buffer de edição em alguns casos, por exemplo, após uma `Update` chamada a seguir `AddNew`. O buffer de edição não será restaurado se você abandonar um buffer de `Update`edição recém-alterado, por exemplo, movendo-se para outro registro antes de chamar .

Além de trocar dados entre a fonte de dados e os membros de dados de campo do conjunto de registros, o RFX gerencia parâmetros de vinculação. Quando o conjunto de registros é aberto, todos os membros de dados de parâmetros `CRecordset::Open` são vinculados à ordem dos "?" espaços reservados na declaração SQL que constrói. Para obter mais informações, consulte [Recordset: Parametizando um Conjunto de Registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

A substituição da sua classe `DoFieldExchange` de gravação faz todo o trabalho, movendo dados em ambas as direções. Como o Exchange de Dados de Diálogo (DDX), o RFX precisa de informações sobre os membros de dados da sua classe. O assistente fornece as informações necessárias escrevendo `DoFieldExchange` uma implementação específica do conjunto de registros para você, com base nos nomes dos membros de dados de campo e nos tipos de dados especificados com o assistente.

## <a name="record-field-exchange-process"></a><a name="_core_the_record_field_exchange_process"></a>Processo de troca de campo de registro

Esta seção descreve a seqüência de eventos RFX como um objeto de conjunto de registros é aberto e à medida que você adiciona, atualiza e exclui registros. A [seqüência de tabela de operações RFX durante](#_core_sequence_of_rfx_operations_during_recordset_open) o Recordset Open e a [seqüência de tabela de operações RFX durante](#_core_sequence_of_rfx_operations_during_scrolling) a rolagem neste tópico mostram o processo à medida que o RFX processa um `Move` comando no conjunto de registros e como o RFX gerencia uma atualização. Durante esses processos, [o DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) é chamado para executar muitas operações diferentes. O `m_nOperation` membro de dados do objeto [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) determina qual operação é solicitada. Você pode achar útil ler [Recordset: How Recordsets Select Records (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md) e [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) antes de ler este material.

### <a name="rfx-initial-binding-of-columns-and-parameters"></a><a name="_mfc_rfx.3a_.initial_binding_of_columns_and_parameters"></a>RFX: Vinculação inicial de colunas e parâmetros

As seguintes atividades de RFX ocorrem, na ordem mostrada, quando você chama a função de membro aberto de um objeto [de](../../mfc/reference/crecordset-class.md#open) recordset:

- Se o conjunto de registros tiver membros `DoFieldExchange` de dados de parâmetros, o framework será capaz de vincular os parâmetros aos espaços reservados de parâmetros na seqüência de demonstrações sql do conjunto de registros. Uma representação dependente do tipo de dados do valor do parâmetro é usada para cada espaço reservado encontrado na declaração **SELECT.** Isso ocorre depois que a declaração SQL é preparada, mas antes de ser executada. Para obter informações sobre `::SQLPrepare` a preparação da declaração, consulte a função no *Programador de Referência da*ODBC .

- O framework `DoFieldExchange` chama uma segunda vez para vincular os valores das colunas selecionadas aos membros correspondentes de dados de campo no conjunto de registros. Isso estabelece o objeto recordset como um buffer de edição contendo as colunas do primeiro registro.

- O conjunto de registros executa a declaração SQL e a fonte de dados seleciona o primeiro registro. As colunas do registro são carregadas nos membros de dados de campo do conjunto de registros.

A tabela a seguir mostra a seqüência de operações RFX quando você abre um conjunto de registros.

### <a name="sequence-of-rfx-operations-during-recordset-open"></a><a name="_core_sequence_of_rfx_operations_during_recordset_open"></a>Seqüência de operações RFX durante o registro aberto

|Sua operação|Operação DoFieldExchange|Operação banco de dados/SQL|
|--------------------|-------------------------------|-----------------------------|
|1. Conjunto de registros abertos.|||
||2. Construa uma declaração SQL.||
|||3. Envie o SQL.|
||4. Vincular membros de dados de parâmetros.||
||5. Vincule os membros de dados de campo a colunas.||
|||6. A ODBC faz o movimento e preenche os dados.|
||7. Corrija os dados para C++.||

Os conjuntos de registros usam a execução preparada da ODBC para permitir a execução rápida com a mesma declaração SQL. Para obter mais informações sobre a execução preparada, consulte a *referência do programador* ODBC SDK na Biblioteca MSDN.

### <a name="rfx-scrolling"></a><a name="_mfc_rfx.3a_.scrolling"></a>RFX: Rolagem

Quando você rola de um registro `DoFieldExchange` para outro, o framework chama para substituir os valores anteriormente armazenados nos membros de dados de campo por valores para o novo registro.

A tabela a seguir mostra a seqüência de operações RFX quando o usuário passa de registro para registro.

### <a name="sequence-of-rfx-operations-during-scrolling"></a><a name="_core_sequence_of_rfx_operations_during_scrolling"></a>Seqüência de operações RFX durante a rolagem

|Sua operação|Operação DoFieldExchange|Operação banco de dados/SQL|
|--------------------|-------------------------------|-----------------------------|
|1. `MoveNext` Ligue ou uma das outras funções Move.|||
|||2. A ODBC faz o movimento e preenche os dados.|
||3. Corrija os dados para C++.||

### <a name="rfx-adding-new-records-and-editing-existing-records"></a><a name="_mfc_rfx.3a_.adding_new_records_and_editing_existing_records"></a>RFX: Adicionando novos registros e edição de registros existentes

Se você adicionar um novo registro, o conjunto de registros funcionará como um buffer de edição para construir o conteúdo do novo registro. Assim como na adição de registros, a edição de registros envolve alterar os valores dos membros de dados de campo do conjunto de registros. Do ponto de vista rfx, a seqüência é a seguinte:

1. Sua chamada para a função [addnew](../../mfc/reference/crecordset-class.md#addnew) ou [editar](../../mfc/reference/crecordset-class.md#edit) membro do conjunto de gravações faz com que o RFX armazene o buffer de edição atual para que ele possa ser restaurado mais tarde.

1. `AddNew`ou `Edit` prepara os campos no buffer de edição para que o RFX possa detectar membros de dados de campo alterados.

   Como um novo registro não tem valores `AddNew` anteriores para comparar novos, define o valor de cada membro de dados de campo para um valor PSEUDO_NULL. Mais tarde, `Update`quando você liga, o RFX compara o valor de cada membro de dados com o valor PSEUDO_NULL. Se houver diferença, o membro de dados foi definido. (PSEUDO_NULL não é o mesmo que uma coluna de registro com um valor nulo verdadeiro nem é qualquer um deles o mesmo que C++ NULL.)

   Ao `Update` contrário `AddNew`do `Update` call `Edit` for , a chamada para comparar valores atualizados com valores armazenados anteriormente em vez de usar PSEUDO_NULL. A diferença `AddNew` é que não tem valores armazenados anteriormente para comparação.

1. Você define diretamente os valores dos membros de dados de campo cujos valores você deseja editar ou que deseja preencher para um novo registro. Isso pode `SetFieldNull`incluir chamada .

1. Sua chamada para [Atualizar](../../mfc/reference/crecordset-class.md#update) verifica os membros de dados de campo alterados, conforme descrito na etapa 2 (consulte a [seqüência de tabela de operações RFX durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling)). Se ninguém mudou, `Update` retorna 0. Se alguns membros de `Update` dados de campo tiverem alterado, prepare e execute uma instrução SQL **INSERT** que contenha valores para todos os campos atualizados no registro.

1. Para `AddNew` `Update` , conclui restaurando os valores previamente armazenados `AddNew` do registro que estava em dia antes da chamada. Para, `Edit`os novos valores editados permanecem em vigor.

A tabela a seguir mostra a seqüência de operações RFX quando você adiciona um novo registro ou edita um registro existente.

### <a name="sequence-of-rfx-operations-during-addnew-and-edit"></a>Seqüência de operações RFX durante o AddNew e edit

|Sua operação|Operação DoFieldExchange|Operação banco de dados/SQL|
|--------------------|-------------------------------|-----------------------------|
|1. `AddNew` Ligue `Edit`ou .|||
||2. Fazer backup do buffer de edição.||
||3. `AddNew`Para, marcar os membros de dados de campo como "limpos" e nulos.||
|4. Atribuir valores aos membros de dados de campo do recordset.|||
|5. `Update`Ligue.|||
||6. Verifique se há campos alterados.||
||7. Construa a instrução SQL **INSERT** para `AddNew` ou a instrução **UPDATE** para `Edit`.||
|||8. Envie o SQL.|
||9. `AddNew`Para, restaurar o buffer de edição ao seu conteúdo de backup. Para, `Edit`exclua o backup.||

### <a name="rfx-deleting-existing-records"></a>RFX: Excluindo registros existentes

Quando você exclui um registro, o RFX define todos os campos como NULL como um lembrete de que o registro é excluído e você deve sair dele. Você não precisa de nenhuma outra informação de seqüência RFX.

## <a name="see-also"></a>Confira também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Classe CfieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[CRecordset::DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange)
