---
title: "Como alterar a linguagem ou a condi&#231;&#227;o de um recurso durante a c&#243;pia | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.resvw.resource.changing"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "propriedade de condição de recurso"
  - "Propriedade de linguagem"
ms.assetid: 8f622ab0-bac2-468f-ae70-78911afc4759
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como alterar a linguagem ou a condi&#231;&#227;o de um recurso durante a c&#243;pia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao copiar em um recurso, você pode alterar sua propriedade de idioma ou propriedade de condição ou ambos.  
  
-   O idioma do recurso identifica exatamente isso, o idioma do recurso.  Isso é usado por [FindResource](http://msdn.microsoft.com/library/windows/desktop/ms648042) para ajudar a identificar o recurso para o qual você está procurando.  \(No entanto, recursos podem ter diferenças para cada idioma que não estão relacionadas ao texto, por exemplo, aceleradores que só podem funcionar em um teclado japonês ou um bitmap que só podem ser apropriado para chinês localizadas compilações, etc.\)  
  
-   A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia particular do recurso deve ser usado.  
  
 A linguagem e a condição de um recurso são mostrados entre parênteses depois do nome do recurso na janela do espaço de trabalho.  Neste exemplo o recurso denominado IDD\_AboutBox e estiver usando finlandês como sua linguagem de sua condição XX33.  
  
```  
IDD_AboutBox (Finnish – XX33)  
```  
  
### Para copiar um recurso existente e alterar seu idioma ou condição  
  
1.  No arquivo. rc ou no [exibição recurso](../windows/resource-view-window.md) janela, clique o recurso que você deseja copiar.  
  
2.  Escolha **Inserir cópia** no menu de atalho.  
  
3.  No **Inserir cópia do recurso** caixa de diálogo:  
  
    -   Para o **idioma** caixa de listagem, selecione o idioma.  
  
    -   No **condição** digite a condição.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Como copiar recursos](../windows/how-to-copy-resources.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)