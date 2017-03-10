---
title: "Especificador de classe de armazenamento estática | Microsoft Docs"
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
- static variables, specifier
- storage classes, static
- static storage class specifiers
ms.assetid: 9bce361e-919b-46b9-8148-40d7ab0eb024
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
ms.openlocfilehash: 34f60570d18882ddfb7ebef78977d6b2f5c82000
ms.lasthandoff: 02/25/2017

---
# <a name="static-storage-class-specifier"></a>Especificador de classe de armazenamento estático
Uma variável declarada no nível interno com o especificador de classe de armazenamento **static** tem um tempo de vida global, mas pode ser visto somente dentro do bloco em que é declarado. Para cadeias de caracteres constantes, usar **static** é útil porque reduz a sobrecarga de inicializações frequentes nas funções chamadas com frequência.  
  
## <a name="remarks"></a>Comentários  
Se você não inicializar explicitamente uma variável **static**, ela será inicializada como 0 por padrão. Dentro de uma função, **static** faz com que o armazenamento seja alocado e sirva como uma definição. As variáveis estáticas internas fornecem armazenamento particular e permanente que só pode ser visto por uma única função.  
  
## <a name="see-also"></a>Consulte também  
[Classes de armazenamento C](c-storage-classes.md)  
[Classes de armazenamento (C++)](../cpp/storage-classes-cpp.md)  
