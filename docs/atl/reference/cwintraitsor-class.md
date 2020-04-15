---
title: Classe Cwintraitsor
ms.date: 11/04/2016
f1_keywords:
- CWinTraitsOR
- ATLWIN/ATL::CWinTraitsOR
- ATLWIN/ATL::CWinTraitsOR::GetWndExStyle
- ATLWIN/ATL::CWinTraitsOR::GetWndStyle
helpviewer_keywords:
- CWinTraitsOR class
- window styles, default values for ATL
ms.assetid: 1eb7b1e8-a9bd-411b-a30a-35a8a10af989
ms.openlocfilehash: 825f79190c6f68cd1372154e4e02f430f545aa48
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330278"
---
# <a name="cwintraitsor-class"></a>Classe Cwintraitsor

Esta classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <DWORD t_dwStyle = 0,
          DWORD t_dwExStyle = 0,
          class TWinTraits = CControlWinTraits>
class CWinTraitsOR
```

#### <a name="parameters"></a>Parâmetros

*t_dwStyle*<br/>
Estilos de janela padrão.

*t_dwExStyle*<br/>
Estilos de janela estendidos padrão.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWinTraitsOR::GetWndExStyle](#getwndexstyle)|Recupera os estilos estendidos para o `CWinTraitsOR` objeto.|
|[CWinTraitsOR::GetWndStyle](#getwndstyle)|Recupera os estilos padrão `CWinTraitsOR` para o objeto.|

## <a name="remarks"></a>Comentários

Esta classe [de traços de janela](../../atl/understanding-window-traits.md) fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Use uma especialização desta classe como parâmetro de modelo para [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outra das classes de janela da ATL para especificar o conjunto mínimo de estilos padrão e estendidos a serem usados para instâncias dessa classe de janela.

Use uma especialização deste modelo se quiser garantir que certos estilos sejam definidos para todas as instâncias da classe de janela, permitindo que outros estilos sejam definidos por instância na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).

Se você quiser fornecer estilos de janela padrão que serão usados apenas `CWindowImpl::Create`quando nenhum outro estilo for especificado na chamada para , use [CWinTraits](../../atl/reference/cwintraits-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cwintraitsorgetwndstyle"></a><a name="getwndstyle"></a>CWinTraitsOR::GetWndStyle

Chame esta função para recuperar uma combinação (usando o operador `CWinTraits` OR lógico) dos estilos padrão do objeto e dos estilos padrão especificados por *t_dwStyle*.

```
static DWORD GetWndStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Estilos usados para a criação de uma janela.

### <a name="return-value"></a>Valor retornado

Uma combinação de estilos que são passados no *dwStyle* e os padrão especificados por `t_dwStyle`, usando o operador OR lógico.

## <a name="cwintraitsorgetwndexstyle"></a><a name="getwndexstyle"></a>CWinTraitsOR::GetWndExStyle

Chame esta função para recuperar uma combinação (usando o operador `CWinTraits` OR lógico) dos `t_dwStyle`estilos estendidos do objeto e dos estilos padrão especificados por .

```
static DWORD GetWndExStyle(DWORD dwExStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Estilos estendidos usados para a criação de uma janela.

### <a name="return-value"></a>Valor retornado

Uma combinação de estilos estendidos que são passados em `t_dwExStyle` *dwExStyle* e os padrão especificados por , usando o operador OR lógico

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Entendendo traços da janela](../../atl/understanding-window-traits.md)
