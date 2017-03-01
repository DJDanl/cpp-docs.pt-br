---
title: "Compilador aviso (nível 4) C4268 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4268
dev_langs:
- C++
helpviewer_keywords:
- C4268
ms.assetid: d0511e80-904f-4ee1-b4d7-39b5c0bd8234
caps.latest.revision: 6
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
ms.openlocfilehash: e746a8391775118e1126325b42000f0e12c10b6f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4268"></a>Compilador C4268 de aviso (nível 4)
'identifier': '' estático/global dados inicializados com o construtor de padrão gerado pelo compilador preenche o objeto com zeros  
  
 A **const** global ou estática instância de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4268.cpp  
// compile with: /c /LD /W4  
class X {  
public:  
   int m_data;  
};  
  
const X x1;   // C4268  
```  
  
 Como essa instância da classe **const**, o valor de `m_data` não pode ser alterado.
