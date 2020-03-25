---
title: Criando um provedor atualizável
ms.date: 08/16/2018
helpviewer_keywords:
- OLE DB providers, updatable
- notifications, support in providers
- OLE DB providers, creating
ms.assetid: bdfd5c9f-1c6f-4098-822c-dd650e70ab82
ms.openlocfilehash: 2811cd56bdc87282b9d4395a9a79ba9b333dadee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211387"
---
# <a name="creating-an-updatable-provider"></a>Criando um provedor atualizável

O C++ Visual dá suporte a provedores atualizáveis ou provedores que podem atualizar (gravar no) armazenamento de dados. Este tópico discute como criar provedores atualizáveis usando modelos de OLE DB.

Este tópico pressupõe que você está começando com um provedor viável. Há duas etapas para criar um provedor atualizável. Primeiro, você deve decidir como o provedor fará alterações no armazenamento de dados; especificamente, se as alterações devem ser feitas imediatamente ou adiadas até que um comando de atualização seja emitido. A seção "[tornando os provedores atualizáveis](#vchowmakingprovidersupdatable)" descreve as alterações e configurações que você precisa fazer no código do provedor.

Em seguida, você deve verificar se o provedor contém toda a funcionalidade para dar suporte a qualquer coisa que o consumidor possa solicitar. Se o consumidor quiser atualizar o armazenamento de dados, o provedor precisará conter código que persiste dados no repositório de dados. Por exemplo, você pode usar a biblioteca de tempo de execução C ou o MFC para executar essas operações em sua fonte de dados. A seção "[gravando na fonte de dados](#vchowwritingtothedatasource)" descreve como gravar na fonte de dados, lidar com valores nulos e padrão e definir sinalizadores de coluna.

> [!NOTE]
> [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) é um exemplo de um provedor atualizável. UpdatePV é o mesmo que MyProv, mas com suporte atualizável.

##  <a name="making-providers-updatable"></a><a name="vchowmakingprovidersupdatable"></a>Tornando os provedores atualizáveis

A chave para tornar um provedor atualizável é entender quais operações você deseja que seu provedor execute no armazenamento de dados e como você deseja que o provedor realize essas operações. Especificamente, o principal problema é se as atualizações do armazenamento de dados devem ser feitas imediatamente ou adiadas (em lote) até que um comando de atualização seja emitido.

Primeiro, você deve decidir se deseja herdar de `IRowsetChangeImpl` ou `IRowsetUpdateImpl` em sua classe de conjunto de linhas. Dependendo de quais deles você optar por implementar, a funcionalidade de três métodos será afetada: `SetData`, `InsertRows`e `DeleteRows`.

- Se você herdar de [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md), chamar esses três métodos imediatamente alterará o armazenamento de dados.

- Se você herdar de [IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md), os métodos adiarão alterações no armazenamento de dados até que você chame `Update`, `GetOriginalData`ou `Undo`. Se a atualização envolver várias alterações, elas serão executadas no modo de lote (Observe que as alterações em lote podem adicionar uma sobrecarga de memória considerável).

Observe que `IRowsetUpdateImpl` deriva de `IRowsetChangeImpl`. Assim, `IRowsetUpdateImpl` lhe dá capacidade de alteração, além da capacidade do lote.

### <a name="to-support-updatability-in-your-provider"></a>Para dar suporte à atualização em seu provedor

1. Na classe do conjunto de linhas, herde de `IRowsetChangeImpl` ou `IRowsetUpdateImpl`. Essas classes fornecem as interfaces apropriadas para alterar o armazenamento de dados:

   **Adicionando IRowsetChange**

   Adicione `IRowsetChangeImpl` à sua cadeia de herança usando este formulário:

    ```cpp
    IRowsetChangeImpl< rowset-name, storage-name >
    ```

   Além disso, adicione `COM_INTERFACE_ENTRY(IRowsetChange)` à seção `BEGIN_COM_MAP` na classe do conjunto de linhas.

   **Adicionando IRowsetUpdate**

   Adicione `IRowsetUpdate` à sua cadeia de herança usando este formulário:

    ```cpp
    IRowsetUpdateImpl< rowset-name, storage>
    ```

   > [!NOTE]
   > Você deve remover a linha de `IRowsetChangeImpl` da sua cadeia de herança. Essa única exceção à diretiva mencionada anteriormente deve incluir o código para `IRowsetChangeImpl`.

1. Adicione o seguinte ao seu mapa de COM (`BEGIN_COM_MAP ... END_COM_MAP`):

   |  Se você implementar   |           Adicionar ao mapa COM             |
   |---------------------|--------------------------------------|
   | `IRowsetChangeImpl` | `COM_INTERFACE_ENTRY(IRowsetChange)` |
   | `IRowsetUpdateImpl` | `COM_INTERFACE_ENTRY(IRowsetUpdate)` |

   | Se você implementar | Adicionar ao mapa do conjunto de propriedades |
   |----------------------|-----------------------------|
   | `IRowsetChangeImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)` |
   | `IRowsetUpdateImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)` |

