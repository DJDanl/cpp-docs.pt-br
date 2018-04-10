---
title: 'Registrar troca de campos: Como funciona RFX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- record editing [C++], using RFX
- RFX (ODBC) [C++], updating data in recordsets
- scrolling [C++]
- ODBC [C++], RFX
- data binding [C++], DFX
- scrolling [C++], RFX
- RFX (ODBC) [C++], binding fields and parameters
ms.assetid: e647cacd-62b0-4b80-9e20-b392deca5a88
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5eac97bb87103bd72dfd721515baf58324fc851f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="record-field-exchange-how-rfx-works"></a>Registrar troca de campos: como funciona RFX
Este tópico explica o processo RFX. Isso é uma avançada cobertura do tópico:  
  
-   [RFX e o conjunto de registros](#_core_rfx_and_the_recordset)  
  
-   [O processo RFX](#_core_the_record_field_exchange_process)  
  
> [!NOTE]
>  Este tópico se aplica a classes derivadas de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, a troca de campos de registro em massa (RFX em massa) é implementada. Em massa RFX é semelhante a RFX. Para entender as diferenças, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_rfx_and_the_recordset"></a>RFX e o conjunto de registros  
 Membros de dados do campo do objeto de conjunto de registros, juntos, constituem um buffer de edição que contém as colunas selecionadas de um registro. Quando o conjunto de registros é aberto pela primeira vez e está prestes a ler o primeiro registro, RFX associa (associados) cada selecionado coluna para o endereço do membro de dados de campo apropriado. Quando o conjunto de registros atualiza um registro, RFX chama funções ODBC API para enviar um SQL **atualização** ou **inserir** instrução para o driver. RFX usa seu conhecimento dos membros de dados de campo para especificar as colunas para gravação.  
  
 A estrutura faz backup do buffer de edição em determinados estágios para que ele possa restaurar seu conteúdo, se necessário. RFX faz backup do buffer de edição antes de adicionar um novo registro e antes de editar um registro existente. Restaura o buffer de edição em alguns casos, por exemplo, após um **atualização** seguinte chamada `AddNew`. O buffer de edição não é restaurado se abandonar um buffer de edição alterado recentemente, por exemplo, movendo para outro registro antes de chamar **atualização**.  
  
 Além de troca de dados entre a fonte de dados e os membros de dados de campo do conjunto de registros, RFX gerencia a associação de parâmetros. Quando o conjunto de registros é aberto, nenhum membro de dados de parâmetro é associado na ordem do "?" espaços reservados na instrução SQL que `CRecordset::Open` constrói. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
 Substituição da sua classe de conjunto de registros do `DoFieldExchange` faz todo o trabalho, movimentação de dados em ambas as direções. Como a troca de dados de caixa de diálogo (DDX), RFX necessita de informações sobre os membros de dados de sua classe. O assistente fornece as informações necessárias, escrevendo uma implementação específica de conjunto de registros de `DoFieldExchange` para você, com base nos dados do campo membro nomes e tipos de dados especificados com o assistente.  
  
##  <a name="_core_the_record_field_exchange_process"></a>Processo de troca de campos do registro  
 Esta seção descreve a sequência de eventos RFX como um objeto de conjunto de registros é aberto e como adicionar, atualizar e excluir registros. A tabela [sequência de RFX operações durante Recordset abrir](#_core_sequence_of_rfx_operations_during_recordset_open) e a tabela [sequência de RFX operações durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling) neste tópico mostram o processo como processos RFX um **mover**comando no conjunto de registros e RFX gerencia uma atualização. Durante esses processos, [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) é chamado para executar muitas operações diferentes. O **m_nOperation** membro de dados a [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto determina qual operação é solicitada. Talvez seja útil ler [conjunto de registros: como conjuntos de registros selecionar registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md) e [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) antes de ler este material.  
  
###  <a name="_mfc_rfx.3a_.initial_binding_of_columns_and_parameters"></a>RFX: A associação inicial de colunas e parâmetros  
 Ocorrem as seguintes atividades RFX, na ordem mostrada, quando você chama um objeto de conjunto de registros [abrir](../../mfc/reference/crecordset-class.md#open) função de membro:  
  
-   Se o conjunto de registros tem membros de dados de parâmetro, o framework chama `DoFieldExchange` para associar os parâmetros de espaços reservados de parâmetros na cadeia de caracteres de instrução de SQL do conjunto de registros. Uma representação de tipo dependente do valor do parâmetro é usada para cada espaço reservado de dados encontrado no **selecione** instrução. Isso ocorre depois que a instrução SQL está preparada, mas antes de ser executado. Para obter informações sobre a preparação de instrução, consulte o **:: SQLPrepare** função no ODBC *referência do programador de*.  
  
-   A estrutura chama `DoFieldExchange` uma segunda vez para associar os valores das colunas selecionadas para membros de dados de campo correspondente no conjunto de registros. Isso estabelece o objeto de conjunto de registros como um buffer de edição que contém as colunas do primeiro registro.  
  
-   O conjunto de registros executa a instrução SQL e a fonte de dados seleciona o primeiro registro. Colunas do registro serão carregadas em membros de dados de campo do conjunto de registros.  
  
 A tabela a seguir mostra a sequência de operações RFX quando você abrir um conjunto de registros.  
  
### <a name="_core_sequence_of_rfx_operations_during_recordset_open"></a>Sequência de operações RFX durante a abertura do conjunto de registros  
  
|A operação|Operação de DoFieldExchange|Operação de banco de dados/SQL|  
|--------------------|-------------------------------|-----------------------------|  
|1. Abra o conjunto de registros.|||  
||2. Crie uma instrução SQL.||  
|||3. Envie o comando SQL.|  
||4. Membros de dados do parâmetro de associação.||  
||5. Associe as colunas de membros de dados do campo.||  
|||6. ODBC faz a movimentação e preenche os dados.|  
||7. Corrigi os dados para C++.||  
  
 Conjuntos de registros usam execução preparada do ODBC para permitir a rápida repetir a consulta com a mesma instrução SQL. Para obter mais informações sobre a execução preparada, consulte o SDK do ODBC *referência do programador de* na biblioteca MSDN.  
  
###  <a name="_mfc_rfx.3a_.scrolling"></a>RFX: rolagem  
 Quando você rolar de um registro para outro, o framework chama `DoFieldExchange` para substituir os valores armazenados anteriormente nos membros de dados de campo com valores para o novo registro.  
  
 A tabela a seguir mostra a sequência de operações RFX quando o usuário move de registro para registro.  
  
### <a name="_core_sequence_of_rfx_operations_during_scrolling"></a>Sequência de operações RFX durante a rolagem  
  
|A operação|Operação de DoFieldExchange|Operação de banco de dados/SQL|  
|--------------------|-------------------------------|-----------------------------|  
|1. Chamar `MoveNext` ou uma das funções de movimentação.|||  
|||2. ODBC faz a movimentação e preenche os dados.|  
||3. Corrigi os dados para C++.||  
  
###  <a name="_mfc_rfx.3a_.adding_new_records_and_editing_existing_records"></a>RFX: Adicionando novos registros e editar os registros existentes  
 Se você adicionar um novo registro, o conjunto de registros funciona como um buffer de edição para criar o conteúdo do novo registro. Com a adição de registros, a edição de registros envolve alterando os valores de membros de dados de campo do conjunto de registros. Da perspectiva do RFX, a sequência é o seguinte:  
  
1.  A chamada para o conjunto de registros [AddNew](../../mfc/reference/crecordset-class.md#addnew) ou [editar](../../mfc/reference/crecordset-class.md#edit) função membro faz com que RFX armazenar o buffer de edição atual para que ele possa ser restaurado posteriormente.  
  
2.  `AddNew`ou **editar** prepara os campos no buffer de edição para RFX possa detectar membros de dados do campo alterado.  
  
     Como um novo registro não tem nenhum valor anterior para comparar novos com, `AddNew` define o valor de cada membro de dados de campo para um **PSEUDO_NULL** valor. Posteriormente, quando você chamar **atualização**, RFX compara o valor de cada membro de dados com o **PSEUDO_NULL** valor. Se houver uma diferença, o membro de dados foi definido. (**PSEUDO_NULL** não é o mesmo que uma coluna de registro com um valor Null true nem qualquer uma delas igual C++ **nulo**.)  
  
     Diferentemente de **atualização** chamar para `AddNew`, o **atualização** chamar para **editar** compara valores atualizados com os valores armazenados anteriormente em vez de usar **PSEUDO_NULL**. A diferença é que `AddNew` sem valores armazenados anteriormente para comparação.  
  
3.  Definir diretamente os valores dos membros de dados do campo cujos valores você deseja editar ou que você deseja preencher para um novo registro. Isso pode incluir a chamada `SetFieldNull`.  
  
4.  A chamada para [atualização](../../mfc/reference/crecordset-class.md#update) verifica para membros de dados de campo alterado, conforme descrito na etapa 2 (consulte a tabela [sequência de RFX operações durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling)). Se nenhum foram alterados, **atualização** retornará 0. Se alguns membros de dados do campo foi alterado, **atualização** prepara e executa um SQL **inserir** instrução que contém os valores para todos os campos atualizados no registro.  
  
5.  Para `AddNew`, **atualização** conclui restaurando os valores armazenados anteriormente do registro que era atual antes do `AddNew` chamar. Para **editar**, os valores novos e editados permanecerão em vigor.  
  
 A tabela a seguir mostra a sequência de operações RFX quando você adiciona um novo registro ou editar um registro existente.  
  
### <a name="sequence-of-rfx-operations-during-addnew-and-edit"></a>Sequência de operações RFX durante AddNew e editar  
  
|A operação|Operação de DoFieldExchange|Operação de banco de dados/SQL|  
|--------------------|-------------------------------|-----------------------------|  
|1. Chamar `AddNew` ou **editar**.|||  
||2. Fazer backup de buffer de edição.||  
||3. Para `AddNew`, marcar membros de dados do campo como "limpeza" e Null.||  
|4. Atribua valores para membros de dados de campo do conjunto de registros.|||  
|5. Chamar **atualização**.|||  
||6. Verifique se há campos alterados.||  
||7. Criar SQL **inserir** instrução `AddNew` ou **atualização** instrução **editar**.||  
|||8. Envie o comando SQL.|  
||9. Para `AddNew`, restaure o buffer de edição para seu conteúdo de backup. Para **editar**, exclua o backup.||  
  
### <a name="rfx-deleting-existing-records"></a>RFX: Excluindo os registros existentes  
 Quando você exclui um registro, RFX define todos os campos **nulo** como um lembrete de que o registro será excluído e você deve mover dela. Outras informações de sequência RFX não é necessário.  
  
## <a name="see-also"></a>Consulte também  
 [Registrar troca de campos (RFX)](../../data/odbc/record-field-exchange-rfx.md)   
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)  
 [Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)   
 [CRecordset::DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange)