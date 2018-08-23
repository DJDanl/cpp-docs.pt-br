---
title: 'Multithreading: Quando usar as Classes de sincronização | Microsoft Docs'
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
ms.openlocfilehash: b3556bace6c578edec8eaedffb528d21cb1644f5
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606058"
---
# <a name="multithreading-when-to-use-the-synchronization-classes"></a>Multithread: quando usar as classes de sincronização
Multithread classes fornecidas com o MFC se enquadram em duas categorias: objetos de sincronização ([CSyncObject](../mfc/reference/csyncobject-class.md), [CSemaphore](../mfc/reference/csemaphore-class.md), [CMutex](../mfc/reference/cmutex-class.md), [ CCriticalSection](../mfc/reference/ccriticalsection-class.md), e [CEvent](../mfc/reference/cevent-class.md)) e objetos de acesso de sincronização ([CMultiLock](../mfc/reference/cmultilock-class.md) e [CSingleLock](../mfc/reference/csinglelock-class.md)).  
  
Classes de sincronização são usadas quando o acesso a um recurso deve ser controlado para garantir a integridade do recurso. Classes de acesso de sincronização são usadas para obter acesso a esses recursos controlados. Este tópico descreve quando usar cada classe.  
  
Para determinar qual classe de sincronização, você deve usar, pergunte a série de perguntas a seguir:  
  
1. O aplicativo precisa esperar que algo aconteça antes que possa acessar o recurso (por exemplo, dados devem ser recebidos de uma porta de comunicações antes que ele pode ser gravado em um arquivo)?  
  
     Se Sim, usar `CEvent`.  
  
2. Pode mais de um thread dentro do mesmo acesso de aplicativo desse recurso ao mesmo tempo (por exemplo, seu aplicativo permite que até cinco janelas com exibições no mesmo documento)?  
  
     Se Sim, usar `CSemaphore`.  
  
3. Pode mais de um aplicativo usar esse recurso (por exemplo, o recurso está em uma DLL)?  
  
     Se Sim, usar `CMutex`.  
  
     Se não, use `CCriticalSection`.  
  
`CSyncObject` nunca é usado diretamente. É a classe base para as outras quatro classes de sincronização.  
  
## <a name="example-1-using-three-synchronization-classes"></a>Exemplo 1: Usando três Classes de sincronização  
 
Por exemplo, colocar um aplicativo que mantém uma lista de contas. Esse aplicativo permite até três contas a ser examinado em janelas separadas, mas apenas um pode ser atualizado a qualquer momento específico. Quando uma conta é atualizada, os dados atualizados são enviados pela rede para um arquivo de dados.  
  
Este aplicativo de exemplo usa todos os três tipos de classes de sincronização. Como ele permite até três contas a ser examinado, ao mesmo tempo, ele usa `CSemaphore` para limitar o acesso a três objetos de exibição. Quando uma tentativa de exibir uma conta do quarta ocorre, o aplicativo seja aguarda até que uma das três primeiras janelas fecha ou falhar. Quando uma conta é atualizada, o aplicativo usa `CCriticalSection` para garantir que apenas uma conta é atualizada a cada vez. Depois que a atualização for bem-sucedida, ele sinaliza `CEvent`, que libera um thread aguardar o evento seja sinalizado. Esse thread envia os novos dados para o arquivamento de dados.  
  
## <a name="example-2-using-synchronization-access-classes"></a>Exemplo 2: Usando Classes de acesso de sincronização  
 
Escolhendo qual classe de acesso de sincronização para usar é ainda mais simples. Se seu aplicativo está preocupado com o acesso a apenas um único recurso controlado, use `CSingleLock`. Se ele precisa acessar qualquer um dos diversos recursos controlados, use `CMultiLock`. No exemplo 1, `CSingleLock` seria usada, porque em cada caso, apenas um recurso é necessário em um determinado momento.  
  
Para obter informações sobre como as classes de sincronização são usadas, consulte [Multithreading: como usar as Classes de sincronização](../parallel/multithreading-how-to-use-the-synchronization-classes.md). Para obter informações sobre a sincronização, consulte [sincronização](http://msdn.microsoft.com/library/windows/desktop/ms686353) no SDK do Windows. Para obter informações sobre o suporte de multithreading no MFC, consulte [Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 
[Multithreading com C++ e MFC](../parallel/multithreading-with-cpp-and-mfc.md)