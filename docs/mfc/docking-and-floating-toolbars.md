---
title: "Encaixando e flutuando barras de ferramentas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CBRS_SIZE_DYNAMIC"
  - "CBRS_SIZE_FIXED"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante CBRS_ALIGN_ANY"
  - "Constante CBRS_SIZE_DYNAMIC"
  - "Constante CBRS_SIZE_FIXED"
  - "barras de ferramentas de tamanho fixo"
  - "paletas flutuantes"
  - "barras de ferramentas flutuantes"
  - "janelas com moldura, ancoragem de barra de ferramentas"
  - "paletas, flutuante"
  - " (tamanho)"
  - " (tamanho), barras de ferramentas"
  - "controles de barra de ferramentas [MFC], disposição"
  - "barras de ferramentas [C++], encaixe"
  - "barras de ferramentas [C++], flutuante"
  - "barras de ferramentas [C++],  (tamanho)"
  - "barras de ferramentas [C++], disposição"
ms.assetid: b7f9f9d4-f629-47d2-a3c4-2b33fa6b51e4
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Encaixando e flutuando barras de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de classes do Microsoft oferece suporte às barras de ferramentas encaixáveis.  Uma barra de ferramentas encaixável pode ser anexado, ou logon, a qualquer lado da janela pai, ou a ele pode ser desanexado, ou flutuado, em sua própria janela de mini\- quadro.  Este artigo explica como usar barras de ferramentas encaixáveis em seus aplicativos.  
  
 Se você usar o assistente de aplicativo para gerar o esqueleto do seu aplicativo, você será solicitado a escolha se você deseja barras de ferramentas encaixáveis.  Por padrão, o assistente de aplicativo gerencia o código que executa três ações necessárias coloque uma barra de ferramentas encaixável em seu aplicativo:  
  
