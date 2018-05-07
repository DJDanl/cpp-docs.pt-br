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
ms.openlocfilehash: a3157f416cf6fb7e0fd3b5ad4797b83de218c9ef
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="recordset-requerying-a-recordset-odbc"></a>Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica como você pode usar um objeto de conjunto de registros para repetir a (ou seja, atualizar) em si do banco de dados e talvez você queira fazer isso com o [Requery](../../mfc/reference/crecordset-class.md#requery) função de membro.  
  
 As razões principais para repetir a consulta de um conjunto de registros são:  
  
-   Coloque o conjunto de registros atualizado com relação aos registros adicionados por você ou por outros usuários e os registros excluídos por outros usuários (os que excluir já são refletidos no conjunto de registros).  
  
-   Atualize o conjunto de registros com base na alteração de valores de parâmetro.  
  
##  <a name="_core_bringing_the_recordset_up_to_date"></a> Colocando o backup do conjunto de registros para data  
 Frequentemente, você deve repetir o objeto de conjunto de registros para colocá-lo atualizado. Em um ambiente de banco de dados multiusuário, outros usuários podem fazer alterações aos dados durante a vida do seu conjunto de registros. Para obter mais informações sobre quando o conjunto de registros reflete as alterações feitas por outros usuários e quando o conjunto de registros de outros usuários reflete suas alterações, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [Dynaset](../../data/odbc/dynaset.md).  
  
##  <a name="_core_requerying_based_on_new_parameters"></a> Repetir a consulta com base em parâmetros de novo  
 Outro frequentes — e igualmente importante — o uso de [Requery](../../mfc/reference/crecordset-class.md#requery) é selecionar um novo conjunto de registros com base nas alterações de valores de parâmetro.  
  
> [!TIP]
>  Velocidade de consulta é provavelmente significativamente mais rápida se você chamar **Requery** com alterando os valores de parâmetro que se você chamar **abrir** novamente.  
  
##  <a name="_core_requerying_dynasets_vs.._snapshots"></a> Repetir a consulta Dynasets vs. Instantâneos  
 Porque dynasets destinam-se para apresentar um conjunto de registros com os dados atualizados dinâmicos, você deseja repetir dynasets geralmente se você quiser refletir adições de outros usuários. Instantâneos, por outro lado, são úteis porque você pode contar com segurança em seu conteúdo estático enquanto você preparar relatórios, calcular totais e assim por diante. Ainda assim, às vezes, convém repetir um instantâneo também. Em um ambiente multiusuário, dados de instantâneo podem perder a sincronização com a fonte de dados que outros usuários alterarem o banco de dados.  
  
#### <a name="to-requery-a-recordset-object"></a>Para repetir a consulta de um objeto de conjunto de registros  
  
1.  Chamar o [Requery](../../mfc/reference/crecordset-class.md#requery) função de membro do objeto.  
  
 Como alternativa, você pode fechar e reabrir o conjunto de registros original. Em ambos os casos, o novo conjunto de registros representa o estado atual da fonte de dados.  
  
 Para obter um exemplo, consulte [exibições de registro: preenchimento de uma caixa de listagem de um segundo conjunto de registros](../../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).  
  
> [!TIP]
>  Para otimizar o **Requery** desempenho, evite alterar o conjunto de registros [filtro](../../data/odbc/recordset-filtering-records-odbc.md) ou [classificação](../../data/odbc/recordset-sorting-records-odbc.md). Alterar somente o valor do parâmetro antes de chamar **Requery**.  
  
 Se o **Requery** chamada falhar, você poderá repetir a chamada; caso contrário, o aplicativo deve ser encerrado normalmente. Uma chamada para **Requery** ou **abrir** pode falhar por qualquer um dos vários motivos. Talvez ocorre um erro de rede; ou, durante a chamada, depois que os dados existentes são liberados, mas antes que os novos dados são obtidos, outro usuário pode obter acesso exclusivo. ou a tabela da qual depende de seu conjunto de registros pode ser excluída.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)   
 [Conjunto de registros: criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)