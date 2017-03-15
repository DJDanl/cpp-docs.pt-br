---
title: "&#193;rea de Transfer&#234;ncia: usando a &#193;rea de Transfer&#234;ncia do Windows | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Área de Transferência [C++], comandos"
  - "Área de Transferência [C++], API da Área de Transferência do Windows"
  - "Comandos da Área de Transferência"
  - "Comandos da Área de Transferência, implementando"
  - "comandos [C++], implementando Editar"
  - "funções do manipulador de comando Recortar/Copiar e Colar"
  - "funções de manipulador, Comandos Recortar/Copiar e Colar"
  - "Área de Transferência do Windows [C++]"
ms.assetid: 24415b42-9301-4a70-b69a-44c97918319f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &#193;rea de Transfer&#234;ncia: usando a &#193;rea de Transfer&#234;ncia do Windows
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve como usar a área de transferência padrão apis do windows em seu aplicativo MFC.  
  
 A maioria dos aplicativos do windows oferecem suporte a dados recortar ou copiar para a área de transferência do windows e colar dados da área de transferência.  Os formatos de dados da área de transferência variam entre aplicativos.  A estrutura aceitar apenas um número limitado de formatos da área de transferência para um número limitado de classes.  Você implementará normalmente os comandos Área de transferência\- relacionados, copiar, — recortar e colar — no menu editar para sua exibição.  A biblioteca de classe define os IDs de comando para esses comandos: **ID\_EDIT\_CUT**, **ID\_EDIT\_COPY**, e **ID\_EDIT\_PASTE**.  A linha mensagem\- avisos também estiver definida.  
  
 [Mensagens e comandos na estrutura](../mfc/messages-and-commands-in-the-framework.md) explica como manipular comandos de menu em seu aplicativo mapeando o comando de menu a uma função de manipulador.  Como seu aplicativo não define o manipulador que as funções para a área de transferência comando no menu editar, ele permanecerá desabilitado.  Para escrever funções do manipulador para os comandos recortar e de cópia, implemente a seleção em seu aplicativo.  Para escrever uma função de manipulador para o comando de pasta, consulte a área de transferência para ver se contiver dados em um formato que seu aplicativo pode aceitar.  Por exemplo, para habilitar o comando de cópia, você pode gravar em um manipulador algo como:  
  
 [!CODE [NVC_MFCListView#2](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCListView#2)]  
  
 Os comandos recortar, copiar e, na pasta só são úteis em determinados contextos.  Os comandos recortar e de cópia deve ser habilitado apenas quando algo está selecionado e, o comando da pasta somente quando algo está na área de transferência.  Você pode fornecer este comportamento definindo as funções de manipulador de atualização que habilitam ou desabilitam esses comandos dependendo do contexto.  Para obter mais informações, consulte [Como atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md).  
  
 A biblioteca de classes do Microsoft fornece suporte da área de transferência para a edição de texto com as classes de `CEdit` e de `CEditView` .  As classes com OLE DB também simplificam implementar as operações da área de transferência que envolvem itens com OLE DB.  Para obter mais informações sobre classes OLE, consulte [Área de transferência: Usando o mecanismo OLE da área de transferência](../mfc/clipboard-using-the-ole-clipboard-mechanism.md).  
  
 Implementar outros comandos de menu editar, como desfazer \(**ID\_EDIT\_UNDO**\) e refazer \(**ID\_EDIT\_REDO**\), será deixado também.  Se seu aplicativo não oferece suporte a esses comandos, você pode facilmente excluí\-los do arquivo de recursos usando os editores de recursos do Visual C\+\+.  
  
## Que você deseja saber mais?  
  
-   [Copiando e colando dados](../Topic/Clipboard:%20Copying%20and%20Pasting%20Data.md)  
  
-   [Usando o mecanismo OLE da área de transferência](../mfc/clipboard-using-the-ole-clipboard-mechanism.md)  
  
## Consulte também  
 [Área de Transferência](../mfc/clipboard.md)