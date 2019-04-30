---
title: (Nível 4) de aviso do compilador C4800
ms.date: 03/14/2019
f1_keywords:
- C4800
helpviewer_keywords:
- C4800
ms.assetid: 4f409799-a250-45ed-bb5f-657691b0d9f7
ms.openlocfilehash: 46418063625e16385497740a4f7e3d837e923156
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401547"
---
# <a name="compiler-warning-level-4-c4800"></a>(Nível 4) de aviso do compilador C4800

::: moniker range=">= vs-2019"
Visual Studio 2019 e posterior:
> Conversão implícita de '*tipo*' em bool. Possível perda de informações
::: moniker-end

C4800 é um aviso de nível 3 no Visual Studio 2015 e anteriores:
> '*tipo*': forçando o valor booliano 'true' ou 'false' (aviso de desempenho)

Esse aviso é gerado quando um valor é convertido implicitamente no tipo `bool`. Normalmente, essa mensagem é causada por meio da atribuição `int` variáveis a serem `bool` variáveis em que o `int` variável contém apenas valores **true** e **false**e pode ser declarado novamente como tipo `bool`. Se você não é possível reescrever a expressão para usar o tipo `bool`, em seguida, você pode adicionar "`!=0`" à expressão, que fornece o tipo de expressão `bool`. A expressão para o tipo de conversão `bool` não desabilitar o aviso, o que acontece por design.

::: moniker range=">= vs-2017"
Esse aviso não é emitido no Visual Studio 2017.
::: moniker-end

::: moniker range=">= vs-2019"
Esse aviso é desativado por padrão, a partir do Visual Studio de 2019. Use __/w__*n*__4800__ habilitar C4800 como um nível *n* aviso, ou [/Wall](../../build/reference/compiler-option-warning-level.md) para habilitar todos os avisos que são desativados por padrão. Para obter mais informações, consulte [compilador avisos que são desativada por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
::: moniker-end

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4800 e mostra como corrigi-lo:

```cpp
// C4800.cpp
// compile with: /W4 /w44800
int main() {
   int i = 0;

   // To fix, instead try:
   // bool i = 0;

   bool j = i;   // C4800
   j++;
}
```