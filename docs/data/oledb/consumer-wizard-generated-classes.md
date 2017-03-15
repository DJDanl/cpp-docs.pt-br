---
title: "Classes geradas pelo Assistente do Consumidor | Microsoft Docs"
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
  - "métodos e classes injetadas por atributos"
  - "classes [C++], gerados pelo Assistente do Consumidor OLE DB"
  - "classes de comando no consumidor OLE DB"
  - "métodos e classes geradas pelo assistente do consumidor"
  - "Consumidores OLE DB, métodos e classes geradas pelo assistente"
  - "classes de registro de usuário no consumidor OLE DB"
  - "métodos e classes geradas pelo assistente"
ms.assetid: dba0538f-2afe-4354-8cbb-f202ea8ade5a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes geradas pelo Assistente do Consumidor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você usa o assistente do consumidor de ATL OLE DB para gerar um consumidor, você tem a opção de usar modelos OLE DB ou atributos OLE DB.  Em ambos os casos, o assistente gerenciar uma classe de comando e uma classe de registro do usuário.  A classe do comando contém o código para abrir a fonte de dados e o conjunto de linhas que você especificou no assistente.  A classe de registro de usuário contém um mapa de coluna para a tabela de base de dados que você selecionou.  Porém, o código gerado é diferente em cada caso:  
  
-   Se você selecionar um consumidor templated, o assistente gerenciar uma classe de comando e uma classe de registro do usuário.  A classe do comando terá o nome que você insere na caixa da classe no assistente \(por exemplo, `CProducts`\), e a classe de registro do usuário terá um nome no formato “*ClassNameAccessor*” \(por exemplo, `CProductsAccessor`\).  Ambas as classes são colocadas no arquivo de cabeçalho do consumidor.  
  
-   Se você selecionar um consumidor atribuído, a classe de registro do usuário terá um nome no formato "\_*ClassName*Accessor" e será injetada.  Isto é, você poderá exibir somente a classe do comando no editor de texto; você só pode exibir a classe de registro do usuário como código SQL injetado.  Para obter informações sobre o código SQL injetado exibição, consulte [Código SQL injetado depuração](../Topic/How%20to:%20Debug%20Injected%20Code.md).  
  
 Os exemplos a seguir usam uma classe de comando criada na tabela de produtos da base de dados Northwind para demonstrar o código script MDX do consumidor da classe da classe de comando e registro do usuário.  
  
## Classes de registro do usuário de Templated  
 Se você criar um consumidor OLE DB que usa os modelos OLE DB \(em vez dos atributos de OLE DB\), o assistente gerencia o código como descrito nesta seção.  
  
### Membros de dados da coluna  
 A primeira parte da classe de registro de usuário inclui as declarações de membro de dados e os membros de dados do status e o comprimento de cada coluna associada a dados.  Para obter mais informações sobre esses membros de dados, consulte [Membros de dados de status do campo em acessadores script gerados](../Topic/Field%20Status%20Data%20Members%20in%20Wizard-Generated%20Accessors.md).  
  
> [!NOTE]
>  Se você alterar a classe de registro do usuário ou escrever seu próprio consumidor, variáveis de dados devem vir antes de variáveis de status e comprimento.  
  
> [!NOTE]
>  O assistente do consumidor de ATL OLE DB usa o tipo de **DB\_NUMERIC** para associar tipos de dados numéricos.  Usou anteriormente **DBTYPE\_VARNUMERIC** \(o formato de que é descrito pelo tipo de **DB\_VARNUMERIC** ; consulte Oledb.h\).  Se você não usar o assistente para criar consumidores, é recomendável usar **DB\_NUMERIC**.  
  
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
  
### Propriedades de conjunto de linhas  
 Em seguida, o assistente define propriedades de conjunto de linhas.  Se você selecionou **Alterar**, **Inserir**, ou **Excluir** no assistente do consumidor de ATL OLE DB, as propriedades adequadas são definidas aqui \(DBPROP\_IRowsetChange sempre é definido, em um ou mais de DBPROPVAL\_UP\_CHANGE, DBPROPVAL\_UP\_INSERT, e\/ou DBPROPVAL\_UP\_DELETE, respectivamente\).  
  
```  
void GetRowsetProperties(CDBPropSet* pPropSet)  
{  
   pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);  
   pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);  
}  
```  
  
### Classe command ou de tabela  
 Se você especificar uma classe de comando, o assistente declara a classe do comando; para o código templated, o comando tem a seguinte aparência:  
  
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
  
### Mapa de coluna  
 O assistente gerencia as associações de coluna ou o mapa da coluna.  Para corrigir vários problemas com alguns provedores, o seguinte código pode associar colunas em uma ordem diferente de aquela informada pelo provedor.  
  
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
  
### Declaração de classe  
 Finalmente, o assistente gerenciar uma declaração de classe do comando como o seguinte:  
  
```  
class CProducts : public CCommand<CAccessor<CProductsAccessor> >  
```  
  
## Classes de registro atributo injetadas do usuário  
 Se você criar um consumidor OLE DB que usa os atributos da base de dados \([db\_command](../../windows/db-command.md) ou [db\_table](../../windows/db-table.md)\), os atributos injetam uma classe de registro de usuário com um nome no formato "\_*ClassName*Accessor." Por exemplo, se você denominada sua classe `COrders`do comando, a classe de registro do usuário será `_COrdersAccessor`.  Embora a classe de registro de usuário aparece na exibição da classe, clicando duas vezes em navegue até a classe de comando ou da tabela no arquivo de cabeçalho no lugar.  Nesses casos, você só pode exibir a declaração real da classe de registro de usuário exibindo o código SQL injetado atributo.  
  
 Pode haver complicações potenciais se você adicionar ou substituir os métodos para os consumidores atribuídos.  Por exemplo, você pode adicionar um construtor de `_COrdersAccessor` à declaração de `COrders` , mas observe que na realidade essa adiciona um construtor para a classe injetada de `COrdersAccessor` .  Como o construtor pode inicializar as colunas\/parâmetros, mas não pode criar um construtor de cópia dessa forma, pois não é diretamente criar uma instância do objeto de `COrdersAccessor` .  Se você precisar de um construtor \(ou outro método\) diretamente na classe de `COrders` , é recomendável definir uma nova classe que deriva de `COrders` e adiciona os métodos necessários lá.  
  
 No exemplo a seguir, o assistente gerenciar uma declaração da classe `COrders`, mas a classe de registro `COrdersAccessor` do usuário não aparecer, como os atributos a injetam.  
  
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
  
 A declaração injetada da classe do comando é semelhante a esta:  
  
```  
class CProducts : public CCommand<CAccessor<_CProductsAccessor> >  
```  
  
 A maior parte do código SQL injetado é o mesmo que ou semelhante à versão templated.  As principais diferenças nos métodos injetados, que são descritos em [Métodos gerados para o consumidor\)](../Topic/Consumer%20Wizard-Generated%20Methods.md).  
  
 Para obter informações sobre o código SQL injetado exibição, consulte [Código SQL injetado depuração](../Topic/How%20to:%20Debug%20Injected%20Code.md).  
  
## Consulte também  
 [Criando um consumidor de banco de dados OLE sem usar um assistente](../../data/oledb/creating-an-ole-db-consumer-using-a-wizard.md)