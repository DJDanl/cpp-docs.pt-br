---
title: "Referência de contagem (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- AddRef method [C++], reference counting
- reference counting
- AddRef method [C++]
- reference counts
- references, counting
ms.assetid: b1fd4514-6de6-429f-9e60-2777c0d07a3d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: be6aff46df500a55665f85f6f462514985885b9b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="reference-counting"></a>Contagem de referência
COM em si não tentará automaticamente remover um objeto de memória, quando ele achar que o objeto não está sendo usado. Em vez disso, o programador de objeto deve remover o objeto não utilizado. O programador determina se um objeto pode ser removido com base em uma contagem de referência.  
  
 Usa COM o **IUnknown** métodos, [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), para gerenciar a contagem de referência de interfaces em um objeto. As regras gerais para chamar esses métodos são:  
  
-   Sempre que um cliente recebe um ponteiro de interface `AddRef` deve ser chamado na interface.  
  
-   Sempre que o cliente tiver terminado de usar o ponteiro de interface, ele deverá chamar **versão**.  
  
 Em uma implementação simple, cada `AddRef` chamar incrementos e cada **versão** chamar decrementa uma variável de contador dentro do objeto. Quando a contagem retorna para zero, a interface não tem todos os usuários e está livre para remover a mesmo da memória.  
  
 Contagem de referência também pode ser implementado para que cada referência ao objeto (e não para uma interface individual) é contada. Nesse caso, cada `AddRef` e **versão** chamar delegados para uma implementação central no objeto, e **versão** libera o objeto inteiro quando sua contagem de referência chega a zero.  
  
> [!NOTE]
>  Quando um `CComObject`-objeto derivado é construído usando o **novo** operador, a contagem de referência é 0. Portanto, uma chamada para `AddRef` devem ser feitas após a criação com êxito o `CComObject`-objeto derivado.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Gerenciamento de vida útil do objeto por meio de contagem de referência](http://msdn.microsoft.com/library/windows/desktop/ms687260)

