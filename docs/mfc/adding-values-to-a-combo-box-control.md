---
title: "Adicionando valores a um controle de caixa de combina&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.dialog.combo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "caixas de combinação [C++], adicionando valores"
  - "caixas de combinação [C++], Propriedade de dados"
  - "caixas de combinação [C++], visualizando valores"
  - "caixas de combinação [C++], testando valores"
  - "controles [C++], testando valores em caixas de combinação"
  - "controles [Visual Studio], testando valores em caixas de combinação"
  - "Propriedade de dados"
ms.assetid: 22a78f98-fada-48b3-90d8-7fa0d8e4de51
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando valores a um controle de caixa de combina&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode adicionar valores a um controle de caixa de combinação, contanto que você tenha o editor de diálogo Abrir.  
  
> [!TIP]
>  Ele é uma boa idéia adicionar todos os valores para a caixa de combinação  *antes de* você dimensiona a caixa no editor de diálogo, ou você pode truncar o texto que deve aparecer no controle de combinação.  
  
#### Para inserir valores em um controle de caixa de combinação  
  
1.  Selecione o controle de caixa de combinação, clicando nele.  
  
2.  No  [Janela Propriedades do](../Topic/Properties%20Window.md), role para baixo até o  **dados** propriedade.  
  
    > [!NOTE]
    >  Se você estiver exibindo as propriedades agrupadas por tipo,  **dados** consta o  **diverso** propriedades.  
  
3.  Clique na área de valor para o  **dados** propriedade e digite os valores de dados, separados por ponto e vírgula.  
  
    > [!NOTE]
    >  Não coloque espaços entre valores porque espaços interferem colocando em ordem alfabética na lista suspensa.  
  
4.  Clique em  **Enter** quando você terminar de adicionar valores.  
  
 Para informações sobre como ampliar a parte suspensa de uma caixa de combinação, consulte  [definir o tamanho da sua lista de Drop\-Down de caixa de combinação e](../mfc/setting-the-size-of-the-combo-box-and-its-drop-down-list.md).  
  
> [!NOTE]
>  Não é possível adicionar valores aos projetos do Win32 usando este procedimento \(o  **dados**  propriedade fica cinza em projetos Win32\).  Porque os projetos do Win32 não possuem bibliotecas que adicionar esse recurso, você deve adicionar valores para uma caixa de combinação com um projeto do Win32 programaticamente.  
  
#### Para testar a aparência dos valores em uma caixa de combinação  
  
1.  Depois de inserir valores na  **dados** propriedade, clique no  **teste** na barra a  [Barra de ferramentas do Editor de diálogo](../mfc/showing-or-hiding-the-dialog-editor-toolbar.md).  
  
     Tente a rolagem para baixo na lista de todo o valor.  Os valores exibidos exatamente em que são digitados a  **dados** propriedade na janela Propriedades.  Não há nenhuma ortografia ou a verificação de maiúsculas e minúsculas.  
  
     Pressione ESC para retornar ao editor de caixa de diálogo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 Win32  
  
## Consulte também  
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)