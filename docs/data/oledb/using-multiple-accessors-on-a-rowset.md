---
title: Usando vários acessadores em um conjunto de linhas
ms.date: 10/24/2018
helpviewer_keywords:
- BEGIN_ACCESSOR macro
- BEGIN_ACCESSOR macro, multiple accessors
- rowsets [C++], multiple accessors
- accessors [C++], rowsets
ms.assetid: 80d4dc5d-4940-4a28-a4ee-d8602f71d2a6
ms.openlocfilehash: 48772539b4dda9262a244506a36932d1e752949e
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509403"
---
# <a name="using-multiple-accessors-on-a-rowset"></a>Usando vários acessadores em um conjunto de linhas

Há três cenários básicos nos quais você precisa usar vários acessadores:

- **Vários conjuntos de linhas de leitura/gravação.** Nesse cenário, você tem uma tabela com uma chave primária. Você deseja ser capaz de ler todas as colunas na linha, incluindo a chave primária. Você também deseja ser capaz de gravar dados em todas as colunas, exceto a chave primária (porque não é possível gravar na coluna de chave primária). Nesse caso, você configura dois acessadores:

  - O acessador 0 contém todas as colunas.

  - O acessador 1 contém todas as colunas, exceto a chave primária.

- **Desempenho.** Nesse cenário, uma ou mais colunas têm uma grande quantidade de dados, por exemplo, gráficos, som ou arquivos de vídeo. Sempre que você passa para uma linha, provavelmente não deseja recuperar a coluna com o arquivo de dados grande, pois isso tornaria o desempenho do aplicativo mais lento.

  Você pode configurar acessadores separados nos quais o primeiro acessador contém todas as colunas, exceto aquela com dados grandes, e recupera dados dessas colunas automaticamente; o primeiro acessador é o acessador automático. O segundo acessador recupera apenas a coluna que contém dados grandes, mas não recupera dados dessa coluna automaticamente. Você pode ter outros métodos atualizados ou buscar os dados grandes sob demanda.

  - O acessador 0 é um acessador automático; Ele recupera todas as colunas, exceto aquela com dados grandes.

  - O acessador 1 não é um acessador automático; Ele recupera a coluna com dados grandes.

  Use o argumento auto para especificar se o acessador é um acessador automático.

- **Várias colunas ISequentialStream.** Nesse cenário, você tem mais de uma coluna contendo `ISequentialStream` dados. No entanto, cada acessador é limitado a um `ISequentialStream` fluxo de dados. Para resolver esse problema, configure vários acessadores, cada um com um `ISequentialStream` ponteiro.

