---
title: 'Controles ActiveX MFC: Acessando Propriedades ambiente | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], accessing ambient properties
- properties [MFC], accessing ambient
ms.assetid: fdc9db29-e6b0-45d2-a879-8bd60e2058a7
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b05e6d37a0550cf157dcd43a22689c9db029b51f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-accessing-ambient-properties"></a>Controles ActiveX MFC: acessando propriedades ambiente
Este artigo descreve como um controle ActiveX pode acessar as propriedades do ambiente de seu contêiner de controle.  
  
 Um controle pode obter informações sobre seu contêiner acessando propriedades ambiente do contêiner. Essas propriedades expõem características visuais, como a cor de plano de fundo do contêiner, a fonte atual usada pelo contêiner e características operacionais, como se o contêiner está em modo de usuário ou modo do designer. Um controle pode usar propriedades de ambiente para personalizar sua aparência e comportamento para o contêiner particular na qual ele está incorporado. No entanto, um controle nunca assuma que seu contêiner será compatível com qualquer propriedade de ambiente específica. Na verdade, alguns contêineres podem não suportar as propriedades de ambiente em todos os. Na ausência de uma propriedade de ambiente, um controle deve presumir um valor razoável padrão.  
  
 Para acessar uma propriedade de ambiente, fazer uma chamada para [COleControl::GetAmbientProperty](../mfc/reference/colecontrol-class.md#getambientproperty). Essa função espera que a ID de distribuição para a propriedade de ambiente como o primeiro parâmetro (o arquivo OLECTL. H define identificadores de expedição para o conjunto padrão de propriedades do ambiente).  
  
 Os parâmetros de `GetAmbientProperty` função são a identificação de expedição, uma marca de variant que indica o tipo de propriedade esperado e um ponteiro de memória em que o valor deve ser retornado. O tipo de dados ao qual se refere a esse ponteiro variam dependendo da marca variant. A função retorna **TRUE** se o contêiner tiver suporte para a propriedade, caso contrário, retorna **FALSE**.  
  
 O exemplo de código a seguir obtém o valor da propriedade de ambiente chamada "Modo de usuário". Se a propriedade não é suportada pelo contêiner, um valor padrão de **TRUE** será assumido:  
  
 [!code-cpp[NVC_MFC_AxUI#30](../mfc/codesnippet/cpp/mfc-activex-controls-accessing-ambient-properties_1.cpp)]  
  
 Para sua conveniência, `COleControl` fornece funções auxiliares que acessam muitas das propriedades de ambiente usadas com frequência e retornam padrões apropriados quando as propriedades não estão disponíveis. Essas funções auxiliares são da seguinte maneira:  
  
-   [COleControl::AmbientBackColor](../mfc/reference/colecontrol-class.md#ambientbackcolor)  
  
-   [AmbientDisplayName](../mfc/reference/colecontrol-class.md#ambientdisplayname)  
  
-   [AmbientFont](../mfc/reference/colecontrol-class.md#ambientfont)  
  
    > [!NOTE]
    >  Deve ser chamado **() de liberação** da fonte retornado.  
  
-   [AmbientForeColor](../mfc/reference/colecontrol-class.md#ambientforecolor)  
  
-   [AmbientLocaleID](../mfc/reference/colecontrol-class.md#ambientlocaleid)  
  
-   [AmbientScaleUnits](../mfc/reference/colecontrol-class.md#ambientscaleunits)  
  
-   [AmbientTextAlign](../mfc/reference/colecontrol-class.md#ambienttextalign)  
  
-   [AmbientUserMode](../mfc/reference/colecontrol-class.md#ambientusermode)  
  
-   [AmbientUIDead](../mfc/reference/colecontrol-class.md#ambientuidead)  
  
-   [AmbientShowHatching](../mfc/reference/colecontrol-class.md#ambientshowhatching)  
  
-   [AmbientShowGrabHandles](../mfc/reference/colecontrol-class.md#ambientshowgrabhandles)  
  
 Se o valor de uma propriedade de ambiente é alterado (por meio de alguma ação do contêiner), o **OnAmbientPropertyChanged** é chamada de função de membro do controle. Substitua essa função de membro para manipular uma notificação. O parâmetro **OnAmbientPropertyChanged** é a ID de expedição da propriedade ambiente afetada. O valor da ID distribuição pode ser **DISPID_UNKNOWN**, que indica que uma ou mais propriedades de ambiente foi alterado, mas não estão disponíveis com informações sobre quais propriedades foram afetadas.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

