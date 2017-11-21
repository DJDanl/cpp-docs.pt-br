---
title: Classe vector&lt;bool&gt;::reference | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vector/vector<bool>::reference
dev_langs: C++
helpviewer_keywords: vector<bool> reference class
ms.assetid: f27854f9-0ef0-4e7e-ad2e-cd53b6cb3334
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1ca67fcf0ea4b74d167ddb6cdeb01de071a24862
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="vectorltboolgtreference-class"></a>Classe vector&lt;bool&gt;::reference
A classe `vector<bool>::reference` é uma classe proxy fornecida pela Classe [vector\<bool>](../standard-library/vector-bool-class.md) para simular `bool&`.  
  
## <a name="remarks"></a>Comentários  
 Uma referência simulada é necessária porque o C++ não permite nativamente referências diretas aos bits. `vector<bool>` usa apenas um bit por elemento, que pode ser referenciado usando essa classe proxy. No entanto, a simulação de referência não é concluída porque determinadas atribuições não são válidas. Por exemplo, como o endereço do objeto `vector<bool>::reference` não pode ser usado, o código a seguir que usa [vector\<bool>::operator&#91;&#93;](http://msdn.microsoft.com/Library/97738633-690d-4069-b2d9-8c54104fbfdd) não está correto:  
  
```cpp  
vector<bool> vb;  
// ...  
bool* pb = &vb[1]; // conversion error - do not use  
bool& refb = vb[1];   // conversion error - do not use  
```  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[flip](../standard-library/vector-bool-reference-flip.md)|Inverte o valor booliano de um elemento de vetor.|  
|[operator bool](../standard-library/vector-bool-reference-operator-bool.md)|Fornece uma conversão implícita de `vector<bool>::reference` em `bool`.|  
|[operator=](../standard-library/vector-bool-reference-operator-assign.md)|Atribui um valor booliano a um bit ou o valor mantido por um elemento referenciado para um bit.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: \<vector>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<vector>](../standard-library/vector.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)

