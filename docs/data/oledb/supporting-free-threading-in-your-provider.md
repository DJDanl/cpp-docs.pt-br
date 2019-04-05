---
title: Dando suporte ao thread livre no provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB providers, multithreaded
- threading [C++], providers
ms.assetid: a91270dc-cdf9-4855-88e7-88a54be7cbe8
ms.openlocfilehash: a2afb7354dd0447375ee6205b7c5d9a4755aa4b8
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59025332"
---
# <a name="supporting-free-threading-in-your-provider"></a>Dando suporte ao thread livre no provedor

Todas as classes de provedor OLE DB são thread-safe e entradas do registro serão definidas de acordo. É uma boa ideia para dar suporte a threading livre para ajudar a fornecer um alto nível de desempenho em situações de multiusuários. Para ajudar a manter seu provedor de thread-safe, você deve verificar que seu código está bloqueado corretamente. Sempre que você escreve ou armazena dados, você deve bloquear o acesso com seções críticas.

Cada objeto de modelo de provedor do OLE DB tem sua própria seção crítica. Para tornar mais fácil de bloqueio, cada nova classe que você cria deve ser uma classe de modelo usando a classe pai nome como um argumento.

O exemplo a seguir mostra como bloquear o seu código:

```cpp
template <class T>
class CMyObject<T> : public...

HRESULT MyObject::MyMethod(void)
{
   T* pT = (T*)this;      // this gets the parent class

// You don't need to do anything if you are only reading information

// If you want to write information, do the following:
   pT->Lock();         // engages critical section in the object
   ...;                // write whatever information you wish
   pT->Unlock();       // disengages the critical section
}
```

Para obter mais informações sobre como proteger seções críticas com `Lock` e `Unlock`, consulte [Multithreading: Como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

Verifique se todos os métodos que você substituir (como `Execute`) são thread-safe.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)