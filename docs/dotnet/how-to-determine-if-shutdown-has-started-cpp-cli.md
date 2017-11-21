---
title: 'Como: determinar se o desligamento foi iniciado (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- .NET Framework, shutdown
- shutdown
- termination
- applications [C++], shutdown
ms.assetid: a8d39731-dea8-4f0a-96b7-2a5de09b21d7
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7f4575f212752a43df2b130fbde9aa7264186d6f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-determine-if-shutdown-has-started-ccli"></a>Como determinar se o desligamento foi iniciado (C++/CLI)
O exemplo de código a seguir demonstra como determinar se o aplicativo ou o .NET Framework está encerrando no momento. Isso é útil para acessar elementos estáticos no .NET Framework, porque, durante o desligamento, essas construções são finalizadas pelo sistema e não podem ser usadas de forma confiável. Verificando o <xref:System.Environment.HasShutdownStarted%2A> propriedade primeiro, você pode evitar possíveis falhas não acessar esses elementos.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Operações do Windows (C + + CLI)](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)