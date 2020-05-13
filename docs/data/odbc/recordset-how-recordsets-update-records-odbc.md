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
ms.openlocfilehash: 03fb696c1fadd834962d37c8e75b5f8910af819e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366973"
---
# <a name="recordset-how-recordsets-update-records-odbc"></a>Conjunto de registros: como conjuntos de registros atualizam registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Além de sua capacidade de selecionar registros de uma fonte de dados, os conjuntos de registros podem (opcionalmente) atualizar ou excluir os registros selecionados ou adicionar novos registros. Três fatores determinam a capacidade de atualização de um conjunto de registros: se a fonte de dados conectada é atualizável, as opções especificadas quando você cria um objeto de conjunto de registros e o SQL criado.

> [!NOTE]
> O SQL no `CRecordset` qual seu objeto é baseado pode afetar a capacidade de atualização do seu conjunto de registros. Por exemplo, se o seu SQL contiver uma adesão ou uma cláusula **GROUP BY,** o MFC definirá a capacidade de atualização como FALSE.

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Este tópico explica:

- [Seu papel na atualização do conjunto de registros](#_core_your_role_in_recordset_updating) e o que a estrutura faz por você.

- [O conjunto de registros como um buffer de edição](#_core_the_edit_buffer) e as diferenças entre [dynasets e snapshots](#_core_dynasets_and_snapshots).

[Conjunto de registros: Como adicionarnovo, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md) descreve as ações dessas funções do ponto de vista do conjunto de registros.

[Conjunto de registros: Mais sobre atualizações (ODBC)](../../data/odbc/recordset-more-about-updates-odbc.md) completa a história de atualização do conjunto de registros explicando como as transações afetam as atualizações, como fechar um conjunto de registros ou rolagem afeta as atualizações em andamento e como suas atualizações interagem com as atualizações de outros usuários.

## <a name="your-role-in-recordset-updating"></a><a name="_core_your_role_in_recordset_updating"></a>Seu papel na atualização do recordset

A tabela a seguir mostra seu papel no uso de conjuntos de registros para adicionar, editar ou excluir registros, juntamente com o que a estrutura faz por você.

### <a name="recordset-updating-you-and-the-framework"></a>Atualização do conjunto de registros: você e o Framework

|Você|A estrutura|
|---------|-------------------|
|Determine se a fonte de dados é atualizável (ou apêndice).|Fornece funções de membro [do CDatabase](../../mfc/reference/cdatabase-class.md) para testar a capacidade de atualização ou apêndice da fonte de dados.|
|Abra um conjunto de registros updatable (de qualquer tipo).||
|Determine se o conjunto de registros `CRecordset` é atualizável `CanUpdate` `CanAppend`chamando funções de atualização como ou .||
|Funções de membro do conjunto de registros de chamadas para adicionar, editar e excluir registros.|Gerencia a mecânica de troca de dados entre o objeto recordset e a fonte de dados.|
|Opcionalmente, use transações para controlar o processo de atualização.|Fornece `CDatabase` funções de membro para suportar transações.|

Para obter mais informações sobre transações, consulte [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

## <a name="the-edit-buffer"></a><a name="_core_the_edit_buffer"></a>O Buffer de edição

Tomadas coletivamente, os membros de dados de campo de um conjunto de registros servem como um buffer de edição que contém um registro — o registro atual. As operações de atualização usam este buffer para operar no registro atual.

- Quando você adiciona um registro, o buffer de edição é usado para construir um novo registro. Quando você termina de adicionar o registro, o recorde que era anteriormente atual torna-se atual novamente.

- Quando você atualiza (editar) um registro, o buffer de edição é usado para definir os membros de dados de campo do conjunto de registros como novos valores. Quando você terminar de atualizar, o registro atualizado ainda está atualizado.

Quando você chama [AddNew](../../mfc/reference/crecordset-class.md#addnew) ou [Edit,](../../mfc/reference/crecordset-class.md#edit)o registro atual é armazenado para que possa ser restaurado mais tarde, conforme necessário. Quando você chama [Excluir,](../../mfc/reference/crecordset-class.md#delete)o registro atual não é armazenado, mas está marcado como excluído e você deve rolar para outro registro.

> [!NOTE]
> O buffer de edição não desempenha nenhum papel na exclusão de registros. Quando você exclui o registro atual, o registro é marcado como excluído, e o conjunto de registros é "não em um registro" até que você role para um registro diferente.

## <a name="dynasets-and-snapshots"></a><a name="_core_dynasets_and_snapshots"></a>Dynasets e Snapshots

[Os dynasets](../../data/odbc/dynaset.md) atualizam o conteúdo de um registro enquanto você rola para o registro. [Os instantâneos](../../data/odbc/snapshot.md) são representações estáticas dos registros, de modo que o conteúdo de um registro não é atualizado a menos que você chame [Requery](../../mfc/reference/crecordset-class.md#requery). Para usar todas as funcionalidades de dynasets, você deve estar trabalhando com um driver ODBC que esteja em conformidade com o nível correto de suporte à API ODBC. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [Dynaset](../../data/odbc/dynaset.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como fazer AddNew, editar e excluir trabalho (ODBC)](../../data/odbc/recordset-how-addnew-edit-and-delete-work-odbc.md)
