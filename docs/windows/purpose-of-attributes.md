---
title: Finalidade dos atributos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], about attributes
ms.assetid: 3aff8bfa-a2a3-4fcb-a2c6-1d96a2b4c68d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2ca7757c1b9a8ebf034f68b9a380c09d4a5b08f1
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39607018"
---
# <a name="purpose-of-attributes"></a>Finalidade de atributos
Atributos de estendem o C++ em direções no momento, não é possíveis sem quebrar a estrutura clássica do idioma. Atributos permitem que provedores (DLLs separadas) para estender a funcionalidade de idioma dinamicamente. O objetivo principal de atributos é simplificar a criação de componentes COM, além de aumentar o nível de produtividade do desenvolvedor de componentes. Atributos podem ser aplicados a praticamente qualquer constructo de C++, como classes, membros de dados ou funções de membro. Este é um realce de benefícios fornecidos por essa nova tecnologia:  
  
-   Expõe uma convenção de chamada simple e familiar.  
  
-   Usa inserido código, que, ao contrário de macros, é reconhecido pelo depurador.  
  
-   Permite a fácil derivação das classes base sem os detalhes de implementação cansativo.  
  
-   Substitui a grande quantidade de código IDL necessária para um componente com alguns atributos concisos.  
  
 Por exemplo, para implementar um coletor de eventos simples para uma classe genérica do ATL, você pode aplicar a [event_receiver](../windows/event-receiver.md) atributo em uma classe específica como `CMyReceiver`. O `event_receiver` atributo, em seguida, é compilado pelo compilador Visual C++, que insere o código apropriado no arquivo de objeto.  
  
```  
[event_receiver(com)]  
class CMyReceiver   
{  
   void handler1(int i) { ... }  
   void handler2(int i, float j) { ... }  
}  
```  
  
 Você pode configurar o `CMyReceiver` métodos `handler1` e `handler2` para manipular eventos (usando a função intrínseca [hook](../cpp/hook.md)) de uma fonte de evento, você pode criar usando [event_source](../windows/event-source.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../windows/attributed-programming-concepts.md)