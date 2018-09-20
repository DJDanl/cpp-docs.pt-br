---
title: Tipos (C++ – CL) gerenciados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __gc types
- types [C++], CLR
ms.assetid: 1ddd114e-be02-4de7-a4dd-a2d72ad8ff81
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 382228b9e8364d90d7929b4633744071c5eb0c77
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408014"
---
# <a name="managed-types-ccl"></a>Tipos gerenciados (C++/CL)

A sintaxe para a declaração de tipos gerenciados e a criação e uso de objetos desses tipos significativamente alterada de extensões gerenciadas para C++ no Visual C++. Isso foi feito para promover sua integração dentro do sistema de tipo de ISO-c + +. Essas alterações são apresentadas em detalhes nas subseções a seguir.

## <a name="in-this-section"></a>Nesta seção

[Declaração de um tipo de classe gerenciado](../dotnet/declaration-of-a-managed-class-type.md)<br/>
Discute como declarar um gerenciado `class`, `struct`, ou `interface`.

[Declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md)<br/>
Discute como declarar um objeto de tipo de classe de referência usando uma alça de controle.

[Declaração de uma matriz CLR](../dotnet/declaration-of-a-clr-array.md)<br/>
Explica como declarar e inicializar uma matriz.

[Alterações na ordem de inicialização do construtor](../dotnet/changes-in-constructor-initialization-order.md)<br/>
Discute as principais alterações na ordem de inicialização do construtor de classe.

[Alterações na semântica do destruidor](../dotnet/changes-in-destructor-semantics.md)<br/>
Discute a finalização não determinista, `Finalize` versus `Dispose`, ramificações para objetos de referência e use um valor explícito `Finalize`.

**Observação:** a discussão de delegados é adiada até que [delegados e eventos](../dotnet/delegates-and-events.md) para apresentá-los com membros de evento em uma classe, o tópico geral de [declarações de membro em uma classe ou Interface (C + + / CLI) ](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md).

## <a name="see-also"></a>Consulte também

[Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)<br/>
[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)<br/>
[Matrizes](../windows/arrays-cpp-component-extensions.md)