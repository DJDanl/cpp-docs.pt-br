---
title: "Como determinar o estado interativo do usu&#225;rio (C++/CLI) | Microsoft Docs"
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
  - "estado interativo do usuário"
  - "Visual C++, estado interativo do usuário"
ms.assetid: 9f52323e-38b8-4a41-9b1d-052012ad839b
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como determinar o estado interativo do usu&#225;rio (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra como determinar se o código está sendo executado em um contexto de usuário interativa.  Se <xref:System.Environment.UserInteractive%2A> for false, o código está sendo executado como um processo do serviço ou de dentro de um aplicativo Web, nesse caso você tentar interagir com o usuário.  
  
## Exemplo  
  
```  
// user_interactive.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   if ( Environment::UserInteractive )  
      Console::WriteLine("User interactive");  
   else  
      Console::WriteLine("Noninteractive");  
   return 0;  
}  
```  
  
## Consulte também  
 [Operações do Windows](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)