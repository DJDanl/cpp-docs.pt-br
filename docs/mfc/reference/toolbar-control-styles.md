---
title: Estilos de controle de barra de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ToolBar control styles [MFC]
ms.assetid: 0f717eb9-fa32-4263-b852-809238863feb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 35b5b87944f2b0f9ce78adbe42b59d92b98a6e5a
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37885829"
---
# <a name="toolbar-control-styles"></a>Estilos de controle da ToolBar
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) tem um conjunto de sinalizadores de estilo que determinam a aparência e comportamento do botão. Você pode definir uma combinação desses sinalizadores chamando [CMFCToolBarButton::SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle). Este tópico lista os valores de sinalizador de estilo e seus significados.  
  
## <a name="property-values"></a>Valores de propriedade  
 Os valores a seguir determinam o tipo de botão que representa o controle:  
  
 TBBS_BUTTON  
 Botão de ação padrão (padrão).  
  
 TBBS_CHECKBOX  
 Caixa de seleção.  
  
 TBBS_CHECKGROUP  
 O início de um grupo de caixas de seleção.  
  
 TBBS_GROUP  
 O início de um grupo de botões.  
  
 TBBS_SEPARATOR  
 Separador.  
  
 Os valores a seguir representam o status atual do controle:  
  
 TBBS_CHECKED  
 Caixa de seleção está marcada.  
  
 TBBS_DISABLED  
 Controle está desabilitado.  
  
 TBBS_INDETERMINATE  
 Caixa de seleção está em um estado indeterminado.  
  
 TBBS_PRESSED  
 Botão é pressionado.  
  
 O valor a seguir altera o layout do botão na barra de ferramentas:  
  
 TBBS_BREAK  
 Coloca o item em uma nova linha ou em uma nova coluna sem separar colunas.  
  
## <a name="remarks"></a>Comentários  
 O estilo atual é armazenado no [CMFCToolBarButton::m_nStyle](../../mfc/reference/cmfctoolbarbutton-class.md#m_nstyle). Não defina um novo valor `m_nStyle` diretamente, porque algumas classes derivadas realizar processamento adicional quando você chamar `SetStyles`.  
  
 O Gerenciador visual determina a aparência dos botões em cada estado. Ver [Gerenciador de visualização](../../mfc/visualization-manager.md) para obter mais informações.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarbutton.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Gerenciador de visualização](../../mfc/visualization-manager.md)


