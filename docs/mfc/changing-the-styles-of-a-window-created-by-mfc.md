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
ms.openlocfilehash: 221092eb25a4f044cda5b379d6774659d9e9d2d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374589"
---
# <a name="changing-the-styles-of-a-window-created-by-mfc"></a>Alternando os estilos de uma janela criada por MFC

Em sua versão `WinMain` da função, o MFC registra várias classes de janela padrão para você. Como você normalmente não edita `WinMain`MFC's, essa função não lhe dá oportunidade de alterar os estilos de janela padrão do MFC. Este artigo explica como você pode alterar os estilos de uma classe de janela pré-registrada em um aplicativo existente.

## <a name="changing-styles-in-a-new-mfc-application"></a><a name="_core_changing_styles_in_a_new_mfc_application"></a>Mudando estilos em um novo aplicativo MFC

Se você estiver usando o Visual C++ 2.0 ou posterior, você pode alterar os estilos de janela padrão no Assistente de aplicativo ao criar seu aplicativo. Na página Recursos de interface de usuário do Assistente de aplicativo, você pode alterar estilos para a janela principal do quadro e janelas de crianças MDI. Para qualquer tipo de janela, você pode especificar a espessura do quadro (grosso ou fino) e qualquer um dos seguintes:

- Se a janela tem controles Minimizar ou Maximizar.

- Se a janela aparece inicialmente minimizada, maximizada ou nenhuma delas.

Para janelas de quadro principal, você também pode especificar se a janela tem um menu do sistema. Para janelas de crianças MDI, você pode especificar se a janela suporta painéis divisores.

## <a name="changing-styles-in-an-existing-application"></a><a name="_core_changing_styles_in_an_existing_application"></a>Alterando estilos em um aplicativo existente

Se você estiver alterando os atributos da janela em um aplicativo existente, siga as instruções no resto deste artigo.

Para alterar os atributos de janela padrão usados por um aplicativo de framework criado com o Assistente de Aplicativo, altere a função de membro virtual [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) da janela. `PreCreateWindow`permite que um aplicativo acesse o processo de criação normalmente gerenciado internamente pela classe [CDocTemplate.](../mfc/reference/cdoctemplate-class.md) A estrutura `PreCreateWindow` chama pouco antes de criar a janela. Ao modificar a estrutura [CRIATRUCT](/windows/win32/api/winuser/ns-winuser-createstructw) passada para `PreCreateWindow`, seu aplicativo pode alterar os atributos usados para criar a janela. Por exemplo, para garantir que uma janela não use uma legenda, use a seguinte operação bitwise:

[!code-cpp[NVC_MFCDocView#15](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_1.cpp)]

A aplicação da amostra [CTRLBARS](../overview/visual-cpp-samples.md) demonstra essa técnica para alterar os atributos da janela. Dependendo do que seu `PreCreateWindow`aplicativo muda, pode ser necessário chamar a implementação da classe base da função.

A discussão a seguir abrange o caso SDI e o [caso DoM.](#_core_the_mdi_case)

## <a name="the-sdi-case"></a><a name="_core_the_sdi_case"></a>O caso SDI

Em um único aplicativo de interface de documento (SDI), o estilo de janela padrão na estrutura é uma combinação dos estilos **WS_OVERLAPPEDWINDOW** e **FWS_ADDTOTITLE.** **FWS_ADDTOTITLE** é um estilo específico do MFC que instrui a estrutura a adicionar o título do documento à legenda da janela. Para alterar os atributos da janela em `PreCreateWindow` um aplicativo SDI, altere a função em sua classe derivada (da qual o Assistente de `CFrameWnd` Aplicativo nomeia `CMainFrame`). Por exemplo:

[!code-cpp[NVC_MFCDocViewSDI#11](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_2.cpp)]

Este código cria uma janela de quadro principal sem minimizar e maximizar botões e sem uma borda considerável. A janela está inicialmente centrada na tela.

## <a name="the-mdi-case"></a><a name="_core_the_mdi_case"></a>O Caso MDI

Um pouco mais de trabalho é necessário para alterar o estilo de janela de uma janela filho em um aplicativo de interface de documento múltiplo (MDI). Por padrão, um aplicativo MDI criado com o Assistente de Aplicativo usa a classe [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) padrão definida no MFC. Para alterar o estilo de janela de uma janela de `CMDIChildWnd` criança MDI, `CMDIChildWnd` você deve derivar uma nova classe e substituir todas as referências ao seu projeto por referências à nova classe. Provavelmente, a única `CMDIChildWnd` referência no aplicativo está localizada `InitInstance` na função de membro do aplicativo.

O estilo de janela padrão usado em um aplicativo MDI é uma combinação dos estilos **WS_CHILD,** **WS_OVERLAPPEDWINDOW**e **FWS_ADDTOTITLE.** Para alterar os atributos de janela das janelas de filho de um aplicativo MDI, anule a função [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) em sua classe derivada de `CMDIChildWnd`. Por exemplo:

[!code-cpp[NVC_MFCDocView#16](../mfc/codesnippet/cpp/changing-the-styles-of-a-window-created-by-mfc_3.cpp)]

Este código cria janelas de crianças MDI sem um botão Maximizar.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Estilos de Windows](../mfc/reference/styles-used-by-mfc.md#window-styles)

- [Estilos de janela de quadros](../mfc/frame-window-styles-cpp.md)

- [Estilos de janela](/windows/win32/winmsg/window-styles)

## <a name="see-also"></a>Confira também

[Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)
