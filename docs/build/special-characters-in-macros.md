---
title: Caracteres especiais em Macros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: special characters, in NMAKE macros
ms.assetid: c0a06cfc-7103-4ee2-a585-e8f6e85dccd7
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4d954abc593fcba3887da4f7ee4bd5ce1e443e18
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="special-characters-in-macros"></a>Caracteres especiais em macros
Um número entrar (#) depois que uma definição especifica um comentário. Para especificar um sinal numérico literal em uma macro, use um acento circunflexo (^), como em ^ #.  
  
 Um sinal de cifrão ($) especifica uma invocação de macro. Para especificar um $ literal, use $$.  
  
 Para estender uma definição para uma nova linha, finalizar a linha com uma barra invertida (\\). Quando a macro é chamada, o caractere de barra invertida e a nova linha é substituído por um espaço. Para especificar uma barra invertida literal no final da linha, preceda-o com um sinal de intercalação (^) ou segui-la com um especificador de comentário (#).  
  
 Para especificar um caractere literal, terminar com a linha com um sinal de intercalação (^), como:  
  
```  
CMDS = cls^  
dir  
```  
  
## <a name="see-also"></a>Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)