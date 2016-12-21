---
title: "Desenhando uma exibi&#231;&#227;o | Microsoft Docs"
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
  - "contextos de dispositivo, desenhos da tela"
  - "desenho, em exibições"
  - "pintar mensagens na classe de exibição"
  - "imprimindo [MFC], modos de exibição"
  - "imprimindo exibições"
  - "modos de exibição, imprimindo"
  - "modos de exibição, renderização"
  - "modos de exibição, atualizando"
ms.assetid: e3761db6-0f19-4482-a4cd-ac38ef7c4d3a
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Desenhando uma exibi&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quase todo o desenho em seu aplicativo ocorre na função de membro de `OnDraw` da exibição, que você deve substituir em sua classe da exibição. \(A exceção é desenho do mouse em, discutido em [Interpretando a entrada do usuário através de uma exibição](../mfc/interpreting-user-input-through-a-view.md).\) A substituição de `OnDraw` :  
  
1.  Obtém dados chamando funções de membro do documento que você fornece.  
  
2.  Exibe os dados chamando funções de membro de um objeto do dispositivo contexto que a estrutura passa a `OnDraw`.  
  
 Quando os dados de um documento será alterado de alguma forma, a exibição deve ser redesenhada para refletir as alterações.  Geralmente, isso ocorre quando o usuário faz uma alteração com uma exibição no documento.  Nesse caso, a exibição chama a função de membro de [UpdateAllViews](../Topic/CDocument::UpdateAllViews.md) do documento para notificar todas as exibições no mesmo documento para atualizar\-se.  `UpdateAllViews` chama a função de membro de [OnUpdate](../Topic/CView::OnUpdate.md) de cada exibição.  A implementação padrão de `OnUpdate` invalida a área do cliente da exibição.  Você pode substituí\-la para invalidar somente as regiões da área de cliente que mapeiam para as partes alteradas do documento.  
  
 A função de membro de `UpdateAllViews` da classe **CDocument** e a função de membro de `OnUpdate` da classe `CView` permitem passar informações que descrevem quais partes do documento foram alteradas.  Esse mecanismo de “dica” permite limitar a área que a exibição deve redesenhar.  `OnUpdate` usa dois argumentos “dica”.  O primeiro, `lHint`, do tipo **LPARAM**, deix\-o\-ar transmitir todos os dados que você gostar, quando o segundo, `pHint`, do tipo `CObject`\*, permite passar um ponteiro para qualquer objeto derivado de `CObject`.  
  
 Quando uma exibição se tornar inválido, as janelas a envia uma mensagem de `WM_PAINT` .  A função de manipulador de [OnPaint](../Topic/CWnd::OnPaint.md) de exibição responder à mensagem criando um objeto do dispositivo contexto da classe [CPaintDC](../mfc/reference/cpaintdc-class.md) e chama a função de membro de `OnDraw` de sua exibição.  Você não tem que normalmente escrever uma função substituindo do manipulador de `OnPaint` .  
  
 [contexto de dispositivo](../Topic/Device%20Contexts.md) é uma estrutura de dados do windows que contém informações sobre os atributos de desenho de um dispositivo como uma exibição ou uma impressora.  Todas as chamadas de desenho são feitas por meio de um objeto do dispositivo contexto.  Para desenhar na tela, `OnDraw` é transmitido para um objeto de `CPaintDC` .  Para desenhar em uma impressora, é passado um objeto de [CDC](../Topic/CDC%20Class.md) configurado para a impressora atual.  
  
 Seu código para desenhar na exibição primeiro recupera um ponteiro para o documento, então faz chamadas de desenho com o contexto do dispositivo.  O exemplo simples de `OnDraw` ilustra o processo:  
  
 [!code-cpp[NVC_MFCDocView#1](../mfc/codesnippet/CPP/drawing-in-a-view_1.cpp)]  
  
 Neste exemplo, você definirá a função de `GetData` como um membro da sua classe derivada do documento.  
  
 As cópias do exemplo de cadeia de caracteres obtém o do documento, centralizadas na exibição.  Se a chamada de `OnDraw` é para o desenho da tela, o objeto de `CDC` transmitido em `pDC` é `CPaintDC` cujo construtor `BeginPaint`já tiver chamado.  As chamadas para desenhar funções são feitas pelo ponteiro de dispositivo contexto.  Para obter informações sobre os contextos de dispositivo e das chamadas de desenho, consulte a classe [CDC](../Topic/CDC%20Class.md) na *Referência do MFC* e em [Trabalhar com objetos da janela](../Topic/Working%20with%20Window%20Objects.md).  
  
 Para obter mais exemplos de como escrever `OnDraw`, consulte [MFC Exemplos](../top/visual-cpp-samples.md).  
  
## Consulte também  
 [Usando exibições](../mfc/using-views.md)