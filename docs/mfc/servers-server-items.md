---
title: 'Servidores: itens de servidor'
ms.date: 11/04/2016
helpviewer_keywords:
- server items, implementing
- servers [MFC], server items
- architecture [MFC], server-item
- server items
- OLE server applications [MFC], server items
ms.assetid: 28ba81a1-726a-4728-a52d-68bc7efd5a3c
ms.openlocfilehash: 8ae24104a30a0b44e92b889006907911124310f7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355108"
---
# <a name="servers-server-items"></a>Servidores: itens de servidor

Quando um contêiner inicia um servidor para que um usuário possa editar um item OLE incorporado ou vinculado, o aplicativo do servidor cria um "item do servidor". O item do servidor, que é um `COleServerItem`objeto de uma classe derivada, fornece uma interface entre o documento do servidor e o aplicativo do contêiner.

A `COleServerItem` classe define várias funções de membros superridíveis que são chamadas pela OLE, geralmente em resposta às solicitações do contêiner. Os itens do servidor podem representar parte do documento do servidor ou de todo o documento. Quando um item OLE é incorporado no documento do contêiner, o item do servidor representa todo o documento do servidor. Quando o item OLE é vinculado, o item do servidor pode representar uma parte do documento do servidor ou todo o documento, dependendo se o link é para uma parte ou para o todo.

Na amostra [HIERSVR,](../overview/visual-cpp-samples.md) por exemplo, a classe `CServerItem`de item do servidor, tem um `CServerNode`membro que é um ponteiro para um objeto da classe . O `CServerNode` objeto é um nó no documento do aplicativo HIERSVR, que é uma árvore. Quando `CServerNode` o objeto é o `CServerItem` nó raiz, o objeto representa todo o documento. Quando `CServerNode` o objeto é um `CServerItem` nó de criança, o objeto representa uma parte do documento. Consulte a amostra de OLE do MFC [HIERSVR](../overview/visual-cpp-samples.md) para um exemplo dessa interação.

## <a name="implementing-server-items"></a><a name="_core_implementing_server_items"></a>Implementando itens do servidor

Se você usar o assistente do aplicativo para produzir código "inicial" para o seu aplicativo, tudo o que você precisa fazer para incluir itens do servidor em seu código inicial é escolher uma das opções do servidor na página Opções OLE. Se você estiver adicionando itens do servidor a um aplicativo existente, execute as seguintes etapas:

#### <a name="to-implement-a-server-item"></a>Para implementar um item de servidor

1. Derivar uma `COleServerItem`classe de .

1. Em sua classe derivada, `OnDraw` anule a função de membro.

   A estrutura `OnDraw` chama para transformar o item OLE em um metaarquivo. O aplicativo de contêiner usa este metaarquivo para renderizar o item. A classe de visualização `OnDraw` do aplicativo também tem uma função de membro, que é usada para renderizar o item quando o aplicativo do servidor está ativo.

1. Implemente uma `OnGetEmbeddedItem` substituição da sua classe de documento de servidor. Para obter mais informações, consulte o artigo [Servidores: Implementando documentos do servidor](../mfc/servers-implementing-server-documents.md) e a amostra de OLE do MFC [HIERSVR](../overview/visual-cpp-samples.md).

1. Implemente a função de `OnGetExtent` membro da classe de itens do servidor. A estrutura chama essa função para recuperar o tamanho do item. A implementação padrão não faz nada.

## <a name="a-tip-for-server-item-architecture"></a><a name="_core_a_tip_for_server.2d.item_architecture"></a>Uma dica para arquitetura de itens do servidor

Como observado na [implementação de itens do servidor,](#_core_implementing_server_items)os aplicativos de servidor devem ser capazes de renderizar itens tanto na exibição do servidor quanto em um metaarquivo usado pelo aplicativo de contêiner. Na arquitetura de aplicativos da Microsoft Foundation Class `OnDraw` Library, a função de membro da classe de exibição renderiza o item quando ele está sendo editado (consulte [CView::OnDraw](../mfc/reference/cview-class.md#ondraw) na *referência da biblioteca de classe).* O item do `OnDraw` servidor torna o item em um metaarquivo em todos os outros casos (ver [COleServerItem::OnDraw](../mfc/reference/coleserveritem-class.md#ondraw)).

Você pode evitar a duplicação de código escrevendo funções auxiliares na `OnDraw` sua classe de documento de servidor e chamando-as das funções em suas classes de exibição e item do servidor. A amostra DeLHIERSVR da amostra MFC `CServerView::OnDraw` `CServerItem::OnDraw` OLE `CServerDoc::DrawTree` usa essa estratégia: as funções e ambas as chamadas para renderizar o item. [HIERSVR](../overview/visual-cpp-samples.md)

A vista e o `OnDraw` item têm funções de membro porque desenham em condições diferentes. A visualização deve levar em conta fatores como zoom, tamanho e extensão da seleção, recorte e elementos de interface do usuário, como barras de rolagem. O item do servidor, por outro lado, sempre desenha todo o objeto OLE.

Para obter mais informações, consulte [CView::OnDraw](../mfc/reference/cview-class.md#ondraw), [COleServerItem,](../mfc/reference/coleserveritem-class.md) [COleServerItem::OnDraw](../mfc/reference/coleserveritem-class.md#ondraw)e [COleServerDoc::OnGetEmbeddedItem](../mfc/reference/coleserverdoc-class.md#ongetembeddeditem) na *referência da biblioteca de*classes .

## <a name="see-also"></a>Confira também

[Servidores](../mfc/servers.md)
