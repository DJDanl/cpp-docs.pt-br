---
title: 'Multithreading: Quando usar as classes de sincronização do MFC'
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
ms.openlocfilehash: cb68487e036093ce4718c39c18c9d1e75afe0f7c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512005"
---
# <a name="multithreading-when-to-use-the-mfc-synchronization-classes"></a>Multithreading: Quando usar as classes de sincronização do MFC

As classes multi-threaded fornecidas com o MFC se enquadram em duas categorias: objetos de sincronização ([CSyncObject](../mfc/reference/csyncobject-class.md), [CSemaphore](../mfc/reference/csemaphore-class.md), [CMutex](../mfc/reference/cmutex-class.md), [CCriticalSection](../mfc/reference/ccriticalsection-class.md)e [CEvent](../mfc/reference/cevent-class.md)) e objetos de acesso de sincronização ([ CMultiLock](../mfc/reference/cmultilock-class.md) e [CSingleLock](../mfc/reference/csinglelock-class.md)).

As classes de sincronização são usadas quando o acesso a um recurso deve ser controlado para garantir a integridade do recurso. As classes de acesso de sincronização são usadas para obter acesso a esses recursos controlados. Este tópico descreve quando usar cada classe.

Para determinar qual classe de sincronização deve ser usada, faça a seguinte série de perguntas:

1. O aplicativo precisa aguardar que algo aconteça antes de poder acessar o recurso (por exemplo, os dados devem ser recebidos de uma porta de comunicação antes que possam ser gravados em um arquivo)?

   Em caso afirmativo `CEvent`, use.

2. É possível que mais de um thread no mesmo aplicativo acesse esse recurso de uma só vez (por exemplo, seu aplicativo permite até cinco janelas com exibições no mesmo documento)?

   Em caso afirmativo `CSemaphore`, use.

3. É possível que mais de um aplicativo use esse recurso (por exemplo, o recurso está em uma DLL)?

   Em caso afirmativo `CMutex`, use.

   Se não, use `CCriticalSection`.

`CSyncObject`Nunca é usado diretamente. É a classe base para as outras quatro classes de sincronização.

## <a name="example-1-using-three-synchronization-classes"></a>Exemplo 1: Usando três classes de sincronização

Por exemplo, pegue um aplicativo que mantém uma lista vinculada de contas. Esse aplicativo permite que até três contas sejam examinadas em janelas separadas, mas apenas uma pode ser atualizada em um momento específico. Quando uma conta é atualizada, os dados atualizados são enviados pela rede para um arquivo de dados.

Este aplicativo de exemplo usa todos os três tipos de classes de sincronização. Como ele permite que até três contas sejam examinadas ao mesmo tempo, ele usa `CSemaphore` para limitar o acesso a três objetos de exibição. Quando ocorre uma tentativa de exibir uma quarta conta, o aplicativo aguarda até que uma das três primeiras janelas seja fechada ou falhe. Quando uma conta é atualizada, o aplicativo usa `CCriticalSection` o para garantir que apenas uma conta seja atualizada por vez. Depois que a atualização é realizada com sucesso `CEvent`, ela é sinalizada, que libera um thread Aguardando que o evento seja sinalizado. Esse thread envia os novos dados para o arquivo de dados.

## <a name="example-2-using-synchronization-access-classes"></a>Exemplo 2: Usando classes de acesso de sincronização

Escolher a classe de acesso de sincronização a ser usada é ainda mais simples. Se seu aplicativo estiver preocupado com o acesso apenas a um único recurso controlado `CSingleLock`, use. Se precisar de acesso a qualquer um dos vários recursos controlados, use `CMultiLock`. No exemplo 1, `CSingleLock` teria sido usado, porque, em cada caso, apenas um recurso é necessário em um determinado momento.

Para obter informações sobre como as classes de sincronização são usadas [, consulte Multithreading: Como usar as classes](multithreading-how-to-use-the-synchronization-classes.md)de sincronização. Para obter informações sobre sincronização, consulte [sincronização](/windows/win32/Sync/synchronization) no SDK do Windows. Para obter informações sobre o suporte multithread no MFC, consulte [multithreading C++ com e MFC](multithreading-with-cpp-and-mfc.md).

## <a name="see-also"></a>Consulte também

[Multithreading com C++ e MFC](multithreading-with-cpp-and-mfc.md)
