---
title: C3446 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 07/21/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3446
dev_langs: C++
helpviewer_keywords: C3445
ms.assetid: 33064548-24e4-46f1-beb1-476e3c3b3fbf
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1147c83a0cdd1519b56f862312b721d0db54540b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3446"></a>C3446 de erro do compilador  
  
>'*classe*': um inicializador de membro padrão não é permitido para um membro de uma classe de valor  
  
No Visual Studio 2015 e nas versões anteriores, o compilador permitia (mas ignorava) um inicializador de membro padrão para um membro de uma classe de valor. A inicialização padrão de uma classe de valor sempre inicializa os membros em zero; um construtor padrão não é permitido. No Visual Studio 2017, os inicializadores de membro padrão geram um erro de compilador, conforme mostrado neste exemplo:

## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3446 no Visual Studio de 2017 e posterior:  
  
```cpp  
// C3446.cpp  
value struct V
{
       int i = 0; // error C3446: 'V::i': a default member initializer  
                  // is not allowed for a member of a value class
       int j {0}; // C3446           
};
```  
  
Para corrigir o erro, remova o inicializador de:  
  
```cpp  
// C3446b.cpp  
value struct V
{
       int i;  
       int j;
};
```  
  