Normalmente, você cria acessadores usando as macros [BEGIN_ACCESSOR](./macros-and-global-functions-for-ole-db-consumer-templates.md#begin_accessor) e [END_ACCESSOR](./macros-and-global-functions-for-ole-db-consumer-templates.md#end_accessor) . Você também pode usar o atributo [db_accessor](../../windows/attributes/db-accessor.md) . (Os acessadores são descritos mais detalhadamente em [registros de usuário](../../data/oledb/user-records.md).) As macros ou o atributo especificam se um acessador é um acessador automático ou não automático:

- Em um acessador automático, mova métodos como `MoveFirst` ,, `MoveLast` `MoveNext` e `MovePrev` recupere dados para todas as colunas especificadas automaticamente. O acessador 0 deve ser o acessador automático.

- Em um acessador não automático, a recuperação não ocorre até que você chame explicitamente um método como `Update` , `Insert` , `Fetch` ou `Delete` . Nos cenários descritos acima, talvez você não queira recuperar todas as colunas em cada movimento. Você pode colocar uma ou mais colunas em um acessador separado e torná-lo um acessador não automático, como mostrado abaixo.

O exemplo a seguir usa vários acessadores para ler e gravar na tabela de trabalhos do banco de dados pubs SQL Server usando vários acessadores. Este exemplo é o uso mais comum de vários acessadores; consulte o cenário "vários conjuntos de linhas de leitura/gravação" acima.

A classe de registro de usuário é a seguinte: Ele configura dois acessadores: o acessador 0 contém apenas a coluna de chave primária (ID) e o acessador 1 contém outras colunas.

```cpp
class CJobs
{
public:
    enum {
        sizeOfDescription = 51
    };

    short nID;
    char szDescription[ sizeOfDescription ];
    short nMinLvl;
    short nMaxLvl;

    DWORD dwID;
    DWORD dwDescription;
    DWORD dwMinLvl;
    DWORD dwMaxLvl;

BEGIN_ACCESSOR_MAP(CJobs, 2)
    // Accessor 0 is the automatic accessor
    BEGIN_ACCESSOR(0, true)
        COLUMN_ENTRY_STATUS(1, nID, dwID)
    END_ACCESSOR()
    // Accessor 1 is the non-automatic accessor
    BEGIN_ACCESSOR(1, true)
        COLUMN_ENTRY_STATUS(2, szDescription, dwDescription)
        COLUMN_ENTRY_STATUS(3, nMinLvl, dwMinLvl)
        COLUMN_ENTRY_STATUS(4, nMaxLvl, dwMaxLvl)
    END_ACCESSOR()
END_ACCESSOR_MAP()
};
```

O código principal é o seguinte. A chamada `MoveNext` recupera automaticamente os dados da ID da coluna de chave primária usando o acessador 0. Observe como o `Insert` método próximo ao final usa o acessador 1 para evitar gravar na coluna de chave primária.

```cpp
int main(int argc, char* argv[])
{
    // Initialize COM
    ::CoInitialize(NULL);

    // Create instances of the data source and session
    CDataSource source;
    CSession session;
    HRESULT hr = S_OK;

    // Set initialization properties
    CDBPropSet dbinit(DBPROPSET_DBINIT);
    dbinit.AddProperty(DBPROP_AUTH_USERID, OLESTR("my_user_id"));
    dbinit.AddProperty(DBPROP_INIT_CATALOG, OLESTR("pubs"));
    dbinit.AddProperty(DBPROP_INIT_DATASOURCE, OLESTR("(local)"));

    hr = source.Open("SQLOLEDB.1", &dbinit);
    if (hr == S_OK)
    {
        hr = session.Open(source);
        if (hr == S_OK)
        {
            // Ready to fetch/access data
            CTable<CAccessor<CJobs>> jobs;

            // Set properties for making the rowset a read/write cursor
            CDBPropSet dbRowset(DBPROPSET_ROWSET);
            dbRowset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
            dbRowset.AddProperty(DBPROP_CANSCROLLBACKWARDS, true);
            dbRowset.AddProperty(DBPROP_IRowsetChange, true);
            dbRowset.AddProperty(DBPROP_UPDATABILITY,
                DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE |
                DBPROPVAL_UP_DELETE);

            hr = jobs.Open(session, "jobs", &dbRowset);
            if (hr == S_OK)
            {
                // Calling MoveNext automatically retrieves ID
                // (using accessor 0)
                while(jobs.MoveNext() == S_OK)
                   printf_s("Description = %s\n", jobs.szDescription);

                hr = jobs.MoveFirst();
                if (hr == S_OK)
                {
                    jobs.nID = 25;
                    strcpy_s(&jobs.szDescription[0],
                             jobs.sizeOfDescription,
                             "Developer");
                    jobs.nMinLvl = 10;
                    jobs.nMaxLvl = 20;

                    jobs.dwDescription = DBSTATUS_S_OK;
                    jobs.dwID = DBSTATUS_S_OK;
                    jobs.dwMaxLvl = DBSTATUS_S_OK;
                    jobs.dwMinLvl = DBSTATUS_S_OK;

                    // Insert method uses accessor 1
                    // (to avoid writing to the primary key column)
                    hr = jobs.Insert(1);
                }
                jobs.Close();
            }
            session.Close();
        }
        source.Close();
    }

    // Uninitialize COM
    ::CoUninitialize();
    return 0;
}
```

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)<br/>
[Registros de usuário](../../data/oledb/user-records.md)
