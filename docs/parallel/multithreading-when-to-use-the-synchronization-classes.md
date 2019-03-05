---
title: 'Multithreading: Quando usar as Classes de sincronização do MFC'
ms.date: 08/27/2018
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
ms.openlocfilehash: 72cf5310704c1ae959cc012146a03dd32cff4068
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284366"
---
# <a name="multithreading-when-to-use-the-mfc-synchronization-classes"></a>Multithreading: Quando usar as Classes de sincronização do MFC

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

Para obter informações sobre como as classes de sincronização são usadas, consulte [Multithreading: Como usar as Classes de sincronização](multithreading-how-to-use-the-synchronization-classes.md). Para obter informações sobre a sincronização, consulte [sincronização](/windows/desktop/Sync/synchronization) no SDK do Windows. Para obter informações sobre o suporte de multithreading no MFC, consulte [Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md).

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
