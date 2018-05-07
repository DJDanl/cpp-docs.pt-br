---
title: Usando vários acessadores em um conjunto de linhas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- BEGIN_ACCESSOR macro
- BEGIN_ACCESSOR macro, multiple accessors
- rowsets [C++], multiple accessors
- accessors [C++], rowsets
ms.assetid: 80d4dc5d-4940-4a28-a4ee-d8602f71d2a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a30108ec344091631094cd55f6a3bd3f0f4a4a54
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-multiple-accessors-on-a-rowset"></a>Usando vários acessadores em um conjunto de linhas
Há três cenários básicos que você precisa usar vários acessadores:  
  
-   **Vários conjuntos de linhas de leitura/gravação.** Nesse cenário, você tem uma tabela com uma chave primária. Você deseja ser capaz de ler todas as colunas na linha, incluindo a chave primária. Você também deseja ser capaz de gravar dados em todas as colunas, exceto a chave primária (porque você não pode gravar a coluna de chave primária). Nesse caso, você configurar dois acessadores:  
  
    -   Acessador 0 contém todas as colunas.  
  
    -   Acessador 1 contém todas as colunas exceto a chave primária.  
  
-   **Desempenho.** Nesse cenário, uma ou mais colunas contêm uma grande quantidade de arquivos de dados, por exemplo, gráficos, som ou vídeo. Sempre que você mover para uma linha, você provavelmente não deseja recuperar a coluna com o arquivo de dados grandes, porque fazer assim seria mais lento o desempenho do aplicativo.  
  
     Você pode configurar acessadores separados no qual o acessador primeiro contém todas as colunas exceto aquele com dados grandes e recupera dados dessas colunas automaticamente. Este é o acessador automática. O acessador segundo recupera somente a coluna que contém dados grandes, mas ele não recuperar os dados desta coluna automaticamente. Você pode ter outros métodos de atualização ou buscar os dados grandes sob demanda.  
  
    -   Acessador 0 é um acessador automática; recupera todas as colunas, exceto o com dados grandes.  
  
    -   Acessador 1 não é um acessador automática; recupera a coluna com dados grandes.  
  
     Use o argumento de automática para especificar se o acessador é um acessador automática.  
  
-   **Várias colunas de ISequentialStream.** Nesse cenário, você tem mais de uma coluna que contém `ISequentialStream` dados. No entanto, cada acessador é limitado a uma `ISequentialStream` o fluxo de dados. Para resolver esse problema, configure vários acessadores, cada um contendo uma `ISequentialStream` ponteiro.  
  
 Você normalmente cria acessadores usando o [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros. Você também pode usar o [db_accessor](../../windows/db-accessor.md) atributo. (Acessadores são descritos mais detalhadamente em [registros de usuário](../../data/oledb/user-records.md).) As macros ou o atributo de especificar se um acessador é automático ou um acessador não automático:  
  
-   Em um acessador automática, mover métodos como **MoveFirst**, `MoveLast`, `MoveNext`, e `MovePrev` recuperar dados para todas as colunas especificadas automaticamente. Acessador 0 deve ser o acessador automática.  
  
-   Em um acessador não automático, a recuperação não ocorrerá até que você explicitamente chama um método como **atualização**, **inserir**, **buscar**, ou **excluir**. Nos cenários descritos acima, não convém recuperar todas as colunas em cada movimento. Você pode colocar uma ou mais colunas em um acessador separado e verifique um acessador não automático, conforme mostrado abaixo.  
  
 O exemplo a seguir usa vários acessadores para ler e gravar na tabela de trabalhos do SQL Server pubs banco de dados usando vários acessadores. Este é o uso mais comum de vários acessadores; Consulte o cenário de "vários conjuntos de leitura/gravação" acima.  
  
 A classe de registro de usuário é o seguinte. Define dois acessadores: acessador 0 contém somente a coluna de chave primária (ID) e acessador 1 contém outras colunas.  
  
```  
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
  
 O código principal é o seguinte. Chamando `MoveNext` automaticamente recupera dados de ID da coluna de chave primária usando o acessador de 0. Observe como o **inserir** método perto o acessador usa end 1 para evitar a gravação para a coluna de chave primária.  
  
```  
int main(int argc, char* argv[])  
{  
    // Initalize COM  
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
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Registros de usuário](../../data/oledb/user-records.md)