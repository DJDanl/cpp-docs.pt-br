---
title: "Como determinar se o desligamento foi iniciado (C++/CLI) | Microsoft Docs"
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
  - ".NET Framework, desligamento"
  - "aplicativos [C++], desligamento"
  - "desligamento"
  - "encerramento"
ms.assetid: a8d39731-dea8-4f0a-96b7-2a5de09b21d7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como determinar se o desligamento foi iniciado (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra como determinar se o aplicativo ou o .NET Framework estão sendo encerrado no momento.  Isso é útil para acessar os elementos estáticos no .NET Framework, como durante o desligamento, essas construções são terminadas pelo sistema e não é possível usadas.  Verificando a propriedade de <xref:System.Environment.HasShutdownStarted%2A> primeiro, você pode evitar falhas potenciais não acessando esses elementos.  
  
## Exemplo  
  
```  
// check_shutdown.cpp  
// compile with: /clr  
using namespace System;  
int main()   
{  
   if (Environment::HasShutdownStarted)  
      Console::WriteLine("Shutting down.");  
   else  
      Console::WriteLine("Not shutting down.");  
   return 0;  
}  
```  
  
## Consulte também  
 [Operações do Windows](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)