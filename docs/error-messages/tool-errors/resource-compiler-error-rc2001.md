---
title: RC2001 de erro do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: RC2001
dev_langs: C++
helpviewer_keywords: RC2001
ms.assetid: 92bfb4c0-1879-4606-bb9f-ef7368707b4a
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7c04110898780495f918c1e37c0068daead340a4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-error-rc2001"></a>Erro RC2001 (compilador de recurso)
nova linha em constante  
  
 Uma constante de cadeia de caracteres foi retomada em uma segunda linha sem uma barra invertida (**\\**) ou de abertura e fechamento aspas duplas (**"**).  
  
 Para interromper uma constante de cadeia de caracteres que é em duas linhas no arquivo de origem, siga um destes procedimentos:  
  
-   Finalizar a primeira linha com o caractere de continuação de linha, uma barra invertida.  
  
-   Feche a cadeia de caracteres na primeira linha com aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa.  
  
 Não é suficiente para terminar a primeira linha com \n, a sequência de escape para inserir um caractere de nova linha em uma constante de cadeia de caracteres.