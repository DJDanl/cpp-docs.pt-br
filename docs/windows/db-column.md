---
title: db_column | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.db_column
dev_langs:
- C++
helpviewer_keywords:
- db_column attribute
ms.assetid: 58da4afc-f69c-4ae6-af9a-3f9515f56081
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 35ab2472ac9e46b620ca735d06b23806126871e0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879627"
---
# <a name="dbcolumn"></a>db_column
Associa uma coluna especificada em uma variável no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `ordinal`  
 O número de coluna ordinal (**DBCOLUMNINFO** ordinal) ou o nome de coluna (cadeia de caracteres ANSI ou Unicode) correspondente a um campo no conjunto de linhas para o qual associar dados. Se você usar números, você pode ignorar ordinais consecutivos (por exemplo: 1, 2, 3, 5). O nome pode conter espaços, se o provedor OLE DB que você use dá suporte a ele. Por exemplo, você pode usar qualquer um dos seguintes formatos:  
  
```  
[db_column("2")] TCHAR szCity[30];  
[db_column(L"city_name")] TCHAR szCity[30];  
```  
  
 *DbType* (opcional)  
 OLE DB [indicador de tipo](https://msdn.microsoft.com/en-us/library/ms711251.aspx) para a entrada da coluna.  
  
 *precisão* (opcional)  
 A precisão a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição do `bPrecision` elemento o [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *escala* (opcional)  
 A escala a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição do `bScale` elemento o [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *status* (opcional)  
 Uma variável de membro usada para manter o status dessa coluna. O status indica se o valor da coluna é um valor de dados ou algum outro valor, como **nulo**. Para obter os valores possíveis, consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE*.  
  
 *comprimento* (opcional)  
 Uma variável de membro usada para manter o tamanho da coluna em bytes.  
  
## <a name="remarks"></a>Comentários  
 **db_column** associa a coluna especificada em uma variável no conjunto de linhas. Ele delimita os dados de membro que podem participar de OLE DB `IAccessor`-com base em associação. Esse atributo define o mapa de coluna normalmente definido usando as macros de consumidor OLE DB [BEGIN_COLUMN_MAP](../data/oledb/begin-column-map.md), [END_COLUMN_MAP](../data/oledb/end-column-map.md), e [COLUMN_ENTRY](../data/oledb/column-entry.md). Esses manipulam o OLE DB [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) para associar a coluna especificada. Cada membro que você marca com o **db_column** atributo ocupará uma entrada no mapa de coluna na forma de uma entrada de coluna. Portanto, você chama esse atributo onde você deve colocar o mapa de coluna, ou seja, a classe de comando ou uma tabela.  
  
 Use **db_column** em conjunto com o o [db_table](../windows/db-table.md) ou [db_command](../windows/db-command.md) atributos.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador irá renomear a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome atribuído a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivado de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as classes.  
  
 Para obter exemplos desse atributo usado em um aplicativo, consulte os exemplos [AtlAgent](http://msdn.microsoft.com/en-us/52bef5da-c1a0-4223-b4e6-9e464b6db409), e [MultiRead](http://msdn.microsoft.com/en-us/5a2a915a-77dc-492f-94b2-1b809995dd5e).  
  
## <a name="example"></a>Exemplo  
 Este exemplo associa uma coluna em uma tabela para um **longo** membro de dados e especifica os campos de comprimento e status.  
  
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
  
## <a name="example"></a>Exemplo  
 Este exemplo associa quatro colunas para um **longo**, uma cadeia de caracteres, um carimbo de hora e um **DB_NUMERIC** inteiro, nessa ordem.  
  
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
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, membro, método|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
