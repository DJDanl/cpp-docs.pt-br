---
title: 'Contêineres: implementando um contêiner'
ms.date: 11/04/2016
helpviewer_keywords:
- applications [OLE], OLE container
- OLE containers [MFC], implementing
ms.assetid: af1e2079-619a-4eac-9327-985ad875823a
ms.openlocfilehash: ed95324b8df978a6ab2f7582c0ddf626a45e7fe1
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127914"
---
# <a name="containers-implementing-a-container"></a>Contêineres: implementando um contêiner

Este artigo resume o procedimento para implementar um contêiner e aponta para outros artigos que fornecem explicações mais detalhadas sobre a implementação de contêineres. Ele também lista alguns recursos OLE opcionais que talvez você queira implementar e os artigos que descrevem esses recursos.

#### <a name="to-prepare-your-cwinapp-derived-class"></a>Para preparar sua classe derivada de CWinApp

1. Inicialize as bibliotecas OLE chamando `AfxOleInit` na função de membro `InitInstance`.

1. Chame `CDocTemplate::SetContainerInfo` no `InitInstance` para atribuir os recursos de menu e acelerador usados quando um item incorporado é ativado no local. Para obter mais informações sobre este tópico, consulte [ativação](../mfc/activation-cpp.md).

Esses recursos são fornecidos automaticamente quando você usa o assistente de aplicativo MFC para criar um aplicativo de contêiner. Consulte [criando um programa exe do MFC](../mfc/reference/mfc-application-wizard.md).

#### <a name="to-prepare-your-view-class"></a>Para preparar sua classe de exibição

1. Mantenha o controle dos itens selecionados mantendo um ponteiro ou uma lista de ponteiros se você der suporte à seleção múltipla para os itens selecionados. Sua função `OnDraw` deve desenhar todos os itens OLE.

1. Substitua `IsSelected` para verificar se o item passado para ele está selecionado no momento.

1. Implemente um manipulador de mensagens `OnInsertObject` para exibir a caixa de diálogo **Inserir objeto** .

1. Implemente um manipulador de mensagens `OnSetFocus` para transferir o foco da exibição para um item OLE incorporado ativo no local.

1. Implemente um manipulador de mensagens `OnSize` para informar um item OLE incorporado que precisa alterar seu retângulo para refletir a alteração no tamanho da exibição que o contém.

Como a implementação desses recursos varia drasticamente de um aplicativo para o outro, o assistente de aplicativo fornece apenas uma implementação básica. Provavelmente, você precisará personalizar essas funções para que seu aplicativo funcione corretamente. Para obter um exemplo disso, consulte o exemplo de [contêiner](../overview/visual-cpp-samples.md) .

#### <a name="to-handle-embedded-and-linked-items"></a>Para lidar com itens incorporados e vinculados

1. Derive uma classe de [COleClientItem](../mfc/reference/coleclientitem-class.md). Os objetos dessa classe representam os itens que foram inseridos ou vinculados ao seu documento OLE.

1. Substituir `OnChange`, `OnChangeItemPosition`e `OnGetItemPosition`. Essas funções lidam com o dimensionamento, o posicionamento e a modificação de itens incorporados e vinculados.

O assistente de aplicativo derivará a classe para você, mas provavelmente será necessário substituir `OnChange` e as outras funções listadas com ele na etapa 2 no procedimento anterior. As implementações de esqueleto precisam ser personalizadas para a maioria dos aplicativos, pois essas funções são implementadas de forma diferente de um aplicativo para o outro. Para obter exemplos disso, consulte os exemplos de MFC [DRAWCLI](../overview/visual-cpp-samples.md) e [container](../overview/visual-cpp-samples.md).

Você deve adicionar um número de itens à estrutura de menu do aplicativo de contêiner para dar suporte ao OLE. Para obter mais informações sobre eles, consulte [menus e recursos: adições de contêiner](../mfc/menus-and-resources-container-additions.md).

Talvez você também queira dar suporte a alguns dos seguintes recursos em seu aplicativo de contêiner:

- Ativação in-loco ao editar um item inserido.

   Para obter mais informações, consulte [ativação](../mfc/activation-cpp.md).

- Criação de itens OLE arrastando e soltando uma seleção de um aplicativo de servidor.

   Para obter mais informações, consulte [arrastar e soltar OLE](../mfc/drag-and-drop-ole.md).

- Links para objetos inseridos ou aplicativos de contêiner/servidor de combinação.

   Para obter mais informações, consulte [contêineres: recursos avançados](../mfc/containers-advanced-features.md).

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: itens clientes](../mfc/containers-client-items.md)
