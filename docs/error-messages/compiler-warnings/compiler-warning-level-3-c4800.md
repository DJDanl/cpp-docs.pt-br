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
ms.openlocfilehash: b5a19c27731192a5fe2930aec3e78fb66d790484
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46090900"
---
# <a name="compiler-warning-level-3-c4800"></a>Aviso (nível 3) do compilador C4800

> '*tipo*': forçando o valor booliano 'true' ou 'false' (aviso de desempenho)

Esse aviso é gerado quando um valor que não é `bool` atribuído ou imposto para o tipo `bool`. Normalmente, essa mensagem é causada por meio da atribuição `int` variáveis a serem `bool` variáveis em que o `int` variável contém apenas valores **true** e **false**e pode ser declarado novamente como tipo `bool`. Se você não é possível reescrever a expressão para usar o tipo `bool`, em seguida, você pode adicionar "`!=0`" à expressão, que fornece o tipo de expressão `bool`. A expressão para o tipo de conversão `bool` não desabilita o aviso, o que acontece por design.

Esse aviso não é mais gerado no Visual Studio 2017.

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