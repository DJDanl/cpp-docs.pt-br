---
title: "Compilador aviso (nível 1) C4926 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4926
dev_langs:
- C++
helpviewer_keywords:
- C4926
ms.assetid: 5717fce0-146f-4ef2-bde0-e9a01c0922d1
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8fafc207d2e0276814ad13efe05c091a21a66c75
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4926"></a>Compilador C4926 de aviso (nível 1)
'identifier': símbolo já está definido: atributos ignorados  
  
 Uma declaração de encaminhamento foi encontrada, mas uma construção atribuída com o mesmo nome já existe. Os atributos para a declaração de encaminhamento são ignorados.  
  
 O exemplo a seguir gera C4926:  
  
```  
// C4926.cpp  
// compile with: /W1  
[module(name="MyLib")];  
  
[coclass]  
struct a {  
};  
  
[coclass]  
struct a;   // C4926  
  
int main() {  
}  
```
