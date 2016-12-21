---
title: "Ativa&#231;&#227;o (C++) | Microsoft Docs"
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
  - "ativando objetos"
  - "ativação [C++]"
  - "ativação [C++], itens inseridos OLE"
  - "documentos, OLE"
  - "objetos inseridos"
  - "ativação no local"
  - "ativação no local, itens vinculados e inseridos"
  - "OLE [C++], ativação"
  - "OLE [C++], edição"
  - "OLE [C++], ativação no local"
  - "ativação de OLE"
  - "Itens OLE, edição visual"
  - "aplicativos de servidor OLE, ativação"
  - "edição visual"
  - "edição visual, ativação"
ms.assetid: ed8357d9-e487-4aaa-aa6b-2edc4de25dfa
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ativa&#231;&#227;o (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica a função de ativação na edição visual de itens com OLE DB.  Depois que um usuário inseriu um item OLE em um documento contêiner, pode precisar ser usado.  Para isso, o usuário clica duas vezes no item, que ativa o item.  A atividade a mais frequente para a ativação está editando.  Muitos itens com OLE DB atuais, quando ativados para a edição, fazem com que os menus e barras de ferramentas da janela atual do quadro para refletir a alteração aqueles que pertencem ao aplicativo de servidor que criou o item.  Esse comportamento, conhecido como o ativação no local, permite que o usuário editar qualquer item inserido em um documento composto sem deixar a janela de documento contêiner.  
  
 Também é possível editar itens com OLE DB inseridos em uma janela separada.  Isso acontecerá se o contêiner ou o aplicativo de servidor não oferecem suporte a ativação local.  Nesse caso, quando o usuário clicar duas vezes em um item inserido, o aplicativo de servidor é iniciado em uma janela separada e o item inserida aparecerá como seu próprio documento.  O usuário edita o item nessa janela.  Ao editar é concluído, o usuário fecha o aplicativo de servidor e retorna ao aplicativo do contêiner.  
  
 Como alternativa, o usuário poderá escolher “a edição” aberta com o comando de **\<object\> Open** no menu de **Editar** .  Isso abre o objeto em uma janela separada.  
  
> [!NOTE]
>  Editar itens inseridos em uma janela separada foi comportamento padrão na versão 1 OLE, e alguns aplicativos OLE podem oferecer suporte somente para esse estilo de edição.  
  
 O ativação em promove uma abordagem documento centradas para a criação do documento.  O usuário pode tratar um documento composto como uma única entidade, trabalhando nela sem alternar entre aplicativos.  Porém, a ativação local é usado apenas para itens inseridos, não para itens vinculados: devem ser editados em uma janela separada.  Isso ocorre porque um item vinculado é realmente armazenado em um local diferente.  A edição de um item vinculado ocorre no contexto atual dos dados, ou seja, onde os dados são armazenados.  Editar um item vinculado em uma janela separada lembra o usuário que pertencem os dados a outro documento.  
  
 MFC O não oferece suporte à ativação in\-loco aninhado.  Se você criar um contêiner\/aplicativo de servidor, e os contêineres\/servidor é inserido em um em outro contêiner e ativado no local, in\-loco não pode ativar objetos incorporados nele.  
  
 O que acontece a um item inserido quando o usuário clicar duas vezes nele depende dos verbos definidos para o item.  Para obter mais informações, consulte [Ativação: Verbos](../mfc/activation-verbs.md).  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)