-   [Habilitar o encaixe em uma janela do quadro](#_core_enabling_docking_in_a_frame_window).  
  
-   [Habilitar o encaixe de uma barra de ferramentas](#_core_enabling_docking_for_a_toolbar).  
  
-   [Encaixe a barra de ferramentas \(à janela do quadro\)](#_core_docking_the_toolbar).  
  
 Se qualquer uma dessas etapas estiverem ausentes, o aplicativo exibe uma barra de ferramentas padrão.  As duas últimas etapas devem ser executadas para cada barra de ferramentas encaixável em seu aplicativo.  
  
 Outros tópicos abordados neste artigo incluem:  
  
-   [Flutuando a barra de ferramentas](#_core_floating_the_toolbar)  
  
-   [Redimensionando dinamicamente a barra de ferramentas](#_core_dynamically_resizing_the_toolbar)  
  
-   [Definindo as posições de quebra automática para uma barra de ferramentas de estilo fixa](#_core_setting_wrap_positions_for_a_fixed.2d.style_toolbar)  
  
 Consulte o exemplo [DOCKTOOL](../top/visual-cpp-samples.md) gerais de MFC para obter exemplos.  
  
##  <a name="_core_enabling_docking_in_a_frame_window"></a> Habilitando o encaixe em uma janela do quadro  
 Para as barras de ferramentas a uma janela do quadro, a janela do quadro ou \(o destino\) devem ser habilitados para permitir logon.  Isso é feito usando a função de [CFrameWnd::EnableDocking](../Topic/CFrameWnd::EnableDocking.md) , que assume um parâmetro de `DWORD` que é um conjunto de indicação os bits de estilo que o lado da janela do quadro aceita o encaixe.  Se uma barra de ferramentas está prestes a ser inserida e houver vários lados que pode ser feito logon no, os lados indicados no parâmetro passado a `EnableDocking` são usados na seguinte ordem: parte superior, inferior, à esquerda, direita.  Se você deseja poder entre barras de controle em qualquer lugar, passe `CBRS_ALIGN_ANY` a `EnableDocking`.  
  
##  <a name="_core_enabling_docking_for_a_toolbar"></a> Habilitando o encaixe de uma barra de ferramentas  
 Após preparar o destino do logon, você deve preparar a barra de ferramentas \(ou a origem\) de uma maneira semelhante.  Chame [CControlBar::EnableDocking](../Topic/CControlBar::EnableDocking.md) para cada barra de ferramentas que você deseja inserir, especificando os lados de destino à qual a barra de ferramentas deve fazer logon.  Se nenhum dos lados especificados na chamada à correspondência de `CControlBar::EnableDocking` os lados habilitados digitando na janela do quadro, a barra de ferramentas não podem efetuar logon — flutuarão.  Uma vez que foi flutuado, ele permanecerá uma barra de ferramentas flutuante, conseguir fazer logon na janela do quadro.  
  
 Se o efeito desejado é uma barra de ferramentas permanentemente flutuante, chama `EnableDocking` com um parâmetro de 0.  Em [CFrameWnd::FloatControlBar](../Topic/CFrameWnd::FloatControlBar.md)chamada.  A barra de ferramentas permaneça float, permanentemente não é possível fazer em qualquer lugar.  
  
##  <a name="_core_docking_the_toolbar"></a> Registrando a barra de ferramentas  
 A estrutura chama [CFrameWnd::DockControlBar](../Topic/CFrameWnd::DockControlBar.md) quando o usuário tenta remover a barra de ferramentas em um lado da janela do tableau que permite fazer logon.  
  
 Além disso, você pode chamar essa função a qualquer momento para as barras de controle para a janela do quadro.  Isso é feito normalmente durante a inicialização.  Mais de uma barra de ferramentas pode ser entrada para um lado específico da janela do quadro.  
  
##  <a name="_core_floating_the_toolbar"></a> Flutuando a barra de ferramentas  
 Desanexando uma barra de ferramentas encaixável da janela do quadro é chamado flutuando a barra de ferramentas.  Chame [CFrameWnd::FloatControlBar](../Topic/CFrameWnd::FloatControlBar.md) para fazer isso.  Especifique a barra de ferramentas a ser flutuados, o ponto onde deve ser colocada, e um estilo de alinhamento que determina se a barra de ferramentas de flutuação é horizontal ou vertical.  
  
 A estrutura chamará essa função quando um usuário arrasta uma barra de ferramentas fora de seu local digitado solta\-a em um local em que o logon não está habilitado.  Isso pode ser em qualquer lugar dentro ou fora da janela do quadro.  Como com `DockControlBar`, você também pode chamar essa função durante a inicialização.  
  
 A implementação de MFC de barras de ferramentas encaixáveis não fornece alguns dos recursos estendidos localizados em alguns aplicativos que dão suporte a barra de ferramentas encaixáveis.  Os recursos como barras de ferramentas e não forem fornecidos.  
  
##  <a name="_core_dynamically_resizing_the_toolbar"></a> Redimensionando dinamicamente a barra de ferramentas  
 A partir da versão 4,0 do Visual C\+\+, você pode torná\-la possível para usuários de seu aplicativo redimensionar dinamicamente barras de ferramentas flutuante.  Normalmente, uma barra de ferramentas tem uma forma longa, linear, exibidas horizontalmente.  Mas você pode alterar a forma da barra de ferramentas orientação e.  Por exemplo, quando o usuário insere uma barra de ferramentas em um dos lados verticais da janela do quadro, a forma é alterado para um layout vertical.  Também é possível refazer a barra de ferramentas em um retângulo com várias linhas de botões.  
  
 Você pode:  
  
-   Especifique o tamanho dinâmica como uma característica da barra de ferramentas.  
  
-   Especifique o tamanho fixo como uma característica da barra de ferramentas.  
  
 Para fornecer esse suporte, há dois novos estilos da barra de ferramentas para uso em seus chamadas para a função de membro de [CToolBar::Create](../Topic/CToolBar::Create.md) .  Elas são:  
  
-   A barra de controle de**CBRS\_SIZE\_DYNAMIC**é dinâmico.  
  
-   A barra de controle de**CBRS\_SIZE\_FIXED**é fixa.  
  
 O estilo dinâmico de tamanho permite que o usuário redimensionar a barra de ferramentas a serem flutuantes, mas não quando estiver conectado.  A barra de ferramentas “envolve” onde necessário deformar como os arrastos as bordas do usuário.  
  
 O estilo tamanho fixo preserva os estados de quebra automática de uma barra de ferramentas, corrigir a posição dos botões em cada coluna.  O usuário do aplicativo não pode alterar a forma da barra de ferramentas.  Encapsula na barra de ferramentas em locais criados, como os locais dos separadores entre os botões.  Mantém essa forma se a barra de ferramentas será entrada ou float.  O efeito é uma paleta fixa com várias colunas dos botões.  
  
 Você também pode usar [CToolBar::GetButtonStyle](../Topic/CToolBar::GetButtonStyle.md) para retornar um estado e um estilo dos botões em suas barras de ferramentas.  O estilo de um botão determina como o botão é exibido e como responder à entrada do usuário; o estado indica se o botão está em um estado ajustado.  
  
##  <a name="_core_setting_wrap_positions_for_a_fixed.2d.style_toolbar"></a> Definindo as posições de quebra automática para uma barra de ferramentas de estilo fixa  
 Para uma barra de ferramentas com o estilo tamanho fixo, os índices criados no botão na barra de ferramentas na barra de ferramentas envolverão.  O código a seguir mostra como fazer isso na substituição de `OnCreate` da janela do quadro principal:  
  
 [!code-cpp[NVC_MFCDocViewSDI#10](../mfc/codesnippet/CPP/docking-and-floating-toolbars_1.cpp)]  
  
 Mostra de [DOCKTOOL](../top/visual-cpp-samples.md) de exemplo gerais de MFC como usar funções de membro das classes [CControlBar](../mfc/reference/ccontrolbar-class.md) e [CToolBar](../mfc/reference/ctoolbar-class.md) para gerenciar o layout dinâmico de uma barra de ferramentas.  Consulte o arquivo EDITBAR.CPP em DOCKTOOL.  
  
### Que você deseja saber mais?  
  
-   [Conceitos básicos da barra de ferramentas](../mfc/toolbar-fundamentals.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../Topic/Toolbar%20Tool%20Tips.md)  
  
-   [Usando suas barras de ferramentas antigos](../Topic/Using%20Your%20Old%20Toolbars.md)  
  
## Consulte também  
 [Implementação da barra de ferramentas MFC](../mfc/mfc-toolbar-implementation.md)