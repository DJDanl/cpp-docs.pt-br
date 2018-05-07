---
title: C2919 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2919
dev_langs:
- C++
helpviewer_keywords:
- C2919
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c5e2eb2a32f1a906814f5b347ba1ebf13eba71ff
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2919"></a>C2919 de erro do compilador
'type': operadores não podem ser usados na superfície publicada de um tipo WinRT  
  
 O sistema de tipos do tempo de execução do Windows não oferece suporte a funções de membro do operador na superfície publicada de um tipo. Isso ocorre porque nem todos os idiomas podem consumir funções de membro do operador. Você pode criar funções de membro que podem ser chamadas de código C++ na mesma unidade de compilação ou a classe do operador privada ou interna.  
  
 Para corrigir esse problema, remova a função de membro do operador na interface pública ou alterá-la para uma função de membro nomeado. Por exemplo, em vez de `operator==`, nomear a função de membro `Equals`.