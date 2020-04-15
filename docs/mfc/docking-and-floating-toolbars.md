---
title: Encaixando e flutuando barras de ferramentas
ms.date: 11/04/2016
f1_keywords:
- CBRS_SIZE_DYNAMIC
- CBRS_SIZE_FIXED
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
ms.openlocfilehash: 30113565167b96b0df84a65768a1dfabe92ceffe
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369770"
---
# <a name="docking-and-floating-toolbars"></a>Encaixando e flutuando barras de ferramentas

A Biblioteca de Classes da Microsoft Foundation suporta barras de ferramentas ancoráveis. Uma barra de ferramentas ancorável pode ser anexada, ou encaixada, a qualquer lado de sua janela pai, ou pode ser separada, ou flutuada, em sua própria janela de mini-quadros. Este artigo explica como usar barras de ferramentas ancoráveis em seus aplicativos.

Se você usar o Assistente de Aplicativo para gerar o esqueleto do seu aplicativo, você será convidado a escolher se deseja barras de ferramentas ancoráveis. Por padrão, o Assistente de Aplicativo gera o código que executa as três ações necessárias para colocar uma barra de ferramentas docada em seu aplicativo:

- [Habilite o encaixe em uma janela de quadro](#_core_enabling_docking_in_a_frame_window).

- [Habilite o encaixe para uma barra de ferramentas](#_core_enabling_docking_for_a_toolbar).

- [Encaixe a barra de ferramentas (para a janela do quadro)](#_core_docking_the_toolbar).

Se alguma dessas etapas estiver faltando, seu aplicativo exibirá uma barra de ferramentas padrão. As duas últimas etapas devem ser executadas para cada barra de ferramentas ancorável em sua aplicação.

Outros tópicos abordados neste artigo incluem:

- [Flutuando a barra de ferramentas](#_core_floating_the_toolbar)

- [Redimensionamento dinâmico da barra de ferramentas](#_core_dynamically_resizing_the_toolbar)

- [Definindo posições de envoltório para uma barra de ferramentas de estilo fixo](#_core_setting_wrap_positions_for_a_fixed_style_toolbar)

Consulte a amostra geral do MFC [DOCKTOOL,](../overview/visual-cpp-samples.md) por exemplo.

## <a name="enabling-docking-in-a-frame-window"></a><a name="_core_enabling_docking_in_a_frame_window"></a>Ativando o encaixe em uma janela de quadro

Para encaixar barras de ferramentas em uma janela de quadro, a janela do quadro (ou destino) deve ser habilitada para permitir o encaixe. Isso é feito usando a função [CFrameWnd::EnableDocking,](../mfc/reference/cframewnd-class.md#enabledocking) que leva um parâmetro *DWORD* que é um conjunto de bits de estilo indicando qual lado da janela do quadro aceita acoplamento. Se uma barra de ferramentas estiver prestes a ser encaixada e houver vários lados para os `EnableDocking` quais ela possa ser encaixada, os lados indicados no parâmetro passado são usados na seguinte ordem: superior, inferior, esquerdo, direito. Se você quiser ser capaz de acoplar `EnableDocking`barras de controle em qualquer lugar, passe **CBRS_ALIGN_ANY** para .

## <a name="enabling-docking-for-a-toolbar"></a><a name="_core_enabling_docking_for_a_toolbar"></a>Ativando o encaixe para uma barra de ferramentas

Depois de ter preparado o destino para atracar, você deve preparar a barra de ferramentas (ou fonte) de forma semelhante. Ligue para [CControlBar::EnableDocking](../mfc/reference/ccontrolbar-class.md#enabledocking) para cada barra de ferramentas desejando dock, especificando os lados de destino aos quais a barra de ferramentas deve acoplar. Se nenhum dos lados especificado `CControlBar::EnableDocking` na chamada corresponder aos lados habilitados para acoplar na janela do quadro, a barra de ferramentas não poderá acoplar — ela flutuará. Uma vez flutuado, ele permanece uma barra de ferramentas flutuante, incapaz de acoplar à janela do quadro.

Se o efeito que você deseja for `EnableDocking` uma barra de ferramentas permanentemente flutuante, ligue com um parâmetro de 0. Em seguida, ligue para [CFrameWnd::FloatControlBar](../mfc/reference/cframewnd-class.md#floatcontrolbar). A barra de ferramentas permanece flutuando, permanentemente incapaz de atracar em qualquer lugar.

## <a name="docking-the-toolbar"></a><a name="_core_docking_the_toolbar"></a>Acoplamento da barra de ferramentas

A estrutura chama [CFrameWnd::DockControlBar](../mfc/reference/cframewnd-class.md#dockcontrolbar) quando o usuário tenta soltar a barra de ferramentas em um lado da janela do quadro que permite o encaixe.

Além disso, você pode chamar esta função a qualquer momento para encaixar barras de controle na janela do quadro. Isso normalmente é feito durante a inicialização. Mais de uma barra de ferramentas pode ser encaixada em um lado específico da janela do quadro.

## <a name="floating-the-toolbar"></a><a name="_core_floating_the_toolbar"></a>Flutuando a barra de ferramentas

A retirada de uma barra de ferramentas ancorável da janela do quadro é chamada de barra de ferramentas flutuante. Ligue para [CFrameWnd::FloatControlBar](../mfc/reference/cframewnd-class.md#floatcontrolbar) para fazer isso. Especifique a barra de ferramentas a ser flutuada, o ponto onde deve ser colocada e um estilo de alinhamento que determina se a barra de ferramentas flutuante é horizontal ou vertical.

A estrutura chama essa função quando um usuário arrasta uma barra de ferramentas para fora de seu local ancorado e a descarta em um local onde o encaixe não está ativado. Isso pode estar em qualquer lugar dentro ou fora da janela da moldura. Como `DockControlBar`acontece, você também pode chamar essa função durante a inicialização.

A implementação de barras de ferramentas do MFC não fornece alguns dos recursos estendidos encontrados em alguns aplicativos que suportam barras de ferramentas ancoráveis. Recursos como barras de ferramentas personalizáveis não são fornecidos.

## <a name="dynamically-resizing-the-toolbar"></a><a name="_core_dynamically_resizing_the_toolbar"></a>Redimensionamento dinâmico da barra de ferramentas

A partir da versão 4.0 do Visual C++, você pode tornar possível que os usuários do seu aplicativo redimensionem as barras de ferramentas flutuantes dinamicamente. Normalmente, uma barra de ferramentas tem uma forma longa e linear, exibida horizontalmente. Mas você pode alterar a orientação da barra de ferramentas e sua forma. Por exemplo, quando o usuário encaixa uma barra de ferramentas contra um dos lados verticais da janela do quadro, a forma muda para um layout vertical. Também é possível remodelar a barra de ferramentas em um retângulo com várias linhas de botões.

Você pode:

- Especifique o dimensionamento dinâmico como uma característica da barra de ferramentas.

- Especifique o dimensionamento fixo como uma característica da barra de ferramentas.

Para fornecer esse suporte, existem dois novos estilos de barra de ferramentas para uso em suas chamadas para a função [CToolBar::Criar](../mfc/reference/ctoolbar-class.md#create) membro. Eles são:

- **CBRS_SIZE_DYNAMIC CBRS_SIZE_DYNAMIC.** A barra de controle é dinâmica.

- **CBRS_SIZE_FIXED.** A barra de controle está fixa.

O estilo dinâmico de tamanho permite que o usuário redimensione a barra de ferramentas enquanto ela estiver flutuando, mas não enquanto estiver ancorada. A barra de ferramentas "embrulha" onde é necessário mudar de forma à medida que o usuário arrasta suas bordas.

O tamanho do estilo fixo preserva os estados de envoltório de uma barra de ferramentas, fixando a posição dos botões em cada coluna. O usuário do aplicativo não pode alterar a forma da barra de ferramentas. A barra de ferramentas envolve em locais designados, como a localização de separadores entre os botões. Ele mantém esta forma se a barra de ferramentas está ancorada ou flutuando. O efeito é uma paleta fixa com várias colunas de botões.

Você também pode usar [CToolBar::GetButtonStyle](../mfc/reference/ctoolbar-class.md#getbuttonstyle) para retornar um estado e estilo para botões em suas barras de ferramentas. O estilo de um botão determina como o botão aparece e como ele responde à entrada do usuário; o estado diz se o botão está em um estado embrulhado.

## <a name="setting-wrap-positions-for-a-fixed-style-toolbar"></a><a name="_core_setting_wrap_positions_for_a_fixed_style_toolbar"></a>Definindo posições de envoltório para uma barra de ferramentas de estilo fixo

Para uma barra de ferramentas com o estilo fixo de tamanho, designe índices de botão da barra de ferramentas nos quais a barra de ferramentas será wrap. O código a seguir mostra como fazer isso `OnCreate` na substituição da janela do quadro principal:

[!code-cpp[NVC_MFCDocViewSDI#10](../mfc/codesnippet/cpp/docking-and-floating-toolbars_1.cpp)]

A amostra mfc geral [DOCKTOOL](../overview/visual-cpp-samples.md) mostra como usar funções de membros das classes [CControlBar](../mfc/reference/ccontrolbar-class.md) e [CToolBar](../mfc/reference/ctoolbar-class.md) para gerenciar o layout dinâmico de uma barra de ferramentas. Consulte o arquivo EDITBAR. CPP em DOCKTOOL.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Fundamentos da barra de ferramentas](../mfc/toolbar-fundamentals.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- [Usando suas barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)

## <a name="see-also"></a>Confira também

[Implementação da barra de ferramentas MFC](../mfc/mfc-toolbar-implementation.md)
