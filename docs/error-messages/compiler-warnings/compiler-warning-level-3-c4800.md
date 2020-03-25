---
title: Aviso do compilador (nível 4) C4800
ms.date: 03/14/2019
f1_keywords:
- C4800
helpviewer_keywords:
- C4800
ms.assetid: 4f409799-a250-45ed-bb5f-657691b0d9f7
ms.openlocfilehash: 828b38aeb184741af284f2d7722017b24f6255a3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198582"
---
# <a name="compiler-warning-level-4-c4800"></a>Aviso do compilador (nível 4) C4800

::: moniker range=">= vs-2019"
Visual Studio 2019 e posterior:
> Conversão implícita de '*Type*' para bool. Possível perda de informações
::: moniker-end

C4800 é um aviso de nível 3 no Visual Studio 2015 e anterior:
> '*Type*': forçando o valor para bool ' true ' ou ' false ' (aviso de desempenho)

Esse aviso é gerado quando um valor é convertido implicitamente no tipo `bool`. Normalmente, essa mensagem é causada pela atribuição de variáveis `int` para `bool` variáveis em que a variável `int` contém apenas valores **true** e **false**e pode ser redeclarado como tipo `bool`. Se não for possível reescrever a expressão para usar o tipo `bool`, você poderá adicionar "`!=0`" à expressão, que fornece o tipo de expressão `bool`. A conversão da expressão no tipo `bool` não desabilita o aviso, que é por design.

::: moniker range=">= vs-2017"
Esse aviso não é emitido no Visual Studio 2017.
::: moniker-end

::: moniker range=">= vs-2019"
Esse aviso está desativado por padrão a partir do Visual Studio 2019. Use __/w__*n*__4800__ para habilitar C4800 como um aviso de nível *n* ou [/Wall](../../build/reference/compiler-option-warning-level.md) para habilitar todos os avisos que estão desativados por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
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
