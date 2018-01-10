---
title: Acesso a dados usando ADO.NET (C++ /CLI CLI) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ADO.NET [C++]
- .NET Framework [C++], data access
- databases [C++], accessing in C++
- data access [C++], ADO.NET
- data [C++], ADO.NET
ms.assetid: b0cd987d-1ea7-4f76-ba01-cbd52503d06d
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fb7d184ebdb537c02b79a412d69a4bdcaabde424
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="data-access-using-adonet-ccli"></a>Acesso a dados usando ADO.NET (C++/CLI)
ADO.NET é a API do .NET Framework para acesso a dados e fornece o poder e a facilidade de uso sem correspondência por soluções de acesso de dados anterior. Esta seção descreve alguns dos problemas que envolvem ADO.NET que são exclusivos para usuários do Visual C++, como empacotamento tipos nativos.  
  
 ADO.NET é executado sob o tempo de execução do CLR (Common Language). Portanto, qualquer aplicativo que interage com o ADO.NET também deve usar o CLR. No entanto, isso não significa que aplicativos nativos não é possível usar o ADO.NET. Esses exemplos demonstrará como interagir com um banco de dados do ADO.NET do código nativo.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Como realizar marshaling de cadeias de caracteres ANSI para ADO.NET (C++/CLI)](../dotnet/how-to-marshal-ansi-strings-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de cadeias de caracteres BSTR para ADO.NET (C++/CLI)](../dotnet/how-to-marshal-bstr-strings-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de cadeias de caracteres Unicode para ADO.NET (C++/CLI)](../dotnet/how-to-marshal-unicode-strings-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de um VARIANT para ADO.NET (C++/CLI)](../dotnet/how-to-marshal-a-variant-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de um SAFEARRAY para ADO.NET (C++/CLI)](../dotnet/how-to-marshal-a-safearray-for-adonet-cpp-cli.md)  
  
## <a name="related-sections"></a>Seções relacionadas  
  
|Seção|Descrição|  
|-------------|-----------------|  
|[ADO.NET](/dotnet/framework/data/adonet/index)|Fornece uma visão geral do ADO.NET, um conjunto de classes que expõem serviços de acesso de dados para o programador .NET.|  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)