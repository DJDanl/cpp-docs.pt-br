---
title: Testes de caractere | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 376ba061-bae3-427e-9569-33fa5949a199
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: ca3c90169a3dab061a1e50e838b3432deec77b0c
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="character-testing"></a>Testes de caractere
**ANSI 4.3.1** Os conjuntos de caracteres testados pelas funções `isalnum`, `isalpha`, `iscntrl`, `islower`, `isprint` e `isupper`  
  
 A lista a seguir descreve essas funções como são implementadas pelo compilador Microsoft C.  
  
|Função|Testes para|  
|--------------|---------------|  
|`isalnum`|Caracteres 0 – 9, A–Z, a–z ASCII 48– 57, 65– 90, 97– 122|  
|`isalpha`|Caracteres A–Z, a–z ASCII 65–90, 97–122|  
|`iscntrl`|ASCII 0 – 31, 127|  
|`islower`|Caracteres A–Z ASCII 97–122|  
|`isprint`|Caracteres A–Z, a–z, 0 – 9, pontuação, espaço ASCII 32–126|  
|`isupper`|Caracteres A–Z ASCII 65–90|  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)
