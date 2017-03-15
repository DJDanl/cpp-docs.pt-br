---
title: "db_column | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.db_column"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "db_column attribute"
ms.assetid: 58da4afc-f69c-4ae6-af9a-3f9515f56081
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# db_column
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Vincula uma coluna especificada para uma variável no conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      [ db_column(   
   ordinal,   
   dbtype,   
   precision,   
   scale,   
   status,   
   length   
) ]  
```  
  
#### Parâmetros  
 `ordinal`  
 O número ordinal de coluna \(**DBCOLUMNINFO** ordinal\) ou o nome de coluna \(seqüência de caracteres ANSI ou Unicode\) correspondente a um campo no conjunto de linhas ao qual vincular dados.  Se você usar números, você pode ignorar ordinais consecutivos \(por exemplo: 1, 2, 3, 5\).  O nome pode conter espaços, se o provedor do OLE DB que você use compatível.  Por exemplo, você pode usar qualquer um dos seguintes formatos:  
  
```  
[db_column("2")] TCHAR szCity[30];  
[db_column(L"city_name")] TCHAR szCity[30];  
```  
  
 *DbType*  \(opcional\)  
 Um OLE DB  [Indicador do tipo](https://msdn.microsoft.com/en-us/library/ms711251.aspx) para a entrada de coluna.  
  
 *Precision*  \(opcional\)  
 A precisão a ser usado para a entrada de coluna.  Para obter detalhes, consulte a descrição da `bPrecision` elemento da  [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *escala*  \(opcional\)  
 A escala a ser usado para a entrada de coluna.  Para obter detalhes, consulte a descrição do `bScale` elemento da  [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *status*  \(opcional\)  
 Uma variável de membro usada para manter o status desta coluna.  O status indica se o valor da coluna é um valor de dados ou algum outro valor, como  **Nulo**.  Para obter valores possíveis, consulte  [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) na  *referência OLE DB Programmer*.  
  
 *comprimento de*  \(opcional\)  
 Uma variável de membro usada para manter o tamanho da coluna em bytes.  
  
## Comentários  
 **db\_column** vincula\-se a coluna da tabela especificada para uma variável no conjunto de linhas.  Ela delimita os dados de membros que podem participar do OLE DB `IAccessor`\-com base em ligação.  Este atributo define o mapa de coluna normalmente definido usando\-se as macros de consumidor do OLE DB  [BEGIN\_COLUMN\_MAP](../Topic/BEGIN_COLUMN_MAP.md),  [END\_COLUMN\_MAP](../data/oledb/end-column-map.md), e  [COLUMN\_ENTRY](../data/oledb/column-entry.md).  Elas manipulam o OLE DB  [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) para vincular a coluna especificada.  Cada membro que você marcou com o  **db\_column** atributo ocupará uma entrada no mapa de coluna na forma de uma entrada de coluna.  Portanto, chamar este atributo onde você deve colocar o mapa de coluna, ou seja, a classe de comando ou a tabela.  
  
 Use  **db\_column** em conjunto com qualquer um o  [db\_table](../windows/db-table.md) ou  [db\_command](../windows/db-command.md) atributos.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo para uma classe, o compilador irá renomear a classe para \_*YourClassName*acessador, onde  *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada  *YourClassName,*  que é derivada de \_*YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.  
  
 Para obter exemplos deste atributo usado em um aplicativo, consulte os exemplos de  [AtlAgent](http://msdn.microsoft.com/pt-br/52bef5da-c1a0-4223-b4e6-9e464b6db409), e  [MultiRead](http://msdn.microsoft.com/pt-br/5a2a915a-77dc-492f-94b2-1b809995dd5e).  
  
## Exemplo  
 Este exemplo vincula a uma coluna em uma tabela para um  **longo** membro de dados e especifica os campos status e de comprimento.  
  
```  
// db_column_1.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[ db_command(L"Select * from Products") ]  
class CProducts {  
   DBSTATUS m_dwProductIDStatus;  
   DBLENGTH m_dwProductIDLength;  
  
   [ db_column("1", status="m_dwProductIDStatus", length="m_dwProductIDLength") ] LONG m_ProductID;  
};  
```  
  
## Exemplo  
 Este exemplo vincula quatro colunas para um  **longo**, uma seqüência de caracteres, um carimbo de hora e um  **DB\_NUMERIC** inteiro, nessa ordem.  
  
```  
// db_column_2.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[ db_command(L"Select * from Products") ]  
class CProducts {  
   [db_column("1")] LONG m_OrderID;  
   [db_column("2")] TCHAR m_CustomerID[6];  
   [db_column("4")] DB_NUMERIC m_OrderDate;     
   [db_column("7", dbtype="DBTYPE_NUMERIC")] DB_NUMERIC m_ShipVia;  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**, `struct`, membro, método|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [OLE DB Consumer Attributes](../windows/ole-db-consumer-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)