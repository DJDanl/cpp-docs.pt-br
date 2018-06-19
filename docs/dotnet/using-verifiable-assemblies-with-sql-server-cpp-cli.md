---
title: Usando Assemblies verificáveis com SQL Server (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- verifiable assemblies [C++], with SQL Server
ms.assetid: 5248a60d-aa88-4ff3-b30a-b791c3ea2de9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f172eea3108771e129636e9aa95d721d45c99609
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33168640"
---
# <a name="using-verifiable-assemblies-with-sql-server-ccli"></a>Usando assemblies verificáveis com SQL Server (C++/CLI)
Procedimentos armazenados estendidos, são empacotados como bibliotecas de vínculo dinâmico (DLLs) fornecem uma maneira de estender a funcionalidade do SQL Server por meio de funções desenvolvidos com o Visual C++. Procedimentos armazenados estendidos são implementados como funções em DLLs. Além das funções, procedimentos armazenados estendidos também podem definir [tipos definidos pelo usuário](../cpp/classes-and-structs-cpp.md) e [funções de agregação](http://msdn.microsoft.com/en-us/de255454-f45e-4281-81f9-bc61893ac5da) (como SUM ou AVG).  
  
 Quando um cliente executa um procedimento armazenado estendido, pesquisas de SQL Server para a DLL associada com o procedimento armazenado estendido e carrega a DLL. SQL Server chama o procedimento armazenado estendido solicitado e executa-o em um contexto de segurança especificado. O procedimento armazenado estendido e conjuntos de resultados de passagens e retorna os parâmetros de volta para o servidor.  
  
 [!INCLUDE[sqprsqlong](../dotnet/includes/sqprsqlong_md.md)] fornece extensões para o Transact-SQL (T-SQL) para que você possa instalar assemblies verificáveis no SQL Server. O conjunto de permissões do SQL Server Especifica o contexto de segurança, com os seguintes níveis de segurança:  
  
-   Modo irrestrito: executar código em seu próprio risco; código não precisa ser fortemente tipado verificável.  
  
-   Modo de segurança: verificável executar código typesafe; compilado com /CLR: safe.  
  
 Modo de segurança requer que os assemblies executados seja verificável typesafe.  
  
 Para criar e carregar um assembly verificável no SQL Server, use os comandos Transact-SQL CREATE ASSEMBLY e DROP ASSEMBLY da seguinte maneira:  
  
```  
CREATE ASSEMBLY <assemblyName> FROM <'Assembly UNC Path'> WITH   
  PERMISSION_SET <permissions>  
DROP ASSEMBLY <assemblyName>  
```  
  
 O comando PERMISSION_SET Especifica o contexto de segurança e pode ter os valores irrestrito, SAFE ou ESTENDIDOS.  
  
 Além disso, você pode usar o comando CREATE FUNCTION para associar a nomes de método em uma classe:  
  
```  
CREATE FUNCTION <FunctionName>(<FunctionParams>)  
RETURNS returnType  
[EXTERNAL NAME <AssemblyName>:<ClassName>::<StaticMethodName>]  
```  
  
## <a name="example"></a>Exemplo  
 O seguinte script SQL (por exemplo, chamado "MyScript.sql") carrega um assembly no SQL Server e disponibiliza um método de uma classe:  
  
```  
-- Create assembly without external access  
drop assembly stockNoEA  
go  
create assembly stockNoEA  
from   
'c:\stockNoEA.dll'  
with permission_set safe  
  
-- Create function on assembly with no external access  
drop function GetQuoteNoEA  
go  
create function GetQuoteNoEA(@sym nvarchar(10))  
returns real  
external name stockNoEA:StockQuotes::GetQuote  
go  
  
-- To call the function  
select dbo.GetQuoteNoEA('MSFT')  
go  
```  
  
 Scripts SQL podem ser executados interativamente no SQL Query Analyzer ou na linha de comando com o utilitário de sqlcmd.exe. A seguinte linha de comando se conecta ao MyServer, usa o banco de dados padrão, usa uma conexão confiável, Myscript de entradas e saídas MyResult.txt.  
  
```  
sqlcmd -S MyServer -E -i myScript.sql -o myResult.txt  
```  
  
## <a name="see-also"></a>Consulte também  
 [Como: migrar para /CLR: Safe (C + + CLI)](../dotnet/how-to-migrate-to-clr-safe-cpp-cli.md)   
 [Classes e Structs](../cpp/classes-and-structs-cpp.md)