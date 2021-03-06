---
title: Configurações para o controle da dica de ferramenta
ms.date: 11/04/2016
helpviewer_keywords:
- tool tips [MFC], activating
- CToolTipCtrl class [MFC], settings
ms.assetid: ff8c5c46-2047-403a-bd98-ffec3d21ee3a
ms.openlocfilehash: 5cc72401da95e63520b544865ea509a8ad219bda
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307608"
---
# <a name="settings-for-the-tool-tip-control"></a>Configurações para o controle da dica de ferramenta

Você pode definir o controle da dica de ferramenta ([CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)) a ser ativos ou inativos. Quando você definir como ativo, o controle da dica de ferramenta é exibida quando o cursor estiver em uma ferramenta. Quando você defini-lo para ficar inativo, o controle da dica de ferramenta não aparece, mesmo se o cursor estiver em uma ferramenta. Chame [ativar](../mfc/reference/ctooltipctrl-class.md#activate) para ativar ou desativar um controle de dica de ferramenta.

Você pode definir uma dica de ferramenta Active Directory para exibir a dica de ferramenta quando o cursor estiver em uma ferramenta, se a janela do proprietário do controle de dica de ferramenta está ativo ou inativo, usando o estilo TTS_ALWAYSTIP ou não. Se você não usar esse estilo, o controle da dica de ferramenta é exibida quando a janela do proprietário da ferramenta está ativa, mas não quando ela está inativa.

A maioria dos aplicativos contêm as barras de ferramentas com as ferramentas que correspondem aos comandos de menu. Para tais ferramentas, é conveniente para o controle da dica de ferramenta exibir o mesmo texto como o item de menu correspondente. O sistema retira automaticamente o e comercial (&) caracteres de acelerador de todas as cadeias de caracteres passada para um controle de dica de ferramenta, a menos que o controle tem o estilo TTS_NOPREFIX.

## <a name="see-also"></a>Consulte também

[Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
