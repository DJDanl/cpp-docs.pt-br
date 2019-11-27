---
title: Como criar e usar instâncias de weak_ptr
ms.custom: how-to
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: 8dd6909b-b070-4afa-9696-f2fc94579c65
ms.openlocfilehash: 32e8d64fdb6449f1d40aec4161bfda54987ca66a
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245596"
---
# <a name="how-to-create-and-use-weak_ptr-instances"></a>Como criar e usar instâncias de weak_ptr

Às vezes, um objeto deve armazenar uma maneira de acessar o objeto subjacente de um [shared_ptr](../standard-library/shared-ptr-class.md) sem fazer com que a contagem de referência seja incrementada. Normalmente, essa situação ocorre quando você tem referências cíclicas entre `shared_ptr` instâncias.

O melhor design é evitar a propriedade compartilhada de ponteiros sempre que possível. No entanto, se você precisar ter Propriedade compartilhada de instâncias de `shared_ptr`, evite referências cíclicas entre elas. Quando as referências cíclicas são inevitáveis ou até mesmo preferíveis por algum motivo, use [weak_ptr](../standard-library/weak-ptr-class.md) para dar a um ou mais proprietários uma referência fraca a outro `shared_ptr`. Usando uma `weak_ptr`, você pode criar um `shared_ptr` que ingresse em um conjunto existente de instâncias relacionadas, mas somente se o recurso de memória subjacente ainda for válido. Uma `weak_ptr` em si não participa da contagem de referência e, portanto, não pode impedir que a contagem de referência vá para zero. No entanto, você pode usar uma `weak_ptr` para tentar obter uma nova cópia da `shared_ptr` com a qual ela foi inicializada. Se a memória já tiver sido excluída, o operador bool do `weak_ptr`retornará `false`. Se a memória ainda for válida, o novo ponteiro compartilhado incrementará a contagem de referência e garantirá que a memória será válida, contanto que a variável `shared_ptr` permaneça no escopo.

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra um caso em que `weak_ptr` é usado para garantir a exclusão adequada de objetos que têm dependências circulares. Ao examinar o exemplo, suponha que ele foi criado somente depois que as soluções alternativas foram consideradas. Os objetos de `Controller` representam algum aspecto de um processo de máquina e operam de forma independente. Cada controlador deve ser capaz de consultar o status dos outros controladores a qualquer momento, e cada um deles contém um `vector<weak_ptr<Controller>>` particular para essa finalidade. Cada vetor contém uma referência circular e, portanto, `weak_ptr` instâncias são usadas em vez de `shared_ptr`.

[!code-cpp[stl_smart_pointers#222](../cpp/codesnippet/CPP/how-to-create-and-use-weak-ptr-instances_1.cpp)]

```Output
Creating Controller0
Creating Controller1
Creating Controller2
Creating Controller3
Creating Controller4
push_back to v[0]: 1
push_back to v[0]: 2
push_back to v[0]: 3
push_back to v[0]: 4
push_back to v[1]: 0
push_back to v[1]: 2
push_back to v[1]: 3
push_back to v[1]: 4
push_back to v[2]: 0
push_back to v[2]: 1
push_back to v[2]: 3
push_back to v[2]: 4
push_back to v[3]: 0
push_back to v[3]: 1
push_back to v[3]: 2
push_back to v[3]: 4
push_back to v[4]: 0
push_back to v[4]: 1
push_back to v[4]: 2
push_back to v[4]: 3
use_count = 1
Status of 1 = On
Status of 2 = On
Status of 3 = On
Status of 4 = On
use_count = 1
Status of 0 = On
Status of 2 = On
Status of 3 = On
Status of 4 = On
use_count = 1
Status of 0 = On
Status of 1 = On
Status of 3 = On
Status of 4 = On
use_count = 1
Status of 0 = On
Status of 1 = On
Status of 2 = On
Status of 4 = On
use_count = 1
Status of 0 = On
Status of 1 = On
Status of 2 = On
Status of 3 = On
Destroying Controller0
Destroying Controller1
Destroying Controller2
Destroying Controller3
Destroying Controller4
Press any key
```

Como um experimento, modifique o `others` de vetor para ser um `vector<shared_ptr<Controller>>`e, em seguida, na saída, observe que nenhum destruidor é invocado quando `TestRun` retorna.

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)
