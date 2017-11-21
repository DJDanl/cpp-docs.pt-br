---
title: "Como: recuperar o nome de usuário atual (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- current user names
- user names, retrieving
- UserName string
ms.assetid: 91679571-d029-41f5-b657-1460c81c608a
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c4738c829f346126dfed7990c50186a7c267df1a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-retrieve-the-current-username-ccli"></a>Como recuperar o nome de usuário atual (C++/CLI)
O exemplo de código a seguir demonstra a recuperação do nome do usuário atual (o nome do usuário conectado no Windows). O nome é armazenado no <xref:System.Environment.UserName%2A> cadeia de caracteres, que é definida no <xref:System.Environment> namespace.  
  
## <a name="example"></a>Exemplo  
  
```  
// username.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   Console::WriteLine("\nCurrent user: {0}", Environment::UserName);  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operações do Windows (C + + CLI)](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)