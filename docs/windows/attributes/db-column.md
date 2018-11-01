---
title: db_column (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_column
helpviewer_keywords:
- db_column attribute
ms.assetid: 58da4afc-f69c-4ae6-af9a-3f9515f56081
ms.openlocfilehash: c9c060bda4198c199ea86f0e2a33adc3275b353b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50555045"
---
# <a name="dbcolumn"></a>db_column

Associa uma coluna especificada para uma variável no conjunto de linhas.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_column(ordinal, dbtype, precision, scale, status, length) ]
```

#### <a name="parameters"></a>Parâmetros

*Ordinal*<br/>
O número de coluna ordinal (`DBCOLUMNINFO` ordinal) ou o nome de coluna (cadeia de caracteres ANSI ou Unicode) corresponde a um campo no conjunto de linhas à qual associar dados. Se você usar números, você pode ignorar ordinais consecutivos (por exemplo: 1, 2, 3, 5). O nome pode conter espaços, se o provedor OLE DB que você use suportá-lo. Por exemplo, você pode usar qualquer um dos seguintes formatos:

```cpp
[db_column("2")] TCHAR szCity[30];
[db_column(L"city_name")] TCHAR szCity[30];
```

*DbType*<br/>
(Opcional) Um banco de dados OLE [indicador de tipo](/previous-versions/windows/desktop/ms711251) para a entrada de coluna.

*precision*<br/>
(Opcional) A precisão a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição dos `bPrecision` elemento o [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845)

*Escala*<br/>
(Opcional) A escala a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição da `bScale` elemento o [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845)

*status*<br/>
(Opcional) Uma variável de membro usada para manter o status dessa coluna. O status indica se o valor da coluna é um valor de dados ou algum outro valor, como nulo. Para os valores possíveis, consulte [Status](/previous-versions/windows/desktop/ms722617) na *referência do programador DB OLE*.

*length*<br/>
(Opcional) Uma variável de membro usada para manter o tamanho da coluna em bytes.

## <a name="remarks"></a>Comentários

**db_column** associa a coluna da tabela especificada a uma variável no conjunto de linhas. Delimita os dados de membro que podem participar de OLE DB `IAccessor`-com base em associação. Este atributo define o mapa de coluna normalmente é definido usando as macros de consumidor do OLE DB [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md), [END_COLUMN_MAP](../../data/oledb/end-column-map.md), e [COLUMN_ENTRY](../../data/oledb/column-entry.md). Eles manipulam o OLE DB [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845) para associar a coluna especificada. Cada membro marcar com o **db_column** atributo ocupa uma entrada no mapa de coluna na forma de uma entrada de coluna. Portanto, chamar este atributo em que você colocaria o mapa de coluna, ou seja, na classe de comando ou tabela.

Use **db_column** em conjunto com qualquer um os [db_table](db-table.md) ou [db_command](db-command.md) atributos.

Quando o provedor do consumidor de atributo se aplica a esse atributo a uma classe, o compilador renomeará a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivada de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.

Para obter exemplos desse atributo usado em um aplicativo, consulte os exemplos [AtlAgent](https://github.com/Microsoft/VCSamples), e [MultiRead](https://github.com/Microsoft/VCSamples).

## <a name="example"></a>Exemplo

Este exemplo associa uma coluna em uma tabela para uma **longo** membro de dados e especifica os campos de status e o comprimento.

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

Este exemplo associa quatro colunas para um **longo**, uma cadeia de caracteres, um carimbo de hora e um `DB_NUMERIC` inteiro, nessa ordem.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**, membro, método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de consumidor do OLE DB](ole-db-consumer-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
