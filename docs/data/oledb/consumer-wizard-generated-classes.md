---
title: Classes geradas pelo Assistente do Consumidor
ms.date: 05/09/2019
helpviewer_keywords:
- user record classes in OLE DB consumer
ms.assetid: dba0538f-2afe-4354-8cbb-f202ea8ade5a
ms.openlocfilehash: 3442ff484876aec9b2cd3fa93e95c4d503649ee9
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707746"
---
# <a name="consumer-wizard-generated-classes"></a>Classes geradas pelo Assistente do Consumidor


::: moniker range="vs-2019"

O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente.

::: moniker-end

::: moniker range="<=vs-2017"

Ao usar o **Assistente de Consumidor OLE DB do ATL** para gerar um consumidor, você tem a opção de usar modelos ou atributos de OLE DB. Em ambos os casos, o assistente gera uma classe de comando e uma classe de registro de usuário. A classe de comando contém código para abrir a fonte de dados e o conjunto de linhas especificado no assistente. A classe de registro de usuário contém um mapa de coluna para a tabela de banco de dados selecionada. No entanto, o código gerado é diferente em cada caso:

- Se você selecionar um consumidor com modelo, o assistente gerará uma classe de comando e uma classe de registro de usuário. A classe de comando terá o nome que você inseriu na caixa **Classe** no assistente (nesse caso, `CProducts`), e a classe de registro de usuário terá um nome no formato "*NomeClasse*Acessador" (por exemplo, `CProductsAccessor`). Ambas as classes são colocadas no arquivo de cabeçalho do consumidor.

- Se você selecionar um consumidor atribuído, a classe de registro de usuário terá um nome no formato "_*NomeClasse*Acessador" e será injetada. Ou seja, você poderá exibir apenas a classe de comando no editor de texto; só será possível exibir a classe de registro de usuário como código injetado. Saiba mais sobre como exibir o código injetado em [Depuração de código injetado](/visualstudio/debugger/how-to-debug-injected-code).

Os exemplos a seguir usam uma classe de comando criada na tabela `Products` do banco de dados `Northwind` para demonstrar o código de consumidor gerado pelo assistente para a classe de comando e a classe de registro de usuário.

## <a name="templated-user-record-classes"></a>Classes de registro de usuário com modelo

Se você criar um consumidor de OLE DB usando os modelos de OLE DB (em vez dos atributos de OLE DB), o assistente gerará código conforme descrito nesta seção.

### <a name="column-data-members"></a>Membros de dados da coluna

A primeira parte da classe de registro de usuário inclui as declarações de membro de dados e os membros de dados de status e comprimento de cada coluna de associação de dados. Saiba mais sobre esses membros de dados em [Membros de dados do status de campo em acessadores gerados pelo assistente](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).

> [!NOTE]
> Se você modificar a classe de registro de usuário ou escrever seu próprio consumidor, as variáveis de dados deverão vir antes das variáveis de status e comprimento.

> [!NOTE]
> O Assistente de Consumidor OLE DB do ATL usa o tipo `DB_NUMERIC` para associar os tipos de dados numéricos. Anteriormente, ele usava `DBTYPE_VARNUMERIC` (o formato é descrito pelo tipo `DB_VARNUMERIC`; consulte Oledb.h). Se você não usar o assistente para criar consumidores, é recomendável usar `DB_NUMERIC`.

```cpp
// Products.H : Declaration of the CProducts class

class CProductsAccessor
{
public:
   // Column data members:
   LONG m_ProductID;
   TCHAR m_ProductName[41];
   LONG m_SupplierID;
   LONG m_CategoryID;
   TCHAR m_QuantityPerUnit[21];
   CURRENCY m_UnitPrice;
   SHORT m_UnitsInStock;
   SHORT m_UnitsOnOrder;
   SHORT m_ReorderLevel;
   VARIANT_BOOL m_Discontinued;

   // Column status data members:
   DBSTATUS m_dwProductIDStatus;
   DBSTATUS m_dwProductNameStatus;
   DBSTATUS m_dwSupplierIDStatus;
   DBSTATUS m_dwCategoryIDStatus;
   DBSTATUS m_dwQuantityPerUnitStatus;
   DBSTATUS m_dwUnitPriceStatus;
   DBSTATUS m_dwUnitsInStockStatus;
   DBSTATUS m_dwUnitsOnOrderStatus;
   DBSTATUS m_dwReorderLevelStatus;
   DBSTATUS m_dwDiscontinuedStatus;

   // Column length data members:
   DBLENGTH m_dwProductIDLength;
   DBLENGTH m_dwProductNameLength;
   DBLENGTH m_dwSupplierIDLength;
   DBLENGTH m_dwCategoryIDLength;
   DBLENGTH m_dwQuantityPerUnitLength;
   DBLENGTH m_dwUnitPriceLength;
   DBLENGTH m_dwUnitsInStockLength;
   DBLENGTH m_dwUnitsOnOrderLength;
   DBLENGTH m_dwReorderLevelLength;
   DBLENGTH m_dwDiscontinuedLength;
```

### <a name="rowset-properties"></a>Propriedades do conjunto de linhas

Em seguida, o assistente define as propriedades do conjunto de linhas. Se você selecionou **Alterar**, **Inserir** ou **Excluir** no Assistente de Consumidor OLE DB do ATL, as propriedades adequadas são definidas aqui (DBPROP_IRowsetChange é sempre definida, depois uma ou mais de DBPROPVAL_UP_CHANGE, DBPROPVAL_UP_INSERT e/ou DBPROPVAL_UP_DELETE, respectivamente).

```cpp
void GetRowsetProperties(CDBPropSet* pPropSet)
{
   pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
   pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
   pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
   pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
}
```

