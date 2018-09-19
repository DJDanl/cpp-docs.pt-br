---
title: 'Conjunto de registros: Repetindo consulta a um conjunto de registros (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- recordsets, requerying
- requerying recordsets
- Requery method
- ODBC recordsets, requerying
- refreshing recordsets
ms.assetid: 4ebc3b5b-5b91-4f51-a967-245223c6b8e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: efbc1b14bef93e801c52964f54053310273be853
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116876"
---
# <a name="recordset-requerying-a-recordset-odbc"></a>Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)

Este tópico se aplica às classes ODBC do MFC.  
  
Este tópico explica como você pode usar um objeto recordset para repetir a (ou seja, atualizar) em si do banco de dados e você talvez queira fazer isso com o [Requery](../../mfc/reference/crecordset-class.md#requery) função de membro.  
  
Os principais motivos para repetindo consulta a um conjunto de registros são:  
  
- Traga o conjunto de registros atualizado em relação a registros adicionados por você ou por outros usuários e registros excluídos por outros usuários (aqueles que excluir já são refletidas no conjunto de registros).  
  
- Atualize o conjunto de registros com base na alteração de valores de parâmetro.  
  
##  <a name="_core_bringing_the_recordset_up_to_date"></a> Trazendo o conjunto de registros de cima para data  

Com frequência, você desejará requery seu objeto de conjunto de registros para colocá-lo atualizado. Em um ambiente de banco de dados multiusuário, outros usuários podem fazer alterações aos dados durante o ciclo de vida de seu conjunto de registros. Para obter mais informações sobre quando o seu conjunto de registros reflete as alterações feitas por outros usuários e quando os conjuntos de registros de outros usuários refletem suas alterações, consulte [conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [Dynaset](../../data/odbc/dynaset.md).  
  
##  <a name="_core_requerying_based_on_new_parameters"></a> Repetir a consulta com base em novos parâmetros  

Outro frequentes — e igualmente importante — uso de [Requery](../../mfc/reference/crecordset-class.md#requery) é selecionar um novo conjunto de registros com base na alteração de valores de parâmetro.  
  
> [!TIP]
>  Velocidade de consulta é provavelmente significativamente mais rápida se você chamar `Requery` com a alteração de valores de parâmetro que se você chamar `Open` novamente.  
  
##  <a name="_core_requerying_dynasets_vs.._snapshots"></a> Repetindo consulta Dynasets vs. Instantâneos  

Como dynasets destinam-se para apresentar um conjunto de registros dinâmicos dados atualizados, convém requery dynasets geralmente se quiser refletir adições de outros usuários. Instantâneos, por outro lado, são úteis porque é possível confiar tranquilamente em seu conteúdo estático enquanto você preparar relatórios, calcular totais e assim por diante. Ainda assim, às vezes, convém repetir um instantâneo também. Em um ambiente multiusuário, dados de instantâneo podem perder a sincronização com a fonte de dados à medida que outros usuários alteram o banco de dados.  
  
#### <a name="to-requery-a-recordset-object"></a>Para repetir a consulta de um objeto recordset  
  
1. Chame o [Requery](../../mfc/reference/crecordset-class.md#requery) função de membro do objeto.  
  
Como alternativa, você pode fechar e reabrir o conjunto de registros original. Em ambos os casos, o novo conjunto de registros representa o estado atual da fonte de dados.  
  
Por exemplo, consulte [exibições de registro: preenchendo uma caixa de listagem de um segundo conjunto de registros](../../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).  
  
> [!TIP]
>  Para otimizar `Requery` desempenho, evite alterar o conjunto de registros [filtro](../../data/odbc/recordset-filtering-records-odbc.md) ou [classificação](../../data/odbc/recordset-sorting-records-odbc.md). Alterar apenas o valor do parâmetro antes de chamar `Requery`.  
  
Se o `Requery` chamar falhar, você pode repetir a chamada; caso contrário, seu aplicativo é encerrado normalmente. Uma chamada para `Requery` ou `Open` pode falhar por vários motivos. Talvez ocorre um erro de rede; ou, durante a chamada, após os dados existentes são liberados, mas antes dos novos dados são obtidos, outro usuário pode obter acesso exclusivo. ou a tabela da qual depende de seu conjunto de registros pode ser excluída.  
  
## <a name="see-also"></a>Consulte também  

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)<br/>
[Conjunto de registros: criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)