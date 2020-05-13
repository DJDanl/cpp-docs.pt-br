---
title: restrita (C++ AMP)
ms.date: 11/04/2016
f1_keywords:
- cpu_CPP
- amp_CPP
helpviewer_keywords:
- restrict clause (C++ AMP)
ms.assetid: 07d3291f-7edf-456b-8828-283ac8673661
ms.openlocfilehash: 5a0011d11e4a59c9ca3a5e18f44d4cf831b21582
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366656"
---
# <a name="restrict-c-amp"></a>restrita (C++ AMP)

O especificador de restrição pode ser aplicado a declarações de função e lambda. Impõe restrições no código na função e no comportamento da função em aplicativos que usam o runtime do C++ Accelerated Massive Parallelism(AMP C++).

> [!NOTE]
> Para obter informações sobre a palavra-chave **restringir** que faz parte dos atributos **__declspec** classe de armazenamento, consulte [restringir](../cpp/restrict.md).

A cláusula **de restrição** toma os seguintes formulários:

|Cláusula|Descrição|
|------------|-----------------|
|`restrict(cpu)`|A função pode usar a linguagem C++ completa. Somente outras funções que são declaradas usando as funções restrict(cpu) podem chamar a função.|
|`restrict(amp)`|A função só pode usar o subconjunto da linguagem C++ que o AMP C++ pode acelerar.|
|Uma sequência de `restrict(cpu)` e `restrict(amp)`.|A função deve atender às limitações de `restrict(cpu)` e `restrict(amp)`. A função pode ser chamada por funções que são declaradas usando `restrict(cpu)`, `restrict(amp)`, `restrict(cpu, amp)` ou `restrict(amp, cpu)`.<br /><br /> A forma `restrict(A) restrict(B)` pode ser escrita como `restrict(A,B)`.|

## <a name="remarks"></a>Comentários

A palavra-chave **restrita** é uma palavra-chave contextual. Os especificadores de restrição `cpu` e `amp` não são palavras reservadas. A lista de especificadores não é extensível. Uma função que não tem uma cláusula **de restrição** `restrict(cpu)` é a mesma de uma função que tem a cláusula.

Uma função que tem a cláusula `restrict(amp)` tem as seguintes limitações:

- A função só pode chamar funções que tenham a cláusula `restrict(amp)`.

- A função deve ser embutível.

- A função pode declarar apenas **int**, **int não assinado**, **flutuação**, e **variáveis duplas,** e classes e estruturas que contêm apenas esses tipos. **bool** também é permitido, mas deve ser 4-byte-alinhado se você usá-lo em um tipo composto.

- As funções lambda não podem capturar por referência nem capturar os ponteiros.

- As referências e ponteiros de indireção única só têm suporte como variáveis locais, argumentos de função e tipos de retorno.

- Os seguintes não são permitidos:

  - Recursão.

  - Variáveis declaradas com a palavra-chave [volátil.](../cpp/volatile-cpp.md)

  - Funções virtuais.

  - Ponteiros para funções.

  - Ponteiros para funções de membro.

  - Ponteiros em estruturas.

  - Ponteiros para ponteiros.

  - **irpara** declarações.

  - Instruções rotuladas.

  - **tentar,** **pegar**ou **lançar** declarações.

  - Variáveis globais.

  - Variáveis estáticas. Use [tile_static palavra-chave](../cpp/tile-static-keyword.md) em vez disso.

  - **dynamic_cast** moldes.

  - O operador **da tipo.**

  - Declarações asm.

  - Varargs.

Para uma discussão sobre limitações de função, consulte [restringir (amp) Restrições](https://blogs.msdn.microsoft.com/nativeconcurrency/2011/12/19/restrictamp-restrictions-part-0-of-n-introduction/).

## <a name="example"></a>Exemplo

O exemplo a seguir `restrict(amp)`mostra como usar a cláusula.

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
