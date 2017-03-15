---
title: "Atualizando conjuntos de linhas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conjuntos de linhas"
  - "conjuntos de linhas, atualizando dados"
  - "atualizando dados, conjuntos de linhas"
  - "atualizando conjuntos de linhas"
ms.assetid: 39588758-5c72-4254-a10d-cc2b1f473357
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualizando conjuntos de linhas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma operação de base de dados muito básica é atualizar, ou gravar dados no, no armazenamento de dados.  No OLE DB, o mecanismo de atualização é simples: seu aplicativo do consumidor define os valores de membros de dados associados e então escreverá esses valores ao conjunto de linhas; o consumidor solicita que a atualização do provedor o repositório de dados.  
  
 Os consumidores podem executar os seguintes tipos de atualizações em dados do conjunto de linhas: definindo valores de coluna em uma linha, inserindo uma linha, e exclusão de uma linha.  Para executar essas operações, as ferramentas de [CRowset](../Topic/CRowset%20Class.md) da classe do modelo de OLE DB a interface e substituições de [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) os seguintes métodos da interface:  
  
-   valores de coluna das alterações de[SetData](../../data/oledb/crowset-setdata.md) em uma linha de um conjunto de linhas; é equivalente ao comando UPDATE do SQL.  
  
-   [Inserção](../../data/oledb/crowset-insert.md) insere uma linha em um conjunto de linhas; é equivalente ao comando SQL INSERT.  
  
-   linhas de exclusão de[Excluir](../../data/oledb/crowset-delete.md) de um conjunto de linhas; é equivalente ao comando SQL DELETE.  
  
## Operações de atualização de suporte  
 Quando você cria um consumidor com o assistente do consumidor de ATL OLE DB, você pode oferecer suporte a operações de atualização selecionando uma ou mais das três caixas de seleção **Alterar**, **Inserir**, e **Excluir**.  Se você selecionar esse caso, o assistente altera o código apropriadamente para dar suporte ao tipo de alteração que você escolher.  No entanto, se você não usar o assistente, você precisa definir as seguintes propriedades de conjunto de linhas a `VARIANT_TRUE` para oferecer suporte a atualizações:  
  
-   **DBPROPVAL\_UP\_CHANGE** permite alterar os valores de dados em uma linha.  
  
-   **DBPROPVAL\_UP\_INSERT** permite inserir uma linha.  
  
-   **DBPROPVAL\_UP\_DELETE** permite excluir uma linha.  
  
 Você define as propriedades da seguinte maneira:  
  
```  
CDBPropSet ps(DBPROPSET_ROWSET);  
ps.AddProperty(DBPROP_IRowsetChange, true)  
ps.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE)  
```  
  
 Alterar, inserir\-se, ou as operações de exclusão podem falhar se uma ou mais colunas não são gravável.  Modifique seu mapa de cursor para corrigir isso.  
  
## Dados de configuração em linhas  
 [CRowset::SetData](../../data/oledb/crowset-setdata.md) define os valores de dados em uma ou mais colunas da linha atual.  Os seguintes conjuntos de códigos os valores de limite de membros de dados para as colunas “name” e “dirige” em estoque de produtos da tabela e chamar `SetData` para gravar esses valores com 100th linha do conjunto de linhas:  
  
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
  
## Ao inserir linhas em conjuntos de linhas  
 [CRowset::Insert](../../data/oledb/crowset-insert.md) cria e inicializa uma nova linha usando dados do acessador.  **Inserir** cria uma linha completamente novo depois da linha atual; você precisa especificar se o incremento da linha atual para a próxima linha ou deixá\-la inalterado.  Você faz isso ao definir o parâmetro *de bGetRow* :  
  
```  
HRESULT Insert(int nAccessor = 0, bool bGetRow = false)  
```  
  
-   **false** \(o valor padrão\) especifica que o incremento atual da linha seguinte \(nesse caso aponta para a linha inserida\).  
  
