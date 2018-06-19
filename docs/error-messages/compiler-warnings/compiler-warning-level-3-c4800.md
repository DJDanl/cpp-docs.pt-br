---
title: Aviso (nível 3) do compilador C4800 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4800
dev_langs:
- C++
helpviewer_keywords:
- C4800
ms.assetid: 4f409799-a250-45ed-bb5f-657691b0d9f7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed4b14ae2f3af3218909d6cd4609f1f45d3d7cc2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33293628"
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