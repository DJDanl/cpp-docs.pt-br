---
title: "Aviso (nível 3) do compilador C4800 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4800
dev_langs:
- C++
helpviewer_keywords:
- C4800
ms.assetid: 4f409799-a250-45ed-bb5f-657691b0d9f7
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 687b0dab996bfbfe2ce30d65b86196383c02b914
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4800"></a>Aviso (nível 3) do compilador C4800  
  
> '*tipo*': forçando valor para bool 'true' ou 'false' (aviso de desempenho)  
  
Esse aviso é gerado quando um valor que não seja `bool` atribuído ou imposto para o tipo `bool`. Normalmente, essa mensagem é exibida, atribuindo `int` variáveis de `bool` variáveis onde o `int` variável contém apenas valores **true** e **false**e pode ser declarado novamente como tipo `bool`. Se você não pode reescrever a expressão para usar o tipo `bool`, em seguida, você pode adicionar "`!=0`" à expressão, que fornece o tipo da expressão `bool`. Converter a expressão para o tipo `bool` não desabilita o aviso, que é por design.  
  
Esse aviso não é gerado no Visual Studio de 2017.  
  
## <a name="example"></a>Exemplo
  
 O exemplo a seguir gera C4800 e mostra como corrigi-lo:  
  
```cpp  
// C4800.cpp  
// compile with: /W3  
int main() {  
   int i = 0;  
  
   // To fix, instead try:  
   // bool i = 0;  
  
   bool j = i;   // C4800  
   j++;  
}  
```