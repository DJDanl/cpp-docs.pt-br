---
title: db_command | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc-attr.db_command
dev_langs:
- C++
helpviewer_keywords:
- db_command attribute
ms.assetid: 714c3e15-85d7-408b-9a7c-88505c3e5d24
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 87209d673da47827723198697a26300d4056d3d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dbcommand"></a>db_command
Cria um comando OLE DB.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ db_command(   
   command,   
   name,   
   source_name,   
   hresult,   
   bindings,   
   bulk_fetch)  
]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `command`  
 Uma cadeia de caracteres de comando que contém o texto de um comando de OLE DB. É um exemplo simples:  
  
```  
[ db_command ( command = "Select * from Products" ) ]  
```  
  
 O *comando* sintaxe é a seguinte:  
  
```  
binding parameter block 1  
   OLE DB command  
binding parameter block 2  
   continuation of OLE DB command  
binding parameter block 3  
...  
```  
  
 Um *bloco de parâmetro de associação* é definido da seguinte maneira:  
  
 **([** `bindtype` **]** *szVar1* [*, szVar2* [, *nVar3* [,...]]] **)**  
  
 em que:  
  
 **(** marca o início do bloco de associação de dados.  
  
 **[** `bindtype` **]** é uma das seguintes cadeias de caracteres de maiusculas e minúsculas:  
  
-   **[db_column]**  associa cada uma das variáveis de membro a uma coluna em um conjunto de linhas.  
  
-   **[bindto]**  (mesmo que **[db_column]**).  
  
-   **[in]**  associa as variáveis de membro como parâmetros de entrada.  
  
-   **[out]**  associa as variáveis de membro como parâmetros de saída.  
  
-   **[out no]**  associa as variáveis de membro como parâmetros de entrada/saída.  
  
 *SzVarX* resolve a uma variável de membro dentro do escopo atual.  
  
 **)** marca o fim do bloco de associação de dados.  
  
 Se a cadeia de caracteres de comando contém um ou mais especificadores como [in], [out] ou [entrada/saída], **db_command** cria um mapa de parâmetro.  
  
 Se a cadeia de caracteres de comando contém um ou mais parâmetros como [db_column] ou [bindto] **db_command** gera um conjunto de linhas e um mapa de acessador para atender a essas variáveis associadas. Consulte [db_accessor](../windows/db-accessor.md) para obter mais informações.  
  
> [!NOTE]
>  [`bindtype`] sintaxe e o `bindings` parâmetro não são válidos quando usando **db_command** no nível de classe.  
  
 Aqui estão alguns exemplos de blocos de parâmetro de associação. O exemplo a seguir associa o `m_au_fname` e `m_au_lname` membros de dados para o `au_fname` e `au_lname` colunas, respectivamente, da tabela dos autores no banco de dados pubs:  
  
```  
TCHAR m_au_fname[21];  
TCHAR m_au_lname[41];  
TCHAR m_state[3] = 'CA';  
  
[db_command (  
   command = "SELECT au_fname([bindto]m_au_fname), au_lname([bindto]m_au_lname) " \  
   "FROM dbo.authors " \  
   "WHERE state = ?([in]m_state)")  
```  
  
 ]  
  
 *nome* (opcional)  
 O nome do identificador que você usa para trabalhar com o conjunto de linhas. Se você especificar *nome*, **db_command** gera uma classe com especificado *nome*, que pode ser usado para percorrer o conjunto de linhas ou para executar várias consultas de ação. Se você não especificar *nome*, não será possível retornar mais de uma linha de resultados para o usuário.  
  
 *source_name* (opcional)  
 O `CSession` variável ou instância de uma classe que tem o `db_source` atributo aplicado a ele no qual o comando é executado. Consulte [db_source](../windows/db-source.md).  
  
 **db_command** verificações para garantir que a variável usada para *source_name* é válido, portanto, a variável especificada deve estar no escopo global ou de função.  
  
 `hresult` (opcional)  
 Identifica a variável que receberá o `HRESULT` deste comando de banco de dados. Se a variável não existir, ele será automaticamente introduzido pelo atributo.  
  
 *associações* (opcional)  
 Permite que você separe os parâmetros de ligação do comando OLE DB.  
  
 Se você especificar um valor para `bindings`, **db_command** analisará o valor associado e não analisará o [`bindtype`] parâmetro. Esse uso permite que você use a sintaxe do provedor OLE DB. Para desabilitar a análise, sem associação de parâmetros, especifique **associações = ""**.  
  
 Se você não especificar um valor para `bindings`, **db_command** analisará o bloco de parâmetro de associação, procurando por '**(**', seguido por **[** `bindtype` **]**  entre colchetes, seguidos por um ou mais declarada anteriormente C++ variáveis de membro, seguido por '**)**'. Todo o texto entre os parênteses será removido do comando resultante, e esses parâmetros serão usados para construir as associações de parâmetro e coluna para este comando.  
  
 *bulk_fetch*(opcional)  
 Um valor inteiro que especifica o número de linhas a serem buscadas.  
  
 O valor padrão é 1, que especifica a busca de única linha (o conjunto de linhas será do tipo [CRowset](../data/oledb/crowset-class.md)).  
  
 Um valor maior que 1 Especifica que a busca de linhas em massa. Busca de linhas em massa refere-se à capacidade de conjuntos de linhas em massa para buscar vários identificadores de linha (o conjunto de linhas será do tipo [CBulkRowset](../data/oledb/cbulkrowset-class.md) e chamará `SetRows` com o número especificado de linhas).  
  
 Se *bulk_fetch* é menor do que um `SetRows` retornará zero.  
  
