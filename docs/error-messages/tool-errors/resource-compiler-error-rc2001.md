---
title: RC2001 de erro do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC2001
dev_langs:
- C++
helpviewer_keywords:
- RC2001
ms.assetid: 92bfb4c0-1879-4606-bb9f-ef7368707b4a
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ba9e855e61af80d29a682738a3f04377f49b6bdf
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-error-rc2001"></a>Erro RC2001 (compilador de recurso)
newline em constante  
  
 Uma constante de cadeia de caracteres foi retomada em uma segunda linha sem uma barra invertida (**\\**) ou fechar e abrir as aspas duplas (**"**).  
  
 Para interromper uma constante de cadeia de caracteres que é em duas linhas no arquivo de origem, siga um destes procedimentos:  
  
-   Finalizar a primeira linha com o caractere de continuação de linha, uma barra invertida.  
  
-   Feche a cadeia de caracteres na primeira linha com aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa.  
  
 Não é suficiente encerrar a primeira linha com \n, a sequência de escape para inserir um caractere de nova linha em uma constante de cadeia de caracteres.
