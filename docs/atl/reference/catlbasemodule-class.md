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
ms.openlocfilehash: d57d6e631cb287496a4ff5516e97e65ec0152e30
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168287"
---
# <a name="catlbasemodule-class"></a>Classe CAtlBaseModule

Essa classe é instanciada em todos os projetos ATL.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CAtlBaseModule::AddResourceInstance](#addresourceinstance)|Adiciona uma instância de recurso à lista de identificadores armazenados.|
|[CAtlBaseModule::GetHInstanceAt](#gethinstanceat)|Retorna um identificador para uma instância de recurso especificada.|
|[CAtlBaseModule::GetModuleInstance](#getmoduleinstance)|Retorna a instância de módulo de `CAtlBaseModule` um objeto.|
|[CAtlBaseModule::GetResourceInstance](#getresourceinstance)|Retorna a instância de recurso de `CAtlBaseModule` um objeto.|
|[CAtlBaseModule::RemoveResourceInstance](#removeresourceinstance)|Remove uma instância de recurso da lista de identificadores armazenados.|
|[CAtlBaseModule::SetResourceInstance](#setresourceinstance)|Define a instância de recurso de `CAtlBaseModule` um objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlBaseModule:: m_bInitFailed](#m_binitfailed)|Uma variável que indica se a inicialização do módulo falhou.|

## <a name="remarks"></a>Comentários

Uma instância de `CAtlBaseModule` _AtlBaseModule nomeada está presente em todos os projetos do ATL, contendo um identificador para a instância do módulo, um identificador para o módulo que contém recursos (que por padrão são um e o mesmo) e uma matriz de identificadores para módulos que fornecem recursos primários. `CAtlBaseModule`pode ser acessado com segurança de vários threads.

Essa classe substitui a classe [CComModule](../../atl/reference/ccommodule-class.md) obsoleta usada em versões anteriores do ATL.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module)

`CAtlBaseModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

## <a name="catlbasemoduleaddresourceinstance"></a><a name="addresourceinstance"></a>CAtlBaseModule::AddResourceInstance

Adiciona uma instância de recurso à lista de identificadores armazenados.

```cpp
bool AddResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*hInst*<br/>
A instância de recurso a ser adicionada.

### <a name="return-value"></a>Valor retornado

Retorna true se o recurso foi adicionado com êxito; caso contrário, false.

## <a name="catlbasemodulecatlbasemodule"></a><a name="catlbasemodule"></a>CAtlBaseModule::CAtlBaseModule

O construtor.

```cpp
CAtlBaseModule() throw();
```

### <a name="remarks"></a>Comentários

Cria o `CAtlBaseModule`.

## <a name="catlbasemodulegethinstanceat"></a><a name="gethinstanceat"></a>CAtlBaseModule::GetHInstanceAt

Retorna um identificador para uma instância de recurso especificada.

```cpp
HINSTANCE GetHInstanceAt(int i) throw();
```

### <a name="parameters"></a>Parâmetros

*Encontrei*<br/>
O número da instância do recurso.

### <a name="return-value"></a>Valor retornado

Retorna o identificador para a instância de recurso ou NULL se não existir nenhuma instância de recurso correspondente.

## <a name="catlbasemodulegetmoduleinstance"></a><a name="getmoduleinstance"></a>CAtlBaseModule::GetModuleInstance

Retorna a instância de módulo de `CAtlBaseModule` um objeto.

```cpp
HINSTANCE GetModuleInstance() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a instância do módulo.

## <a name="catlbasemodulegetresourceinstance"></a><a name="getresourceinstance"></a>CAtlBaseModule::GetResourceInstance

Retorna a instância de recurso.

```cpp
HINSTANCE GetResourceInstance() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a instância de recurso.

## <a name="catlbasemodulem_binitfailed"></a><a name="m_binitfailed"></a>CAtlBaseModule:: m_bInitFailed

Uma variável que indica se a inicialização do módulo falhou.

```cpp
static bool m_bInitFailed;
```

### <a name="remarks"></a>Comentários

True se o módulo for inicializado, false se ele não for inicializado.

## <a name="catlbasemoduleremoveresourceinstance"></a><a name="removeresourceinstance"></a>CAtlBaseModule::RemoveResourceInstance

Remove uma instância de recurso da lista de identificadores armazenados.

```cpp
bool RemoveResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*hInst*<br/>
A instância de recurso a ser removida.

### <a name="return-value"></a>Valor retornado

Retornará true se o recurso tiver sido removido com êxito; caso contrário, false.

## <a name="catlbasemodulesetresourceinstance"></a><a name="setresourceinstance"></a>CAtlBaseModule::SetResourceInstance

Define a instância de recurso de `CAtlBaseModule` um objeto.

```cpp
HINSTANCE SetResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*hInst*<br/>
A nova instância de recurso.

### <a name="return-value"></a>Valor retornado

Retorna a instância de recurso atualizada.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
