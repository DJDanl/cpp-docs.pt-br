---
title: 'Contêineres: Implementando um contêiner'
ms.date: 11/04/2016
helpviewer_keywords:
- applications [OLE], OLE container
- OLE containers [MFC], implementing
ms.assetid: af1e2079-619a-4eac-9327-985ad875823a
ms.openlocfilehash: b0d737a2025ed0006db00425d42c02ebf0bdeda8
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58767880"
---
# <a name="containers-implementing-a-container"></a>Contêineres: Implementando um contêiner

Este artigo resume o procedimento para a implementação de um contêiner e aponta para outros artigos que fornecem a que obter mais explicações sobre a implementação de contêineres. Ela também lista alguns recursos opcionais do OLE, que você talvez queira implementar e os artigos que descrevem esses recursos.

#### <a name="to-prepare-your-cwinapp-derived-class"></a>Para preparar a sua classe derivada de CWinApp

1. Inicializar as bibliotecas OLE chamando `AfxOleInit` no `InitInstance` função de membro.

1. Chame `CDocTemplate::SetContainerInfo` em `InitInstance` para atribuir o menu e o Acelerador de recursos usados quando um item inserido é ativado no local. Para obter mais informações sobre esse tópico, consulte [ativação](../mfc/activation-cpp.md).

Esses recursos são fornecidos para você automaticamente quando você usa o Assistente de aplicativo do MFC para criar um aplicativo de contêiner. Ver [criando um programa MFC EXE](../mfc/reference/mfc-application-wizard.md).

#### <a name="to-prepare-your-view-class"></a>Para preparar a sua classe de exibição

1. Manter o controle de itens selecionados, mantendo um ponteiro ou lista de ponteiros, se você oferecer suporte a seleção múltipla, para os itens selecionados. Seu `OnDraw` função deve desenhar todos os itens OLE.

1. Substituir `IsSelected` para verificar se o item passado para ele no momento está selecionado.

1. Implementar uma `OnInsertObject` manipulador de mensagem para exibir o **Inserir objeto** caixa de diálogo.

1. Implemente um `OnSetFocus` manipulador para transferir o foco do modo de exibição para do Active Directory OLE inseridos de item de mensagem.

1. Implemente um `OnSize` manipulador de mensagem para informar uma OLE inseridos item que ele precisa alterar seu retângulo para refletir a alteração no tamanho do modo de exibição que contém.

Como a implementação desses recursos varia significativamente de um aplicativo para o próximo, o Assistente de aplicativo fornece apenas uma implementação básica. Provavelmente, você precisará personalizar essas funções para que seu aplicativo funcione corretamente. Para obter um exemplo disso, consulte a [CONTÊINER](../overview/visual-cpp-samples.md) exemplo.

#### <a name="to-handle-embedded-and-linked-items"></a>Para lidar com itens vinculados e inseridos

1. Derive uma classe de [COleClientItem](../mfc/reference/coleclientitem-class.md). Objetos dessa classe representam os itens que foram inseridos no ou vinculados ao documento OLE.

1. Substituir `OnChange`, `OnChangeItemPosition`, e `OnGetItemPosition`. Essas funções tratam de dimensionamento, posicionamento e modificando os itens vinculados e inseridos.

O Assistente para aplicativo derivará a classe para você, mas você provavelmente precisará substituir `OnChange` e as outras funções são listadas com ele na etapa 2 do procedimento anterior. As implementações de esqueleto precisam ser personalizado para a maioria dos aplicativos, porque essas funções são implementadas de forma diferente de um aplicativo para o próximo. Para obter exemplos de isso, consulte os exemplos MFC [DRAWCLI](../overview/visual-cpp-samples.md) e [CONTÊINER](../overview/visual-cpp-samples.md).

Você deve adicionar um número de itens para a estrutura do menu do aplicativo de contêiner para dar suporte a OLE. Para obter mais informações sobre isso, consulte [Menus e recursos: Adições de contêiner](../mfc/menus-and-resources-container-additions.md).

Convém também oferecem suporte a alguns dos recursos a seguir em seu aplicativo de contêiner:

- Ativação in-loco ao editar um item inserido.

   Para obter mais informações, consulte [ativação](../mfc/activation-cpp.md).

- Criação de OLE itens arrastando e soltando uma seleção de um aplicativo de servidor.

   Para obter mais informações, consulte [arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md).

- Contém links para os objetos inseridos ou aplicativos de servidor/contêiner de combinação.

   Para obter mais informações, consulte [contêineres: Recursos avançados de](../mfc/containers-advanced-features.md).

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: Itens de cliente](../mfc/containers-client-items.md)
