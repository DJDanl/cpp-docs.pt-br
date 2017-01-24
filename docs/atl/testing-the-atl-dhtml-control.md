---
title: "Testando o controle de ATL DHTML | Microsoft Docs"
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
  - "Controles DHTML"
  - "Controles DHTML, testando"
  - "controles HTML, testando"
  - "controles de teste"
ms.assetid: 0e4b4358-80ce-4505-8b06-ef4f30b1d1f0
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Testando o controle de ATL DHTML
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Depois de criar o projeto, você pode criar e testar o exemplo de controle.  Antes de você fizer isso, o modo da classe de uso e solution Explorer para examinar o projeto.  Os elementos do projeto são descritos em detalhes em [Identificando os elementos do projeto de controle HTML dinâmico \(DHTML\)](../atl/identifying-the-elements-of-the-dhtml-control-project.md).  
  
#### Para criar e testar o controle de ATL DHTML  
  
1.  Crie o projeto.  Em o menu de **Compilar** , clique em **Compilar solução**.  
  
2.  Quando a compilação for concluída, abra o contêiner de teste.  Consulte [Propriedades e eventos de teste com recipientes de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o recipiente de teste.  
  
3.  Em o contêiner de teste, no menu de **Editar** , clique em **Insert New Control**.  
  
4.  Em a caixa de diálogo de **Inserir Controle** , selecione o controle de caixa de listagem.  Lembre\-se, o nome é baseado no nome curto que você indicou no assistente de controle de ATL.  Clique em **OK**.  
  
5.  Examine o controle.  Observe que tem um barra de rolagem.  Use o controle manipula para redimensionar o controle para ativar a barra de rolagem.  
  
6.  Testar os botões do controle.  A cor do plano de fundo muda para a cor indicada pelo botão.  
  
7.  Próximo contêiner de teste.  
  
 Em seguida, tente [alterando o controle HTML dinâmico \(DHTML\)](../atl/modifying-the-atl-dhtml-control.md).  
  
## Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)