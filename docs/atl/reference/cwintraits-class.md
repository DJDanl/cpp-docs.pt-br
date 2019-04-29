---
title: Classe CWinTraits
ms.date: 11/04/2016
f1_keywords:
- CWinTraits
- ATLWIN/ATL::CWinTraits
- ATLWIN/ATL::CWinTraits::GetWndExStyle
- ATLWIN/ATL::CWinTraits::GetWndStyle
helpviewer_keywords:
- CMDIChildWinTraits class
- window styles, default values for ATL
- CWinTraits class
- CFrameWinTraits class
- CControlWinTraits class
ms.assetid: f78f486e-6d9c-42c6-8e86-371e05aa7e59
ms.openlocfilehash: 840433ffb325a4f181848371306607b62373e75a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62276770"
---
# <a name="cwintraits-class"></a>Classe CWinTraits

Essa classe fornece um método para padronizar os estilos usados durante a criação de um objeto de janela.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <DWORD t_dwStyle = 0, DWORD t_dwExStyle = 0>  class CWinTraits
```

#### <a name="parameters"></a>Parâmetros

*t_dwStyle*<br/>
Estilos de janela padrão do padrão.

*t_dwExStyle*<br/>
Estilos de janela estendidos por padrão.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinTraits::GetWndExStyle](#getwndexstyle)|(Estático) Recupera os estilos estendidos para o `CWinTraits` objeto.|
|[CWinTraits::GetWndStyle](#getwndstyle)|(Estático) Recupera os estilos padrão para o `CWinTraits` objeto.|

## <a name="remarks"></a>Comentários

Isso [características da janela](../../atl/understanding-window-traits.md) classe fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Usar uma especialização dessa classe como um parâmetro de modelo [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outra das classes de janela da ATL para especificar os estilos de padrão e estendidas padrão usados para instâncias dessa classe de janela.

Use este modelo quando desejar fornecer padrão estilos de janela que serão usados somente quando não há outros estilos são especificados na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).

ATL fornece três especializações predefinidas desse modelo para comumente usadas combinações de estilos de janela:

- `CControlWinTraits`

   Projetado para uma janela de controle padrão. Os seguintes estilos padrão são usados: WS_CHILD, WS_VISIBLE, WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Não há nenhum estilos estendidos.

- `CFrameWinTraits`

   Projetado para uma janela de quadro padrão. Os estilos padrão usados incluem: WS_OVERLAPPEDWINDOW, WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Os estilos estendidos usados incluem: WS_EX_APPWINDOW e WS_EX_WINDOWEDGE.

- `CMDIChildWinTraits`

   Projetado para uma janela filho da MDI padrão. Os estilos padrão usados incluem: WS_OVERLAPPEDWINDOW, WS_CHILD, WS_VISIBLE, WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Os estilos estendidos usados incluem: WS_EX_MDICHILD.

Se você quiser garantir que determinados estilos são definidos para todas as instâncias da classe de janela ao mesmo tempo, permitindo que outros estilos a ser definido em uma base por instância, use [CWinTraitsOR](../../atl/reference/cwintraitsor-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="getwndstyle"></a>  CWinTraits::GetWndStyle

Chame essa função para recuperar os estilos padrão do `CWinTraits` objeto.

```
static DWORD GetWndStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Estilos padrão usados para a criação de uma janela. Se *dwStyle* for 0, os valores de estilo de modelo (`t_dwStyle`) são retornados. Se *dwStyle* for diferente de zero *dwStyle* é retornado.

### <a name="return-value"></a>Valor de retorno

Os estilos de janela padrão do objeto.

##  <a name="getwndexstyle"></a>  CWinTraits::GetWndExStyle

Chame essa função para recuperar os estilos estendidos do `CWinTraits` objeto.

```
static DWORD GetWndExStyle(DWORD dwExStyle);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Estilos estendidos usados para a criação de uma janela. Se *dwExStyle* for 0, os valores de estilo de modelo (`t_dwExStyle`) são retornados. Se *dwExStyle* for diferente de zero *dwExStyle* é retornado.

### <a name="return-value"></a>Valor de retorno

Os estilos de janela estendidos do objeto.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Noções básicas sobre as características da janela](../../atl/understanding-window-traits.md)
