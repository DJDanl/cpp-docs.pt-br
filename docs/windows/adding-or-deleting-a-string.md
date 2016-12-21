---
title: "Adicionando ou excluindo uma cadeia de caracteres | Microsoft Docs"
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
  - "vc.editors.string"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tabelas de cadeias de caracteres, adicionando cadeias de caracteres"
  - "tabelas de cadeias de caracteres, excluindo cadeias de caracteres"
  - "cadeias de caracteres [C++], adicionando a tabelas de cadeias de caracteres"
  - "cadeias de caracteres [C++], excluindo em tabelas de cadeias de caracteres"
ms.assetid: 077077b4-0f4b-4633-92d6-60b321164cab
caps.latest.revision: 11
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando ou excluindo uma cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode inserir rapidamente novas entradas na tabela de cadeia de caracteres usando o editor de seqüência de caracteres.  Novas seqüências de caracteres são colocadas no final da tabela e recebem o próximo identificador disponível.  Você pode editar as propriedades de identificação, valor ou legenda no  [janela Propriedades do](../Topic/Properties%20Window.md) conforme necessário.  
  
 O editor de seqüência certifica\-se de que não usar uma identificação que já está em uso.  Se você selecionar uma ID já em uso, o editor de seqüência irá notificá\-lo e, em seguida, atribuir uma ID exclusiva genérica, por exemplo IDS\_STRING58113.  
  
### Para adicionar uma entrada de tabela de cadeia de caracteres  
  
1.  Abra a tabela de cadeia de caracteres clicando duas vezes no ícone correspondente na  [Exibição de recurso](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Clique com o botão direito dentro da tabela de cadeia de caracteres e escolha  **Nova cadeia de caracteres** no menu de atalho.  
  
3.  No  **seqüência de caracteres** editor, selecione um  **ID** na lista drop\-down de ID ou digite um local de diretamente no ID.  
  
4.  Editar o  **valor**, se necessário.  
  
5.  Digite uma entrada para o  **legenda**.  
  
    > [!NOTE]
    >  Seqüências de caracteres nulas não são permitidas em tabelas de cadeia de caracteres do Windows.  Se você criar uma entrada na tabela de cadeia de caracteres que é uma seqüência nula, você receberá uma mensagem pedindo para "Insira uma seqüência de caracteres para esta entrada da tabela."  
  
### Para excluir uma entrada de tabela de cadeia de caracteres  
  
1.  Selecione a entrada que você deseja excluir.  
  
2.  Sobre o  **Editar** menu, clique em  **Excluir**.  
  
 \- ou \-  
  
-   Clique com o botão direito a seqüência de caracteres que você deseja excluir e escolha  **Excluir** no menu de atalho.  
  
 \- ou \-  
  
-   Pressione o  **Excluir** chave.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados \(aquelas que visam common language runtime\), consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de Cadeia de Caracteres](../mfc/string-editor.md)   
 [Seqüências de caracteres](_win32_Strings)   
 [sobre seqüências de caracteres](_win32_About_Strings_cpp)