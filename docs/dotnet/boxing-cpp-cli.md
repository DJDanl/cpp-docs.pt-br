---
title: "Convers&#227;o boxing (C++/CLI) | Microsoft Docs"
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
ms.assetid: f4ee27a8-6a34-432d-b9ec-39285d513b23
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#227;o boxing (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O boxing é o processo de converter um tipo de valor no tipo `object` ou a qualquer tipo de interface que é implementado pelo tipo de valor.  Quando Common Language Runtime \(CLR\) como um tipo de valor, envolve o valor em `System.Object` e armazenado no heap gerenciado.  O unboxing extrai o tipo do valor do objeto.  O encapsulamento é implícito; o desencapsulamento é explícito.  
  
## Artigos relacionados  
  
|Nome|Descrição|  
|----------|---------------|  
|[Como fazer uma conversão boxing de solicitação explícita](../Topic/How%20to:%20Explicitly%20Request%20Boxing.md)|Descreve como solicitar explicitamente com o em uma variável.|  
|[Como usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)|Mostra como usar `gcnew` para criar um tipo de valor encaixotado que pode ser colocado no heap gerenciado, com coletados.|  
|[Como converter](../dotnet/how-to-unbox.md)|Mostra como unbox e modificar um valor.|  
|[Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)|Mostra que uma conversão padrão será escolhida pelo compilador sobre uma conversão que requer o com.|  
|[Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|O artigo de nível superior para a programação do .NET na documentação do Visual C\+\+.|