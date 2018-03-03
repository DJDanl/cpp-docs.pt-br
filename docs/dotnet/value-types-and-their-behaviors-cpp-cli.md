---
title: Tipos de valor e seus comportamentos (C + + CLI) | Microsoft Docs
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
- value types
ms.assetid: 5cb872a6-1e0a-429d-853d-df4ab47e8f2a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ccb26e1f054e6914f24982b36f6655fa62fc9f99
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="value-types-and-their-behaviors-ccli"></a>Tipos de valor e seus comportamentos (C++/CLI)
Tipos de valor foram alterados de várias maneiras de extensões gerenciadas para C++ para Visual C++. Nesta seção, vamos examinar o tipo de enum CLR e o tipo de classe de valor, junto com uma olhada boxing e acesso à instância demarcado no heap CLR, bem como uma olhada em ponteiros de fixação e interiores. Houve alterações de vários idiomas nessa área.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Tipo de enum do CLR](../dotnet/value-types-and-their-behaviors-cpp-cli.md)  
 Aborda as alterações na declaração e comportamento de enums.  
  
 [Conversão boxing implícita de tipos de valor](../dotnet/implicit-boxing-of-value-types.md)  
 Discute a motivação para conversão boxing implícita de tipos de valor e as alterações resultante no comportamento.  
  
 [Um identificador de acompanhamento de um valor demarcado](../dotnet/a-tracking-handle-to-a-boxed-value.md)  
 Discute a conversão boxing como implícita do valor de tipos é convertido para um identificador de rastreamento para o objeto de valor Demarcado.  
  
 [Semântica de tipo de valor](../dotnet/value-type-semantics.md)  
 Aborda as alterações a semântica do tipo de valor, incluindo métodos virtuais herdados, construtores de classe, ponteiros internos e fixando ponteiros.  
  
## <a name="see-also"></a>Consulte também  
 [C + + CLI Primer de migração](../dotnet/cpp-cli-migration-primer.md)   
 [Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)