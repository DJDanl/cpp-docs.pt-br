---
title: 'Como: Criar e usar instâncias weak_ptr'
ms.custom: how-to
ms.date: 07/12/2018
ms.topic: conceptual
ms.assetid: 8dd6909b-b070-4afa-9696-f2fc94579c65
ms.openlocfilehash: 1a0e2880e97a77a0c9975553631a6024072745f0
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220316"
---
# <a name="how-to-create-and-use-weakptr-instances"></a>Como: Criar e usar instâncias weak_ptr

Às vezes, um objeto deve armazenar uma maneira de acessar o objeto subjacente de um `shared_ptr` sem fazer com que a contagem de referência seja incrementada. Normalmente, essa situação ocorre quando você tem referências cíclicas entre `shared_ptr` instâncias.

O melhor design é impedir a propriedade compartilhada de ponteiros sempre que possível. No entanto, se você deve ter a propriedade compartilhada de `shared_ptr` instâncias, evite referências cíclicas entre elas. Quando as referências cíclicas forem inevitáveis, ou mesmo preferíveis por algum motivo, use `weak_ptr` para dar a um ou mais dos proprietários uma referência fraca para outro `shared_ptr`. Usando um `weak_ptr`, você pode criar um `shared_ptr` que une a um conjunto existente de instâncias relacionadas, mas somente se o recurso de memória subjacente ainda é válido. Um `weak_ptr` em si não participa da contagem de referência e, portanto, ele não pode impedir que a contagem de referência de Zerar. No entanto, você pode usar um `weak_ptr` para tentar obter uma nova cópia do `shared_ptr` com o qual ele foi inicializado. Se a memória já tiver sido excluída, um `bad_weak_ptr` exceção é lançada. Se a memória ainda for válida, o novo ponteiro compartilhado incrementa a contagem de referência e garante que a memória seja válida, desde o `shared_ptr` variável permanece no escopo.

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra um caso onde `weak_ptr` é usado para garantir a exclusão apropriada de objetos que têm dependências circulares. Ao examinar o exemplo, suponha que ele foi criado somente depois que as soluções alternativas foram consideradas. O `Controller` objetos representam algum aspecto de um processo de máquina, e eles operam independentemente. Cada controlador deve ser capaz de consultar o status dos outros controladores a qualquer momento, e cada um deles contém uma privada `vector<weak_ptr<Controller>>` para essa finalidade. Cada vetor contém uma referência circular e, portanto, `weak_ptr` instâncias são usadas em vez de `shared_ptr`.

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
Status of 0 = O
nStatus of 1 = On
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

Para experimentar, modifique o vetor `others` seja um `vector<shared_ptr<Controller>>`e, em seguida, na saída, observe que nenhum destruidor é invocado quando `TestRun` retorna.

## <a name="see-also"></a>Consulte também

[Ponteiros inteligentes (C++ moderno)](../cpp/smart-pointers-modern-cpp.md)
