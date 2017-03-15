---
title: "Erros de posição do arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- file pointers [C++], file position errors
ms.assetid: d5e59d8b-08c0-4927-a338-0b2d8234ce24
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: bd1a22e881c58423e21d8c37cea92d59f564f65f
ms.lasthandoff: 02/25/2017

---
# <a name="file-position-errors"></a>Erros de posição do arquivo
**ANSI 4.9.9.1, 4.9.9.4** O valor para o qual a macro `errno` é definida pela função `fgetpos` ou `ftell` em caso de falha  
  
 Quando `fgetpos` ou `ftell` falha, `errno` é definido como a contaste de manifesto `EINVAL` se a posição for inválida ou EBADF, se o número do arquivo estiver incorreto. As constantes também são definidas em ERRNO.H.  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)
