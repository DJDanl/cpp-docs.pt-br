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
ms.openlocfilehash: 34b6d6e9313092a8f9a0a11967c7c6a62ed15e15
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="activation-c"></a>Ativação (C++)
Este artigo explica a função de ativação na edição visual de itens OLE. Depois que um usuário tiver inserido um item OLE em um documento de contêiner, ele pode ser necessário ser usado. Para fazer isso, o usuário clica duas vezes o item, que ativa esse item. A atividade mais frequente para a ativação está editando. Muitos itens OLE atuais, quando ativado para edição, fazer com que os menus e barras de ferramentas na janela do quadro atual para alterar para refletir pertencente ao aplicativo do servidor que criou o item. Esse comportamento, conhecido como ativação in-loco, permite ao usuário editar qualquer item inserido em um documento composto sem sair da janela do documento contêiner.  
  
 Também é possível editar itens inseridos OLE em uma janela separada. Isso ocorrerá se o aplicativo de contêiner ou o servidor não oferece suporte a ativação no local. Nesse caso, quando o usuário clica duas vezes em um item inserido, o aplicativo de servidor é iniciado em uma janela separada e o item inserido é exibido como seu próprio documento. O usuário edita o item nesta janela. Quando a edição estiver concluída, o usuário fecha o aplicativo de servidor e retorna para o aplicativo de contêiner.  
  
 Como alternativa, o usuário pode escolher "abrir edição" com o  **\<objeto > Abrir** comando o **editar** menu. Isso abre o objeto em uma janela separada.  
  
> [!NOTE]
>  Edição de itens inseridos em uma janela separada era o comportamento padrão na versão 1 do OLE, e alguns aplicativos OLE podem oferecer suporte a somente esse estilo de edição.  
  
 Ativação no local promove uma abordagem centrada no documento para criação de documentos. O usuário pode tratar um documento composto como uma única entidade, trabalhando sem alternar entre aplicativos. No entanto, a ativação no local é usada apenas para itens incorporados e não para itens vinculados: eles devem ser editadas em uma janela separada. Isso ocorre porque um item vinculado, na verdade, é armazenado em um local diferente. A edição de um item vinculado ocorre dentro do contexto real dos dados, ou seja, onde os dados são armazenados. Editar um item vinculado em uma janela separada lembra ao usuário que os dados pertencem a outro documento.  
  
 MFC não oferece suporte a ativação no local aninhada. Se você criar um aplicativo de contêiner/servidor e que contêiner/servidor é incorporado em outro contêiner e ativado no local, ele não é possível in-loco ativar objetos inseridos dentro dele.  
  
 O que acontece com um item inserido quando o usuário clica duas vezes ele depende dos verbos definidos para o item. Para obter informações, consulte [ativação: verbos](../mfc/activation-verbs.md).  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)

