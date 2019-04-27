---
title: Macros de mapa de objeto
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_OBJECT_DESCRIPTION
- atlcom/ATL::OBJECT_ENTRY_AUTO
- atlcom/ATL::OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO
ms.assetid: 680087f4-9894-41dd-a79c-6f337e1f13c1
ms.openlocfilehash: 73dc924527bac8499adefab3d0d6b51afa500a5a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62197374"
---
# <a name="object-map-macros"></a>Macros de mapa de objeto

Essas macros definem entradas e mapas de objeto.

|||
|-|-|
|[DECLARE_OBJECT_DESCRIPTION](#declare_object_description)|Permite que você especifique a descrição de texto de um objeto classe, que será inserida no mapa de objetos.|
|[OBJECT_ENTRY_AUTO](#object_entry_auto)|Insere um objeto ATL no mapa de objetos, atualiza o registro e cria uma instância do objeto.|
|[OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](#object_entry_non_createable_ex_auto)|Permite que você especifique que o objeto deve ser registrado e inicializado, mas ele não deve ser pode ser criado externamente por meio de `CoCreateInstance`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="declare_object_description"></a>  DECLARE_OBJECT_DESCRIPTION

Permite que você especifique uma descrição de texto para seu objeto de classe.

```
DECLARE_OBJECT_DESCRIPTION( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] Descrição do objeto de classe.

### <a name="remarks"></a>Comentários

ATL insere essa descrição no mapa de objetos por meio de [OBJECT_ENTRY_AUTO](#object_entry_auto) macro.

DECLARE_OBJECT_DESCRIPTION implementa um `GetObjectDescription` função, que você pode usar para substituir o [CComCoClass::GetObjectDescription](ccomcoclass-class.md#getobjectdescription) método.

O `GetObjectDescription` função é chamada por `IComponentRegistrar::GetComponents`. `IComponentRegistrar` é uma interface de automação que lhe permite registrar e cancelar o registro de componentes individuais em uma DLL. Quando você cria um objeto do registrador de componentes com o Assistente de projeto da ATL, o assistente irá implementar automaticamente o `IComponentRegistrar` interface. `IComponentRegistrar` normalmente é usado pelo Microsoft Transaction Server.

Para obter mais informações sobre o Assistente de projeto da ATL, consulte o artigo [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#123](../../atl/codesnippet/cpp/object-map-macros_1.h)]

##  <a name="object_entry_auto"></a>  OBJECT_ENTRY_AUTO

Insere um objeto ATL no mapa de objetos, atualiza o registro e cria uma instância do objeto.

```
OBJECT_ENTRY_AUTO( clsid, class )
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[in] O CLSID de uma classe COM implementada pelo C++ classe denominada *classe*.

*class*<br/>
[in] O nome da C++ classe que implementa a classe COM representado por *clsid*.

### <a name="remarks"></a>Comentários

Macros de entrada de objeto são colocadas no escopo global no projeto para fornecer suporte para o registro, a inicialização e a criação de uma classe.

OBJECT_ENTRY_AUTO entra em ponteiros de função da classe do criador e da classe do criador de fábrica de classes `CreateInstance` funções para este objeto no mapa de objeto ATL gerado automaticamente. Quando [CAtlComModule::RegisterServer](catlcommodule-class.md#registerserver) é chamado, ele atualiza o registro do sistema para cada objeto no mapa de objetos.

A tabela a seguir descreve como as informações adicionadas ao mapa de objetos são obtidas da classe determinada como o segundo parâmetro para essa macro.

|Informações para|Obtido de|
|---------------------|-------------------|
|Registro COM|[Macros de Registro](../../atl/reference/registry-macros.md)|
|Criação da classe de fábrica|[Macros de classe de fábrica](../../atl/reference/aggregation-and-class-factory-macros.md)|
|Criação de instância|[Macros de agregação](../../atl/reference/aggregation-and-class-factory-macros.md)|
|Registro de categoria do componente|[Macros de categoria](../../atl/reference/category-macros.md)|
|Limpeza e a inicialização de nível de classe|[ObjectMain](ccomobjectrootex-class.md#objectmain)|

##  <a name="object_entry_non_createable_ex_auto"></a>  OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO

Permite que você especifique que o objeto deve ser registrado e inicializado, mas ele não deve ser pode ser criado externamente por meio de `CoCreateInstance`.

```
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO( clsid, class )
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[in] O CLSID de uma classe COM implementada pelo C++ classe denominada *classe*.

*class*<br/>
[in] O nome da C++ classe que implementa a classe COM representado por *clsid*.

### <a name="remarks"></a>Comentários

Macros de entrada de objeto são colocadas no escopo global no projeto para fornecer suporte para o registro, a inicialização e a criação de uma classe.

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO permite que você especifique que um objeto deve ser registrado e inicializado (consulte [OBJECT_ENTRY_AUTO](#object_entry_auto) para obter mais informações), mas não deve ser pode ser criado por meio de `CoCreateInstance`.

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
