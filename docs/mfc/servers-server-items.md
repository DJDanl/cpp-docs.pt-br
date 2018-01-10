---
title: 'Servidores: Itens do servidor | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- server items, implementing
- servers [MFC], server items
- architecture [MFC], server-item
- server items
- OLE server applications [MFC], server items
ms.assetid: 28ba81a1-726a-4728-a52d-68bc7efd5a3c
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2fe196eb561c336e45402de6c390146a0d77bea4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="servers-server-items"></a>Servidores: itens de servidor
Quando um contêiner inicia um servidor para que um usuário pode editar um item OLE incorporado ou vinculado, o aplicativo de servidor cria um "item de servidor". O item do servidor, que é um objeto de uma classe derivada de `COleServerItem`, fornece uma interface entre o documento do servidor e o aplicativo de contêiner.  
  
 O `COleServerItem` classe define várias funções de membro substituíveis que são chamadas pelo OLE, geralmente em resposta a solicitações do contêiner. Itens do servidor podem representar a parte do documento do servidor ou o documento inteiro. Quando um item OLE é incorporado no documento contêiner, o item do servidor representa o documento de todo o servidor. Quando o item OLE é vinculado, o item do servidor pode representar uma parte do documento do servidor ou o documento inteiro, dependendo se o link é uma parte ou todo o.  
  
 No [HIERSVR](../visual-cpp-samples.md) de exemplo, por exemplo, a classe de item de servidor, **CServerItem**, tem um membro que é um ponteiro para um objeto da classe **CServerNode**. O **CServerNode** objeto for um nó de documento do aplicativo HIERSVR, que é uma árvore. Quando o **CServerNode** objeto é o nó raiz, o **CServerItem** objeto representa o documento inteiro. Quando o **CServerNode** objeto é um nó filho, o **CServerItem** objeto representa uma parte do documento. Consulte o exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md) para obter um exemplo dessa interação.  
  
##  <a name="_core_implementing_server_items"></a>Implementação de itens do servidor  
 Se você usar o Assistente de aplicativo para gerar o código de "início" para seu aplicativo, você precisa fazer para incluir itens de servidor no seu código inicial é escolher uma das opções de servidor da página de opções OLE. Se você estiver adicionando itens do servidor para um aplicativo existente, execute as seguintes etapas:  
  
#### <a name="to-implement-a-server-item"></a>Para implementar um item de servidor  
  
1.  Derive uma classe de `COleServerItem`.  
  
2.  Em sua classe derivada, substituir o `OnDraw` função de membro.  
  
     A estrutura chama `OnDraw` para renderizar o item OLE em um metarquivo. O aplicativo de contêiner usa esse metarquivo para renderizar o item. Classe de exibição do aplicativo também tem um `OnDraw` a função de membro, que é usada para renderizar o item quando o aplicativo do servidor está ativo.  
  
3.  Implementar uma substituição de `OnGetEmbeddedItem` para sua classe de documento do servidor. Para obter mais informações, consulte o artigo [servidores: Implementando documentos de servidor](../mfc/servers-implementing-server-documents.md) o exemplo OLE do MFC e [HIERSVR](../visual-cpp-samples.md).  
  
4.  Implementar sua classe de item de servidor `OnGetExtent` função de membro. O framework chama esta função para recuperar o tamanho do item. A implementação padrão não fará nada.  
  
##  <a name="_core_a_tip_for_server.2d.item_architecture"></a>Uma dica para arquitetura de Item do servidor  
 Conforme observado na [itens do servidor implementando](#_core_implementing_server_items), aplicativos de servidor devem ser capazes de processar os itens no modo de exibição do servidor e em um meta-arquivo usado pelo aplicativo de contêiner. No arquitetura do aplicativo da biblioteca Microsoft Foundation Class, a classe de exibição `OnDraw` função membro renderiza o item quando ele está sendo editado (consulte [CView::OnDraw](../mfc/reference/cview-class.md#ondraw) no *referência da biblioteca de classe* ). O item do servidor `OnDraw` renderiza o item em um meta-arquivo em todos os outros casos (consulte [COleServerItem::OnDraw](../mfc/reference/coleserveritem-class.md#ondraw)).  
  
 Você pode evitar a duplicação de código escrevendo funções auxiliares em sua classe de documento do servidor e chamando-as do `OnDraw` funções em suas classes de exibição e o item do servidor. O exemplo OLE do MFC [HIERSVR](../visual-cpp-samples.md) usa essa estratégia: as funções **CServerView::OnDraw** e **CServerItem::OnDraw** chamam **CServerDoc::DrawTree**  para renderizar o item.  
  
 O modo de exibição e o item tem `OnDraw` funções de membro porque eles desenhar em condições diferentes. O modo de exibição deve levar em conta fatores como aumentar o zoom, tamanho da seleção e extensão, recorte e elementos de interface do usuário, como barras de rolagem. O item do servidor, por outro lado, sempre desenha todo o objeto OLE.  
  
 Para obter mais informações, consulte [CView::OnDraw](../mfc/reference/cview-class.md#ondraw), [COleServerItem](../mfc/reference/coleserveritem-class.md), [COleServerItem::OnDraw](../mfc/reference/coleserveritem-class.md#ondraw), e [COleServerDoc::OnGetEmbeddedItem](../mfc/reference/coleserverdoc-class.md#ongetembeddeditem)no *referência da biblioteca de classes*.  
  
## <a name="see-also"></a>Consulte também  
 [Servidores](../mfc/servers.md)

