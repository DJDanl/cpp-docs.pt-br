---
title: db_column (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_column
helpviewer_keywords:
- db_column attribute
ms.assetid: 58da4afc-f69c-4ae6-af9a-3f9515f56081
ms.openlocfilehash: 4ce57443480e35e7a4c7b9e872e41777662ddc20
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167284"
---
# <a name="db_column"></a>db_column

Associa uma coluna especificada a uma variável no conjunto de linhas.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_column(ordinal, dbtype, precision, scale, status, length) ]
```

### <a name="parameters"></a>parâmetros

*ordinal*<br/>
O número da coluna ordinal (`DBCOLUMNINFO` ordinal) ou o nome da coluna (cadeia de caracteres ANSI ou Unicode) correspondente a um campo no conjunto de linhas ao qual associar dados. Se você usar números, poderá ignorar ordinais consecutivos (por exemplo: 1, 2, 3, 5). O nome poderá conter espaços se o provedor de OLE DB usado oferecer suporte a ele. Por exemplo, você pode usar qualquer um dos seguintes formatos:

```cpp
[db_column("2")] TCHAR szCity[30];
[db_column(L"city_name")] TCHAR szCity[30];
```

*DbType*<br/>
Adicional Um [indicador de tipo](/previous-versions/windows/desktop/ms711251(v=vs.85)) de OLE DB para a entrada de coluna.

*precisão*<br/>
Adicional A precisão a ser usada para a entrada de coluna. Para obter detalhes, consulte a descrição do elemento `bPrecision` da [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85))

*scale*<br/>
Adicional A escala a ser usada para a entrada de coluna. Para obter detalhes, consulte a descrição do elemento `bScale` da [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85))

*status*<br/>
Adicional Uma variável de membro usada para manter o status desta coluna. O status indica se o valor da coluna é um valor de dados ou algum outro valor, como NULL. Para obter os valores possíveis, consulte [status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB*.

*length*<br/>
Adicional Uma variável de membro usada para manter o tamanho da coluna em bytes.

## <a name="remarks"></a>Comentários

**db_column** associa a coluna da tabela especificada a uma variável no conjunto de linhas. Ele delimita os dados do membro que podem participar de OLE DB associação baseada em `IAccessor`. Esse atributo configura o mapa de colunas normalmente definido usando as macros OLE DB consumidor [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md), [END_COLUMN_MAP](../../data/oledb/end-column-map.md)e [COLUMN_ENTRY](../../data/oledb/column-entry.md). Eles manipulam a [estrutura](/previous-versions/windows/desktop/ms716845(v=vs.85)) de OLE DB DBBINDING para associar a coluna especificada. Cada membro que você marca com o atributo **db_column** ocupará uma entrada no mapa de coluna na forma de uma entrada de coluna. Portanto, você chama esse atributo onde colocaria o mapa de coluna, ou seja, na classe Command ou Table.

Use **db_column** em conjunto com os atributos [db_table](db-table.md) ou [db_command](db-command.md) .

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_acessador *YourClassName*, em que *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

Para obter um exemplo desse atributo usado em um aplicativo, consulte [MultiRead](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer).

## <a name="example"></a>Exemplo

Este exemplo associa uma coluna em uma tabela a um membro de dados **Long** e especifica os campos de status e comprimento.

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

## <a name="example"></a>Exemplo

Este exemplo associa quatro colunas a um **longo**, uma cadeia de caracteres, um carimbo de data/hora e um `DB_NUMERIC` inteiro, nessa ordem.

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**, membro, método|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de consumidor do OLE DB](ole-db-consumer-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
