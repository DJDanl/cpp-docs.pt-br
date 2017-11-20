---
title: "Especificador de classe de armazenamento estática | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- static variables, specifier
- storage classes, static
- static storage class specifiers
ms.assetid: 9bce361e-919b-46b9-8148-40d7ab0eb024
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0a51dfc10ac0ae05a67a280b4b76c2c92eb57a0b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="static-storage-class-specifier"></a>Especificador de classe de armazenamento estático
Uma variável declarada no nível interno com o especificador de classe de armazenamento **static** tem um tempo de vida global, mas pode ser visto somente dentro do bloco em que é declarado. Para cadeias de caracteres constantes, usar **static** é útil porque reduz a sobrecarga de inicializações frequentes nas funções chamadas com frequência.  
  
## <a name="remarks"></a>Comentários  
Se você não inicializar explicitamente uma variável **static**, ela será inicializada como 0 por padrão. Dentro de uma função, **static** faz com que o armazenamento seja alocado e sirva como uma definição. As variáveis estáticas internas fornecem armazenamento particular e permanente que só pode ser visto por uma única função.  
  
## <a name="see-also"></a>Consulte também  
[Classes de armazenamento C](c-storage-classes.md)  
[Classes de armazenamento (C++)](../cpp/storage-classes-cpp.md)  