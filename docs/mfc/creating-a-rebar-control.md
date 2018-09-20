---
title: Criando um controle Rebar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rebar controls [MFC], creating
- CReBarCtrl class [MFC], creating
ms.assetid: 0a012e08-772b-4f6a-af86-7cb651d11d3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea9ab73bf054b07b24beee8a222cc0a138b9513d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46395252"
---
# <a name="creating-a-rebar-control"></a>Criando um controle rebar

[CReBarCtrl](../mfc/reference/crebarctrl-class.md) objetos devem ser criados antes do objeto pai é visível. Isso minimiza as possibilidades de problemas de pintura.

Por exemplo, controles rebar (usados em objetos de janela de quadro) são usados como janelas de pai para controles de barra de ferramentas. Portanto, o pai do controle rebar é o objeto de janela do quadro. Porque o objeto de janela do quadro é o pai, o `OnCreate` a função de membro (do pai) é um excelente lugar para criar o controle rebar.

Para usar um `CReBarCtrl` do objeto, você normalmente seguirá estas etapas:

### <a name="to-use-a-crebarctrl-object"></a>Usar um objeto CReBarCtrl

1. Construir o [CReBarCtrl](../mfc/reference/crebarctrl-class.md) objeto.

1. Chame [Create](../mfc/reference/crebarctrl-class.md#create) para criar o controle comum do Windows rebar e anexá-lo para o `CReBarCtrl` objeto, especificando a qualquer estilo desejado.

1. Carregar um bitmap, com uma chamada para [CBitmap::LoadBitmap](../mfc/reference/cbitmap-class.md#loadbitmap), para ser usado como o plano de fundo do objeto de controle rebar.

1. Criar e inicializar quaisquer objetos de janela filho (barras de ferramentas, controles de caixa de diálogo e assim por diante) que estarão contidos pelo objeto de controle rebar.

1. Inicializar uma **REBARBANDINFO** estrutura com as informações necessárias para a faixa prestes a ser inserido.

1. Chame [InsertBand](../mfc/reference/crebarctrl-class.md#insertband) inserir existentes do windows filho (como `m_wndReToolBar`) no novo controle rebar. Para obter mais informações sobre como inserir as faixas em um controle rebar existente, consulte [controles Rebar e bandas](../mfc/rebar-controls-and-bands.md).

## <a name="see-also"></a>Consulte também

[Usando CReBarCtrl](../mfc/using-crebarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

