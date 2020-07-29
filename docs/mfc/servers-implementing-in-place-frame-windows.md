---
title: 'Servidores: implementando janelas de quadro in-loco'
ms.date: 09/09/2019
helpviewer_keywords:
- frame windows [MFC], implementing
- OLE server applications [MFC], frame windows
- servers, in-place frame windows
- frame windows [MFC], in-place
- in-place frame windows
ms.assetid: 09bde4d8-15e2-4fba-8d14-9b954d926b92
ms.openlocfilehash: a082afe141a21e4175886f13a26043694ac0d426
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230461"
---
# <a name="servers-implementing-in-place-frame-windows"></a>Servidores: implementando janelas de quadro in-loco

Este artigo explica o que você deve fazer para implementar janelas de quadros in-loco em seu aplicativo de servidor de edição visual se você não usar o assistente de aplicativo para criar seu aplicativo de servidor. Em vez de seguir o procedimento descrito neste artigo, você pode usar uma classe de janela de quadro in-loco existente por meio de um aplicativo gerado pelo assistente de aplicativo ou um exemplo fornecido com Visual C++.

#### <a name="to-declare-an-in-place-frame-window-class"></a>Para declarar uma classe de janela de quadro no local

1. Derive uma classe de janela de quadro no local de `COleIPFrameWnd` .

   - Use a macro DECLARE_DYNCREATE em seu arquivo de cabeçalho de classe.

   - Use a macro IMPLEMENT_DYNCREATE em seu arquivo de implementação de classe (. cpp). Isso permite que os objetos dessa classe sejam criados pela estrutura.

1. Declare um `COleResizeBar` membro na classe quadro-janela. Isso será necessário se você quiser dar suporte ao redimensionamento in-loco em aplicativos de servidor.

   Declare um `OnCreate` manipulador de mensagens (usando o [Assistente de classe](reference/mfc-class-wizard.md)) e chame `Create` seu `COleResizeBar` membro, se você o tiver definido.

1. Se você tiver uma barra de ferramentas, declare um `CToolBar` membro na classe quadro-janela.

   Substitua a `OnCreateControlBars` função de membro para criar uma barra de ferramentas quando o servidor estiver ativo no local. Por exemplo:

   [!code-cpp[NVC_MFCOleServer#1](../mfc/codesnippet/cpp/servers-implementing-in-place-frame-windows_1.cpp)]

   Consulte a discussão deste código seguindo a etapa 5.

1. Inclua o arquivo de cabeçalho para essa classe de janela de quadro in-loco em seu arquivo. cpp principal.

1. Em `InitInstance` para sua classe de aplicativo, chame a `SetServerInfo` função do objeto de modelo de documento para especificar os recursos e a janela de quadro in-loco a serem usados na edição aberta e in-loco.

A série de chamadas de função na **`if`** instrução cria a barra de ferramentas a partir dos recursos fornecidos pelo servidor. Neste ponto, a barra de ferramentas faz parte da hierarquia da janela do contêiner. Como essa barra de ferramentas é derivada de `CToolBar` , ela passará suas mensagens para seu proprietário, a janela do quadro do aplicativo de contêiner, a menos que você altere o proprietário. É por isso que a chamada para `SetOwner` é necessária. Essa chamada altera a janela onde os comandos são enviados para serem a janela do quadro in-loco do servidor, fazendo com que as mensagens sejam passadas para o servidor. Isso permite que o servidor reaja a operações na barra de ferramentas que ele fornece.

A ID do bitmap da barra de ferramentas deve ser a mesma que os outros recursos in-loco definidos no aplicativo do servidor. Consulte [menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md) para obter detalhes.

Para obter mais informações, consulte [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md), [COleResizeBar](../mfc/reference/coleresizebar-class.md)e [CDocTemplate:: SetServerInfo](../mfc/reference/cdoctemplate-class.md#setserverinfo) na referência da *biblioteca de classes*.

## <a name="see-also"></a>Confira também

[Servidores](../mfc/servers.md)<br/>
[Servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md)<br/>
[Servidores: implementando documentos de servidor](../mfc/servers-implementing-server-documents.md)<br/>
[Servidores: itens de servidor](../mfc/servers-server-items.md)
