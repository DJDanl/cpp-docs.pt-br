---
title: db_source (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_source
helpviewer_keywords:
- db_source attribute
ms.assetid: 0ec8bbf7-ade2-4899-bf4c-8608b92779bc
ms.openlocfilehash: f17a4ea183a24f7bf4e88137f4536ca082efdf85
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831379"
---
# <a name="db_source"></a>db_source

Cria uma conexão com uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_source(db_source, name, hresult) ]
```

### <a name="parameters"></a>parâmetros

*db_source*<br/>
A cadeia de conexão usada para se conectar à fonte de dados. Para o formato da cadeia de conexão, consulte [cadeias de conexão e links de dados](/previous-versions/windows/desktop/ms718376(v=vs.85)) no SDK do MDAC (Microsoft Data Access Components).

*name*<br/>
Adicional Quando você usa **db_source** em uma classe, *Name* é uma instância de um objeto de fonte de dados que tem o atributo **db_source** aplicado a ele (consulte o exemplo 1). Quando você usa **db_source** embutido em uma implementação de método, *Name* é uma variável (local para o método) que pode ser usada para acessar a fonte de dados (consulte o exemplo 2). Você passa esse *nome* para o parâmetro *source_name* do `db_command` para associar a fonte de dados a um comando.

*resultado*<br/>
Adicional Identifica a variável que receberá o HRESULT deste comando de banco de dados. Se a variável não existir, ela será injetada automaticamente pelo atributo.

## <a name="remarks"></a>Comentários

**db_source** cria um objeto [CDataSource](../../data/oledb/cdatasource-class.md) e um [CSession](../../data/oledb/csession-class.md) , que juntos representam uma conexão com uma fonte de dados de consumidor OLE DB.

Quando você usa **db_source** em uma classe, o `CSession` objeto se torna um membro da classe.

Quando você usa **db_source** em um método, o código injetado será executado no escopo do método e o `CSession` objeto será criado como uma variável local.

**db_source** adiciona propriedades de fonte de dados a uma classe ou dentro de um método. Ele é usado em conjunto com `db_command` (que usa o parâmetro de *nome* *db_source* como seu parâmetro *source_name* ).

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_ acessador *YourClassName*, em que *YourClassName* é o nome que você forneceu à classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_ acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

Para obter um exemplo desse atributo usado em um aplicativo, consulte [MultiRead](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer).

## <a name="example"></a>Exemplo

Este exemplo chama **db_source** em uma classe para criar uma conexão com a fonte de dados `ds` usando o banco de dados Northwind. `ds` é um identificador para a fonte de dados, que pode ser usado internamente para a `CMyCommand` classe.

```cpp
// db_source_1.cpp
// compile with: /LD
#include <atlbase.h>
#include <atlplus.h>
#include <atldbcli.h>

[
  db_source(L"my_connection_string", name="ds"),
  db_command(L"select * from Products")
]
class CMyCommand {};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`** , membro, método, local|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[OLE DB atributos de consumidor](ole-db-consumer-attributes.md)
