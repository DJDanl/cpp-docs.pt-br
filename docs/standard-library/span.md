---
title: '&lt;compreende&gt;'
description: Referência de API para o namespace de span da biblioteca de modelos padrão (STL), que fornece uma exibição leve sobre uma sequência contígua de objetos.
ms.date: 05/28/2020
f1_keywords:
- <span>
helpviewer_keywords:
- span header
ms.openlocfilehash: f4c6b141dfea6464e58d06e221a39a693469d31c
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039866"
---
# <a name="ltspangt"></a>&lt;compreende&gt;

Um `span` é uma exibição em uma sequência de objetos contígua. Ele fornece acesso seguro rápido e limitado. Ao contrário de `vector` ou `array` , ele não "possui" os elementos aos quais ele fornece acesso.

Consulte [classe span](span-class.md) para obter informações detalhadas. Veja um exemplo de como um Span pode ser usado:

```cpp
#include <span>
#include <iostream>

void Show(std::span<int> someValues)
{
    // show values in reverse
    for (auto rIt = someValues.rbegin(); rIt != someValues.rend(); ++rIt)
    {
        std::cout << *rIt;
    }

    // show a subspan
    for (auto& i : someValues.subspan(1, 2))
    {
        std::cout << i;
    }
}

int main()
{
    int numbers[]{ 0,1,2,3,4 };
    Show(numbers); // note conversion from array to span
}
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<span>

**Namespace:** std

**Opção do compilador:** [/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md)

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|:-|
|[compreende](span-class.md)| Fornece uma exibição sobre uma sequência de objetos contígua. |

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|:-|
|[operador =](span-class.md#op_eq)| Atribuição de span |
|[operador\[\]](span-class.md#op_at)| Acesso a elemento |

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|:-|
| [as_bytes](span-functions.md#as_bytes)| Obtenha os bytes subjacentes somente leitura da extensão. |
| [as_writable_bytes](span-functions.md#as_writable_bytes) | Obter os bytes subjacentes da extensão. |

### <a name="constants"></a>Constantes

|Nome|Descrição|
|-|:-|
| **dynamic_extent** | Indica que o tamanho do span é determinado em tempo de execução em vez de tempo de compilação. Quando o número de elementos no span é conhecido no momento da compilação, ele é especificado como o `Extent` parâmetro de modelo. Quando o número não for conhecido até o tempo de execução, especifique `dynamic_extent` em vez disso. |

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
