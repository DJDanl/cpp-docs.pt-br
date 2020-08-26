---
title: db_accessor (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_accessor
helpviewer_keywords:
- db_accessor attribute
ms.assetid: ec407a9f-24d7-4822-96d4-7cc6a0301815
ms.openlocfilehash: 559838201e3d1c425b6b1bf7f3650d9635c44c97
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833134"
---
# <a name="db_accessor"></a>db_accessor

Agrupa `db_column` atributos que participam de `IAccessor` associação baseada em.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_accessor(num, auto) ]
```

#### <a name="parameters"></a>parâmetros

*num*<br/>
Especifica o número do acessador (um índice de inteiro com base em zero). Você deve especificar números de acessadores em ordem crescente, usando números inteiros ou valores definidos.

*Automático*<br/>
Um valor booliano que especifica se o acessador é recuperado automaticamente (TRUE) ou não foi recuperado (FALSE).

## <a name="remarks"></a>Comentários

**db_accessor** define o acessador de OLE DB subjacente para `db_column` os atributos subsequentes e `db_param` dentro da mesma classe ou função. **db_accessor** é utilizável no nível de membro e é usado para agrupar `db_column` atributos que participam de `IAccessor` associação baseada em OLE DB. Ele é usado em conjunto com os `db_table` atributos ou `db_command` . Chamar esse atributo é semelhante a chamar as macros [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) .

**db_accessor** gera um conjunto de linhas e o associa aos mapas de acessadores correspondentes. Se você não chamar **db_accessor**, o acessador 0 será gerado automaticamente e todas as associações de coluna serão mapeadas para esse bloco de acessador.

o **db_accessor** agrupa associações de coluna de banco de dados em um ou mais acessadores. Para obter uma discussão sobre os cenários em que você precisa usar vários acessadores, consulte [usando vários acessadores em um conjunto de linhas](../../data/oledb/using-multiple-accessors-on-a-rowset.md). Consulte também "suporte ao registro de usuário para vários acessadores" em [registros de usuário](../../data/oledb/user-records.md).

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_ acessador *YourClassName*, em que *YourClassName* é o nome que você forneceu à classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_ acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

## <a name="example"></a>Exemplo

O exemplo a seguir usa **db_accessor** para agrupar colunas na tabela Orders do banco de dados Northwind em dois acessadores. O acessador 0 é um acessador automático e o acessador 1 não.

```cpp
// cpp_attr_ref_db_accessor.cpp
// compile with: /LD /link /OPT:NOREF
#define _ATL_ATTRIBUTES
#include <atlbase.h>
#include <atldbcli.h>

[ db_command(L"SELECT LastName, FirstName FROM Orders") ]
class CEmployees {
public:
   [ db_accessor(0, TRUE) ];
   [ db_column("1") ] LONG m_OrderID;
   [ db_column("2") ] TCHAR m_CustomerID[6];
   [ db_column("4") ] DBTIMESTAMP m_OrderDate;

   [ db_accessor(1, FALSE) ];
   [ db_column("8") ] CURRENCY m_Freight;
};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Blocos de atributo|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[OLE DB atributos de consumidor](ole-db-consumer-attributes.md)
