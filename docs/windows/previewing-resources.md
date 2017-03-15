---
title: "Visualizando recursos | Microsoft Docs"
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
  - "vc.resvw.resource.previewing"
  - "vs.resvw.resource.previewing"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "código, exibindo"
  - "visualizações de recurso"
  - "recursos [Visual Studio], exibindo"
ms.assetid: d6abda66-0e2b-4ac3-a59a-a57b8c6fb70b
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Visualizando recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A visualização de seus recursos permite que você visualize os recursos gráficos sem abri\-los.  A visualização também é útil para executáveis depois que você tenha compilado\-los, pois os identificadores de recurso alterar para números.  Desde que esses identificadores numéricos geralmente não fornecerem informações suficientes, visualizar os recursos ajuda você a identificar rapidamente\-los.  
  
 Você pode visualizar o layout visual dos seguintes tipos de recurso:  
  
-   Bitmap  
  
-   Dialog  
  
-   Ícone  
  
-   Menu  
  
-   Cursor  
  
-   Toolbar  
  
 A função de visualização visual não se aplica aos recursos do Accelerator, manifesto, tabela de cadeia de caracteres e as informações de versão.  
  
### Para visualizar recursos  
  
1.  Em  [Exibição de recurso](../windows/resource-view-window.md) ou uma janela de documento, selecione o recurso, por exemplo, IDD\_ABOUTBOX ÿ100,23523.  
  
     **Nota** se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No  [janela Propriedades do](../Topic/Properties%20Window.md), clique no  **Páginas de propriedades** botão.  
  
     \- ou \-  
  
3.  No menu **View**, clique em **Property Pages**.  
  
     A página de propriedades para o recurso abre exibindo uma visualização do recurso.  Você pode usar de cima e para baixo as teclas de seta para navegar no modo de exibição de recursos ou na janela de documento, o controle de árvore.  A página de propriedades será devem permanecer aberta e mostrar todos os recursos que tem foco e é capaz de ser visualizado.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Como abrir o arquivo de script do recurso fora de um projeto \(autônomo\)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)   
 [Editores de recursos](../mfc/resource-editors.md)