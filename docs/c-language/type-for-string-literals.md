---
title: Tipo para literais da cadeia de caracteres | Microsoft Docs
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
- string literals, type
- types [C], string literals
ms.assetid: f50a28af-20c1-4440-bdc6-564c86a309c8
caps.latest.revision: 7
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
ms.openlocfilehash: 92446901a1042ecd064fed6d3a8e647a9f406e29
ms.lasthandoff: 02/25/2017

---
# <a name="type-for-string-literals"></a>Tipo para literais da cadeia de caracteres
As literais da cadeias de caracteres têm a matriz do tipo `char` (ou seja, **char[ ]**). (As cadeias de caracteres amplos têm a matriz do tipo `wchar_t` (ou seja, **wchar_t[ ]**)). Isso significa que uma cadeia de caracteres é uma matriz com elementos do tipo `char`. O número de elementos na matriz é igual ao número de caracteres na cadeia de caracteres mais um, para o caractere nulo de encerramento.  
  
## <a name="see-also"></a>Consulte também  
 [Literais da cadeia de caracteres C](../c-language/c-string-literals.md)
