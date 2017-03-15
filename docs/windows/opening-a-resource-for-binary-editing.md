---
title: "Abrindo um recurso para edi&#231;&#227;o bin&#225;ria | Microsoft Docs"
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
  - "vc.editors.binary"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dados binários, edição"
  - "recursos [Visual Studio], abrindo para edição binária"
ms.assetid: d3cdb0e4-da66-410d-8e49-b29073ff2929
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Abrindo um recurso para edi&#231;&#227;o bin&#225;ria
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para abrir um recurso de área de trabalho do Windows para edição binária  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), selecione o arquivo de recurso específico que você deseja editar.  
  
    > [!NOTE]
    >  Se seu projeto ainda não contém um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  O recurso de atalho e clique em **Abrir dados binários** no menu de atalho.  
  
    > [!NOTE]
    >  Se você usar o [exibição recursos](../windows/resource-view-window.md) janela para abrir um recurso com um formato que o Visual Studio não reconhece \(como RCDATA ou um recurso personalizado\), o recurso é aberta automaticamente no editor binário.  
  
### Para abrir um recurso gerenciado para edição binária  
  
1.  No Solution Explorer, selecione o arquivo de recurso específico que você deseja editar.  
  
2.  O recurso de atalho e escolha **Abrir com** no menu de atalho.  
  
3.  No **Abrir com** caixa de diálogo, escolha **Editor binário**.  
  
    > [!NOTE]
    >  Você pode usar o [editor de imagem](../mfc/image-editor-for-icons.md) e [editor binário](../mfc/binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não dão suporte a edição de recursos inseridos.  
  
    > [!NOTE]
    >  Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 ![Editor do Visual Studio binário](../Image/vcBinaryEditor2.gif "vcBinaryEditor2")  
Dados binários de uma caixa de diálogo exibida no Editor binário  
  
 Apenas determinados valores ASCII são representados no editor binário \(0x20 através de 0x7E\). Caracteres estendidos são exibidos como pontos na seção de valor ASCII do editor binário \(painel direito\). Os caracteres "imprimíveis" são valores ASCII de 32 a 126.  
  
> [!NOTE]
>  Se você quiser usar o editor binário em um recurso que já está sendo editado em outra janela do editor, feche a janela do editor primeiro.  
  
 **Requisitos**  
  
 Nenhum  
  
## Consulte também  
 [Editor binário](../mfc/binary-editor.md)