-   **true** especifica que a linha atual permanece onde é.  
  
 Os seguintes conjuntos de códigos os valores de limite de membros de dados para as colunas dos produtos da tabela e chamar **Inserir** para inserir uma nova linha com esses valores após a 100th linha do conjunto de linhas.  É recomendável definir todos os valores de coluna para evitar dados definidos na nova linha:  
  
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
  
 Para obter um exemplo mais detalhadas, consulte [CRowset::Insert](../../data/oledb/crowset-insert.md).  
  
 Para obter mais informações sobre como definir os membros de dados de status e comprimento, consulte [Coloque membros de dados de status em acessadores script gerados](../Topic/Field%20Status%20Data%20Members%20in%20Wizard-Generated%20Accessors.md).  
  
## Excluindo linhas dos conjuntos de linhas  
 [CRowset::Delete](../../data/oledb/crowset-delete.md) exclui a linha atual do conjunto de linhas.  O código a seguir chama **Excluir** para remover a 100th linha do conjunto de linhas:  
  
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
  
## Atualizações imediatas e adiadas  
 A menos que você especifique de outra forma, as chamadas para `SetData`, a **Inserir**, os métodos e de **Excluir** atualiza o repositório de dados imediatamente.  É possível, contudo, adiar atualizações de modo que ele armazena todas as alterações em um cache local e a transferir no repositório de dados quando você chama um dos seguintes métodos de atualização:  
  
-   [CRowset::Update](../Topic/CRowset::Update.md) transfere todas as alterações pendentes feitas à linha atual desde que o a última busca ou **Atualizar** o chamam.  
  
-   [CRowset::UpdateAll](../../data/oledb/crowset-updateall.md) transfere todas as alterações pendentes feitas em todas as linhas desde que o a última busca ou **Atualizar** o chamam.  
  
 Observe que a atualização, como usada pelos métodos de atualização, tem um significado específico de fazer alterações no comando e não deve ser confundido com o comando UPDATE do SQL \(`SetData` é equivalente ao comando UPDATE do SQL\).  
  
 As atualizações adiadas são úteis, por exemplo, em situações como uma série de transações de serviços bancários; se uma transação for cancelada, você pode desfazer a alteração, pois você não envia a série de alterações até depois da última é confirmado.  Além disso, o provedor pode agrupar as alterações em uma chamada de rede, que é mais eficiente.  
  
 Para oferecer suporte a atualizações adiadas, você deve definir a propriedade de **DBPROP\_IRowsetChange** além das propriedades descritas em “operações de atualização de suporte”:  
  
```  
pPropSet->AddProperty(DBPROP_IRowsetUpdate, true);  
```  
  
 Quando você chama **Atualizar** ou `UpdateAll`, as alterações da transferência dos métodos do cache local ao repositório de dados e em para limpar o cache local.  Porque a atualização transfere as alterações apenas para a linha atual, é importante que se seu aplicativo mantiver o controle de linha para atualizar e quando a atualização.  O exemplo a seguir mostra como atualizar duas linhas sucessivas:  
  
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
  
 Para assegurar que as alterações pendentes sejam transferidos, você deve chamar **Atualizar** antes de passar para outra linha.  No entanto, quando este é fastidioso ou ineficiente, por exemplo, quando o aplicativo precisa atualizar centenas de linhas, você pode usar `UpdateAll` para atualização imediata todas as linhas.  
  
 Por exemplo, se a primeira chamada de **Atualizar** estiver ausente do código anterior, a linha 100 permaneceria inalterado, quando a linha 101 seria alterada.  Depois desse ponto, o aplicativo precisará chamar `UpdateAll` ou mover de para a linha 100 e chamar **Atualizar** para essa linha é atualizada.  
  
 Finalmente, uma razão principal adiar alterações é poder desfazer.  A chamada [CRowset::Undo](../../data/oledb/crowset-undo.md) reverteu o estado do cache local da alteração do estado do repositório de dados antes de todas as alterações pendentes foram feitas.  É importante observar que **Desfazer** não reverte o estado do cache local por uma etapa \(somente estado antes da alteração mais recente\); em vez disso, limpa o cache local de aquela linha.  Além disso, **Desfazer** afeta somente a linha atual.  
  
## Consulte também  
 [Trabalhando com modelos de consumidor de banco de dados OLE](../../data/oledb/working-with-ole-db-consumer-templates.md)   
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx)