---
title: db_command (atributo COM C++)
ms.date: 07/10/2018
f1_keywords:
- vc-attr.db_command
helpviewer_keywords:
- db_command attribute
ms.assetid: 714c3e15-85d7-408b-9a7c-88505c3e5d24
ms.openlocfilehash: d9ee1ed1bede6a5deaeae0be3783d6abbd05a0d9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831366"
---
# <a name="db_command"></a>db_command

Cria um comando OLE DB.

## <a name="syntax"></a>Sintaxe

```cpp
[ db_command(command, name, source_name, hresult, bindings, bulk_fetch)
]
```

### <a name="parameters"></a>parâmetros

*command*<br/>
Uma cadeia de caracteres de comando que contém o texto de um comando OLE DB. Um exemplo simples é:

```cpp
[ db_command ( command = "Select * from Products" ) ]
```

A sintaxe do *comando* é a seguinte:

> bloco de parâmetro de associação 1 \
> &nbsp;&nbsp;OLE DB comando \
> bloco de parâmetro de associação 2 \
> &nbsp;&nbsp;continuação do comando de OLE DB \
> bloco de parâmetro de associação 3 \
> ...

Um *bloco de parâmetro de associação* é definido da seguinte maneira:

> **( \[ ** *BindType* **]** *szVar1* \[ , *szVar2* \[ , *nVar3* \[ ,...]]] **)**

onde:

- **(** marca o início do bloco de vinculação de dados.

- **\[***associatype* **]** é uma das seguintes cadeias de caracteres que não diferenciam maiúsculas de minúsculas:

  - ** \[ db_column]** associa cada uma das variáveis de membro a uma coluna em um conjunto de linhas.

  - ** \[ associato]** (o mesmo que ** \[ db_column]**).

  - ** \[ in]** associa variáveis de membro como parâmetros de entrada.

  - ** \[ out]** associa variáveis de membro como parâmetros de saída.

  - ** \[ in, out]** associa variáveis de membro como parâmetros de entrada/saída.

- *szVarX*, *nVarX* é resolvido para uma variável de membro dentro do escopo atual.

- **)** marca o final do bloco de associação de dados.

Se a cadeia de caracteres de comando contiver um ou mais especificadores, como \[ em], \[ out] ou \[ in/out], **db_command** criará um mapa de parâmetro.

Se a cadeia de caracteres de comando contiver um ou mais parâmetros como \[ db_column] ou \[ associato], **db_command** gerará um conjunto de linhas e um mapa de acessador para atender a essas variáveis associadas. Consulte [db_accessor](db-accessor.md) para obter mais informações.

> [!NOTE]
> \[*associatype*] a sintaxe e o parâmetro de *associações* não são válidos ao usar **db_command** no nível de classe.

Aqui estão alguns exemplos de blocos de parâmetro de associação. O exemplo a seguir associa os `m_au_fname` `m_au_lname` membros de dados e às `au_fname` `au_lname` colunas e, respectivamente, da tabela autores no banco de dados pubs:

```cpp
TCHAR m_au_fname[21];
TCHAR m_au_lname[41];
TCHAR m_state[3] = 'CA';

[db_command (command = "SELECT au_fname([bindto]m_au_fname), au_lname([bindto]m_au_lname) " \
   "FROM dbo.authors " \
   "WHERE state = ?([in]m_state)")
]
```

*name*<br/>
Adicional O nome do identificador que você usa para trabalhar com o conjunto de linhas. Se você especificar *nome*, **db_command** gerará uma classe com o *nome*especificado, que pode ser usado para atravessar o conjunto de linhas ou para executar várias consultas de ação. Se você não especificar o *nome*, não será possível retornar mais de uma linha de resultados ao usuário.

*source_name*<br/>
Adicional A `CSession` variável ou instância de uma classe que tem o `db_source` atributo aplicado a ela na qual o comando é executado. Consulte [db_source](db-source.md).

**db_command** verifica se a variável usada para *source_name* é válida, portanto, a variável especificada deve estar na função ou no escopo global.

*resultado*<br/>
Adicional Identifica a variável que receberá o HRESULT deste comando de banco de dados. Se a variável não existir, ela será injetada automaticamente pelo atributo.

