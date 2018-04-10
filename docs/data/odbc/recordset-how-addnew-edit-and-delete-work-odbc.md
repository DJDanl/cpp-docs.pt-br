---
title: 'Conjunto de registros: Como AddNew, editar e excluir trabalham (ODBC) | Microsoft Docs'
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
- records [C++], updating
- record editing [C++], in recordsets
- recordsets [C++], adding records
- records [C++], adding
- ODBC recordsets [C++], adding records
- recordsets [C++], editing records
- recordsets [C++], updating
- AddNew method
- ODBC recordsets [C++], deleting records
- records [C++], deleting in recordsets
- data in recordsets [C++]
- recordsets [C++], deleting records
- ODBC recordsets [C++], editing records
- records [C++], editing
ms.assetid: cab43d43-235a-4bed-ac05-67d10e94f34e
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: dbbf224797bd7d2eed2b085a6a7dd8eb1865de1c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recordset-how-addnew-edit-and-delete-work-odbc"></a>Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica como o `AddNew`, **editar**, e **excluir** funções membro de classe `CRecordset` de trabalho. Os tópicos abordados incluem:  
  
-   [Como adicionar registros funciona](#_core_adding_a_record)  
  
-   [Visibilidade de registros adicionados](#_core_visibility_of_added_records)  
  
-   [Como funciona a edição de registros](#_core_editing_an_existing_record)  
  
-   [Como excluir registros funciona](#_core_deleting_a_record)  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Como um suplemento, talvez você queira ler [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md), que descreve a função correspondente de RFX em operações de atualização.  
  
##  <a name="_core_adding_a_record"></a>Adicionar um registro  

 Adicionar um novo registro para um conjunto de registros envolve chamando o conjunto de registros [AddNew](../../mfc/reference/crecordset-class.md#addnew) função de membro, definir os valores campo do registro novo membros de dados e, em seguida, chamar o [atualização](../../mfc/reference/crecordset-class.md#update) função de membro para gravação o registro para a fonte de dados.  
  
 Como uma pré-condição para chamar `AddNew`, o conjunto de registros deve não ter sido aberto como somente leitura. O `CanUpdate` e `CanAppend` funções de membro permite que você determine essas condições.  
  
 Quando você chama `AddNew`:  
  
-   O registro no buffer de edição é armazenado, seu conteúdo pode ser restaurado se a operação foi cancelada.  
  
-   Os membros de dados do campo são sinalizados portanto, é possível detectar alterações em-los mais tarde. Os dados também são membros do campo Limpar (inalterados) e definido como um valor nulo.  
  
 Depois de chamar `AddNew`, o buffer de edição representa um novo, vazio registro, pronto para ser preenchido com valores. Para fazer isso, você definir manualmente os valores, atribuindo a eles. Em vez de especificar um valor de dados reais de um campo, você pode chamar `SetFieldNull` para especificar o valor Null.  
  
 Para confirmar suas alterações, você deve chamar **atualização**. Quando você chama **atualização** para o novo registro:  
  
-   Se o driver ODBC oferece suporte a **:: SQLSetPos** função de API de ODBC MFC usa a função para adicionar o registro na fonte de dados. Com **:: SQLSetPos**, MFC pode adicionar um registro com mais eficiência porque ele não tem que criar e processar uma instrução SQL.  
  
-   Se **:: SQLSetPos** não pode ser usado, MFC faz o seguinte:  
  
    1.  Se nenhuma alteração for detectada, **atualização** não faz nada e retornará 0.  
  
    2.  Se houver alterações, **atualização** constrói um SQL **inserir** instrução. As colunas representadas por todos os membros de dados do campo sujas são listadas no **inserir** instrução. Para forçar uma coluna a ser incluído, chame o [SetFieldDirty](../../mfc/reference/crecordset-class.md#setfielddirty) função de membro:  
  
        ```  
        SetFieldDirty( &m_dataMember, TRUE );  
        ```  
  
    3.  **Atualização** confirma o novo registro — o **inserir** instrução é executada e o registro é confirmado para a tabela na fonte de dados (e o conjunto de registros, se não um instantâneo), a menos que uma transação está em andamento.  
  
    4.  O registro armazenado será restaurado para o buffer de edição. O registro atual antes do `AddNew` chamada é atual novamente, independentemente se o **inserir** instrução foi executada com êxito.  
  
    > [!TIP]
    >  Para obter controle total de um novo registro, usar a seguinte abordagem: definir os valores de todos os campos que têm valores e, em seguida, defina explicitamente todos os campos que serão sempre Null chamando `SetFieldNull` com um ponteiro para o campo e o parâmetro **TRUE**  (o padrão). Se você deseja garantir que um campo não é gravado para a fonte de dados, chamada `SetFieldDirty` com um ponteiro para o campo e o parâmetro **FALSE**e não modifique o valor do campo. Para determinar se um campo pode ser Null, chame `IsFieldNullable`.  
  
    > [!TIP]
    >  Para detectar quando o valor de alterar membros de dados do conjunto de registros, MFC usa um **PSEUDO_NULL** valor apropriado para cada tipo de dados que você pode armazenar em um conjunto de registros. Se você deve definir explicitamente um campo o **PSEUDO_NULL** valor e o campo já acontece seja marcado como Null, você também deve chamar `SetFieldNull`, passando o endereço do campo no primeiro parâmetro e **FALSE**no segundo parâmetro.  
  
##  <a name="_core_visibility_of_added_records"></a>Visibilidade de registros adicionados  
 Quando um registro adicional é visível para o conjunto de registros? Registros adicionados às vezes aparecem e, às vezes, não são visíveis, dependendo de duas coisas:  
  
-   O driver que é capaz de.  
  
-   O que a estrutura pode aproveitar.  
  
 Se o driver ODBC oferece suporte a **:: SQLSetPos** função de API de ODBC MFC usa a função para adicionar registros. Com **:: SQLSetPos**, adicionados registros são visíveis para qualquer conjunto de registros do MFC atualizável. Sem suporte para a função, adicionados registros não são visíveis, e você deve chamar **Requery** para vê-los. Usando **:: SQLSetPos** também é mais eficiente.  
  
##  <a name="_core_editing_an_existing_record"></a>Edição de um registro existente  
 Editar um registro existente em um conjunto de registros envolve a rolagem para o registro, chamando o conjunto de registros [editar](../../mfc/reference/crecordset-class.md#edit) função de membro, definir os valores campo do registro novo membros de dados e, em seguida, chamar o [atualizar](../../mfc/reference/crecordset-class.md#update)função de membro para gravar o registro alterado para a fonte de dados.  
  
 Como uma pré-condição para chamar **editar**, o conjunto de registros deve ser atualizável e em um registro. O `CanUpdate` e `IsDeleted` funções de membro permite que você determine essas condições. O registro atual também deve não já ter sido excluído, e deve haver registros no conjunto de registros (ambos `IsBOF` e `IsEOF` retornam 0).  
  
 Quando você chama **editar**, o registro no buffer de edição (o registro atual) é armazenado. Os valores do registro armazenado posteriormente são usados para detectar se todos os campos foram alterados.  
  
 Depois de chamar **editar**, o buffer de edição ainda representa o registro atual, mas agora está pronto para aceitar as alterações para os membros de dados do campo. Para alterar o registro, você definir manualmente os valores de quaisquer membros de dados de campo que você deseja editar. Em vez de especificar um valor de dados reais de um campo, você pode chamar `SetFieldNull` para especificar o valor Null. Para confirmar suas alterações, chame **atualização**.  
  
> [!TIP]
>  Para tirar proveito do `AddNew` ou **editar** modo, chamada **mover** com o parâmetro **AFX_MOVE_REFRESH**.  
  
 Como uma pré-condição para chamar **atualização**, o conjunto de registros não pode estar vazio e o registro atual não tenham sido excluído. `IsBOF`, `IsEOF`, e `IsDeleted` todos devem retornar 0.  
  
 Quando você chama **atualização** do Registro editado:  
  
-   Se o driver ODBC oferece suporte a **:: SQLSetPos** função de API de ODBC MFC usa a função para atualizar o registro na fonte de dados. Com **:: SQLSetPos**, o driver compara seu buffer de edição com o registro correspondente no servidor, atualizar o registro no servidor se os dois são diferentes. Com **:: SQLSetPos**, MFC pode atualizar um registro com mais eficiência porque ele não tem que criar e processar uma instrução SQL.  
  
     -ou-  
  
-   Se **:: SQLSetPos** não pode ser usado, MFC faz o seguinte:  
  
    1.  Se não houve nenhuma alteração, **atualização** não faz nada e retornará 0.  
  
    2.  Se houver alterações, **atualização** constrói um SQL **atualização** instrução. As colunas listadas no **atualização** instrução são com base nos membros de dados de campo que foram alterados.  
  
    3.  **Atualização** confirma as alterações — executa o **atualização** instrução — e o registro é alterado na fonte de dados, mas não confirmada se uma transação está em andamento (consulte [transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md) para obter informações sobre como a transação afeta a atualização). ODBC mantém uma cópia do registro, também será alterado.  
  
    4.  Ao contrário do processo para `AddNew`, o **editar** processo não restaura o registro armazenado. O registro editado permanece no local como o registro atual.  
  
    > [!CAUTION]
    >  Quando você se prepara para atualizar um conjunto de registros chamando **atualizar**, lembre-se que o conjunto de registros inclui todas as colunas que compõem a chave primária da tabela (ou todas as colunas de qualquer exclusivo de índice na tabela ou colunas suficientes para exclusivamente identificar a linha). Em alguns casos, a estrutura pode usar somente as colunas selecionadas em seu conjunto de registros para identificar qual registro na tabela para atualizar. Sem todas as colunas necessárias, vários registros poderão ser atualizados na tabela. Nesse caso, o framework lança exceções ao chamar **atualização**.  
  
    > [!TIP]
    >  Se você chamar `AddNew` ou **editar** depois de ter chamado a qualquer função anteriormente, mas antes de chamar **atualização**, o buffer de edição é atualizado com o registro armazenado, substituindo o registro de novo ou editado no progresso. Esse comportamento fornece uma maneira para anular uma `AddNew` ou **editar** e iniciar uma nova: se você determinar que o registro em andamento está com defeito, simplesmente chamar **editar** ou `AddNew` novamente.  
  
##  <a name="_core_deleting_a_record"></a>Excluindo um registro  
 Excluir um registro de um conjunto de registros envolve a rolagem para o registro e chamando o conjunto de registros [excluir](../../mfc/reference/crecordset-class.md#delete) função de membro. Ao contrário de `AddNew` e **editar**, **excluir** não requer uma chamada correspondente para **atualização**.  
  
 Como uma pré-condição para chamar **excluir**, o conjunto de registros deve ser atualizável e ele deve estar em um registro. O `CanUpdate`, `IsBOF`, `IsEOF`, e `IsDeleted` funções de membro permite que você determine essas condições.  
  
 Quando você chama **excluir**:  
  
-   Se o driver ODBC oferece suporte a **:: SQLSetPos** função de API de ODBC MFC usa a função para excluir o registro na fonte de dados. Usando **:: SQLSetPos** é geralmente mais eficiente do que usando o SQL.  
  
     -ou-  
  
-   Se **:: SQLSetPos** não pode ser usado, MFC faz o seguinte:  
  
    1.  O registro atual no buffer de edição não é feito como em `AddNew` e **editar**.  
  
    2.  **Excluir** constrói um SQL **excluir** instrução que remove o registro.  
  
         O registro atual no buffer de edição não é armazenado como em `AddNew` e **editar**.  
  
    3.  **Excluir** confirma a exclusão — executa o **excluir** instrução. O registro é marcado como excluído na fonte de dados e, se o registro é um instantâneo, no ODBC.  
  
    4.  Os valores do registro excluído ainda estão em membros de dados de campo do conjunto de registros, mas os membros de dados do campo marcado como Null e o conjunto de registros `IsDeleted` função membro retorna um valor diferente de zero.  
  
    > [!NOTE]
    >  Depois de excluir um registro, você deve rolar para outro registro para preencher novamente o buffer de edição com os novos dados do registro. Erro ao chamar **excluir** novamente ou chamar **editar**.  
  
 Para obter informações sobre as instruções SQL usado em operações de atualização, consulte [SQL](../../data/odbc/sql.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md)   
 [RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)