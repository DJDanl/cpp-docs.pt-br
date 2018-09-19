---
title: Funções globais WinModule | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlWinModuleAddCreateWndData
- atlbase/ATL::AtlWinModuleExtractCreateWndData
dev_langs:
- C++
ms.assetid: 8ce45a5b-26a7-491f-9096-c09ceca5f2c2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 70b99ac7790477df88a0e685afd5652a35c06233
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047519"
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
