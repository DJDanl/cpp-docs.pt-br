---
title: "Controles ActiveX MFC: Otimização | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 46a17a6594db6c59148042f6e8c6cc72c7068dc0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-optimization"></a>Controles ActiveX MFC: otimização
Este artigo explica as técnicas que você pode usar para otimizar seus controles ActiveX para melhorar o desempenho.  
  
 Os tópicos [ativar desativar a opção Ativar quando visível](../mfc/turning-off-the-activate-when-visible-option.md) e [fornecendo Mouse interação enquanto inativo](../mfc/providing-mouse-interaction-while-inactive.md) discutir os controles que não criam uma janela até que ativado. O tópico [fornecendo ativação sem janelas](../mfc/providing-windowless-activation.md) discute controles que nunca criarem uma janela, mesmo quando elas são habilitadas.  
  
 Windows tem duas principais desvantagens para objetos OLE: elas impedem que objetos sendo transparente ou não retangular quando ativa e adicionarem uma grande sobrecarga para a instanciação e a exibição dos controles. Normalmente, a criação de uma janela demora 60 por cento do tempo de criação do controle. Com uma única janela compartilhada (geralmente do contêiner) e algum código expedição, um controle recebe os mesmos serviços de janela, geralmente sem perda de desempenho. Ter uma janela é principalmente uma sobrecarga desnecessária para o objeto.  
  
 Algumas otimizações não melhorar desempenho necessariamente quando o controle é usado em certos contêineres. Por exemplo, contêineres lançados antes do 1996 não deu suporte a ativação sem janelas, para que implementar esse recurso não fornecem um benefício em contêineres mais antigos. No entanto, quase todos os contêineres dá suporte à persistência, para que otimizar o código de persistência do controle provavelmente melhorará o desempenho em qualquer contêiner. Se o seu controle destina-se especificamente a ser usado com um tipo específico de contêiner, convém pesquisar que essas otimizações é suportado pelo contêiner. Em geral, no entanto, você deve tentar implementar forma muitas dessas técnicas que são aplicáveis ao seu controle específico para garantir que seu controle executa possivelmente bem como em uma ampla gama de contêineres.  
  
 Você pode implementar muitas dessas otimizações por meio de [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md), no [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página.  
  
### <a name="mfc-activex-control-wizard-ole-optimization-options"></a>Opções de otimização OLE do Assistente de controle ActiveX MFC  
  
|Configuração de controle do Assistente de controle ActiveX MFC|Ação|Mais informações|  
|-------------------------------------------------------|------------|----------------------|  
|**Ativar quando visível** caixa de seleção|Clear|[Desativando o ativar quando visível opção](../mfc/turning-off-the-activate-when-visible-option.md)|  
|**Ativação sem janelas** caixa de seleção|Selecionar|[Fornecendo ativação sem janelas](../mfc/providing-windowless-activation.md)|  
|**Contexto de dispositivo não recortado** caixa de seleção|Selecionar|[Usando um contexto de dispositivo não recortado](../mfc/using-an-unclipped-device-context.md)|  
|**Ativação cintilação** caixa de seleção|Selecionar|[Fornecendo ativação sem cintilação](../mfc/providing-flicker-free-activation.md)|  
|**As notificações quando inativo do ponteiro do mouse** caixa de seleção|Selecionar|[Fornecendo interação do mouse enquanto inativo](../mfc/providing-mouse-interaction-while-inactive.md)|  
|**Otimização de código de desenho** caixa de seleção|Selecionar|[Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md)|  
  
 Para obter informações detalhadas sobre as funções de membro que implementam essas otimizações, consulte [COleControl](../mfc/reference/colecontrol-class.md). As funções de membro são listadas pelo uso, como [operações sem janelas](http://msdn.microsoft.com/en-us/e9e28f79-9a70-4ae4-a5aa-b3e92f1904df) e [inativo funções de manipulação de ponteiro](http://msdn.microsoft.com/en-us/e9e28f79-9a70-4ae4-a5aa-b3e92f1904df).  
  
 Para obter mais informações, consulte:  
  
-   [Otimizando persistência e inicialização](../mfc/optimizing-persistence-and-initialization.md)  
  
-   [Fornecendo ativação sem janelas](../mfc/providing-windowless-activation.md)  
  
-   [Desativando o ativar quando visível opção](../mfc/turning-off-the-activate-when-visible-option.md)  
  
-   [Fornecendo interação do mouse enquanto inativo](../mfc/providing-mouse-interaction-while-inactive.md)  
  
-   [Fornecendo ativação sem cintilação](../mfc/providing-flicker-free-activation.md)  
  
-   [Usando um contexto de dispositivo não recortado](../mfc/using-an-unclipped-device-context.md)  
  
-   [Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

