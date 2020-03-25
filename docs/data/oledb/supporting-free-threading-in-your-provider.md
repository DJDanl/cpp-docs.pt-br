---
title: Dando suporte ao thread livre no provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB providers, multithreaded
- threading [C++], providers
ms.assetid: a91270dc-cdf9-4855-88e7-88a54be7cbe8
ms.openlocfilehash: 50e05b70a782dd343031443540790697e980c994
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209528"
---
# <a name="supporting-free-threading-in-your-provider"></a>Dando suporte ao thread livre no provedor

Todas as classes de provedor de OLE DB são thread-safe e as entradas do registro são definidas de acordo. É uma boa ideia dar suporte a Threading gratuito para ajudar a fornecer um alto nível de desempenho em situações multiusuários. Para ajudar a manter seu provedor seguro para thread, você deve verificar se o código está bloqueado corretamente. Sempre que você gravar ou armazenar dados, deverá bloquear o acesso com seções críticas.

Cada objeto de modelo de provedor de OLE DB tem sua própria seção crítica. Para facilitar o bloqueio, cada nova classe criada deve ser uma classe de modelo que leva o nome da classe pai como um argumento.

O exemplo a seguir mostra como bloquear seu código:

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

Para obter mais informações sobre como proteger seções críticas com `Lock` e `Unlock`, consulte [multithreading: como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

Verifique se todos os métodos que você substituir (como `Execute`) são thread-safe.

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)
