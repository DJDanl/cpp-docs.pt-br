---
title: "Ativa&#231;&#227;o: verbos | Microsoft Docs"
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
  - "ativação [C++], verbos"
  - "editar verbo"
  - "OLE [C++], ativação"
  - "OLE [C++], edição"
  - "ativação de OLE"
  - "Verbo primário"
  - "verbos"
ms.assetid: eb56ff23-1de8-43ad-abeb-dc7346ba7b70
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ativa&#231;&#227;o: verbos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica a função primária e os verbos secundários são executados em [ativação](../mfc/activation-cpp.md)OLE.  
  
 Em geral, clique duas vezes em um item inserido permite que o usuário editá\-lo.  No entanto, alguns itens não se comportam essa maneira.  Por exemplo, clique duas vezes em um item criado com o aplicativo do registrador satisfatório não abre o servidor em uma janela separada; em vez disso, execute o correta.  
  
 O motivo dessa diferença de comportamento é que os itens do registrador satisfatório “têm um verbo primário diferente.” O verbo primário é a ação executada quando o usuário clicar duas vezes em um item OLE.  Para a maioria dos tipos de itens OLE, o verbo primário é a edição, o que inicia o servidor que criou o item.  Para alguns tipos de itens, como itens do registrador satisfatório, o verbo primário é reprodução.  
  
 Muitos tipos de itens do oferecem suporte apenas a um verbo, e a edição é mais comuns.  No entanto, alguns tipos de itens dão suporte a vários verbos.  Por exemplo, edição de suporte dos itens do registrador satisfatório como um verbo secundário.  
  
 Outro verbo frequentemente usado é aberto.  O verbo aberto é idêntico à edição, a não ser que o aplicativo servidor é iniciado em uma janela separada.  Este verbo deve ser usado quando o aplicativo de contêiner ou o aplicativo de servidor não oferecem suporte a ativação local.  
  
 Todos os verbos diferentes do verbo primário devem ser invocados por meio de um comando no submenu quando o item é selecionado.  Este submenu contém todos os verbos aceitos pelo item e é atingido geralmente pelo comando de **Objeto***typename*no menu de **Editar** .  Para obter informações sobre o comando de **Objeto***typename*, consulte o artigo [Menus e recursos: Adições do contêiner](../mfc/menus-and-resources-container-additions.md).  
  
 Os verbos que um aplicativo de servidor da suporte são listados na base de dados do registro do windows.  Se seu aplicativo de servidor é gravado com a biblioteca de classes do Microsoft, registrará automaticamente todos os verbos quando o servidor é iniciado.  Caso contrário, você deve registrá\-los durante a fase de inicialização de aplicativo de servidor.  Para obter mais informações, consulte o artigo [Registro](../mfc/registration.md).  
  
## Consulte também  
 [Ativação](../mfc/activation-cpp.md)   
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)