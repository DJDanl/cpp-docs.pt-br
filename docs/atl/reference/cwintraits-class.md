---
title: Classe Cwintraits
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
ms.openlocfilehash: fd73f733e4eff21da92937d1e1b0cce21552a48c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330306"
---
# <a name="cwintraits-class"></a>Classe Cwintraits

Esta classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <DWORD t_dwStyle = 0, DWORD t_dwExStyle = 0>  class CWinTraits
```

#### <a name="parameters"></a>Parâmetros

*t_dwStyle*<br/>
Estilos de janela padrão padrão.

*t_dwExStyle*<br/>
Estilos de janela estendidos padrão.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinTraits::GetWndExStyle](#getwndexstyle)|(Estática) Recupera os estilos estendidos para o `CWinTraits` objeto.|
|[CWinTraits::GetWndStyle](#getwndstyle)|(Estática) Recupera os estilos padrão `CWinTraits` para o objeto.|

## <a name="remarks"></a>Comentários

Esta classe [de traços de janela](../../atl/understanding-window-traits.md) fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Use uma especialização desta classe como parâmetro de modelo para [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outra das classes de janela da ATL para especificar o padrão padrão e os estilos estendidos usados para instâncias dessa classe de janela.

Use este modelo quando quiser fornecer estilos de janela padrão que serão usados somente quando nenhum outro estilo for especificado na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).

A ATL fornece três especializações predefinidas deste modelo para combinações comumente usadas de estilos de janela:

- `CControlWinTraits`

   Projetado para uma janela de controle padrão. Os seguintes estilos padrão são usados: WS_CHILD, WS_VISIBLE, WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Não há estilos estendidos.

- `CFrameWinTraits`

   Projetado para uma janela de quadro padrão. Os estilos padrão utilizados incluem: WS_OVERLAPPEDWINDOW, WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Os estilos estendidos utilizados incluem: WS_EX_APPWINDOW e WS_EX_WINDOWEDGE.

- `CMDIChildWinTraits`

   Projetado para uma janela de criança MDI padrão. Os estilos padrão utilizados incluem: WS_OVERLAPPEDWINDOW, WS_CHILD, WS_VISIBLE, WS_CLIPCHILDREN e WS_CLIPSIBLINGS. Os estilos estendidos utilizados incluem: WS_EX_MDICHILD.

Se você quiser garantir que certos estilos sejam definidos para todas as instâncias da classe de janela, permitindo que outros estilos sejam definidos por instância, use [CWinTraitsOR](../../atl/reference/cwintraitsor-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cwintraitsgetwndstyle"></a><a name="getwndstyle"></a>CWinTraits::GetWndStyle

Chame esta função para recuperar `CWinTraits` os estilos padrão do objeto.

```
static DWORD GetWndStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Estilos padrão usados para a criação de uma janela. Se *dwStyle* for 0, os`t_dwStyle`valores de estilo do modelo () serão devolvidos. Se *dwStyle* não for zero, *dwStyle* será devolvido.

### <a name="return-value"></a>Valor retornado

Os estilos de janela padrão do objeto.

## <a name="cwintraitsgetwndexstyle"></a><a name="getwndexstyle"></a>CWinTraits::GetWndExStyle

Chame esta função para recuperar `CWinTraits` os estilos estendidos do objeto.

```
static DWORD GetWndExStyle(DWORD dwExStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Estilos estendidos usados para a criação de uma janela. Se *dwExStyle* for 0, os`t_dwExStyle`valores de estilo do modelo () serão devolvidos. Se *dwExStyle* não for zero, *dwExStyle* será devolvido.

### <a name="return-value"></a>Valor retornado

Os estilos de janela estendidos do objeto.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Entendendo traços da janela](../../atl/understanding-window-traits.md)
