---
title: __clrcall
ms.date: 11/04/2016
f1_keywords:
- __clrcall_cpp
helpviewer_keywords:
- __clrcall keyword [C++]
ms.assetid: 92096695-683a-40ed-bf65-0c8443572152
ms.openlocfilehash: bc44feb97223de47f45734f75777ee040d0ebdd8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50534570"
---
# <a name="clrcall"></a>__clrcall

**Seção específica da Microsoft**

Especifica que uma função só pode ser chamada de um código gerenciado.  Use **clrcall** para todas as funções virtuais que serão chamadas apenas do código gerenciado. No entanto, essa convenção de chamada não pode ser usada para as funções que serão chamadas a partir do código nativo.

Use **clrcall** para melhorar o desempenho ao chamar a partir de uma função gerenciada para uma função gerenciada virtual ou função gerenciada para a função gerenciada pelo ponteiro.

Os pontos de entrada são funções separadas geradas pelo compilador. Se uma função tem pontos de entrada nativos e gerenciados, um deles será a função real com a implementação da função. Outra função será uma função separada (uma conversão) que chamará a função real e deixará Common Language Runtime executar PInvoke. Ao marcar uma função como **clrcall**, indicam a implementação da função deverá ser MSIL e que a função de ponto de entrada nativo não será gerada.

Ao colocar o endereço de uma função nativa se **clrcall** não for especificado, o compilador usa o ponto de entrada nativo. **clrcall** indica que a função é gerenciada e não há nenhuma necessidade de passar pela transição de gerenciada a nativa. Nesse caso, o compilador usa o ponto de entrada gerenciado.

Quando `/clr` (não `/clr:pure` ou `/clr:safe`) é usado e **clrcall** não é usado, colocar o endereço de uma função sempre retorna o endereço da função de ponto de entrada nativo. Quando **clrcall** é usado, a função de ponto de entrada nativo não for criada, para que você obtenha o endereço da função gerenciada, não uma função de conversão de ponto de entrada. Para obter mais informações, consulte [dupla](../dotnet/double-thunking-cpp.md). O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

[/CLR (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md) significa que todas as funções e ponteiros de função são **clrcall** e o compilador não permitirá que uma função dentro de compiland seja marcada como algo que não seja **clrcall**. Quando **/clr: pure** for usado, **clrcall** só pode ser especificado em ponteiros de função e declarações externas.

Você pode chamar diretamente **clrcall** funções de código C++ existente que foi compilado usando **/clr** desde que essa função tem uma implementação de MSIL. **clrcall** funções não podem ser chamadas diretamente de funções que têm asm e chamam intrinisics específico da CPU, por exemplo, mesmo se essas funções forem compilados com `/clr`.

**clrcall** ponteiros de função somente devem ser usadas no domínio do aplicativo no qual eles foram criados.  Em vez de passar **clrcall** ponteiros de função em domínios de aplicativo, use <xref:System.CrossAppDomainDelegate>. Para obter mais informações, consulte [domínios de aplicativo e do Visual C++](../dotnet/application-domains-and-visual-cpp.md).

## <a name="example"></a>Exemplo

Observe que, quando uma função é declarada com **clrcall**, código será gerado quando necessário; por exemplo, quando função é chamada.

```cpp
// clrcall2.cpp
// compile with: /clr
using namespace System;
int __clrcall Func1() {
   Console::WriteLine("in Func1");
   return 0;
}

// Func1 hasn't been used at this point (code has not been generated),
// so runtime returns the adddress of a stub to the function
int (__clrcall *pf)() = &Func1;

// code calls the function, code generated at difference address
int i = pf();   // comment this line and comparison will pass

int main() {
   if (&Func1 == pf)
      Console::WriteLine("&Func1 == pf, comparison succeeds");
   else
      Console::WriteLine("&Func1 != pf, comparison fails");

   // even though comparison fails, stub and function call are correct
   pf();
   Func1();
}
```

```Output
in Func1
&Func1 != pf, comparison fails
in Func1
in Func1
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra que você pode definir um ponteiro de função de modo a declarar que o ponteiro de função será invocado apenas de códigos gerenciados. Isso permite que o compilador chame diretamente a função gerenciada e evita o ponto de entrada nativo (problema de duas conversões).

```cpp
// clrcall3.cpp
// compile with: /clr
void Test() {
   System::Console::WriteLine("in Test");
}

int main() {
   void (*pTest)() = &Test;
   (*pTest)();

   void (__clrcall *pTest2)() = &Test;
   (*pTest2)();
}
```

## <a name="see-also"></a>Consulte também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
