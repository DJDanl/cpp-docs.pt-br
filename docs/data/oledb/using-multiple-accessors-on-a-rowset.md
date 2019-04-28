---
title: Usando vários acessadores em um conjunto de linhas
ms.date: 10/24/2018
helpviewer_keywords:
- BEGIN_ACCESSOR macro
- BEGIN_ACCESSOR macro, multiple accessors
- rowsets [C++], multiple accessors
- accessors [C++], rowsets
ms.assetid: 80d4dc5d-4940-4a28-a4ee-d8602f71d2a6
ms.openlocfilehash: d1ab314edeebedef4cff14cd5364a7ca16c74769
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62216376"
---
# <a name="using-multiple-accessors-on-a-rowset"></a>Usando vários acessadores em um conjunto de linhas

Há três cenários básicos em que você precisa usar vários acessadores:

- **Vários conjuntos de linhas de leitura/gravação.** Nesse cenário, você tem uma tabela com uma chave primária. Você deseja ser capaz de ler todas as colunas na linha, incluindo a chave primária. Você também deseja ser capaz de gravar dados em todas as colunas, exceto a chave primária (porque você não pode gravar a coluna de chave primária). Nesse caso, você configurar dois acessadores:

  - Acessador 0 contém todas as colunas.

  - Acessador 1 contém todas as colunas exceto a chave primária.

- **Desempenho.** Nesse cenário, uma ou mais colunas têm uma grande quantidade de dados, por exemplo, elementos gráficos, som, arquivos ou vídeo. Sempre que mudar para uma linha, você provavelmente não deseja recuperar a coluna com o arquivo de dados grandes, porque fazer então retardaria o desempenho do seu aplicativo.

  Você pode definir acessadores separados no qual o acessador primeiro contém todas as colunas, exceto o com dados grandes e recupera dados dessas colunas automaticamente. o acessador primeiro é o acessador automática. O acessador segundo recupera somente a coluna que contém dados grandes, mas ela não recupera os dados desta coluna automaticamente. Você pode ter outros métodos de atualização ou buscar os dados grandes sob demanda.

  - Acessador 0 é um acessador automática; ele recupera todas as colunas, exceto o com dados grandes.

  - Acessador 1 não é um acessador automática; ele recupera a coluna com dados grandes.

  Use o argumento de automática para especificar se o acessador é um acessador de automático.

- **Várias colunas de ISequentialStream.** Nesse cenário, que você espera de mais de uma coluna `ISequentialStream` dados. No entanto, cada acessador é limitada a uma `ISequentialStream` fluxo de dados. Para resolver esse problema, configurar vários acessadores, cada um tendo uma `ISequentialStream` ponteiro.

Você normalmente cria acessadores usando o [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros. Você também pode usar o [db_accessor](../../windows/db-accessor.md) atributo. (Acessadores são descritos mais detalhadamente em [registros de usuário](../../data/oledb/user-records.md).) As macros ou o atributo Especifique se um acessador é automático ou um acessador não automático:

- Em um acessador automática, mover métodos como `MoveFirst`, `MoveLast`, `MoveNext`, e `MovePrev` recuperar dados para todas as colunas especificadas automaticamente. Acessador 0 deve ser o acessador automática.

- Em um acessador não automático, a recuperação não ocorre até que você chamar explicitamente um método como `Update`, `Insert`, `Fetch`, ou `Delete`. Nos cenários descritos acima, talvez você não queira recuperar todas as colunas em cada movimento. Você pode colocar uma ou mais colunas em um acessador separado e verifique um acessador não automático, conforme mostrado abaixo.

O exemplo a seguir usa vários acessadores para ler e gravar na tabela de trabalhos de banco de dados de pubs do SQL Server usando vários acessadores. Este exemplo é o uso mais comum de vários acessadores; Consulte o cenário de "vários conjuntos de leitura/gravação" acima.

A classe de registro de usuário é da seguinte maneira. Ele configura dois acessadores: acessador 0 contém apenas a coluna de chave primária (ID) e o acessador 1 contém outras colunas.

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

O código principal é da seguinte maneira. Chamar `MoveNext` automaticamente recupera dados da ID da coluna de chave primária usando o acessador de 0. Observe como o `Insert` método perto o acessador de end usa 1 para evitar a escrita para a coluna de chave primária.

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
