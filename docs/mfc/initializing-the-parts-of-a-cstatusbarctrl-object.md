---
title: Inicializando as partes de um objeto CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- CStatusBarCtrl class [MFC], simple mode
- status bars [MFC], declaring parts of
- simple status bars [MFC]
- status bars [MFC], icons
- status bars [MFC], simple mode
- icons, using in status bars
- CStatusBarCtrl class [MFC], declaring parts of
ms.assetid: 60e8f285-d2d8-424a-a6ea-2fc548370303
ms.openlocfilehash: bd099a67d9f11cc3657a91b4141d3f18c6fa719d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621649"
---
# <a name="initializing-the-parts-of-a-cstatusbarctrl-object"></a>Inicializando as partes de um objeto CStatusBarCtrl

Por padrão, uma barra de status exibe informações de status usando painéis separados. Esses painéis (também conhecidos como partes) podem conter uma cadeia de caracteres de texto, um ícone ou ambos.

Use [SetParts](reference/cstatusbarctrl-class.md#setparts) para definir quantas partes e o comprimento da barra de status terão. Depois de criar as partes da barra de status, faça chamadas para [SetText](reference/cstatusbarctrl-class.md#settext) e [SetIcon](reference/cstatusbarctrl-class.md#seticon) para definir o texto ou o ícone de uma parte específica da barra de status. Depois que a parte tiver sido definida com êxito, o controle será redesenhado automaticamente.

O exemplo a seguir inicializa um `CStatusBarCtrl` objeto existente ( `m_StatusBarCtrl` ) com quatro painéis e, em seguida, define um ícone (IDI_ICON1) e algum texto na segunda parte.

[!code-cpp[NVC_MFCControlLadenDialog#31](codesnippet/cpp/initializing-the-parts-of-a-cstatusbarctrl-object_1.cpp)]

Para obter mais informações sobre como definir o modo de um `CStatusBarCtrl` objeto como simples, consulte [definindo o modo de um objeto CStatusBarCtrl](setting-the-mode-of-a-cstatusbarctrl-object.md).

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](using-cstatusbarctrl.md)<br/>
[Controles](controls-mfc.md)
