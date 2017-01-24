---
title: "Criando um menu | Microsoft Docs"
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
  - "vc.editors.menu"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mnemônicos, associando itens de menu"
  - "menus, associando comandos a teclas mnemônicas"
  - "menus, criando"
ms.assetid: 66f94448-9b97-4b73-bf97-10d4bf87cc65
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um menu
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A janela de recurso não está disponível nas edições Express.  
  
### Para criar um menu padrão  
  
1.  Do **exibição** menu, clique na **exibição recursos** e, em seguida, clique no **Menu** título e escolha **Adicionar recurso**. Escolha **Menu**.  
  
2.  Selecione o **Novo Item** caixa \(o retângulo que contém "Digite aqui"\) na barra de menus.  
  
     ![Nova caixa de Item de Menu Editor do Visual Studio](../Image/vcMenuEditorNewItemBox.gif "vcMenuEditorNewItemBox")  
Caixa de novo Item  
  
3.  Digite um nome para o novo menu, por exemplo, "Arquivo".  
  
     O texto digitado aparece no **Menu** editor e no **legenda** caixa a [janela propriedades](../Topic/Properties%20Window.md). Você pode editar as propriedades para o novo menu em qualquer local.  
  
     Depois de você ter recebe um nome do seu novo menu na barra de menus, a caixa novo item desloca para a direita \(para permitir que você adicione outro menu\) e abre outra caixa de novo item abaixo de seu primeiro menu assim você pode adicionar comandos de menu a ele.  
  
     ![Caixa de novo Item expandida](../windows/media/vcmenueditornewitemboxexpanded.png "vcMenuEditorNewItemBoxExpanded")  
Caixa de novo Item com foco deslocado após digitar o nome de Menu  
  
    > [!NOTE]
    >  Para criar um único item de menu na barra de menus, defina a propriedade de pop\-up como False.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de menu](../Topic/Menu%20Editor.md)