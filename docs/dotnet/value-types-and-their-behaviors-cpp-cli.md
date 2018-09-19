---
title: Tipos de valor e seus comportamentos (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- value types
ms.assetid: 5cb872a6-1e0a-429d-853d-df4ab47e8f2a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4d2d980e48a6f948c35faf0c4e42969795ef8dc7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404651"
---
# <a name="value-types-and-their-behaviors-ccli"></a>Tipos de valor e seus comportamentos (C++/CLI)

Tipos de valor foram alterados de várias maneiras de extensões gerenciadas para C++ no Visual C++. Nesta seção, vamos examinar o tipo de enum CLR e o tipo de classe de valor, junto com uma olhada em conversões boxing e acesso à instância demarcado no heap CLR, bem como uma olhada em ponteiros interiores e fixos. Houve alterações de linguagem extensivo nessa área.

## <a name="in-this-section"></a>Nesta seção

[Tipo de enum do CLR](../dotnet/value-types-and-their-behaviors-cpp-cli.md)<br/>
Aborda as alterações na declaração e comportamento de enums.

[Conversão boxing implícita de tipos de valor](../dotnet/implicit-boxing-of-value-types.md)<br/>
Discute a motivação para conversão boxing implícita de tipos de valor e as consequente alterações no comportamento.

[Um identificador de acompanhamento de um valor demarcado](../dotnet/a-tracking-handle-to-a-boxed-value.md)<br/>
Discute a conversão boxing como implícita do valor de tipos se traduz em um identificador de rastreamento para o objeto de valor Demarcado.

[Semântica de tipo de valor](../dotnet/value-type-semantics.md)<br/>
Aborda as alterações à semântica de tipo de valor, incluindo métodos virtuais herdados, construtores da classe padrão, os ponteiros internos e ponteiros de fixação.

## <a name="see-also"></a>Consulte também

[Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)<br/>
[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)