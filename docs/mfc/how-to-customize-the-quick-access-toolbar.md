---
title: "Como personalizar a barra de ferramentas de acesso r&#225;pido | Microsoft Docs"
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
  - "barra de ferramentas de acesso rápido, personalização"
ms.assetid: 2554099b-0c89-4605-9249-31bf9cbcefe0
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como personalizar a barra de ferramentas de acesso r&#225;pido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A barra de ferramentas de acesso rápido \(QAT\) é uma barra de ferramentas personalizável que contém um conjunto de comandos que são o exibido ao lado do botão do aplicativo ou nas guias de categoria.  A ilustração a seguir mostra uma barra de ferramentas comum de acesso rápido.  
  
 ![Ferramentas de acesso rápido de faixa de opções do MFC](../mfc/media/quick_access_toolbar.png "Quick\_Access\_Toolbar")  
  
 Para personalizar a barra de ferramentas de acesso rápido, abra\-a na janela de **Propriedades** , modifique os comandos, e visualizá\-lo no controle de fita.  
  
### Para abrir a barra de ferramentas de acesso rápido na janela Propriedades  
  
1.  No Visual Studio, no menu de **Exibir** , clique em **Modo de Exibição de Recurso**.  
  
2.  Em **Modo de Exibição de Recurso**, clique duas vezes no recurso de fita para exibi\-lo na superfície de design.  
  
3.  Na superfície de design, clique com o botão direito do mouse no menu da barra de ferramentas de acesso rápido e clique em **Propriedades**.  
  
## Propriedades da barra de ferramentas de acesso rápido  
 A tabela a seguir define as propriedades da barra de ferramentas de acesso rápido.  
  
|Propriedade|Definição|  
|-----------------|---------------|  
|Posição de QAT|Especificar a posição da barra de ferramentas de acesso rápido quando o aplicativo é iniciado.  A posição pode ser **Acima** ou **Abaixo** o controle de fita.|  
|Itens de QAT|Especifica os comandos que estão disponíveis para a barra de ferramentas de acesso rápido.|  
  
#### Para adicionar ou remover comandos na barra de ferramentas de acesso rápido  
  
1.  Na janela de **Propriedades** , clique em **Itens QAT**, e clique no botão de reticências **\(...\)**.  
  
2.  Na caixa de diálogo de **Editor de Itens QAT** , use os botões de **Adicionar** e de **Remover** para alterar a lista de comandos na barra de ferramentas de acesso rápido.  
  
3.  Se você desejar um comando aparecer na barra de ferramentas de acesso rápido e no menu da barra de ferramentas de acesso rápido, marque a caixa ao lado do comando.  Se você quiser que o comando aparecer somente no menu, desmarque a caixa.  
  
## Visualizando a Faixa De Opções  
 Os comandos da barra de ferramentas de acesso rápido não aparecem na superfície de design.  Exibi\-los, visualize a fita ou executar o aplicativo.  
  
#### Para visualizar o controle de fita  
  
-   Em **Barra de ferramentas do editor da Faixa De Opções**, clique em **Faixa de Opções de Teste**.  
  
## Consulte também  
 [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md)