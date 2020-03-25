---
title: Aviso do compilador (nível 4) C4127
ms.date: 10/16/2019
f1_keywords:
- C4127
helpviewer_keywords:
- C4127
ms.assetid: f59ded9e-5227-45bd-ac43-2aa861581363
ms.openlocfilehash: 9d4397c11c4d2f0f9013c7df914cbc4be9fd4e9d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198478"
---
# <a name="compiler-warning-level-4-c4127"></a>Aviso do compilador (nível 4) C4127

> a expressão condicional é constante

## <a name="remarks"></a>Comentários

A expressão de controle de uma instrução **If** ou loop **while** é avaliada como uma constante. Devido ao uso comum de idiomática, a partir do Visual Studio 2015 atualização 3, constantes triviais como 1 ou **true** não disparam o aviso, a menos que sejam o resultado de uma operação em uma expressão.

Se a expressão de controle de um loop **while** for uma constante porque o loop é encerrado no meio, considere substituir o loop **while** por um loop **for** . Você pode omitir a inicialização, o teste de encerramento e o incremento do loop de um loop **for** , o que faz com que o loop seja infinito, assim como `while(1)`, e você pode sair do loop do corpo da instrução **for** .

## <a name="example"></a>Exemplo

O exemplo a seguir mostra duas maneiras como o C4127 é gerado e mostra como usar um loop for para evitar o aviso:

```cpp
// C4127.cpp
// compile with: /W4
#include <stdio.h>
int main() {
   if (true) {}           // OK in VS2015 update 3 and later
   if (1 == 1) {}         // C4127
   while (42) { break; }  // C4127

   // OK
   for ( ; ; ) {
      printf("test\n");
      break;
   }
}
```

Esse aviso também pode ser gerado quando uma constante de tempo de compilação é usada em uma expressão condicional:

```cpp
#include <string>

using namespace std;

template<size_t S, class T>
void MyFunc()
{
   if (sizeof(T) >= S) // C4127. "Consider using 'if constexpr' statement instead"
   {
   }
}

class Foo
{
   int i;
   string s;
};

int main()
{
   Foo f;
   MyFunc<4, Foo>();
}
```
