---
title: C2919 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2919
dev_langs:
- C++
helpviewer_keywords:
- C2919
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a70b679d4add5fa4ad2904e3c0d103e1c8881280
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2919"></a>C2919 de erro do compilador
'type': operadores não podem ser usados na superfície publicada de um tipo WinRT  
  
 O sistema de tipos do tempo de execução do Windows não oferece suporte a funções de membro do operador na superfície publicada de um tipo. Isso ocorre porque nem todos os idiomas podem consumir funções de membro do operador. Você pode criar funções de membro que podem ser chamadas de código C++ na mesma unidade de compilação ou a classe do operador privada ou interna.  
  
 Para corrigir esse problema, remova a função de membro do operador na interface pública ou alterá-la para uma função de membro nomeado. Por exemplo, em vez de `operator==`, nomear a função de membro `Equals`.
