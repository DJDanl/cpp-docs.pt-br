---
title: Criando um provedor atualizável
ms.date: 08/16/2018
helpviewer_keywords:
- OLE DB providers, updatable
- notifications, support in providers
- OLE DB providers, creating
ms.assetid: bdfd5c9f-1c6f-4098-822c-dd650e70ab82
ms.openlocfilehash: 04db02bc8ad4db0c669e07a0bcf1b60ffa22e8ad
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51521395"
---
# <a name="creating-an-updatable-provider"></a>Criando um provedor atualizável

Visual C++ oferece suporte a provedores atualizáveis ou os provedores que podem atualizar (gravar) o repositório de dados. Este tópico discute como criar provedores atualizáveis usando modelos OLE DB.

Este tópico pressupõe que você está começando com um provedor viável. Há duas etapas para criar um provedor atualizável. Primeiro você deve decidir como o provedor será fazer alterações ao repositório de dados; Especificamente, se as alterações devem ser feito imediatamente ou adiada até que um comando update é emitido. A seção "[tornando provedores atualizáveis](#vchowmakingprovidersupdatable)" descreve as alterações e configurações que você precisa fazer no código do provedor.

Em seguida, você deve verificar se que seu provedor contém toda a funcionalidade para dar suporte a qualquer coisa que o consumidor pode solicitar dele. Se o consumidor deseja atualizar o armazenamento de dados, o provedor deve conter código que persiste os dados para o armazenamento de dados. Por exemplo, você pode usar a biblioteca de tempo de execução do C ou o MFC para realizar operações em sua fonte de dados. A seção "[escrevendo para a fonte de dados](#vchowwritingtothedatasource)" descreve como gravar na fonte de dados, lidar com valores nulos e padrão e definir sinalizadores de coluna.

> [!NOTE]
> [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) é um exemplo de um provedor atualizável. UpdatePV é o mesmo que MyProv, mas com suporte atualizável.

##  <a name="vchowmakingprovidersupdatable"></a> Tornando provedores atualizáveis

A chave para tornar um provedor atualizável é entender as operações que você deseja que o provedor para executar no armazenamento de dados e como você deseja que o provedor para executar essas operações. Especificamente, o grande problema é se as atualizações para o armazenamento de dados devem ser feito imediatamente ou adiada (agrupados) até que um comando update é emitido.

Primeiro você deve decidir se deseja herdar `IRowsetChangeImpl` ou `IRowsetUpdateImpl` em sua classe de conjunto de linhas. Dependendo de qual deles você optar por implementar, a funcionalidade dos três métodos será afetada: `SetData`, `InsertRows`, e `DeleteRows`.

- Se você herda de [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md), esses três métodos de chamada imediatamente altera o armazenamento de dados.

- Se você herda de [IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md), os métodos de adiar as alterações ao repositório de dados até que você chame `Update`, `GetOriginalData`, ou `Undo`. Se a atualização envolver várias alterações, elas são executadas no modo de lote (Observe que o envio em lote de alterações pode adicionar sobrecarga considerável de memória).

Observe que `IRowsetUpdateImpl` deriva `IRowsetChangeImpl`. Portanto, `IRowsetUpdateImpl` dá a você alterar a funcionalidade além da funcionalidade de lote.

### <a name="to-support-updatability-in-your-provider"></a>Para dar suporte à capacidade de atualização no provedor

