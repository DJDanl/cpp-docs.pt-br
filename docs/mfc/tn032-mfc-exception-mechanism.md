---
title: "TN032: mecanismo de exce&#231;&#227;o MFC | Microsoft Docs"
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
  - "vc.mfc.exceptions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CException, usando"
  - "MFC, exceções"
  - "TN032"
ms.assetid: 0271f0aa-82cb-47a2-b7ea-e88126fc7e43
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN032: mecanismo de exce&#231;&#227;o MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As versões anteriores do Visual C\+\+ não ofereciam suporte ao mecanismo de exceção padrão do C\+\+, e macros MFC fornecidos **TRY\/CATCH\/THROW** que foram usados no lugar.  Esta versão do Visual C\+\+ aceita completamente exceções C\+\+.  Essa observação cobrisse alguns dos detalhes de implementação avançadas de macros anteriores que incluem automaticamente como objetos baseados pilha de limpeza.  Como a pilha das exceções C\+\+ que desenrola por padrão, essa técnica observe que não é mais necessário.  
  
 Consulte [Exceções: Usando macros de MFC e exceções C\+\+](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) para obter mais informações sobre as diferenças entre as macros MFC e as novas palavras\-chave C\+\+.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)