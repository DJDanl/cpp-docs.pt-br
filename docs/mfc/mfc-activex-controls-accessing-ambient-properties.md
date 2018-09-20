---
title: 'Controles ActiveX MFC: Acessando Propriedades ambiente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], accessing ambient properties
- properties [MFC], accessing ambient
ms.assetid: fdc9db29-e6b0-45d2-a879-8bd60e2058a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8aaa379513695f3cd39589a1009e3a157d957761
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407889"
---
# <a name="mfc-activex-controls-accessing-ambient-properties"></a>Controles ActiveX MFC: acessando propriedades ambiente

Este artigo discute como um controle ActiveX pode acessar as propriedades de ambiente de seu contêiner de controle.

Um controle pode obter informações sobre seu contêiner acessando propriedades de ambiente do contêiner. Essas propriedades expõem as características visuais, como a cor de plano de fundo do contêiner, a fonte atual usada pelo contêiner e as características operacionais, como se o contêiner está atualmente no modo de usuário ou o modo de designer. Um controle pode usar propriedades de ambiente para personalizar sua aparência e comportamento para o contêiner particular na qual ele é incorporado. No entanto, um controle nunca deve presumir que seu contêiner será compatível com qualquer propriedade de ambiente específica. Na verdade, alguns contêineres podem não aceitar quaisquer propriedades de ambiente em todos os. Na ausência de uma propriedade de ambiente, um controle deve pressupor um valor padrão razoável.

Para acessar uma propriedade de ambiente, fazer uma chamada para [COleControl::GetAmbientProperty](../mfc/reference/colecontrol-class.md#getambientproperty). Essa função espera que a ID de expedição para a propriedade de ambiente como o primeiro parâmetro (o arquivo OLECTL. H define identificadores de expedição para o conjunto padrão de propriedades de ambiente).

Os parâmetros do `GetAmbientProperty` função são a ID de expedição, uma marca de variant que indica o tipo de propriedade esperado e um ponteiro de memória em que o valor deve ser retornado. O tipo de dados ao qual se refere a esse ponteiro irá variar dependendo da marca variant. A função retornará **verdadeira** se o contêiner dá suporte à propriedade, caso contrário, ele retornará **falso**.

O exemplo de código a seguir obtém o valor da propriedade ambiente chamado "Modo do usuário". Se a propriedade não é suportada pelo contêiner, um valor padrão de **verdadeira** presume-se:

[!code-cpp[NVC_MFC_AxUI#30](../mfc/codesnippet/cpp/mfc-activex-controls-accessing-ambient-properties_1.cpp)]

Para sua conveniência, `COleControl` fornece funções auxiliares que acessam a muitas das propriedades de ambiente comumente usadas e retornam os padrões apropriados quando as propriedades não estão disponíveis. Essas funções auxiliares são da seguinte maneira:

- [COleControl::AmbientBackColor](../mfc/reference/colecontrol-class.md#ambientbackcolor)

- [AmbientDisplayName](../mfc/reference/colecontrol-class.md#ambientdisplayname)

- [AmbientFont](../mfc/reference/colecontrol-class.md#ambientfont)

    > [!NOTE]
    >  Chamador deve chamar `Release( )` sobre a fonte retornada.

- [AmbientForeColor](../mfc/reference/colecontrol-class.md#ambientforecolor)

- [AmbientLocaleID](../mfc/reference/colecontrol-class.md#ambientlocaleid)

- [AmbientScaleUnits](../mfc/reference/colecontrol-class.md#ambientscaleunits)

- [AmbientTextAlign](../mfc/reference/colecontrol-class.md#ambienttextalign)

- [AmbientUserMode](../mfc/reference/colecontrol-class.md#ambientusermode)

- [AmbientUIDead](../mfc/reference/colecontrol-class.md#ambientuidead)

- [AmbientShowHatching](../mfc/reference/colecontrol-class.md#ambientshowhatching)

- [AmbientShowGrabHandles](../mfc/reference/colecontrol-class.md#ambientshowgrabhandles)

Se o valor de uma propriedade de ambiente for alterado (por meio de alguma ação do contêiner), o `OnAmbientPropertyChanged` é chamada de função de membro do controle. Substitua essa função de membro para lidar com uma notificação. O parâmetro `OnAmbientPropertyChanged` é a ID de expedição da propriedade ambiente afetada. O valor dessa ID de expedição pode ser DISPID_UNKNOWN, que indica que um ou mais propriedades de ambiente foi alterado, mas não estão disponíveis com informações sobre quais propriedades foram afetadas.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

