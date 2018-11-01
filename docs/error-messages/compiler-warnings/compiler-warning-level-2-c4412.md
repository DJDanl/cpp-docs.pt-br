---
title: Compilador aviso (nível 2) C4412
ms.date: 11/04/2016
f1_keywords:
- C4412
helpviewer_keywords:
- C4412
ms.assetid: f28dc531-1a98-497b-a366-0a13e1bc81c7
ms.openlocfilehash: 2c9d50fc3433321c0ca92366a512892212545754
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665511"
---
# <a name="compiler-warning-level-2-c4412"></a>Compilador aviso (nível 2) C4412

> '*função*': assinatura de função contém o tipo '*tipo*'; Objetos de C++ são seguros para passar entre código puro e combinado ou nativo.

## <a name="remarks"></a>Comentários

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017. Se você tiver o código que precisa ser pura, é recomendável portar para C#.

O compilador detectou uma situação potencialmente não segura que pode resultar em um erro de tempo de execução: está sendo feita uma chamada de um **/clr: pure** compiland para uma função que foi importada por meio de dllimport e a assinatura de função contém um tipo não seguro . Um tipo é seguro se ele contém uma função de membro ou tem um membro de dados que é um tipo não seguro ou uma indireção a um tipo que não é segura.

Isso não é seguro por causa da diferença no padrão de convenções entre código puro e nativo de chamada (ou misto gerenciado e nativo). Durante a importação de (por meio `dllimport`) uma função em um **/clr: pure** compiland, certifique-se de que as declarações de cada tipo na assinatura são idênticas àquelas em compiland que exporta a função (sendo especialmente cuidado em relação a diferenças em convenções de chamada implícitas).

Uma função membro virtual é especialmente propensa a gerar resultados inesperados.  No entanto, até mesmo uma função não virtual deve ser testada para garantir que você obtenha os resultados corretos. Se você tiver certeza de que você está obtendo os resultados corretos, você pode ignorar este aviso.

C4412 está desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) e [dllexport, dllimport](../../cpp/dllexport-dllimport.md) para obter mais informações.

Para resolver este aviso, remova todas as funções do tipo.

## <a name="example"></a>Exemplo

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

## <a name="example"></a>Exemplo

O exemplo a seguir é um arquivo de cabeçalho que declara dois tipos. O `Unsafe` tipo é seguro porque ele tem uma função de membro.

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

## <a name="example"></a>Exemplo

Este exemplo exporta as funções com os tipos definidos no arquivo de cabeçalho.

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

## <a name="example"></a>Exemplo

O padrão de convenção de chamada um **/clr: pure** compilação é diferente de uma compilação nativa.  Quando C4412.h é incluída, `Test` padrão é `__clrcall`. Se você compilar e executar esse programa (não use **/c**), o programa irá acionar uma exceção.

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