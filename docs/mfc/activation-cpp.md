---
title: Ativação (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- OLE server applications [MFC], activation
- OLE items [MFC], visual editing
- activation [MFC]
- OLE [MFC], in-place activation
- OLE [MFC], activation
- in-place activation, embedded and linked items
- activating objects
- visual editing, activation
- visual editing
- documents [MFC], OLE
- embedded objects [MFC]
- OLE [MFC], editing
- in-place activation
- activation [MFC], embedded OLE items
- OLE activation [MFC]
ms.assetid: ed8357d9-e487-4aaa-aa6b-2edc4de25dfa
ms.openlocfilehash: 47640a59180348bd3513013b65029a775545e211
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619178"
---
# <a name="activation-c"></a>Ativação (C++)

Este artigo explica a função de ativação na edição visual de itens OLE. Depois que um usuário tiver inserido um item OLE em um documento de contêiner, talvez seja necessário usá-lo. Para fazer isso, o usuário clica duas vezes no item, que ativa esse item. A atividade mais frequente para a ativação é edição. Muitos itens OLE atuais, quando ativados para edição, fazem com que os menus e barras de ferramentas na janela do quadro atual sejam alterados para refletir aqueles que pertencem ao aplicativo de servidor que criou o item. Esse comportamento, conhecido como ativação in-loco, permite que o usuário edite qualquer item inserido em um documento composto sem sair da janela do documento do contêiner.

Também é possível editar itens OLE incorporados em uma janela separada. Isso ocorrerá se o aplicativo de contêiner ou de servidor não oferecer suporte à ativação in-loco. Nesse caso, quando o usuário clica duas vezes em um item inserido, o aplicativo de servidor é iniciado em uma janela separada e o item inserido aparece como seu próprio documento. O usuário edita o item nesta janela. Quando a edição é concluída, o usuário fecha o aplicativo de servidor e retorna para o aplicativo de contêiner.

Como alternativa, o usuário pode escolher "abrir edição" com o comando ** \<object> abrir** no menu **Editar** . Isso abre o objeto em uma janela separada.

> [!NOTE]
> A edição de itens incorporados em uma janela separada era o comportamento padrão na versão 1 do OLE, e alguns aplicativos OLE podem dar suporte apenas a esse estilo de edição.

A ativação in-loco promove uma abordagem centrada em documentos à criação de documentos. O usuário pode tratar um documento composto como uma única entidade, trabalhando nele sem alternar entre aplicativos. No entanto, a ativação in-loco é usada somente para itens inseridos, não para itens vinculados: eles devem ser editados em uma janela separada. Isso ocorre porque um item vinculado é realmente armazenado em um local diferente. A edição de um item vinculado ocorre no contexto real dos dados, ou seja, onde os dados são armazenados. A edição de um item vinculado em uma janela separada lembra o usuário de que os dados pertencem a outro documento.

O MFC não dá suporte à ativação in-loco aninhada. Se você criar um aplicativo de contêiner/servidor e esse contêiner/servidor estiver inserido em outro contêiner e ativado no local, ele não poderá ativar objetos de ativação in-loco incorporados dentro dele.

O que acontece com um item incorporado quando o usuário clica duas vezes nele depende dos verbos definidos para o item. Para obter informações, consulte [ativação: verbos](activation-verbs.md).

## <a name="see-also"></a>Consulte também

[OLE](ole-in-mfc.md)<br/>
[Contêineres](containers.md)<br/>
[Servidores](servers.md)
