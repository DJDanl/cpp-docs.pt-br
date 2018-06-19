---
title: Compilador (nível 4) de aviso C4268 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4268
dev_langs:
- C++
helpviewer_keywords:
- C4268
ms.assetid: d0511e80-904f-4ee1-b4d7-39b5c0bd8234
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bef62649af39df950c3966ef93dddb6c71ec2fd6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33293354"
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