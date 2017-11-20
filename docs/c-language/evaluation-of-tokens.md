---
title: "Avaliação de tokens | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: tokens, evaluating
ms.assetid: 28870b62-dff6-4644-8b75-d58f340b48d2
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 38fe88ba1db7e602844569733046cca99c86d4b3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="evaluation-of-tokens"></a>Avaliação de tokens
Quando o compilador interpreta tokens, ele inclui o máximo de caracteres possível em um único token antes seguir para o próximo token. Devido a esse comportamento, o compilador pode não interpretar tokens como você gostaria se eles não forem separados corretamente por um espaço em branco. Considere a seguinte expressão:  
  
```  
i+++j  
```  
  
 Neste exemplo, o compilador primeiro cria o operador mais longo possível (`++`) dos três sinais positivos, depois processa o sinal de positivo restante como um operador de adição (`+`). Assim, a expressão é interpretada como `(i++) + (j)`, não `(i) + (++j)`. Nesse e em casos semelhantes, use espaço em branco e parênteses para evitar ambiguidade e assegurar a avaliação apropriada da expressão.  
  
 **Seção específica da Microsoft**  
  
 O compilador C trata um caractere CTRL+Z como um indicador de fim do arquivo. Ignora qualquer texto após CTRL+Z.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Tokens C](../c-language/c-tokens.md)