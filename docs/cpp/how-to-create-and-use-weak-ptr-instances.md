---
title: 'Como: Criar e usar instâncias de weak_ptr'
ms.custom: how-to
ms.date: 07/12/2018
ms.topic: conceptual
ms.assetid: 8dd6909b-b070-4afa-9696-f2fc94579c65
ms.openlocfilehash: 63eed40117d1a79c69bd05e5bd1503d4222f556d
ms.sourcegitcommit: af4ab63866ed09b5988ed53f1bb6996a54f02484
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/05/2019
ms.locfileid: "68787084"
---
# <a name="how-to-create-and-use-weak_ptr-instances"></a>Como: Criar e usar instâncias de weak_ptr

Às vezes, um objeto deve armazenar uma maneira de acessar o objeto subjacente `shared_ptr` de um sem fazer com que a contagem de referência seja incrementada. Normalmente, essa situação ocorre quando você tem referências cíclicas `shared_ptr` entre instâncias.

O melhor design é evitar a propriedade compartilhada de ponteiros sempre que possível. No entanto, se você precisar ter propriedade `shared_ptr` compartilhada de instâncias, evite referências cíclicas entre elas. Quando as referências cíclicas são inevitáveis ou até mesmo preferíveis por algum `weak_ptr` motivo, use para dar a um ou mais dos proprietários uma referência `shared_ptr`fraca a outra. Usando um `weak_ptr`, você pode criar um `shared_ptr` que une a um conjunto existente de instâncias relacionadas, mas somente se o recurso de memória subjacente ainda for válido. Uma `weak_ptr` em si não participa da contagem de referência e, portanto, não pode impedir que a contagem de referência vá para zero. No entanto, você pode `weak_ptr` usar um para tentar obter uma nova cópia do `shared_ptr` com a qual ela foi inicializada. Se a memória já tiver sido excluída, `bad_weak_ptr` uma exceção será lançada. Se a memória ainda for válida, o novo ponteiro compartilhado incrementará a contagem de referência e garantirá que a memória será válida, desde que `shared_ptr` a variável permaneça no escopo.

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra um `weak_ptr` caso em que é usado para garantir a exclusão adequada de objetos que têm dependências circulares. Ao examinar o exemplo, suponha que ele foi criado somente depois que as soluções alternativas foram consideradas. Os `Controller` objetos representam algum aspecto de um processo de máquina e operam de forma independente. Cada controlador deve ser capaz de consultar o status dos outros controladores a qualquer momento, e cada um deles contém um privado `vector<weak_ptr<Controller>>` para essa finalidade. Cada vetor contém uma referência circular e, portanto, `weak_ptr` as instâncias são usadas em `shared_ptr`vez de.

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

Como um experimento, modifique o vetor `others` para ser um `vector<shared_ptr<Controller>>`e, em seguida, na saída, observe que nenhum destruidor é invocado quando `TestRun` retorna.

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)
