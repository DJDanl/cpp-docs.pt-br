---
title: Classe CAtlBaseModule
ms.date: 11/04/2016
f1_keywords:
- CAtlBaseModule
- ATLCORE/ATL::CAtlBaseModule
- ATLCORE/ATL::CAtlBaseModule::CAtlBaseModule
- ATLCORE/ATL::CAtlBaseModule::AddResourceInstance
- ATLCORE/ATL::CAtlBaseModule::GetHInstanceAt
- ATLCORE/ATL::CAtlBaseModule::GetModuleInstance
- ATLCORE/ATL::CAtlBaseModule::GetResourceInstance
- ATLCORE/ATL::CAtlBaseModule::RemoveResourceInstance
- ATLCORE/ATL::CAtlBaseModule::SetResourceInstance
- ATLCORE/ATL::CAtlBaseModule::m_bInitFailed
helpviewer_keywords:
- CAtlBaseModule class
ms.assetid: 55ade80c-9b0c-4c51-933e-2158436c1096
ms.openlocfilehash: a55412eff18fd04ac4e41c0f001991c1cf725b9f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321502"
---
# <a name="catlbasemodule-class"></a>Classe CAtlBaseModule

Esta classe é instanciada em todos os projetos ATL.

## <a name="syntax"></a>Sintaxe

```
class CAtlBaseModule : public _ATL_BASE_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlBaseModule::CAtlBaseModule](#catlbasemodule)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlBaseModule::Adicionar instância de recursos](#addresourceinstance)|Adiciona uma instância de recurso à lista de alças armazenadas.|
|[CAtlBaseModule::GetHInstanceAt](#gethinstanceat)|Retorna uma alça para uma instância de recurso especificada.|
|[CAtlBaseModule::GetModuleInstance](#getmoduleinstance)|Retorna a instância `CAtlBaseModule` do módulo de um objeto.|
|[CAtlBaseModule::GetResourceInstance](#getresourceinstance)|Retorna a instância `CAtlBaseModule` de recurso de um objeto.|
|[CAtlBaseModule::RemoveResourceInstance](#removeresourceinstance)|Remove uma instância de recurso da lista de alças armazenadas.|
|[CAtlBaseModule::SetResourceInstance](#setresourceinstance)|Define a instância `CAtlBaseModule` de recurso de um objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlBaseModule::m_bInitFailed](#m_binitfailed)|Uma variável que indica se a inicialização do módulo falhou.|

## <a name="remarks"></a>Comentários

Uma instância `CAtlBaseModule` de _AtlBaseModule nomeada está presente em todos os projetos ATL, contendo uma alça para a instância do módulo, uma alça para o módulo contendo recursos (que por padrão, são um e o mesmo), e um conjunto de alças para módulos que fornecem recursos primários. `CAtlBaseModule`pode ser acessado com segurança a partir de vários segmentos.

Esta classe substitui a obsoleta classe [CComModule](../../atl/reference/ccommodule-class.md) usada em versões anteriores do ATL.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module)

`CAtlBaseModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="catlbasemoduleaddresourceinstance"></a><a name="addresourceinstance"></a>CAtlBaseModule::Adicionar instância de recursos

Adiciona uma instância de recurso à lista de alças armazenadas.

```
bool AddResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*Hinst*<br/>
A instância de recurso para adicionar.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o recurso foi adicionado com sucesso, falso de outra forma.

## <a name="catlbasemodulecatlbasemodule"></a><a name="catlbasemodule"></a>CAtlBaseModule::CAtlBaseModule

O construtor.

```
CAtlBaseModule() throw();
```

### <a name="remarks"></a>Comentários

Cria o `CAtlBaseModule`.

## <a name="catlbasemodulegethinstanceat"></a><a name="gethinstanceat"></a>CAtlBaseModule::GetHInstanceAt

Retorna uma alça para uma instância de recurso especificada.

```
HINSTANCE GetHInstanceAt(int i) throw();
```

### <a name="parameters"></a>Parâmetros

*Eu*<br/>
O número da instância de recurso.

### <a name="return-value"></a>Valor retornado

Retorna a alça para a instância de recurso ou NULL se não houver instância de recurso correspondente.

## <a name="catlbasemodulegetmoduleinstance"></a><a name="getmoduleinstance"></a>CAtlBaseModule::GetModuleInstance

Retorna a instância `CAtlBaseModule` do módulo de um objeto.

```
HINSTANCE GetModuleInstance() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a instância do módulo.

## <a name="catlbasemodulegetresourceinstance"></a><a name="getresourceinstance"></a>CAtlBaseModule::GetResourceInstance

Retorna a instância de recurso.

```
HINSTANCE GetResourceInstance() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a instância de recurso.

## <a name="catlbasemodulem_binitfailed"></a><a name="m_binitfailed"></a>CAtlBaseModule::m_bInitFailed

Uma variável que indica se a inicialização do módulo falhou.

```
static bool m_bInitFailed;
```

### <a name="remarks"></a>Comentários

Verdade se o módulo inicializado, falso se ele falhou em inicializar.

## <a name="catlbasemoduleremoveresourceinstance"></a><a name="removeresourceinstance"></a>CAtlBaseModule::RemoveResourceInstance

Remove uma instância de recurso da lista de alças armazenadas.

```
bool RemoveResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*Hinst*<br/>
A instância de recurso para remover.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o recurso foi removido com sucesso, falso de outra forma.

## <a name="catlbasemodulesetresourceinstance"></a><a name="setresourceinstance"></a>CAtlBaseModule::SetResourceInstance

Define a instância `CAtlBaseModule` de recurso de um objeto.

```
HINSTANCE SetResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*Hinst*<br/>
A nova instância de recurso.

### <a name="return-value"></a>Valor retornado

Retorna a instância de recurso atualizada.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)
