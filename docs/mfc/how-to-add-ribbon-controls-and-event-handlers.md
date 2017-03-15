---
title: "Como adicionar controles de faixa de op&#231;&#245;es e manipuladores de evento | Microsoft Docs"
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
  - "manipuladores de eventos, adicionando"
  - "controles de faixa de opções, adicionando"
ms.assetid: b31f25bc-ede7-49c3-9e3c-dffe4e174a69
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como adicionar controles de faixa de op&#231;&#245;es e manipuladores de evento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os controles de Faixa De Opções são elementos, como os botões e as caixas de combinação, que você adiciona aos painéis.  Os painéis são as áreas da barra de fita que exibem um grupo de controles relacionados.  
  
 Neste tópico, você abrirá o designer da Faixa De Opções, adicionar um botão, e vincular em um evento que o mundo do exibe “hello”.  
  
### Para abrir o designer da Faixa De Opções  
  
1.  No Visual Studio, no menu de **Exibir** , clique em **Modo de Exibição de Recurso**.  
  
2.  Em **Modo de Exibição de Recurso**, clique duas vezes no recurso de fita para exibi\-lo na superfície de design.  
  
### Para adicionar um botão e um manipulador de eventos  
  
1.  De **Barra de Ferramentas**, clique em **Botão** e arraste\-o em um painel na superfície de design.  
  
2.  Clique com o botão direito do mouse no botão e, em **Adicionar Manipulador de Eventos**.  
  
3.  Em **Assistente do manipulador de eventos**, confirme as configurações padrão e clique em **Adicionar e editar**.  Para obter mais informações, consulte [Assistente de Manipulador de Eventos](../ide/event-handler-wizard.md).  
  
4.  No editor de códigos, adicione o código a seguir na função de manipulador:  
  
    ```  
    MessageBox((LPCTSTR)L"Hello World");  
    ```  
  
## Consulte também  
 [Exemplo de RibbonGadgets: Aplicativo de gadget da Faixa De Opções](../top/visual-cpp-samples.md)   
 [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md)