1. Em sua classe de conjunto de linhas, herdam `IRowsetChangeImpl` ou `IRowsetUpdateImpl`. Essas classes fornecem interfaces apropriadas para o armazenamento de dados de alteração:

   **Adicionando IRowsetChange**

   Adicionar `IRowsetChangeImpl` para sua cadeia de herança usando este formato:

    ```cpp
    IRowsetChangeImpl< rowset-name, storage-name >
    ```

   Também adicione `COM_INTERFACE_ENTRY(IRowsetChange)` para o `BEGIN_COM_MAP` seção em sua classe de conjunto de linhas.

   **Adicionando IRowsetUpdate**

   Adicionar `IRowsetUpdate` para sua cadeia de herança usando este formato:

    ```cpp
    IRowsetUpdateImpl< rowset-name, storage>
    ```

   > [!NOTE]
   > Você deve remover o `IRowsetChangeImpl` linha de sua cadeia de herança. Essa única exceção à diretiva mencionada anteriormente deve incluir o código para `IRowsetChangeImpl`.

1. Adicione o seguinte ao seu mapa COM (`BEGIN_COM_MAP ... END_COM_MAP`):

   |  Se você implementar   |           Adicionar ao mapa COM             |
   |---------------------|--------------------------------------|
   | `IRowsetChangeImpl` | `COM_INTERFACE_ENTRY(IRowsetChange)` |
   | `IRowsetUpdateImpl` | `COM_INTERFACE_ENTRY(IRowsetUpdate)` |

   | Se você implementar | Adicionar ao mapa de conjunto de propriedade |
   |----------------------|-----------------------------|
   | `IRowsetChangeImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)` |
   | `IRowsetUpdateImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)` |

1. Em seu comando, adicione o seguinte ao seu mapa de conjunto de propriedade (`BEGIN_PROPSET_MAP ... END_PROPSET_MAP`):

   |  Se você implementar   |                                             Adicionar ao mapa de conjunto de propriedade                                              |
   |---------------------|------------------------------------------------------------------------------------------------------------------|
   | `IRowsetChangeImpl` |                            `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)`                             |
   | `IRowsetUpdateImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)` |

1. Em seu mapa de conjunto de propriedade, você também deve incluir todas as configurações a seguir conforme elas aparecem abaixo:

    ```cpp
    PROPERTY_INFO_ENTRY_VALUE(UPDATABILITY, DBPROPVAL_UP_CHANGE |
      DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE)
    PROPERTY_INFO_ENTRY_VALUE(CHANGEINSERTEDROWS, VARIANT_TRUE)
    PROPERTY_INFO_ENTRY_VALUE(IMMOBILEROWS, VARIANT_TRUE)

    PROPERTY_INFO_ENTRY_EX(OWNINSERT, VT_BOOL, DBPROPFLAGS_ROWSET |
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)
    PROPERTY_INFO_ENTRY_EX(OWNUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET |
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)
    PROPERTY_INFO_ENTRY_EX(OTHERINSERT, VT_BOOL, DBPROPFLAGS_ROWSET |
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)
    PROPERTY_INFO_ENTRY_EX(OTHERUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET |
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)
    PROPERTY_INFO_ENTRY_EX(REMOVEDELETED, VT_BOOL, DBPROPFLAGS_ROWSET |
      DBPROPFLAGS_READ, VARIANT_FALSE, 0)
    ```

   Você pode encontrar os valores usados nessas chamadas de macro examinando Atldb.h para as IDs de propriedade e os valores (se Atldb.h difere da documentação online, Atldb.h substitui a documentação).

   > [!NOTE]
   > Muitas da `VARIANT_FALSE` e `VARIANT_TRUE` configurações são necessários para os modelos OLE DB; a especificação OLE DB diz que eles podem ser de leitura/gravação, mas os modelos OLE DB só podem oferecer suporte a um valor.

   **Se você implementar IRowsetChangeImpl**

   Se você implementar `IRowsetChangeImpl`, você deve definir as propriedades a seguir no seu provedor. Essas propriedades são usadas principalmente para solicitar interfaces por `ICommandProperties::SetProperties`.

   - `DBPROP_IRowsetChange`: Isso automaticamente definindo conjuntos `DBPROP_IRowsetChange`.

   - `DBPROP_UPDATABILITY`: Um bitmask que especifica os métodos com suporte no `IRowsetChange`: `SetData`, `DeleteRows`, ou `InsertRow`.

   - `DBPROP_CHANGEINSERTEDROWS`: O consumidor pode chamar `IRowsetChange::DeleteRows` ou `SetData` para linhas recentemente inseridas.

   - `DBPROP_IMMOBILEROWS`: O conjunto de linhas não reorganizará as linhas inseridas ou atualizadas.

   **Se você implementar IRowsetUpdateImpl**

   Se você implementar `IRowsetUpdateImpl`, você deve definir as propriedades a seguir no seu provedor, além para definir todas as propriedades para `IRowsetChangeImpl` listados anteriormente:

   - `DBPROP_IRowsetUpdate`.

   - `DBPROP_OWNINSERT`: Deve ser VARIANT_TRUE e de READ_ONLY.

   - `DBPROP_OWNUPDATEDELETE`: Deve ser VARIANT_TRUE e de READ_ONLY.

   - `DBPROP_OTHERINSERT`: Deve ser VARIANT_TRUE e de READ_ONLY.

   - `DBPROP_OTHERUPDATEDELETE`: Deve ser VARIANT_TRUE e de READ_ONLY.

   - `DBPROP_REMOVEDELETED`: Deve ser VARIANT_TRUE e de READ_ONLY.

   - `DBPROP_MAXPENDINGROWS`.

   > [!NOTE]
   > Se você oferecer suporte a notificações, você também pode ter algumas outras propriedades também; Consulte a seção sobre `IRowsetNotifyCP` para esta lista.

