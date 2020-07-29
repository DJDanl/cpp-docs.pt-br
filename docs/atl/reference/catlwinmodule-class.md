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
ms.openlocfilehash: 04dc7e5b8c0c5dd21567f23395b4bafd4ae839dc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229981"
---
# <a name="catlwinmodule-class"></a>Classe CAtlWinModule

Essa classe fornece suporte para componentes da janela ATL.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
class CAtlWinModule : public _ATL_WIN_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlWinModule::CAtlWinModule](#catlwinmodule)|O construtor.|
|[CAtlWinModule:: ~ CAtlWinModule](#dtor)|O destruidor.|

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

## <a name="catlwinmoduleaddcreatewnddata"></a><a name="addcreatewnddata"></a>CAtlWinModule::AddCreateWndData

Esse método inicializa e adiciona uma `_AtlCreateWndData` estrutura.

```cpp
void AddCreateWndData(_AtlCreateWndData* pData, void* pObject);
```

### <a name="parameters"></a>parâmetros

*pData*<br/>
Ponteiro para a `_AtlCreateWndData` estrutura a ser inicializada e adicionada ao módulo atual.

*pObject*<br/>
Ponteiro para o ponteiro de um objeto **`this`** .

### <a name="remarks"></a>Comentários

Esse método chama [AtlWinModuleAddCreateWndData](winmodule-global-functions.md#atlwinmoduleaddcreatewnddata) que Inicializa uma estrutura de [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) . Essa estrutura armazenará o **`this`** ponteiro, usado para obter a instância de classe em procedimentos de janela.

## <a name="catlwinmodulecatlwinmodule"></a><a name="catlwinmodule"></a>CAtlWinModule::CAtlWinModule

O construtor.

```cpp
CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Se a inicialização falhar, uma exceção de **EXCEPTION_NONCONTINUABLE** será gerada.

## <a name="catlwinmodulecatlwinmodule"></a><a name="dtor"></a>CAtlWinModule:: ~ CAtlWinModule

O destruidor.

```cpp
~CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="catlwinmoduleextractcreatewnddata"></a><a name="extractcreatewnddata"></a>CAtlWinModule::ExtractCreateWndData

Esse método retorna um ponteiro para uma `_AtlCreateWndData` estrutura.

```cpp
void* ExtractCreateWndData();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a `_AtlCreateWndData` estrutura adicionada anteriormente com [CAtlWinModule:: ADDCREATEWNDDATA](#addcreatewnddata)ou NULL se nenhum objeto estiver disponível.

## <a name="see-also"></a>Confira também

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
