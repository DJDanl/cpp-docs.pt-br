---
title: Atualizando conjuntos de linhas
ms.date: 10/19/2018
helpviewer_keywords:
- rowsets, updating data
- updating data, rowsets
- updating rowsets
- rowsets
ms.assetid: 39588758-5c72-4254-a10d-cc2b1f473357
ms.openlocfilehash: d00b9036b216e3425615478d6bf92d239a3637d1
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556693"
---
# <a name="updating-rowsets"></a>Atualizando conjuntos de linhas

É uma operação de banco de dados básico atualizar ou gravar dados para o armazenamento de dados. No OLE DB, o mecanismo de atualização é simple: seu aplicativo de consumidor define os valores dos membros de dados associados e, em seguida, grava esses valores no conjunto de linhas; o consumidor solicita que o provedor de atualizar o armazenamento de dados.

Os consumidores podem concluir os seguintes tipos de atualizações nos dados do conjunto de linhas: definindo valores de coluna dentro de uma linha, inserindo uma linha e exclusão de uma linha. Para concluir essas operações, a classe de modelo de banco de dados OLE [CRowset](../../data/oledb/crowset-class.md) implementa a [IRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715790(v=vs.85)) de interface e substitui os seguintes métodos de interface:

- [SetData](../../data/oledb/crowset-setdata.md) valores de coluna de alterações em uma linha de um conjunto de linhas; ele equivale ao comando SQL UPDATE.

- [Inserir](../../data/oledb/crowset-insert.md) insere uma linha em um conjunto de linhas; ele equivale ao comando SQL INSERT.

- [Excluir](../../data/oledb/crowset-delete.md) exclui linhas de um conjunto de linhas; ele equivale ao comando SQL DELETE.

## <a name="supporting-update-operations"></a>Suporte a operações de atualização

Quando você cria um consumidor com o **ATL OLE DB Assistente de consumidor**, você pode dar suporte as operações de atualização, selecionando uma ou mais das três caixas de seleção **alteração**, **inserir**, e **excluir**. Se você selecionar essas opções, o assistente modifica o código adequadamente para dar suporte o tipo de alterações que você escolher. No entanto, se você não usar o assistente, você precisa definir as seguintes propriedades de conjunto de linhas `VARIANT_TRUE` para dar suporte a atualizações:

- `DBPROPVAL_UP_CHANGE` permite que você altere os valores de dados em uma linha.

- `DBPROPVAL_UP_INSERT` permite que você inserir uma linha.

- `DBPROPVAL_UP_DELETE` permite que você excluir uma linha.

Você pode definir as propriedades da seguinte maneira:

```cpp
CDBPropSet ps(DBPROPSET_ROWSET);

ps.AddProperty(DBPROP_IRowsetChange, true);
ps.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
```

Operações de exclusão, inserção ou alteração poderá falhar se uma ou mais colunas não é gravável. Modifique seu mapa de cursor para corrigir esse problema.

## <a name="setting-data-in-rows"></a>Dados de configuração em linhas

[Crowset:: SetData](../../data/oledb/crowset-setdata.md) define valores de dados em uma ou mais colunas da linha atual. O código a seguir define os valores de membros de dados associados às colunas de `Name` e `Units in Stock` da tabela `Products` e, em seguida, chama `SetData` escrever esses valores para a linha do 100 º do conjunto de linhas:

```cpp
// Instantiate a rowset based on the user record class
CTable<CAccessor<CProductAccessor>> product;
CSession session;

// Open the rowset and move to the 100th row
product.Open(session, "Product", &ps, 1);  // ps is the property set
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row

// Change the values of columns "Name" and "Units in Stock" in the current row of the Product table
_tcscpy_s(product.m_ProductName, product.m_sizeOfProductName, _T( "Candle" ) );

product.m_UnitsInStock = 10000;

// Set the data
HRESULT hr = product.SetData();
```

## <a name="inserting-rows-into-rowsets"></a>Inserindo linhas em conjuntos de linhas

[Crowset:: Insert](../../data/oledb/crowset-insert.md) cria e inicializa uma nova linha usando os dados do acessador. `Insert` cria uma totalmente nova linha após a linha atual; Você precisa especificar se deseja incrementar a linha atual para a próxima linha ou deixá-lo inalterado. Você pode fazer isso definindo a *bGetRow* parâmetro:

```cpp
HRESULT Insert(int nAccessor = 0, bool bGetRow = false)
```

- **False** (o valor padrão) Especifica que a linha atual aumentam para a próxima linha (nesse caso, ele aponta para a linha inserida).

- **True** Especifica que a linha atual fique onde ele está.

O código a seguir define os valores de membros de dados associados às colunas da tabela `Products` e, em seguida, chama `Insert` para inserir uma nova linha com esses valores após a linha do 100 º do conjunto de linhas. É recomendável que você defina todos os valores de coluna para evitar dados indefinidos na nova linha:

```cpp
// Instantiate a rowset based on the user record class
CTable<CAccessor<CProductAccessor>> product;
CSession session;

// Open the rowset and move to the 100th row
product.Open(session, "Product", &ps, 1);  // ps is the property set
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row

// Set the column values for a row of the Product table, then insert the row
product.m_ProductID = 101;
_tcscpy_s(product.m_ProductName, product.m_sizeOfProductName, _T( "Candle" ) );

product.m_SupplierID = 27857;
product.m_CategoryID = 372;
_tcscpy_s(product.m_QuantityPerUnit, product.m_sizeOfQuantityPerUnit, _T( "Pack of 10" ) );

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
HRESULT hr = product.Insert();
```

