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
ms.openlocfilehash: ef79fc88604d565a942fdb0ae07d5fc5a2e0ebeb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509005"
---
# <a name="changing-the-styles-of-a-window-created-by-mfc"></a>Alternando os estilos de uma janela criada por MFC

Em sua versão da função `WinMain` , o MFC registra várias classes de janela padrão para você. Como você não edita normalmente o MFC `WinMain`, essa função não oferece nenhuma oportunidade de alterar os estilos de janela padrão do MFC. Este artigo explica como você pode alterar os estilos de tal classe de janela preregistered em um aplicativo existente.

##  <a name="_core_changing_styles_in_a_new_mfc_application"></a>Alterando estilos em um novo aplicativo MFC

Se você estiver usando o C++ Visual 2,0 ou posterior, poderá alterar os estilos de janela padrão no assistente de aplicativo ao criar seu aplicativo. Na página recursos de interface do usuário do assistente de aplicativo, você pode alterar os estilos da janela principal do quadro e do Windows filho MDI. Para qualquer tipo de janela, você pode especificar sua espessura de quadro (espessa ou fina) e qualquer um dos seguintes:

- Se a janela tem os controles minimizar ou maximizar.

- Se a janela aparece inicialmente minimizada, maximizada ou nenhuma.

Para janelas de quadros principais, você também pode especificar se a janela tem um menu do sistema. Para janelas filho MDI, você pode especificar se a janela oferece suporte a painéis de divisão.

##  <a name="_core_changing_styles_in_an_existing_application"></a>Alterando estilos em um aplicativo existente

Se você estiver alterando atributos de janela em um aplicativo existente, siga as instruções no restante deste artigo em vez disso.

Para alterar os atributos de janela padrão usados por um aplicativo de estrutura criado com o assistente de aplicativo, substitua a função de membro virtual [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) da janela. `PreCreateWindow`permite que um aplicativo acesse o processo de criação normalmente gerenciado internamente pela classe [CDocTemplate](../mfc/reference/cdoctemplate-class.md) . A estrutura chama `PreCreateWindow` -se logo antes da criação da janela. Ao modificar a estrutura [CREATESTRUCT](/windows/win32/api/winuser/ns-winuser-createstructw) passada para `PreCreateWindow`, seu aplicativo pode alterar os atributos usados para criar a janela. Por exemplo, para garantir que uma janela não use uma legenda, use a operação bit a seguir:

[!code-cpp[NVC_MFCDocView#15](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_1.cpp)]

O aplicativo de exemplo [CTRLBARS](../overview/visual-cpp-samples.md) demonstra essa técnica para alterar atributos de janela. Dependendo do que o aplicativo altera `PreCreateWindow`, pode ser necessário chamar a implementação da classe base da função.

A discussão a seguir aborda o caso de SDI e o [caso MDI](#_core_the_mdi_case).

##  <a name="_core_the_sdi_case"></a>O caso de SDI

Em um aplicativo SDI (interface de documento único), o estilo de janela padrão na estrutura é uma combinação dos estilos **WS_OVERLAPPEDWINDOW** e **FWS_ADDTOTITLE** . **FWS_ADDTOTITLE** é um estilo específico do MFC que instrui a estrutura a adicionar o título do documento à legenda da janela. Para alterar os atributos de janela em um aplicativo SDI, substitua `PreCreateWindow` a função na classe derivada de `CFrameWnd` (que o assistente de aplicativo `CMainFrame`nomeia). Por exemplo:

[!code-cpp[NVC_MFCDocViewSDI#11](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_2.cpp)]

Esse código cria uma janela de quadro principal sem minimizar e maximizar os botões e sem uma borda ajustável. A janela é inicialmente centralizada na tela.

##  <a name="_core_the_mdi_case"></a>O caso MDI

Um pouco mais de trabalho é necessário para alterar o estilo de janela de uma janela filho em um aplicativo de interface de vários documentos (MDI). Por padrão, um aplicativo MDI criado com o assistente de aplicativo usa a classe [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) padrão definida no MFC. Para alterar o estilo de janela de uma janela filho MDI, você deve derivar uma nova `CMDIChildWnd` classe de e substituir todas `CMDIChildWnd` as referências a em seu projeto por referências à nova classe. Provavelmente, a única referência a `CMDIChildWnd` no aplicativo está localizada na função de membro do `InitInstance` seu aplicativo.

O estilo de janela padrão usado em um aplicativo MDI é uma combinação dos estilos **WS_CHILD**, **WS_OVERLAPPEDWINDOW**e **FWS_ADDTOTITLE** . Para alterar os atributos de janela das janelas filho de um aplicativo MDI, substitua a função [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) em sua classe derivada `CMDIChildWnd`de. Por exemplo:

[!code-cpp[NVC_MFCDocView#16](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_3.cpp)]

Esse código cria janelas filho MDI sem um botão de maximização.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Estilos do Windows](../mfc/reference/styles-used-by-mfc.md#window-styles)

- [Estilos de janela de quadro](../mfc/frame-window-styles-cpp.md)

- [Estilos de janela](/windows/win32/winmsg/window-styles)

## <a name="see-also"></a>Consulte também

[Estilos de janela de quadro](../mfc/frame-window-styles-cpp.md)
