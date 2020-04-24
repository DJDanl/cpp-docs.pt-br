---
title: CMFCDisableMenuAnimation Class
ms.date: 11/04/2016
f1_keywords:
- CMFCDisableMenuAnimation
- AFXPOPUPMENU/CMFCDisableMenuAnimation
- AFXPOPUPMENU/CMFCDisableMenuAnimation::Restore
helpviewer_keywords:
- CMFCDisableMenuAnimation [MFC], Restore
ms.assetid: c6eb07da-c382-43d6-8028-007f2320e50e
ms.openlocfilehash: c6d81f253016d3a292dd50b16c19f76a05e75e56
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752410"
---
# <a name="cmfcdisablemenuanimation-class"></a>CMFCDisableMenuAnimation Class

Desabilita a animação do menu pop-up.

## <a name="syntax"></a>Sintaxe

```
class CMFCDisableMenuAnimation
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCDisableMenuAnimation::CMFCDisableMenuAnimation`|Constrói um objeto `CMFCDisableMenuAnimation`.|
|`CMFCDisableMenuAnimation::~CMFCDisableMenuAnimation`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCDisableMenuAnimation::Restauração](#restore)|Restaura a animação anterior que a estrutura usou para exibir um menu pop-up.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|`CMFCDisableMenuAnimation::m_animType`|Armazena o tipo de animação do menu pop-up anterior.|

### <a name="remarks"></a>Comentários

Use esta classe de ajudantes para desativar temporariamente a animação do menu pop-up (por exemplo, quando você processa comandos de mouse ou teclado).

Um `CMFCDisableMenuAnimation` objeto desativa a animação do menu pop-up durante sua vida útil. O construtor armazena o tipo de animação `m_animType` atual do menu pop-up no campo e define o tipo de animação atual para `CMFCPopupMenu::NO_ANIMATION`. O destruidor restaura o tipo de animação anterior.

Você pode `CMFCDisableMenuAnimation` criar um objeto na pilha para desativar a animação do menu pop-up em uma única função. Se você quiser desativar a animação do menu `CMFCDisableMenuAnimation` pop-up entre as funções, crie um objeto no heap e, em seguida, exclua-o quando quiser restaurar a animação do menu pop-up.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar a pilha para desativar temporariamente a animação do menu.

[!code-cpp[NVC_MFC_Misc#1](../../mfc/reference/codesnippet/cpp/cmfcdisablemenuanimation-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMFCDisableMenuAnimation](../../mfc/reference/cmfcdisablemenuanimation-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpopupmenu.h

## <a name="cmfcdisablemenuanimationrestore"></a><a name="restore"></a>CMFCDisableMenuAnimation::Restauração

Restaura a animação anterior que a estrutura usou para exibir um menu pop-up.

```cpp
void Restore ();
```

### <a name="remarks"></a>Comentários

Este método é `CMFCDisableMenuAnimation` chamado pelo destruidor para restaurar a animação anterior que a estrutura usada para exibir um menu pop-up.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)
