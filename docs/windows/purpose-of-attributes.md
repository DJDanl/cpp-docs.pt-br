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
ms.openlocfilehash: 2b34ff9641df4d102c2902e5b8ea42a80db4db50
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42607094"
---
# <a name="purpose-of-attributes"></a>Finalidade de atributos

Atributos de estendem o C++ em direções no momento, não é possíveis sem quebrar a estrutura clássica do idioma. Atributos permitem que provedores (DLLs separadas) para estender a funcionalidade de idioma dinamicamente. O objetivo principal de atributos é simplificar a criação de componentes COM, além de aumentar o nível de produtividade do desenvolvedor de componentes. Atributos podem ser aplicados a praticamente qualquer constructo de C++, como classes, membros de dados ou funções de membro. Este é um realce de benefícios fornecidos por essa nova tecnologia:

- Expõe uma convenção de chamada simple e familiar.

- Usa inserido código, que, ao contrário de macros, é reconhecido pelo depurador.

- Permite a fácil derivação das classes base sem os detalhes de implementação cansativo.

- Substitui a grande quantidade de código IDL necessária para um componente com alguns atributos concisos.

Por exemplo, para implementar um coletor de eventos simples para uma classe genérica do ATL, você pode aplicar a [event_receiver](../windows/event-receiver.md) atributo em uma classe específica como `CMyReceiver`. O `event_receiver` atributo, em seguida, é compilado pelo compilador Visual C++, que insere o código apropriado no arquivo de objeto.

```cpp
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