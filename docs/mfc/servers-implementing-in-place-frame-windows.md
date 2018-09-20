---
title: 'Servidores: Implementando o Windows de quadro in-loco | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- frame windows [MFC], implementing
- OLE server applications [MFC], frame windows
- servers, in-place frame windows
- frame windows [MFC], in-place
- in-place frame windows
ms.assetid: 09bde4d8-15e2-4fba-8d14-9b954d926b92
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 24c63c10feff624abe399952b682303a6e262d35
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46425005"
---
# <a name="servers-implementing-in-place-frame-windows"></a>Servidores: implementando janelas de quadro in-loco

Este artigo explica o que você deve fazer para implementar janelas com moldura no local em seu aplicativo de servidor de edição visual se você não usar o Assistente de aplicativo para criar seu aplicativo de servidor. Em vez de seguir o procedimento descrito neste artigo, você pode usar uma classe de janela com moldura no local existente de um aplicativo gerado pelo Assistente de aplicativo ou um exemplo fornecido com o Visual C++.

#### <a name="to-declare-an-in-place-frame-window-class"></a>Para declarar uma classe de janela de quadro in-loco

1. Derivar uma classe de janela com moldura no local de `COleIPFrameWnd`.

   - Use a macro DECLARE_DYNCREATE em seu arquivo de cabeçalho de classe.

   - Use a macro IMPLEMENT_DYNCREATE em seu arquivo de implementação (. cpp) de classe. Isso permite que os objetos dessa classe a ser criado pela estrutura.

1. Declarar um `COleResizeBar` membro na classe de janela do quadro. Isso é necessário se você quiser dar suporte a redimensionamento in-loco em aplicativos de servidor.

     Declarar uma `OnCreate` manipulador de mensagens (usando o **propriedades** janela) e chame `Create` para sua `COleResizeBar` membro, se você defini-lo.

1. Se você tiver uma barra de ferramentas, declare um `CToolBar` membro na classe de janela do quadro.

     Substituir o `OnCreateControlBars` a função de membro para criar uma barra de ferramentas quando o servidor está ativo em vigor. Por exemplo:

     [!code-cpp[NVC_MFCOleServer#1](../mfc/codesnippet/cpp/servers-implementing-in-place-frame-windows_1.cpp)]

     Consulte a discussão sobre esse código seguindo a etapa 5.

1. Inclua o arquivo de cabeçalho para essa classe de janela com moldura no local em seu arquivo. cpp principal.

1. Na `InitInstance` para sua classe de aplicativo, chame o `SetServerInfo` função do objeto de modelo de documento para especificar os recursos e a janela do quadro no local a ser usado no modo de edição aberta e no local.

A série de função chama o **se** instrução cria a barra de ferramentas nos recursos do servidor fornecido. Neste ponto, a barra de ferramentas é parte da hierarquia de janela do contêiner. Porque essa barra de ferramentas é derivada de `CToolBar`, ela passará suas mensagens ao seu proprietário, a janela do quadro do aplicativo de contêiner, a menos que você altere o proprietário. É por isso que a chamada para `SetOwner` é necessário. Essa chamada muda a janela em que os comandos são enviados para ser a janela de quadro no local do servidor, fazendo com que as mensagens a serem passados para o servidor. Isso permite que o servidor reagir às operações na barra de ferramentas que ele oferece.

A ID para o bitmap de barra de ferramentas deve ser o mesmo que os outros recursos no local definidos no seu aplicativo de servidor. Ver [Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md) para obter detalhes.

Para obter mais informações, consulte [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md), [COleResizeBar](../mfc/reference/coleresizebar-class.md), e [CDocTemplate::SetServerInfo](../mfc/reference/cdoctemplate-class.md#setserverinfo) no *referência da biblioteca de classe*.

## <a name="see-also"></a>Consulte também

[Servidores](../mfc/servers.md)<br/>
[Servidores: implementando um servidor](../mfc/servers-implementing-a-server.md)<br/>
[Servidores: implementando documentos de servidor](../mfc/servers-implementing-server-documents.md)<br/>
[Servidores: itens de servidor](../mfc/servers-server-items.md)

