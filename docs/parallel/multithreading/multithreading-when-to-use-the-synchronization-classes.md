---
title: "Multithread: quando usar as classes de sincroniza&#231;&#227;o | Microsoft Docs"
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
  - "acesso a recursos controlados [C++]"
  - "multithreading [C++], classes de sincronização"
  - "recursos [C++], multithreading"
  - "sincronização [C++], multithreading"
  - "classes de acesso de sincronização [C++]"
  - "classes de sincronização [C++]"
  - "threading [C++], sincronização"
  - "threading [MFC], classes de sincronização"
ms.assetid: 4914f54e-68ac-438f-93c9-c013455a657e
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread: quando usar as classes de sincroniza&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes multi\-threaded fornecidas com o MFC podem ser divididas em duas categorias: objetos de sincronização \([CSyncObject](../../mfc/reference/csyncobject-class.md), [CSemaphore](../../mfc/reference/csemaphore-class.md), [CMutex](../../mfc/reference/cmutex-class.md), [CCriticalSection](../Topic/CCriticalSection%20Class.md), e [CEvent](../../mfc/reference/cevent-class.md)\) e objetos de sincronização \([CMultiLock](../../mfc/reference/cmultilock-class.md) e [CSingleLock](../../mfc/reference/csinglelock-class.md)\).  
  
 As classes de sincronização são usadas quando o acesso a um recurso deve ser controlado para assegurar a integridade de recursos.  As classes de acesso de sincronização são usadas para obter acesso a esses recursos controlados.  Este tópico descreve quando usar cada classe.  
  
 Para determinar quais classes de sincronização você deve usar, faça a série seguinte de perguntas:  
  
1.  O aplicativo precisa esperar que algo acontecer antes que possa acessar o recurso \(por exemplo, os dados devem ser recebidos de uma porta de comunicações para que se possa gravar em um arquivo\)?  
  
     Se sim, use `CEvent`.  
  
2.  Pode mais de um thread no mesmo aplicativo acessar esse recurso ao mesmo tempo \(por exemplo, o aplicativo permite até cinco o windows com exibições no mesmo documento\)?  
  
     Se sim, use `CSemaphore`.  
  
3.  Pode mais de um aplicativo usar esse recurso \(por exemplo, o recurso está em uma DLL\)?  
  
     Se sim, use `CMutex`.  
  
     Se não, use `CCriticalSection`.  
  
 **CSyncObject** nunca é usado diretamente.  É a classe base para outras quatro classes de sincronização.  
  
## Exemplo 1: Usando três classes de sincronização  
 Como exemplo, faça um aplicativo que mantém uma lista vinculada de contas.  Esse aplicativo que permite até três contas são verificadas no windows separadas, mas somente uma pode ser atualizado em todas as horários específicos.  Quando uma conta é atualizada, os dados atualizados serão enviados pela rede a um arquivo morto de dados.  
  
 Este aplicativo de exemplo usa todos os três tipos de classes de sincronização.  Porque permite até três contas que sejam verificadas ao mesmo tempo, usar `CSemaphore` para limitar o acesso a três objetos de exibição.  Quando uma tentativa de exibir uma quarta conta ocorre, o aplicativo uma espera até que uma das três primeiras o windows seja encerrada ou falhar.  Quando uma conta é atualizada, o aplicativo usa `CCriticalSection` para garantir que somente uma conta foi atualizada por vez.  Depois que a atualização for bem\-sucedido, sinaliza `CEvent`, que libera um thread que espera o evento a ser sinalizado.  Esse thread envia os novos dados ao arquivo morto de dados.  
  
## Exemplo 2: Usando classes de acesso de sincronização  
 Escolhendo que a classe de acesso de sincronização para usar o mesmo é mais simples.  Se seu aplicativo for estado relacionado com acesso controlado apenas um único recurso, use `CSingleLock`.  Se precisa de acesso a qualquer número de recursos controlados, use `CMultiLock`.  No exemplo 1, `CSingleLock` seria usado, para cada casos a apenas um recurso for necessário em todas as horários específicos.  
  
 Para obter informações sobre como as classes de sincronização são usadas, consulte [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  Para obter informações sobre sincronização, consulte [Sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)].  Para obter informações sobre suporte de multithreading MFC no, consulte [Multithreading com C\+\+ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md).  
  
## Consulte também  
 [Multithread com C\+\+ e MFC](../../parallel/multithreading-with-cpp-and-mfc.md)