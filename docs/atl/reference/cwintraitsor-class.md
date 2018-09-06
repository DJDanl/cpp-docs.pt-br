---
title: Classe CWinTraitsOR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CWinTraitsOR
- ATLWIN/ATL::CWinTraitsOR
- ATLWIN/ATL::CWinTraitsOR::GetWndExStyle
- ATLWIN/ATL::CWinTraitsOR::GetWndStyle
dev_langs:
- C++
helpviewer_keywords:
- CWinTraitsOR class
- window styles, default values for ATL
ms.assetid: 1eb7b1e8-a9bd-411b-a30a-35a8a10af989
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5e837e15f934e53f7b1d06a94efb4a320f2e8407
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43757888"
---
# <a name="cwintraitsor-class"></a>Classe CWinTraitsOR

Essa classe fornece um método para padronizar os estilos usados durante a criação de um objeto de janela.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <DWORD t_dwStyle = 0,
          DWORD t_dwExStyle = 0, 
          class TWinTraits = CControlWinTraits>
class CWinTraitsOR
```

#### <a name="parameters"></a>Parâmetros

*t_dwStyle*  
Estilos de janela padrão.

*t_dwExStyle*  
Estilos de janela estendidos por padrão.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinTraitsOR::GetWndExStyle](#getwndexstyle)|Recupera os estilos estendidos para o `CWinTraitsOR` objeto.|
|[CWinTraitsOR::GetWndStyle](#getwndstyle)|Recupera os estilos padrão para o `CWinTraitsOR` objeto.|

## <a name="remarks"></a>Comentários

Isso [características da janela](../../atl/understanding-window-traits.md) classe fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Usar uma especialização dessa classe como um parâmetro de modelo [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outra das classes de janela da ATL para especificar o conjunto mínimo de estilos padrão e estendidos a ser usado para instâncias dessa classe de janela.

Use uma especialização do modelo, se você quiser garantir que determinados estilos são definidos para todas as instâncias da classe de janela ao permitir que outros estilos a ser definido em uma base por instância na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).

Se você quiser fornecer padrão estilos de janela que serão usados somente quando não há outros estilos são especificados na chamada para `CWindowImpl::Create`, use [CWinTraits](../../atl/reference/cwintraits-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="getwndstyle"></a>  CWinTraitsOR::GetWndStyle

Chame essa função para recuperar uma combinação (usando o operador OR lógico) dos estilos de padrão a `CWinTraits` objeto e os estilos padrão especificados por *t_dwStyle*.

```
static DWORD GetWndStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*  
Estilos usados para criação de uma janela.

### <a name="return-value"></a>Valor de retorno

Uma combinação de estilos que são passados *dwStyle* e o padrão que aqueles especificados pelo `t_dwStyle`, usando o operador OR lógico.

##  <a name="getwndexstyle"></a>  CWinTraitsOR::GetWndExStyle

Chame essa função para recuperar uma combinação (usando o operador OR lógico) estilos estendidos do `CWinTraits` objeto e os estilos padrão especificados pelo `t_dwStyle`.

```
static DWORD GetWndExStyle(DWORD dwExStyle);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*  
Estilos estendidos usados para a criação de uma janela.

### <a name="return-value"></a>Valor de retorno

Uma combinação de estilos estendidos que são passados *dwExStyle* e o padrão especificado pelo `t_dwExStyle`, usando o operador OR lógico

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)   
[Noções básicas sobre as características da janela](../../atl/understanding-window-traits.md)

