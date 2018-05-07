---
title: Compilador (nível 1) de aviso C4269 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4269
dev_langs:
- C++
helpviewer_keywords:
- C4269
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5e393c657e12f84d3cadfacd469e35e3472a39d0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4269"></a>Compilador C4269 de aviso (nível 1)
'Identificador': 'const' automática de dados inicializada com o construtor do padrão gerado pelo compilador produz resultados não confiáveis  
  
 Um **const** instância automática de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4269.cpp  
// compile with: /c /LD /W1  
class X {  
public:  
   int m_data;  
};  
  
void g() {  
   const X x1;   // C4269  
};  
```  
  
 Desde que esta instância da classe é gerada na pilha, o valor inicial da `m_data` pode ser qualquer coisa. Além disso, pois ele é um **const** instância, o valor de `m_data` nunca pode ser alterado.