## <a name="remarks"></a>Comentários  
 **db_command** cria um [CCommand](../data/oledb/ccommand-class.md) objeto, que é usado por um consumidor OLE DB para executar um comando.  
  
 Você pode usar **db_command** com escopo de classe ou função; a principal diferença é o escopo do `CCommand` objeto. Com escopo de função, dados, como associações de terminam a fim de função. Usos de escopo de classe e a função envolvem a classe de OLE DB consumidor modelo **CCommand <>**, mas os argumentos de modelo são diferentes para os casos de função e classe. No caso de função, associações serão feitas para um **acessador** que consiste em variáveis locais, enquanto o uso da classe deduz um `CAccessor`-derivado da classe como o argumento. Quando usado como um atributo de classe, **db_command** funciona em conjunto com **db_column**.  
  
 **db_command** pode ser usado para executar comandos que não retornam um conjunto de resultados.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador irá renomear a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome atribuído a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivado de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as classes.  
  
## <a name="example"></a>Exemplo  
 Este exemplo define um comando que seleciona os nomes e sobrenomes de uma tabela em que a coluna de estado corresponde a 'CA'. **db_command** cria e lê um conjunto de linhas em que você pode chamar funções geradas pelo assistente, como [OpenAll e CloseAll](../data/oledb/consumer-wizard-generated-methods.md), bem como `CRowset` , como funções de membro [MoveNext](../data/oledb/crowset-movenext.md).  
  
 Observe que esse código requer que você forneça sua própria cadeia de caracteres de conexão que se conecta ao banco de dados pubs. Para obter informações sobre como fazer isso no ambiente de desenvolvimento, consulte [como: conectar-se ao banco de dados do Gerenciador de servidores](http://msdn.microsoft.com/en-us/7c1c3067-0d77-471b-872b-639f9f50db74) e [como: adicionar novas conexões de dados no Server Explorer/Database Explorer](http://msdn.microsoft.com/en-us/fb2f513b-ddad-4142-911e-856bba0054c8).  
  
```  
// db_command.h  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
#pragma once  
  
[  db_source(L"your connection string"),  
   db_command(L" \  
      SELECT au_lname, au_fname \  
      FROM dbo.authors \  
      WHERE state = 'CA'")  ]  
  
struct CAuthors {  
   // In order to fix several issues with some providers, the code below may bind  
   // columns in a different order than reported by the provider  
  
   DBSTATUS m_dwau_lnameStatus;  
   DBSTATUS m_dwau_fnameStatus;  
   DBLENGTH m_dwau_lnameLength;  
   DBLENGTH m_dwau_fnameLength;  
  
   [ db_column("au_lname", status="m_dwau_lnameStatus", length="m_dwau_lnameLength") ] TCHAR m_au_lname[41];  
   [ db_column("au_fname", status="m_dwau_fnameStatus", length="m_dwau_fnameLength") ] TCHAR m_au_fname[21];  
  
   [ db_param("7", paramtype="DBPARAMIO_INPUT") ] TCHAR m_state[3];  
  
   void GetRowsetProperties(CDBPropSet* pPropSet) {  
      pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
      pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);  
   }  
};  
```  
  
## <a name="example"></a>Exemplo  
  
```  
// db_command.cpp  
// compile with: /c  
#include "db_command.h"  
  
int main(int argc, _TCHAR* argv[]) {  
   HRESULT hr = CoInitialize(NULL);  
  
   // Instantiate rowset  
   CAuthors rs;  
  
   // Open rowset and move to first row  
   strcpy_s(rs.m_state, sizeof(rs.m_state), _T("CA"));  
   hr = rs.OpenAll();  
   hr = rs.MoveFirst();  
  
   // Iterate through the rowset  
   while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET ) {  
      // Print out the column information for each row  
      printf("First Name: %s, Last Name: %s\n", rs.m_au_fname, rs.m_au_lname);  
      hr = rs.MoveNext();  
   }  
  
   rs.CloseAll();  
   CoUninitialize();  
}  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa `db_source` em uma classe de fonte de dados `CMySource`, e `db_command` em classes de comando `CCommand1` e `CCommand2`.  
  
```  
// db_command_2.cpp  
// compile with: /c  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
// class usage for both db_source and db_command  
  
[  db_source(L"your connection string"),  
   db_command(L" \  
      SELECT au_lname, au_fname \  
      FROM dbo.authors \  
      WHERE state = 'CA'")  ]  
struct CMySource {  
   HRESULT OpenDataSource() {  
      return S_OK;  
   }  
};  
  
[db_command(command = "SELECT * FROM Products")]  
class CCommand1 {};  
  
[db_command(command = "SELECT FNAME, LNAME FROM Customers")]  
class CCommand2 {};  
  
int main() {  
   CMySource s;  
   HRESULT hr = s.OpenDataSource();  
   if (SUCCEEDED(hr)) {  
      CCommand1 c1;  
      hr = c1.Open(s);  
  
      CCommand2 c2;  
      hr = c2.Open(s);  
   }  
  
   s.CloseDataSource();  
}  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, membro, o método, o local|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   
 [Atributos independentes](../windows/stand-alone-attributes.md)   
