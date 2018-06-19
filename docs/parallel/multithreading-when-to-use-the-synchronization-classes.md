---
title: 'Multithread: Quando usar as Classes de sincronização | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- threading [MFC], synchronization classes
- resources [C++], multithreading
- synchronization classes [C++]
- synchronization [C++], multithreading
- controlled resource access [C++]
- synchronization access classes [C++]
- threading [C++], synchronization
- multithreading [C++], synchronization classes
ms.assetid: 4914f54e-68ac-438f-93c9-c013455a657e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b05922b826de81b5192b183e1c0afdfcda189f03
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688252"
---
# <a name="multithreading-when-to-use-the-synchronization-classes"></a>Multithread: quando usar as classes de sincronização
As classes multithread fornecidas com MFC se enquadram em duas categorias: objetos de sincronização ([CSyncObject](../mfc/reference/csyncobject-class.md), [CSemaphore](../mfc/reference/csemaphore-class.md), [CMutex](../mfc/reference/cmutex-class.md), [ CCriticalSection](../mfc/reference/ccriticalsection-class.md), e [CEvent](../mfc/reference/cevent-class.md)) e objetos de acesso de sincronização ([CMultiLock](../mfc/reference/cmultilock-class.md) e [CSingleLock](../mfc/reference/csinglelock-class.md)).  
  
 Classes de sincronização são usados quando o acesso a um recurso deve ser controlado para garantir a integridade do recurso. Classes de sincronização de acesso são usados para acessar esses recursos controlados. Este tópico descreve quando usar cada classe.  
  
 Para determinar qual classe de sincronização, você deve usar, pergunte a série de perguntas a seguir:  
  
1.  O aplicativo precisa aguardar a algo acontecer antes que possa acessar o recurso (por exemplo, dados devem ser recebidos de uma porta de comunicação antes que ele pode ser gravado em um arquivo)?  
  
     Se Sim, use `CEvent`.  
  
2.  Pode mais de um thread em que o mesmo acesso de aplicativo esse recurso ao mesmo tempo (por exemplo, o aplicativo permite windows até cinco modos de exibição no mesmo documento)?  
  
     Se Sim, use `CSemaphore`.  
  
3.  Pode mais de um aplicativo usar esse recurso (por exemplo, o recurso está em uma DLL)?  
  
     Se Sim, use `CMutex`.  
  
     Se não, use `CCriticalSection`.  
  
 **CSyncObject** nunca é usada diretamente. É a classe base para as outras quatro classes de sincronização.  
  
## <a name="example-1-using-three-synchronization-classes"></a>Exemplo 1: Usando três Classes de sincronização  
 Por exemplo, colocar um aplicativo que mantém uma lista de contas. Esse aplicativo permite até três contas a ser examinado em janelas separadas, mas apenas um pode ser atualizado em um determinado momento. Quando uma conta é atualizada, os dados atualizados são enviados pela rede para um arquivo de dados.  
  
 Este aplicativo de exemplo usa os três tipos de classes de sincronização. Porque ele permite até três contas a ser examinado por vez, ele usa `CSemaphore` para limitar o acesso a três objetos de exibição. Quando uma tentativa de exibir uma quarta conta ocorre, o aplicativo em espera até que um dos três primeiros windows fecha ou falhar. Quando uma conta é atualizada, o aplicativo usa `CCriticalSection` para garantir que apenas uma conta é atualizada a cada vez. Depois que a atualização for bem-sucedida, ela sinaliza `CEvent`, que libera um thread que espera para o evento deve ser sinalizado. Esse thread envia os novos dados para o arquivamento de dados.  
  
## <a name="example-2-using-synchronization-access-classes"></a>Exemplo 2: Usando Classes de acesso de sincronização  
 Escolher a classe de sincronização de acesso para usar é ainda mais simples. Se seu aplicativo está relacionado ao acesso a apenas um único recurso controlado, use `CSingleLock`. Se ele precisa acessar qualquer um dos diversos recursos controlados, use `CMultiLock`. No exemplo 1, `CSingleLock` poderia ter sido usado, porque em cada caso, somente um recurso é necessário em um determinado momento.  
  
 Para obter informações sobre como as classes de sincronização são usadas, consulte [Multithreading: como usar as Classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md). Para obter informações sobre a sincronização, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)]. Para obter informações sobre o suporte a multithreading em MFC, consulte [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)