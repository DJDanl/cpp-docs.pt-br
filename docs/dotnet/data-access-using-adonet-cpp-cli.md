---
title: "Acesso a dados usando ADO.NET (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - ".NET Framework [C++], acesso a dados"
  - "ADO.NET [C++]"
  - "dados [C++], ADO.NET"
  - "acesso a dados [C++], ADO.NET"
  - "bancos de dados [C++], acessando em C++"
ms.assetid: b0cd987d-1ea7-4f76-ba01-cbd52503d06d
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso a dados usando ADO.NET (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ADO.NET é uma API do.NET Framework para acesso a dados e fornece a capacidade e ímpar facilidade de uso por soluções anteriores de acesso a dados.  Esta seção descreve alguns dos problemas que envolvem ADO.NET que são exclusivos para usuários do Visual C\+\+, como o marshaling tipos nativos.  
  
 ADO.NET executa sob Common Language Runtime \(CLR\).  Em virtude disso, qualquer aplicativo que interaja com o ADO.NET também deve atingir CLR.  No entanto, isso não significa que os aplicativos nativos não podem usar ADO.NET.  Esses exemplos demonstrarão como interagir com uma base de dados do ADO.NET de código nativo.  
  
## Nesta seção  
 [Como realizar marshaling de cadeias de caracteres ANSI para ADO.NET](../dotnet/how-to-marshal-ansi-strings-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de cadeias de caracteres BSTR para ADO.NET](../dotnet/how-to-marshal-bstr-strings-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de cadeias de caracteres Unicode para ADO.NET](../dotnet/how-to-marshal-unicode-strings-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de um VARIANT para ADO.NET](../dotnet/how-to-marshal-a-variant-for-adonet-cpp-cli.md)  
  
 [Como realizar marshaling de um SAFEARRAY para ADO.NET](../dotnet/how-to-marshal-a-safearray-for-adonet-cpp-cli.md)  
  
## Seções relacionadas  
  
|Seção|Descrição|  
|-----------|---------------|  
|[ADO.NET](../Topic/ADO.NET.md)|Fornece uma visão geral do ADO.NET, um conjunto de classes que expõe os serviços de acesso a dados ao programador do .NET.|  
|[Creating SQL Server 2005 Objects In Managed Code](http://msdn.microsoft.com/pt-br/5358a825-e19b-49aa-8214-674ce5fed1da)|Descreve como usar as linguagens .NET, incluindo Visual C\+\+, para criar objetos de base de dados como procedimentos armazenados, gatilhos, agregações, funções definidas pelo usuário, e tipos definidos pelo usuário; e para recuperar e atualizar dados de bases de dados do Microsoft SQL Server 2005.|  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md)