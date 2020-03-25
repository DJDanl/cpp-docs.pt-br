---
title: 'Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- records, updating
- ODBC recordsets, updating
- recordsets, editing records
- updating recordsets
- recordsets, updating
ms.assetid: 5ceecc06-7a86-43b1-93db-a54fb1e717c7
ms.openlocfilehash: 578b3b39d90b3beb80dbd201d4982fee30dc6bce
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212869"
---
# <a name="recordset-how-recordsets-update-records-odbc"></a>Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Além de sua capacidade de selecionar registros de uma fonte de dados, os conjuntos de registros podem (opcionalmente) atualizar ou excluir os registros selecionados ou adicionar novos registros. Três fatores determinam a atualização de um conjunto de registros: se a fonte de dados conectada é atualizável, as opções que você especifica ao criar um objeto de conjunto de registros e o SQL que é criado.

> [!NOTE]
>  O SQL no qual seu objeto de `CRecordset` é baseado pode afetar a atualização de seu conjunto de registros. Por exemplo, se o SQL contiver uma cláusula JOIN ou **Group by** , o MFC definirá a atualização como false.

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Este tópico explica:

- [Sua função na atualização do conjunto de registros](#_core_your_role_in_recordset_updating) e o que a estrutura faz para você.

- [O conjunto de registros como um buffer de edição](#_core_the_edit_buffer) e as [diferenças entre dynasets e instantâneos](#_core_dynasets_and_snapshots).

[Conjunto de registros: como AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md) descreve as ações dessas funções a partir do ponto de vista do conjunto de registros.

[Conjunto de registros: mais informações sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md) conclui a história de atualização do conjunto de registros explicando como as transações afetam as atualizações, como o fechamento de um conjunto de registros ou a rolagem afeta as atualizações em andamento e como as atualizações interagem com as atualizações de outros usuários.

##  <a name="your-role-in-recordset-updating"></a><a name="_core_your_role_in_recordset_updating"></a>Sua função na atualização do conjunto de registros

A tabela a seguir mostra sua função no uso de conjuntos de registros para adicionar, editar ou excluir registros, juntamente com o que a estrutura faz para você.

### <a name="recordset-updating-you-and-the-framework"></a>Atualização de conjunto de registros: você e a estrutura

|Você|A estrutura|
|---------|-------------------|
|Determinar se a fonte de dados é atualizável (ou acrescentável).|Fornece funções de membro do [CDatabase](../../mfc/reference/cdatabase-class.md) para testar a data de atualização ou a possível anexação da fonte de dados.|
|Abra um conjunto de registros atualizável (de qualquer tipo).||
|Determine se o conjunto de registros é atualizável chamando `CRecordset` funções de atualização, como `CanUpdate` ou `CanAppend`.||
|Chame funções de membro do conjunto de registros para adicionar, editar e excluir registros.|Gerencia a mecânica de troca de dados entre o objeto Recordset e a fonte de dados.|
|Opcionalmente, use transações para controlar o processo de atualização.|Fornece `CDatabase` funções membro para dar suporte a transações.|

Para obter mais informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="the-edit-buffer"></a><a name="_core_the_edit_buffer"></a>O buffer de edição

Coletivamente, os membros de dados de campo de um conjunto de registros servem como um buffer de edição que contém um registro — o registro atual. As operações de atualização usam esse buffer para operar no registro atual.

- Quando você adiciona um registro, o buffer de edição é usado para criar um novo registro. Quando você terminar de adicionar o registro, o registro que estava anteriormente atual se tornará atual novamente.

- Quando você atualiza (edita) um registro, o buffer de edição é usado para definir os membros de dados de campo do conjunto de registros como novos valores. Quando você terminar de atualizar, o registro atualizado ainda será atual.

Quando você chama [AddNew](../../mfc/reference/crecordset-class.md#addnew) ou [Edit](../../mfc/reference/crecordset-class.md#edit), o registro atual é armazenado para que ele possa ser restaurado posteriormente, conforme necessário. Quando você chama [excluir](../../mfc/reference/crecordset-class.md#delete), o registro atual não é armazenado, mas é marcado como excluído e você deve rolar para outro registro.

> [!NOTE]
>  O buffer de edição não desempenha nenhuma função na exclusão do registro. Quando você exclui o registro atual, o registro é marcado como excluído e o conjunto de registros é "não está em um registro" até que você role para um registro diferente.

##  <a name="dynasets-and-snapshots"></a><a name="_core_dynasets_and_snapshots"></a>Dynasets e instantâneos

Os [dynasets](../../data/odbc/dynaset.md) atualizam o conteúdo de um registro conforme você rola para o registro. Os [instantâneos](../../data/odbc/snapshot.md) são representações estáticas dos registros, portanto, o conteúdo de um registro não é atualizado, a menos que você chame [Requery](../../mfc/reference/crecordset-class.md#requery). Para usar toda a funcionalidade de dynasets, você deve estar trabalhando com um driver ODBC que esteja em conformidade com o nível correto de suporte à API do ODBC. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [dynaset](../../data/odbc/dynaset.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como fazer AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md)
