---
title: '&lt;compreende&gt;'
ms.date: 05/28/2020
f1_keywords:
- <span>
helpviewer_keywords:
- span header
ms.openlocfilehash: 27f27acfa84a3ccc42586593747e4657146cbe39
ms.sourcegitcommit: 83ea5df40917885e261089b103d5de3660314104
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/01/2020
ms.locfileid: "85813529"
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

**Opção do compilador:** /std: c + + mais recente

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|||
|-|:-|
|[compreende](span-class.md)| Fornece uma exibição sobre uma sequência de objetos contígua. |

### <a name="operators"></a>Operadores

|||
|-|:-|
|[operador =](span-class.md#op_eq)| Atribuição de span |
|[operador\[\]](span-class.md#op_at)| Acesso a elemento |

### <a name="functions"></a>Funções

|||
|-|:-|
| [as_bytes](span-functions.md#as_bytes)| Obtenha os bytes subjacentes somente leitura da extensão. |
| [as_writable_bytes](span-functions.md#as_writable_bytes) | Obter os bytes subjacentes da extensão. |

### <a name="constants"></a>Constantes

|||
|-|:-|
| **dynamic_extent** | Indica que o tamanho do span é determinado em tempo de execução em vez de tempo de compilação. Quando o número de elementos no span é conhecido no momento da compilação, ele é especificado como o `Extent` parâmetro de modelo. Quando o número não for conhecido até o tempo de execução, especifique `dynamic_extent` em vez disso. |

## <a name="see-also"></a>Veja também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
