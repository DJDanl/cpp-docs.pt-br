---
title: 'Multithread: Como usar as Classes de sincronização | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 49b0737a794216c4899b280bc049a1cdc0fe0948
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="multithreading-how-to-use-the-synchronization-classes"></a>Multithread: como usar as classes de sincronização
Sincronizar o acesso a recursos entre threads é um problema comum ao escrever aplicativos multithread. Ter dois ou mais threads simultaneamente os mesmos dados podem levar a resultados indesejáveis e imprevisíveis de acesso. Por exemplo, um thread pode ser atualizar o conteúdo de uma estrutura enquanto outro thread está lendo o conteúdo da mesma estrutura. Ele é desconhecido que recebe o thread de leitura de dados: os dados antigos, os dados gravados recentemente ou possivelmente uma mistura de ambos. MFC fornece uma série de sincronização e classes de acesso de sincronização para ajudar a resolver esse problema. Este tópico explica as classes disponíveis e como usá-las para criar classes thread-safe em um aplicativo multithread típico.  
  
 Um aplicativo multithread típico tem uma classe que representa um recurso seja compartilhado entre threads. Uma classe projetada corretamente, totalmente thread-safe não exige que você chamar quaisquer funções de sincronização. Tudo o que é manipulado internamente para a classe, permitindo que você se concentre em como usar melhor a classe, não sobre como ele pode obter corrompido. É uma técnica eficaz para a criação de uma classe thread-safe totalmente para a classe de sincronização de mesclagem para a classe de recurso. As classes de sincronização de mesclagem para a classe compartilhada é um processo simples.  
  
 Por exemplo, colocar um aplicativo que mantém uma lista de contas. Esse aplicativo permite até três contas a ser examinado em janelas separadas, mas apenas um pode ser atualizado em um determinado momento. Quando uma conta é atualizada, os dados atualizados são enviados pela rede para um arquivo de dados.  
  
 Este aplicativo de exemplo usa os três tipos de classes de sincronização. Porque ele permite até três contas a ser examinado por vez, ele usa [CSemaphore](../mfc/reference/csemaphore-class.md) para limitar o acesso a três objetos de exibição. Quando uma tentativa de exibir uma quarta conta ocorre, o aplicativo em espera até que um dos três primeiros windows fecha ou falhar. Quando uma conta é atualizada, o aplicativo usa [CCriticalSection](../mfc/reference/ccriticalsection-class.md) para garantir que apenas uma conta é atualizada a cada vez. Depois que a atualização for bem-sucedida, ela sinaliza [CEvent](../mfc/reference/cevent-class.md), que libera um thread que espera para o evento deve ser sinalizado. Esse thread envia os novos dados para o arquivamento de dados.  
  
##  <a name="_mfc_designing_a_thread.2d.safe_class"></a> Criando uma classe Thread-Safe  
 Para tornar uma classe totalmente thread-safe, adicione primeiro a classe de sincronização adequadas para as classes compartilhadas como um membro de dados. No exemplo anterior de gerenciamento de conta, um **CSemaphore** membro de dados deve ser adicionado para a classe de exibição, uma `CCriticalSection` membro de dados deve ser adicionado à classe de lista vinculada e um `CEvent` membro de dados deve ser adicionado aos dados classe de armazenamento.  
  
 Em seguida, adicione chamadas de sincronização para todas as funções de membro que modificam os dados na classe ou acessam um recurso controlado. Cada função, você deve criar um [CSingleLock](../mfc/reference/csinglelock-class.md) ou [CMultiLock](../mfc/reference/cmultilock-class.md) do objeto e chame esse objeto `Lock` função. Quando o objeto de bloqueio sai do escopo e é destruído, chama o destruidor do objeto `Unlock` para você, liberando o recurso. Obviamente, você pode chamar `Unlock` diretamente se desejar.  
  
 Criando a classe thread-safe dessa maneira permite para ser usado em um aplicativo multithread como facilmente como uma classe non-thread-safe, mas com um nível mais alto de segurança. Encapsula o objeto de sincronização e o objeto de sincronização de acesso na classe do recurso fornece todos os benefícios de programação totalmente thread-safe sem a desvantagem de manter o código de sincronização.  
  
 O exemplo de código a seguir demonstra esse método por meio de um membro de dados, `m_CritSection` (do tipo `CCriticalSection`), declarado na classe de recurso compartilhado e uma `CSingleLock` objeto. A sincronização do recurso compartilhado (derivado de `CWinThread`) é tentada criando um `CSingleLock` objeto usando o endereço do `m_CritSection` objeto. É feita uma tentativa para bloquear o recurso e, quando obtido, o trabalho é realizado no objeto compartilhado. Quando o trabalho for concluído, o recurso está desbloqueado com uma chamada para `Unlock`.  
  
```  
CSingleLock singleLock(&m_CritSection);  
singleLock.Lock();  
// resource locked  
//.usage of shared resource...  
  
singleLock.Unlock();  
```  
  
> [!NOTE]
>  `CCriticalSection`, ao contrário de outras classes de sincronização do MFC, não tem a opção de uma solicitação de bloqueio atingido. O período de espera por um thread seja liberado é infinito.  
  
 A desvantagem dessa abordagem é que a classe será um pouco mais lenta que a mesma classe sem os objetos de sincronização adicionados. Além disso, se houver uma possibilidade de que mais de um thread pode excluir o objeto, a abordagem mesclada pode nem sempre funcionar. Nessa situação, é melhor manter objetos de sincronização separado.  
  
 Para obter informações sobre como determinar qual classe de sincronização a ser usado em situações diferentes, consulte [Multithreading: quando usar as Classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md). Para obter mais informações sobre sincronização, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)]. Para obter mais informações sobre o suporte a multithreading em MFC, consulte [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)