---
title: Atualizando conjuntos de linhas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- rowsets, updating data
- updating data, rowsets
- updating rowsets
- rowsets
ms.assetid: 39588758-5c72-4254-a10d-cc2b1f473357
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5d0d34b3dee1fb4983f60c7e437c14025b4e3022
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="updating-rowsets"></a>Atualizando conjuntos de linhas
É uma operação muito básica do banco de dados atualizar ou gravar dados, o repositório de dados. No OLE DB, o mecanismo de atualização é simple: o aplicativo de consumidor define os valores dos membros de dados associados e, em seguida, grava esses valores no conjunto de linhas; o consumidor solicita que o provedor de atualizar o armazenamento de dados.  
  
 Os consumidores podem executar os seguintes tipos de atualizações no conjunto de linhas dados: definindo valores de coluna em uma linha, inserindo uma linha e a exclusão de uma linha. Para executar essas operações, a classe de modelo de banco de dados OLE [CRowset](../../data/oledb/crowset-class.md) implementa o [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) de interface e substitui os seguintes métodos de interface:  
  
-   [SetData](../../data/oledb/crowset-setdata.md) valores de coluna de alterações em uma linha de um conjunto de linhas; ela é equivalente ao comando UPDATE SQL.  
  
-   [Inserir](../../data/oledb/crowset-insert.md) insere uma linha em um conjunto de linhas; é equivalente ao comando SQL INSERT.  
  
-   [Excluir](../../data/oledb/crowset-delete.md) exclui linhas de um conjunto de linhas; é equivalente ao comando SQL DELETE.  
  
## <a name="supporting-update-operations"></a>Suporte a operações de atualização  
 Quando você cria um consumidor com o ATL OLE DB Assistente de consumidor, você pode dar suporte as operações de atualização, selecionando uma ou mais das três caixas de seleção **alteração**, **inserir**, e **excluir**. Se você selecionar esses, o assistente modifica o código adequadamente para dar suporte o tipo de alterações que você escolher. No entanto, se você não usar o assistente, você precisa definir as seguintes propriedades de conjunto de linhas `VARIANT_TRUE` para oferecer suporte a atualizações:  
  
-   **DBPROPVAL_UP_CHANGE** permite que você altere os valores de dados em uma linha.  
  
-   **DBPROPVAL_UP_INSERT** permite que você inserir uma linha.  
  
-   **DBPROPVAL_UP_DELETE** permite que você exclua uma linha.  
  
 Você pode definir as propriedades da seguinte maneira:  
  
```  
CDBPropSet ps(DBPROPSET_ROWSET);  
ps.AddProperty(DBPROP_IRowsetChange, true)  
ps.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE)  
```  
  
 Operações delete, insert ou alteração podem falhar se uma ou mais colunas não é gravável. Modifique seu mapa de cursor para corrigir o problema.  
  
## <a name="setting-data-in-rows"></a>Dados de configuração em linhas  
 [Crowset:: SetData](../../data/oledb/crowset-setdata.md) define valores de dados em uma ou mais colunas da linha atual. O código a seguir define os valores dos membros de dados associados às colunas "Nome" e "Unidades em estoque" da tabela Produtos e, em seguida, chama `SetData` para gravar esses valores para a linha 100 vezes do conjunto de linhas:  
  
```  
// Instantiate a rowset based on the user record class  
CTable<CAccessor<CProductAccessor> > product;  
CSession session;  
  
// Open the rowset and move to the 100th row  
product.Open(session, "Product", &ps, 1);  // ps is the property set  
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row  
  
// Change the values of columns "Name" and "Units in Stock" in the current row of the Product table  
_tcscpy_s( product.m_ProductName, product.m_sizeOfProductName,  
           _T( "Candle" ) );  
product.m_UnitsInStock = 10000;  
  
// Set the data  
HRESULT hr = product.SetData( );  
```  
  
