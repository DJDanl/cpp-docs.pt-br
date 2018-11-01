---
title: 'Multithreading: Como usar as Classes de sincronização do MFC'
ms.date: 08/27/2018
helpviewer_keywords:
- MFC [C++], multithreading
- threading [MFC], synchronization classes
- resources [C++], multithreading
- thread-safe classes [C++]
- synchronization classes [C++]
- synchronization [C++], multithreading
- threading [MFC], thread-safe class design
- threading [C++], synchronization
- multithreading [C++], synchronization classes
- threading [C++], thread-safe class design
ms.assetid: f266d4c6-0454-4bda-9758-26157ef74cc5
ms.openlocfilehash: 0f8304c3b45f87dadc2317de95a0b30b54baffa0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604159"
---
# <a name="multithreading-how-to-use-the-mfc-synchronization-classes"></a>Multithreading: Como usar as Classes de sincronização do MFC

Sincronizar acesso a recursos entre threads é um problema comum ao escrever aplicativos multi-threaded. Ter dois ou mais threads simultaneamente os mesmos dados podem levar a resultados indesejáveis e imprevisíveis de acesso. Por exemplo, um thread pode estar sendo atualizada o conteúdo de uma estrutura enquanto outro thread esteja lendo o conteúdo da mesma estrutura. Ele é desconhecido que receberá o thread de leitura de dados: os dados antigos, os dados gravados recentemente ou, possivelmente, uma mistura de ambos. MFC fornece uma série de sincronização e classes de acesso de sincronização para ajudar a resolver esse problema. Este tópico explica as classes disponíveis e como usá-los para criar classes thread-safe em um aplicativo típico de vários threads.

Um aplicativo multithread típico tem uma classe que representa um recurso a ser compartilhado entre threads. Uma classe projetada corretamente, totalmente thread-safe não exige que você chamar quaisquer funções de sincronização. Tudo o que é tratado internamente a classe, permitindo que você se concentrar em como usar melhor a classe, não sobre como ele pode obter corrompido. É uma técnica eficaz para a criação de uma classe totalmente thread-safe mesclar a classe de sincronização na classe de recurso. Mesclando as classes de sincronização a classe compartilhada é um processo simples.

Por exemplo, colocar um aplicativo que mantém uma lista de contas. Esse aplicativo permite até três contas a ser examinado em janelas separadas, mas apenas um pode ser atualizado a qualquer momento específico. Quando uma conta é atualizada, os dados atualizados são enviados pela rede para um arquivo de dados.

Este aplicativo de exemplo usa todos os três tipos de classes de sincronização. Como ele permite até três contas a ser examinado, ao mesmo tempo, ele usa [CSemaphore](../mfc/reference/csemaphore-class.md) para limitar o acesso a três objetos de exibição. Quando uma tentativa de exibir uma conta do quarta ocorre, o aplicativo seja aguarda até que uma das três primeiras janelas fecha ou falhar. Quando uma conta é atualizada, o aplicativo usa [CCriticalSection](../mfc/reference/ccriticalsection-class.md) para garantir que apenas uma conta é atualizada a cada vez. Depois que a atualização for bem-sucedida, ele sinaliza [CEvent](../mfc/reference/cevent-class.md), que libera um thread aguardar o evento seja sinalizado. Esse thread envia os novos dados para o arquivamento de dados.

##  <a name="_mfc_designing_a_thread.2d.safe_class"></a> Projetando uma classe Thread-Safe

Para tornar uma classe totalmente thread-safe, primeiro adicione a classe de sincronização adequadas para as classes compartilhadas como um membro de dados. No exemplo anterior de gerenciamento de contas, uma `CSemaphore` membro de dados seria adicionado à classe de exibição, uma `CCriticalSection` membro de dados seria adicionado à classe de lista vinculada e um `CEvent` membro de dados seria adicionado à classe de armazenamento de dados.

Em seguida, adicione chamadas de sincronização para todas as funções de membro que modificam os dados na classe ou acessam um recurso controlado. Em cada função, você deve criar uma [CSingleLock](../mfc/reference/csinglelock-class.md) ou [CMultiLock](../mfc/reference/cmultilock-class.md) do objeto e chame esse objeto `Lock` função. Quando o objeto de bloqueio sai do escopo e é destruído, o destruidor do objeto chama `Unlock` para você, liberar o recurso. É claro, você pode chamar `Unlock` diretamente se desejar.

Projetando sua classe thread-safe, dessa maneira permite que ele seja usado em um aplicativo multithreaded como facilmente como uma classe não thread-safe, mas com um nível mais alto de segurança do. Encapsular o objeto de sincronização e o objeto de sincronização de acesso na classe do recurso fornece todos os benefícios da programação totalmente thread-safe sem o inconveniente de manter o código de sincronização.

O exemplo de código a seguir demonstra esse método por meio de um membro de dados `m_CritSection` (do tipo `CCriticalSection`), declarado na classe de recurso compartilhado e um `CSingleLock` objeto. A sincronização do recurso compartilhado (derivado de `CWinThread`) é tentada, criando um `CSingleLock` do objeto usando o endereço do `m_CritSection` objeto. É feita uma tentativa de bloquear o recurso e, quando obtido, o trabalho é feito no objeto compartilhado. Quando o trabalho for concluído, o recurso é desbloqueado com uma chamada para `Unlock`.

```
CSingleLock singleLock(&m_CritSection);
singleLock.Lock();
// resource locked
//.usage of shared resource...

singleLock.Unlock();
```

> [!NOTE]
> `CCriticalSection`, ao contrário de outras classes de sincronização do MFC, não tem a opção de uma solicitação de tempo limite de bloqueio. O período de espera para um thread seja liberado é infinito.

As desvantagens dessa abordagem são que a classe será um pouco mais lenta do que a mesma classe sem os objetos de sincronização adicionados. Além disso, se houver uma chance de que mais de um thread pode excluir o objeto, a abordagem mesclada talvez nem sempre funciona. Nessa situação, é melhor manter objetos de sincronização separado.

Para obter informações sobre como determinar qual classe de sincronização a ser usado em situações diferentes, consulte [Multithreading: quando usar as Classes de sincronização](multithreading-when-to-use-the-synchronization-classes.md). Para obter mais informações sobre a sincronização, consulte [sincronização](/windows/desktop/Sync/synchronization) no SDK do Windows. Para obter mais informações sobre suporte multithreading no MFC, consulte [Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md).

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)