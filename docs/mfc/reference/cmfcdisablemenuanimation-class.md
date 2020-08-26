---
title: Classe CMFCDisableMenuAnimation
ms.date: 11/04/2016
f1_keywords:
- CMFCDisableMenuAnimation
- AFXPOPUPMENU/CMFCDisableMenuAnimation
- AFXPOPUPMENU/CMFCDisableMenuAnimation::Restore
helpviewer_keywords:
- CMFCDisableMenuAnimation [MFC], Restore
ms.assetid: c6eb07da-c382-43d6-8028-007f2320e50e
ms.openlocfilehash: 97a93e000b3e12d8ec4824100059581216b1b8d9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840759"
---
# <a name="cmfcdisablemenuanimation-class"></a>Classe CMFCDisableMenuAnimation

Desabilita a animação do menu pop-up.

## <a name="syntax"></a>Sintaxe

```
class CMFCDisableMenuAnimation
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|`CMFCDisableMenuAnimation::CMFCDisableMenuAnimation`|Constrói um objeto `CMFCDisableMenuAnimation`.|
|`CMFCDisableMenuAnimation::~CMFCDisableMenuAnimation`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCDisableMenuAnimation:: Restore](#restore)|Restaura a animação anterior usada pela estrutura para exibir um menu pop-up.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|-|-|
|`CMFCDisableMenuAnimation::m_animType`|Armazena o tipo de animação de menu pop-up anterior.|

### <a name="remarks"></a>Comentários

Use essa classe auxiliar para desabilitar temporariamente a animação do menu pop-up (por exemplo, quando você processa comandos do mouse ou do teclado).

Um `CMFCDisableMenuAnimation` objeto desabilita a animação de menu pop-up durante seu tempo de vida. O Construtor armazena o tipo de animação de menu pop-up atual no `m_animType` campo e define o tipo de animação atual como `CMFCPopupMenu::NO_ANIMATION` . O destruidor restaura o tipo de animação anterior.

Você pode criar um `CMFCDisableMenuAnimation` objeto na pilha para desabilitar a animação do menu pop-up em uma única função. Se você quiser desabilitar a animação de menu pop-up entre funções, crie um `CMFCDisableMenuAnimation` objeto no heap e, em seguida, exclua-o quando desejar restaurar a animação do menu pop-up.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar a pilha para desabilitar temporariamente a animação de menu.

[!code-cpp[NVC_MFC_Misc#1](../../mfc/reference/codesnippet/cpp/cmfcdisablemenuanimation-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMFCDisableMenuAnimation](../../mfc/reference/cmfcdisablemenuanimation-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpopupmenu. h

## <a name="cmfcdisablemenuanimationrestore"></a><a name="restore"></a> CMFCDisableMenuAnimation:: Restore

Restaura a animação anterior usada pela estrutura para exibir um menu pop-up.

```cpp
void Restore ();
```

### <a name="remarks"></a>Comentários

Esse método é chamado pelo `CMFCDisableMenuAnimation` destruidor para restaurar a animação anterior usada pela estrutura para exibir um menu pop-up.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)