### <a name="command-or-table-class"></a>Classe de comando ou tabela

Se você especificar uma classe de comando, o assistente declarará a classe de comando; para o código com modelo, o comando tem esta aparência:

```cpp
DEFINE_COMMAND_EX(CProductsAccessor, L" \
SELECT \
   ProductID, \
   ProductName, \
   SupplierID, \
   CategoryID, \
   QuantityPerUnit, \
   UnitPrice, \
   UnitsInStock, \
   UnitsOnOrder, \
   ReorderLevel, \
   Discontinued \
   FROM dbo.Products")
```

### <a name="column-map"></a>Mapa de coluna

Em seguida, o assistente gera as associações de coluna ou um mapa de coluna. Para corrigir vários problemas com alguns provedores, o código a seguir pode associar colunas em uma ordem diferente daquela relatada pelo provedor.

```cpp
   BEGIN_COLUMN_MAP(CProductsAccessor)
      COLUMN_ENTRY_LENGTH_STATUS(1, m_ProductID, m_dwProductIDLength, m_dwProductIDStatus)
      COLUMN_ENTRY_LENGTH_STATUS(2, m_ProductName, m_dwProductNameLength, m_dwProductNameStatus)
      COLUMN_ENTRY_LENGTH_STATUS(3, m_SupplierID, m_dwSupplierIDLength, m_dwSupplierIDStatus)
      COLUMN_ENTRY_LENGTH_STATUS(4, m_CategoryID, m_dwCategoryIDLength, m_dwCategoryIDStatus)
      COLUMN_ENTRY_LENGTH_STATUS(5, m_QuantityPerUnit, m_dwQuantityPerUnitLength, m_dwQuantityPerUnitStatus)
      _COLUMN_ENTRY_CODE(6, DBTYPE_CY, _SIZE_TYPE(m_UnitPrice), 0, 0, offsetbuf(m_UnitPrice), offsetbuf(m_dwUnitPriceLength), offsetbuf(m_dwUnitPriceStatus))
      COLUMN_ENTRY_LENGTH_STATUS(7, m_UnitsInStock, m_dwUnitsInStockLength, m_dwUnitsInStockStatus)
      COLUMN_ENTRY_LENGTH_STATUS(8, m_UnitsOnOrder, m_dwUnitsOnOrderLength, m_dwUnitsOnOrderStatus)
      COLUMN_ENTRY_LENGTH_STATUS(9, m_ReorderLevel, m_dwReorderLevelLength, m_dwReorderLevelStatus)
      _COLUMN_ENTRY_CODE(10, DBTYPE_BOOL, _SIZE_TYPE(m_Discontinued), 0, 0, offsetbuf(m_Discontinued), offsetbuf(m_dwDiscontinuedLength), offsetbuf(m_dwDiscontinuedStatus))
   END_COLUMN_MAP()
};
```

### <a name="class-declaration"></a>Declaração de classe

Por fim, o assistente gera uma declaração de classe de comando como a seguinte:

```cpp
class CProducts : public CCommand<CAccessor<CProductsAccessor>>
```

## <a name="attribute-injected-user-record-classes"></a>Classes de registro de usuário injetadas por atributos

Se você criar um consumidor de OLE DB usando os atributos de banco de dados ([db_command](../../windows/db-command.md) ou [db_table](../../windows/db-table.md)), os atributos injetarão uma classe de registro de usuário com um nome no formato "_*NomeClasse*Acessador". Por exemplo, se você nomear sua classe de comando como `COrders`, a classe de registro de usuário será `_COrdersAccessor`. Embora a classe de registro de usuário apareça em **Modo de Exibição de Classe**, clicar duas vezes nela navega para a classe de comando ou de tabela no arquivo de cabeçalho. Nesses casos, só é possível visualizar a declaração real da classe de registro de usuário exibindo o código injetado por atributo.

É possível que haja complicações se você adicionar ou substituir métodos em consumidores atribuídos. Por exemplo, você pode adicionar um construtor `_COrdersAccessor` à declaração `COrders`, mas observe que, na verdade, isso adiciona um construtor à classe injetada `COrdersAccessor`. Esse construtor pode iniciar as colunas/parâmetros, mas não é possível criar um construtor de cópia dessa forma, porque ele não pode instanciar diretamente o objeto `COrdersAccessor`. Se você precisar de um construtor (ou outro método) diretamente na classe `COrders`, é recomendável definir uma nova classe que derive de `COrders` e adicionar os métodos necessários lá.

No exemplo a seguir, o assistente gera uma declaração para a classe `COrders`, mas a classe de registro de usuário `COrdersAccessor` não é exibida, pois os atributos a injetam.

```cpp
#define _ATL_ATTRIBUTES
#include <atlbase.h>
#include <atldbcli.h>
[
   db_source(L"your connection string"),
   db_command(L"Select ShipName from Orders;")
]
class COrders
{
public:

   // COrders()            // incorrect constructor name
   _COrdersAccessor()      // correct constructor name
   {
   }
      [db_column(1) ] TCHAR m_ShipName[41];
   };
```

A declaração de classe de comando injetada tem esta aparência:

```cpp
class CProducts : public CCommand<CAccessor<_CProductsAccessor>>
```

A maior parte do código injetado é igual ou semelhante à versão com modelo. As principais diferenças estão nos métodos injetados, que são descritos em [Métodos gerados pelo Assistente do Consumidor](../../data/oledb/consumer-wizard-generated-methods.md).

Saiba mais sobre como exibir o código injetado em [Depuração de código injetado](/visualstudio/debugger/how-to-debug-injected-code).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um consumidor do OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)