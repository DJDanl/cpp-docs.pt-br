---
title: 'Como: recuperar o nome do computador Local (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- computer name, retrieving
- machine name, retrieving
- computer name
ms.assetid: 6c7acb9a-3f9b-43b2-a756-bd4fb859e697
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f02c9d12809ef908415c58c6b04da2597a3a1bfc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33128635"
---
# <a name="how-to-retrieve-the-local-machine-name-ccli"></a>Como recuperar o nome da máquina local (C++/CLI)
O exemplo de código a seguir demonstra a recuperação do nome do computador local (o nome do computador, como ele aparece em uma rede). Você pode fazer isso obtendo o <xref:System.Environment.MachineName%2A> cadeia de caracteres, que é definida no <xref:System.Environment> namespace.  
  
## <a name="example"></a>Exemplo  
  
```  
// machine_name.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   Console::WriteLine("\nMachineName: {0}", Environment::MachineName);  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operações do Windows (C + + CLI)](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)