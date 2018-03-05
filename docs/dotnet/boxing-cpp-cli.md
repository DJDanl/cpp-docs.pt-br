---
title: "Conversão boxing (C++ /CLI CLI) | Microsoft Docs"
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
ms.assetid: f4ee27a8-6a34-432d-b9ec-39285d513b23
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: e49c6f82099e6d7dbcfc47079d19228d7a91dc05
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="boxing-ccli"></a>Conversão boxing (C++/CLI)
Conversão boxing é o processo de converter um tipo de valor para o tipo `object` ou a qualquer tipo de interface é implementado pelo tipo de valor. Quando o common language runtime (CLR) caixas de um tipo de valor, ela inclui o valor em uma `System.Object` e os armazena no heap gerenciado. A conversão unboxing extrai o tipo de valor do objeto. A conversão boxing é implícita, a conversão unboxing é explícita.  
  
## <a name="related-articles"></a>Artigos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Como solicitar uma conversão boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)|Descreve como solicitar explicitamente boxing em uma variável.|  
|[Como usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)|Mostra como usar `gcnew` para criar um tipo de valor demarcado que pode ser colocado no heap gerenciado, coletados como lixo.|  
|[Como reverter uma conversão boxing](../dotnet/how-to-unbox.md)|Mostra como converter e modificar um valor.|  
|[Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)|Mostra que uma conversão padrão é escolhida pelo compilador sobre uma conversão que requer conversão.|  
|[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|O artigo de nível superior para programação do .NET na documentação do Visual C++.|