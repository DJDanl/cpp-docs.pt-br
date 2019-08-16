---
title: 'Multithreading: Como usar as classes de sincronização do MFC'
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
ms.openlocfilehash: 26a059e378edb92f5ff7f4e788ded90678e0c129
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511873"
---
# <a name="multithreading-how-to-use-the-mfc-synchronization-classes"></a>Multithreading: Como usar as classes de sincronização do MFC

Sincronizar o acesso a recursos entre threads é um problema comum ao escrever aplicativos multithread. Ter dois ou mais threads acessando simultaneamente os mesmos dados pode levar a resultados indesejáveis e imprevisíveis. Por exemplo, um thread pode estar atualizando o conteúdo de uma estrutura enquanto outro thread está lendo o conteúdo da mesma estrutura. É desconhecido quais dados o thread de leitura receberá: os dados antigos, os dados gravados recentemente ou, possivelmente, uma mistura de ambos. O MFC fornece uma série de classes de acesso de sincronização e sincronização para ajudar a resolver esse problema. Este tópico explica as classes disponíveis e como usá-las para criar classes thread-safe em um aplicativo multithread típico.

Um aplicativo multithread típico tem uma classe que representa um recurso a ser compartilhado entre threads. Uma classe devidamente projetada e totalmente segura para thread não exige que você chame nenhuma função de sincronização. Tudo é manipulado internamente para a classe, permitindo que você se concentre em como usar melhor a classe, e não sobre como ela pode ser corrompida. Uma técnica eficaz para criar uma classe totalmente segura para thread é mesclar a classe de sincronização na classe de recurso. Mesclar as classes de sincronização na classe compartilhada é um processo simples.

Por exemplo, pegue um aplicativo que mantém uma lista vinculada de contas. Esse aplicativo permite que até três contas sejam examinadas em janelas separadas, mas apenas uma pode ser atualizada em um momento específico. Quando uma conta é atualizada, os dados atualizados são enviados pela rede para um arquivo de dados.

Este aplicativo de exemplo usa todos os três tipos de classes de sincronização. Como ele permite que até três contas sejam examinadas ao mesmo tempo, ele usa [CSemaphore](../mfc/reference/csemaphore-class.md) para limitar o acesso a três objetos de exibição. Quando ocorre uma tentativa de exibir uma quarta conta, o aplicativo aguarda até que uma das três primeiras janelas seja fechada ou falhe. Quando uma conta é atualizada, o aplicativo usa [CCriticalSection](../mfc/reference/ccriticalsection-class.md) para garantir que apenas uma conta seja atualizada por vez. Depois que a atualização for realizada com sucesso, ela sinaliza [CEvent](../mfc/reference/cevent-class.md), que libera um thread Aguardando que o evento seja sinalizado. Esse thread envia os novos dados para o arquivo de dados.

##  <a name="_mfc_designing_a_thread.2d.safe_class"></a>Criando uma classe thread-safe

Para tornar uma classe totalmente segura para thread, primeiro adicione a classe de sincronização apropriada às classes compartilhadas como um membro de dados. No exemplo de gerenciamento de conta anterior, um `CSemaphore` membro de dados seria adicionado à classe de exibição, um `CCriticalSection` membro de dados seria adicionado à classe de lista vinculada e um `CEvent` membro de dados seria adicionado à classe de armazenamento de dados.

Em seguida, adicione chamadas de sincronização a todas as funções de membro que modificam os dados na classe ou acessam um recurso controlado. Em cada função, você deve criar um objeto [CSingleLock](../mfc/reference/csinglelock-class.md) ou [CMultiLock](../mfc/reference/cmultilock-class.md) e chamar `Lock` a função desse objeto. Quando o objeto de bloqueio sai do escopo e é destruído, o destruidor do objeto chama `Unlock` para você, liberando o recurso. É claro que você pode chamar `Unlock` diretamente se desejar.

Criar sua classe thread-safe dessa maneira permite que ela seja usada em um aplicativo multithread tão fácil como uma classe sem thread-safe, mas com um nível mais alto de segurança. Encapsular o objeto de sincronização e o objeto de acesso de sincronização na classe do recurso fornece todos os benefícios da programação totalmente segura para threads sem a desvantagem de manter o código de sincronização.

O exemplo de código a seguir demonstra esse método usando um membro de `m_CritSection` dados, ( `CCriticalSection`do tipo), declarado na classe de recurso compartilhado `CSingleLock` e um objeto. A sincronização do recurso compartilhado (derivado de `CWinThread`) é tentada pela criação de um `CSingleLock` objeto `m_CritSection` usando o endereço do objeto. É feita uma tentativa de bloquear o recurso e, quando obtido, o trabalho é feito no objeto compartilhado. Quando o trabalho é concluído, o recurso é desbloqueado com uma chamada `Unlock`para.

```
CSingleLock singleLock(&m_CritSection);
singleLock.Lock();
// resource locked
//.usage of shared resource...

singleLock.Unlock();
```

> [!NOTE]
> `CCriticalSection`, ao contrário de outras classes de sincronização MFC, não tem a opção de uma solicitação de bloqueio cronometrada. O período de espera para que um thread se torne livre é infinito.

As desvantagens dessa abordagem são que a classe será um pouco mais lenta do que a mesma classe sem os objetos de sincronização adicionados. Além disso, se houver uma chance de que mais de um thread possa excluir o objeto, a abordagem mesclada talvez nem sempre funcione. Nessa situação, é melhor manter objetos de sincronização separados.

Para obter informações sobre como determinar qual classe de sincronização usar em diferentes situações [, consulte Multithreading: Quando usar as classes](multithreading-when-to-use-the-synchronization-classes.md)de sincronização. Para obter mais informações sobre sincronização, consulte [sincronização](/windows/win32/Sync/synchronization) no SDK do Windows. Para obter mais informações sobre o suporte a multithreading no MFC, consulte Multithreading [ C++ com e MFC](multithreading-with-cpp-and-mfc.md).

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
