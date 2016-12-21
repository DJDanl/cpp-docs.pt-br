---
title: "Controles ActiveX MFC: otimiza&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "contextos de dispositivo, não recortado para controles ActiveX MFC"
  - "Controles ActiveX sem cintilação"
  - "Controles ActiveX MFC, estado ativo/inativo"
  - "Controles ActiveX MFC, sem cintilação"
  - "Controles ActiveX MFC, interação de mouse"
  - "Controles ActiveX MFC, otimizando"
  - "Controles ActiveX MFC, sem janela"
  - "otimização, Controles ActiveX"
  - "otimizando o desempenho, Controles ActiveX"
  - "desempenho, Controles ActiveX"
  - "Controles ActiveX MFC sem janela"
ms.assetid: 8b11f26a-190d-469b-b594-5336094a0109
caps.latest.revision: 8
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: otimiza&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica técnicas que você pode usar para otimizar seus controles ActiveX para o melhor desempenho.  
  
 Os tópicos [Desativando ativar a opção visível](../mfc/turning-off-the-activate-when-visible-option.md) e [Fornecendo a interação do mouse em quando inativo](../Topic/Providing%20Mouse%20Interaction%20While%20Inactive.md) discutem os controles que não criará uma janela até ativado.  O [Fornecendo a ativação sem o windows](../mfc/providing-windowless-activation.md) tópico discute os controles que nunca criam uma janela do, mesmo quando são ativados.  
  
 O windows tem dois desvantagens principais para objetos OLE: impedem que os objetos são transparentes ou nonrectangular quando ativas, e adicionará uma grande sobrecarga a instanciação e a exibição dos controles.  Normalmente, criar uma janela tem 60 por cento da hora de criação de um controle.  Com uma única janela compartilhada \(geralmente o contêiner\) e um código de despacho, um controle recebe os mesmos serviços da janela, normalmente sem uma perda de desempenho.  Ter uma janela for predominante sobrecarga desnecessária para o objeto.  
  
 Algumas otimizações não necessariamente melhoram o desempenho quando o controle é usado em determinados contêiner.  Por exemplo, os contêineres liberados antes de 1996 não ofereciam suporte à ativação sem o windows, portanto implementar esse recurso não fornecerá um benefício em contêineres mais antigos.  No entanto, quase cada contêiner da suporte à persistência, portanto otimizar o código de persistência do controle provavelmente melhorará o desempenho em qualquer contêiner.  Se o controle é destinado especificamente ser usado com um tipo específico de contêiner, você pode querer pesquisa que essas otimizações é suportado por esse contêiner.  No entanto, em geral, você deve tentar implementar o máximo como essas técnicas como é aplicável a seu controle específico garantir que seu controle executar tão bem como pode possivelmente em uma ampla gama de contêiner.  
  
 Você pode implementar muitas dessas otimizações com [Assistente de controle ActiveX de MFC](../mfc/reference/mfc-activex-control-wizard.md), na página de [Controle configurações](../mfc/reference/control-settings-mfc-activex-control-wizard.md) .  
  
### Opções com OLE DB de otimização do assistente do controle ActiveX MFC  
  
|Controle a configuração no assistente de controle ActiveX de MFC|Ação|Mais informações|  
|----------------------------------------------------------------------|----------|----------------------|  
|Caixa de seleção de**Activate when visible**|Limpar|[Desativando ativar a opção visível](../mfc/turning-off-the-activate-when-visible-option.md)|  
|Caixa de seleção de**Windowless activation**|Select|[Fornecendo a ativação sem o windows](../mfc/providing-windowless-activation.md)|  
|Caixa de seleção de**Unclipped device context**|Select|[Usando um contexto Unclipped de dispositivo](../mfc/using-an-unclipped-device-context.md)|  
|Caixa de seleção de**Flicker\-free activation**|Select|[Fornecendo a ativação Cintilação\-livre](../mfc/providing-flicker-free-activation.md)|  
|Caixa de seleção de**Mouse pointer notifications when inactive**|Select|[Fornecendo a interação do mouse em quando inativo](../Topic/Providing%20Mouse%20Interaction%20While%20Inactive.md)|  
|Caixa de seleção de**Optimized drawing code**|Select|[Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md)|  
  
 Para obter informações detalhadas sobre as funções de membro que implementam essas otimizações, consulte [COleControl](../mfc/reference/colecontrol-class.md).  As funções de membro são listadas pelo uso do, como [Operações sem o windows](http://msdn.microsoft.com/pt-br/e9e28f79-9a70-4ae4-a5aa-b3e92f1904df) e [Funções de manipulação inativos do ponteiro](http://msdn.microsoft.com/pt-br/e9e28f79-9a70-4ae4-a5aa-b3e92f1904df).  
  
 Para obter mais informações, consulte:  
  
-   [Otimizando a persistência e a inicialização](../mfc/optimizing-persistence-and-initialization.md)  
  
-   [Fornecendo a ativação sem o windows](../mfc/providing-windowless-activation.md)  
  
-   [Desativando ativar a opção visível](../mfc/turning-off-the-activate-when-visible-option.md)  
  
-   [Fornecendo a interação do mouse em quando inativo](../Topic/Providing%20Mouse%20Interaction%20While%20Inactive.md)  
  
-   [Fornecendo a ativação Cintilação\-livre](../mfc/providing-flicker-free-activation.md)  
  
-   [Usando um contexto Unclipped de dispositivo](../mfc/using-an-unclipped-device-context.md)  
  
-   [Otimizando o desenho de controle](../mfc/optimizing-control-drawing.md)  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)