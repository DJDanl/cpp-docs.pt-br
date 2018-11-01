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
ms.openlocfilehash: cc4d210abe0bca5ba8d3a442796173111f45f6e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588559"
---
# <a name="mfc-activex-controls-optimization"></a>Controles ActiveX MFC: otimização

Este artigo explica as técnicas que você pode usar para otimizar seus controles ActiveX para melhorar o desempenho.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Os tópicos [transformando desativar a opção Ativar quando visível](../mfc/turning-off-the-activate-when-visible-option.md) e [fornecendo Mouse interação enquanto inativo](../mfc/providing-mouse-interaction-while-inactive.md) discutir os controles que não criam uma janela até ser ativado. O tópico [fornecendo ativação sem janelas](../mfc/providing-windowless-activation.md) discute os controles que nunca criam uma janela, mesmo quando elas são habilitadas.

Windows tem duas desvantagens importantes para objetos OLE: eles impedir que os objetos que estão sendo transparente ou não retangular ao Active Directory e adicionarem uma grande sobrecarga para a instanciação e a exibição de controles. Normalmente, a criação de uma janela leva 60 por cento do tempo de criação de um controle. Com uma única janela compartilhada (normalmente do contêiner) e algum código de expedição, um controle recebe os mesmos serviços de janela, geralmente sem perda de desempenho. Ter uma janela é principalmente uma sobrecarga desnecessária para o objeto.

Algumas otimizações não melhora necessariamente desempenho quando o controle é usado em certos contêineres. Por exemplo, contêineres lançados antes do 1996 não deu suporte a ativação sem janelas, para que implementar esse recurso não fornecerá um benefício em contêineres mais antigos. No entanto, praticamente cada contêiner oferece suporte a persistência, otimizar o código de persistência do seu controle provavelmente melhorará o desempenho de qualquer contêiner. Se seu controle especificamente se destina a ser usado com um tipo específico de contêiner, você pode deseja pesquisar qual dessas otimizações é compatível com esse contêiner. Em geral, no entanto, você deve tentar implementar de forma muitas dessas técnicas como são aplicáveis ao seu controle específico para garantir que seu controle executa, possivelmente, bem como em uma ampla gama de contêineres.

Você pode implementar muitas dessas otimizações por meio do [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md), no [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página.

### <a name="mfc-activex-control-wizard-ole-optimization-options"></a>Opções de otimização OLE do Assistente de controle ActiveX MFC

|Configuração de controle do Assistente de controle ActiveX MFC|Ação|Mais informações|
|-------------------------------------------------------|------------|----------------------|
|**Ativar quando visível** caixa de seleção|Clear|[Desativando a ativar quando visível opção](../mfc/turning-off-the-activate-when-visible-option.md)|
|**Ativação sem janelas** caixa de seleção|Selecionar|[Fornecendo ativação sem janelas](../mfc/providing-windowless-activation.md)|
|**Contexto de dispositivo não recortado** caixa de seleção|Selecionar|[Usando um contexto de dispositivo não recortado](../mfc/using-an-unclipped-device-context.md)|
|**Ativação cintilação** caixa de seleção|Selecionar|[Fornecendo ativação sem cintilação](../mfc/providing-flicker-free-activation.md)|
|**As notificações quando inativo do ponteiro do mouse** caixa de seleção|Selecionar|[Fornecendo interação do mouse enquanto inativo](../mfc/providing-mouse-interaction-while-inactive.md)|
|**Com a otimização de código de desenho** caixa de seleção|Selecionar|[Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md)|

Para obter informações detalhadas sobre as funções de membro que implementam essas otimizações, consulte [COleControl](../mfc/reference/colecontrol-class.md).

Para obter mais informações, consulte:

- [Otimizando persistência e inicialização](../mfc/optimizing-persistence-and-initialization.md)

- [Fornecendo ativação sem janelas](../mfc/providing-windowless-activation.md)

- [Desativando a ativar quando visível opção](../mfc/turning-off-the-activate-when-visible-option.md)

- [Fornecendo interação do mouse enquanto inativo](../mfc/providing-mouse-interaction-while-inactive.md)

- [Fornecendo ativação sem cintilação](../mfc/providing-flicker-free-activation.md)

- [Usando um contexto de dispositivo não recortado](../mfc/using-an-unclipped-device-context.md)

- [Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

