---
title: Classe CAtlWinModule
ms.date: 11/04/2016
f1_keywords:
- CAtlWinModule
- ATLBASE/ATL::CAtlWinModule
- ATLBASE/ATL::CAtlWinModule::CAtlWinModule
- ATLBASE/ATL::CAtlWinModule::AddCreateWndData
- ATLBASE/ATL::CAtlWinModule::ExtractCreateWndData
helpviewer_keywords:
- CAtlWinModule class
ms.assetid: 7ec844af-0f68-4a34-b0c8-9de50a025df0
ms.openlocfilehash: d0bc98fa48f84e67ab38106dea3fe22d5ad1757d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78857345"
---
# <a name="catlwinmodule-class"></a>Classe CAtlWinModule

Essa classe fornece suporte para componentes da janela ATL.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CAtlWinModule : public _ATL_WIN_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAtlWinModule::CAtlWinModule](#catlwinmodule)|O construtor.|
|[CAtlWinModule:: ~ CAtlWinModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAtlWinModule::AddCreateWndData](#addcreatewnddata)|Adiciona um objeto de dados.|
|[CAtlWinModule::ExtractCreateWndData](#extractcreatewnddata)|Retorna um ponteiro para o objeto de dados do módulo de janela.|

## <a name="remarks"></a>Comentários

Essa classe fornece suporte para todas as classes ATL que exigem recursos de janelas.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)

`CAtlWinModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="addcreatewnddata"></a>CAtlWinModule::AddCreateWndData

Esse método inicializa e adiciona uma estrutura de `_AtlCreateWndData`.

```
void AddCreateWndData(_AtlCreateWndData* pData, void* pObject);
```

### <a name="parameters"></a>Parâmetros

*pData*<br/>
Ponteiro para a estrutura de `_AtlCreateWndData` a ser inicializada e adicionada ao módulo atual.

*pObject*<br/>
Ponteiro para **o** ponteiro de um objeto.

### <a name="remarks"></a>Comentários

Esse método chama [AtlWinModuleAddCreateWndData](winmodule-global-functions.md#atlwinmoduleaddcreatewnddata) que Inicializa uma estrutura de [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) . Essa estrutura armazenará **esse** ponteiro, usado para obter a instância de classe em procedimentos de janela.

##  <a name="catlwinmodule"></a>CAtlWinModule::CAtlWinModule

O construtor.

```
CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Se a inicialização falhar, uma exceção de **EXCEPTION_NONCONTINUABLE** será gerada.

##  <a name="dtor"></a>CAtlWinModule:: ~ CAtlWinModule

O destruidor.

```
~CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="extractcreatewnddata"></a>CAtlWinModule::ExtractCreateWndData

Esse método retorna um ponteiro para uma estrutura de `_AtlCreateWndData`.

```
void* ExtractCreateWndData();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a estrutura de `_AtlCreateWndData` adicionada anteriormente com [CAtlWinModule:: AddCreateWndData](#addcreatewnddata)ou NULL se nenhum objeto estiver disponível.

## <a name="see-also"></a>Veja também

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
