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
ms.openlocfilehash: e131ca1b4eb6e320d533ad1292c23add6ffa46e5
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748561"
---
# <a name="catlwinmodule-class"></a>Classe CAtlWinModule

Esta classe fornece suporte para componentes de janelas ATL.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlWinModule : public _ATL_WIN_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlWinModule::CAtlWinModule](#catlwinmodule)|O construtor.|
|[CAtlWinModule::~CAtlWinModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlWinModule::AddCreateWndData](#addcreatewnddata)|Adiciona um objeto de dados.|
|[CAtlWinModule::ExtractCreateWndData](#extractcreatewnddata)|Retorna um ponteiro para o objeto de dados do módulo da janela.|

## <a name="remarks"></a>Comentários

Esta classe fornece suporte para todas as classes ATL que requerem recursos de janelas.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)

`CAtlWinModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlwinmoduleaddcreatewnddata"></a><a name="addcreatewnddata"></a>CAtlWinModule::AddCreateWndData

Este método inicia e `_AtlCreateWndData` adiciona uma estrutura.

```cpp
void AddCreateWndData(_AtlCreateWndData* pData, void* pObject);
```

### <a name="parameters"></a>Parâmetros

*Pdata*<br/>
Ponteiro para `_AtlCreateWndData` a estrutura a ser inicializada e adicionada ao módulo atual.

*Pobject*<br/>
Ponteiro para um objeto é **este** ponteiro.

### <a name="remarks"></a>Comentários

Este método chama [AtlWinModuleAddCreateWnDData](winmodule-global-functions.md#atlwinmoduleaddcreatewnddata) que inicia uma estrutura [de _AtlCreateWndData.](../../atl/reference/atlcreatewnddata-structure.md) Esta estrutura armazenará **este** ponteiro, usado para obter a instância de classe em procedimentos de janela.

## <a name="catlwinmodulecatlwinmodule"></a><a name="catlwinmodule"></a>CAtlWinModule::CAtlWinModule

O construtor.

```
CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Se a inicialização falhar, uma exceção **EXCEPTION_NONCONTINUABLE** será levantada.

## <a name="catlwinmodulecatlwinmodule"></a><a name="dtor"></a>CAtlWinModule::~CAtlWinModule

O destruidor.

```
~CAtlWinModule();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="catlwinmoduleextractcreatewnddata"></a><a name="extractcreatewnddata"></a>CAtlWinModule::ExtractCreateWndData

Este método retorna um `_AtlCreateWndData` ponteiro para uma estrutura.

```cpp
void* ExtractCreateWndData();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `_AtlCreateWndData` à estrutura anteriormente adicionado com [CAtlWinModule::AddCreateWndData](#addcreatewnddata)ou NULL se nenhum objeto estiver disponível.

## <a name="see-also"></a>Confira também

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)
