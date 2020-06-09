---
title: 'Controles ActiveX MFC: otimização'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], windowless
- flicker-free ActiveX controls
- MFC ActiveX controls [MFC], mouse interaction
- device contexts, unclipped for MFC ActiveX controls
- MFC ActiveX controls [MFC], optimizing
- performance, ActiveX controls
- optimization, ActiveX controls
- MFC ActiveX controls [MFC], flicker-free
- windowless MFC ActiveX controls
- MFC ActiveX controls [MFC], active/inactive state
- optimizing performance, ActiveX controls
ms.assetid: 8b11f26a-190d-469b-b594-5336094a0109
ms.openlocfilehash: b4e12889ca1bb5f4bb423a1f1ede1c396f8d60b5
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615397"
---
# <a name="mfc-activex-controls-optimization"></a>Controles ActiveX MFC: otimização

Este artigo explica técnicas que você pode usar para otimizar os controles ActiveX para melhorar o desempenho.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Os tópicos que desativam [a opção Ativar quando visível](turning-off-the-activate-when-visible-option.md) e [fornecem interação com o mouse enquanto inativo](providing-mouse-interaction-while-inactive.md) discutem os controles que não criam uma janela até que sejam ativados. O tópico [fornecendo ativação sem janela](providing-windowless-activation.md) discute controles que nunca criam uma janela, mesmo quando eles são ativados.

O Windows tem duas desvantagens principais para objetos OLE: eles impedem que os objetos sejam transparentes ou não possam ser desnecessários quando ativos e adicionam uma grande sobrecarga à instanciação e à exibição de controles. Normalmente, a criação de uma janela leva 60% do tempo de criação de um controle. Com uma única janela compartilhada (geralmente, o contêiner) e algum código de expedição, um controle recebe os mesmos serviços de janela, geralmente sem perda de desempenho. Ter uma janela é, na maior parte, uma sobrecarga desnecessária para o objeto.

Algumas otimizações não necessariamente melhoram o desempenho quando seu controle é usado em determinados contêineres. Por exemplo, os contêineres lançados antes de 1996 não davam suporte à ativação sem janelas, portanto, a implementação desse recurso não fornecerá um benefício em contêineres mais antigos. No entanto, quase todos os contêineres dão suporte à persistência, portanto, otimizar o código de persistência do controle provavelmente melhorará seu desempenho em qualquer contêiner. Se o seu controle destina-se especificamente a ser usado com um tipo específico de contêiner, talvez você queira Pesquisar quais dessas otimizações são suportadas por esse contêiner. Em geral, no entanto, você deve tentar implementar quantas dessas técnicas forem aplicáveis ao seu controle específico para garantir que seu controle seja executado, bem como possivelmente pode em uma ampla gama de contêineres.

Você pode implementar muitas dessas otimizações por meio do [Assistente de controle ActiveX do MFC](reference/mfc-activex-control-wizard.md), na página [configurações de controle](reference/control-settings-mfc-activex-control-wizard.md) .

### <a name="mfc-activex-control-wizard-ole-optimization-options"></a>Opções de otimização de OLE do assistente de controle ActiveX do MFC

|Configuração de controle no assistente de controle ActiveX do MFC|Ação|Mais informações|
|-------------------------------------------------------|------------|----------------------|
|Caixa de seleção **Ativar quando visível**|Liberada|[Desativando a opção Ativar quando visível](turning-off-the-activate-when-visible-option.md)|
|Caixa de seleção **ativação sem janela**|Selecionar|[Fornecendo ativação sem janelas](providing-windowless-activation.md)|
|Caixa de seleção de **contexto de dispositivo não recortado**|Selecionar|[Usando um contexto de dispositivo não recortado](using-an-unclipped-device-context.md)|
|Caixa **de seleção ativação sem cintilação**|Selecionar|[Fornecendo ativação sem cintilação](providing-flicker-free-activation.md)|
|Caixa de seleção **notificações do ponteiro do mouse quando inativo**|Selecionar|[Fornecendo interação do mouse enquanto inativo](providing-mouse-interaction-while-inactive.md)|
|Caixa de seleção de **código de desenho otimizado**|Selecionar|[Otimizando o desenho de controle](optimizing-control-drawing.md)|

Para obter informações detalhadas sobre as funções de membro que implementam essas otimizações, consulte [COleControl](reference/colecontrol-class.md).

Para obter mais informações, consulte:

- [Otimizando a persistência e a inicialização](optimizing-persistence-and-initialization.md)

- [Fornecendo ativação sem janelas](providing-windowless-activation.md)

- [Desativando a opção Ativar quando visível](turning-off-the-activate-when-visible-option.md)

- [Fornecendo interação do mouse enquanto inativo](providing-mouse-interaction-while-inactive.md)

- [Fornecendo ativação sem cintilação](providing-flicker-free-activation.md)

- [Usando um contexto de dispositivo não recortado](using-an-unclipped-device-context.md)

- [Otimizando o desenho de controle](optimizing-control-drawing.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
