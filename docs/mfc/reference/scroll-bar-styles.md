---
title: Estilos de barra de rolagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SBS_VERT
- SBS_SIZEBOXBOTTOMRIGHTALIGN
- SBS_LEFTALIGN
- SBS_RIGHTALIGN
- SBS_TOPALIGN
- SBS_SIZEBOXTOPLEFTALIGN
- SBS_BOTTOMALIGN
- SBS_SIZEBOX
- SBS_HORZ
dev_langs:
- C++
helpviewer_keywords:
- SBS_HORZ constant
- SBS_TOPALIGN constant
- SBS_SIZEBOX constant
- SBS_BOTTOMALIGN constant
- SBS_VERT constant
- SBS_LEFTALIGN constant
- SBS_SIZEBOXBOTTOMRIGHTALIGN constant
- scroll bars, styles
- SBS_SIZEBOXTOPLEFTALIGN constant
- SBS_RIGHTALIGN constant
ms.assetid: 8bcde35b-387d-49ae-bdd6-7cda9f5dae26
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 778fe7b0f6f6319884df4ed9c5ccbe8e34bd8d42
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="scroll-bar-styles"></a>Estilos de barra de rolagem
-   **SBS_BOTTOMALIGN** usado com o **SBS_HORZ** estilo. A parte inferior da barra de rolagem é alinhada com a borda inferior do retângulo especificado no **criar** função de membro. A barra de rolagem tem a altura padrão para barras de rolagem do sistema.  
  
-   **SBS_HORZ** designa uma barra de rolagem horizontal. Se nem o **SBS_BOTTOMALIGN** nem **SBS_TOPALIGN** estilo for especificado, a barra de rolagem tem a altura, a largura e a posição fornecida no **criar** função de membro.  
  
-   **SBS_LEFTALIGN** usado com o **SBS_VERT** estilo. A borda esquerda da barra de rolagem é alinhada com a borda esquerda do retângulo especificado no **criar** função de membro. A barra de rolagem tem a largura padrão para barras de rolagem do sistema.  
  
-   **SBS_RIGHTALIGN** usado com o **SBS_VERT** estilo. A borda direita da barra de rolagem é alinhada com a borda direita do retângulo especificado no **criar** função de membro. A barra de rolagem tem a largura padrão para barras de rolagem do sistema.  
  
-   **SBS_SIZEBOX** designa uma caixa de tamanho. Se nem o **SBS_SIZEBOXBOTTOMRIGHTALIGN** nem **SBS_SIZEBOXTOPLEFTALIGN** estilo for especificado, a caixa de tamanho tem a altura, a largura e a posição fornecida no **criar** função de membro.  
  
-   **SBS_SIZEBOXBOTTOMRIGHTALIGN** usado com o **SBS_SIZEBOX** estilo. O canto inferior direito da caixa de tamanho está alinhado com o canto inferior direito do retângulo especificado no **criar** função de membro. A caixa de tamanho tem o tamanho padrão para caixas de tamanho do sistema.  
  
-   **SBS_SIZEBOXTOPLEFTALIGN** usado com o **SBS_SIZEBOX** estilo. O canto superior esquerdo da caixa de tamanho está alinhado com o canto superior esquerdo do retângulo especificado no **criar** função de membro. A caixa de tamanho tem o tamanho padrão para caixas de tamanho do sistema.  
  
-   **SBS_SIZEGRIP** igual **SBS_SIZEBOX**, mas com uma borda aumentada.  
  
-   **SBS_TOPALIGN** usado com o **SBS_HORZ** estilo. A borda superior da barra de rolagem é alinhada com a borda superior do retângulo especificado no **criar** função de membro. A barra de rolagem tem a altura padrão para barras de rolagem do sistema.  
  
-   **SBS_VERT** designa uma barra de rolagem vertical. Se nem o **SBS_RIGHTALIGN** nem **SBS_LEFTALIGN** estilo for especificado, a barra de rolagem tem a altura, a largura e a posição fornecida no **criar** função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CScrollBar::Create](../../mfc/reference/cscrollbar-class.md#create)   
 [Estilos de controle barra de rolagem](http://msdn.microsoft.com/library/windows/desktop/bb787533)