## <a name="inserting-rows-into-rowsets"></a>Inserindo linhas em conjuntos de linhas  
 [Crowset:: Insert](../../data/oledb/crowset-insert.md) cria e inicializa uma nova linha usando dados de acessador. **Inserir** cria uma inteiramente nova linha após a linha atual; você precisa especificar se deseja incrementar a linha atual para a próxima linha ou deixá-la inalterada. Você pode fazer isso definindo o *bGetRow* parâmetro:  
  
```  
HRESULT Insert(int nAccessor = 0, bool bGetRow = false)  
```  
  
-   **False** (o valor padrão) Especifica que a linha atual é incrementado para a próxima linha (caso em que ele aponte para a linha inserida).  
  
-   **True** Especifica que a linha atual permanecem onde ele está.  
  
 O código a seguir define os valores dos membros de dados associados às colunas da tabela Produtos e, em seguida, chama **inserir** para inserir uma nova linha com os valores após a 100 vezes linha do conjunto de linhas. É recomendável que você defina todos os valores de coluna para evitar dados indefinidos na nova linha:  
  
```  
// Instantiate a rowset based on the user record class  
CTable<CAccessor<CProductAccessor> > product;  
CSession session;  
  
// Open the rowset and move to the 100th row  
product.Open(session, "Product", &ps, 1);  // ps is the property set  
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row  
  
// Set the column values for a row of the Product table, then insert the row  
product.m_ProductID = 101;  
_tcscpy_s( product.m_ProductName, product.m_sizeOfProductName,  
           _T( "Candle" ) );  
product.m_SupplierID = 27857;  
product.m_CategoryID = 372;  
_tcscpy_s( product.m_QuantityPerUnit, product.m_sizeOfQuantityPerUnit,  
           _T( "Pack of 10" ) );  
product.m_UnitPrice = 20;  
product.m_UnitsInStock = 10000;  
product.m_UnitsOnOrder = 5201;  
product.m_ReorderLevel = 5000;  
product.m_Discontinued = false;  
  
// You must also initialize the status and length fields before setting/inserting data  
// Set the column status values  
m_dwProductIDStatus = DBSTATUS_S_OK;  
m_dwProductNameStatus = DBSTATUS_S_OK;  
m_dwSupplierIDStatus = DBSTATUS_S_OK;  
m_dwCategoryIDStatus = DBSTATUS_S_OK;  
m_dwQuantityPerUnitStatus = DBSTATUS_S_OK;  
m_dwUnitPriceStatus = DBSTATUS_S_OK;  
m_dwUnitsInStockStatus = DBSTATUS_S_OK;  
m_dwUnitsOnOrderStatus = DBSTATUS_S_OK;  
m_dwReorderLevelStatus = DBSTATUS_S_OK;  
m_dwDiscontinuedStatus = DBSTATUS_S_OK;  
  
// Set the column length value for column data members that are not fixed-length types.  
// The value should be the length of the string that you are setting.  
m_dwProductNameLength = 6;             // "Candle" has 6 characters  
m_dwQuantityPerUnitLength = 10;        // "Pack of 10" has 10 characters  
  
// Insert the data  
HRESULT hr = product.Insert( );  
```  
  
 Para obter um exemplo mais detalhado, consulte [crowset:: Insert](../../data/oledb/crowset-insert.md).  
  
 Para obter mais informações sobre como definir o status e o comprimento de membros de dados, consulte [membros de dados de Status de campo em acessadores de Wizard-Generated](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).  
  
## <a name="deleting-rows-from-rowsets"></a>Excluindo linhas de conjuntos de linhas  
 [Crowset:: delete](../../data/oledb/crowset-delete.md) exclui a linha atual do conjunto de linhas. O código a seguir chama **excluir** para remover a 100 vezes linha do conjunto de linhas:  
  
```  
// Instantiate a rowset based on the user record class  
CTable<CAccessor<CProductAccessor> > product;  
CSession session;  
  
// Open the rowset and move to the 100th row  
product.Open(session, "Product", &ps, 1);  // ps is the property set  
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row  
  
// Delete the row  
HRESULT hr = product.Delete( );  
```  
  
