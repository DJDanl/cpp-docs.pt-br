---
title: C3222 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3222
dev_langs:
- C++
helpviewer_keywords:
- C3222
ms.assetid: 5624bde8-2fd0-4b8b-92ce-5dfbaf91cf93
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 424c0f1011d984dff59d3d952347ad4f7b90f515
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3222"></a>C3222 de erro do compilador
'parameter': não é possível declarar argumentos padrão para o membro de um serviço ou tipo de WinRT ou genéricas funções  
  
Não é permitido para declarar um parâmetro de método com um argumento padrão. Um formulário de sobrecarga do método é uma maneira de solucionar esse problema. Ou seja, definir um método com o mesmo nome sem parâmetros e, em seguida, inicializar a variável no corpo do método.  
  
O exemplo a seguir gera C3222:  
  
```  
// C3222_2.cpp  
// compile with: /clr  
public ref class G {  
   void f( int n = 0 );   // C3222  
};  
```  
