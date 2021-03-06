---
title: restrita (C++ AMP)
ms.date: 11/04/2016
f1_keywords:
- cpu_CPP
- amp_CPP
helpviewer_keywords:
- restrict clause (C++ AMP)
ms.assetid: 07d3291f-7edf-456b-8828-283ac8673661
ms.openlocfilehash: 31db9e8c6f18879e65596593c10a8b3413c5cea9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213262"
---
# <a name="restrict-c-amp"></a>restrita (C++ AMP)

O especificador de restrição pode ser aplicado a declarações de função e lambda. Impõe restrições no código na função e no comportamento da função em aplicativos que usam o runtime do C++ Accelerated Massive Parallelism(AMP C++).

> [!NOTE]
> Para obter informações sobre a **`restrict`** palavra-chave que faz parte dos **`__declspec`** atributos de classe de armazenamento, consulte [restringir](../cpp/restrict.md).

A **`restrict`** cláusula usa os seguintes formulários:

|Cláusula|Descrição|
|------------|-----------------|
|`restrict(cpu)`|A função pode usar a linguagem C++ completa. Somente outras funções que são declaradas usando as funções restrict(cpu) podem chamar a função.|
|`restrict(amp)`|A função só pode usar o subconjunto da linguagem C++ que o AMP C++ pode acelerar.|
|Uma sequência de `restrict(cpu)` e `restrict(amp)`.|A função deve atender às limitações de `restrict(cpu)` e `restrict(amp)`. A função pode ser chamada por funções que são declaradas usando `restrict(cpu)`, `restrict(amp)`, `restrict(cpu, amp)` ou `restrict(amp, cpu)`.<br /><br /> A forma `restrict(A) restrict(B)` pode ser escrita como `restrict(A,B)`.|

## <a name="remarks"></a>Comentários

A **`restrict`** palavra-chave é uma palavra-chave contextual. Os especificadores de restrição `cpu` e `amp` não são palavras reservadas. A lista de especificadores não é extensível. Uma função que não tem uma **`restrict`** cláusula é igual a uma função que tem a `restrict(cpu)` cláusula.

Uma função que tem a cláusula `restrict(amp)` tem as seguintes limitações:

- A função só pode chamar funções que tenham a cláusula `restrict(amp)`.

- A função deve ser embutível.

- A função pode declarar somente **`int`** variáveis,, **`unsigned int`** **`float`** , e **`double`** , e classes e estruturas que contêm apenas esses tipos. **`bool`** também é permitido, mas deve ser alinhado em 4 bytes se você usá-lo em um tipo composto.

- As funções lambda não podem capturar por referência nem capturar os ponteiros.

- As referências e ponteiros de indireção única só têm suporte como variáveis locais, argumentos de função e tipos de retorno.

- Os seguintes não são permitidos:

  - Recursão.

  - Variáveis declaradas com a palavra-chave [volatile](../cpp/volatile-cpp.md) .

  - Funções virtuais.

  - Ponteiros para funções.

  - Ponteiros para funções de membro.

  - Ponteiros em estruturas.

  - Ponteiros para ponteiros.

  - **`goto`** instruções.

  - Instruções rotuladas.

  - **`try`****`catch`** instruções, ou **`throw`** .

  - Variáveis globais.

  - Variáveis estáticas. Em vez disso, use [Tile_static palavra-chave](../cpp/tile-static-keyword.md) .

  - **`dynamic_cast`** conversões.

  - O **`typeid`** operador.

  - Declarações asm.

  - Varargs.

Para obter uma discussão sobre limitações de função, consulte [restrições (amp)](/archive/blogs/nativeconcurrency/restrictamp-restrictions-part-0-of-n-introduction).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar a `restrict(amp)` cláusula.

```cpp
void functionAmp() restrict(amp) {}
void functionNonAmp() {}

void callFunctions() restrict(amp)
{
    // int is allowed.
    int x;
    // long long int is not allowed in an amp-restricted function. This generates a compiler error.
    // long long int y;

    // Calling an amp-restricted function is allowed.
    functionAmp();

    // Calling a non-amp-restricted function is not allowed.
    // functionNonAmp();
}
```

## <a name="see-also"></a>Confira também

[C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)
