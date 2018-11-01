---
title: Erro do compilador C3293
ms.date: 07/21/2017
f1_keywords:
- C3293
helpviewer_keywords:
- C3293
ms.assetid: b772cf98-52e0-4e24-be23-1f5d87d999ac
ms.openlocfilehash: 84d539722474d5f5dfffe1f6fe121bb7349ba131
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548197"
---
# <a name="compiler-error-c3293"></a>Erro do compilador C3293

'acessador': use 'default' para acessar a propriedade padrão (indexador) para a classe 'type'

Uma propriedade indexada foi acessada incorretamente.  Ver [como: usar propriedades no C + + c++ CLI](../../dotnet/how-to-use-properties-in-cpp-cli.md) para obter mais informações.

**Visual Studio 2017 e posterior**: no Visual Studio 2015 e versões anterior, o compilador em alguns casos, identificava incorretamente uma propriedade padrão como um indexador padrão. É possível resolver o problema usando o identificador "padrão" para acessar a propriedade. A solução em si se tornou um problema depois que o padrão foi introduzido como uma palavra-chave no C++ 11. Portanto, no Visual Studio 2017, os bugs que exigiam a solução alternativa foram corrigidos, e agora o compilador gera um erro quando o “padrão” é usado para acessar a propriedade padrão de uma classe.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3293 no Visual Studio 2015 e versões anteriores.

```
// C3293.cpp
// compile with: /clr /c
using namespace System;
ref class IndexerClass {
public:
   // default indexer
   property int default[int] {
      int get(int index) { return 0; }
      void set(int index, int value) {}
   }
};

int main() {
   IndexerClass ^ ic = gcnew IndexerClass;
   ic->Item[0] = 21;   // C3293 in VS2015 OK in VS2017
   ic->default[0] = 21;   // OK in VS2015 and earlier

   String ^s = "Hello";
   wchar_t wc = s->Chars[0];   // C3293 in VS2015 OK in VS2017
   wchar_t wc2 = s->default[0];   // OK in VS2015 and earlier
   Console::WriteLine(wc2);
}
```