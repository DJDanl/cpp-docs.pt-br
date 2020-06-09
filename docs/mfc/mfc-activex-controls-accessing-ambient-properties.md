---
title: 'Controles ActiveX MFC: acessando propriedades ambiente'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], accessing ambient properties
- properties [MFC], accessing ambient
ms.assetid: fdc9db29-e6b0-45d2-a879-8bd60e2058a7
ms.openlocfilehash: e5c78c9943f8baeadcc1198ee8c96f2023ac0215
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625439"
---
# <a name="mfc-activex-controls-accessing-ambient-properties"></a>Controles ActiveX MFC: acessando propriedades ambiente

Este artigo discute como um controle ActiveX pode acessar as propriedades de ambiente de seu contêiner de controle.

Um controle pode obter informações sobre seu Contêiner acessando as propriedades de ambiente do contêiner. Essas propriedades expõem características visuais, como a cor do plano de fundo do contêiner, a fonte atual usada pelo contêiner e as características operacionais, como se o contêiner está atualmente no modo de usuário ou de designer. Um controle pode usar propriedades de ambiente para personalizar sua aparência e comportamento para o contêiner específico no qual ele está inserido. No entanto, um controle nunca deve supor que seu contêiner dará suporte a qualquer propriedade de ambiente específica. Na verdade, alguns contêineres podem não dar suporte a todas as propriedades de ambiente. Na ausência de uma propriedade de ambiente, um controle deve assumir um valor padrão razoável.

Para acessar uma propriedade de ambiente, faça uma chamada para [COleControl:: Getambienteproperty](reference/colecontrol-class.md#getambientproperty). Essa função espera a ID de expedição para a propriedade de ambiente como o primeiro parâmetro (o arquivo OLECTL. H define as IDs de expedição para o conjunto padrão de propriedades de ambiente).

Os parâmetros da `GetAmbientProperty` função são a ID de expedição, uma marca de variante que indica o tipo de propriedade esperado e um ponteiro para a memória em que o valor deve ser retornado. O tipo de dados ao qual esse ponteiro se refere variará dependendo da marca de variante. A função retornará **true** se o contêiner oferecer suporte à propriedade; caso contrário, retornará **false**.

O exemplo de código a seguir obtém o valor da propriedade de ambiente chamada "UserMode". Se a propriedade não for suportada pelo contêiner, um valor padrão **true** será assumido:

[!code-cpp[NVC_MFC_AxUI#30](codesnippet/cpp/mfc-activex-controls-accessing-ambient-properties_1.cpp)]

Para sua conveniência, o `COleControl` fornece funções auxiliares que acessam muitas das propriedades de ambiente usadas com frequência e retornam os padrões apropriados quando as propriedades não estão disponíveis. Essas funções auxiliares são as seguintes:

- [COleControl::AmbientBackColor](reference/colecontrol-class.md#ambientbackcolor)

- [AmbientDisplayName](reference/colecontrol-class.md#ambientdisplayname)

- [AmbientFont](reference/colecontrol-class.md#ambientfont)

    > [!NOTE]
    >  O chamador deve chamar `Release( )` na fonte retornada.

- [AmbientForeColor](reference/colecontrol-class.md#ambientforecolor)

- [AmbientLocaleID](reference/colecontrol-class.md#ambientlocaleid)

- [AmbientScaleUnits](reference/colecontrol-class.md#ambientscaleunits)

- [AmbientTextAlign](reference/colecontrol-class.md#ambienttextalign)

- [AmbientUserMode](reference/colecontrol-class.md#ambientusermode)

- [AmbientUIDead](reference/colecontrol-class.md#ambientuidead)

- [AmbientShowHatching](reference/colecontrol-class.md#ambientshowhatching)

- [AmbientShowGrabHandles](reference/colecontrol-class.md#ambientshowgrabhandles)

Se o valor de uma propriedade de ambiente for alterado (por meio de alguma ação do contêiner), a `OnAmbientPropertyChanged` função de membro do controle será chamada. Substitua essa função de membro para lidar com tal notificação. O parâmetro para `OnAmbientPropertyChanged` é a ID de expedição da propriedade de ambiente afetada. O valor dessa ID de expedição pode ser DISPID_UNKNOWN, o que indica que uma ou mais propriedades de ambiente foram alteradas, mas as informações sobre quais propriedades foram afetadas não estão disponíveis.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
