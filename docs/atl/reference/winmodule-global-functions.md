---
title: Funções globais do WinModule
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlWinModuleAddCreateWndData
- atlbase/ATL::AtlWinModuleExtractCreateWndData
ms.assetid: 8ce45a5b-26a7-491f-9096-c09ceca5f2c2
ms.openlocfilehash: 3d7d001a2835514cc5385a7069c0bcda58cdd88e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329356"
---
# <a name="winmodule-global-functions"></a>Funções globais do WinModule

Essas funções fornecem `_AtlCreateWndData` suporte para operações de estrutura.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AtlWinModuleAddCreateWndData](#atlwinmoduleaddcreatewnddata)|Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.|
|[AtlWinModuleExtractCreateWndData](#atlwinmoduleextractcreatewnddata)|Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlwinmoduleaddcreatewnddata"></a><a name="atlwinmoduleaddcreatewnddata"></a>AtlWinModuleAddCreatewndData

Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.

```
ATLINLINE ATLAPI_(void) AtlWinModuleAddCreateWndData(
    _ATL_WIN_MODULE* pWinModule,
    _AtlCreateWndData* pData,
    void* pObject);
```

### <a name="parameters"></a>Parâmetros

*pWinModule*<br/>
Ponteiro para a estrutura [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) de um módulo.

*Pdata*<br/>
Ponteiro para a estrutura [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) a ser inicializada e adicionada ao módulo atual.

*Pobject*<br/>
Ponteiro para um objeto é **este** ponteiro.

### <a name="remarks"></a>Comentários

Inicializa uma `_AtlCreateWndData` estrutura, que é usada para armazenar o **ponteiro usado** para se referir a instâncias `_ATL_WIN_MODULE70` de classe, e adiciona-a à lista referenciada pela estrutura de um módulo. Chamado por [CAtlWinModule::AddCreateWndData](catlwinmodule-class.md#addcreatewnddata).

## <a name="atlwinmoduleextractcreatewnddata"></a><a name="atlwinmoduleextractcreatewnddata"></a>AtlWinModuleExtractCreateWndData

Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.

```
ATLINLINE ATLAPI_(void*) AtlWinModuleExtractCreateWndData(_ATL_WIN_MODULE* pWinModule);
```

### <a name="parameters"></a>Parâmetros

*pWinModule*<br/>
Ponteiro para a estrutura [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) de um módulo.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a estrutura [_AtlCreateWndData.](../../atl/reference/atlcreatewnddata-structure.md)

### <a name="remarks"></a>Comentários

Esta função extrairá `_AtlCreateWndData` uma estrutura existente da lista referenciada pela estrutura de `_ATL_WIN_MODULE70` um módulo.

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
