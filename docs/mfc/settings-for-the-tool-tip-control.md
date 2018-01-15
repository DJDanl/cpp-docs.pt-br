---
title: "Configurações para a ferramenta de controle da dica | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- tool tips [MFC], activating
- CToolTipCtrl class [MFC], settings
ms.assetid: ff8c5c46-2047-403a-bd98-ffec3d21ee3a
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 406e35b6ab694ca972d4cd6add0dcca7586e5005
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="settings-for-the-tool-tip-control"></a>Configurações para o controle da dica de ferramenta
Você pode definir o controle de dica de ferramenta ([CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)) a ser ativos ou inativos. Quando for definido como ativo, o controle de dica de ferramenta é exibida quando o cursor estiver em uma ferramenta. Quando você definir para ficar inativo, o controle de dica de ferramenta não aparece, mesmo se o cursor estiver em uma ferramenta. Chamar [ativar](../mfc/reference/ctooltipctrl-class.md#activate) para ativar ou desativar um controle de dica de ferramenta.  
  
 Você pode definir uma dica de ferramenta ativa para exibir a dica de ferramenta quando o cursor estiver em uma ferramenta, se a janela do proprietário do controle de dica de ferramenta está ativa ou inativa, usando ou não o **TTS_ALWAYSTIP** estilo. Se você não usar esse estilo, o controle de dica de ferramenta é exibida quando a janela do proprietário da ferramenta está ativa, mas não quando ele estiver inativo.  
  
 A maioria dos aplicativos conter barras de ferramentas com ferramentas que correspondem aos comandos de menu. Para tais ferramentas, é conveniente para o controle de dica de ferramenta exibir o mesmo texto como o item de menu correspondente. O sistema automaticamente remove os caracteres de e comercial (&) acelerador de todas as cadeias de caracteres passadas para um controle de dica de ferramenta, a menos que o controle tem o **TTS_NOPREFIX** estilo.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)

