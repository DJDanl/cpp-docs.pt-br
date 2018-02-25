---
title: Dando suporte ao thread livre no provedor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, multithreaded
- threading [C++], providers
ms.assetid: a91270dc-cdf9-4855-88e7-88a54be7cbe8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5cd5ce6b852b490334cbc8d49c6e967efffb3a6e
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="supporting-free-threading-in-your-provider"></a>Dando suporte ao thread livre no provedor
Todas as classes de provedor OLE DB são thread-safe e entradas do registro estão definidas adequadamente. É uma boa ideia para dar suporte ao thread livre para ajudar a fornecer um alto nível de desempenho em situações de multiusuários. Para ajudar a manter seu provedor de thread-safe, você deve verificar que seu código está bloqueado corretamente. Sempre que você escreve ou armazena dados, você deve bloquear o acesso com seções críticas.  
  
 Cada objeto de modelo de provedor do OLE DB tem sua própria seção crítica. Para tornar mais fácil de bloqueio, cada nova classe que você cria deve ser uma classe de modelo, levando a classe pai nome como um argumento.  
  
 O exemplo a seguir mostra como bloquear seu código:  
  
```  
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
  
 Para obter mais informações sobre como proteger seções críticas com `Lock` e `Unlock`, consulte [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
 Você também deve verificar se todos os métodos que você substituir (como `Execute`) são thread-safe.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)