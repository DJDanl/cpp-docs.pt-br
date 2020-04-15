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
ms.openlocfilehash: 9f3fba71002a19a0be0e3429a0faeeefb7c65197
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354176"
---
# <a name="activation-c"></a>Ativação (C++)

Este artigo explica o papel da ativação na edição visual dos itens OLE. Depois que um usuário tiver incorporado um item OLE em um documento de contêiner, ele pode precisar ser usado. Para isso, o usuário clica duas vezes no item, que ativa esse item. A atividade mais freqüente para ativação é a edição. Muitos itens OLE atuais, quando ativados para edição, fazem com que os menus e barras de ferramentas na janela atual do quadro mudem para refletir aqueles pertencentes ao aplicativo de servidor que criou o item. Esse comportamento, conhecido como ativação no local, permite que o usuário edite qualquer item incorporado em um documento composto sem sair da janela do documento do contêiner.

Também é possível editar itens OLE incorporados em uma janela separada. Isso acontecerá se o aplicativo de contêiner ou servidor não suportar a ativação no local. Neste caso, quando o usuário clica duas vezes em um item incorporado, o aplicativo do servidor é iniciado em uma janela separada e o item incorporado aparece como seu próprio documento. O usuário emite o item nesta janela. Quando a edição é concluída, o usuário fecha o aplicativo do servidor e retorna ao aplicativo de contêiner.

Como alternativa, o usuário pode escolher "editar ** \<** aberta" com o objeto> comando Abrir no menu **Editar.** Isso abre o objeto em uma janela separada.

> [!NOTE]
> Editar itens incorporados em uma janela separada foi um comportamento padrão na versão 1 do OLE, e alguns aplicativos OLE podem suportar apenas esse estilo de edição.

A ativação no local promove uma abordagem centrada em documentos para a criação de documentos. O usuário pode tratar um documento composto como uma única entidade, trabalhando nele sem alternar entre aplicativos. No entanto, a ativação no local é usada apenas para itens incorporados, não para itens vinculados: eles devem ser editados em uma janela separada. Isso ocorre porque um item vinculado é realmente armazenado em um lugar diferente. A edição de um item vinculado ocorre dentro do contexto real dos dados, ou seja, onde os dados são armazenados. Editar um item vinculado em uma janela separada lembra ao usuário que os dados pertencem a outro documento.

O MFC não suporta ativação aninhada no local. Se você criar um aplicativo de contêiner/servidor e esse contêiner/servidor estiver incorporado em outro contêiner e ativado no local, ele não poderá ativar objetos incorporados nele.

O que acontece com um item incorporado quando o usuário clica duas vezes depende dos verbos definidos para o item. Para obter informações, consulte [Ativação: Verbos](../mfc/activation-verbs.md).

## <a name="see-also"></a>Confira também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)
