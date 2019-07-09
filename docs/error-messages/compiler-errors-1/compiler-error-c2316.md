---
title: Erro do compilador C2316
ms.date: 07/08/2019
f1_keywords:
- C2316
helpviewer_keywords:
- C2316
ms.assetid: 9ad08eb5-060b-4eb0-8d66-0dc134f7bf67
ms.openlocfilehash: 5a3d9052775a5e1cbedfd58ccaaf0ff039a8475d
ms.sourcegitcommit: 07b34ca1c1fecced9fadc95de15dc5fee4f31e5a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2019
ms.locfileid: "67693440"
---
# <a name="compiler-error-c2316"></a>Erro do compilador C2316

> '*class_type*': não pode ser detectado porque o destruidor e/ou o construtor de cópia é inacessíveis ou foram excluídos

Uma exceção foi capturada por valor ou por referência, mas o construtor de cópia, o operador de atribuição, ou ambos estavam inacessíveis.

## <a name="remarks"></a>Comentários

Alterações de conformidade no Visual Studio 2015 feitas a esse erro se aplicam a instruções catch incorreta de exceções de MFC derivadas de `CException`. Porque `CException` tem um construtor de cópia privada herdada, a classe e seus derivados não podem ser copiados e não podem ser passados por valor, que também significa que eles não podem ser detectados pelo valor. Capture as instruções que exceções de MFC capturadas por valor anteriormente levou a exceções não identificadas no tempo de execução. Agora, o compilador identifica essa situação corretamente e relata o erro C2316. Para corrigir esse problema, recomendamos que use as macros MFC TRY/CATCH em vez de escrever seus próprios manipuladores de exceção. Se não for apropriada para seu código, capture exceções de MFC por referência.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2316 e mostra uma maneira de corrigir isso:

```cpp
// C2316.cpp
// compile with: /EHsc
#include <stdio.h>

struct B
{
public:
    B() {}
    // Delete the following line to resolve.
private:
    // copy constructor
    B(const B&) {}
};

void f(const B&)
{
}

int main()
{
    try
    {
        B aB;
        f(aB);
    }
    catch (B b)    // C2316
    {
        printf_s("Caught an exception!\n");
    }
}
```
