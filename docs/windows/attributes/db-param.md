---
title: db_param (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_param
helpviewer_keywords:
- db_param attribute
ms.assetid: a28315f5-4722-459e-92ef-32e83c0b205a
ms.openlocfilehash: 1a32dcceae1e4e4fbc730101381eda84b5350ffd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215303"
---
# <a name="db_param"></a>db_param

Associa a variável de membro especificada com um parâmetro de entrada ou saída e delimita a variável.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_param(ordinal, paramtype="DBPARAMIO_INPUT", dbtype, precision, scale, status, length) ]
```

### <a name="parameters"></a>parâmetros

*ordinal*<br/>
O número da coluna (ordinal DBCOLUMNINFO) correspondente a um campo no conjunto de linhas ao qual associar dados.

*ParamType*<br/>
Adicional O tipo a ser definido para o parâmetro. Os provedores dão suporte apenas a tipos de e/s de parâmetro que são suportados pela fonte de dados subjacente. O tipo é uma combinação de um ou mais valores de DBPARAMIOENUM:

- DBPARAMIO_INPUT um parâmetro de entrada.

- DBPARAMIO_OUTPUT um parâmetro de saída.

- DBPARAMIO_NOTPARAM o acessador não tem parâmetros. `eParamIO`A configuração para esse valor em acessadores de linha lembra o usuário de que os parâmetros são ignorados.

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

**db_param** define os parâmetros que você usa em comandos; Portanto, você o utiliza com o `db_command` . Por exemplo, você pode usar **db_param** para associar parâmetros em consultas SQL ou procedimentos armazenados. Os parâmetros em um procedimento armazenado são indicados por pontos de interrogação (?) e você deve associar os membros de dados na ordem em que os parâmetros são exibidos.

**db_param** delimite os dados do membro que podem participar da `ICommandWithParameters` associação baseada em OLE DB. Ele define o tipo de parâmetro (entrada ou saída), OLE DB tipo, precisão, escala, status e comprimento para o parâmetro especificado. Esse atributo insere as macros OLE DB consumidor BEGIN_PARAM_MAP... END_PARAM_MAP. Cada membro marcado com o atributo **db_param** ocupará uma entrada no mapa na forma de um COLUMN_ENTRY.

**db_param** é usado em conjunto com os atributos [db_table](db-table.md) ou [db_command](db-command.md) .

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_ acessador *YourClassName*, em que *YourClassName* é o nome que você forneceu à classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_ acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

## <a name="example"></a>Exemplo

O exemplo a seguir cria uma classe de comando com base no procedimento armazenado SalesbyYear no banco de dados Northwind. Ele associa o primeiro parâmetro no procedimento armazenado à `m_RETURN_VALUE` variável e o define como um parâmetro de saída. Ele associa os dois últimos parâmetros (entrada) com `m_Beginning_Date` e `m_Ending_Date` .

O exemplo a seguir associa a `nOutput` variável a um parâmetro de saída.

```cpp
// db_param.cpp
// compile with: /LD
#include <atlbase.h>
#include <atlplus.h>
#include <atldbcli.h>

[ db_source(L"my_connection_string"),
  db_command(L"{ ? = CALL dbo.\"Sales by Year\"(?,?) }")
]
struct CSalesbyYear {
   DBSTATUS m_dwShippedDateStatus;
   DBSTATUS m_dwOrderIDStatus;
   DBSTATUS m_dwSubtotalStatus;
   DBSTATUS m_dwYearStatus;

   DBLENGTH m_dwShippedDateLength;
   DBLENGTH m_dwOrderIDLength;
   DBLENGTH m_dwSubtotalLength;
   DBLENGTH m_dwYearLength;

   // Bind columns
   [ db_column("1", status="m_dwShippedDateStatus", length="m_dwShippedDateLength") ] DBTIMESTAMP m_ShippedDate;
   [ db_column("2", status="m_dwOrderIDStatus", length="m_dwOrderIDLength") ] LONG m_OrderID;
   [ db_column("3", status="m_dwSubtotalStatus", length="m_dwSubtotalLength") ] CURRENCY m_Subtotal;
   [ db_column("4", status="m_dwYearStatus", length="m_dwYearLength") ] TCHAR m_Year[31];

   // Bind parameters
   [ db_param("1", paramtype="DBPARAMIO_OUTPUT") ] LONG m_RETURN_VALUE;
   [ db_param("2", paramtype="DBPARAMIO_INPUT") ] DBTIMESTAMP m_Beginning_Date;
   [ db_param("3", paramtype="DBPARAMIO_INPUT") ] DBTIMESTAMP m_Ending_Date;
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**, **`struct`** , membro, método, local|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[OLE DB atributos de consumidor](ole-db-consumer-attributes.md)
