---
title: Aviso do compilador C4868
ms.date: 10/26/2017
f1_keywords:
- C4868
helpviewer_keywords:
- C4868
ms.assetid: fc6aa7e5-34dd-4ec2-88bd-16e430361dc7
ms.openlocfilehash: c1d49eb61a5c7c47fa83dacb39ed50f42e0fb147
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810483"
---
# <a name="compiler-warning-level-4-c4868"></a>Aviso do compilador (nível 4) C4868

> o compilador '_File_(*line_number*) ' não pode impor a ordem de avaliação da esquerda para a direita na lista de inicializadores de chaves

Os elementos de uma lista de inicializadores entre chaves devem ser avaliados na ordem da esquerda para a direita. Há dois casos em que o compilador não pode garantir esse pedido: o primeiro é quando alguns dos elementos são objetos passados por valor; a segunda é quando se compila com `/clr` e alguns dos elementos são campos de objetos ou são elementos de matriz. Quando o compilador não pode garantir a avaliação da esquerda para a direita, ele emite o aviso C4868.

Esse aviso pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2015 atualização 2. O código que compilou antes do Visual Studio 2015 atualização 2 agora pode gerar C4868.

Esse aviso está desativado por padrão. Use `/Wall` para ativar este aviso.

Para resolver esse aviso, primeiro considere se a avaliação da esquerda para a direita dos elementos da lista de inicializadores é necessária, por exemplo, quando a avaliação dos elementos pode produzir efeitos colaterais dependentes de ordem. Em muitos casos, a ordem na qual os elementos são avaliados não tem um efeito observável.

Se a ordem de avaliação deve ser da esquerda para a direita, considere se é possível passar os elementos por `const` referência em vez disso. Uma alteração como essa elimina o aviso no exemplo de código a seguir.

## <a name="example"></a>Exemplo

Este exemplo gera C4868 e mostra uma maneira de corrigi-lo:

```cpp
// C4868.cpp
// compile with: /c /Wall
#include <cstdio>

class HasCopyConstructor
{
public:
    int x;

    HasCopyConstructor(int x): x(x) {}

    HasCopyConstructor(const HasCopyConstructor& h): x(h.x)
    {
        printf("Constructing %d\n", h.x);
    }
};

class TripWarning4868
{
public:
    // note that taking "HasCopyConstructor" parameters by-value will trigger copy-construction.
    TripWarning4868(HasCopyConstructor a, HasCopyConstructor b) {}

    // This variation will not trigger the warning:
    // TripWarning4868(const HasCopyConstructor& a, const HasCopyConstructor& b) {}
};

int main()
{
    HasCopyConstructor a{1};
    HasCopyConstructor b{2};

    // the warning will indicate the below line, the usage of the braced initializer list.
    TripWarning4868 warningOnThisLine{a, b};
};
```