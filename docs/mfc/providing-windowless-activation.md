---
title: "Fornecendo ativa&#231;&#227;o sem janelas | Microsoft Docs"
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
  - "ativação [C++], Controles ActiveX MFC"
  - "ativação [C++], sem janela"
  - "Controles ActiveX MFC [C++], ativar opções"
  - "ativação sem janelas dos controles ActiveX MFC"
ms.assetid: 094903b5-c344-42fa-96ff-ce01e16891c5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fornecendo ativa&#231;&#227;o sem janelas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O código de criação da janela \(ou seja, tudo o que acontece quando você chama **CreateWindow**\) é caro executar.  Um controle que mantém uma janela na tela precisa gerenciar mensagens para a janela.  Os controles sem o windows são como consequência mais rápido do que controla com o windows.  
  
 Uma vantagem adicional de controles sem o windows é que, ao contrário dos controles da janela do, os controles sem windows da suporte à paint transparente e regiões nonrectangular da tela.  Um exemplo comum de um controle transparente é um controle de texto com um plano de fundo transparente.  Os controles pintam o texto mas não o plano de fundo, assim o que está sob mostra de texto completo.  Mais recentes formulários usam frequentemente controles nonrectangular, como setas os botões e arredonda.  
  
 Frequentemente, um controle não precisa de uma janela de seus próprios e, em vez disso, não pode usar os serviços da janela do respectivo contêiner, contanto que o contêiner foi registrado dar suporte a objetos sem o windows.  Os controles sem o windows são compatíveis com contêineres mais antigos.  Em contêineres mais antigas não escritos para oferecer suporte aos controles do windows, sem os controles sem windows cria uma janela quando ativas.  
  
 Como os controles sem o windows não têm suas próprias o windows, o contêiner \(que tem uma janela\) é responsável para fornecer os serviços que são fornecidos de outra forma por própria janela do controle.  Por exemplo, se suas necessidades de controle do foco de teclado, a captura do mouse, ou obter um contexto do dispositivo, essas operações são gerenciadas pelo contêiner.  O contêiner roteia as mensagens de entrada de usuário enviadas à janela ao controle do windows sem apropriado, usando a interface de `IOleInPlaceObjectWindowless` . \(Consulte *ActiveX SDK* para obter uma descrição desta interface.\) funções de membro de `COleControl` para invocar esses serviços do contêiner.  
  
 Para fazer seu controle usar a ativação sem o windows, inclua o sinalizador de **windowlessActivate** no conjunto de sinalizadores retornados por [COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md).  Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/CPP/providing-windowless-activation_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#6](../mfc/codesnippet/CPP/providing-windowless-activation_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/CPP/providing-windowless-activation_3.cpp)]  
  
 O código para incluir esse sinalizador é gerado automaticamente se você selecionar a opção de **Windowless activation** na página de [Controle configurações](../mfc/reference/control-settings-mfc-activex-control-wizard.md) do assistente do controle ActiveX MFC.  
  
 Quando a ativação sem o windows está habilitada, o contêiner delegará para as mensagens para a interface de `IOleInPlaceObjectWindowless` do controle.  a implementação de`COleControl` dessa interface despacha as mensagens pelo mapa da mensagem do seu controle, depois de definir as coordenadas do mouse em adequadamente.  Você pode processar as mensagens como mensagens comuns da janela, adicionando entradas correspondentes no mapa da mensagem.  Nos manipuladores para essas mensagens, evite usar a variável de membro de `m_hWnd` \(ou qualquer função de membro que o usar\) sem verificar primeiro se o valor não é **nulo**.  
  
 `COleControl` fornece funções de membro que invocam a captura do mouse em, o foco de teclado, o deslocamento, e outros serviços da janela do contêiner conforme apropriado, incluindo:  
  
-   [GetFocus](../Topic/COleControl::GetFocus.md), [SetFocus](../Topic/COleControl::SetFocus.md)  
  
-   [GetCapture](../Topic/COleControl::GetCapture.md), [SetCapture](../Topic/COleControl::SetCapture.md), [ReleaseCapture](../Topic/COleControl::ReleaseCapture.md)  
  
-   [GetDC](../Topic/COleControl::GetDC.md), [ReleaseDC](../Topic/COleControl::ReleaseDC.md)  
  
-   [InvalidateRgn](../Topic/COleControl::InvalidateRgn.md)  
  
-   [ScrollWindow](../Topic/COleControl::ScrollWindow.md)  
  
-   [GetClientRect](../Topic/COleControl::GetClientRect.md)  
  
 Em controles sem o windows, você sempre deve usar as funções de membro de `COleControl` em vez de funções de membro correspondente de `CWnd` ou suas funções relacionadas da API do Win32.  
  
 Talvez você queira um controle sem o windows para ser o destino de uma operação de arrastar e soltar OLE.  Normalmente, isso exigiria que a janela de controle foi registrada como um destino de descarte.  Desde que o controle não tem nenhuma janela de seus próprios, o contêiner usa sua própria janela como um destino de descarte.  O controle fornece uma implementação da interface de `IDropTarget` ao qual o contêiner pode delegar chamadas por um tempo apropriado.  Para expor essa interface para o contêiner, substitua [COleControl::GetWindowlessDropTarget](../Topic/COleControl::GetWindowlessDropTarget.md).  Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#8](../mfc/codesnippet/CPP/providing-windowless-activation_4.cpp)]  
  
## Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)