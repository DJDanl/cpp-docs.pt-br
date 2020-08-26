---
title: Estilos de controle da ToolBar
ms.date: 11/04/2016
helpviewer_keywords:
- ToolBar control styles [MFC]
ms.assetid: 0f717eb9-fa32-4263-b852-809238863feb
ms.openlocfilehash: eab4dbde68fcebdb0afd0d058b4678c464874c81
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837119"
---
# <a name="toolbar-control-styles"></a>Estilos de controle da ToolBar

A [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) tem um conjunto de sinalizadores de estilo que determinam a aparência e o comportamento do botão. Você pode definir uma combinação desses sinalizadores chamando [CMFCToolBarButton:: SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle). Este tópico lista os valores de sinalizador de estilo e seus significados.

## <a name="property-values"></a>Valores da propriedade

Os valores a seguir determinam o tipo de botão que o controle representa:

|Nome|Descrição|
|-|-|
|TBBS_BUTTON|Pressão padrão (padrão).  |
|TBBS_CHECKBOX|Caixa de seleção.  |
|TBBS_CHECKGROUP|O início de um grupo de caixas de seleção.  |
|TBBS_GROUP|O início de um grupo de botões.  |
|TBBS_SEPARATOR|Caractere.  |

Os seguintes valores representam o status atual do controle:

|Nome|Descrição|
|-|-|
|TBBS_CHECKED|A caixa de seleção está marcada.  |
|TBBS_DISABLED|O controle está desabilitado.  |
|TBBS_INDETERMINATE|A caixa de seleção está em um estado indeterminado.  |
|TBBS_PRESSED|Botão é pressionado.  |

O valor a seguir altera o layout do botão na barra de ferramentas:

|Nome|Descrição|
|-|-|
|TBBS_BREAK|Coloca o item em uma nova linha ou em uma nova coluna sem separar colunas.  |

## <a name="remarks"></a>Comentários

O estilo atual é armazenado em [CMFCToolBarButton:: m_nStyle](../../mfc/reference/cmfctoolbarbutton-class.md#m_nstyle). Não defina um novo valor                 `m_nStyle` diretamente, porque algumas classes derivadas executam processamento adicional quando você chama `SetStyles` .

O Gerenciador visual determina a aparência dos botões em cada Estado. Consulte [Gerenciador de visualização](../../mfc/visualization-manager.md) para obter mais informações.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarbutton. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Gerenciador de visualização](../../mfc/visualization-manager.md)
