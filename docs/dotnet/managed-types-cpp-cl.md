---
title: Tipos (C++-CL) gerenciados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- __gc types
- types [C++], CLR
ms.assetid: 1ddd114e-be02-4de7-a4dd-a2d72ad8ff81
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9e7bbd9687c3cc696b35e0284d55a18f59c898cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="managed-types-ccl"></a>Tipos gerenciados (C++/CL)
A sintaxe para a declaração de tipos gerenciados e a criação e uso de objetos desses tipos significativamente alterada de extensões gerenciadas para C++ para Visual C++. Isso foi feito para promover sua integração dentro do sistema de tipo ISO C++. Essas alterações são apresentadas em detalhes nas subseções a seguir.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Declaração de um tipo de classe gerenciado](../dotnet/declaration-of-a-managed-class-type.md)  
 Discute como declarar uma gerenciado `class`, `struct`, ou `interface`.  
  
 [Declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md)  
 Discute como declarar um objeto de tipo de classe de referência usando um identificador de rastreamento.  
  
 [Declaração de uma matriz CLR](../dotnet/declaration-of-a-clr-array.md)  
 Explica como declarar e inicializar uma matriz.  
  
 [Alterações na ordem de inicialização do construtor](../dotnet/changes-in-constructor-initialization-order.md)  
 Aborda as principais alterações na ordem de inicialização do construtor de classe.  
  
 [Alterações na semântica do destruidor](../dotnet/changes-in-destructor-semantics.md)  
 Discute a finalização determinística, `Finalize` versus `Dispose`, ramificações para objetos de referência e use um valor explícito `Finalize`.  
  
 **Observação:** a discussão sobre delegados é adiada até [representantes e eventos](../dotnet/delegates-and-events.md) para apresentá-los com membros de evento em uma classe, o tópico geral de [declarações de membro em uma classe ou Interface (C + + CLI) ](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md).  
  
## <a name="see-also"></a>Consulte também  
 [C + + CLI Primer de migração](../dotnet/cpp-cli-migration-primer.md)   
 [Classes e structs](../windows/classes-and-structs-cpp-component-extensions.md)   
 [Matrizes](../windows/arrays-cpp-component-extensions.md)