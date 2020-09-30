---
title: Atualizando conjuntos de linhas
ms.date: 05/09/2019
helpviewer_keywords:
- rowsets, updating data
- updating data, rowsets
- updating rowsets
- rowsets
ms.assetid: 39588758-5c72-4254-a10d-cc2b1f473357
ms.openlocfilehash: 134ab73428b7535bb34094b7d5b1952fd61a3d69
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509438"
---
# <a name="updating-rowsets"></a>Atualizando conjuntos de linhas

Uma operação de banco de dados básica consiste em atualizar ou gravar dados no armazenamento de dados. No OLE DB, o mecanismo de atualização é simples: o aplicativo de consumidor define os valores dos membros de dados associados e, em seguida, grava esses valores no conjunto de linhas; o consumidor, então, solicita que o provedor atualize o armazenamento de dados.

Os consumidores podem realizar os seguintes tipos de atualizações nos dados do conjunto de linhas: definir valores de coluna dentro de uma linha, inserir uma linha e excluir uma linha. Para concluir essas operações, a classe de modelo do OLE DB [CRowset](../../data/oledb/crowset-class.md) implementa a interface [IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85)) e substitui os seguintes métodos de interface:

- [SetData](./crowset-class.md#setdata) altera os valores de coluna em uma linha de um conjunto de linhas; equivale ao comando SQL UPDATE.

- [Insert](./crowset-class.md#insert) insere uma linha em um conjunto de linhas; equivale ao comando SQL INSERT.

- [Delete](./crowset-class.md#delete) exclui linhas de um conjunto de linhas; equivale ao comando SQL DELETE.

## <a name="supporting-update-operations"></a>Suporte a operações de atualização

> [!NOTE]
> O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](creating-a-consumer-without-using-a-wizard.md).

Ao criar um consumidor com o **Assistente de Consumidor OLE DB do ATL**, é possível ser compatível com as operações de atualização selecionando uma ou mais das três caixas de seleção **Alterar**, **Inserir** e **Excluir**. Se você selecionar essas opções, o assistente modificará o código adequadamente para ser compatível com o tipo de alteração escolhido. No entanto, se você não usar o assistente, precisará definir as seguintes propriedades do conjunto de linhas como `VARIANT_TRUE` para ser compatível com atualizações:

- `DBPROPVAL_UP_CHANGE` permite alterar os valores de dados em uma linha.

- `DBPROPVAL_UP_INSERT` permite inserir uma linha.

- `DBPROPVAL_UP_DELETE` permite excluir uma linha.

Defina as propriedades da seguinte maneira:

```cpp
CDBPropSet ps(DBPROPSET_ROWSET);

ps.AddProperty(DBPROP_IRowsetChange, true);
ps.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
```

Operações de exclusão, inserção ou alteração poderão falhar se uma ou mais colunas não forem graváveis. Modifique seu mapa de cursor para corrigir esse problema.

## <a name="setting-data-in-rows"></a>Definir dados em linhas

[CRowset::SetData](./crowset-class.md#setdata) define valores de dados em uma ou mais colunas da linha atual. O código a seguir define os valores de membros de dados associados às colunas `Name` e `Units in Stock` da tabela `Products` e, em seguida, chama `SetData` para gravar esses valores na linha 100 do conjunto de linhas:

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

## <a name="inserting-rows-into-rowsets"></a>Inserir linhas em conjuntos de linhas

[CRowset::Insert](./crowset-class.md#insert) cria e inicia uma nova linha usando os dados do acessador. `Insert` cria uma linha totalmente nova após a linha atual; especifique se deseja incrementar a linha atual na próxima linha ou deixá-la inalterada. Para fazer isso, defina o parâmetro *bGetRow*:

```cpp
HRESULT Insert(int nAccessor = 0, bool bGetRow = false)
```

- **`false`** (o valor padrão) especifica que a linha atual é incrementada para a próxima linha (nesse caso, ela aponta para a linha inserida).

- **`true`** Especifica que a linha atual permanece onde está.

O código a seguir define os valores de membros de dados associados às colunas da tabela `Products` e, em seguida, chama `Insert` para inserir uma nova linha com esses valores após a linha 100 do conjunto de linhas. É recomendável definir todos os valores de coluna para evitar dados indefinidos na nova linha:

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

Confira um exemplo mais detalhado em [CRowset::Insert](./crowset-class.md#insert).

Saiba mais sobre como definir o status e o comprimento de membros de dados em [Membros de dados de status de campo em acessadores gerados pelo assistente](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).

## <a name="deleting-rows-from-rowsets"></a>Excluir linhas dos conjuntos de linhas

[CRowset::Delete](./crowset-class.md#delete) exclui a linha atual do conjunto de linhas. O código a seguir chama `Delete` para remover a linha 100 do conjunto de linhas:

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

A menos que você especifique de outra forma, as chamadas para os métodos `SetData`, `Insert` e `Delete` atualizam o armazenamento de dados imediatamente. No entanto, você pode adiar as atualizações de forma que o consumidor armazene todas as alterações em um cache local e, em seguida, transfira-as para o armazenamento de dados ao chamar um dos seguintes métodos de atualização:

- [CRowset::Update](./crowset-class.md#update) transfere todas as alterações pendentes feitas na linha atual desde o último fetch ou chamada de `Update`.

- [CRowset::UpdateAll](./crowset-class.md#updateall) transfere todas as alterações pendentes feitas em todas as linhas desde o último fetch ou chamada de `Update`.

Update, conforme usado pelos métodos de atualização, tem a função específica de fazer alterações no comando e não deve ser confundido com o comando **UPDATE** (`SetData` é equivalente ao comando SQL **UPDATE**).

Atualizações adiadas são úteis, por exemplo, em situações como uma série de transações bancárias; se uma transação for cancelada, é possível desfazer a alteração, porque você não envia a série de alterações até que a última seja confirmada. Além disso, o provedor pode agrupar as alterações em uma chamada de rede, o que é mais eficiente.

Para ser compatível com atualizações adiadas, defina a propriedade `DBPROP_IRowsetChange` com as propriedades descritas em **Suporte a operações de atualização**:

```cpp
pPropSet->AddProperty(DBPROP_IRowsetUpdate, true);
```

Ao chamar `Update` ou `UpdateAll`, os métodos transferem as alterações do cache local para o armazenamento de dados e, em seguida, apagam o cache local. Como a atualização transfere as alterações somente para a linha atual, é importante que seu aplicativo mantenha o controle de qual linha deve ser atualizada e de quando isso deve ser feito. O exemplo a seguir mostra como atualizar duas linhas consecutivas:

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

Para garantir que as alterações pendentes sejam transferidas, você deve chamar `Update` antes de passar para outra linha. No entanto, quando isso é entediante ou ineficiente, por exemplo, quando seu aplicativo precisa atualizar centenas de linhas, é possível usar `UpdateAll` para atualizar todas as linhas ao mesmo tempo.

Por exemplo, se a primeira chamada `Update` estiver ausente do código acima, a linha 100 permanecerá inalterada, enquanto a linha 101 será alterada. Depois desse ponto, seu aplicativo teria que chamar `UpdateAll` ou retornar à linha 100 e chamar `Update` para que essa linha fosse atualizada.

Por fim, um motivo principal para adiar as alterações é ser capaz de desfazê-las. Chamar [CRowset::Undo](./crowset-class.md#undo) reverte o estado do cache de alterações local para o estado em que o armazenamento de dados estava antes que todas as alterações pendentes fossem feitas. É importante observar que `Undo` não reverte o estado do cache local em uma única etapa (o estado antes da alteração mais recente); em vez disso, ele limpa o cache local para aquela linha. Além disso, `Undo` afeta somente a linha atual.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de consumidor OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)<br/>
[Classe CRowset](../../data/oledb/crowset-class.md)<br/>
[IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85))<br/>
