---
title: Alternando os estilos de uma janela criada por MFC
ms.date: 11/04/2016
helpviewer_keywords:
- window styles [MFC]
- WS_OVERLAPPEDWINDOW macro [MFC]
- single document interface (SDI), changing window attributes
- MDI [MFC], window styles
- windows [MFC], MFC
- child windows [MFC], styles
- MFC, windows
- CFrameWnd class [MFC], window styles
- CREATESTRUCT macro [MFC]
- CMDIChildWnd class [MFC], changing window styles
- multidocument interface style
- PreCreateWindow method [MFC], window styles
- single document interface (SDI), style
- default window style
- defaults [MFC], window style
- PreCreateWindow method [MFC], changing window styles
- CMainFrame class [MFC]
- styles [MFC], windows
ms.assetid: 77fa4f03-96b4-4687-9ade-41e46f7e4b0a
ms.openlocfilehash: c8a3a5d9b8b007887dfb31f7459c0269377b38fd
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57294155"
---
# <a name="changing-the-styles-of-a-window-created-by-mfc"></a>Alternando os estilos de uma janela criada por MFC

Em sua versão dos `WinMain` função, o MFC registra várias classes de janela padrão para você. Como você normalmente não os edite do MFC `WinMain`, que função não permite que você nenhuma oportunidade de alterar os estilos de janela padrão MFC. Este artigo explica como você pode alterar os estilos de uma classe de janela previamente em um aplicativo existente.

##  <a name="_core_changing_styles_in_a_new_mfc_application"></a> Alterando estilos em um novo aplicativo do MFC

Se você estiver usando o Visual C++ 2.0 ou posterior, você pode alterar os estilos de janela padrão no Assistente do aplicativo quando você cria seu aplicativo. Na página de recursos de Interface do usuário do Assistente de aplicativo, você pode alterar os estilos de sua janela de quadro principal e janelas filho MDI. Para qualquer tipo de janela, você pode especificar sua espessura do quadro (grossa ou fina) e qualquer um dos seguintes:

- Se a janela tiver controles minimizar ou maximizar.

- Se a janela é exibida inicialmente minimizada, maximizada, ou nenhum.

Para janelas de quadro principal, você também pode especificar se a janela tem um Menu de sistema. Para janelas filho MDI, você pode especificar se a janela dá suporte a painéis de divisor.

##  <a name="_core_changing_styles_in_an_existing_application"></a> Alterando estilos em um aplicativo existente

Se você estiver alterando atributos de janela em um aplicativo existente, siga as instruções no restante deste artigo, em vez disso.

Para alterar os atributos de janela padrão usados por um aplicativo de framework criado com o Assistente de aplicativo, substitua a janela [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) função membro virtual. `PreCreateWindow` permite que um aplicativo acessar o processo de criação normalmente gerenciado internamente pelo [CDocTemplate](../mfc/reference/cdoctemplate-class.md) classe. A estrutura chama `PreCreateWindow` antes de criar a janela. Modificando o [CREATESTRUCT](/windows/desktop/api/winuser/ns-winuser-tagcreatestructa) estrutura passada para `PreCreateWindow`, seu aplicativo pode alterar os atributos usados para criar a janela. Por exemplo, para garantir que uma janela não usa uma legenda, use a seguinte operação bit a bit:

[!code-cpp[NVC_MFCDocView#15](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_1.cpp)]

O [CTRLBARS](../visual-cpp-samples.md) aplicativo de exemplo demonstra essa técnica para alterar os atributos de janela. Dependendo de quais alterações a seu aplicativo no `PreCreateWindow`, talvez seja necessário chamar a implementação da classe base da função.

A discussão a seguir aborda o caso de SDI e o [caso MDI](#_core_the_mdi_case).

##  <a name="_core_the_sdi_case"></a> O caso de SDI

Em um aplicativo de interface (SDI) único documento, o estilo de janela padrão do Framework é uma combinação da **WS_OVERLAPPEDWINDOW** e **FWS_ADDTOTITLE** estilos. **FWS_ADDTOTITLE** é um estilo específico do MFC que instrui a estrutura para adicionar o título do documento para a legenda da janela. Para alterar os atributos de janela em um aplicativo SDI, substitua os `PreCreateWindow` função em sua classe derivada de `CFrameWnd` (que os nomes do Assistente para aplicativo `CMainFrame`). Por exemplo:

[!code-cpp[NVC_MFCDocViewSDI#11](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_2.cpp)]

Esse código cria uma janela de quadro principal sem botões minimizar e maximizar e sem uma borda dimensionável. Inicialmente, a janela é centralizada na tela.

##  <a name="_core_the_mdi_case"></a> O caso MDI

Um pouco mais de trabalho é necessária para alterar o estilo da janela de uma janela filho em um aplicativo de interface MDI vários documentos. Por padrão, um aplicativo MDI criado com o Assistente de aplicativo usa o padrão [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) classe definida no MFC. Para alterar o estilo da janela de uma janela filho MDI, você deve derivar uma nova classe de `CMDIChildWnd` e substitua todas as referências a `CMDIChildWnd` em seu projeto com referências para a nova classe. Provavelmente, a única referência a `CMDIChildWnd` no aplicativo está localizado em seu aplicativo `InitInstance` função de membro.

O estilo de janela padrão usado em um aplicativo MDI é uma combinação da **WS_CHILD**, **WS_OVERLAPPEDWINDOW**, e **FWS_ADDTOTITLE** estilos. Para alterar os atributos de janela de janelas filho de um aplicativo MDI, substitua os [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) função em sua classe derivada de `CMDIChildWnd`. Por exemplo:

[!code-cpp[NVC_MFCDocView#16](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_3.cpp)]

Esse código cria o filho MDI janelas sem um botão maximizar.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Estilos do Windows](../mfc/reference/styles-used-by-mfc.md#window-styles)

- [Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)

- [Estilos de janela](/windows/desktop/winmsg/window-styles)

## <a name="see-also"></a>Consulte também

[Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)
