---
title: db_param (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_param
helpviewer_keywords:
- db_param attribute
ms.assetid: a28315f5-4722-459e-92ef-32e83c0b205a
ms.openlocfilehash: a3cfcf3c7ce3313eaff9a3b35854e1e077fc906f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59038090"
---
# <a name="dbparam"></a>db_param

Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_param(ordinal, paramtype="DBPARAMIO_INPUT", dbtype, precision, scale, status, length) ]
```

### <a name="parameters"></a>Parâmetros

*ordinal*<br/>
O número da coluna (ordinal DBCOLUMNINFO) correspondente a um campo no conjunto de linhas à qual associar dados.

*paramtype*<br/>
(Opcional) O tipo a ser definido para o parâmetro. Provedores dão suporte a apenas tipos de e/s parâmetros que têm suporte pela fonte de dados subjacente. O tipo é uma combinação de um ou mais valores DBPARAMIOENUM:

- DBPARAMIO_INPUT um parâmetro de entrada.

- DBPARAMIO_OUTPUT um parâmetro de saída.

- DBPARAMIO_NOTPARAM o acessador não tem parâmetros. Definindo `eParamIO` para esse valor na linha acessadores lembra ao usuário que os parâmetros são ignorados.

*dbtype*<br/>
(Opcional) Um banco de dados OLE [indicador de tipo](/previous-versions/windows/desktop/ms711251(v=vs.85)) para a entrada de coluna.

*precision*<br/>
(Opcional) A precisão a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição da `bPrecision` elemento o [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85))

*scale*<br/>
(Opcional) A escala a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição da `bScale` elemento o [estrutura DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85))

*status*<br/>
(Opcional) Uma variável de membro usada para manter o status dessa coluna. O status indica se o valor da coluna é um valor de dados ou algum outro valor, como nulo. Para os valores possíveis, consulte [Status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador DB OLE*.

*length*<br/>
(Opcional) Uma variável de membro usada para manter o tamanho da coluna em bytes.

## <a name="remarks"></a>Comentários

**db_param** define os parâmetros que você pode usar nos comandos; portanto, usá-lo com `db_command`. Por exemplo, você pode usar **db_param** para associar parâmetros em consultas SQL ou procedimentos armazenados. Parâmetros em um procedimento armazenado são indicados por pontos de interrogação (?), e você deve associar os membros de dados na ordem em que os parâmetros aparecem.

**db_param** delimita os dados de membro que podem participar de OLE DB `ICommandWithParameters`-com base em associação. Ele define o tipo de parâmetro (entrada ou saída), tipo de OLE DB, precisão, escala, status e comprimento para o parâmetro especificado. Esse atributo insere as macros de consumidor do OLE DB BEGIN_PARAM_MAP... END_PARAM_MAP. Cada membro marcar com o **db_param** atributo ocupa uma entrada no mapa na forma de um COLUMN_ENTRY.

**db_param** é usado em conjunto com qualquer um de [db_table](db-table.md) ou [db_command](db-command.md) atributos.

Quando o provedor do consumidor de atributo se aplica a esse atributo a uma classe, o compilador renomeará a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivada de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.

## <a name="example"></a>Exemplo

O exemplo a seguir cria uma classe de comando com base no procedimento SalesbyYear armazenado no banco de dados Northwind. Associa o primeiro parâmetro no procedimento armazenado com o `m_RETURN_VALUE` variável e a define como um parâmetro de saída. Associa os últimos dois parâmetros (entrados) com `m_Beginning_Date` e `m_Ending_Date`.

O exemplo a seguir associa o `nOutput` variável com um parâmetro de saída.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**, membro, o método, o local|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de consumidor do OLE DB](ole-db-consumer-attributes.md)
