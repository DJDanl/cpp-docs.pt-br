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
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269455"
---
# <a name="catlwinmodule-class"></a>Classe CAtlWinModule

Essa classe fornece suporte para componentes de janelas do ATL.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlWinModule : public _ATL_WIN_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlWinModule::CAtlWinModule](#catlwinmodule)|O construtor.|
|[CAtlWinModule::~CAtlWinModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
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

##  <a name="addcreatewnddata"></a>  CAtlWinModule::AddCreateWndData

Esse método inicializa e adiciona um `_AtlCreateWndData` estrutura.

```
void AddCreateWndData(_AtlCreateWndData* pData, void* pObject);
```

### <a name="parameters"></a>Parâmetros

*pData*<br/>
Ponteiro para o `_AtlCreateWndData` estrutura a ser inicializado e adicionados ao módulo atual.

*pObject*<br/>
Ponteiro para um objeto **isso** ponteiro.

### <a name="remarks"></a>Comentários

Este método chama [AtlWinModuleAddCreateWndData](winmodule-global-functions.md#atlwinmoduleaddcreatewnddata) quais inicializa um [atlcreatewnddata](../../atl/reference/atlcreatewnddata-structure.md) estrutura. Essa estrutura armazenará a **isso** ponteiro, usado para obter a instância da classe nos procedimentos de janela.

##  <a name="catlwinmodule"></a>  CAtlWinModule::CAtlWinModule

O construtor.

```
CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Se a inicialização falhar, uma **EXCEPTION_NONCONTINUABLE** exceção será gerada.

##  <a name="dtor"></a>  CAtlWinModule::~CAtlWinModule

O destruidor.

```
~CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="extractcreatewnddata"></a>  CAtlWinModule::ExtractCreateWndData

Esse método retorna um ponteiro para um `_AtlCreateWndData` estrutura.

```
void* ExtractCreateWndData();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o `_AtlCreateWndData` estrutura adicionada anteriormente com [CAtlWinModule::AddCreateWndData](#addcreatewnddata), ou nulo se nenhum objeto está disponível.

## <a name="see-also"></a>Consulte também

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