Para obter um exemplo mais detalhado, consulte [crowset:: Insert](../../data/oledb/crowset-insert.md).

Para obter mais informações sobre como definir o status e o comprimento de membros de dados, consulte [membros de dados de Status de campo em acessadores de Wizard-Generated](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).

## <a name="deleting-rows-from-rowsets"></a>Excluindo linhas de conjuntos de linhas

[Crowset:: delete](../../data/oledb/crowset-delete.md) exclui a linha atual do conjunto de linhas. O código a seguir chama `Delete` para remover a linha do 100 º do conjunto de linhas:

```cpp
// Instantiate a rowset based on the user record class
CTable<CAccessor<CProductAccessor>> product;
CSession session;

// Open the rowset and move to the 100th row
product.Open(session, "Product", &ps, 1);  // ps is the property set
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row

// Delete the row
HRESULT hr = product.Delete();
```

## <a name="immediate-and-deferred-updates"></a>Atualizações imediatas e adiadas

A menos que você especifique de outra forma, chamadas para o `SetData`, `Insert`, e `Delete` métodos de atualizar o armazenamento de dados imediatamente. No entanto, você pode, adiar atualizações de forma que o consumidor armazena todas as alterações em um cache local e, em seguida, transfere para o armazenamento de dados quando você chama um dos seguintes métodos de atualização:

- [Crowset:: Update](../../data/oledb/crowset-update.md) transfere todas as alterações feitas na linha atual desde o último fetch pendentes ou `Update` chamar nela.

- [Crowset:: UpdateAll](../../data/oledb/crowset-updateall.md) transfere todas as alterações feitas a todas as linhas desde o último fetch pendentes ou `Update` chamar nela.

Têm significado específico de fazer alterações no comando conforme usado por métodos de atualização, atualização e não deve ser confundido com o SQL **atualize** comando (`SetData` é equivalente ao SQL **atualizar** comando) .

Atualizações adiadas são úteis, por exemplo, em situações como uma série de transações bancárias; Se uma transação for cancelada, você pode desfazer a alteração, porque você não envia a série de alterações até depois que o último é confirmada. Além disso, o provedor pode agrupar as alterações em chamada de uma rede, o que é mais eficiente.

Para dar suporte a atualizações adiadas, você deve definir a `DBPROP_IRowsetChange` propriedade junto com as propriedades descritas na **que dão suporte a operações de atualização**:

```cpp
pPropSet->AddProperty(DBPROP_IRowsetUpdate, true);
```

Quando você chama `Update` ou `UpdateAll`, os métodos de transferir as alterações do cache local para o armazenamento de dados e, em seguida, apagar o cache local. Como atualizar transfere as alterações somente para a linha atual, é importante que seu aplicativo mantém o controle de qual linha deve ser update e quando para atualizá-lo. O exemplo a seguir mostra como atualizar duas linhas consecutivas:

```cpp
// Instantiate a rowset based on the user record class
CTable<CAccessor<CProductAccessor>> product;
CSession session;

// Open the rowset and move to the 100th row
product.Open(session, "Product", &ps, 1);  // ps is the property set
product.MoveToBookmark(&bookmark, 0);      // Assume that bookmark is set to 100th row

// Change the values of columns "Name" and "Units in Stock" in the 100th row of the Product table
_tcscpy_s(product.m_ProductName, product.m_sizeOfProductName, _T( "Wick" ) );

product.m_UnitsInStock = 10000;

HRESULT hr = product.SetData();  // No changes made to row 100 yet
product.Update();                 // Update row 100 now

// Change the values of columns "Name" and "Units in Stock" in the 101st row of the Product table
product.MoveNext();

_tcscpy_s(product.m_ProductName, product.m_sizeOfProductName _T( "Wax" ) );

product.m_UnitsInStock = 500;

HRESULT hr = product.SetData();  // No changes made to row 101 yet
product.Update();                 // Update row 101 now
```

Para garantir que as alterações pendentes são transferidos, você deve chamar `Update` antes de passar para outra linha. No entanto, quando isso é entediante ou ineficiente, por exemplo, quando seu aplicativo precisa para atualizar a centenas de linhas, você pode usar `UpdateAll` para atualizar todas as linhas ao mesmo tempo.

Por exemplo, se o primeiro `Update` chamada estavam faltando no código acima, a linha 100 permanece inalterada, enquanto a linha 101 seria alterada. Depois desse ponto, seu aplicativo tem que chamar `UpdateAll` ou mover de volta para a linha 100 e chamada `Update` para aquela linha a ser atualizada.

Por fim, um motivo principal para adiar as alterações é ser capaz de desfazê-las. Chamando [crowset:: Undo](../../data/oledb/crowset-undo.md) reverte o estado do cache local de alteração para o estado do repositório de dados antes que todas as alterações pendentes foram feitas. É importante observar que `Undo` não reverter de volta o estado do cache local por uma única etapa (o estado antes de apenas a alteração mais recente); em vez disso, ele limpa o cache local para aquela linha. Além disso, `Undo` afeta somente a linha atual.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)<br/>
[Classe CRowset](../../data/oledb/crowset-class.md)<br/>
[IRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715790(v=vs.85))<br/>
