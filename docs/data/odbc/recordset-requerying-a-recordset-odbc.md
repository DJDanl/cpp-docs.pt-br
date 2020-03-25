---
title: 'Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- recordsets, requerying
- requerying recordsets
- Requery method
- ODBC recordsets, requerying
- refreshing recordsets
ms.assetid: 4ebc3b5b-5b91-4f51-a967-245223c6b8e1
ms.openlocfilehash: b7cf40ca3b0c8e415368772063aee61008a52764
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212778"
---
# <a name="recordset-requerying-a-recordset-odbc"></a>Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como você pode usar um objeto Recordset para repetir a consulta (ou seja, atualizar) a partir do banco de dados e quando você pode desejar fazer isso com a função de membro [Requery](../../mfc/reference/crecordset-class.md#requery) .

Os principais motivos para reconsultar um conjunto de registros são:

- Traga o conjunto de registros atualizado em relação aos registros adicionados por você ou por outros usuários e registros excluídos por outros usuários (aqueles que você exclui já estão refletidos no conjunto de registros).

- Atualize o conjunto de registros com base na alteração de valores de parâmetro.

##  <a name="bringing-the-recordset-up-to-date"></a><a name="_core_bringing_the_recordset_up_to_date"></a>Trazendo o conjunto de registros até o momento

Com frequência, você desejará repetir o objeto do conjunto de registros para atualizá-lo. Em um ambiente de banco de dados multiusuário, outros usuários podem fazer alterações nos dados durante a vida útil do seu conjunto de registros. Para obter mais informações sobre quando o conjunto de registros reflete as alterações feitas por outros usuários e quando os conjuntos de registros de outros usuários refletem suas alterações, consulte conjunto de registros [: como os registros de atualização de conjuntos de registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [dynaset](../../data/odbc/dynaset.md).

##  <a name="requerying-based-on-new-parameters"></a><a name="_core_requerying_based_on_new_parameters"></a>Consultando com base nos novos parâmetros

Outra consulta frequente – e igualmente importante – o uso de [Requery](../../mfc/reference/crecordset-class.md#requery) é selecionar um novo conjunto de registros com base na alteração de valores de parâmetro.

> [!TIP]
>  A velocidade da consulta provavelmente será significativamente mais rápida se você chamar `Requery` com a alteração de valores de parâmetro do que se você chamar `Open` novamente.

##  <a name="requerying-dynasets-vs-snapshots"></a><a name="_core_requerying_dynasets_vs.._snapshots"></a>Reconsultando dynasets versus instantâneos

Como os dynasets destinam-se a apresentar um conjunto de registros com dados dinâmicos atualizados, você deseja repetir a consulta de dynasets com frequência se quiser refletir as adições de outros usuários. Os instantâneos, por outro lado, são úteis porque você pode confiar com segurança em seu conteúdo estático enquanto prepara relatórios, calcula totais e assim por diante. Ainda assim, às vezes você pode querer repetir uma consulta a um instantâneo também. Em um ambiente multiusuário, os dados de instantâneo podem perder a sincronização com a fonte de dados, já que outros usuários alteram o banco de dado.

#### <a name="to-requery-a-recordset-object"></a>Para repetir um objeto de conjunto de registros

1. Chame a função de membro [Requery](../../mfc/reference/crecordset-class.md#requery) do objeto.

Como alternativa, você pode fechar e reabrir o conjunto de registros original. Em ambos os casos, o novo conjunto de registros representa o estado atual da fonte de dados.

Para obter um exemplo, consulte [exibições de registro: preenchendo uma caixa de listagem de um segundo conjunto de registros](../../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).

> [!TIP]
>  Para otimizar o desempenho do `Requery`, evite alterar o [filtro](../../data/odbc/recordset-filtering-records-odbc.md) ou a [classificação](../../data/odbc/recordset-sorting-records-odbc.md)do conjunto de registros. Altere apenas o valor do parâmetro antes de chamar `Requery`.

Se a chamada de `Requery` falhar, você poderá repetir a chamada; caso contrário, seu aplicativo deverá ser encerrado normalmente. Uma chamada para `Requery` ou `Open` pode falhar por vários motivos. Talvez um erro de rede ocorra; ou, durante a chamada, depois que os dados existentes forem liberados, mas antes que os novos dados sejam obtidos, outro usuário poderá obter acesso exclusivo; ou a tabela na qual o conjunto de registros depende poderia ser excluída.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)<br/>
[Conjunto de registros: criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)
