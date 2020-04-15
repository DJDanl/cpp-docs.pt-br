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
ms.openlocfilehash: cdae28f81eebe8427bc829072e0d9a83c6ec1722
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366954"
---
# <a name="recordset-requerying-a-recordset-odbc"></a>Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como você pode usar um objeto de conjunto de registros para requery (ou seja, atualizar) a partir do banco de dados e quando você pode querer fazer isso com a função [requery](../../mfc/reference/crecordset-class.md#requery) membro.

As principais razões para solicitar um conjunto de registros são:

- Atualize o registro atualizado em relação aos registros adicionados por você ou por outros usuários e registros excluídos por outros usuários (aqueles que você exclui já estão refletidos no conjunto de registros).

- Atualize o conjunto de registros com base na alteração dos valores dos parâmetros.

## <a name="bringing-the-recordset-up-to-date"></a><a name="_core_bringing_the_recordset_up_to_date"></a>Trazendo o Recordset atualizado

Frequentemente, você vai querer requery seu objeto de conjunto de registros para atualizá-lo. Em um ambiente de banco de dados multiusuário, outros usuários podem fazer alterações nos dados durante a vida útil do seu conjunto de registros. Para obter mais informações sobre quando seu conjunto de registros reflete as alterações feitas por outros usuários e quando os conjuntos de registros de outros usuários refletem suas alterações, consulte [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [Dynaset](../../data/odbc/dynaset.md).

## <a name="requerying-based-on-new-parameters"></a><a name="_core_requerying_based_on_new_parameters"></a>Requerying Com base em novos parâmetros

Outro uso frequente — e igualmente importante — do [Requery](../../mfc/reference/crecordset-class.md#requery) é selecionar um novo conjunto de registros com base na alteração dos valores dos parâmetros.

> [!TIP]
> A velocidade de consulta é provavelmente significativamente mais rápida se você ligar `Requery` com valores de parâmetro sumindo do que se você ligar `Open` novamente.

## <a name="requerying-dynasets-vs-snapshots"></a><a name="_core_requerying_dynasets_vs.._snapshots"></a>Requerying Dynasets vs. Snapshots

Como os dynasets são feitos para apresentar um conjunto de registros com dados dinâmicos atualizados, você deseja requery dynasets muitas vezes se quiser refletir as adições de outros usuários. Os instantâneos, por outro lado, são úteis porque você pode confiar com segurança em seu conteúdo estático enquanto prepara relatórios, calcula totais e assim por diante. Ainda assim, às vezes você pode querer requery um instantâneo também. Em um ambiente multiusuário, os dados de instantâneo podem perder a sincronização com a fonte de dados à medida que outros usuários alteram o banco de dados.

#### <a name="to-requery-a-recordset-object"></a>Para requery um objeto de conjunto de registros

1. Ligue para a função de membro [requery](../../mfc/reference/crecordset-class.md#requery) do objeto.

Alternativamente, você pode fechar e reabrir o conjunto de discos original. Em ambos os casos, o novo conjunto de registros representa o estado atual da fonte de dados.

Por exemplo, veja [Record Views: Preenchendo uma caixa de lista a partir de um segundo conjunto de registros](../../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).

> [!TIP]
> Para `Requery` otimizar o desempenho, evite alterar o [filtro](../../data/odbc/recordset-filtering-records-odbc.md) ou [classificar](../../data/odbc/recordset-sorting-records-odbc.md)do conjunto de discos . Alterar apenas o valor `Requery`do parâmetro antes de ligar .

Se `Requery` a chamada falhar, você pode tentar novamente a chamada; caso contrário, sua aplicação deve terminar graciosamente. Uma chamada `Requery` `Open` ou pode falhar por uma série de razões. Talvez ocorra um erro de rede; ou, durante a chamada, após a divulgação dos dados existentes, mas antes de os novos dados serem obtidos, outro usuário poderá ter acesso exclusivo; ou a tabela em que seu conjunto de registros depende pode ser excluída.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)<br/>
[Conjunto de registros: criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)
