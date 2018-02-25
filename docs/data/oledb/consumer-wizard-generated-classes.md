---
title: Classes geradas pelo Assistente do consumidor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attribute-injected classes and methods
- wizard-generated classes and methods
- OLE DB consumers, wizard-generated classes and methods
- command classes in OLE DB consumer
- classes [C++], OLE DB Consumer Wizard-generated
- consumer wizard-generated classes and methods
- user record classes in OLE DB consumer
ms.assetid: dba0538f-2afe-4354-8cbb-f202ea8ade5a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 194c71fda245663e648298af17a6ceb874aef4d5
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="consumer-wizard-generated-classes"></a>Classes geradas pelo Assistente do Consumidor
Quando você usa o ATL OLE DB consumidor Assistente para gerar um consumidor, você tem a opção de usar atributos de modelos OLE DB ou OLE DB. Em ambos os casos, o assistente gera uma classe de comando e uma classe de registro de usuário. A classe de comando contém código para abrir a fonte de dados e o conjunto de linhas que você especificou no assistente. A classe de registro de usuário contém um mapa de coluna para a tabela de banco de dados selecionado. No entanto, o código gerado é diferente em cada caso:  
  
-   Se você selecionar um consumidor de modelo, o assistente gera uma classe de comando e uma classe de registro de usuário. A classe de comando terá o nome que você inseriu na caixa de classe no Assistente (por exemplo, `CProducts`), e a classe de registro de usuário terá um nome no formato "*ClassName*acessador" (por exemplo, `CProductsAccessor`). Ambas as classes são colocadas no arquivo de cabeçalho do consumidor.  
  
-   Se você selecionar um consumidor atribuído, a classe de registro de usuário terá um nome no formato "_*ClassName*acessador" e serão injetados. Ou seja, você poderá exibir apenas a classe de comando no editor de texto; Você só pode exibir a classe de registro de usuário como código injetado. Para obter informações sobre como exibir o código injetado, consulte [depurar código injetado](/visualstudio/debugger/how-to-debug-injected-code).  
  
 Os exemplos a seguir usam uma classe de comando criada na tabela de produtos de banco de dados Northwind para demonstrar o código gerado pelo Assistente de consumidor para a classe de comando e a classe de registro de usuário.  
  
## <a name="templated-user-record-classes"></a>Classes de registro do modelo de usuário  
 Se você criar um consumidor OLE DB usando os modelos OLE DB (em vez dos atributos de banco de dados OLE), o assistente gera código, conforme descrito nesta seção.  
  
### <a name="column-data-members"></a>Membros de dados de coluna  
 A primeira parte da classe de registro de usuário inclui as declarações de membro de dados e os membros de dados de comprimento e status para cada coluna de dados associados. Para obter informações sobre esses membros de dados, consulte [membros de dados de Status de campo em acessadores de Wizard-Generated](../../data/oledb/field-status-data-members-in-wizard-generated-accessors.md).  
  
> [!NOTE]
>  Se você modificar a classe de registro de usuário ou gravar seu próprio cliente, as variáveis de dados devem vir antes das variáveis de status e comprimento.  
  
> [!NOTE]
>  Assistente de ATL OLE DB consumidor usa a **DB_NUMERIC** tipo para associar os tipos de dados numéricos. Usado anteriormente **DBTYPE_VARNUMERIC** (o formato que é descrito pelo **DB_VARNUMERIC** tipo; consulte OLEDB). Se você não usar o Assistente para criar os consumidores, é recomendável que você use **DB_NUMERIC**.  
  
```  
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
 Em seguida, o assistente define propriedades de conjunto de linhas. Se você selecionou **alteração**, **inserir**, ou **excluir** na ATL OLE DB consumidor assistente, as propriedades apropriadas são definidas aqui (DBPROP_IRowsetChange é sempre definido, em seguida, um ou mais DBPROPVAL_UP_CHANGE, DBPROPVAL_UP_INSERT e/ou DBPROPVAL_UP_DELETE, respectivamente).  
  
```  
void GetRowsetProperties(CDBPropSet* pPropSet)  
{  
   pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);  
}  
```  
  
### <a name="command-or-table-class"></a>Classe de tabela ou de comando  
 Se você especificar uma classe de comando, o assistente declara a classe de comando. código do modelo, o comando tem esta aparência:  
  
```  
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
 O assistente gera as associações de coluna ou um mapa de coluna. Para corrigir vários problemas com alguns provedores, o código a seguir pode associar colunas em uma ordem diferente daquela que relatado pelo provedor.  
  
```  
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
 Por fim, o assistente gera uma declaração de classe, como o seguinte comando:  
  
```  
class CProducts : public CCommand<CAccessor<CProductsAccessor>>  
```  
  
## <a name="attribute-injected-user-record-classes"></a>Classes de registro de usuário injetadas por atributos  
 Se você criar um consumidor OLE DB usando os atributos de banco de dados ([db_command](../../windows/db-command.md) ou [db_table](../../windows/db-table.md)), os atributos injetar uma classe de registro de usuário com um nome de formato "_*ClassName*Acessador. " Por exemplo, se você nomeou sua classe de comando `COrders`, a classe de registro de usuário será `_COrdersAccessor`. Embora a classe de registro do usuário apareça no modo de exibição de classe, clicando duas vezes nela navega para a classe de comando ou uma tabela no arquivo de cabeçalho, em vez disso. Nesses casos, você só pode exibir a declaração real da classe de registro de usuário exibindo o código injetado de atributo.  
  
 Pode haver possíveis complicações se você adicionar ou substituir os métodos consumidores atribuídos. Por exemplo, você pode adicionar uma `_COrdersAccessor` construtor para o `COrders` declaração, mas observe que na verdade isso adiciona um construtor para o injetado `COrdersAccessor` classe. Um construtor pode inicializar os colunas/parâmetros, mas não é possível criar um construtor de cópia dessa forma, porque ele não pode instanciar diretamente o `COrdersAccessor` objeto. Se precisar de um construtor (ou outro método) diretamente o `COrders` classe, é recomendável que você defina uma nova classe derivando de `COrders` e adicione os métodos necessários.  
  
 No exemplo a seguir, o assistente gera uma declaração para a classe `COrders`, mas a classe de registro de usuário `COrdersAccessor` não aparecer, porque os atributos injetá-lo.  
  
```  
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
  
 A declaração de classe do comando injetado tem esta aparência:  
  
```  
class CProducts : public CCommand<CAccessor<_CProductsAccessor>>  
```  
  
 A maioria do código injetado é igual ou semelhante para a versão de modelo. As principais diferenças estão nos métodos injetados, que são descritos em [Consumer Wizard-Generated métodos](../../data/oledb/consumer-wizard-generated-methods.md).  
  
 Para obter informações sobre como exibir o código injetado, consulte [depurar código injetado](/visualstudio/debugger/how-to-debug-injected-code).  
  
## <a name="see-also"></a>Consulte também  
 [Criando um consumidor do OLE DB usando um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)