##  <a name="vchowwritingtothedatasource"></a> Escrevendo para a fonte de dados

Para ler da fonte de dados, chame o `Execute` função. Para gravar a fonte de dados, chame o `FlushData` função. (Em um sentido geral, liberação meios para salvar as modificações feitas a uma tabela ou índice em disco).

```cpp
FlushData(HROW, HACCESSOR);
```

O identificador de linha (HROW) e os argumentos do identificador (HACCESSOR) de acessador permitem que você especifique a região de gravação. Normalmente, você deve escrever um único campo de dados por vez.

O `FlushData` método grava dados no formato em que foi originalmente armazenado. Se você não substituir essa função, seu provedor funcionarão corretamente, mas as alterações não serão liberadas para o armazenamento de dados.

### <a name="when-to-flush"></a>Quando você liberar

Os modelos de provedor chamar FlushData sempre que dados precisam ser gravados no armazenamento de dados; Isso normalmente (mas nem sempre) ocorre como resultado de chamadas para as seguintes funções:

- `IRowsetChange::DeleteRows`

- `IRowsetChange::SetData`

- `IRowsetChange::InsertRows` (se houver novos dados a ser inserido na linha)

- `IRowsetUpdate::Update`

### <a name="how-it-works"></a>Como ele funciona

O consumidor faz uma chamada que requer uma liberação (como atualização) e essa chamada é passada para o provedor, que sempre faz o seguinte:

- Chamadas `SetDBStatus` sempre que você tem um valor de status associado.

- Verifica os sinalizadores de coluna.

- Chama `IsUpdateAllowed`.

Essas três etapas ajudam a fornecer segurança. Em seguida, chama o provedor `FlushData`.

### <a name="how-to-implement-flushdata"></a>Como implementar FlushData

Para implementar `FlushData`, você precisa levar em consideração vários problemas:

Certificar-se de que o armazenamento de dados pode lidar com as alterações.

Manipulando valores nulos.

### <a name="handling-default-values"></a>Lidar com valores padrão.

Para implementar sua própria `FlushData` método, você precisa:

- Vá para a sua classe de conjunto de linhas.

- No conjunto de linhas classe colocar a declaração de:

   ```cpp
   HRESULT FlushData(HROW, HACCESSOR)
   {
      // Insert your implementation here and return an HRESULT.
   }
   ```

- Fornecer uma implementação de `FlushData`.

