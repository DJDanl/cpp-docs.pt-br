---
title: Aviso do compilador (nível 2) C4412
ms.date: 11/04/2016
f1_keywords:
- C4412
helpviewer_keywords:
- C4412
ms.assetid: f28dc531-1a98-497b-a366-0a13e1bc81c7
ms.openlocfilehash: 79b4ac95fbac344ff86922b84870e01c6681ed69
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684987"
---
# <a name="compiler-warning-level-2-c4412"></a>Aviso do compilador (nível 2) C4412

> '*Function*': assinatura de função contém tipo '*Type*'; Os objetos C++ não são seguros para passar entre o código puro e o misto ou nativo.

## <a name="remarks"></a>Comentários

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017. Se você tiver um código que precisa ser puro, é recomendável portá-lo para C#.

O compilador detectou uma situação potencialmente insegura que poderia resultar em um erro de tempo de execução: uma chamada está sendo feita de um compiland **/CLR: Pure** para uma função que foi importada via DllImport e a assinatura de função contém um tipo não seguro. Um tipo não é seguro se ele contiver uma função de membro ou tiver um membro de dados que seja um tipo não seguro ou um indireção para um tipo não seguro.

Isso não é seguro por causa da diferença nas convenções de chamada padrão entre código puro e nativo (ou misto nativo e gerenciado). Ao importar (via `dllimport` ) uma função em um compiland **/CLR: Pure** , certifique-se de que as declarações de cada tipo na assinatura sejam idênticas às do compiland que exporta a função (sendo especialmente cuidadoso em relação às diferenças nas convenções de chamada implícitas).

Uma função membro virtual é especialmente propensa a fornecer resultados inesperados.  No entanto, até mesmo uma função não virtual deve ser testada para garantir que você obtenha os resultados corretos. Se você tiver certeza de que está obtendo os resultados corretos, poderá ignorar este aviso.

C4412 está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) e [dllexport, DllImport](../../cpp/dllexport-dllimport.md) para obter mais informações.

Para resolver esse aviso, remova todas as funções do tipo.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C4412.

```cpp
// C4412.cpp
// compile with: /c /W2 /clr:pure
#pragma warning (default : 4412)

struct Unsafe {
   virtual void __cdecl Test();
};

struct Safe {
   int i;
};

__declspec(dllimport) Unsafe * __cdecl func();
__declspec(dllimport) Safe * __cdecl func2();

int main() {
   Unsafe *pUnsafe = func();   // C4412
   // pUnsafe->Test();

   Safe *pSafe = func2();   // OK
}
```

O exemplo a seguir é um arquivo de cabeçalho que declara dois tipos. O `Unsafe` tipo não é seguro porque ele tem uma função membro.

```cpp
// C4412.h
struct Unsafe {
   // will be __clrcall if #included in pure compilation
   // defaults to __cdecl in native or mixed mode compilation
   virtual void Test(int * pi);

   // try the following line instead
   // virtual void __cdecl Test(int * pi);
};

struct Safe {
   int i;
};
```

Este exemplo exporta funções com os tipos definidos no arquivo de cabeçalho.

```cpp
// C4412_2.cpp
// compile with: /LD
#include "C4412.h"

void Unsafe::Test(int * pi) {
   *pi++;
}

__declspec(dllexport) Unsafe * __cdecl func() { return new Unsafe; }
__declspec(dllexport) Safe * __cdecl func2() { return new Safe; }
```

A Convenção de chamada padrão em uma compilação **/CLR: Pure** é diferente de uma compilação nativa.  Quando C4412. h é incluído, o `Test` padrão é `__clrcall` . Se você compilar e executar este programa (não use **/c**), o programa gerará uma exceção.

O exemplo a seguir gera C4412.

```cpp
// C4412_3.cpp
// compile with: /W2 /clr:pure /c /link C4412_2.lib
#pragma warning (default : 4412)
#include "C4412.h"

__declspec(dllimport) Unsafe * __cdecl func();
__declspec(dllimport) Safe * __cdecl func2();

int main() {
   int n = 7;
   Unsafe *pUnsafe = func();   // C4412
   pUnsafe->Test(&n);

   Safe *pSafe = func2();   // OK
}
```
