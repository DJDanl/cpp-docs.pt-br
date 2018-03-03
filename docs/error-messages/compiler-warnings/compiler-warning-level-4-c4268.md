---
title: "Compilador (nível 4) de aviso C4268 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4268
dev_langs:
- C++
helpviewer_keywords:
- C4268
ms.assetid: d0511e80-904f-4ee1-b4d7-39b5c0bd8234
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b88e7c44099d49eb76d1bee9c68dd8a94413074a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4268"></a>Compilador C4268 de aviso (nível 4)
'Identificador': 'const' dados static/globais inicializados com o construtor do padrão gerado pelo compilador preenche o objeto com zeros  
  
 Um **const** global ou estática de instância de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.  
  
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
  
 Como esta instância da classe é **const**, o valor de `m_data` não pode ser alterado.