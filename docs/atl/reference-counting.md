---
title: Contagem (ATL) de referências | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- AddRef method [C++], reference counting
- reference counting
- AddRef method [C++]
- reference counts
- references, counting
ms.assetid: b1fd4514-6de6-429f-9e60-2777c0d07a3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1469bef0ef41c72e2ff5e59017088cd63f0f9c79
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43194592"
---
# <a name="reference-counting"></a>Contagem de referência
COM em si não tentará automaticamente remover um objeto de memória quando se considera que o objeto não está sendo usado. Em vez disso, o programador do objeto deve remover o objeto não utilizado. O programador determina se um objeto pode ser removido com base em uma contagem de referência.  
  
 COM usa o `IUnknown` métodos, [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), para gerenciar a contagem de referência de interfaces em um objeto. As regras gerais para chamar esses métodos são:  
  
-   Sempre que um cliente recebe um ponteiro de interface `AddRef` deve ser chamado na interface.  
  
-   Sempre que o cliente tiver terminado de usar o ponteiro de interface, ela deve chamar `Release`.  
  
 Em uma implementação simple, cada `AddRef` chamar incrementos e cada `Release` chamar decrementa uma variável de contador dentro do objeto. Quando retorna a contagem como zero, a interface não tem todos os usuários e está livre para remover a mesmo da memória.  
  
 Contagem de referência também pode ser implementado para que cada referência ao objeto (não para uma interface individual) é contada. Nesse caso, cada `AddRef` e `Release` chamar delegados para uma implementação central no objeto, e `Release` libera o objeto inteiro, quando sua contagem de referência chega a zero.  
  
> [!NOTE]
>  Quando um `CComObject`-derivada do objeto é construído usando o **nova** operador, a contagem de referência é 0. Portanto, uma chamada para `AddRef` deve ser feita após a criação com êxito o `CComObject`-objeto derivado.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução a COM](../atl/introduction-to-com.md)   
 [Gerenciando os tempos de vida do objeto por meio de contagem de referência](/windows/desktop/com/managing-object-lifetimes-through-reference-counting)

