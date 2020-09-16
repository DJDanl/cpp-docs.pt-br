---
title: __clrcall
ms.date: 11/04/2016
f1_keywords:
- __clrcall_cpp
helpviewer_keywords:
- __clrcall keyword [C++]
ms.assetid: 92096695-683a-40ed-bf65-0c8443572152
ms.openlocfilehash: 85e9025c26cc821cdbd8e5218e184f05e2b96b24
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90685825"
---
# <a name="__clrcall"></a>__clrcall

Especifica que uma função só pode ser chamada de um código gerenciado.  Use **__clrcall** para todas as funções virtuais que só serão chamadas a partir do código gerenciado. No entanto, essa convenção de chamada não pode ser usada para as funções que serão chamadas a partir do código nativo. O modificador de **__clrcall** é específico da Microsoft.

Use **__clrcall** para melhorar o desempenho ao chamar de uma função gerenciada para uma função gerenciada virtual ou da função gerenciada para a função gerenciada por meio de ponteiro.

Os pontos de entrada são funções separadas geradas pelo compilador. Se uma função tem pontos de entrada nativos e gerenciados, um deles será a função real com a implementação da função. Outra função será uma função separada (uma conversão) que chamará a função real e deixará Common Language Runtime executar PInvoke. Ao marcar uma função como **__clrcall**, você indica que a implementação da função deve ser MSIL e que a função de ponto de entrada nativa não será gerada.

Ao pegar o endereço de uma função nativa se **__clrcall** não for especificado, o compilador usará o ponto de entrada nativo. **__clrcall** indica que a função é gerenciada e não há necessidade de passar pela transição de gerenciado para nativo. Nesse caso, o compilador usa o ponto de entrada gerenciado.

Quando `/clr` (não `/clr:pure` ou `/clr:safe` ) é usado e **__clrcall** não é usado, pegar o endereço de uma função sempre retorna o endereço da função de ponto de entrada nativa. Quando **__clrcall** é usado, a função de ponto de entrada nativa não é criada e, portanto, você obtém o endereço da função gerenciada, não uma função de conversão de ponto de entrada. Para obter mais informações, consulte [conversão dupla](../dotnet/double-thunking-cpp.md). As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

o [/CLR (compilação Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md) implica que todas as funções e ponteiros de função são **__clrcall** e o compilador não permitirá que uma função dentro do compiland seja marcada como algo diferente de **__clrcall**. Quando **/CLR: Pure** é usado, **__clrcall** só pode ser especificado em ponteiros de função e em declarações externas.

Você pode chamar diretamente **__clrcall** funções do código C++ existente que foi compilado usando **/CLR** , desde que essa função tenha uma implementação MSIL. **__clrcall** funções não podem ser chamadas diretamente de funções que têm asm embutido e chamam intrinisics específicas de CPU, por exemplo, mesmo que essas funções sejam compiladas com `/clr` .

**__clrcall** ponteiros de função devem ser usados apenas no domínio do aplicativo no qual foram criados.  Em vez de passar **__clrcall** ponteiros de função entre domínios de aplicativo, use <xref:System.CrossAppDomainDelegate> . Para obter mais informações, consulte [domínios de aplicativo e Visual C++](../dotnet/application-domains-and-visual-cpp.md).

## <a name="examples"></a>Exemplos

Observe que quando uma função é declarada com **__clrcall**, o código será gerado quando necessário; por exemplo, quando a função é chamada.

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

## <a name="see-also"></a>Confira também

[Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
