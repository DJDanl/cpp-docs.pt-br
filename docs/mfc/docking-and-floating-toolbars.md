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
ms.openlocfilehash: f40d8860f2e514bf3c9e9364a664326250c9627a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615830"
---
# <a name="docking-and-floating-toolbars"></a>Encaixando e flutuando barras de ferramentas

O biblioteca MFC dá suporte a barras de ferramentas encaixáveis. Uma barra de ferramentas encaixáveis pode ser anexada ou encaixada a qualquer lado de sua janela pai, ou pode ser desanexada, ou flutuante, em sua própria janela de mini-quadro. Este artigo explica como usar as barras de ferramentas do encaixáveis em seus aplicativos.

Se você usar o assistente de aplicativo para gerar o esqueleto de seu aplicativo, será solicitado que você escolha se deseja encaixáveis barras de ferramentas. Por padrão, o assistente de aplicativo gera o código que executa as três ações necessárias para inserir uma barra de ferramentas encaixáveis em seu aplicativo:

- [Habilitar encaixe em uma janela do quadro](#_core_enabling_docking_in_a_frame_window).

- [Habilite o encaixe para uma barra de ferramentas](#_core_enabling_docking_for_a_toolbar).

- [Encaixe a barra de ferramentas (na janela do quadro)](#_core_docking_the_toolbar).

Se qualquer uma dessas etapas estiver ausente, seu aplicativo exibirá uma barra de ferramentas padrão. As duas últimas etapas devem ser executadas para cada barra de ferramentas encaixáveis em seu aplicativo.

Outros tópicos abordados neste artigo incluem:

- [Flutuando a barra de ferramentas](#_core_floating_the_toolbar)

- [Redimensionamento dinâmico da barra de ferramentas](#_core_dynamically_resizing_the_toolbar)

- [Configurando posições de quebra automática para uma barra de ferramentas de estilo fixo](#_core_setting_wrap_positions_for_a_fixed_style_toolbar)

Consulte o exemplo de [DOCKTOOL](../overview/visual-cpp-samples.md) geral do MFC para obter exemplos.

## <a name="enabling-docking-in-a-frame-window"></a><a name="_core_enabling_docking_in_a_frame_window"></a>Habilitando o encaixe em uma janela do quadro

Para encaixar barras de ferramentas em uma janela do quadro, a janela do quadro (ou destino) deve ser habilitada para permitir o encaixe. Isso é feito usando a função [CFrameWnd:: EnableDocking](reference/cframewnd-class.md#enabledocking) , que usa um parâmetro *DWORD* que é um conjunto de bits de estilo que indica qual lado da janela do quadro aceita encaixe. Se uma barra de ferramentas estiver prestes a ser encaixada e houver vários lados nos quais ela poderia ser encaixada, os lados indicados no parâmetro passado para `EnableDocking` serão usados na seguinte ordem: superior, inferior, esquerda, direita. Se você quiser ser capaz de encaixar barras de controle em qualquer lugar, passe **CBRS_ALIGN_ANY** para `EnableDocking` .

## <a name="enabling-docking-for-a-toolbar"></a><a name="_core_enabling_docking_for_a_toolbar"></a>Habilitando o encaixe para uma barra de ferramentas

Depois de preparar o destino para encaixe, você deve preparar a barra de ferramentas (ou origem) de maneira semelhante. Chame [CControlBar:: EnableDocking](reference/ccontrolbar-class.md#enabledocking) para cada barra de ferramentas que você deseja encaixar, especificando os lados de destino para os quais a barra de ferramentas deve se encaixar. Se nenhum dos lados especificados na chamada para corresponder aos `CControlBar::EnableDocking` lados habilitados para encaixe na janela do quadro, a barra de ferramentas não poderá encaixar – ele será flutuante. Depois que ele tiver sido flutuado, ele permanecerá como uma barra de ferramentas flutuante, não poderá ser encaixado na janela do quadro.

Se o efeito desejado for uma barra de ferramentas flutuante permanentemente, chame `EnableDocking` com um parâmetro de 0. Em seguida, chame [CFrameWnd:: FloatControlBar](reference/cframewnd-class.md#floatcontrolbar). A barra de ferramentas permanece flutuante, permanentemente não é possível encaixar em qualquer lugar.

## <a name="docking-the-toolbar"></a><a name="_core_docking_the_toolbar"></a>Encaixando a barra de ferramentas

A estrutura chama [CFrameWnd::D ockcontrolbar](reference/cframewnd-class.md#dockcontrolbar) quando o usuário tenta soltar a barra de ferramentas em um lado da janela do quadro que permite o encaixe.

Além disso, você pode chamar essa função a qualquer momento para encaixar barras de controle na janela do quadro. Isso normalmente é feito durante a inicialização. Mais de uma barra de ferramentas pode ser encaixada em um lado específico da janela do quadro.

## <a name="floating-the-toolbar"></a><a name="_core_floating_the_toolbar"></a>Flutuando a barra de ferramentas

Desanexar uma barra de ferramentas encaixáveis da janela do quadro é chamado de flutuar na barra de ferramentas. Chame [CFrameWnd:: FloatControlBar](reference/cframewnd-class.md#floatcontrolbar) para fazer isso. Especifique a barra de ferramentas a ser flutuante, o ponto em que deve ser colocado e um estilo de alinhamento que determina se a barra de ferramentas flutuante é horizontal ou vertical.

A estrutura chama essa função quando um usuário arrasta uma barra de ferramentas para fora de seu local encaixado e a descarta em um local onde o encaixe não está habilitado. Pode ser em qualquer lugar dentro ou fora da janela do quadro. Assim como acontece com `DockControlBar` o, você também pode chamar essa função durante a inicialização.

A implementação do MFC das barras de ferramentas do encaixáveis não fornece alguns dos recursos estendidos encontrados em alguns aplicativos que dão suporte a barras de ferramentas do encaixáveis. Recursos como barras de ferramentas personalizáveis não são fornecidos.

## <a name="dynamically-resizing-the-toolbar"></a><a name="_core_dynamically_resizing_the_toolbar"></a>Redimensionamento dinâmico da barra de ferramentas

A partir da versão Visual C++ 4,0, você pode possibilitar que os usuários do seu aplicativo redimensionem barras de ferramentas flutuantes dinamicamente. Normalmente, uma barra de ferramentas tem uma forma longa e linear, exibida horizontalmente. Mas você pode alterar a orientação da barra de ferramentas e sua forma. Por exemplo, quando o usuário encaixa uma barra de ferramentas em um dos lados verticais da janela do quadro, a forma muda para um layout vertical. Também é possível remodelar a barra de ferramentas em um retângulo com várias linhas de botões.

Você pode:

- Especifique o dimensionamento dinâmico como uma característica de barra de ferramentas.

- Especifique o dimensionamento fixo como uma característica de barra de ferramentas.

Para fornecer esse suporte, há dois novos estilos de barra de ferramentas para uso em suas chamadas para a função de membro [CToolBar:: Create](reference/ctoolbar-class.md#create) . Eles são:

- **CBRS_SIZE_DYNAMIC** A barra de controle é dinâmica.

- **CBRS_SIZE_FIXED** A barra de controle é fixa.

O estilo dinâmico de tamanho permite que o usuário redimensione a barra de ferramentas enquanto ela está flutuando, mas não enquanto está encaixada. A barra de ferramentas "encapsula", onde é necessário alterar a forma à medida que o usuário arrasta suas bordas.

O estilo fixo de tamanho preserva os Estados de encapsulamento de uma barra de ferramentas, corrigindo a posição dos botões em cada coluna. O usuário do aplicativo não pode alterar a forma da barra de ferramentas. A barra de ferramentas é encapsulada em locais designados, como os locais de separadores entre os botões. Ele mantém essa forma se a barra de ferramentas está encaixada ou flutuante. O efeito é uma paleta fixa com várias colunas de botões.

Você também pode usar [CToolBar:: GetButtonStyle](reference/ctoolbar-class.md#getbuttonstyle) para retornar um estado e um estilo para botões em suas barras de ferramentas. O estilo de um botão determina como o botão é exibido e como ele responde à entrada do usuário; o estado informa se o botão está em um estado delimitado.

## <a name="setting-wrap-positions-for-a-fixed-style-toolbar"></a><a name="_core_setting_wrap_positions_for_a_fixed_style_toolbar"></a>Configurando posições de quebra automática para uma barra de ferramentas de estilo fixo

Para uma barra de ferramentas com o estilo fixo tamanho, designe os índices de botão da barra de ferramentas na qual a barra de ferramentas será encapsulada. O código a seguir mostra como fazer isso na substituição da janela do quadro principal `OnCreate` :

[!code-cpp[NVC_MFCDocViewSDI#10](codesnippet/cpp/docking-and-floating-toolbars_1.cpp)]

O exemplo de [DOCKTOOL](../overview/visual-cpp-samples.md) geral do MFC mostra como usar funções de membro de classes [CControlBar](reference/ccontrolbar-class.md) e [CToolBar](reference/ctoolbar-class.md) para gerenciar o layout dinâmico de uma barra de ferramentas. Consulte o arquivo EDITBAR. CPP em DOCKTOOL.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Conceitos básicos da barra de ferramentas](toolbar-fundamentals.md)

- [Dicas de ferramenta da barra de ferramentas](toolbar-tool-tips.md)

- [Usando suas barras de ferramentas antigas](using-your-old-toolbars.md)

## <a name="see-also"></a>Consulte também

[Implementação da barra de ferramentas MFC](mfc-toolbar-implementation.md)
