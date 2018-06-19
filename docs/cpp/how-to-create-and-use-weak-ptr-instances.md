---
title: 'Como: criar e usar instâncias weak_ptr | Microsoft Docs'
ms.custom: how-to
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8dd6909b-b070-4afa-9696-f2fc94579c65
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8fbbf9d3b427c2451fafe0fae93a531dfd45ad8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32415139"
---
# <a name="how-to-create-and-use-weakptr-instances"></a>Como criar e usar instâncias weak_ptr
Às vezes, um objeto deve armazenar uma maneira de acessar o objeto subjacente de um `shared_ptr` sem fazer com que a contagem de referência a ser incrementado. Normalmente, essa situação ocorre quando você tem referências cíclicas entre `shared_ptr` instâncias.  
  
 O melhor design é evitar compartilham a propriedade dos ponteiros sempre que puder. No entanto, se a propriedade deve ter sido compartilhada `shared_ptr` instâncias, evitar referências cíclicas entre eles. Quando a referências cíclicas são inevitáveis, ou até mesmo preferível por alguma razão, use `weak_ptr` para dar a um ou mais dos proprietários uma referência fraca a outro `shared_ptr`. Usando um `weak_ptr`, você pode criar um `shared_ptr` que ingressa em um conjunto existente de instâncias relacionadas, mas apenas se o recurso de memória subjacente ainda é válido. Um `weak_ptr` em si não participa na contagem de referência e, portanto, ele não pode impedir que a contagem de referência entre a zero. No entanto, você pode usar um `weak_ptr` para tentar obter uma nova cópia do `shared_ptr` com o qual ele foi inicializado. Se a memória já tiver sido excluída, um **bad_weak_ptr** exceção será lançada. Se a memória ainda é válida, o ponteiro compartilhado incrementa a contagem de referência e garante que a memória será válida enquanto o `shared_ptr` variável permanece em escopo.  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir mostra um caso onde `weak_ptr` é usado para garantir a exclusão correta de objetos que têm dependências circulares. Como examinar o exemplo, suponha que foi criado somente depois que as soluções alternativas foram consideradas. O `Controller` objetos representam algum aspecto de um processo de máquina, e eles operam independentemente. Cada controlador deve ser capaz de consultar o status de outros controladores a qualquer momento, e cada uma contém uma particular `vector<weak_ptr<Controller>>` para essa finalidade. Cada vetor contém uma referência circular e, portanto, `weak_ptr` instâncias são usadas em vez de `shared_ptr`.  
  
 [!code-cpp[stl_smart_pointers#222](../cpp/codesnippet/CPP/how-to-create-and-use-weak-ptr-instances_1.cpp)]  
  
```Output  
Creating Controller0Creating Controller1Creating Controller2Creating Controller3Creating Controller4push_back to v[0]: 1push_back to v[0]: 2push_back to v[0]: 3push_back to v[0]: 4push_back to v[1]: 0push_back to v[1]: 2push_back to v[1]: 3push_back to v[1]: 4push_back to v[2]: 0push_back to v[2]: 1push_back to v[2]: 3push_back to v[2]: 4push_back to v[3]: 0push_back to v[3]: 1push_back to v[3]: 2push_back to v[3]: 4push_back to v[4]: 0push_back to v[4]: 1push_back to v[4]: 2push_back to v[4]: 3use_count = 1Status of 1 = OnStatus of 2 = OnStatus of 3 = OnStatus of 4 = Onuse_count = 1Status of 0 = OnStatus of 2 = OnStatus of 3 = OnStatus of 4 = Onuse_count = 1Status of 0 = OnStatus of 1 = OnStatus of 3 = OnStatus of 4 = Onuse_count = 1Status of 0 = OnStatus of 1 = OnStatus of 2 = OnStatus of 4 = Onuse_count = 1Status of 0 = OnStatus of 1 = OnStatus of 2 = OnStatus of 3 = OnDestroying Controller0Destroying Controller1Destroying Controller2Destroying Controller3Destroying Controller4Press any key  
```  
  
 Como uma experiência, modifique o vetor de `others` para ser um `vector<shared_ptr<Controller>>`e, em seguida, na saída, observe que nenhuma destruidores são invocados quando `TestRun` retorna.  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md)