---
title: Funções globais WinModule
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlWinModuleAddCreateWndData
- atlbase/ATL::AtlWinModuleExtractCreateWndData
ms.assetid: 8ce45a5b-26a7-491f-9096-c09ceca5f2c2
ms.openlocfilehash: 0e7450ea2a42c0b35dc5a6d1b77dfb0f2acb9520
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57265074"
---
# <a name="winmodule-global-functions"></a>Funções globais WinModule

Essas funções fornecem suporte para `_AtlCreateWndData` estruturar as operações.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no tempo de execução do Windows.

|||
|-|-|
|[AtlWinModuleAddCreateWndData](#atlwinmoduleaddcreatewnddata)|Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.|
|[AtlWinModuleExtractCreateWndData](#atlwinmoduleextractcreatewnddata)|Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atlwinmoduleaddcreatewnddata"></a>  AtlWinModuleAddCreateWndData

Essa função é usada para inicializar e adicionar uma estrutura `_AtlCreateWndData`.

```
ATLINLINE ATLAPI_(void) AtlWinModuleAddCreateWndData(
    _ATL_WIN_MODULE* pWinModule,
    _AtlCreateWndData* pData,
    void* pObject);
```

### <a name="parameters"></a>Parâmetros

*pWinModule*<br/>
Ponteiro para um módulo [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) estrutura.

*pData*<br/>
Ponteiro para o [atlcreatewnddata](../../atl/reference/atlcreatewnddata-structure.md) estrutura a ser inicializado e adicionados ao módulo atual.

*pObject*<br/>
Ponteiro para um objeto **isso** ponteiro.

### <a name="remarks"></a>Comentários

Inicializa um `_AtlCreateWndData` estrutura, que é usada para armazenar os **isso** ponteiro usado para se referir a instâncias de classe e o adiciona à lista referenciada por um módulo `_ATL_WIN_MODULE70` estrutura. Chamado pelo [CAtlWinModule::AddCreateWndData](catlwinmodule-class.md#addcreatewnddata).

##  <a name="atlwinmoduleextractcreatewnddata"></a>  AtlWinModuleExtractCreateWndData

Chame essa função para extrair uma estrutura `_AtlCreateWndData` existente.

```
ATLINLINE ATLAPI_(void*) AtlWinModuleExtractCreateWndData(_ATL_WIN_MODULE* pWinModule);
```

### <a name="parameters"></a>Parâmetros

*pWinModule*<br/>
Ponteiro para um módulo [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md) estrutura.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o [atlcreatewnddata](../../atl/reference/atlcreatewnddata-structure.md) estrutura.

### <a name="remarks"></a>Comentários

Essa função extrairá um existente `_AtlCreateWndData` estrutura na lista referenciada por um módulo `_ATL_WIN_MODULE70` estrutura.

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
