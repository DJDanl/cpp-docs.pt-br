---
title: db_table (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.db_table
helpviewer_keywords:
- db_table attribute
ms.assetid: ff9eb957-4e6d-4175-afcc-fd8ea916cec0
ms.openlocfilehash: dfdf012550359d0658d53b3f67c0619a124b6309
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834187"
---
# <a name="db_table"></a>db_table

Abre uma tabela OLE DB.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_table(db_table, name, source_name, hresult) ]
```

### <a name="parameters"></a>parâmetros

*db_table*<br/>
Uma cadeia de caracteres que especifica o nome de uma tabela de banco de dados (como "produtos").

*name*<br/>
Adicional O nome do identificador que você usa para trabalhar com a tabela. Você deve especificar esse parâmetro se desejar retornar mais de uma linha de resultados. **db_table** gera uma variável com o *nome* especificado que pode ser usado para percorrer o conjunto de linhas ou executar várias consultas de ação.

*source_name*<br/>
Adicional A `CSession` variável ou instância de uma classe que tem o `db_source` atributo aplicado a ela na qual o comando é executado. Consulte [db_source](db-source.md).

*resultado*<br/>
Adicional Identifica a variável que receberá o HRESULT deste comando de banco de dados. Se a variável não existir, ela será injetada automaticamente pelo atributo.

## <a name="remarks"></a>Comentários

**db_table** cria um objeto [CTable](../../data/oledb/ctable-class.md) , que é usado por um consumidor de OLE DB para abrir uma tabela. Você pode usar esse atributo somente no nível de classe; Você não pode usá-lo embutido. Use `db_column` para associar colunas de tabela a variáveis; use `db_param` para delimitar (definir o tipo de parâmetro e assim por diante) de parâmetros.

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_ acessador *YourClassName*, em que *YourClassName* é o nome que você forneceu à classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_ acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

## <a name="example"></a>Exemplo

O exemplo a seguir abre a tabela produtos para uso pelo `CProducts` .

```cpp
// db_table.cpp
// compile with: /LD
#include <atlbase.h>
#include <atlplus.h>
#include <atldbcli.h>

[ db_table(L"dbo.Products") ]
class CProducts {
   [ db_column("1") ] LONG m_ProductID;
};
```

Para obter um exemplo desse atributo usado em um aplicativo, consulte [MultiRead](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer).

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[OLE DB atributos de consumidor](ole-db-consumer-attributes.md)
