---
title: "Testando o controle modificado DHTML ATL | Microsoft Docs"
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
  - "Controles HTML, testando"
  - "Testando controles"
  - "Controles DHTML, testando"
ms.assetid: 42316118-9433-410f-9d8a-0efcc1eff824
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Testando o controle modificado DHTML ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Experimente o novo controle para ver como ele funciona.  
  
#### Para compilar e testar o controle modificado  
  
1.  Recompilar o projeto e abra\-o no contêiner de teste. Consulte [Testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
     Redimensione o controle para mostrar todos os botões que você adicionou.  
  
2.  Examine os dois botões que você inseriu ao alterar o HTML. Cada botão tem o rótulo que você identificou na [modificando o controle DHTML ATL](../atl/modifying-the-atl-dhtml-control.md): **atualizar** e **HelloHTML**.  
  
3.  Teste os dois novos botões para ver como elas funcionam.  
  
 Teste os métodos que não fazem parte da interface do usuário.  
  
1.  Realce o controle para a borda é ativada.  
  
2.  Sobre o **controle** menu, clique em **invocar métodos**.  
  
 Os métodos na lista rotulado **nome do método** são os métodos que o contêiner pode chamar: `MethodInvoked` e `GoToURL`. Todos os outros métodos são controlados pela interface do usuário.  
  
1.  Selecione um método para invocar e clique em `Invoke` para exibir a caixa de mensagem do método ou navegue até www.microsoft.com.  
  
2.  No **invocar métodos** caixa de diálogo, clique em **Fechar**.  
  
 Para saber mais sobre os diversos elementos e arquivos que compõem um controle DHTML ATL, consulte [identifica os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md).  
  
## Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)