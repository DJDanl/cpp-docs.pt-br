---
title: Conversão dupla (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- double thunks
- interop [C++], double thunking
- mixed assemblies [C++], double thunking
- /clr compiler option [C++], double thunking
- interoperability [C++], double thunking
ms.assetid: a85090b2-dc3c-498a-b40c-340db229dd6f
ms.openlocfilehash: 6b2d3b4415b81dc5a9b7d0e36c154d9ee74b98ee
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221478"
---
# <a name="double-thunking-c"></a>Conversão dupla (C++)

A conversão dupla refere-se à perda de desempenho que você pode experimentar quando uma chamada de função em um contexto gerenciado chama um Visual C++ função gerenciada e onde a execução do programa chama o ponto de entrada nativo da função para chamar a função gerenciada. Este tópico discute onde ocorre a conversão dupla e como você pode evitá-la para melhorar o desempenho.

## <a name="remarks"></a>Comentários

Por padrão, ao compilar com **/CLR**, a definição de uma função gerenciada faz com que o compilador gere um ponto de entrada gerenciado e um ponto de entrada nativo. Isso permite que a função gerenciada seja chamada a partir de sites de chamada nativos e gerenciados. No entanto, quando existe um ponto de entrada nativo, ele pode ser o ponto de entrada para todas as chamadas para a função. Se uma função de chamada for gerenciada, o ponto de entrada nativo chamará o ponto de entrada gerenciado. Na verdade, duas chamadas são necessárias para invocar a função (portanto, conversão dupla). Por exemplo, as funções virtuais são sempre chamadas por meio de um ponto de entrada nativo.

Uma resolução é informar ao compilador para não gerar um ponto de entrada nativo para uma função gerenciada, que a função só será chamada a partir de um contexto gerenciado, usando o [__clrcall](../cpp/clrcall.md) Convenção de chamada.

Da mesma forma, se você exportar ([dllexport, DllImport](../cpp/dllexport-dllimport.md)) uma função gerenciada, um ponto de entrada nativo será gerado e qualquer função que importar e chamar essa função irá chamar o ponto de entrada nativo. Para evitar a conversão dupla nessa situação, não use a semântica de exportação/importação nativa; Basta referenciar os metadados via `#using` (consulte a [diretiva #using](../preprocessor/hash-using-directive-cpp.md)).

O compilador foi atualizado para reduzir a conversão dupla desnecessária. Por exemplo, qualquer função com um tipo gerenciado na assinatura (incluindo tipo de retorno) será marcada implicitamente como `__clrcall` .

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir demonstra a conversão dupla. Quando o nativo compilado (sem **/CLR**), a chamada para a função virtual no `main` gera uma chamada para `T` o construtor de cópia e uma chamada para o destruidor. Um comportamento semelhante é obtido quando a função virtual é declarada com **/CLR** e `__clrcall` . No entanto, quando acabamos de ser compilado com **/CLR**, a chamada de função gera uma chamada para o construtor de cópia, mas há outra chamada para o construtor de cópia devido à conversão nativa para gerenciada.

### <a name="code"></a>Código

```cpp
// double_thunking.cpp
// compile with: /clr
#include <stdio.h>
struct T {
   T() {
      puts(__FUNCSIG__);
   }

   T(const T&) {
      puts(__FUNCSIG__);
   }

   ~T() {
      puts(__FUNCSIG__);
   }

   T& operator=(const T&) {
      puts(__FUNCSIG__);
      return *this;
   }
};

struct S {
   virtual void /* __clrcall */ f(T t) {};
} s;

int main() {
   S* pS = &s;
   T t;

   printf("calling struct S\n");
   pS->f(t);
   printf("after calling struct S\n");
}
```

### <a name="sample-output"></a>Saída de exemplo

```
__thiscall T::T(void)
calling struct S
__thiscall T::T(const struct T &)
__thiscall T::T(const struct T &)
__thiscall T::~T(void)
__thiscall T::~T(void)
after calling struct S
__thiscall T::~T(void)
```

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo anterior demonstrou a existência de uma conversão dupla. Este exemplo mostra seu efeito. O **`for`** loop chama a função virtual e o programa informa o tempo de execução. A hora mais lenta é relatada quando o programa é compilado com **/CLR**. As horas mais rápidas são relatadas durante a compilação sem **/CLR** ou se a função virtual for declarada com `__clrcall` .

### <a name="code"></a>Código

```cpp
// double_thunking_2.cpp
// compile with: /clr
#include <time.h>
#include <stdio.h>

#pragma unmanaged
struct T {
   T() {}
   T(const T&) {}
   ~T() {}
   T& operator=(const T&) { return *this; }
};

struct S {
   virtual void /* __clrcall */ f(T t) {};
} s;

int main() {
   S* pS = &s;
   T t;
   clock_t start, finish;
   double  duration;
   start = clock();

   for ( int i = 0 ; i < 1000000 ; i++ )
      pS->f(t);

   finish = clock();
   duration = (double)(finish - start) / (CLOCKS_PER_SEC);
   printf( "%2.1f seconds\n", duration );
   printf("after calling struct S\n");
}
```

### <a name="sample-output"></a>Saída de exemplo

```
4.2 seconds
after calling struct S
```

## <a name="see-also"></a>Confira também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
