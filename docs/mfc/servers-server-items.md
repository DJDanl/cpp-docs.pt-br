---
title: "Servidores: itens de servidor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquitetura [C++], item de servidor"
  - "aplicativos de servidor OLE, itens de servidor"
  - "itens de servidor"
  - "itens de servidor, implementando"
  - "servidores [C++], itens de servidor"
ms.assetid: 28ba81a1-726a-4728-a52d-68bc7efd5a3c
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores: itens de servidor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um contêiner inicia um servidor de modo que um usuário possa editar um item OLE inserido ou vinculado, o aplicativo de servidor cria um item servidor “.” O item do servidor, que é um objeto de uma classe derivada de `COleServerItem`, fornece uma interface entre o documento de servidor e o aplicativo do contêiner.  
  
 A classe de `COleServerItem` define várias funções de membro substituível que são chamadas pelo OLE, normalmente em resposta a solicitações do contêiner.  Os itens do servidor podem representar a parte do documento de servidor ou do documento inteiro.  OLE quando um item é inserido no documento contêiner, o item do servidor representa o documento inteiro do servidor.  Quando o item é OLE vinculado, o item do servidor pode representar uma parte do documento de servidor ou do documento inteiro, dependendo se o link é a parte ou a todos.  
  
 No exemplo de [HIERSVR](../top/visual-cpp-samples.md) , por exemplo, a classe no item, **CServerItem**, tem um membro que é um ponteiro para um objeto da classe **CServerNode**.  O objeto de **CServerNode** é um nó no documento de aplicativo de HIERSVR, que é uma árvore.  Quando o objeto de **CServerNode** é o nó raiz, o objeto de **CServerItem** representa o documento inteiro.  Quando o objeto de **CServerNode** é um nó filho, o objeto de **CServerItem** representa uma parte do documento.  Consulte o exemplo [HIERSVR](../top/visual-cpp-samples.md) MFC OLE para obter um exemplo dessa interação.  
  
##  <a name="_core_implementing_server_items"></a> Implementando itens do servidor  
 Se você usar o assistente de aplicativo para gerar o código de “acionador de partida” para seu aplicativo, tudo o que você tem que fazer para incluir itens do servidor no acionador de partida o código é escolher uma das opções do servidor da página de opções OLE.  Se você estiver adicionando itens do servidor a um aplicativo existente, execute as seguintes etapas:  
  
#### Para implementar um item do servidor  
  
1.  Derivar uma classe de `COleServerItem`.  
  
2.  Em sua classe derivada, substitua a função de membro de `OnDraw` .  
  
     A estrutura chama `OnDraw` para renderizar o item OLE em um metarquivo.  O aplicativo usa esse contêiner de metarquivo para renderizar o item.  A classe da exibição do seu aplicativo também tem uma função de membro de `OnDraw` , que é usada para renderizar o item quando o aplicativo servidor está ativa.  
  
3.  Implementar uma substituição de `OnGetEmbeddedItem` para a sua classe do documento.  Para obter mais informações, consulte o artigo [Servidores: Implementando documentos do servidor](../mfc/servers-implementing-server-documents.md) e o exemplo [HIERSVR](../top/visual-cpp-samples.md)MFC OLE.  
  
4.  Implementar a função de membro de `OnGetExtent` da classe no item.  A estrutura chamará essa função para recuperar o tamanho do item.  A implementação padrão não fará nada.  
  
##  <a name="_core_a_tip_for_server.2d.item_architecture"></a> Uma dica para a arquitetura do item  
 Como observado em [Implementando itens do servidor](#_core_implementing_server_items), os aplicativos para servidores devem poder renderizar os dois itens na exibição de servidor e um metarquivo usado pelo aplicativo do contêiner.  Na arquitetura do aplicativo de biblioteca de classes do Microsoft, a função de membro de `OnDraw` da classe da exibição renderiza o item quando está sendo editada \(consulte [CView::OnDraw](../Topic/CView::OnDraw.md)*na referência da biblioteca de classe*\).  `OnDraw` do item do servidor renderiza o item em um metarquivo em todos os outros casos [COleServerItem::OnDraw](../Topic/COleServerItem::OnDraw.md)\(consulte\).  
  
 Você pode evitar a duplicação de código para escrever funções auxiliares em sua classe do documento e chamando as funções de `OnDraw` em suas classes de exibição e do item.  O exemplo [HIERSVR](../top/visual-cpp-samples.md) MFC OLE usa essa estratégia: as funções **CServerView::OnDraw** e **CServerItem::OnDraw** ambos chamam **CServerDoc::DrawTree** para renderizar o item.  
  
 A exibição e o item têm funções de membro de `OnDraw` como desenha em condições diferentes.  A exibição deve levar em consideração fatores como aplicar zoom, tamanho e extensão de seleção, recuo, e elementos da interface do usuário como barras de rolagem.  O item do servidor, por outro lado, desenha sempre o objeto OLE inteiro.  
  
 Para obter mais informações, consulte [CView::OnDraw](../Topic/CView::OnDraw.md), [COleServerItem](../mfc/reference/coleserveritem-class.md), [COleServerItem::OnDraw](../Topic/COleServerItem::OnDraw.md), e [COleServerDoc::OnGetEmbeddedItem](../Topic/COleServerDoc::OnGetEmbeddedItem.md)*na referência da biblioteca da classe*.  
  
## Consulte também  
 [Servidores](../mfc/servers.md)