---
title: "Registrar troca de campos: como funciona RFX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "associação de dados [C++], DFX"
  - "ODBC [C++], RFX"
  - "edição de registros [C++], usando RFX"
  - "RFX (ODBC) [C++], associando campos e parâmetros"
  - "RFX (ODBC) [C++], atualizando dados em conjuntos de registros"
  - "rolagem [C++]"
  - "rolagem [C++], RFX"
ms.assetid: e647cacd-62b0-4b80-9e20-b392deca5a88
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrar troca de campos: como funciona RFX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica o processo de RFX.  Essa é uma cobertura avançada do tópico:  
  
-   [RFX e o conjunto de registros](#_core_rfx_and_the_recordset)  
  
-   [O processo de RFX](#_core_the_record_field_exchange_process)  
  
> [!NOTE]
>  Este tópico se aplicam às classes derivadas de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, a troca do campo de registro em massa \(RFX em massa\) é implementada.  RFX em massa é semelhante a RFX.  Para entender as diferenças, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
##  <a name="_core_rfx_and_the_recordset"></a> RFX e o conjunto de registros  
 Os membros de dados do campo do objeto do conjunto de registros, que, juntos constituem um buffer da edição do que contém as colunas selecionadas de um registro.  Quando o conjunto de registros primeiro é aberto e é aproximadamente ler o primeiro registro, RFX associa \(\) associados a cada coluna selecionada para o endereço do membro de dados apropriado do campo.  Quando o conjunto de registros atualiza um registro, RFX chama funções API ODBC para enviar o SQL **ATUALIZAR** ou a instrução de **INSERIR** para o driver.  RFX usa o conhecimento dos membros de dados do campo para especificar as colunas para gravação.  
  
 A estrutura faz backup do buffer de edição em determinadas etapas para que possa restaurar seu conteúdo se necessário.  RFX faz backup do buffer de edição antes de adicionar um novo registro e antes de editar um registro existente.  Restaura o buffer de edição em alguns casos, por exemplo, depois de uma chamada de **Atualizar** depois de `AddNew`.  O buffer de edição não é restaurado se você abandona um buffer por recentemente alterado de edição, por exemplo, se mover para outro registro antes de chamar **Atualizar**.  
  
 Além dos dados de troca entre a fonte de dados e os membros de dados do campo do conjunto de registros, RFX gerencia associando parâmetros.  Quando o conjunto de registros é aberto, todos os membros de dados do parâmetro são associados em ordem de “?” os espaços reservados na instrução SQL que `CRecordset::Open` constrói.  Para obter mais informações, consulte [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
 A substituição da sua classe do conjunto de registros de `DoFieldExchange` executa qualquer trabalho, mover dados nas duas direções.  Como a caixa de diálogo de troca de dados \(DDX\), RFX precisa informações sobre os membros de dados da classe.  O assistente fornecem as informações necessárias para escrever uma implementação conjunto de registros\- específica de `DoFieldExchange` para você, com base nos nomes de membro de dados do campo e os tipos de dados que você especifica no assistente.  
  
##  <a name="_core_the_record_field_exchange_process"></a> Processo do Exchange do campo de registro  
 Esta seção descreve a sequência de eventos de RFX como um objeto do conjunto de registros é aberto e à medida que você adiciona, atualizar e excluir registros.  A tabela [Sequência de operações de RFX durante o conjunto de registros Abrir](#_core_sequence_of_rfx_operations_during_recordset_open) e a tabela [Sequência de operações de RFX durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling) neste tópico mostram como o processo RFX processa um comando de **Mover** no conjunto de registros e como RFX gerencia uma atualização.  Durante esses processos, [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) é chamado para executar muitas operações diferentes.  O membro de dados de **m\_nOperation** do objeto de [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) determina qual operação é solicitada.  Você pode achar útil ler [Conjunto de registros: Como os conjuntos de registros selecione os registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md) e [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) antes de ler este hardware.  
  
###  <a name="_mfc_rfx.3a_.initial_binding_of_columns_and_parameters"></a> RFX: Associação inicial de colunas e parâmetros  
 As seguintes atividades de RFX ocorrerem, na ordem mostrada, quando você chama a função de membro de [Abrir](../Topic/CRecordset::Open.md) de um objeto do conjunto de registros:  
  
-   Se o conjunto de registros tem membros de dados do parâmetro, a estrutura chama `DoFieldExchange` para associar os parâmetros em espaços reservados de parâmetros na cadeia de caracteres da instrução SQL do conjunto de registros.  Uma representação dependentes de classificação dos dados do valor do parâmetro é usada para cada espaço reservado localizado na instrução de **SELECIONAR** .  Isto ocorre depois da instrução SQL está preparada mas antes que seja executada.  Para obter informações sobre preparação de instrução, consulte a função de **::SQLPrepare***na referência do programador*de ODBC.  
  
-   A estrutura chama `DoFieldExchange` uma segunda vez associar os valores das colunas selecionadas para membros de dados correspondentes do campo no conjunto de registros.  Isso estabelece o objeto do conjunto de registros como um buffer da edição do que contém as colunas do primeiro registro.  
  
-   O conjunto de registros executa a instrução SQL e a fonte de dados seleciona o primeiro registro.  As colunas do registro são carregadas nos membros de dados do campo do conjunto de registros.  
  
 A tabela a seguir mostra a sequência de operações de RFX quando você abre um conjunto de registros.  
  
### Sequência de operações de RFX durante o conjunto de registros Abrir  
  
|Sua operação|Operação de DoFieldExchange|Operação do Database\/SQL|  
|------------------|---------------------------------|-------------------------------|  
|1.  Conjunto de registros aberto.|||  
||2.  Compilar uma instrução SQL.||  
|||3.  Enviar SQL.|  
||4.  Membros de dados do parâmetro de associação.||  
||5.  Membros de dados do campo de associação para as colunas.||  
|||6.  ODBC faz a movimentação e preenche os dados.|  
||7.  Corrigir os dados acima para C\+\+.||  
  
 A execução preparada ODBC do uso de conjuntos de registros para permitir e rápido com a mesma instrução SQL.  Para obter mais informações sobre a execução preparada, consulte *a referência do programador* de ODBC o SDK na Biblioteca MSDN.  
  
###  <a name="_mfc_rfx.3a_.scrolling"></a> RFX: Navegação  
 Quando você percorrer de um registro outro, a estrutura chama `DoFieldExchange` para substituir os valores armazenados anteriormente nos membros de dados do campo com os valores do registro novo.  
  
 A tabela a seguir mostra a sequência de operações de RFX quando o usuário se move do registro ao registro.  
  
### Sequência de operações de RFX durante a rolagem  
  
|Sua operação|Operação de DoFieldExchange|Operação do Database\/SQL|  
|------------------|---------------------------------|-------------------------------|  
|1.  Chame `MoveNext` ou um do outro funções de movimentação.|||  
|||2.  ODBC faz a movimentação e preenche os dados.|  
||3.  Corrigir os dados acima para C\+\+.||  
  
###  <a name="_mfc_rfx.3a_.adding_new_records_and_editing_existing_records"></a> RFX: Adicionando novos registros e editar registros existentes  
 Se você adicionar um novo registro, o conjunto de registros opera como um buffer de edição para acumular os conteúdos do registro novo.  Como registros com adicionar, editar registros envolve alterar os valores dos membros de dados do campo do conjunto de registros.  Da perspectiva de RFX, a sequência é a seguinte:  
  
1.  Sua chamada para faz RFX da função de membro de [AddNew](../Topic/CRecordset::AddNew.md) ou de [Edição](../Topic/CRecordset::Edit.md) do conjunto de registros o armazena o buffer atual de modo que a edição pode ser restaurado posteriormente.  
  
2.  `AddNew` ou **Editar** preparar os campos no buffer de edição assim que RFX pode detectar membros de dados alterados do campo.  
  
     Como um novo registro não tem nenhum valor anterior para comparar com novos, `AddNew` define o valor de cada membro de dados do campo para um valor de **PSEUDO\_NULL** .  Posteriormente, quando você chama **Atualizar**, RFX compara o valor de cada membro de dados com o valor de **PSEUDO\_NULL** .  Se houver uma diferença, o membro de dados esteve definido. \(**PSEUDO\_NULL** não é igual à coluna do registro com um valor nulo é verdadeiro ou qualquer uma delass o mesmo que **nulo**C\+\+\).  
  
     Ao contrário de chamada de **Atualizar** para `AddNew`, a chamada de **Atualizar** para **Editar** compara valores atualizados com os valores previamente armazenados em vez de usar **PSEUDO\_NULL**.  A diferença é que `AddNew` não tem nenhum valor armazenado anteriormente para comparação.  
  
3.  Você define diretamente os valores dos membros de dados do campo cujos valores você deseja editar ou que você deseja preenchido para um novo registro.  Isso pode incluir chamar `SetFieldNull`.  
  
4.  Sua chamada a verificações de [Atualização](../Topic/CRecordset::Update.md) para membros de dados alterados do campo, conforme descrito na etapa 2 \(consulte a tabela [Sequência de operações de RFX durante a rolagem](#_core_sequence_of_rfx_operations_during_scrolling)\).  Se nenhum for alterado, retorna 0 de **Atualizar** .  Se alguns membros de dados do campo for alterado, **Atualizar** prepara e executa uma instrução SQL **INSERIR** que contém valores para todos os campos atualizados no registro.  
  
5.  Para `AddNew`, **Atualizar** concluiu restaurando os valores previamente armazenados do registro que esteve atual antes da chamada de `AddNew` .  Para **Editar**, os novos valores, editados permanecem no local.  
  
 A tabela a seguir mostra a sequência de operações de RFX quando você adiciona um novo registro ou editar um registro existente.  
  
### Sequência de operações de RFX durante AddNew e edição  
  
|Sua operação|Operação de DoFieldExchange|Operação do Database\/SQL|  
|------------------|---------------------------------|-------------------------------|  
|1.  Chame `AddNew` ou **Editar**.|||  
||2.  Fazer backup do buffer de edição.||  
||3.  Para `AddNew`, marque membros de dados do campo como” e “limpar zero.||  
|4.  Atribuir valores aos membros de dados do campo do conjunto de registros.|||  
|5.  Chame **Atualizar**.|||  
||6.  Verificação de campos alterados.||  
||7.  Crie a instrução do SQL **INSERIR** para `AddNew` ou a instrução de **ATUALIZAR** para **Editar**.||  
|||8.  Enviar SQL.|  
||9.  Para `AddNew`, restaure o buffer de edição ao seu conteúdo com suporte.  Para **Editar**, exclua o backup.||  
  
### RFX: Excluindo registros existentes  
 Quando você exclui um registro, RFX define todos os campos a **nulo** como um lembrete que o registro será excluído e você deve mover fora delas.  Você não precisa nenhuma outra informação de sequência de RFX.  
  
## Consulte também  
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)   
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Macros, funções globais e variáveis globais](../Topic/Macros,%20Global%20Functions,%20and%20Global%20Variables.md)   
 [Classe de CFieldExchange](../../mfc/reference/cfieldexchange-class.md)   
 [CRecordset::DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md)