---
title: "Manipuladores de mensagens | Microsoft Docs"
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
  - "tratamento de comandos, manipuladores de mensagens"
  - "manipuladores"
  - "manipuladores, comando"
  - "manipuladores,  (mensagem)"
  - "manipuladores de mensagens"
  - "lidando com erros, funções de manipulador de mensagens"
ms.assetid: 51bc4e76-dbe3-4cc2-b026-3199d56b2fa9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de mensagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC no, uma função dedicada *do manipulador* processa cada mensagem separadamente.  As funções são retornadas a funções de membro de uma classe.  Esta documentação usa *a função de membro retornadas aos*termos, *a função retornadas a*, *o manipulador de mensagens*, e *o manipulador* alternadamente.  Alguns tipos de manipuladores de mensagem também são denominados “manipuladores de comando.”  
  
 Os manipuladores de mensagem de gravação para uma grande proporção do trabalho ao escrever um aplicativo da estrutura.  Esta família do artigo descreve como o mecanismo retornadas processamento trabalha.  
  
 Que o manipulador para uma mensagem faz?  Faz o que você deseja fazer em resposta à mensagem.  Você pode criar manipuladores usando a janela Propriedades da classe, e preenche o código do manipulador usando o editor de origem.  
  
 Você pode usar todas as instalações do Microsoft Visual C\+\+ e MFC para gravar seus manipuladores.  Para obter uma lista de todas as classes, consulte [Visão geral da biblioteca de classes](../mfc/class-library-overview.md)*na referência de MFC*.  
  
## Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)