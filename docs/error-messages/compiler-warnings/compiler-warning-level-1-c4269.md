---
title: "Compilador (nível 1) de aviso C4269 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4269
dev_langs: C++
helpviewer_keywords: C4269
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e3d276aa5744d457ee987334d65728b1835593ca
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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