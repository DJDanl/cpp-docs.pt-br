---
title: C4868 de aviso do compilador | Microsoft Docs
ms.date: 10/26/2017
ms.topic: error-reference
f1_keywords: C4868
ms.assetid: fc6aa7e5-34dd-4ec2-88bd-16e430361dc7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 261e826043a4f922902de91573a16707897ae6b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4868"></a>Compilador C4868 de aviso (nível 4)

> '_arquivo_(*line_number*)' compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicializadores entre chaves

Os elementos de uma lista de inicializadores entre chaves devem ser avaliadas na ordem da esquerda para a direita. Há dois casos em que o compilador é capaz de garantir nesta ordem: a primeira é quando alguns dos elementos são objetos passados por valor. a segunda é durante a compilação com `/clr` e alguns dos elementos são campos de objetos ou elementos de matriz. Quando o compilador não pode garantir a avaliação da esquerda para direita emite o aviso C4868.

Esse aviso pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para atualização 2 do Visual C++ 2015. Código compilado antes da atualização 2 do Visual C++ 2015 agora pode gerar C4868.

Esse aviso é desativada por padrão. Use `/Wall` para ativar esse aviso.

Para resolver este aviso, considere se a avaliação da esquerda para a direita dos elementos de lista de inicializador é necessária, como quando a avaliação dos elementos pode produzir efeitos colaterais dependente de ordem. Em muitos casos, a ordem na qual os elementos são avaliados não tem um efeito observável.

Se a ordem de avaliação deve ser esquerda para direita, considere se é possível passar os elementos por `const` referência em vez disso. Uma alteração de como isso elimina o aviso no exemplo de código a seguir.

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