---
title: "Existe uma perda de mem&#243;ria na minha DLL regular, mas meu c&#243;digo parece bom. Como posso encontrar a perda de mem&#243;ria? | Microsoft Docs"
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
  - "DLLs [C++], perdas de memória"
  - "perdas de memória [C++], DLLs"
ms.assetid: a5d76573-b567-4b6a-8303-dafeeed9204d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Existe uma perda de mem&#243;ria na minha DLL regular, mas meu c&#243;digo parece bom. Como posso encontrar a perda de mem&#243;ria?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma possível causa de vazamento de memória é que o MFC cria objetos temporários usados dentro das funções do manipulador de mensagens.  Na DLL regulares, o MFC não libera automaticamente a memória alocada para esses objetos.  Para obter mais informações, consulte [Gerenciamento de memória e o heap de depuração](http://msdn.microsoft.com/pt-br/34dc6ef6-31c9-460e-a2a7-15e7f8e3334b) ou o artigo da Base de Dados de Conhecimento, “limpando o MFC temporário os objetos de DLL de \_USRDLL” \(Q105286\).  
  
 Observe que o termo está USRDLL mais utilizado na documentação do Visual C\+\+.  Uma DLL normal que é vinculado ao estaticamente MFC tem as mesmas características do USRDLL antigo.  Subsídio no artigo da Base de Dados de Conhecimento também se aplica a DLL regulares que são vinculados ao dinamicamente MFC.  As informações no artigo da Base de Dados de Conhecimento anterior se aplica a DLL regulares que vinculam estaticamente MFC ao e a DLL regulares que vinculam dinamicamente ao MFC.  
  
## Consulte também  
 [Perguntas frequentes sobre DLL](../build/dll-frequently-asked-questions.md)