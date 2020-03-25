---
title: 'Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)'
ms.date: 11/04/2016
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
ms.openlocfilehash: 14fc26709541135e80a2e0fe4de872cc75221874
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212999"
---
# <a name="recordset-adding-updating-and-deleting-records-odbc"></a>Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

> [!NOTE]
>  Agora você pode adicionar registros em massa com mais eficiência. Para obter mais informações, consulte conjunto de registros [: adicionando registros em massa (ODBC)](../../data/odbc/recordset-adding-records-in-bulk-odbc.md).

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Instantâneos atualizáveis e dynasets permitem adicionar, editar (atualizar) e excluir registros. Este tópico explica:

- [Como determinar se o conjunto de registros é atualizável](#_core_determining_whether_your_recordset_is_updatable).

- [Como adicionar um novo registro](#_core_adding_a_record_to_a_recordset).

- [Como editar um registro existente](#_core_editing_a_record_in_a_recordset).

- [Como excluir um registro](#_core_deleting_a_record_from_a_recordset).

Para obter mais informações sobre como as atualizações são executadas e como suas atualizações aparecem para outros usuários, consulte conjunto de registros [: como os registros de atualização de conjuntos de registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md). Normalmente, quando você adiciona, edita ou exclui um registro, o conjunto de registros altera a fonte de dados imediatamente. Em vez disso, você pode agrupar grupos de atualizações relacionadas em transações. Se uma transação estiver em andamento, a atualização não se tornará final até que você confirme a transação. Isso permite que você retorne ou reverta as alterações. Para obter informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).

A tabela a seguir resume as opções disponíveis para conjuntos de registros com diferentes características de atualização.

### <a name="recordset-readupdate-options"></a>Opções de leitura/atualização do conjunto de registros

|Type|Ler|Editar registro|Excluir registro|Adicionar novo (acrescentar)|
|----------|----------|-----------------|-------------------|------------------------|
|Somente leitura|S|N|N|N|
|Somente acréscimo|S|N|N|S|
|Totalmente atualizável|S|S|S|S|

##  <a name="determining-whether-your-recordset-is-updateable"></a><a name="_core_determining_whether_your_recordset_is_updatable"></a>Determinando se o conjunto de registros é atualizável

Um objeto Recordset será atualizável se a fonte de dados for atualizável e você tiver aberto o conjunto de registros como atualizável. Sua capacidade de atualização também depende da instrução SQL que você usa, dos recursos do seu driver ODBC e se a biblioteca de cursores ODBC está na memória. Não é possível atualizar um conjunto de registros ou uma fonte de dados somente leitura.

#### <a name="to-determine-whether-your-recordset-is-updatable"></a>Para determinar se o conjunto de registros é atualizável

1. Chame a função de membro [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) do objeto Recordset.

   `CanUpdate` retornará um valor diferente de zero se o conjunto de registros for atualizável.

Por padrão, os conjuntos de registros são totalmente atualizáveis (você pode executar as operações `AddNew`, `Edit`e `Delete`). Mas você também pode usar a opção [AppendOnly](../../mfc/reference/crecordset-class.md#open) para abrir conjuntos de registros atualizáveis. Um conjunto de registros aberto dessa maneira permite apenas a adição de novos registros com `AddNew`. Você não pode editar ou excluir registros existentes. Você pode testar se um conjunto de registros é aberto apenas para anexar chamando a função de membro [CanAppend](../../mfc/reference/crecordset-class.md#canappend) . `CanAppend` retornará um valor diferente de zero se o conjunto de registros for totalmente atualizável ou aberto somente para acréscimo.

O código a seguir mostra como você pode usar `CanUpdate` para um objeto Recordset chamado `rsStudentSet`:

```cpp
if( !rsStudentSet.Open( ) )
    return FALSE;
if( !rsStudentSet.CanUpdate( ) )
{
    AfxMessageBox( "Unable to update the Student recordset." );
    return;
}
```

> [!CAUTION]
>  Quando você se prepara para atualizar um conjunto de registros chamando `Update`, tome cuidado para que o conjunto de registros inclua todas as colunas que compõem a chave primária da tabela (ou todas as colunas de qualquer índice exclusivo na tabela). Em alguns casos, a estrutura pode usar apenas as colunas selecionadas no conjunto de registros para identificar qual registro em sua tabela deve ser atualizado. Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela, possivelmente causando a integridade referencial da tabela. Nesse caso, a estrutura gera exceções quando você chama `Update`.

##  <a name="adding-a-record-to-a-recordset"></a><a name="_core_adding_a_record_to_a_recordset"></a>Adicionando um registro a um conjunto de registros

Você pode adicionar novos registros a um conjunto de registros se sua função de membro [CanAppend](../../mfc/reference/crecordset-class.md#canappend) retornar um valor diferente de zero.

#### <a name="to-add-a-new-record-to-a-recordset"></a>Para adicionar um novo registro a um conjunto de registros

1. Verifique se o conjunto de registros é acrescentável.

1. Chame a função de membro [AddNew](../../mfc/reference/crecordset-class.md#addnew) do objeto Recordset.

   `AddNew` prepara o conjunto de registros para atuar como um buffer de edição. Todos os membros de dados de campo são definidos como o valor especial NULL e marcados como inalterados, de modo que somente os valores alterados (sujos) são gravados na fonte de dados quando você chama [Update](../../mfc/reference/crecordset-class.md#update).

1. Defina os valores dos membros de dados de campo do novo registro.

   Atribua valores aos membros de dados de campo. Aqueles que você não atribui não são gravados na fonte de dados.

1. Chame a função de membro `Update` do objeto Recordset.

   `Update` concluir a adição, gravando o novo registro na fonte de dados. Para obter informações sobre o acontece se você não chamar `Update`, consulte conjunto de registros [: como os conjuntos de registros de atualização do Recordsets (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

Para obter informações sobre como adicionar registros funciona e sobre quando os registros adicionados são visíveis no conjunto de registros, consulte [conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md).

O exemplo a seguir mostra como adicionar um novo registro:

```cpp
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
>  Para cancelar uma chamada de `AddNew` ou `Edit`, basta fazer outra chamada para `AddNew` ou `Edit` ou chamar `Move` com o parâmetro *AFX_MOVE_REFRESH* . Os membros de dados são redefinidos para seus valores anteriores e você ainda está no modo `Edit` ou `Add`.

##  <a name="editing-a-record-in-a-recordset"></a><a name="_core_editing_a_record_in_a_recordset"></a>Editando um registro em um conjunto de registros

Você pode editar os registros existentes se a função de membro [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) do conjunto de registros retornar um valor diferente de zero.

#### <a name="to-edit-an-existing-record-in-a-recordset"></a>Para editar um registro existente em um conjunto de registros

1. Verifique se o conjunto de registros é atualizável.

1. Role até o registro que você deseja atualizar.

1. Chame a função de membro [Edit](../../mfc/reference/crecordset-class.md#edit) do objeto Recordset.

   `Edit` prepara o conjunto de registros para atuar como um buffer de edição. Todos os membros de dados de campo são marcados para que o conjunto de registros possa dizer mais tarde se eles foram alterados. Os novos valores para membros de dados de campo alterados são gravados na fonte de dados quando você chama [Update](../../mfc/reference/crecordset-class.md#update).

1. Defina os valores dos membros de dados de campo do novo registro.

   Atribua valores aos membros de dados de campo. Aqueles para os quais você não atribui valores permanecem inalterados.

1. Chame a função de membro `Update` do objeto Recordset.

   `Update` conclui a edição gravando o registro alterado na fonte de dados. Para obter informações sobre o acontece se você não chamar `Update`, consulte conjunto de registros [: como os conjuntos de registros de atualização do Recordsets (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

Depois de editar um registro, o registro editado permanece o registro atual.

O exemplo a seguir mostra uma operação `Edit`. Ele assume que o usuário se moveu para um registro que ele deseja editar.

```cpp
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
> Para cancelar uma chamada de `AddNew` ou `Edit`, basta fazer outra chamada para `AddNew` ou `Edit` ou chamar `Move` com o parâmetro *AFX_MOVE_REFRESH* . Os membros de dados são redefinidos para seus valores anteriores e você ainda está no modo `Edit` ou `Add`.

##  <a name="deleting-a-record-from-a-recordset"></a><a name="_core_deleting_a_record_from_a_recordset"></a>Excluindo um registro de um conjunto de registros

Você pode excluir registros se a função de membro [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) do conjunto de registros retornar um valor diferente de zero.

#### <a name="to-delete-a-record"></a>Para excluir um registro

1. Verifique se o conjunto de registros é atualizável.

1. Role até o registro que você deseja atualizar.

1. Chame a função de membro [delete](../../mfc/reference/crecordset-class.md#delete) do objeto Recordset.

   `Delete` marca imediatamente o registro como excluído, no conjunto de registros e na fonte de dados.

   Ao contrário de `AddNew` e `Edit`, `Delete` não tem nenhuma chamada de `Update` correspondente.

1. Role até outro registro.

   > [!NOTE]
   >  Ao mover o conjunto de registros, os registros excluídos podem não ser ignorados. Para obter mais informações, consulte a função membro [IsDeleted](../../mfc/reference/crecordset-class.md#isdeleted) .

O exemplo a seguir mostra uma operação `Delete`. Ele pressupõe que o usuário moveu para um registro que o usuário deseja excluir. Depois que `Delete` é chamado, é importante mover para um novo registro.

```
rsStudent.Delete( );
rsStudent.MoveNext( );
```

Para obter mais informações sobre os efeitos das funções de membro `AddNew`, `Edit`e `Delete`, consulte [conjunto de registros: como os registros de atualização de conjuntos de registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)
