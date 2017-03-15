---
title: "Movendo uma cadeia de caracteres de um arquivo de recurso para outro | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "arquivos de script de recurso, movendo cadeias de caracteres"
  - "edição de cadeia de caracteres, movendo cadeias de caracteres entre recursos"
  - "Editor de Cadeias de Caracteres, movendo cadeias de caracteres entre arquivos"
  - "cadeias de caracteres [C++], movendo entre arquivos"
ms.assetid: 94f8ee81-9b4c-4788-ba95-68c58db38029
caps.latest.revision: 12
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Movendo uma cadeia de caracteres de um arquivo de recurso para outro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para mover uma seqüência de caracteres do arquivo de script de um recurso para outro  
  
1.  Abra as tabelas de cadeia de caracteres em ambos os arquivos. rc.  \(Para obter mais informações, consulte  [Recursos de exibição em um recurso Script arquivo fora de um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).\)  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Clique com o botão direito a seqüência de caracteres que você deseja mover e escolha  **Recortar** no menu de atalho.  
  
3.  Coloque o cursor no destino  **O Editor de seqüência de caracteres** janela.  
  
4.  No arquivo. rc ao qual você deseja mover a seqüência de caracteres, clique com o botão direito e escolha  **Colar** no menu de atalho.  
  
    > [!NOTE]
    >  Se o  **ID** ou  **valor** a conflitos de seqüência de caracteres movidos com uma existente  **ID** ou  **valor** no arquivo de destino, tanto o  **ID** ou o  **valor** as alterações de seqüência de caracteres movidos.  Se uma seqüência de caracteres existir com o mesmo  **ID**, o  **ID** as alterações de seqüência de caracteres movidos.  Se uma seqüência de caracteres existir com o mesmo  **valor**, o  **valor** as alterações de seqüência de caracteres movidos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados \(aquelas que visam common language runtime\), consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de Cadeia de Caracteres](../mfc/string-editor.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Personalizando layouts de janela](../Topic/Customizing%20window%20layouts%20in%20Visual%20Studio.md)   
 [Seqüências de caracteres](_win32_Strings)   
 [sobre seqüências de caracteres](_win32_About_Strings_cpp)