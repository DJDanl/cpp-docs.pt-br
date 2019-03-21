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
ms.openlocfilehash: f34af20ed3dd2c48659bdbf7794c443920dbb4e9
ms.sourcegitcommit: 90817d9d78fbaed8ffacde63f3add334842e596f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/20/2019
ms.locfileid: "58278392"
---
# <a name="double-thunking-c"></a>Conversão dupla (C++)

Conversão dupla se refere à perda de desempenho que você pode enfrentar quando uma chamada de função em um chamadas de contexto gerenciado um Visual C++ gerenciado função e onde a execução do programa chama o ponto de entrada nativo da função para chamar a função gerenciada. Este tópico discute onde ocorre a conversão dupla e como evitá-lo para melhorar o desempenho.

## <a name="remarks"></a>Comentários

Por padrão, ao compilar com **/clr**, a definição de uma função gerenciada faz com que o compilador gere um ponto de entrada gerenciado e um ponto de entrada nativo. Isso permite que a função gerenciada a ser chamado de sites de chamada nativa e gerenciada. No entanto, quando existe um ponto de entrada nativo, ele pode ser o ponto de entrada para todas as chamadas para a função. Se uma função de chamada for gerenciada, o ponto de entrada nativo, em seguida, chamará o ponto de entrada gerenciado. Na verdade, duas chamadas são necessários para invocar a função (portanto, duplas conversão dupla). Por exemplo, as funções virtuais sempre são chamadas por meio de um ponto de entrada nativo.

Uma resolução é dizer ao compilador para não gerar um ponto de entrada nativo para uma função gerenciada, que a função somente será chamada de um contexto gerenciado, usando o [clrcall](../cpp/clrcall.md) convenção de chamada.

Da mesma forma, se você exportar ([dllexport, dllimport](../cpp/dllexport-dllimport.md)) uma função gerenciada, um ponto de entrada nativo é gerado e qualquer função que importa e chama essa função chamará o ponto de entrada nativo. Para evitar a dupla nessa situação, não use semântica de importação/exportação nativo; Basta referenciar os metadados por meio `#using` (consulte [# diretiva using](../preprocessor/hash-using-directive-cpp.md)).

O compilador foi atualizado para reduzir a dupla desnecessária. Por exemplo, qualquer função com um tipo gerenciado na assinatura (incluindo o tipo de retorno) implicitamente será marcada como `__clrcall`.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir demonstra a conversão dupla. Quando compilado nativo (sem **/clr**), a chamada para a função virtual na `main` gera uma chamada para `T`do construtor e uma chamada para o destruidor de copiar. Um comportamento semelhante é obtido quando a função virtual é declarada com **/clr** e `__clrcall`. No entanto, quando apenas compilado com **/clr**, a chamada de função gera uma chamada para o construtor de cópia, mas há outra chamada para o construtor de cópia devido à conversão de nativo para gerenciado.

### <a name="code"></a>Código

```
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

### <a name="sample-output"></a>Saída de Exemplo

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

O exemplo anterior demonstrou a existência de conversão dupla. Este exemplo mostra seu efeito. O `for` loop chama a função virtual e o tempo de execução de relatórios do programa. A hora mais lenta é relatada quando o programa é compilado com **/clr**. Os tempos mais rápidos são relatados ao compilar sem **/clr** ou se a função virtual é declarada com `__clrcall`.

### <a name="code"></a>Código

```
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

### <a name="sample-output"></a>Saída de Exemplo

```
4.2 seconds
after calling struct S
```

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
