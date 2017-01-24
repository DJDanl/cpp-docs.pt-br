---
title: "Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC) | Microsoft Docs"
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
  - "Método AddNew"
  - "dados em conjuntos de registros [C++]"
  - "conjuntos de registros ODBC [C++], adicionando registros"
  - "conjuntos de registros ODBC [C++], excluindo registros"
  - "conjuntos de registros ODBC [C++], editando registros"
  - "edição de registros [C++], em conjunto de registros"
  - "registros [C++], adicionando"
  - "registros [C++], excluindo em conjuntos de registros"
  - "registros [C++], edição"
  - "registros [C++], atualizando"
  - "conjunto de registros [C++], adicionando registros"
  - "conjunto de registros [C++], excluindo registros"
  - "conjunto de registros [C++], editando registros"
  - "conjunto de registros [C++], atualizando"
ms.assetid: cab43d43-235a-4bed-ac05-67d10e94f34e
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como `AddNew`, **Editar**, e as funções de membro de **Excluir** da classe `CRecordset` funcionam.  Os tópicos abordados incluem:  
  
-   [Como adicionar registra Works](#_core_adding_a_record)  
  
-   [Visibilidade de registros adicionados](#_core_visibility_of_added_records)  
  
-   [Como editar registra Works](#_core_editing_an_existing_record)  
  
-   [Como a exclusão registra Works](#_core_deleting_a_record)  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Como um suplemento do, talvez você queira ler [Exchange campo do registro: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md), que descreve a função correspondente de RFX em operações de atualização.  
  
##  <a name="_core_adding_a_record"></a> Adicionando um registro  
 Adicionar um novo registro para um conjunto de registros envolve chamar a função de membro de [AddNew](../Topic/CRecordset::AddNew.md) do conjunto de registros, definindo os valores dos membros de dados do campo de registro novo, e chame a função de membro de [Atualização](../Topic/CRecordset::Update.md) gravar um registro à fonte de dados.  
  
 Como um pré\-requisito para chamar `AddNew`, o conjunto de registros não deve ter sido aberto como somente leitura.  As funções de membro de `CanUpdate` e de `CanAppend` permitem determinar essas condições.  
  
 Quando você chamar `AddNew`:  
  
-   O registro no buffer de edição é armazenado, de modo que seu conteúdo pode ser restaurados se a operação será cancelada.  
  
-   Os membros de dados do campo for sinalizado para que seja possível detectar alterações posteriormente nelas.  Os membros de dados do campo são limpos \(sem alteração\) e ajustados também marcados a um nulo.  
  
 Depois de chamar `AddNew`, o buffer de edição representa um novo registro, vazio, pronto para ser preenchida com valores.  Para fazer isso, você definir manualmente os valores atribuindo a eles.  Em vez de especificar um valor de dados real para um campo, você pode chamar `SetFieldNull` para especificar o valor de zero.  
  
 Para confirmar suas alterações, chame **Atualizar**.  Quando você chamar **Atualizar** para o novo registro:  
  
-   Se o driver ODBC da suporte à função de API ODBC de **::SQLSetPos** MFC, o usa a função para adicionar o registro na fonte de dados.  Com **::SQLSetPos**, o MFC pode adicionar um registro com mais eficácia porque não precisa criar e processar uma instrução SQL.  
  
-   Se **::SQLSetPos** não pode ser usado, o MFC faz o seguinte:  
  
    1.  Se nenhuma mudança for detectada, **Atualizar** não fará nada e retorna 0.  
  
    2.  Se houver alterações, **Atualizar** constrói uma instrução SQL **INSERIR** .  As colunas representadas por todos os membros de dados sujos do campo são listadas na instrução de **INSERIR** .  Para forçar uma coluna a ser incluída, chame a função de membro de [SetFieldDirty](../Topic/CRecordset::SetFieldDirty.md) :  
  
        ```  
        SetFieldDirty( &m_dataMember, TRUE );  
        ```  
  
    3.  **Atualizar** confirma o novo registro — a instrução de **INSERIR** é executada e o registro é confirmado a tabela da fonte de dados \(e o conjunto de registros, se não for um instantâneo\) a menos que uma transação está em andamento.  
  
    4.  O registro armazenado é restaurado ao buffer de edição.  O registro que era atual antes da chamada de `AddNew` atual foi novamente independentemente da instrução de **INSERIR** esteve executada com êxito.  
  
    > [!TIP]
    >  Para controle total de um novo registro, faça a abordagem a seguir: definir os valores dos campos que tenham valores e depois definir explicitamente os campos que permaneçam nulos `SetFieldNull` chamando com um ponteiro para o campo e o parâmetro **Verdadeiro** \(o padrão\).  Se você quiser garantir que um campo não seja gravado à fonte de dados, a chamada `SetFieldDirty` com um ponteiro para o campo e o parâmetro **Falso**, e não modifique o valor do campo.  Para determinar se é permitido em um campo ser nulo, chame `IsFieldNullable`.  
  
    > [!TIP]
    >  Para detectar quando os membros de dados do conjunto de registros alteram o valor, MFC o usa um valor de **PSEUDO\_NULL** apropriada a cada tipo de dados que podem ser armazenados em um conjunto de registros.  Se você deverá definir explicitamente um campo para um valor de **PSEUDO\_NULL** e o campo acontece já esteja marcado zero, você também deve chamar `SetFieldNull`, passando o endereço do campo no primeiro parâmetro e de **Falso** no segundo parâmetro.  
  
##  <a name="_core_visibility_of_added_records"></a> Visibilidade de registros adicionados  
 Quando um registro é visível adicionado ao conjunto de registros?  Os registros adicionados às vezes aparecem e não são visíveis às vezes, dependendo das duas coisas:  
  
-   O qual o driver é capaz.  
  
-   O que a estrutura pode se beneficiar.  
  
 Se o driver ODBC da suporte à função de API ODBC de **::SQLSetPos** MFC, o usa a função para adicionar registros.  Com **::SQLSetPos**, os registros adicionados são visíveis para qualquer conjunto de registros atualizável MFC.  Sem suporte para a função, os registros adicionados não são visíveis e você deve chamar **Requery** para vê\-las.  Usar **::SQLSetPos** também é mais eficiente.  
  
##  <a name="_core_editing_an_existing_record"></a> Editando um registro existente  
 Editar um registro existente em um conjunto de registros rolar envolve o registro, chamando a função de membro de [Edição](../Topic/CRecordset::Edit.md) do conjunto de registros, definindo os valores dos membros de dados do campo de registro novo, e chame a função de membro de [Atualização](../Topic/CRecordset::Update.md) gravar um registro alterado à fonte de dados.  
  
 Como um pré\-requisito para chamar **Editar**, o conjunto de registros deve ser atualizável e um registro.  As funções de membro de `CanUpdate` e de `IsDeleted` permitem determinar essas condições.  O registro atual também não já deve ter sido excluído, e deve haver registros no conjunto de registros \( `IsBOF` e `IsEOF` retornam 0\).  
  
 Quando você chama **Editar**, o registro no buffer edition \(o registro atual\) está armazenado.  Os valores do registro armazenado são usados posteriormente para detectar se qualquer campo foi alterado.  
  
 Depois de chamar **Editar**, o buffer de edição ainda representa o registro atual mas agora está pronto para aceitar as alterações nos membros de dados do campo.  Para alterar o registro, você definir manualmente os valores de todos os membros de dados do campo que você deseja editar.  Em vez de especificar um valor de dados real para um campo, você pode chamar `SetFieldNull` para especificar o valor de zero.  Para confirmar suas alterações, chame **Atualizar**.  
  
> [!TIP]
>  Para sair de `AddNew` ou no modo de **Editar** , chame **Mover** com o parâmetro **AFX\_MOVE\_REFRESH**.  
  
 Como um pré\-requisito para chamar **Atualizar**, o conjunto de registros não deve estar vazia e o registro atual não deve ter sido excluído.  `IsBOF`, `IsEOF`, e `IsDeleted` se qualquer 0 de retorno.  
  
 Quando você chamar **Atualizar** para o registro editado:  
  
-   Se o driver ODBC da suporte à função de API ODBC de **::SQLSetPos** MFC, o usa a função para atualizar o registro na fonte de dados.  Com **::SQLSetPos**, o driver compara o buffer de edição com o registro correspondente no servidor, atualizar o registro no servidor se os dois forem diferentes.  Com **::SQLSetPos**, o MFC pode atualizar um registro com mais eficácia porque não precisa criar e processar uma instrução SQL.  
  
     \- ou \-  
  
-   Se **::SQLSetPos** não pode ser usado, o MFC faz o seguinte:  
  
    1.  Se não houver nenhuma alteração, **Atualizar** não fará nada e retorna 0.  
  
    2.  Se houver alterações, **Atualizar** constrói uma instrução SQL **ATUALIZAR** .  As colunas listadas na instrução de **ATUALIZAR** são baseadas nos membros de dados do campo que foram alterados.  
  
    3.  **Atualizar** confirma as alterações — executa a instrução de **ATUALIZAR** — e o registro é alterado na fonte de dados, mas não confirmada se uma transação estiver em andamento \(consulte [Transação: Executando uma transação em um conjunto de registros \(ODBC\)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md) para obter informações sobre como a transação afeta a atualização\).  ODBC mantém uma cópia do registro, que também muda.  
  
    4.  Ao contrário do processo para `AddNew`, o processo de **Editar** não restaura o registro armazenado.  O registro editado permanece em vigor como o registro atual.  
  
    > [!CAUTION]
    >  Quando você se prepara para atualizar um conjunto de registros chamando **Atualizar**, lembre\-se que o conjunto de registros inclui todas as colunas que constituem a chave primária da tabela \(ou todas as colunas de qualquer índice exclusivo na tabela, ou colunas suficientes para identificar a linha\).  Em alguns casos, a estrutura pode usar apenas as colunas selecionadas no conjunto de registros para identificar quais registros na tabela a ser atualizada.  Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela.  Nesse caso, a estrutura lança exceções quando você chama **Atualizar**.  
  
    > [!TIP]
    >  Se você chamar `AddNew` ou **Editar** depois que chamam a função anteriormente mas antes de chamar **Atualizar**, o buffer de edição é atualizado com o registro armazenado, substituindo o novo registro ou editado em andamento.  Esse comportamento é uma forma de `AddNew` nulo ou **Editar** e de iniciar um novo: se você verificar que o registro\-em\- progresso é defeituoso, somente chamada **Editar** ou `AddNew` novamente.  
  
##  <a name="_core_deleting_a_record"></a> Excluindo um registro  
 Excluir um registro de um conjunto de registros rolar envolve o registro e chamar a função de membro de [Excluir](../Topic/CRecordset::Delete.md) conjunto de registros.  Ao contrário de `AddNew` e de **Editar**, **Excluir** não requer uma chamada compatível a **Atualizar**.  
  
 Como um pré\-requisito para chamar **Excluir**, o conjunto de registros deve ser atualizável e deve estar em um registro.  `CanUpdate`, `IsBOF`, `IsEOF`, e as funções de membro de `IsDeleted` permitem determinar essas condições.  
  
 Quando você chamar **Excluir**:  
  
-   Se o driver ODBC da suporte à função de API ODBC de **::SQLSetPos** MFC, o usa a função para excluir o registro na fonte de dados.  Usar **::SQLSetPos** normalmente é mais eficiente que o uso do SQL.  
  
     \- ou \-  
  
-   Se **::SQLSetPos** não pode ser usado, o MFC faz o seguinte:  
  
    1.  O registro atual no buffer de edição não é feito backup como em `AddNew` e em **Editar**.  
  
    2.  **Excluir** constrói uma instrução SQL **EXCLUIR** que remove o registro.  
  
         O registro atual no buffer de edição não é armazenado como em `AddNew` e em **Editar**.  
  
    3.  **Excluir** confirmar a exclusão — executa a instrução de **EXCLUIR** .  O registro é marcado excluiu na fonte de dados e, se o registro é um instantâneo, no ODBC.  
  
    4.  Os valores do registro excluído ainda estão nos membros de dados do campo do conjunto de registros, mas os membros de dados do campo são marcados como zero e a função de membro de `IsDeleted` do conjunto de registros retorna um valor diferente de zero.  
  
    > [!NOTE]
    >  Depois de excluir um registro, você deve rolar outro registro para preencher novamente o buffer de edição com os dados de registro novo.  É um erro para chamar novamente **Excluir** ou para chamar **Editar**.  
  
 Para obter informações sobre as instruções SQL usado em operações de atualização, consulte [SQL](../../data/odbc/sql.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: mais sobre atualizações \(ODBC\)](../../data/odbc/recordset-more-about-updates-odbc.md)   
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)