---
title: 'Conjunto de registros: Adicionando, atualizando e excluindo registros (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- records [C++], updating
- record editing [C++], in recordsets
- recordsets [C++], adding records
- records [C++], adding
- ODBC recordsets [C++], adding records
- recordsets [C++], editing records
- recordsets [C++], updating
- records [C++], deleting
- AddNew method
- ODBC recordsets [C++], deleting records
- data in recordsets [C++]
- record editing [C++]
- recordsets [C++], deleting records
- ODBC recordsets [C++], editing records
- records [C++], editing
ms.assetid: 760c8889-bec4-482b-a8f2-319792a6af98
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8f326a729485ddbc203e6efc04e45061bbbc08d2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-adding-updating-and-deleting-records-odbc"></a>Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
> [!NOTE]
>  Agora você pode adicionar registros em massa com mais eficiência. Para obter mais informações, consulte [conjunto de registros: adicionando registros em massa (ODBC)](../../data/odbc/recordset-adding-records-in-bulk-odbc.md).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Dynasets atualizáveis instantâneos permitem adicionar, editar (atualização) e excluir registros. Este tópico explica:  
  
-   [Como determinar se o conjunto de registros é atualizável](#_core_determining_whether_your_recordset_is_updatable).  
  
-   [Como adicionar um novo registro](#_core_adding_a_record_to_a_recordset).  
  
-   [Como editar um registro existente](#_core_editing_a_record_in_a_recordset).  
  
-   [Como excluir um registro](#_core_deleting_a_record_from_a_recordset).  
  
 Para obter mais informações sobre como as atualizações são realizadas fora e como as atualizações aparecem para outros usuários, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md). Normalmente, quando você adicionar, edita ou excluir um registro, o conjunto de registros altera a fonte de dados imediatamente. Em vez disso, você pode em lotes grupos de atualizações relacionadas em transações. Se uma transação está em andamento, a atualização não fica final até que você confirme a transação. Isso permite que você volta ou reverter as alterações. Para obter informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
 A tabela a seguir resume as opções disponíveis para conjuntos de registros com características diferentes de atualização.  
  
### <a name="recordset-readupdate-options"></a>Opções de leitura/atualização do conjunto de registros  
  
|Tipo|Ler|Editar o registro|Excluir registro|Adicionar novo (acrescentar)|  
|----------|----------|-----------------|-------------------|------------------------|  
|Somente leitura|S|N|N|N|  
|Somente de acréscimo|S|N|N|S|  
|Totalmente atualizável|S|S|S|S|  
  
##  <a name="_core_determining_whether_your_recordset_is_updatable"></a>Determinar se o conjunto de registros é Updateable  
 Um objeto de conjunto de registros é atualizável, se a fonte de dados é atualizável e abrir o conjunto de registros pode ser atualizado. Sua capacidade de atualização também depende da instrução SQL que você usa, os recursos de seu driver de ODBC, e se a biblioteca de cursores ODBC está na memória. Você não pode atualizar uma fonte de dados ou conjunto de registros somente leitura.  
  
#### <a name="to-determine-whether-your-recordset-is-updatable"></a>Para determinar se o conjunto de registros é atualizável  
  
1.  Chamar o objeto de conjunto de registros [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) função de membro.  
  
     `CanUpdate`Retorna um valor diferente de zero se o conjunto de registros é atualizável.  
  
 Por padrão, conjuntos de registros são totalmente atualizáveis (você pode executar `AddNew`, **editar**, e **excluir** operações). Mas você também pode usar o [appendOnly](../../mfc/reference/crecordset-class.md#open) opção para abrir o conjunto de registros pode ser atualizado. Um conjunto de registros aberto dessa maneira permite apenas a adição de novos registros com `AddNew`. Você não pode editar ou excluir os registros existentes. Você pode testar se um conjunto de registros é aberto somente para acrescentar chamando o [CanAppend](../../mfc/reference/crecordset-class.md#canappend) função de membro. `CanAppend`Retorna um valor diferente de zero se o conjunto de registros é totalmente atualizável ou aberto somente para anexar.  
  
 O código a seguir mostra como você pode usar `CanUpdate` para um objeto recordset chamado `rsStudentSet`:  
  
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
>  Quando você se prepara para atualizar um conjunto de registros chamando **atualizar**, lembre-se que o conjunto de registros inclui todas as colunas que compõem a chave primária da tabela (ou todas as colunas de qualquer índice exclusivo na tabela). Em alguns casos, a estrutura pode usar somente as colunas selecionadas em seu conjunto de registros para identificar qual registro na tabela para atualizar. Sem todas as colunas necessárias, vários registros poderão ser atualizados na tabela, possivelmente danificar a integridade referencial da tabela. Nesse caso, o framework lança exceções ao chamar **atualização**.  
  
##  <a name="_core_adding_a_record_to_a_recordset"></a>Adicionar um registro para um conjunto de registros  
 Você pode adicionar novos registros de um conjunto de registros se seu [CanAppend](../../mfc/reference/crecordset-class.md#canappend) função membro retorna um valor diferente de zero.  
  
#### <a name="to-add-a-new-record-to-a-recordset"></a>Para adicionar um novo registro para um conjunto de registros  
  
1.  Verifique se que o conjunto de registros é appendable.  
  
2.  Chamar o objeto de conjunto de registros [AddNew](../../mfc/reference/crecordset-class.md#addnew) função de membro.  
  
     `AddNew`prepara o conjunto de registros para atuar como um buffer de edição. Todos os membros de dados de campo são definidos como o valor especial Null e marcados como inalterada para apenas alterada (suja) valores são gravados para a fonte de dados quando você chamar [atualização](../../mfc/reference/crecordset-class.md#update).  
  
3.  Defina os valores campo do registro novo membros de dados.  
  
     Atribua valores para os membros de dados do campo. Aquelas que não atribua não são gravadas para a fonte de dados.  
  
4.  Chamar o objeto de conjunto de registros **atualização** função de membro.  
  
     **Atualização** conclui a adição, gravando o novo registro para a fonte de dados. Para obter informações sobre acontece se você não chamar **atualização**, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
 Para obter informações sobre como adicionar registros funciona e quando os registros adicionados estão visíveis em seu conjunto de registros, consulte [conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md).  
  
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
>  Para cancelar um `AddNew` ou **editar** chamar, basta fazer outra chamada para `AddNew` ou **editar** ou chame **mover** com o **AFX_MOVE_REFRESH**  parâmetro. Membros de dados são redefinidos para os valores anteriores e você ainda no **editar** ou **adicionar** modo.  
  
##  <a name="_core_editing_a_record_in_a_recordset"></a>Editar um registro em um conjunto de registros  
 Você pode editar os registros existentes se o conjunto de registros [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) função membro retorna um valor diferente de zero.  
  
#### <a name="to-edit-an-existing-record-in-a-recordset"></a>Para editar um registro existente em um conjunto de registros  
  
1.  Verifique se que o conjunto de registros é atualizável.  
  
2.  Role para o registro que você deseja atualizar.  
  
3.  Chamar o objeto de conjunto de registros [editar](../../mfc/reference/crecordset-class.md#edit) função de membro.  
  
     **Editar** prepara o conjunto de registros para atuar como um buffer de edição. Todos os membros de dados de campo são marcados para que o conjunto de registros pode dizer mais tarde, se elas foram alteradas. Os novos valores para membros de dados de campo alterado são gravados para a fonte de dados quando você chamar [atualização](../../mfc/reference/crecordset-class.md#update).  
  
4.  Defina os valores campo do registro novo membros de dados.  
  
     Atribua valores para os membros de dados do campo. Aquelas que não atribua valores permanecem inalteradas.  
  
5.  Chamar o objeto de conjunto de registros **atualização** função de membro.  
  
     **Atualização** concluir a edição, gravando o registro alterado para a fonte de dados. Para obter informações sobre acontece se você não chamar **atualização**, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
 Depois que você edita um registro, o registro editado permanece o registro atual.  
  
 A exemplo a seguir mostra um **editar** operação. Ele pressupõe que o usuário foi movido para um registro que deseja editar.  
  
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
>  Para cancelar um `AddNew` ou **editar** chamar, basta fazer outra chamada para `AddNew` ou **editar** ou chame **mover** com o **AFX_MOVE_REFRESH**  parâmetro. Membros de dados são redefinidos para os valores anteriores e você ainda no **editar** ou **adicionar** modo.  
  
##  <a name="_core_deleting_a_record_from_a_recordset"></a>Excluir um registro de um conjunto de registros  
 Você pode excluir registros se o conjunto de registros [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) função membro retorna um valor diferente de zero.  
  
#### <a name="to-delete-a-record"></a>Para excluir um registro  
  
1.  Verifique se que o conjunto de registros é atualizável.  
  
2.  Role para o registro que você deseja atualizar.  
  
3.  Chamar o objeto de conjunto de registros [excluir](../../mfc/reference/crecordset-class.md#delete) função de membro.  
  
     **Excluir** marca imediatamente o registro como excluído, tanto no conjunto de registros na fonte de dados.  
  
     Ao contrário de `AddNew` e **editar**, **excluir** não tem correspondente **atualização** chamar.  
  
4.  Role até outro registro.  
  
    > [!NOTE]
    >  Ao passar pelo conjunto de registros, registros excluídos não podem ser ignorados. Para obter mais informações, consulte o [IsDeleted](../../mfc/reference/crecordset-class.md#isdeleted) função de membro.  
  
 A exemplo a seguir mostra um **excluir** operação. Ele pressupõe que o usuário foi movido para um registro que o usuário deseja excluir. Depois de **excluir** é chamado, é importante mover para um novo registro.  
  
```  
rsStudent.Delete( );  
rsStudent.MoveNext( );  
```  
  
 Para obter mais informações sobre os efeitos da `AddNew`, **editar**, e **excluir** funções de membro, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)