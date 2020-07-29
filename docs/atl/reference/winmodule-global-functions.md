---
title: Funções globais WinModule
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlWinModuleAddCreateWndData
- atlbase/ATL::AtlWinModuleExtractCreateWndData
ms.assetid: 8ce45a5b-26a7-491f-9096-c09ceca5f2c2
ms.openlocfilehash: 1a929fd0f583150e84ce5b1efa7e896bc16e4247
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229929"
---
# <a name="winmodule-global-functions"></a>Funções globais WinModule

Essas funções fornecem suporte para `_AtlCreateWndData` operações de estrutura.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|||
|-|-|
|[AtlWinModuleAddCreateWndData](#atlwinmoduleaddcreatewnddata)|Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.|
|[AtlWinModuleExtractCreateWndData](#atlwinmoduleextractcreatewnddata)|Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="atlwinmoduleaddcreatewnddata"></a><a name="atlwinmoduleaddcreatewnddata"></a>AtlWinModuleAddCreateWndData

Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.

```
ATLINLINE ATLAPI_(void) AtlWinModuleAddCreateWndData(
    _ATL_WIN_MODULE* pWinModule,
    _AtlCreateWndData* pData,
    void* pObject);
```

### <a name="parameters"></a>parâmetros

*pWinModule*<br/>
Ponteiro para a estrutura de [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) de um módulo.

*pData*<br/>
Ponteiro para a estrutura de [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) a ser inicializada e adicionada ao módulo atual.

*pObject*<br/>
Ponteiro para o ponteiro de um objeto **`this`** .

### <a name="remarks"></a>Comentários

Inicializa uma `_AtlCreateWndData` estrutura, que é usada para armazenar o **`this`** ponteiro usado para se referir a instâncias de classe e a adiciona à lista referenciada pela estrutura de um módulo `_ATL_WIN_MODULE70` . Chamado por [CAtlWinModule:: AddCreateWndData](catlwinmodule-class.md#addcreatewnddata).

## <a name="atlwinmoduleextractcreatewnddata"></a><a name="atlwinmoduleextractcreatewnddata"></a>AtlWinModuleExtractCreateWndData

Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.

```
ATLINLINE ATLAPI_(void*) AtlWinModuleExtractCreateWndData(_ATL_WIN_MODULE* pWinModule);
```

### <a name="parameters"></a>parâmetros

*pWinModule*<br/>
Ponteiro para a estrutura de [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) de um módulo.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a estrutura de [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) .

### <a name="remarks"></a>Comentários

Essa função irá extrair uma `_AtlCreateWndData` estrutura existente da lista referenciada pela estrutura de um módulo `_ATL_WIN_MODULE70` .

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
