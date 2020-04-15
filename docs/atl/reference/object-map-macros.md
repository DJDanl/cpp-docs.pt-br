---
title: Macros do mapa do objeto
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_OBJECT_DESCRIPTION
- atlcom/ATL::OBJECT_ENTRY_AUTO
- atlcom/ATL::OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO
ms.assetid: 680087f4-9894-41dd-a79c-6f337e1f13c1
ms.openlocfilehash: 66a418019ba506a5832c8e3ad86a3764c1186df0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326207"
---
# <a name="object-map-macros"></a>Macros do mapa do objeto

Essas macros definem mapas e entradas de objetos.

|||
|-|-|
|[DECLARE_OBJECT_DESCRIPTION](#declare_object_description)|Permite especificar a descrição do texto de um objeto de classe, que será inserido no mapa do objeto.|
|[Object_entry_auto](#object_entry_auto)|Insere um objeto ATL no mapa do objeto, atualiza o registro e cria uma instância do objeto.|
|[Object_entry_non_createable_ex_auto](#object_entry_non_createable_ex_auto)|Permite especificar que o objeto deve ser registrado e inicializado, mas não `CoCreateInstance`deve ser externamente creatable via .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="declare_object_description"></a><a name="declare_object_description"></a>DECLARE_OBJECT_DESCRIPTION

Permite especificar uma descrição de texto para o objeto de classe.

```
DECLARE_OBJECT_DESCRIPTION( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] A descrição do objeto da classe.

### <a name="remarks"></a>Comentários

AtL insere essa descrição no mapa do objeto através [da](#object_entry_auto) OBJECT_ENTRY_AUTO macro.

DECLARE_OBJECT_DESCRIPTION implementa `GetObjectDescription` uma função, que você pode usar para substituir o método [CComCoClass::GetObjectDescription.](ccomcoclass-class.md#getobjectdescription)

A `GetObjectDescription` função é `IComponentRegistrar::GetComponents`chamada por . `IComponentRegistrar`é uma interface de Automação que permite registrar e descadastrar componentes individuais em uma DLL. Quando você cria um objeto Registrador de Componentes com o `IComponentRegistrar` Assistente de Projeto ATL, o assistente implementará automaticamente a interface. `IComponentRegistrar`é normalmente usado pelo Microsoft Transaction Server.

Para obter mais informações sobre o ASSISTENTE DE PROJETO ATL, consulte o artigo [Criando um Projeto ATL](../../atl/reference/creating-an-atl-project.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#123](../../atl/codesnippet/cpp/object-map-macros_1.h)]

## <a name="object_entry_auto"></a><a name="object_entry_auto"></a>Object_entry_auto

Insere um objeto ATL no mapa do objeto, atualiza o registro e cria uma instância do objeto.

```
OBJECT_ENTRY_AUTO( clsid, class )
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[em] O CLSID de uma classe COM implementado pela classe C++ chamada *classe*.

*classe*<br/>
[em] O nome da classe C++ que implementa a classe COM representada pelo *CLSID*.

### <a name="remarks"></a>Comentários

As macros de entrada de objetos são colocadas no escopo global do projeto para fornecer suporte para o registro, inicialização e criação de uma classe.

OBJECT_ENTRY_AUTO insere os ponteiros de função das `CreateInstance` funções de classe criador e classe de criação para este objeto no mapa de objeto ATL gerado automaticamente. Quando [cAtlComModule::RegisterServer](catlcommodule-class.md#registerserver) é chamado, ele atualiza o registro do sistema para cada objeto no mapa do objeto.

A tabela abaixo descreve como as informações adicionadas ao mapa do objeto são obtidas a partir da classe dada como o segundo parâmetro para esta macro.

|Informações para|Obtido a partir de|
|---------------------|-------------------|
|Inscrição COM|[Macros de registro](../../atl/reference/registry-macros.md)|
|Criação de fábrica de classe|[Macros de fábrica de classe](../../atl/reference/aggregation-and-class-factory-macros.md)|
|Criação de instâncias|[Macros de agregação](../../atl/reference/aggregation-and-class-factory-macros.md)|
|Registro de categoria de componente|[Categorias Macros](../../atl/reference/category-macros.md)|
|Inicialização e limpeza em nível de classe|[Objectmain](ccomobjectrootex-class.md#objectmain)|

## <a name="object_entry_non_createable_ex_auto"></a><a name="object_entry_non_createable_ex_auto"></a>Object_entry_non_createable_ex_auto

Permite especificar que o objeto deve ser registrado e inicializado, mas não `CoCreateInstance`deve ser externamente creatable via .

```
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO( clsid, class )
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[em] O CLSID de uma classe COM implementado pela classe C++ chamada *classe*.

*classe*<br/>
[em] O nome da classe C++ que implementa a classe COM representada pelo *CLSID*.

### <a name="remarks"></a>Comentários

As macros de entrada de objetos são colocadas no escopo global do projeto para fornecer suporte para o registro, inicialização e criação de uma classe.

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO permite especificar que um objeto deve ser registrado e inicializado (veja [OBJECT_ENTRY_AUTO](#object_entry_auto) para `CoCreateInstance`obter mais informações), mas não deve ser creatable via .

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
