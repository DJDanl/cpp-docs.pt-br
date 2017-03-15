---
title: "Como abrir o arquivo de script do recurso no formato de texto | Microsoft Docs"
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
  - "Arquivos .rc, abrindo no formato de texto"
  - "arquivos rc, abrindo no formato de texto"
  - "arquivos de script de recurso, abrindo no formato de texto"
ms.assetid: 0bc57527-f53b-40c9-99a9-4dcbc5c9af57
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como abrir o arquivo de script do recurso no formato de texto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Pode haver ocasiões quando desejar exibir o conteúdo do arquivo de script \(. rc\) do recurso do projeto sem abrir um recurso, como uma caixa de diálogo dentro do editor de recurso específico.  Por exemplo, convém procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recurso sem precisar abrir cada um deles separadamente.  
  
> [!NOTE]
>  Se seu projeto ainda não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
 Você pode facilmente abrir o arquivo de recurso em formato de texto para exibir todos os recursos que ele contém e executem operações globais com suporte a [editor de texto](http://msdn.microsoft.com/pt-br/508e1f18-99d5-48ad-b5ad-d011b21c6ab1).  
  
> [!NOTE]
>  Os editores de recursos não diretamente lêem arquivos. rc ou resource.h.  O compilador de recurso compila em arquivos de .aps, que são consumidos por editores de recursos.  Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos.  Como com um normal compilar o processo, as informações que não seja simbólicas \(por exemplo, comentários\) são descartadas durante o processo de compilação.  Sempre que o arquivo .aps fica fora de sincronia com o arquivo. RC, no arquivo. RC é regenerado \(por exemplo, quando você salva, o resource editor substitui o arquivo. RC e o resource.h\).  Todas as alterações aos próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC será substituído.  Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../Topic/How%20to:%20Include%20Resources%20at%20Compile%20Time.md).  
  
### Para abrir um arquivo de script de recurso como texto  
  
1.  Do **arquivo** menu escolha **Abrir**, em seguida, clique em **arquivo.**  
  
2.  No **Abrir arquivo** caixa de diálogo caixa, navegue até o arquivo de script de recurso que você deseja exibir no formato de texto.  
  
3.  Realce o arquivo, clique na seta suspensa no **Abrir** botão \(localizado à direita do botão\).  
  
4.  Escolha **Abrir com** no menu suspenso.  
  
5.  No **Abrir com** caixa de diálogo, clique em **Editor de código\-fonte \(texto\)**.  
  
6.  Do **Abrir como** lista suspensa, selecione **texto**.  
  
     O recurso é aberto no editor de código\-fonte.  
  
 \-ou\-  
  
1.  Em **Solution Explorer**, com o botão direito no arquivo. rc.  
  
2.  No menu de atalho, escolha **Abrir com...**, em seguida, selecione **Editor de código\-fonte \(texto\)**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)