Uma implementação de BOM de `FlushData` armazena apenas as linhas e colunas que são realmente atualizadas. Você pode usar os parâmetros HROW e HACCESSOR para determinar a linha atual e a coluna que estão sendo armazenados para otimização.

Normalmente, o maior desafio que está trabalhando com seu próprio repositório de dados nativos. Se possível, tente:

- Mantenha o método de gravação para o armazenamento de dados mais simples possível.

- Manipule valores nulos (opcionais mas aconselhável).

- Lidar com valores padrão (opcionais mas aconselhável).

A melhor coisa a fazer é ter especificado os valores reais no seu armazenamento de dados para valores nulos e padrão. É melhor se você pode extrapolar esses dados. Caso contrário, é recomendável não permitir valores nulos e padrão.

A exemplo a seguir mostra como `FlushData` é implementado na `RUpdateRowset` classe o `UpdatePV` exemplo (consulte Rowset.h no código de exemplo):

```cpp
///////////////////////////////////////////////////////////////////////////
// class RUpdateRowset (in rowset.h)
...
HRESULT FlushData(HROW, HACCESSOR)
{
    ATLTRACE2(atlTraceDBProvider, 0, "RUpdateRowset::FlushData\n");

    USES_CONVERSION;
    enum {
        sizeOfString = 256,
        sizeOfFileName = MAX_PATH
    };
    FILE*    pFile = NULL;
    TCHAR    szString[sizeOfString];
    TCHAR    szFile[sizeOfFileName];
    errcode  err = 0;

    ObjectLock lock(this);

    // From a filename, passed in as a command text,
    // scan the file placing data in the data array.
    if (m_strCommandText == (BSTR)NULL)
    {
        ATLTRACE( "RRowsetUpdate::FlushData -- "
                  "No filename specified\n");
        return E_FAIL;
    }

    // Open the file
    _tcscpy_s(szFile, sizeOfFileName, OLE2T(m_strCommandText));
    if ((szFile[0] == _T('\0')) ||
        ((err = _tfopen_s(&pFile, &szFile[0], _T("w"))) != 0))
    {
        ATLTRACE("RUpdateRowset::FlushData -- Could not open file\n");
        return DB_E_NOTABLE;
    }

    // Iterate through the row data and store it.
    for (long l=0; l<m_rgRowData.GetSize(); l++)
    {
        CAgentMan am = m_rgRowData[l];

        _putw((int)am.dwFixed, pFile);

        if (_tcscmp(&am.szCommand[0], _T("")) != 0)
            _stprintf_s(&szString[0], _T("%s\n"), am.szCommand);
        else
            _stprintf_s(&szString[0], _T("%s\n"), _T("NULL"));
        _fputts(szString, pFile);

        if (_tcscmp(&am.szText[0], _T("")) != 0)
            _stprintf_s(&szString[0], _T("%s\n"), am.szText);
        else
            _stprintf_s(&szString[0], _T("%s\n"), _T("NULL"));
        _fputts(szString, pFile);

        if (_tcscmp(&am.szCommand2[0], _T("")) != 0)
            _stprintf_s(&szString[0], _T("%s\n"), am.szCommand2);
        else
            _stprintf_s(&szString[0], _T("%s\n"), _T("NULL"));
        _fputts(szString, pFile);

        if (_tcscmp(&am.szText2[0], _T("")) != 0)
            _stprintf_s(&szString[0], _T("%s\n"), am.szText2);
        else
            _stprintf_s(&szString[0], _T("%s\n"), _T("NULL"));
        _fputts(szString, pFile);
    }

    if (fflush(pFile) == EOF || fclose(pFile) == EOF)
    {
        ATLTRACE("RRowsetUpdate::FlushData -- "
                 "Couldn't flush or close file\n");
    }

    return S_OK;
}
```

### <a name="handling-changes"></a>Manipulação de alterações

