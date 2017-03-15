---
title: "Multithread: como usar as classes de sincroniza&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MFC [C++], multithreading"
  - "multithreading [C++], classes de sincronização"
  - "recursos [C++], multithreading"
  - "sincronização [C++], multithreading"
  - "classes de sincronização [C++]"
  - "threading [C++], sincronização"
  - "threading [C++], design de classe thread-safe"
  - "threading [MFC], classes de sincronização"
  - "threading [MFC], design de classe thread-safe"
  - "classes thread-safe [C++]"
ms.assetid: f266d4c6-0454-4bda-9758-26157ef74cc5
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread: como usar as classes de sincroniza&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Sincronizar o acesso a recursos entre threads é um problema comuns ao escrever aplicativos multi\-threaded.  Tendo dois ou mais threads simultaneamente acessar os mesmos dados pode levar a resultados indesejados e imprevisível.  Por exemplo, um thread pode atualizar o conteúdo de uma estrutura enquanto outro thread ler o conteúdo da mesma estrutura.  É desconhecido dados que o thread de leitura receberá: os dados antigos, os dados gravados recentemente, possivelmente uma combinação de ambos.  MFC O fornece um número de classes de sincronização e acesso de sincronização para ajudar a resolver esse problema.  Este tópico explica as classes disponíveis e como usá\-las para criar classes de seguras em um aplicativo multi\-threaded típico.  
  
 Um aplicativo multi\-threaded típico tem uma classe que representa um recurso a ser compartilhado entre threads.  Uma classe corretamente criada, totalmente seguro para threads não requer nenhuma chamar funções de sincronização.  Tudo é tratada internamente para a classe, permitindo que você concentre na melhor como usar a classe, não sobre como pode obter corrompida.  Uma técnica efetiva para criar uma classe totalmente é seguro para threads mesclar a classe de sincronização na classe de recurso.  Mesclar as classes de sincronização na classe compartilhada é um processo simples.  
  
 Como exemplo, faça um aplicativo que mantém uma lista vinculada de contas.  Esse aplicativo que permite até três contas são verificadas no windows separadas, mas somente uma pode ser atualizado em todas as horários específicos.  Quando uma conta é atualizada, os dados atualizados serão enviados pela rede a um arquivo morto de dados.  
  
 Este aplicativo de exemplo usa todos os três tipos de classes de sincronização.  Porque permite até três contas que sejam verificadas ao mesmo tempo, usar [CSemaphore](../mfc/reference/csemaphore-class.md) para limitar o acesso a três objetos de exibição.  Quando uma tentativa de exibir uma quarta conta ocorre, o aplicativo uma espera até que uma das três primeiras o windows seja encerrada ou falhar.  Quando uma conta é atualizada, o aplicativo usa [CCriticalSection](../Topic/CCriticalSection%20Class.md) para garantir que somente uma conta foi atualizada por vez.  Depois que a atualização for bem\-sucedido, sinaliza [CEvent](../mfc/reference/cevent-class.md), que libera um thread que espera o evento a ser sinalizado.  Esse thread envia os novos dados ao arquivo morto de dados.  
  
##  <a name="_mfc_designing_a_thread.2d.safe_class"></a> Criando uma classe seguro para threads  
 Para fazer uma classe totalmente threads segura, primeiro adicione a classe apropriado de sincronização para classes compartilhadas como um membro de dados.  No exemplo anterior de conta\- gerenciamento, um membro de dados de **CSemaphore** será adicionado à classe da exibição, um membro de dados de `CCriticalSection` será adicionado à classe de vincular\- lista, e um membro de dados de `CEvent` será adicionado à classe de armazenamento de dados.  
  
 Em seguida, adicione chamadas de sincronização a todas as funções de membro que modificam os dados na classe ou acessam um recurso controlado.  Em cada função, você deve criar [CSingleLock](../mfc/reference/csinglelock-class.md) ou objeto de [CMultiLock](../mfc/reference/cmultilock-class.md) e chamar a função de `Lock` do objeto.  Quando o objeto de bloqueio sai do escopo e é destruído, o destruidor de objeto chama `Unlock` para você, liberando o recurso.  Naturalmente, você pode chamar diretamente `Unlock` se você deseja.  
  
 Criar sua classe dessa maneira segura permite que é usada em um aplicativo multi\-threaded tão facilmente quanto uma classe não\-thread\- segura, mas com um nível mais alto de segurança.  Encapsular o objeto de sincronização e o objeto de sincronização na classe de recurso fornece todos os benefícios de programar total de threads segura sem a desvantagem de código de manutenção de sincronização.  
  
 O exemplo de código a seguir demonstra esse método usando um membro de dados, `m_CritSection` \(do tipo `CCriticalSection`\), declarado na classe de recurso compartilhado e em um objeto de `CSingleLock` .  A sincronização de recurso compartilhado \(derivado de `CWinThread`\) é tentada criando um objeto de `CSingleLock` usando o endereço do objeto de `m_CritSection` .  Uma tentativa for feita para bloquear o recurso e, quando atingido, o trabalho é feita no objeto compartilhado.  Quando o trabalho for concluído, o recurso está desbloqueado com uma chamada a `Unlock`.  
  
```  
CSingleLock singleLock(&m_CritSection);  
singleLock.Lock();  
// resource locked  
//.usage of shared resource...  
  
singleLock.Unlock();  
```  
  
> [!NOTE]
>  `CCriticalSection`, diferentemente de outras classes de sincronização MFC, não tem a opção de uma solicitação de tempo limite de bloqueio.  O período de espera para que um thread fique livre será infinito.  
  
 As desvantagens desse método são que a classe será um pouco mais lenta que a mesma classe sem os objetos de sincronização adicionados.  Além disso, se houver a possibilidade de mais de um thread pode excluir o objeto, a abordagem mesclada pode não funcionar sempre.  Nessa situação, é melhor manter objetos separados de sincronização.  
  
 Para obter informações sobre como determinar quais classes de sincronização a ser usado em situações diferentes, consulte a [Multithreading: Quando usar as classes de sincronização](../parallel/multithreading-when-to-use-the-synchronization-classes.md).  Para obter mais informações sobre sincronização, consulte [Sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  Para obter mais informações sobre o suporte de multithreading MFC no, consulte [Multithreading com C\+\+ e MFC](../parallel/multithreading-with-cpp-and-mfc.md).  
  
## Consulte também  
 [Multithread com C\+\+ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)