---
title: "Caixa de di&#225;logo Recurso Inclui | Microsoft Docs"
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
  - "vc.editors.resourceincludes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .rc, alterando armazenamento"
  - "compilando o código-fonte, incluindo recursos"
  - "arquivos rc, alterando armazenamento"
  - "Caixa de diálogo Recurso Inclui"
  - "arquivos de cabeçalho de símbolo, alterando"
  - "arquivos de cabeçalho de símbolo, somente leitura"
  - "símbolos, arquivos de cabeçalho de símbolo"
ms.assetid: 659a54e6-e416-4045-8411-798730ff4ce3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixa de di&#225;logo Recurso Inclui
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar o **recurso inclui** caixa de diálogo para modificar a disposição de trabalho normal do ambiente de armazenamento de todos os recursos no arquivo. rc projeto e todos os [símbolos](../mfc/symbols-resource-identifiers.md) em Resource.h.  
  
 Para abrir o **inclui recursos** caixa de diálogo, clique uma RC do arquivo em [exibição recurso](../windows/resource-view-window.md), escolha **recurso inclui** no menu de atalho.  
  
 **Arquivo de cabeçalho de símbolo**  
 Permite que você altere o nome do arquivo de cabeçalho onde as definições de símbolo para o arquivo de recurso são armazenadas.  Para obter mais informações, consulte [alterando os nomes dos arquivos de cabeçalho do símbolo](../windows/changing-the-names-of-symbol-header-files.md).  
  
 **Diretivas de símbolo somente leitura**  
 Permite que você inclua arquivos de cabeçalho que contêm símbolos que não devem ser modificados durante uma sessão de edição.  Por exemplo, você pode incluir um arquivo de símbolo que é compartilhado entre vários projetos.  Você também pode incluir arquivos do MFC. h.  Para obter mais informações, consulte [incluindo compartilhados \(somente leitura\) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md).  
  
 **Diretivas de tempo de compilação**  
 Permite que você inclua arquivos de recursos que são criados e editados separadamente dos recursos em seu arquivo de recurso principal, contêm diretivas de tempo de compilação \(como aquelas que incluem condicionalmente recursos\) ou contêm recursos em um formato personalizado.  Você também pode usar a caixa de diretivas de tempo de compilação para incluir arquivos de recursos padrão do MFC.  Para obter mais informações, consulte [incluindo recursos em tempo de compilação](../Topic/How%20to:%20Include%20Resources%20at%20Compile%20Time.md).  
  
> [!NOTE]
>  Entradas nessas caixas de texto aparecem no arquivo. rc marcado por `TEXTINCLUDE 1`, `TEXTINCLUDE 2`, e `TEXTINCLUDE 3` respectivamente.  Para obter mais informações, consulte [TN035: usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C\+\+](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md).  
  
 Depois de fazer alterações em seu arquivo de recursos usando o **recurso inclui** caixa de diálogo, você precisa fechar o arquivo. RC e reabri\-lo para que as alterações entrem em vigor.  Para obter mais informações, consulte [incluindo recursos em tempo de compilação](../Topic/How%20to:%20Include%20Resources%20at%20Compile%20Time.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Como especificar diretórios de inclusão para recursos](../windows/how-to-specify-include-directories-for-resources.md)   
 [Símbolos: Identificadores de recursos](../mfc/symbols-resource-identifiers.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)