Para o seu provedor manipular as alterações, você precisa primeiro certificar-se de que seu armazenamento de dados (como um arquivo de texto ou um arquivo de vídeo) tem recursos que permitem fazer alterações nele. Se isso não acontecer, você deve criar esse código separadamente do projeto de provedor.

### <a name="handling-null-data"></a>Manipulação de dados nulo

É possível que um usuário final enviará dados nulos. Quando você escreve valores NULL para os campos na fonte de dados, pode haver problemas em potencial. Imagine um aplicativo de anotações de ordem que aceita valores para cidade e CEP; ele poderia aceitar um ou ambos os valores, mas não nenhum dos dois, pois nesse caso, seria impossível entrega. Portanto, você precisa restringir determinadas combinações de valores nulos nos campos que fazem sentido para seu aplicativo.

Como desenvolvedor do provedor, você deve considerar como você irá armazenar esses dados, como você irá ler dados do armazenamento de dados e como especificar que para o usuário. Especificamente, você deve considerar como alterar o status de dados do conjunto de linhas de dados na fonte de dados (por exemplo, DataStatus = NULL). Você decide qual valor a ser retornado quando um consumidor acessa um campo que contém um valor nulo.

Examinar o código no exemplo UpdatePV; Ele ilustra como um provedor pode lidar com dados nulos. UpdatePV, o provedor armazena dados nulos, escrevendo a cadeia de caracteres "NULL" no repositório de dados. Quando ele lê os dados nulos do armazenamento de dados, ele vê essa cadeia de caracteres e, em seguida, esvazia o buffer, criando uma cadeia de caracteres nula. Ele também tem uma substituição do `IRowsetImpl::GetDBStatus` no qual ele retorna DBSTATUS_S_ISNULL se esse valor de dados está vazia.

### <a name="marking-nullable-columns"></a>Marcar colunas anuláveis

Se você implementar também a conjuntos de linhas de esquema (consulte `IDBSchemaRowsetImpl`), sua implementação deve especificar no conjunto de linhas DBSCHEMA_COLUMNS (geralmente marcado no seu provedor por CxxxSchemaColSchemaRowset) que a coluna é anulável.

Você também precisará especificar que todas as colunas que permitem valor nulas contenham o valor DBCOLUMNFLAGS_ISNULLABLE na sua versão do `GetColumnInfo`.

Na implementação de modelos OLE DB, se você não marcar colunas como anuláveis, o provedor supõe que eles devem conter um valor e não permitirá que o consumidor para enviá-lo a valores nulos.

A exemplo a seguir mostra como o `CommonGetColInfo` função é implementada no CUpdateCommand (consulte UpProvRS.cpp) em UpdatePV. Observe como as colunas têm esse DBCOLUMNFLAGS_ISNULLABLE para colunas que permitem valor nulas.

```cpp
/////////////////////////////////////////////////////////////////////////////
// CUpdateCommand (in UpProvRS.cpp)

ATLCOLUMNINFO* CommonGetColInfo(IUnknown* pPropsUnk, ULONG* pcCols, bool bBookmark)
{
    static ATLCOLUMNINFO _rgColumns[6];
    ULONG ulCols = 0;

    if (bBookmark)
    {
        ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0,
                            sizeof(DWORD), DBTYPE_BYTES,
                            0, 0, GUID_NULL, CAgentMan, dwBookmark,
                            DBCOLUMNFLAGS_ISBOOKMARK)
        ulCols++;
    }

    // Next set the other columns up.
    // Add a fixed length entry for OLE DB conformance testing purposes
    ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Fixed"), 1, 4, DBTYPE_UI4,
                        10, 255, GUID_NULL, CAgentMan, dwFixed,
                        DBCOLUMNFLAGS_WRITE |
                        DBCOLUMNFLAGS_ISFIXEDLENGTH)
    ulCols++;

    ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Command"), 2, 16, DBTYPE_STR,
                        255, 255, GUID_NULL, CAgentMan, szCommand,
                        DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
    ulCols++;
    ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Text"), 3, 16, DBTYPE_STR,
                        255, 255, GUID_NULL, CAgentMan, szText,
                        DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
    ulCols++;

    ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Command2"), 4, 16, DBTYPE_STR,
                        255, 255, GUID_NULL, CAgentMan, szCommand2,
                        DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
    ulCols++;
    ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Text2"), 5, 16, DBTYPE_STR,
                        255, 255, GUID_NULL, CAgentMan, szText2,
                        DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
    ulCols++;

    if (pcCols != NULL)
    {
        *pcCols = ulCols;
    }

    return _rgColumns;
}
```