*associações*<br/>
Adicional Permite separar os parâmetros de associação do comando OLE DB.

Se você especificar um valor para *associações*, **db_command** analisará o valor associado e não analisará o parâmetro \[ *BindType*]. Esse uso permite que você use OLE DB sintaxe do provedor. Para desabilitar a análise, sem parâmetros de associação, especifique `Bindings=""` .

Se você não especificar um valor para *associações*, **db_command** analisará o bloco de parâmetro de associação, procurando por '**(**', seguido de **\[** _BindType_**]** entre colchetes, seguido por uma ou mais variáveis de membro C++ declaradas anteriormente, seguidas por '**)**'. Todo o texto entre parênteses será retirado do comando resultante, e esses parâmetros serão usados para construir associações de coluna e parâmetro para esse comando.

*bulk_fetch*<br/>
Adicional Um valor inteiro que especifica o número de linhas a serem buscadas.

O valor padrão é 1, que especifica a busca de linha única (o conjunto de linhas será do tipo [CRowset](../../data/oledb/crowset-class.md)).

Um valor maior que 1 especifica a busca em massa de linha. A busca de linha em massa refere-se à capacidade de conjuntos de linhas em massa de buscar vários identificadores de linha (o conjunto de linhas será do tipo [CBulkRowset](../../data/oledb/cbulkrowset-class.md) e chamará `SetRows` com o número de linhas especificado).

Se *bulk_fetch* for menor que um, o `SetRows` retornará zero.

## <a name="remarks"></a>Comentários

**db_command** cria um objeto [CCommand](../../data/oledb/ccommand-class.md) , que é usado por um consumidor de OLE DB para executar um comando.

Você pode usar **db_command** com o escopo de classe ou função; a principal diferença é o escopo do `CCommand` objeto. Com o escopo da função, os dados como as associações são encerrados na função End. Os usos de escopo de classe e função envolvem a classe de modelo de consumidor OLE DB `CCommand<>` , mas os argumentos de modelo diferem para os casos de função e classe. No caso de função, as associações serão feitas em um `Accessor` que consiste em variáveis locais, enquanto o uso da classe inferirá uma `CAccessor` classe derivada como o argumento. Quando usado como um atributo de classe, **db_command** funciona em conjunto com **db_column**.

**db_command** pode ser usado para executar comandos que não retornam um conjunto de resultados.

Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador renomeará a classe como \_ acessador *YourClassName*, em que *YourClassName* é o nome que você forneceu à classe e o compilador também criará uma classe chamada *YourClassName*, que deriva de \_ acessador *YourClassName*.  Em Modo de Exibição de Classe, você verá ambas as classes.

## <a name="example"></a>Exemplo

Este exemplo define um comando que seleciona o nome e o sobrenome de uma tabela em que a coluna de estado corresponde a ' AC '. **db_command** cria e lê um conjunto de linhas no qual você pode chamar funções geradas pelo assistente, como [método OpenAll e CloseAll](../../data/oledb/consumer-wizard-generated-methods.md), bem como `CRowset` funções de membro como [MoveNext](../../data/oledb/crowset-movenext.md).

Observe que esse código exige que você forneça sua própria cadeia de conexão que se conecta ao banco de dados pubs. Para obter informações sobre como fazer isso no ambiente de desenvolvimento, consulte [como conectar-se a um banco de dados e navegar por objetos existentes](/sql/ssdt/how-to-connect-to-a-database-and-browse-existing-objects) e [adicionar novas conexões](/visualstudio/data-tools/add-new-connections).

```cpp
// db_command.h
#include <atlbase.h>
#include <atlplus.h>
#include <atldbcli.h>

#pragma once

[  db_source(L"your connection string"), db_command(L" \
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

```cpp
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

Este exemplo usa `db_source` em uma classe de fonte de dados `CMySource` e `db_command` em classes de comando `CCommand1` e `CCommand2` .

```cpp
// db_command_2.cpp
// compile with: /c
#include <atlbase.h>
#include <atlplus.h>
#include <atldbcli.h>
// class usage for both db_source and db_command

[  db_source(L"your connection string"), db_command(L" \
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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`** , membro, método, local|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[OLE DB atributos de consumidor](ole-db-consumer-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)
