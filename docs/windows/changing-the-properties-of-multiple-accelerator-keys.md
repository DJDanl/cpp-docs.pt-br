---
title: "Alterando as propriedades de v&#225;rias teclas de acelera&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "tabelas de teclas aceleradoras [C++], alterando propriedades"
  - "atalhos de teclado [C++], alteração de propriedades"
ms.assetid: b55c9bd6-b430-48bb-b942-0e6f21d7abf9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando as propriedades de v&#225;rias teclas de acelera&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para alterar as propriedades de várias teclas de aceleração  
  
1.  Abra a tabela de acelerador clicando duas vezes no ícone correspondente na  [Exibição de recurso](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Selecione as teclas de aceleração que deseja alterar, mantendo pressionada a  **CTRL** tecla enquanto clica em cada uma delas.  
  
3.  Vá para o  [janela Propriedades do](../Topic/Properties%20Window.md) e digite os valores que deseja que todos os selecionados accelerators para compartilhar.  
  
    > [!NOTE]
    >  Cada valor de modificador aparece como uma propriedade booleana na janela Propriedades.  Se você alterar uma  [modificador](../windows/accelerator-modifier-property.md) valor na janela Propriedades, a tabela accelerator trata o modificador de novo como uma adição a qualquer modificadores que existiam anteriormente.  Dessa forma, se você definir quaisquer valores de modificador, você precisará definir todos eles para garantir que cada accelerator compartilha as mesmas configurações de modificador.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editando tabelas de aceleradores](../windows/editing-accelerator-tables.md)   
 [Editor de aceleradores](../Topic/Accelerator%20Editor.md)