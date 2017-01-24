---
title: "Exibindo e edificando recursos em um Editor de Recurso | Microsoft Docs"
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
  - "vs.resourceview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .rc, exibindo recursos"
  - "código, exibindo recursos"
  - "layouts, visualizando recurso"
  - "arquivos rc, exibindo recursos"
  - "editores de recursos, exibindo recursos"
  - "Painel Modo de Exibição de Recursos"
  - "recursos [Visual Studio], edição"
  - "recursos [Visual Studio], exibindo"
ms.assetid: ba8bdc07-3f60-43c7-aa5c-d5dd11f0966e
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exibindo e edificando recursos em um Editor de Recurso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada tipo de recurso tem um editor de recursos específico para esse tipo de recurso.  Você pode reorganizar, redimensionar, adicionar controles e recursos ou modificar aspectos de um recurso usando o editor associado.  Você também pode editar um recurso em  [formato de texto](../windows/how-to-open-a-resource-script-file-in-text-format.md) e  [formato binário](../mfc/opening-a-resource-for-binary-editing.md).  
  
 Alguns tipos de recursos estão arquivos individuais que podem ser importados e usados de várias maneiras; Eles incluem bitmaps, ícones, cursores, barras de ferramentas e arquivos html.  Esses recursos têm nomes de arquivo, bem como  [identificadores de recurso](../mfc/symbols-resource-identifiers.md).  Outros, como, por exemplo, caixas de diálogo, menus e tabelas de cadeia de caracteres em projetos do Win32, existem apenas como parte de um arquivo de script \(. rc\) do recurso ou um arquivo de modelo \(. rct\) do recurso.  
  
> [!NOTE]
>  Propriedades de um recurso  [pode ser modificado usando a janela Propriedades do](../windows/changing-the-properties-of-a-resource.md).  
  
## Recursos do Win32  
 Você pode acessar os recursos do Win32 no  [Exibição de recurso](../windows/resource-view-window.md) painel.  
  
#### Para exibir um recurso do Win32 em um editor de recurso  
  
1.  Selecione  **Exibição de recurso** da  **Exibir** menu.  
  
2.  Se a janela de exibição de recurso não é o mais alto, clique no  **Exibição de recurso** guia para trazê\-la para a parte superior.  
  
3.  No modo de exibição de recursos, expanda a pasta para o projeto que contém recursos que você deseja exibir.  Por exemplo, se você quiser visualizar um recurso de caixa de diálogo, expanda a pasta de caixa de diálogo.  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
4.  Clique duas vezes o recurso, por exemplo, IDD\_ABOUTBOX ÿ100,23523.  
  
     O recurso abre no editor apropriado.  Por exemplo, para os recursos de caixa de diálogo, o recurso abre dentro do editor de diálogo.  
  
     Você também pode  [Exibir recursos em um arquivo de. rc \(script de recurso\) sem a necessidade de um projeto aberto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
#### Para excluir um recurso de 32 bits do Windows existente  
  
1.  No modo de exibição de recursos, expanda o nó para um tipo de recurso.  
  
2.  Clique com o botão direito no recurso que deseja excluir e escolha  **Excluir** no menu de atalho.  
  
    > [!NOTE]
    >  Você pode excluir um recurso usando o mesmo comando de menu de atalho quando o arquivo. rc aberta em uma janela de documento fora de um projeto.  
  
## Recursos em projetos gerenciados  
 Porque os projetos gerenciados não usam os arquivos de script de recurso, você deve abrir seus recursos de  **Solution Explorer**.  Você pode usar o  [editor de imagens](../mfc/image-editor-for-icons.md) e o  [editor binário](../mfc/binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados.  Quaisquer recursos gerenciados que você deseja editar devem ser recursos vinculados.  Os editores de recursos de Visual Studio não têm suporte para a edição de recursos incorporados.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
#### Para exibir um recurso gerenciado em um editor de recurso  
  
1.  No Solution Explorer, clique duas vezes o recurso, por exemplo, Bitmap1.bmp.  
  
     O recurso abre no editor apropriado.  
  
#### Para excluir um recurso gerenciado existente  
  
1.  No Solution Explorer, clique com o botão direito no recurso que deseja excluir e escolha  **Excluir** no menu de atalho.  
  
### Requisitos  
 Nenhum  
  
## Consulte também  
 [Editores de recursos](../mfc/resource-editors.md)