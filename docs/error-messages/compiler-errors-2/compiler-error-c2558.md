---
title: C2558 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2558
dev_langs:
- C++
helpviewer_keywords:
- C2558
ms.assetid: 822b701e-dcae-423a-b21f-47f36aff9c90
caps.latest.revision: 12
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a90f045e600a8e130cd40218d588f5e26a5337e2
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2558"></a>C2558 de erro do compilador
'identificador': nenhum construtor de cópia disponível ou construtor de cópia declarado como 'explicit'  
  
 Um construtor de cópia inicializa um objeto a partir de outro objeto do mesmo tipo. (Faz uma cópia do objeto.) O compilador gerará um construtor de cópia padrão se você não definir nenhum construtor.  
  
### <a name="to-fix-this-error"></a>Para corrigir esse erro  
  
1.  O problema pode ocorrer quando é feita uma tentativa de copiar uma classe cujo construtor de cópia é `private`. Na maioria dos casos, uma classe que tem um construtor de cópia `private` não deve ser copiada. Uma técnica de programação comum declara um construtor de cópia `private` para evitar o uso direto de uma classe. A classe pode ser inútil isoladamente ou exigir outra classe para funcionar corretamente.  
  
     Se você determinar que é seguro usar uma classe que tem um construtor de cópia `private`, derive uma nova classe da classe que tem o construtor `private` e torne um construtor de cópia `public` ou de `protected` disponível na nova classe. Use a classe derivada em vez da original.  
  
2.  O problema pode ocorrer quando é feita uma tentativa de copiar uma classe cujo construtor de cópia é explícito. Declarar um construtor de cópia como `explicit` evita passar/retornar objetos de uma classe para/de funções. Para obter mais informações sobre construtores explícitos, consulte [conversões de tipo definidas pelo usuário](../../cpp/user-defined-type-conversions-cpp.md).  
  
3.  O problema pode ocorrer quando é feita uma tentativa de copiar uma instância da classe declarada como `const` usando um construtor de cópia que não usa um parâmetro de referência `const`. Declare o construtor de cópia com uma referência de tipo `const` em vez de uma referência de tipo não const.
