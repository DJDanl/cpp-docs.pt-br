---
title: Encaixando e flutuando barras de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CBRS_SIZE_DYNAMIC
- CBRS_SIZE_FIXED
dev_langs:
- C++
helpviewer_keywords:
- size [MFC], toolbars
- size
- frame windows [MFC], toolbar docking
- CBRS_ALIGN_ANY constant [MFC]
- palettes, floating
- toolbars [MFC], docking
- CBRS_SIZE_DYNAMIC constant [MFC]
- floating toolbars
- toolbars [MFC], size
- toolbars [MFC], floating
- fixed-size toolbars
- CBRS_SIZE_FIXED constant [MFC]
- toolbar controls [MFC], wrapping
- toolbars [MFC], wrapping
- floating palettes
ms.assetid: b7f9f9d4-f629-47d2-a3c4-2b33fa6b51e4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 430af2344888696e3cbf053677ef59c7249b50bd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33352783"
---
# <a name="docking-and-floating-toolbars"></a>Encaixando e flutuando barras de ferramentas
A biblioteca Microsoft Foundation Class suporta encaixáveis barras de ferramentas. Uma barra de ferramentas encaixável pode ser anexada ou encaixada, para qualquer lado da sua janela pai, ou pode ser desanexado, ou flutuante, em sua própria janela do quadro simplificado. Este artigo explica como usar as barras de ferramentas encaixáveis em seus aplicativos.  
  
 Se você usar o Assistente de aplicativo para gerar o esqueleto do seu aplicativo, você precisará escolher se deseja encaixáveis barras de ferramentas. Por padrão, o Assistente de aplicativo gera o código que executa as três ações necessárias para colocar uma barra de ferramentas encaixável em seu aplicativo:  
  