## <a name="immediate-and-deferred-updates"></a>Atualizações imediatas e adiadas  
 A menos que você especifique de outra forma, chamadas para o `SetData`, **inserir**, e **excluir** métodos de atualizar o armazenamento de dados imediatamente. No entanto, você pode adiar atualizações para que o consumidor armazena todas as alterações em um cache local e, em seguida, transfere para o repositório de dados quando você chama um dos métodos de atualização a seguir:  
  
-   [Crowset:: Update](../../data/oledb/crowset-update.md) transfere todas as alterações feitas na linha atual desde a última busca pendentes ou **atualização** chamar nela.  
  
-   [Crowset:: UpdateAll](../../data/oledb/crowset-updateall.md) transfere todas as alterações feitas a todas as linhas desde a última busca pendentes ou **atualização** chamar nela.  
  
 Observe que update, conforme usado pelos métodos de atualização, tem um significado específico de fazer alterações no comando e não deve ser confundido com o comando de atualização do SQL (`SetData` é equivalente ao comando de atualização do SQL).  
  
 Atualizações adiadas são úteis, por exemplo, em situações como uma série de transações bancárias; Se uma transação for cancelada, você pode desfazer a alteração, porque você não enviar a série de alterações até depois que o último será confirmada. Além disso, o provedor pode agrupar as alterações na chamada de uma rede, que é mais eficiente.  
  
 Para oferecer suporte a atualizações adiadas, você deve definir o **DBPROP_IRowsetChange** propriedade além das propriedades descritas em "Operações de atualização com suporte":  
  
```  
pPropSet->AddProperty(DBPROP_IRowsetUpdate, true);  
```  
  
 Quando você chama **atualização** ou `UpdateAll`, os métodos de transferir as alterações do cache local para o repositório de dados e, em seguida, apagar o cache local. Como atualizar transfere alterações somente para a linha atual, é importante que seu aplicativo mantenha o controle de quais linhas update e quando atualizá-lo. O exemplo a seguir mostra como atualizar duas linhas consecutivas:  
  
```  
// Instantiate a rowset based on the user record class  
CTable<CAccessor<CProductAccessor> > product;  
CSession session;  
  
// Open the rowset and move to the 100th row  
product.Open(session, "Product", &ps, 1);  // ps is the property set  
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row  
  
// Change the values of columns "Name" and "Units in Stock" in the 100th row of the Product table  
_tcscpy_s( product.m_ProductName, product.m_sizeOfProductName,  
           _T( "Wick" ) );  
product.m_UnitsInStock = 10000;  
HRESULT hr = product.SetData( );  // No changes made to row 100 yet  
product.Update();                 // Update row 100 now  
  
// Change the values of columns "Name" and "Units in Stock" in the 101st row of the Product table  
product.MoveNext( );  
_tcscpy_s( product.m_ProductName, product.m_sizeOfProductName  
           _T( "Wax" ) );  
product.m_UnitsInStock = 500;  
HRESULT hr = product.SetData( );  // No changes made to row 101 yet  
product.Update();                 // Update row 101 now  
```  
  
 Para garantir que as alterações pendentes são transferidos, você deve chamar **atualização** antes de passar para outra linha. No entanto, quando isso é ineficiente ou entediante, por exemplo, quando seu aplicativo precisa atualizar centenas de linhas, você pode usar `UpdateAll` para atualizar todas as linhas de uma vez.  
  
 Por exemplo, se o primeiro **atualização** chamada estavam faltando no código acima, a linha 100 permanecem inalterada, enquanto a linha 101 seria alterada. Após esse ponto, seu aplicativo tem que chamar `UpdateAll` ou voltar para a linha 100 e chame **atualização** para aquela linha a ser atualizada.  
  
 Por fim, um motivo principal para adiar alterações é poderá desfazê-las. Chamando [crowset:: Undo](../../data/oledb/crowset-undo.md) reverte o estado do cache local de alteração para o estado do repositório de dados antes de todas as alterações pendentes foram feitas. É importante observar que **desfazer** não estenderá a fazer o estado do cache local por uma etapa (o estado anterior somente a alteração mais recente); em vez disso, ele limpa o cache local para aquela linha. Além disso, **desfazer** afeta somente a linha atual.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de consumidor OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)   
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx)