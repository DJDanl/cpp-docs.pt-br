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
ms.openlocfilehash: 628ffb2feee385a4114b0dbea074f81678c529d4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367102"
---
# <a name="recordset-adding-updating-and-deleting-records-odbc"></a>Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

> [!NOTE]
> Agora você pode adicionar registros em massa de forma mais eficiente. Para obter mais informações, consulte [Recordset: Adicionando Registros em Massa (ODBC)](../../data/odbc/recordset-adding-records-in-bulk-odbc.md).

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Instantâneos e dynasets atualizáveis permitem adicionar, editar (atualizar) e excluir registros. Este tópico explica:

- [Como determinar se o seu conjunto de registros é updatable](#_core_determining_whether_your_recordset_is_updatable).

- [Como adicionar um novo disco.](#_core_adding_a_record_to_a_recordset)

- [Como editar um registro existente](#_core_editing_a_record_in_a_recordset).

- [Como excluir um registro](#_core_deleting_a_record_from_a_recordset).

Para obter mais informações sobre como as atualizações são realizadas e como suas atualizações aparecem para outros usuários, consulte [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md). Normalmente, quando você adiciona, edita ou exclui um registro, o conjunto de registros altera a fonte de dados imediatamente. Em vez disso, você pode em lotear grupos de atualizações relacionadas em transações. Se uma transação estiver em andamento, a atualização não se tornará definitiva até que você comprometa a transação. Isso permite que você recupere ou reverta as mudanças. Para obter informações sobre transações, consulte [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

A tabela a seguir resume as opções disponíveis para conjuntos de registros com diferentes características de atualização.

### <a name="recordset-readupdate-options"></a>Opções de leitura/atualização do conjunto de registros

|Type|Ler|Editar registro|Excluir registro|Adicionar novo (apêndice)|
|----------|----------|-----------------|-------------------|------------------------|
|Somente leitura|S|N|N|N|
|Somente apêndice|S|N|N|S|
|Totalmente updatable|S|S|S|S|

## <a name="determining-whether-your-recordset-is-updateable"></a><a name="_core_determining_whether_your_recordset_is_updatable"></a>Determinando se seu conjunto de registros é atualizável

Um objeto de conjunto de registros pode ser atualizado se a fonte de dados for atualizada e você abrir o conjunto de registros como atualizável. Sua capacidade de atualização também depende da declaração SQL que você usa, dos recursos do driver ODBC e se a Biblioteca Cursor ODBC está na memória. Não é possível atualizar um conjunto de registros somente leitura ou fonte de dados.

#### <a name="to-determine-whether-your-recordset-is-updatable"></a>Para determinar se o seu conjunto de registros é updatable

1. Ligue para a função de membro [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) do objeto recordset.

   `CanUpdate`retorna um valor não zero se o conjunto de registros for atualizável.

Por padrão, os conjuntos de registros `AddNew` `Edit`são `Delete` totalmente atualizáveis (você pode executar , e operações). Mas você também pode usar a opção [apêndiceOnly](../../mfc/reference/crecordset-class.md#open) para abrir conjuntos de registros atualizáveis. Um conjunto de registros aberto desta forma `AddNew`permite apenas a adição de novos registros com . Não é possível editar ou excluir registros existentes. Você pode testar se um conjunto de registros está aberto apenas para anexar, chamando a função de membro [do CanAppend.](../../mfc/reference/crecordset-class.md#canappend) `CanAppend`retorna um valor não zero se o conjunto de registros for totalmente atualizável ou aberto apenas para anexação.

O código a seguir `CanUpdate` mostra como você `rsStudentSet`pode usar para um objeto de conjunto de registros chamado:

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
> Quando você se preparar para `Update`atualizar um conjunto de registros ligando, tome cuidado para que seu conjunto de registros inclua todas as colunas que compõem a chave principal da tabela (ou todas as colunas de qualquer índice único na tabela). Em alguns casos, o framework pode usar apenas as colunas selecionadas em seu conjunto de registros para identificar qual registro em sua tabela para atualizar. Sem todas as colunas necessárias, vários registros podem ser atualizados na tabela, possivelmente prejudicando a integridade referencial da tabela. Neste caso, o quadro lança exceções quando você chama `Update`.

## <a name="adding-a-record-to-a-recordset"></a><a name="_core_adding_a_record_to_a_recordset"></a>Adicionando um registro a um conjunto de registros

Você pode adicionar novos registros a um conjunto de registros se a função de membro [CanAppend](../../mfc/reference/crecordset-class.md#canappend) retornar a um valor não zero.

#### <a name="to-add-a-new-record-to-a-recordset"></a>Para adicionar um novo recorde a um conjunto de discos

1. Certifique-se de que o conjunto de registros é apêndice.

1. Ligue para a função addnew do objeto [Doset](../../mfc/reference/crecordset-class.md#addnew) de gravação.

   `AddNew`prepara o conjunto de registros para atuar como um buffer de edição. Todos os membros de dados de campo são definidos como valor especial Nulo e marcado como inalterado, de modo que apenas os valores alterados (sujos) são gravados na fonte de dados quando você chama [Atualização](../../mfc/reference/crecordset-class.md#update).

1. Defina os valores dos membros de dados de campo do novo registro.

   Atribuir valores aos membros de dados de campo. Aqueles que você não atribuir não estão escritos na fonte de dados.

1. Ligue para a função `Update` de membro do recordset.

   `Update`completa a adição escrevendo o novo registro para a fonte de dados. Para obter informações sobre o `Update`que acontece se você não ligar, consulte [Recordset: Como o Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

Para obter informações sobre como a adição de registros funciona e sobre quando os registros adicionados são visíveis no seu conjunto de registros, consulte [Recordset: How AddNew, Edit e Delete Work (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md).

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
> Para cancelar `AddNew` `Edit` uma ou ligar, `AddNew` basta `Edit` fazer `Move` outra chamada ou ligar com o parâmetro *AFX_MOVE_REFRESH.* Os membros de dados são redefinidos `Edit` para `Add` seus valores anteriores e você ainda está dentro ou no modo.

## <a name="editing-a-record-in-a-recordset"></a><a name="_core_editing_a_record_in_a_recordset"></a>Editando um Registro em um conjunto de registros

Você pode editar registros existentes se a função de membro [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) do seu conjunto de gravações retornar um valor não zero.

#### <a name="to-edit-an-existing-record-in-a-recordset"></a>Para editar um registro existente em um conjunto de registros

1. Certifique-se de que o conjunto de registros é atualizável.

1. Role até o registro que deseja atualizar.

1. Ligue para a função editar membro do objeto [do](../../mfc/reference/crecordset-class.md#edit) recordset.

   `Edit`prepara o conjunto de registros para atuar como um buffer de edição. Todos os membros de dados de campo são marcados para que o conjunto de registros possa dizer mais tarde se eles foram alterados. Os novos valores para membros de dados de campo alterados são gravados na fonte de dados quando você chama [Atualização](../../mfc/reference/crecordset-class.md#update).

1. Defina os valores dos membros de dados de campo do novo registro.

   Atribuir valores aos membros de dados de campo. Aqueles que você não atribui valores permanecem inalterados.

1. Ligue para a função `Update` de membro do recordset.

   `Update`completa a edição escrevendo o registro alterado para a fonte de dados. Para obter informações sobre o `Update`que acontece se você não ligar, consulte [Recordset: Como o Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

Depois de editar um registro, o registro editado continua sendo o registro atual.

O exemplo a `Edit` seguir mostra uma operação. Ele assume que o usuário mudou para um registro que ele ou ela quer editar.

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
> Para cancelar `AddNew` `Edit` uma ou ligar, `AddNew` basta `Edit` fazer `Move` outra chamada ou ligar com o parâmetro *AFX_MOVE_REFRESH.* Os membros de dados são redefinidos `Edit` para `Add` seus valores anteriores e você ainda está dentro ou no modo.

## <a name="deleting-a-record-from-a-recordset"></a><a name="_core_deleting_a_record_from_a_recordset"></a>Excluindo um registro de um conjunto de gravações

Você pode excluir registros se a função de membro [CanUpdate](../../mfc/reference/crecordset-class.md#canupdate) do seu conjunto de registros retornar um valor não zero.

#### <a name="to-delete-a-record"></a>Para excluir um registro

1. Certifique-se de que o conjunto de registros é atualizável.

1. Role até o registro que deseja atualizar.

1. Ligue para a função ['Excluir](../../mfc/reference/crecordset-class.md#delete) membro' do objeto Recordset.

   `Delete`marca imediatamente o registro como excluído, tanto no conjunto de registros quanto na fonte de dados.

   Ao `AddNew` `Edit`contrário `Delete` e `Update` , não tem chamada correspondente.

1. Role para outro disco.

   > [!NOTE]
   >  Ao passar pelo conjunto de registros, os registros excluídos podem não ser ignorados. Para obter mais informações, consulte a função [membro IsDeleted.](../../mfc/reference/crecordset-class.md#isdeleted)

O exemplo a `Delete` seguir mostra uma operação. Ele assume que o usuário mudou para um registro que o usuário deseja excluir. Depois `Delete` que é chamado, é importante passar para um novo recorde.

```
rsStudent.Delete( );
rsStudent.MoveNext( );
```

Para obter mais informações `AddNew`sobre `Edit`os `Delete` efeitos das funções , e dos membros, consulte [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)
