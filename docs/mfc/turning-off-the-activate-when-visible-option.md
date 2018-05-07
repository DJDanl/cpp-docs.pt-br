---
title: Desativar a opção Ativar quando visível | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], activate options
- Activate When Visible option [MFC]
ms.assetid: 8f7ddc5a-a7a6-4da8-bcb9-1b569f0ecb48
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5625e7d05ea09188aaa2ea50ca629204a4bacc07
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="turning-off-the-activate-when-visible-option"></a>Desativando a opção Ativar Quando Visível
Um controle tem dois estados básico: ativas e inativas. Tradicionalmente, esses estados foram diferenciados por se o controle tiver uma janela. Um controle ativo tinha uma janela. um controle inativo não faziam isso. Com a introdução da ativação sem janelas, essa diferença não é mais universal, mas ainda se aplica a vários controles.  
  
 Em comparação com o restante da inicialização normalmente é executada por um controle ActiveX, a criação de uma janela é uma operação muito cara. Idealmente, um controle seria adiar a criação de sua janela até que absolutamente necessário.  
  
 Muitos controles não precisa estar ativo sempre que estiverem visíveis em um contêiner. Geralmente, um controle pode permanecer no estado inativo até que o usuário executa uma operação que exige que ele se torne ativa (por exemplo, clicando com o mouse ou pressionando a tecla TAB). Para fazer com que um controle permanecem inativos até que o contêiner deve ativá-lo, remova o **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador de sinalizadores de diversos do controle:  
  
 [!code-cpp[NVC_MFC_AxOpt#9](../mfc/codesnippet/cpp/turning-off-the-activate-when-visible-option_1.cpp)]  
  
 O **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador for omitido automaticamente se você desativar o **Ativar quando visível** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do ActiveX do MFC Assistente de controle quando você criar seu controle.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

