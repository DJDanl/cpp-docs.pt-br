---
title: Macros de mapa de objetos
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_OBJECT_DESCRIPTION
- atlcom/ATL::OBJECT_ENTRY_AUTO
- atlcom/ATL::OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO
ms.assetid: 680087f4-9894-41dd-a79c-6f337e1f13c1
ms.openlocfilehash: 2eb24914561a958a6d6d79dab6779e0ba0a70201
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835279"
---
# <a name="object-map-macros"></a>Macros de mapa de objetos

Essas macros definem mapas e entradas de objeto.

|Nome|Descrição|
|-|-|
|[DECLARE_OBJECT_DESCRIPTION](#declare_object_description)|Permite que você especifique a descrição de texto de um objeto de classe, que será inserido no mapa de objetos.|
|[OBJECT_ENTRY_AUTO](#object_entry_auto)|Insere um objeto ATL no mapa de objetos, atualiza o registro e cria uma instância do objeto.|
|[OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](#object_entry_non_createable_ex_auto)|Permite que você especifique que o objeto deve ser registrado e inicializado, mas não deve ser creatabledo externamente via `CoCreateInstance` .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="declare_object_description"></a><a name="declare_object_description"></a> DECLARE_OBJECT_DESCRIPTION

Permite que você especifique uma descrição de texto para seu objeto de classe.

```
DECLARE_OBJECT_DESCRIPTION( x )
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no A descrição do objeto de classe.

### <a name="remarks"></a>Comentários

A ATL insere essa descrição no mapa de objetos por meio da macro [OBJECT_ENTRY_AUTO](#object_entry_auto) .

DECLARE_OBJECT_DESCRIPTION implementa uma `GetObjectDescription` função, que pode ser usada para substituir o método [CComCoClass:: GetObjectDescription](ccomcoclass-class.md#getobjectdescription) .

A `GetObjectDescription` função é chamada por `IComponentRegistrar::GetComponents` . `IComponentRegistrar` é uma interface de automação que permite registrar e cancelar o registro de componentes individuais em uma DLL. Quando você cria um objeto de registrador de componente com o assistente de projeto ATL, o assistente implementa automaticamente a `IComponentRegistrar` interface. `IComponentRegistrar` normalmente é usado pelo Microsoft Transaction Server.

Para obter mais informações sobre o assistente de projeto do ATL, consulte o artigo [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#123](../../atl/codesnippet/cpp/object-map-macros_1.h)]

## <a name="object_entry_auto"></a><a name="object_entry_auto"></a> OBJECT_ENTRY_AUTO

Insere um objeto ATL no mapa de objetos, atualiza o registro e cria uma instância do objeto.

```
OBJECT_ENTRY_AUTO( clsid, class )
```

### <a name="parameters"></a>parâmetros

*clsid*<br/>
no O CLSID de uma classe COM implementada pela classe C++ nomeada *Class*.

*class*<br/>
no O nome da classe C++ que implementa a classe COM representada por *CLSID*.

### <a name="remarks"></a>Comentários

As macros de entrada de objeto são colocadas em escopo global no projeto para fornecer suporte para o registro, a inicialização e a criação de uma classe.

OBJECT_ENTRY_AUTO Insere os ponteiros de função das funções de classe Creator e Class-Factory Creator `CreateInstance` para esse objeto no mapa de objetos ATL gerado automaticamente. Quando [CAtlComModule:: RegisterServer](catlcommodule-class.md#registerserver) é chamado, ele atualiza o registro do sistema para cada objeto no mapa de objetos.

A tabela a seguir descreve como as informações adicionadas ao mapa de objetos são obtidas da classe fornecida como o segundo parâmetro para essa macro.

|Informações para|Obtido de|
|---------------------|-------------------|
|Registro COM|[Macros do registro](../../atl/reference/registry-macros.md)|
|Criação de fábrica de classes|[Macros de fábrica de classes](../../atl/reference/aggregation-and-class-factory-macros.md)|
|Criação de instância|[Macros de agregação](../../atl/reference/aggregation-and-class-factory-macros.md)|
|Registro de categoria de componente|[Macros de categoria](../../atl/reference/category-macros.md)|
|Inicialização e limpeza em nível de classe|[ObjectMain](ccomobjectrootex-class.md#objectmain)|

## <a name="object_entry_non_createable_ex_auto"></a><a name="object_entry_non_createable_ex_auto"></a> OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO

Permite que você especifique que o objeto deve ser registrado e inicializado, mas não deve ser creatabledo externamente via `CoCreateInstance` .

```
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO( clsid, class )
```

### <a name="parameters"></a>parâmetros

*clsid*<br/>
no O CLSID de uma classe COM implementada pela classe C++ nomeada *Class*.

*class*<br/>
no O nome da classe C++ que implementa a classe COM representada por *CLSID*.

### <a name="remarks"></a>Comentários

As macros de entrada de objeto são colocadas em escopo global no projeto para fornecer suporte para o registro, a inicialização e a criação de uma classe.

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO permite que você especifique que um objeto deve ser registrado e inicializado (consulte [OBJECT_ENTRY_AUTO](#object_entry_auto) para obter mais informações), mas não deve ser creatable por meio de `CoCreateInstance` .

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