-   [Ativar encaixe em uma janela do quadro](#_core_enabling_docking_in_a_frame_window).  
  
-   [Ativar encaixe de uma barra de ferramentas](#_core_enabling_docking_for_a_toolbar).  
  
-   [Encaixar a barra de ferramentas (a janela do quadro)](#_core_docking_the_toolbar).  
  
 Se qualquer uma dessas etapas estiver ausente, o aplicativo exibirá uma barra de ferramentas padrão. As duas últimas etapas devem ser executadas para cada barra de ferramentas encaixável em seu aplicativo.  
  
 Outros tópicos abordados neste artigo incluem:  
  
-   [A barra de ferramentas flutuante](#_core_floating_the_toolbar)  
  
-   [Redimensionar dinamicamente a barra de ferramentas](#_core_dynamically_resizing_the_toolbar)  
  
-   [Posições de quebra automática de configuração para uma barra de ferramentas do estilo fixa](#_core_setting_wrap_positions_for_a_fixed_style_toolbar)  
  
 Consulte o exemplo de MFC geral [DOCKTOOL](../visual-cpp-samples.md) para obter exemplos.  
  
##  <a name="_core_enabling_docking_in_a_frame_window"></a> Ativar encaixe em uma janela com moldura  
 Para encaixar barras de ferramentas em uma janela do quadro, a janela do quadro (ou o destino) deve ser habilitado para permitir encaixe. Isso é feito usando o [CFrameWnd::EnableDocking](../mfc/reference/cframewnd-class.md#enabledocking) função, que usa uma `DWORD` parâmetro que é um conjunto de estilo de bits que indica qual lado da janela do quadro aceita de encaixe. Se uma barra de ferramentas está prestes a ser encaixado e houver vários lados que ele poderia ser encaixado, os lados indicado no parâmetro passado para `EnableDocking` são usados na seguinte ordem: superior, inferior, esquerda, direita. Se você deseja ser capaz de controle de encaixe barras em qualquer lugar, transmitir `CBRS_ALIGN_ANY` para `EnableDocking`.  
  
##  <a name="_core_enabling_docking_for_a_toolbar"></a> Ativar encaixe de uma barra de ferramentas  
 Depois de preparar o destino de encaixe, você deve preparar a barra de ferramentas (ou origem) de maneira semelhante. Chamar [CControlBar::EnableDocking](../mfc/reference/ccontrolbar-class.md#enabledocking) para cada barra de ferramentas que você deseja encaixar, especificar o destino lados que deve encaixar a barra de ferramentas. Se nenhum dos lados especificados na chamada para `CControlBar::EnableDocking` corresponde os lados habilitados para a janela do quadro de encaixe, não é possível encaixar a barra de ferramentas — ela flutua. Quando tiver sido flutuante, ela permanece uma barra de ferramentas flutuante, não é possível encaixar a janela do quadro.  
  
 Se o efeito desejado é uma barra de ferramentas flutuante permanentemente, chame `EnableDocking` com um parâmetro de 0. Em seguida, chame [CFrameWnd::FloatControlBar](../mfc/reference/cframewnd-class.md#floatcontrolbar). A barra de ferramentas permanece flutuante, permanentemente, não é possível encaixar em qualquer lugar.  
  
##  <a name="_core_docking_the_toolbar"></a> Encaixe a barra de ferramentas  
 A estrutura chama [CFrameWnd::DockControlBar](../mfc/reference/cframewnd-class.md#dockcontrolbar) quando o usuário tenta descartar a barra de ferramentas em um lado da janela do quadro que permite o encaixe.  
  
 Além disso, você pode chamar essa função a qualquer momento para encaixar a janela do quadro barras de controle. Normalmente, isso é feito durante a inicialização. Mais de uma barra de ferramentas pode ser encaixada em um lado específico da janela do quadro.  
  
##  <a name="_core_floating_the_toolbar"></a> A barra de ferramentas flutuante  
 Desanexar uma encaixável barra de ferramentas da janela do quadro é chamado da barra de ferramentas flutuante. Chamar [CFrameWnd::FloatControlBar](../mfc/reference/cframewnd-class.md#floatcontrolbar) para fazer isso. Especifique um estilo de alinhamento que determina se a barra de ferramentas flutuante é horizontal ou vertical, barra de ferramentas para ser flutuante e o ponto em que ele deve ser colocado.  
  
 O framework chama esta função quando um usuário arrasta uma barra de ferramentas desativar seu local encaixado e descarta-o em um local onde o encaixe não está habilitado. Isso pode estar em qualquer lugar dentro ou fora da janela do quadro. Assim como acontece com `DockControlBar`, você também pode chamar essa função durante a inicialização.  
  
 A implementação do MFC de barras de ferramentas encaixáveis não oferece alguns dos recursos estendidos encontrados em alguns aplicativos que dão suporte a encaixáveis barras de ferramentas. Recursos como barras de ferramentas personalizadas não são fornecidos.  
  
##  <a name="_core_dynamically_resizing_the_toolbar"></a> Redimensionar dinamicamente a barra de ferramentas  
 A partir do Visual C++ versão 4.0, você pode tornar possível para os usuários do seu aplicativo para redimensionar as barras de ferramentas flutuantes dinamicamente. Normalmente, uma barra de ferramentas tem uma forma longa, linear, exibida horizontalmente. Mas você pode alterar a orientação da barra de ferramentas e forma. Por exemplo, quando o usuário encaixa uma barra de ferramentas em um dos lados verticais da janela do quadro, a forma é alterado para um layout vertical. Também é possível alterar a barra de ferramentas em um retângulo com várias linhas de botões.  
  
 Você pode:  
  
-   Especifique o dimensionamento dinâmico como uma característica de barra de ferramentas.  
  
-   Especifica tamanho fixo como uma característica de barra de ferramentas.  
  
 Para oferecer esse suporte, há dois novos estilos de barra de ferramentas para uso em suas chamadas para o [CToolBar::Create](../mfc/reference/ctoolbar-class.md#create) função de membro. Elas são:  
  
-   **CBRS_SIZE_DYNAMIC** barra de controle é dinâmica.  
  
-   **CBRS_SIZE_FIXED** barra de controle é fixo.  
  
 O estilo de tamanho dinâmico permite que o usuário redimensionar a barra de ferramentas enquanto ele estiver flutuando, mas não enquanto ela estiver encaixada. A barra de ferramentas "quebra" quando for necessário alterar a forma como o usuário arrasta bordas.  
  
 O tamanho fixo estilo preserva os estados de quebra automática de uma barra de ferramentas, corrigindo a posição dos botões em cada coluna. Usuário do aplicativo não é possível alterar a forma da barra de ferramentas. A barra de ferramentas é quebrada em locais designados, como os locais dos separadores entre os botões. Ele mantém dessa forma, se a barra de ferramentas está encaixado ou flutuante. O efeito é uma paleta fixa com várias colunas de botões.  
  
 Você também pode usar [CToolBar::GetButtonStyle](../mfc/reference/ctoolbar-class.md#getbuttonstyle) para retornar a um estado e o estilo dos botões em barras de ferramentas. Estilo do botão determina como o botão é exibido e como ele responde à entrada do usuário; o estado informa se o botão estiver em um estado encapsulado.  
  
##  <a name="_core_setting_wrap_positions_for_a_fixed_style_toolbar"></a> Posições de quebra automática de configuração para uma barra de ferramentas com estilo  
 Para uma barra de ferramentas com o tamanho fixo de estilo, designe a barra de ferramentas índices do botão em que a barra de ferramentas será quebrada. O código a seguir mostra como fazer isso na janela do quadro principal `OnCreate` substituir:  
  
 [!code-cpp[NVC_MFCDocViewSDI#10](../mfc/codesnippet/cpp/docking-and-floating-toolbars_1.cpp)]  
  
 O exemplo de MFC geral [DOCKTOOL](../visual-cpp-samples.md) mostra como usar funções de membro de classes [CControlBar](../mfc/reference/ccontrolbar-class.md) e [CToolBar](../mfc/reference/ctoolbar-class.md) para gerenciar o layout dinâmico de uma barra de ferramentas. Consulte o arquivo EDITBAR. CPP em DOCKTOOL.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Fundamentos da barra de ferramentas](../mfc/toolbar-fundamentals.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)  
  
-   [Usando as barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)  
  
## <a name="see-also"></a>Consulte também  
 [Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)

