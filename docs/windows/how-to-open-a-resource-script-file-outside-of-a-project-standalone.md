---
title: "Como abrir o arquivo de script do recurso fora de um projeto (aut&#244;nomo) | Microsoft Docs"
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
  - "vc.editors.resource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .rc, exibindo recursos"
  - "arquivos rc, exibindo recursos"
  - "arquivos de script de recurso, exibindo recursos"
  - "recursos [Visual Studio], exibindo"
ms.assetid: bc350c60-178d-4c5d-9a7e-6576b0c936e4
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como abrir o arquivo de script do recurso fora de um projeto (aut&#244;nomo)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode exibir os recursos em um arquivo. rc sem ter que abrir um projeto.  O arquivo. RC será aberto em uma janela de documento em vez de abertura de [exibição de recurso](../windows/resource-view-window.md) janela \(como quando o arquivo é aberto dentro de um projeto\).  
  
> [!NOTE]
>  Essa é uma distinção importante porque alguns comandos estão disponíveis somente quando o arquivo é aberto autônomo \(fora de um projeto\).  Por exemplo, você só pode salvar um arquivo em um formato diferente ou como um nome de arquivo diferente quando o arquivo é aberto fora de um projeto \(o **Salvar como** comando não está disponível quando um arquivo é aberto dentro de um projeto\).  
  
### Para abrir um arquivo. rc fora de um projeto  
  
1.  Do **arquivo** menu, escolha **Abrir**, em seguida, clique em **arquivo**.  
  
2.  No **Abrir arquivo** caixa de diálogo caixa, navegue até o arquivo de script de recurso que você deseja exibir, realce o arquivo e clique em **Abrir**.  
  
    > [!NOTE]
    >  Se você abrir o projeto primeiro \(**arquivo**, **Abrir**, **projeto**\), alguns comandos não estarão disponíveis para você.  Abrir um arquivo "autônomo" significa abri\-lo sem primeiro carregar o projeto.  
  
 Para abrir e exibir o arquivo de recurso em formato de texto, consulte [editando um Script de recurso \(. rc\) arquivo](../windows/how-to-open-a-resource-script-file-in-text-format.md).  
  
#### Para abrir vários arquivos. rc fora de um projeto  
  
1.  Abra dois arquivos autônomos.  Por exemplo, abra Source1.rc e Source2.rc.  
  
    1.  Do **arquivo** menu, escolha **Abrir**, em seguida, clique em **arquivo**.  
  
    2.  No **Abrir arquivo** caixa de diálogo caixa, navegue até o primeiro arquivo de script de recurso que deseja abrir \(Source1.rc\), realce o arquivo e clique em **Abrir**.  
  
    3.  Repita a etapa anterior para abrir o segundo arquivo. RC \(Source2.rc\).  
  
         Os arquivos. rc agora estão abertos em janelas de documentos separados.  
  
2.  Quando ambos os arquivos. rc estão abertos, lado a lado as janelas para que você pode exibir simultaneamente:  
  
    -   Do **janela** menu, escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais**.  
  
         \-ou\-  
  
    -   Clique em um dos arquivos. RC e escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais** no menu de atalho.  
  
> [!NOTE]
>  Se seu projeto ainda não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 Win32  
  
## Consulte também  
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)