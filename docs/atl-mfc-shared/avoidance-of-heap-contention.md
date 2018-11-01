---
title: Evitar contenção de Heap
ms.date: 11/04/2016
helpviewer_keywords:
- heap contention
ms.assetid: 797129d7-5f8c-4b0e-8974-bb93217e9ab5
ms.openlocfilehash: c28e5ba01cc2bb1e3cae19087a67cf97e6ac415f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536780"
---
# <a name="avoidance-of-heap-contention"></a>Evitar contenção de Heap

Os gerentes de cadeia de caracteres padrão fornecidos pelo MFC e ATL são invólucros simples sobre um heap global. Essa pilha global é totalmente thread-safe, que significa que vários threads podem alocar e liberar memória dele simultaneamente sem corromper o heap. Para ajudar a fornecer acesso thread-safe, o heap deve serializar o acesso a mesmo. Geralmente, isso é feito com uma seção crítica ou de um mecanismo de bloqueio semelhante. Sempre que dois threads tentarem acessar simultaneamente o heap, um thread é bloqueado até que a solicitação do outro thread é concluída. Para muitos aplicativos, essa situação ocorre raramente e o impacto no desempenho do mecanismo de bloqueio do heap é insignificante. No entanto, para aplicativos que acessam com frequência o heap de vários threads contenção de bloqueio do heap pode fazer com que o aplicativo seja executado mais lentamente do que se fosse single-thread (mesmo em computadores com várias CPUs).

Aplicativos que usam [CStringT](../atl-mfc-shared/reference/cstringt-class.md) são especialmente suscetíveis à contenção de heap porque operações em `CStringT` objetos normalmente exigem a realocação do buffer de cadeia de caracteres.

É uma maneira de aliviar a contenção de heap entre os threads fazer com que cada thread alocar cadeias de caracteres de um heap privado, o local de thread. Desde que as cadeias de caracteres é alocado com o alocador de um determinado thread são usados somente no thread em questão, o alocador não precisa ser thread-safe.

## <a name="example"></a>Exemplo

O exemplo a seguir ilustra um procedimento de thread que aloca a seu próprio heap não thread-safe privada a ser usado para cadeias de caracteres nesse thread:

[!code-cpp[NVC_ATLMFC_Utilities#182](../atl-mfc-shared/codesnippet/cpp/avoidance-of-heap-contention_1.cpp)]

## <a name="comments"></a>Comentários

Vários threads podem estar em execução usando esse mesmo procedimento de thread, mas uma vez que cada thread tem seu próprio heap não há nenhuma contenção entre threads. Além disso, o fato de que cada heap não é thread-safe proporciona um aumento mensurável no desempenho, mesmo que apenas uma cópia do thread está em execução. Esse é o resultado do heap não usando operações sincronizadas caras para proteger contra acesso simultâneo.

Para obter um procedimento de thread mais complicado, pode ser conveniente armazenar um ponteiro para o Gerenciador de cadeia de caracteres do thread em um slot de armazenamento local (TLS) do thread. Isso permite que outras funções chamadas por um procedimento de thread para acessar o Gerenciador de cadeia de caracteres do thread.

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)

