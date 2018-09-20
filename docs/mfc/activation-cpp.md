---
title: Ativação (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e0f6207d91fa3816ab17462f62bd39551f7961e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383968"
---
# <a name="activation-c"></a>Ativação (C++)

Este artigo explica a função de ativação na edição visual de itens OLE. Depois que um usuário tiver inserido um item OLE em um documento de contêiner, ele talvez precise ser usada. Para fazer isso, o usuário clica duas vezes no item, que ativa esse item. A atividade mais frequente para a ativação está editando. Muitos itens OLE atuais, quando ativado para edição, fazer com que os menus e barras de ferramentas na janela de quadro atual ser alterada para refletir as que pertencem ao aplicativo do servidor que criou o item. Esse comportamento, conhecido como ativação in-loco, permite ao usuário editar qualquer item inserido em um documento composto sem sair da janela do documento contêiner.

Também é possível editar itens inseridos OLE em uma janela separada. Isso ocorrerá se o aplicativo de contêiner ou o servidor não oferece suporte a ativação in-loco. Nesse caso, quando o usuário clica duas vezes em um item inserido, o aplicativo de servidor é iniciado em uma janela separada, e o item inserido é exibido como seu próprio documento. O usuário edita o item nessa janela. Quando a edição for concluída, o usuário fecha o aplicativo de servidor e retorna para o aplicativo de contêiner.

Como alternativa, o usuário pode escolher "abrir edição" com o  **\<objeto > Abrir** comando os **editar** menu. Isso abre o objeto em uma janela separada.

> [!NOTE]
>  Editar itens inseridos em uma janela separada era o comportamento padrão na versão 1 do OLE, e alguns aplicativos OLE podem oferecer suporte a apenas esse estilo de edição.

Ativação in-loco promove uma abordagem centrada em documento para a criação de documentos. O usuário pode tratar um documento composto como uma única entidade, estamos trabalhando nisso, sem precisar alternar entre aplicativos. No entanto, a ativação in-loco é usada apenas para itens incorporados e não para os itens vinculados: eles devem ser editados em uma janela separada. Isso ocorre porque um item vinculado, na verdade, é armazenado em um local diferente. A edição de um item vinculado ocorre dentro do contexto real dos dados, ou seja, onde os dados são armazenados. Editar um item vinculado em uma janela separada lembra ao usuário que pertencem os dados a outro documento.

MFC não oferece suporte a ativação in-loco aninhada. Se você cria um aplicativo de contêiner/servidor e que contêiner/servidor é inserido em outro contêiner e ativado no local, ele não é possível in-loco ativar objetos incorporados nele.

O que acontece com um item inserido quando o usuário clica duas vezes ele depende dos verbos definidos para o item. Para obter informações, consulte [ativação: verbos](../mfc/activation-verbs.md).

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)

