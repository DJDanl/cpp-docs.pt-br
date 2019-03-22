---
title: db_source (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_source
helpviewer_keywords:
- db_source attribute
ms.assetid: 0ec8bbf7-ade2-4899-bf4c-8608b92779bc
ms.openlocfilehash: a171e6a7eea5e10b47bf680545bc14618893b155
ms.sourcegitcommit: c1f646c8b72f330fa8cf5ddb0f8f261ba10d16f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2019
ms.locfileid: "58328981"
---
# <a name="dbsource"></a>db_source

Cria uma conexão a uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_source(db_source, name, hresult) ]
```

### <a name="parameters"></a>Parâmetros

*db_source*<br/>
A cadeia de conexão usada para se conectar à fonte de dados. Para o formato da cadeia de caracteres de conexão, consulte [cadeias de caracteres de Conexão e Links de dados](/previous-versions/windows/desktop/ms718376(v=vs.85)) no Microsoft Data Access Components (MDAC) do SDK.

*name*<br/>
(Opcional) Quando você usa **db_source** em uma classe *nome* é uma instância de um objeto de fonte de dados que tem o **db_source** atributo aplicado a ele (consulte o exemplo 1). Quando você usa **db_source** embutido na implementação de um método *nome* é uma variável (local para o método) que pode ser usada para acessar os dados de origem (consulte o exemplo 2). Você passá-la *nome* para o *source_name* parâmetro do `db_command` para associar a fonte de dados com um comando.

*hresult*<br/>
(Opcional) Identifica a variável que receberá o HRESULT desse comando de banco de dados. Se a variável não existir, ele será automaticamente injetado pelo atributo.

## <a name="remarks"></a>Comentários

**db_source** cria um [CDataSource](../../data/oledb/cdatasource-class.md) e uma [CSession](../../data/oledb/csession-class.md) objeto, que juntas representam uma conexão com uma fonte de dados do consumidor OLE DB.

Quando você usa **db_source** em uma classe, o `CSession` objeto se torna um membro da classe.

Quando você usa **db_source** em um método, o código injetado será executado dentro do escopo do método e o `CSession` objeto é criado como uma variável local.

**db_source** adiciona propriedades da fonte de dados para uma classe ou dentro de um método. Ele é usado em conjunto com `db_command` (que utiliza o *db_source* *nome* parâmetro como seu *source_name* parâmetro).

Quando o provedor do consumidor de atributo se aplica a esse atributo a uma classe, o compilador renomeará a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivada de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.

Para obter um exemplo desse atributo usado em um aplicativo, consulte os exemplos [AtlAgent](https://github.com/Microsoft/VCSamples) e [MultiRead](https://github.com/Microsoft/VCSamples).

## <a name="example"></a>Exemplo

Este exemplo chama **db_source** em uma classe para criar uma conexão à fonte de dados `ds` usando o banco de dados Northwind. `ds` é um identificador para a fonte de dados, que pode ser usado internamente para o `CMyCommand` classe.

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
