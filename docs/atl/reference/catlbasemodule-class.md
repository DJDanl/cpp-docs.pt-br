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
ms.openlocfilehash: d382d1fe7d50a2fdeefc9b477625580792de7d6f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62247146"
---
# <a name="catlbasemodule-class"></a>Classe CAtlBaseModule

Essa classe é instanciada em cada projeto ATL.

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
|[CAtlBaseModule::AddResourceInstance](#addresourceinstance)|Adiciona uma instância do recurso à lista de identificadores de armazenado.|
|[CAtlBaseModule::GetHInstanceAt](#gethinstanceat)|Retorna um identificador para uma instância do recurso especificado.|
|[CAtlBaseModule::GetModuleInstance](#getmoduleinstance)|Retorna a instância de módulo de um `CAtlBaseModule` objeto.|
|[CAtlBaseModule::GetResourceInstance](#getresourceinstance)|Retorna a instância do recurso de um `CAtlBaseModule` objeto.|
|[CAtlBaseModule::RemoveResourceInstance](#removeresourceinstance)|Remove uma instância do recurso na lista de identificadores de armazenado.|
|[CAtlBaseModule::SetResourceInstance](#setresourceinstance)|Define a instância do recurso de um `CAtlBaseModule` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlBaseModule::m_bInitFailed](#m_binitfailed)|Uma variável que indica se a inicialização do módulo tiver falhado.|

## <a name="remarks"></a>Comentários

Uma instância de `CAtlBaseModule` _AtlBaseModule nomeado está presente em cada projeto da ATL, que contém um identificador para a instância de módulo, um identificador para o módulo que contém recursos (que, por padrão, são o mesmo) e uma matriz de identificadores para módulos que fornecem primário recursos. `CAtlBaseModule` podem ser acessados com segurança de vários threads.

Essa classe substitui o obsoletos [CComModule](../../atl/reference/ccommodule-class.md) classe usado em versões anteriores do ATL.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module)

`CAtlBaseModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

##  <a name="addresourceinstance"></a>  CAtlBaseModule::AddResourceInstance

Adiciona uma instância do recurso à lista de identificadores de armazenado.

```
bool AddResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*hInst*<br/>
A instância do recurso para adicionar.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o recurso tiver sido adicionado, false caso contrário.

##  <a name="catlbasemodule"></a>  CAtlBaseModule::CAtlBaseModule

O construtor.

```
CAtlBaseModule() throw();
```

### <a name="remarks"></a>Comentários

Cria o `CAtlBaseModule`.

##  <a name="gethinstanceat"></a>  CAtlBaseModule::GetHInstanceAt

Retorna um identificador para uma instância do recurso especificado.

```
HINSTANCE GetHInstanceAt(int i) throw();
```

### <a name="parameters"></a>Parâmetros

*i*<br/>
O número da instância do recurso.

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para a instância do recurso, ou nulo se não existir nenhuma instância de recurso correspondente.

##  <a name="getmoduleinstance"></a>  CAtlBaseModule::GetModuleInstance

Retorna a instância de módulo de um `CAtlBaseModule` objeto.

```
HINSTANCE GetModuleInstance() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a instância de módulo.

##  <a name="getresourceinstance"></a>  CAtlBaseModule::GetResourceInstance

Retorna a instância do recurso.

```
HINSTANCE GetResourceInstance() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a instância do recurso.

##  <a name="m_binitfailed"></a>  CAtlBaseModule::m_bInitFailed

Uma variável que indica se a inicialização do módulo tiver falhado.

```
static bool m_bInitFailed;
```

### <a name="remarks"></a>Comentários

True se o módulo inicializado, FALSO se ele falha ao inicializar.

##  <a name="removeresourceinstance"></a>  CAtlBaseModule::RemoveResourceInstance

Remove uma instância do recurso na lista de identificadores de armazenado.

```
bool RemoveResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*hInst*<br/>
A instância do recurso a ser removido.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o recurso foi removido com êxito, false caso contrário.

##  <a name="setresourceinstance"></a>  CAtlBaseModule::SetResourceInstance

Define a instância do recurso de um `CAtlBaseModule` objeto.

```
HINSTANCE SetResourceInstance(HINSTANCE hInst) throw();
```

### <a name="parameters"></a>Parâmetros

*hInst*<br/>
A nova instância do recurso.

### <a name="return-value"></a>Valor de retorno

Retorna a instância do recurso atualizado.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
