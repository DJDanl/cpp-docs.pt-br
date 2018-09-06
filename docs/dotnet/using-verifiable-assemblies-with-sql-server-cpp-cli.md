---
title: Usando Assemblies verificáveis com SQL Server (C + + / CLI) | Microsoft Docs
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
ms.openlocfilehash: bbd42d3d51921ccab01dfdcaed9ad988e22ae9a8
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43894692"
---
# <a name="using-verifiable-assemblies-with-sql-server-ccli"></a>Usando assemblies verificáveis com SQL Server (C++/CLI)

Procedimentos armazenados estendidos, empacotados como bibliotecas de vínculo dinâmico (DLLs), fornecem uma maneira de estender a funcionalidade do SQL Server por meio de funções desenvolvidos com o Visual C++. Os procedimentos armazenados estendidos são implementados como funções em DLLs. Além das funções, procedimentos armazenados estendidos também podem definir [tipos definidos pelo usuário](../cpp/classes-and-structs-cpp.md) e agregar funções (como SUM ou AVG).

Quando um cliente executa um procedimento armazenado estendido, pesquisas de SQL Server para a DLL associada com o procedimento armazenado estendido e carrega a DLL. SQL Server chama o procedimento armazenado estendido solicitado e o executa em um contexto de segurança especificado. O procedimento armazenado estendido, em seguida, conjuntos de resultados de passagens e retorna os parâmetros de volta para o servidor.

SQL Server fornece extensões para Transact-SQL (T-SQL) para que você possa instalar assemblies verificáveis no SQL Server. O conjunto de permissões do SQL Server Especifica o contexto de segurança, com os seguintes níveis de segurança:

- Modo irrestrito: executar o código em seu próprio risco; código não precisa ser fortemente tipado verificável.

- Modo de segurança: executar o código de segurança de tipos; verificável compilado com /CLR: safe.

Modo de segurança exige que os assemblies executados seja verificável typesafe.

Para criar e carregar um assembly verificável no SQL Server, use os comandos Transact-SQL CREATE ASSEMBLY e DROP ASSEMBLY da seguinte maneira:

```sql
CREATE ASSEMBLY <assemblyName> FROM <'Assembly UNC Path'> WITH
  PERMISSION_SET <permissions>
DROP ASSEMBLY <assemblyName>
```  

O comando PERMISSION_SET Especifica o contexto de segurança e pode ter os valores irrestrito, SAFE ou estendido.

Além disso, você pode usar o comando CREATE FUNCTION para associar a nomes de método em uma classe:

```sql
CREATE FUNCTION <FunctionName>(<FunctionParams>)  
RETURNS returnType
[EXTERNAL NAME <AssemblyName>:<ClassName>::<StaticMethodName>]
```  

## <a name="example"></a>Exemplo
O seguinte script SQL (por exemplo, nomeado "Myscript") carrega um assembly no SQL Server e disponibiliza um método de uma classe:

```sql
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

Scripts SQL podem ser executados interativamente no SQL Query Analyzer ou na linha de comando com o utilitário sqlcmd.exe. A seguinte linha de comando se conecta ao MyServer, usa o banco de dados padrão, usa uma conexão confiável, Myscript de entradas e saídas MyResult.txt.

```cmd
sqlcmd -S MyServer -E -i myScript.sql -o myResult.txt
```  

## <a name="see-also"></a>Consulte também

[Como: migrar para /CLR: Safe (C + + / CLI)](../dotnet/how-to-migrate-to-clr-safe-cpp-cli.md)   
[Classes e Structs](../cpp/classes-and-structs-cpp.md)