---
title: Aviso do compilador C4868
ms.date: 10/26/2017
f1_keywords:
- C4868
ms.assetid: fc6aa7e5-34dd-4ec2-88bd-16e430361dc7
ms.openlocfilehash: d0bc8716e53e71c52f6a31036a95d0b4cefedd79
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62388703"
---
# <a name="compiler-warning-level-4-c4868"></a>(Nível 4) de aviso do compilador C4868

> '_arquivo_(*line_number*)' compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicializadores entre chaves

Os elementos de uma lista de inicializadores entre chaves devem ser avaliados em ordem da esquerda para a direita. Há dois casos em que o compilador é capaz de garantir nesta ordem: a primeira é quando alguns dos elementos são objetos passados por valor; o segundo é ao compilar com `/clr` e alguns dos elementos são campos de objetos ou elementos da matriz. Quando o compilador não pode garantir a avaliação da esquerda para a direita, ele emitirá o aviso C4868.

Esse aviso pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2015 atualização 2. O código compilado antes do Visual C++ 2015 atualização 2 agora pode gerar C4868.

Esse aviso é desativado por padrão. Use `/Wall` para ativar esse aviso.

Para resolver este aviso, considere se a avaliação da esquerda para a direita dos elementos de lista de inicializador é necessária, como quando a avaliação dos elementos pode produzir efeitos colaterais depende da ordem. Em muitos casos, a ordem na qual os elementos são avaliados não tem efeito observável.

Se a ordem de avaliação deve ser esquerda para a direita, considere se é possível passar os elementos por `const` de referência em vez disso. Uma alteração de como isso elimina o aviso no exemplo de código a seguir.

## <a name="example"></a>Exemplo

Este exemplo gera C4868 e mostra uma maneira de corrigir isso:

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