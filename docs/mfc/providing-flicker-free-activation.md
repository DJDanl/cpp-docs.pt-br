---
title: "Fornecendo ativação sem cintilação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], flicker-free
- flicker, MFC ActiveX controls
- activation [MFC], flicker-free
ms.assetid: bcb24b77-31d8-44a0-8c58-2ea6213b4c43
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1f14998ce663e5a8e53901acf9192719fa41e724
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="providing-flicker-free-activation"></a>Fornecendo ativação sem cintilação
Se o controle se desenha identicamente nos Estados inativos e ativos (e não usar a ativação sem janelas), você poderá eliminar as operações de desenho e a oscilação visual que normalmente ocorrem quando você faz a transição entre o inativo e estados ativos. Para fazer isso, inclua o **noFlickerActivate** sinalizador no conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags). Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/providing-flicker-free-activation_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#13](../mfc/codesnippet/cpp/providing-flicker-free-activation_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/providing-flicker-free-activation_3.cpp)]  
  
 O código para incluir esse sinalizador é gerado automaticamente se você selecionar o **ativação sem cintilação** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página ao criar o controle com o Assistente de controle ActiveX MFC.  
  
 Se você estiver usando a ativação sem janelas, essa otimização não tem nenhum efeito.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

