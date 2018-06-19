---
title: Impedimento de contenção de Heap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- heap contention
ms.assetid: 797129d7-5f8c-4b0e-8974-bb93217e9ab5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 731fcb2328f789e5c487dc56510bbd6f7ec049ea
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358079"
---
# <a name="avoidance-of-heap-contention"></a>Impedimento de contenção de Heap
Os gerenciadores de cadeia de caracteres padrão fornecidos pelo MFC e ATL são wrappers simples sobre um heap global. Esta pilha global é totalmente thread-safe, que significa que vários threads podem alocar e liberar memória dele simultaneamente, sem a corrupção de heap. Para ajudar a fornecer acesso thread-safe, o heap tem que serializar o acesso a mesmo. Isso geralmente é feito com uma seção crítica ou mecanismo de bloqueio semelhante. Sempre que dois threads tentarem acessar simultaneamente o heap, um thread está bloqueado até que a solicitação do outro thread é concluída. Para muitos aplicativos, essa situação ocorre raramente e o impacto no desempenho do mecanismo de bloqueio do heap é insignificante. No entanto, para aplicativos que acessam com frequência o heap de vários threads de contenção de bloqueio da pilha pode causar o aplicativo seja executado mais lentamente do que se fosse single-threaded (mesmo em computadores com várias CPUs).  
  
 Aplicativos que usam [CStringT](../atl-mfc-shared/reference/cstringt-class.md) são especialmente suscetíveis a contenção de heap porque operações em `CStringT` objetos frequentemente exigem realocação do buffer de cadeia de caracteres.  
  
 Uma maneira de minimizar a contenção de heap entre threads é ter cada thread alocar cadeias de caracteres de um heap particular, o local de thread. Como as cadeias de caracteres é alocado com alocador de um determinado segmento são usados somente no thread, o alocador não precisa ser thread-safe.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir ilustra um procedimento de thread que aloca a sua própria pilha non-thread-safe privada usar cadeias de caracteres nesse thread:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#182](../atl-mfc-shared/codesnippet/cpp/avoidance-of-heap-contention_1.cpp)]  
  
## <a name="comments"></a>Comentários  
 Vários threads poderiam estar em execução usando o mesmo procedimento de thread, mas como cada thread tem sua própria pilha não há nenhum conflito entre threads. Além disso, o fato de que cada heap não é thread-safe oferece um aumento significativo no desempenho, mesmo que apenas uma cópia do thread está em execução. Este é o resultado do heap não usando operações interconectadas caras para proteger contra acesso simultâneo.  
  
 Para um procedimento de thread mais complicado, pode ser conveniente armazenar um ponteiro para o Gerenciador de cadeia de caracteres do thread em um slot de armazenamento local (TLS) do thread. Isso permite que outras funções chamadas pelo procedimento de thread para acessar o Gerenciador de cadeia de caracteres do thread.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)

