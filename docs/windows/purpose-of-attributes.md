---
title: A finalidade dos atributos | Microsoft Docs
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
ms.openlocfilehash: 0ea3b731cc22d144e2e20dc70f14e6b0b76b1479
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="purpose-of-attributes"></a>Finalidade de atributos
Atributos estendem C++ em direções atualmente não é possíveis sem quebrar a estrutura clássica do idioma. Atributos permitem que provedores (DLLs separadas) para estender a funcionalidade de idioma dinamicamente. O objetivo principal de atributos é simplificar a criação de componentes COM, além de aumentar o nível de produtividade do desenvolvedor do componente. Atributos podem ser aplicados a praticamente qualquer construção C++, como classes, membros de dados ou funções de membro. Um realce dos benefícios fornecidos por esta nova tecnologia é o seguinte:  
  
-   Expõe uma convenção de chamada simple e familiar.  
  
-   Usa inserido o código, que, ao contrário das macros, é reconhecido pelo depurador.  
  
-   Permite o fácil derivação de classes base sem os detalhes de implementação penosa.  
  
-   Substitui a grande quantidade de código IDL exigido por um componente com alguns atributos concisos.  
  
 Por exemplo, para implementar um coletor de eventos simples para uma classe genérica do ATL, você pode aplicar o [event_receiver](../windows/event-receiver.md) atributo a uma classe específica como `CMyReceiver`. O **event_receiver** atributo, em seguida, é compilado, o compilador do Visual C++, que insere o código apropriado para o arquivo de objeto.  
  
```  
[event_receiver(com)]  
class CMyReceiver   
{  
   void handler1(int i) { ... }  
   void handler2(int i, float j) { ... }  
}  
```  
  
 Você pode, em seguida, configurar o **CMyReceiver** métodos `handler1` e `handler2` para tratar eventos (usando a função intrínseca [hook](../cpp/hook.md)) de uma fonte de evento, você pode criar usando [event_source](../windows/event-source.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../windows/attributed-programming-concepts.md)