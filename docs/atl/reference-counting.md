---
title: Contagem de referência (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- AddRef method [C++], reference counting
- reference counting
- AddRef method [C++]
- reference counts
- references, counting
ms.assetid: b1fd4514-6de6-429f-9e60-2777c0d07a3d
ms.openlocfilehash: f90c818e58ae7ef6e4a0b771cb53ae5b185d1617
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224338"
---
# <a name="reference-counting"></a>Contagem de referência

O próprio COM não tenta remover automaticamente um objeto da memória quando ele pensa que o objeto não está mais sendo usado. Em vez disso, o programador de objetos deve remover o objeto não utilizado. O programador determina se um objeto pode ser removido com base em uma contagem de referência.

COM usa os `IUnknown` métodos, [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release), para gerenciar a contagem de referência de interfaces em um objeto. As regras gerais para chamar esses métodos são:

- Sempre que um cliente recebe um ponteiro de interface, `AddRef` deve ser chamado na interface.

- Sempre que o cliente tiver terminado de usar o ponteiro de interface, ele deverá chamar `Release` .

Em uma implementação simples, cada `AddRef` chamada é incrementada e cada `Release` chamada diminui uma variável de contador dentro do objeto. Quando a contagem retorna para zero, a interface não tem mais nenhum usuário e está livre para se remover da memória.

A contagem de referência também pode ser implementada para que cada referência ao objeto (não a uma interface individual) seja contada. Nesse caso, cada um `AddRef` e `Release` chamar delega para uma implementação central no objeto e `Release` libera o objeto inteiro quando sua contagem de referência chega a zero.

> [!NOTE]
> Quando um `CComObject` objeto derivado é construído usando o **`new`** operador, a contagem de referência é 0. Portanto, uma chamada para `AddRef` deve ser feita depois de criar com êxito o `CComObject` objeto derivado.

## <a name="see-also"></a>Confira também

[Introdução ao COM](../atl/introduction-to-com.md)<br/>
[Gerenciando tempos de vida de objeto por meio de contagem de referência](/windows/win32/com/managing-object-lifetimes-through-reference-counting)