1. No comando, adicione o seguinte ao seu mapa de conjunto de Propriedades (`BEGIN_PROPSET_MAP ... END_PROPSET_MAP`):

   |  Se você implementar   |                                             Adicionar ao mapa do conjunto de propriedades                                              |
   |---------------------|------------------------------------------------------------------------------------------------------------------|
   | `IRowsetChangeImpl` |                            `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)`                             |
   | `IRowsetUpdateImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)` |

1. No mapa do conjunto de propriedades, você também deve incluir todas as configurações a seguir, como aparecem abaixo:

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

   Você pode encontrar os valores usados nessas chamadas de macro olhando Atldb. h para os valores e IDs de propriedade (se Atldb. h diferir da documentação online, Atldb. h substituirá a documentação).

   > [!NOTE]
   > Muitas das configurações de `VARIANT_FALSE` e `VARIANT_TRUE` são exigidas pelos modelos de OLE DB; a especificação de OLE DB diz que eles podem ser de leitura/gravação, mas os modelos de OLE DB só podem dar suporte a um valor.

   **Se você implementar IRowsetChangeImpl**

   Se você implementar `IRowsetChangeImpl`, deverá definir as propriedades a seguir em seu provedor. Essas propriedades são usadas principalmente para solicitar interfaces por meio de `ICommandProperties::SetProperties`.

   - `DBPROP_IRowsetChange`: definir isso define automaticamente `DBPROP_IRowsetChange`.

   - `DBPROP_UPDATABILITY`: um bitmask especificando os métodos com suporte em `IRowsetChange`: `SetData`, `DeleteRows`ou `InsertRow`.

   - `DBPROP_CHANGEINSERTEDROWS`: o consumidor pode chamar `IRowsetChange::DeleteRows` ou `SetData` para linhas recentemente inseridas.

   - `DBPROP_IMMOBILEROWS`: conjunto de linhas não reordenar linhas inseridas ou atualizadas.

   **Se você implementar IRowsetUpdateImpl**

   Se você implementar `IRowsetUpdateImpl`, deverá definir as propriedades a seguir em seu provedor, além de definir todas as propriedades de `IRowsetChangeImpl` listadas anteriormente:

   - `DBPROP_IRowsetUpdate`.

   - `DBPROP_OWNINSERT`: deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_OWNUPDATEDELETE`: deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_OTHERINSERT`: deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_OTHERUPDATEDELETE`: deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_REMOVEDELETED`: deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_MAXPENDINGROWS`.

   > [!NOTE]
   > Se você oferecer suporte a notificações, também poderá ter outras propriedades; consulte a seção sobre `IRowsetNotifyCP` para esta lista.

##  <a name="writing-to-the-data-source"></a><a name="vchowwritingtothedatasource"></a>Gravando na fonte de dados

Para ler a partir da fonte de dados, chame a função `Execute`. Para gravar na fonte de dados, chame a função `FlushData`. (Em um sentido geral, a liberação significa salvar as modificações feitas em uma tabela ou índice no disco.)

```cpp
FlushData(HROW, HACCESSOR);
```

Os argumentos identificador de linha (HROW) e identificador de acessador (HACCESSOR) permitem que você especifique a região a ser gravada. Normalmente, você escreve um único campo de dados por vez.

O método `FlushData` grava dados no formato no qual ele foi originalmente armazenado. Se você não substituir essa função, seu provedor funcionará corretamente, mas as alterações não serão liberadas para o armazenamento de dados.

### <a name="when-to-flush"></a>Quando liberar

Os modelos de provedor chamam FlushData sempre que os dados precisam ser gravados no armazenamento de dados; Normalmente, isso ocorre como resultado de chamadas para as seguintes funções:

- `IRowsetChange::DeleteRows`

- `IRowsetChange::SetData`

- `IRowsetChange::InsertRows` (se houver novos dados a serem inseridos na linha)

- `IRowsetUpdate::Update`

### <a name="how-it-works"></a>Como ela funciona

O consumidor faz uma chamada que requer uma liberação (como atualização) e essa chamada é passada para o provedor, que sempre faz o seguinte:

- Chama `SetDBStatus` sempre que você tem um valor de status associado.

- Verifica os sinalizadores de coluna.

- Chama `IsUpdateAllowed`.

Essas três etapas ajudam a fornecer segurança. Em seguida, o provedor chama `FlushData`.

### <a name="how-to-implement-flushdata"></a>Como implementar FlushData

Para implementar `FlushData`, você precisa levar em conta vários problemas:

Garantir que o armazenamento de dados possa lidar com alterações.

Tratamento de valores nulos.

### <a name="handling-default-values"></a>Manipulando valores padrão.

Para implementar seu próprio método de `FlushData`, você precisa:

- Vá para a classe do conjunto de linhas.

- Na classe Rowset, coloque a declaração de:

   ```cpp
   HRESULT FlushData(HROW, HACCESSOR)
   {
      // Insert your implementation here and return an HRESULT.
   }
   ```

- Forneça uma implementação de `FlushData`.

Uma boa implementação de `FlushData` armazena apenas as linhas e colunas que são realmente atualizadas. Você pode usar os parâmetros HROW e HACCESSOR para determinar a linha e a coluna atuais que estão sendo armazenadas para otimização.

Normalmente, o maior desafio é trabalhar com seu próprio armazenamento de dados nativo. Se possível, tente:

- Mantenha o método de gravação no armazenamento de dados o mais simples possível.

- Tratar valores nulos (opcional, mas recomendado).

- Manipule valores padrão (opcional, mas recomendado).

A melhor coisa a fazer é ter valores reais especificados em seu repositório de dados para valores nulos e padrão. É melhor se você puder extrapolar esses dados. Caso contrário, é recomendável não permitir valores nulos e padrão.

O exemplo a seguir mostra como `FlushData` é implementado na classe `RUpdateRowset` no exemplo de `UpdatePV` (consulte Rowset. h no código de exemplo):

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

### <a name="handling-changes"></a>Manipulando alterações

Para que seu provedor manipule alterações, primeiro você precisa verificar se o armazenamento de dados (como um arquivo de texto ou arquivo de vídeo) tem instalações que permitem que você faça alterações nela. Se não tiver, você deverá criar esse código separadamente do projeto do provedor.

### <a name="handling-null-data"></a>Manipulando dados nulos

É possível que um usuário final envie dados nulos. Quando você grava valores nulos em campos na fonte de dados, pode haver possíveis problemas. Imagine um aplicativo de pedido que aceite valores para cidade e código postal; Ele poderia aceitar um ou ambos os valores, mas não nenhum, porque nesse caso a entrega seria impossível. Portanto, você precisa restringir determinadas combinações de valores nulos em campos que fazem sentido para seu aplicativo.

Como desenvolvedor do provedor, você precisa considerar como armazenará esses dados, como você lerá esses dados do armazenamento de dados e como você especifica isso para o usuário. Especificamente, você deve considerar como alterar o status dos dados dos dados do conjunto de linhas na fonte de dados (por exemplo, DataStatus = NULL). Você decide qual valor retornar quando um consumidor acessa um campo que contém um valor nulo.

Examine o código no exemplo UpdatePV; Ele ilustra como um provedor pode manipular dados nulos. No UpdatePV, o provedor armazena dados nulos gravando a cadeia de caracteres "NULL" no repositório de dados. Quando ele lê dados nulos do armazenamento de dados, ele vê a cadeia de caracteres e, em seguida, esvazia o buffer, criando uma cadeia de caracteres nula. Ele também tem uma substituição de `IRowsetImpl::GetDBStatus` em que ele retorna DBSTATUS_S_ISNULL se esse valor de dados estiver vazio.

### <a name="marking-nullable-columns"></a>Marcando colunas anuláveis

Se você também implementar conjuntos de linhas de esquema (consulte `IDBSchemaRowsetImpl`), sua implementação deve especificar no conjunto de DBSCHEMA_COLUMNS (geralmente marcado em seu provedor por CxxxSchemaColSchemaRowset) que a coluna é anulável.

Você também precisa especificar que todas as colunas anuláveis contenham o valor DBCOLUMNFLAGS_ISNULLABLE em sua versão do `GetColumnInfo`.

Na implementação de modelos de OLE DB, se você não marcar colunas como anuláveis, o provedor pressupõe que ele deve conter um valor e não permitirá que o consumidor envie valores nulos.

O exemplo a seguir mostra como a função `CommonGetColInfo` é implementada em CUpdateCommand (consulte os próprios Provrs. cpp) em UpdatePV. Observe como as colunas têm essa DBCOLUMNFLAGS_ISNULLABLE para colunas anuláveis.

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

Assim como acontece com dados nulos, você tem a responsabilidade de lidar com a alteração de valores padrão.

O padrão de `FlushData` e `Execute` é retornar S_OK. Portanto, se você não substituir essa função, as alterações parecerão ter sucesso (S_OK serão retornadas), mas elas não serão transmitidas para o armazenamento de dados.

No exemplo de `UpdatePV` (em Rowset. h), o método `SetDBStatus` manipula valores padrão da seguinte maneira:

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

Se você der suporte a valores padrão em suas colunas, precisará defini-lo usando metadados na classe de provedor de \<\>classe SchemaRowset. Defina `m_bColumnHasDefault = VARIANT_TRUE`.

Você também tem a responsabilidade de definir os sinalizadores de coluna, que são especificados usando o tipo enumerado DBCOLUMNFLAGS. Os sinalizadores de coluna descrevem as características da coluna.

Por exemplo, na classe `CUpdateSessionColSchemaRowset` em `UpdatePV` (em Session. h), a primeira coluna é configurada dessa forma:

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

Esse código especifica, entre outras coisas, que a coluna dá suporte a um valor padrão de 0, que pode ser gravada e que todos os dados na coluna têm o mesmo comprimento. Se você quiser que os dados em uma coluna tenham comprimento variável, você não definirá esse sinalizador.

## <a name="see-also"></a>Confira também

[Criando um provedor do OLE DB](creating-an-ole-db-provider.md)
