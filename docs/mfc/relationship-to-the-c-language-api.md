---
title: "Relacionamento com a API da linguagem C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "livros [C++]"
  - "livros [C++], sobre MFC e Windows SDK"
  - "MFC [C++], API do Windows"
  - "Visual C, Chamadas à API do Windows"
  - "API do Windows [C++], e MFC"
ms.assetid: 334e8efc-f3cc-4018-bc2e-02908b2a39fe
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Relacionamento com a API da linguagem C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A única característica que define a biblioteca de \(MFC\) de classes do Microsoft foundation independentemente de outras bibliotecas da classe para o windows é o mapeamento muito próximo a API do windows escrito em C \- idioma.  Além disso, normalmente é possível misturar as chamadas a biblioteca de classes livremente com chamadas à API do windows.  Esse acesso direto, porém, não significa que as classes têm uma substituição completo para o API.  Os desenvolvedores devem ainda ocasionalmente fazer chamadas às funções de algumas janelas, como [SetCursor](http://msdn.microsoft.com/library/windows/desktop/ms648393) e [GetSystemMetrics](http://msdn.microsoft.com/library/windows/desktop/ms724385), por exemplo.  Uma função do windows está envolvida por uma função de membro da classe apenas quando há uma melhoria clara a fazer isso.  
  
 Como às vezes você precisa de fazer chamadas de função nativos do windows, você deve ter acesso à documentação da API do windows do C \- idioma.  Esta documentação é incluída com o Microsoft Visual C\+\+.  
  
> [!NOTE]
>  Para obter uma visão geral de como a estrutura de biblioteca MFC opera, consulte [Usando as classes para gravar aplicativos do windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md).  
  
## Consulte também  
 [Filosofia de design da classe geral](../mfc/general-class-design-philosophy.md)