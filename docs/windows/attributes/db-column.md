---
title: db_column (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_column
helpviewer_keywords:
- db_column attribute
ms.assetid: 58da4afc-f69c-4ae6-af9a-3f9515f56081
ms.openlocfilehash: 05f734a9b083d93f2501172d9455b7889c65a5a6
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91503542"
---
# <a name="db_column"></a>db_column

Associa uma coluna especificada a uma variável no conjunto de linhas.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_column(ordinal, dbtype, precision, scale, status, length) ]
```

### <a name="parameters"></a>Parâmetros

*numera*<br/>
O número ordinal da coluna ( `DBCOLUMNINFO` ordinal) ou o nome da coluna (cadeia de caracteres ANSI ou Unicode) correspondente a um campo no conjunto de linhas ao qual associar os dados. Se você usar números, poderá ignorar ordinais consecutivos (por exemplo: 1, 2, 3, 5). O nome poderá conter espaços se o provedor de OLE DB usado oferecer suporte a ele. Por exemplo, você pode usar qualquer um dos seguintes formatos:

```cpp
[db_column("2")] TCHAR szCity[30];
[db_column(L"city_name")] TCHAR szCity[30];
```

*DbType*<br/>
Adicional Um [indicador de tipo](/previous-versions/windows/desktop/ms711251(v=vs.85)) de OLE DB para a entrada de coluna.

*precisão*<br/>
Adicional A precisão a ser usada para a entrada de coluna. Para obter detalhes, consulte a descrição do `bPrecision` elemento da [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85))

*scale*<br/>
Adicional A escala a ser usada para a entrada de coluna. Para obter detalhes, consulte a descrição do `bScale` elemento da [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85))

*status*<br/>
Adicional Uma variável de membro usada para manter o status desta coluna. O status indica se o valor da coluna é um valor de dados ou algum outro valor, como NULL. Para obter os valores possíveis, consulte [status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB*.

*length*<br/>
Adicional Uma variável de membro usada para manter o tamanho da coluna em bytes.

## <a name="remarks"></a>Comentários

**db_column** associa a coluna da tabela especificada a uma variável no conjunto de linhas. Ele delimita os dados do membro que podem participar da `IAccessor` associação baseada em OLE DB. Esse atributo configura o mapa de colunas normalmente definido usando as macros OLE DB consumidor [BEGIN_COLUMN_MAP](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md#begin_column_map), [END_COLUMN_MAP](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md#end_column_map)e [COLUMN_ENTRY](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md#column_entry). Eles manipulam a [estrutura](/previous-versions/windows/desktop/ms716845(v=vs.85)) de OLE DB DBBINDING para associar a coluna especificada. Cada membro que você marca com o atributo **db_column** ocupará uma entrada no mapa de coluna na forma de uma entrada de coluna. Portanto, você chama esse atributo onde colocaria o mapa de coluna, ou seja, na classe Command ou Table.

Use **db_column** em conjunto com os atributos [db_table](db-table.md) ou [db_command](db-command.md) .

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_ acessador *YourClassName*, em que *YourClassName* é o nome que você forneceu à classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_ acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

Para obter um exemplo desse atributo usado em um aplicativo, consulte [MultiRead](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer).

## <a name="examples"></a>Exemplos

Este exemplo associa uma coluna em uma tabela a um **`long`** membro de dados e especifica os campos de status e comprimento.

```cpp
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

Este exemplo associa quatro colunas a um **`long`** , uma cadeia de caracteres, um carimbo de data/hora e um `DB_NUMERIC` inteiro, nessa ordem.

```cpp
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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`** , membro, método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[OLE DB atributos de consumidor](ole-db-consumer-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