### <a name="default-values"></a>Valores padrão

Assim como acontece com dados NULL, você tem a responsabilidade de lidar com valores padrão de alteração.

O padrão de `FlushData` e `Execute` é retornar S_OK. Portanto, se você não substituir essa função, as alterações aparecem tenha êxito (S_OK será retornado), mas eles não serão transmitidos para o armazenamento de dados.

No `UpdatePV` exemplo (em Rowset.h), o `SetDBStatus` método lida com valores padrão da seguinte maneira:

```cpp
virtual HRESULT SetDBStatus(DBSTATUS* pdbStatus, CSimpleRow* pRow,
                            ATLCOLUMNINFO* pColInfo)
{
    ATLASSERT(pRow != NULL && pColInfo != NULL && pdbStatus != NULL);

    void* pData = NULL;
    char* pDefaultData = NULL;
    DWORD* pFixedData = NULL;

    switch (*pdbStatus)
    {
        case DBSTATUS_S_DEFAULT:
            pData = (void*)&m_rgRowData[pRow->m_iRowset];
            if (pColInfo->wType == DBTYPE_STR)
            {
                pDefaultData = (char*)pData + pColInfo->cbOffset;
                strcpy_s(pDefaultData, "Default");
            }
            else
            {
                pFixedData = (DWORD*)((BYTE*)pData +
                                          pColInfo->cbOffset);
                *pFixedData = 0;
                return S_OK;
            }
            break;
        case DBSTATUS_S_ISNULL:
        default:
            break;
    }
    return S_OK;
}
```

### <a name="column-flags"></a>Sinalizadores de coluna

Se você oferecer suporte a valores padrão em suas colunas, você precisa configurá-lo usando os metadados na \<classe de provedor\>Conjunto_de_linhas_de_esquema classe. Definir `m_bColumnHasDefault = VARIANT_TRUE`.

Você também tem a responsabilidade de definir os sinalizadores de coluna, que são especificados usar o DBCOLUMNFLAGS tipo enumerado. Os sinalizadores de coluna descrevem as características da coluna.

Por exemplo, nos `CUpdateSessionColSchemaRowset` classe `UpdatePV` (no Session.h), a primeira coluna é configurada dessa forma:

```cpp
// Set up column 1
trData[0].m_ulOrdinalPosition = 1;
trData[0].m_bIsNullable = VARIANT_FALSE;
trData[0].m_bColumnHasDefault = VARIANT_TRUE;
trData[0].m_nDataType = DBTYPE_UI4;
trData[0].m_nNumericPrecision = 10;
trData[0].m_ulColumnFlags = DBCOLUMNFLAGS_WRITE |
                            DBCOLUMNFLAGS_ISFIXEDLENGTH;
lstrcpyW(trData[0].m_szColumnDefault, OLESTR("0"));
m_rgRowData.Add(trData[0]);
```

Esse código especifica, entre outras coisas, a coluna dá suporte a um valor padrão de 0, que pode ser gravável, e se todos os dados na coluna tem o mesmo tamanho. Se você quiser que os dados em uma coluna tenha um comprimento variável, não definiria esse sinalizador.

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](creating-an-ole-db-provider.md)