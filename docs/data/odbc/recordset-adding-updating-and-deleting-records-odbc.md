---
title: "Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC) | Microsoft Docs"
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
  - "edição de registros [C++]"
  - "edição de registros [C++], em conjunto de registros"
  - "registros [C++], adicionando"
  - "registros [C++], excluindo"
  - "registros [C++], edição"
  - "registros [C++], atualizando"
  - "conjunto de registros [C++], adicionando registros"
  - "conjunto de registros [C++], excluindo registros"
  - "conjunto de registros [C++], editando registros"
  - "conjunto de registros [C++], atualizando"
ms.assetid: 760c8889-bec4-482b-a8f2-319792a6af98
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
> [!NOTE]
>  Agora você pode adicionar registros em massa mais eficiente.  Para obter mais informações, consulte [Conjunto de registros: Adicionando registros em massa \(ODBC\)](../../data/odbc/recordset-adding-records-in-bulk-odbc.md).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Os instantâneos e os dynasets atualizáveis permitem adicionar, editar \(atualização\), e exclui registros.  Este tópico explica:  
  
-   [Como determinar se o conjunto de registros é atualizável](#_core_determining_whether_your_recordset_is_updatable).  
  
-   [Como adicionar um novo registro](#_core_adding_a_record_to_a_recordset).  
  
-   [Como editar um registro existente](#_core_editing_a_record_in_a_recordset).  
  
-   [Como excluir um registro](#_core_deleting_a_record_from_a_recordset).  
  
 Para obter mais informações sobre como as atualizações são mantidas e como as atualizações são exibidas a outros usuários, consulte [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  Normalmente, quando você adicionar, editar, excluir ou um registro, as alterações do conjunto de registros a fonte de dados imediatamente.  Você pode então processar em lotes grupos de atualizações relacionadas de transações.  Se uma transação estiver em andamento, a atualização não se torna final até que você confirme a transação.  Isso permite que você faça novamente ou reverta as alterações.  Para obter informações sobre transações, consulte [Transações \(ODBC\)](../../data/odbc/transaction-odbc.md).  
  
 A tabela a seguir resume as opções disponíveis para conjuntos de registros com características diferentes de atualização.  
  
### Conjunto de registros ler\/opções de atualização  
  
|Tipo|Ler|Registro de edição|Excluir registro|Adicionar novo \(adicionar\)|  
|----------|---------|------------------------|----------------------|----------------------------------|  
|Somente leitura|Y|N|N|N|  
|Somente de acréscimo|Y|N|N|Y|  
|Completamente atualizável|Y|Y|Y|Y|  
  
##  <a name="_core_determining_whether_your_recordset_is_updatable"></a> Determinando se o conjunto de registros é Atualizável  
 Um objeto do conjunto de registros é atualizável se a fonte de dados pode ser atualizado e você abriu o conjunto de registros como atualizáveis.  Seu updateability depende também da instrução SQL usada, os recursos do driver ODBC e, se a biblioteca de cursores ODBC estiver na memória.  Você não pode atualizar um conjunto de registros ou uma fonte de dados somente leitura.  
  
#### Para determinar se o conjunto de registros é atualizável  
  
1.  Chame a função de membro de [CanUpdate](../Topic/CRecordset::CanUpdate.md) do objeto do conjunto de registros.  
  
     `CanUpdate` retorna um valor diferente de zero se o conjunto de registros é atualizável.  
  
 Por padrão, os conjuntos de registros são completamente atualizável \(você pode executar `AddNew`, **Editar**, e operações de **Excluir** \).  Mas você também pode usar a opção de [appendOnly](../Topic/CRecordset::Open.md) abrir os conjuntos de registros atualizável.  Um conjunto de registros abriu essa maneira permite apenas a adição de novos registros com `AddNew`.  Você não pode editar ou excluir registros existentes.  Você pode testar se um conjunto de registros é aberto somente para acrescentar chamando a função de membro de [CanAppend](../Topic/CRecordset::CanAppend.md) .  `CanAppend` retorna um valor diferente de zero se o conjunto de registros é completamente atualizado ou aberto somente para acrescentar.  
  
 O código a seguir mostra como você pode usar `CanUpdate` para um objeto do conjunto de registros chamado `rsStudentSet`:  
  
```  
if( !rsStudentSet.Open( ) )  
    return FALSE;  
if( !rsStudentSet.CanUpdate( ) )  
{  
    AfxMessageBox( "Unable to update the Student recordset." );  
    return;  
}  
```  
  
> [!CAUTION]
>  Quando você se prepara para atualizar um conjunto de registros chamando **Atualizar**, lembre\-se que o conjunto de registros inclui todas as colunas que constituem a chave primária da tabela \(ou todas as colunas de qualquer índice exclusivo na tabela\).  Em alguns casos, a estrutura pode usar apenas as colunas selecionadas no conjunto de registros para identificar quais registros na tabela a ser atualizada.  Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela, corrompendo possivelmente a integridade referencial da tabela.  Nesse caso, a estrutura lança exceções quando você chama **Atualizar**.  
  
##  <a name="_core_adding_a_record_to_a_recordset"></a> Adicionando um registro em um conjunto de registros  
 Você pode adicionar novos registros em um conjunto de registros se sua função de membro de [CanAppend](../Topic/CRecordset::CanAppend.md) retorna um valor diferente de zero.  
  
#### Para adicionar um novo registro para um conjunto de registros  
  
1.  Verifique se o conjunto de registros é appendable.  
  
2.  Chame a função de membro de [AddNew](../Topic/CRecordset::AddNew.md) do objeto do conjunto de registros.  
  
     `AddNew` prepara o conjunto de registros para atuar como um buffer de edição.  Todos os membros de dados do campo são definidos como zero do valor especial e marcados como sujos de forma que apenas valores \(\) alterados inalteradas são gravados na fonte de dados quando você chama [Atualização](../Topic/CRecordset::Update.md).  
  
3.  Definir os valores dos membros de dados do campo de registro novo.  
  
     Atribuir valores aos membros de dados do campo.  As que você não atribuir não são gravados na fonte de dados.  
  
4.  Chame a função de membro de **Atualizar** do objeto do conjunto de registros.  
  
     **Atualizar** conclui a adição do gravando novo registro à fonte de dados.  Para obter informações sobre como acontece se você não chama **Atualizar**, consulte [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
 Para obter informações sobre como adicionar registra trabalhos e sobre quando os registros adicionados são visíveis no conjunto de registros, consulte [Conjunto de registros: Como AddNew, edição e, trabalho de exclusão \(ODBC\)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md).  
  
 O exemplo a seguir mostra como adicionar um novo registro:  
  
```  
if( !rsStudent.Open( ) )  
    return FALSE;  
if( !rsStudent.CanAppend( ) )  
    return FALSE;                      // no field values were set  
rsStudent.AddNew( );  
rsStudent.m_strName = strName;  
rsStudent.m_strCity = strCity;  
rsStudent.m_strStreet = strStreet;  
if( !rsStudent.Update( ) )  
{  
    AfxMessageBox( "Record not added; no field values were set." );  
    return FALSE;  
}  
```  
  
> [!TIP]
>  Para cancelar uma chamada de `AddNew` ou de **Editar** , execute apenas outra chamada para `AddNew` ou a **Editar** ou chame **Mover** com o parâmetro de **AFX\_MOVE\_REFRESH** .  Os membros de dados são redefinidos para os valores anteriores e você ainda estão em **Editar** ou do modo de **Adicionar** .  
  
##  <a name="_core_editing_a_record_in_a_recordset"></a> Editando um registro em um conjunto de registros  
 Você pode editar registros existentes se a função de membro de [CanUpdate](../Topic/CRecordset::CanUpdate.md) do conjunto de registros retorna um valor diferente de zero.  
  
#### Para editar um registro existente em um conjunto de registros  
  
1.  Verifique se o conjunto de registros é atualizável.  
  
2.  Role ao registro que você deseja atualizar.  
  
3.  Chame a função de membro de [Edição](../Topic/CRecordset::Edit.md) do objeto do conjunto de registros.  
  
     **Editar** prepara o conjunto de registros para atuar como um buffer de edição.  Todos os membros de dados do campo são marcados de modo que o conjunto de registros pode informar posteriormente se foram alterados.  Os novos valores para membros de dados alterados do campo são gravados na fonte de dados quando você chama [Atualização](../Topic/CRecordset::Update.md).  
  
4.  Definir os valores dos membros de dados do campo de registro novo.  
  
     Atribuir valores aos membros de dados do campo.  As que você não atribuir valores permanecem inalterados.  
  
5.  Chame a função de membro de **Atualizar** do objeto do conjunto de registros.  
  
     **Atualizar** concluir a edição do gravando registro alterado à fonte de dados.  Para obter informações sobre como acontece se você não chama **Atualizar**, consulte [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
 Depois que você edita um registro, o registro permanece editado o registro atual.  
  
 O exemplo a seguir mostra uma operação de **Editar** .  Assumir o usuário movê\-lo para um registro ou deseja editar.  
  
```  
rsStudent.Edit( );  
rsStudent.m_strStreet = strNewStreet;  
rsStudent.m_strCity = strNewCity;  
rsStudent.m_strState = strNewState;  
rsStudent.m_strPostalCode = strNewPostalCode;  
if( !rsStudent.Update( ) )  
{  
    AfxMessageBox( "Record not updated; no field values were set." );  
    return FALSE;  
}  
```  
  
> [!TIP]
>  Para cancelar uma chamada de `AddNew` ou de **Editar** , execute apenas outra chamada para `AddNew` ou a **Editar** ou chame **Mover** com o parâmetro de **AFX\_MOVE\_REFRESH** .  Os membros de dados são redefinidos para os valores anteriores e você ainda estão em **Editar** ou do modo de **Adicionar** .  
  
##  <a name="_core_deleting_a_record_from_a_recordset"></a> Excluindo um registro de um conjunto de registros  
 Você pode excluir registros se a função de membro de [CanUpdate](../Topic/CRecordset::CanUpdate.md) do conjunto de registros retorna um valor diferente de zero.  
  
#### Para excluir um registro  
  
1.  Verifique se o conjunto de registros é atualizável.  
  
2.  Role ao registro que você deseja atualizar.  
  
3.  Chame a função de membro de [Excluir](../Topic/CRecordset::Delete.md) do objeto do conjunto de registros.  
  
     **Excluir** marca imediatamente o registro como excluído, no conjunto de registros e na fonte de dados.  
  
     Ao contrário de `AddNew` e de **Editar**, **Excluir** não tem nenhum chamada correspondente de **Atualizar** .  
  
4.  Role para outro registro.  
  
    > [!NOTE]
    >  Ao mover com o conjunto de registros, os registros excluídos não podem ser ignorados.  Para obter mais informações, veja a função de membro de [IsDeleted](../Topic/CRecordset::IsDeleted.md) .  
  
 O exemplo a seguir mostra uma operação de **Excluir** .  Assume que o usuário se transportou a um registro que o usuário deseja excluir.  Depois que **Excluir** é chamado, é importante para a movimentação para um novo registro.  
  
```  
rsStudent.Delete( );  
rsStudent.MoveNext( );  
```  
  
 Para obter mais informações sobre os efeitos de `AddNew`, **Editar**, e as funções de membro de **Excluir** , consulte [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: bloqueando registros \(ODBC\)](../../data/odbc/recordset-locking-records-odbc.md)