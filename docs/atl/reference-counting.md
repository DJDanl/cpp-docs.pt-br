---
title: "Contagem de refer&#234;ncia | Microsoft Docs"
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
  - "Método AddRef [C++]"
  - "Método AddRef [C++], contagem de referência"
  - "contagem de referência"
  - "as contagens de referência"
  - "referências, contagem"
ms.assetid: b1fd4514-6de6-429f-9e60-2777c0d07a3d
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Contagem de refer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

COM próprio não tenta automaticamente remover um objeto de memória quando acha que o objeto não está sendo usado.  Em vez de isso, o programador do objeto deve remover o objeto não usado.  O programador determina se um objeto pode ser removido com base em uma contagem de referência.  
  
 COM usa os métodos de **IUnknown** , [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) e [Versão](http://msdn.microsoft.com/library/windows/desktop/ms682317), para gerenciar contagem de referência das interfaces em um objeto.  As regras gerais para chamar esses métodos são:  
  
-   Sempre que um cliente recebe um ponteiro de interface, `AddRef` deve ser chamado a interface.  
  
-   Sempre que o cliente tiver terminado de usar o ponteiro de interface, deve chamar **Versão**.  
  
 Em uma implementação simples, os incrementos de cada chamada de `AddRef` e cada **Versão** chamam diminuições uma variável de contagem do objeto.  Quando retorna a contagem de zero, a interface ainda não tiverem todos os usuários e estão livres se remova de memória.  
  
 Contagem de referência também pode ser implementada para que cada referência ao objeto \(não uma a interface individual é após\).  Em esse caso, cada `AddRef` e representantes de chamada de **Versão** a uma implementação central no objeto e, **Versão** liberam o objeto inteiro quando a contagem de referência atinge zero.  
  
> [!NOTE]
>  Quando `CComObject`\- o objeto derivado é construído usando o operador de **new** , contagem de referência é 0.  Portanto, uma chamada a `AddRef` deve ser feito após ter criado com êxito `CComObject`objeto derivado de.  
  
## Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Managing Object Lifetimes through Reference Counting](http://msdn.microsoft.com/library/windows/desktop/ms687260)