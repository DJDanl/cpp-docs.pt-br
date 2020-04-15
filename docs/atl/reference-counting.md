---
title: Contagem de referências (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- AddRef method [C++], reference counting
- reference counting
- AddRef method [C++]
- reference counts
- references, counting
ms.assetid: b1fd4514-6de6-429f-9e60-2777c0d07a3d
ms.openlocfilehash: 095f0ad2ecc1e1a870077899d61a3c594f8cc95f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321735"
---
# <a name="reference-counting"></a>Contagem de referências

O PRÓPRIO COM não tenta automaticamente remover um objeto da memória quando ele pensa que o objeto não está mais sendo usado. Em vez disso, o programador de objetos deve remover o objeto não utilizado. O programador determina se um objeto pode ser removido com base em uma contagem de referência.

O COM `IUnknown` usa os métodos [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release), para gerenciar a contagem de referência de interfaces em um objeto. As regras gerais para chamar esses métodos são:

- Sempre que um cliente `AddRef` recebe um ponteiro de interface, deve ser chamado na interface.

- Sempre que o cliente tiver terminado de `Release`usar o ponteiro de interface, ele deve chamar .

Em uma implementação `AddRef` simples, cada `Release` chamada incrementa e cada chamada decreta uma contravariável dentro do objeto. Quando a contagem retorna a zero, a interface não tem mais usuários e é livre para remover-se da memória.

A contagem de referências também pode ser implementada para que cada referência ao objeto (não a uma interface individual) seja contada. Neste caso, `AddRef` cada `Release` um e chamar delegados para `Release` uma implementação central no objeto, e libera todo o objeto quando sua contagem de referência atinge zero.

> [!NOTE]
> Quando `CComObject`um objeto derivado é construído usando o **novo** operador, a contagem de referência é 0. Portanto, uma chamada `AddRef` deve ser feita `CComObject`após a criação com sucesso do objeto derivado.

## <a name="see-also"></a>Confira também

[Introdução ao COM](../atl/introduction-to-com.md)<br/>
[Gerenciamento de vidas de objetos através da contagem de referências](/windows/win32/com/managing-object-lifetimes-through-reference-counting)
