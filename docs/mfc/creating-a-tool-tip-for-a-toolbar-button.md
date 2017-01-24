---
title: "Criando uma dica de ferramenta para um bot&#227;o da barra de ferramentas | Microsoft Docs"
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
  - "\n em dica de ferramenta"
  - "botões [C++], dicas de ferramenta"
  - "dicas de ferramenta [C++], adicionando a botões de barra de ferramentas"
  - "botões da barra de ferramentas [C++], dicas de ferramenta"
  - "Editor da barra de ferramentas, criando dicas de ferramenta"
ms.assetid: 0af65342-fd78-4e78-8d0d-dc68f7fc462e
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando uma dica de ferramenta para um bot&#227;o da barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para criar uma dica de ferramenta  
  
1.  Selecione o botão de barra de ferramentas.  
  
2.  No  [Janela Propriedades](../Topic/Properties%20Window.md), no  **Prompt** propriedade de campo, adicione uma descrição do botão da barra de status; Após a mensagem, adicione \\ n e o nome da dica de ferramenta.  
  
 Um exemplo comum de uma dica de ferramenta é o botão Imprimir no WordPad:  
  
 1.  Abrir o WordPad.  
  
 2.  Passe o ponteiro do mouse sobre o  **Print** o botão de barra de ferramentas.  
  
 3.  Observe que a palavra 'Imprimir' agora é flutuante sob o ponteiro do mouse.  
  
 4.  Observe a barra de status \(na parte inferior da janela do WordPad\) – Observe que ela agora mostra o texto "Imprime o documento ativo".  
  
 'Imprimir' na etapa 3 é o "nome de dica de ferramenta" e o 'imprime o documento ativo ' da etapa 4 é a "Descrição do botão da barra de status de".  
  
 Se desejar esse efeito usando o  **barra de ferramentas** editor, defina a  **Prompt** propriedade para  **imprime o ativo document\\nPrint**.  
  
> [!NOTE]
>  Você pode editar o texto de aviso usando o  [Janela Propriedades do](../Topic/Properties%20Window.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 MFC ou ATL  
  
## Consulte também  
 [Criando, movendo e editando botões da barra de ferramentas](../mfc/creating-moving-and-editing-toolbar-buttons.md)   
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)