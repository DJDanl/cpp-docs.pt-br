---
title: "Avalia&#231;&#227;o de tokens | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "tokens, avaliando"
ms.assetid: 28870b62-dff6-4644-8b75-d58f340b48d2
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Avalia&#231;&#227;o de tokens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando o compilador interpreta tokens, ele inclui o máximo de caracteres possível em um único token antes seguir para o próximo token.  Devido a esse comportamento, o compilador pode não interpretar tokens como você gostaria se eles não forem separados corretamente por um espaço em branco.  Considere a seguinte expressão:  
  
```  
i+++j  
```  
  
 Neste exemplo, o compilador primeiro cria o operador mais longo possível \(`++`\) dos três sinais positivos, depois processa o sinal de positivo restante como um operador de adição \(`+`\).  Assim, a expressão é interpretada como `(i++) + (j)`, não `(i) + (++j)`.  Nesse e em casos semelhantes, use espaço em branco e parênteses para evitar ambiguidade e assegurar a avaliação apropriada da expressão.  
  
 **Específico da Microsoft**  
  
 O compilador C trata um caractere CTRL\+Z como um indicador de fim do arquivo.  Ignora qualquer texto após CTRL\+Z.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Tokens C](../c-language/c-tokens.md)