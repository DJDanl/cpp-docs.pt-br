---
title: Criando um provedor atualizável
ms.date: 08/16/2018
helpviewer_keywords:
- OLE DB providers, updatable
- notifications, support in providers
- OLE DB providers, creating
ms.assetid: bdfd5c9f-1c6f-4098-822c-dd650e70ab82
ms.openlocfilehash: 720ceba397d17642402de4d44cbb4481852fa153
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365552"
---
# <a name="creating-an-updatable-provider"></a>Criando um provedor atualizável

O Visual C++ suporta provedores ou provedores atualizados que podem atualizar (gravar) o armazenamento de dados. Este tópico discute como criar provedores updatable usando modelos OLE DB.

Este tópico pressupõe que você está começando com um provedor viável. Existem duas etapas para criar um provedor updatable. Primeiro, você deve decidir como o provedor fará alterações no armazenamento de dados; especificamente, se as alterações devem ser feitas imediatamente ou adiadas até que um comando de atualização seja emitido. A seção "[Making Providers Updatable](#vchowmakingprovidersupdatable)" descreve as alterações e configurações que você precisa fazer no código do provedor.

Em seguida, você deve certificar-se de que seu provedor contém todas as funcionalidades para suportar qualquer coisa que o consumidor possa solicitar dele. Se o consumidor quiser atualizar o armazenamento de dados, o provedor tem que conter código que persiste nos dados para o armazenamento de dados. Por exemplo, você pode usar a Biblioteca c run-time ou MFC para executar tais operações na sua fonte de dados. A seção "[Writing to the Data Source](#vchowwritingtothedatasource)" descreve como escrever para a fonte de dados, lidar com valores NULL e padrão e definir sinalizadores de coluna.

> [!NOTE]
> [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) é um exemplo de provedor updatable. UpdatePV é o mesmo que MyProv, mas com suporte updatable.

## <a name="making-providers-updatable"></a><a name="vchowmakingprovidersupdatable"></a>Tornando os provedores updatable

A chave para tornar um provedor updatable é entender quais operações você quer que seu provedor realize no armazenamento de dados e como você quer que o provedor realize essas operações. Especificamente, a principal questão é se as atualizações no armazenamento de dados devem ser feitas imediatamente ou diferidas (em lote) até que um comando de atualização seja emitido.

Você deve primeiro decidir `IRowsetChangeImpl` se `IRowsetUpdateImpl` herdará ou em sua classe de rowset. Dependendo de qual deles você escolher implementar, a funcionalidade de `SetData`três `InsertRows`métodos será afetada: , e `DeleteRows`.

- Se você herdar do [IRowsetChangeImpl,](../../data/oledb/irowsetchangeimpl-class.md)chamar esses três métodos muda imediatamente o armazenamento de dados.

- Se você herdar do [IRowsetUpdateImpl,](../../data/oledb/irowsetupdateimpl-class.md)os métodos adiam alterações no armazenamento de dados até que você ligue, `Update` `GetOriginalData`ou `Undo`. Se a atualização envolver várias alterações, elas são realizadas no modo de lote (observe que as alterações de loteamento podem adicionar uma sobrecarga de memória considerável).

Note `IRowsetUpdateImpl` que deriva `IRowsetChangeImpl`de . Assim, `IRowsetUpdateImpl` dá-lhe capacidade de alteração mais capacidade de lote.

### <a name="to-support-updatability-in-your-provider"></a>Para suportar a updatability em seu provedor

1. Na sua classe rowset, herde `IRowsetChangeImpl` ou `IRowsetUpdateImpl`. Essas classes fornecem interfaces apropriadas para alterar o armazenamento de dados:

   **Adicionando IRowsetChange**

   Adicione `IRowsetChangeImpl` à sua cadeia de herança usando este formulário:

    ```cpp
    IRowsetChangeImpl< rowset-name, storage-name >
    ```

   Adicione `COM_INTERFACE_ENTRY(IRowsetChange)` também `BEGIN_COM_MAP` à seção em sua classe de conjunto de linhas.

   **Adicionando IRowsetUpdate**

   Adicione `IRowsetUpdate` à sua cadeia de herança usando este formulário:

    ```cpp
    IRowsetUpdateImpl< rowset-name, storage>
    ```

   > [!NOTE]
   > Você deve `IRowsetChangeImpl` remover a linha de sua cadeia de herança. Esta exceção à diretiva mencionada anteriormente `IRowsetChangeImpl`deve incluir o código para .

1. Adicione o seguinte ao`BEGIN_COM_MAP ... END_COM_MAP`seu mapa COM ():

   |  Se você implementar   |           Adicionar ao mapa COM             |
   |---------------------|--------------------------------------|
   | `IRowsetChangeImpl` | `COM_INTERFACE_ENTRY(IRowsetChange)` |
   | `IRowsetUpdateImpl` | `COM_INTERFACE_ENTRY(IRowsetUpdate)` |

   | Se você implementar | Adicionar ao mapa do conjunto de propriedades |
   |----------------------|-----------------------------|
   | `IRowsetChangeImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)` |
   | `IRowsetUpdateImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)` |

1. No seu comando, adicione o seguinte`BEGIN_PROPSET_MAP ... END_PROPSET_MAP`ao mapa do conjunto de propriedades ():

   |  Se você implementar   |                                             Adicionar ao mapa do conjunto de propriedades                                              |
   |---------------------|------------------------------------------------------------------------------------------------------------------|
   | `IRowsetChangeImpl` |                            `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)`                             |
   | `IRowsetUpdateImpl` | `PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)` |

1. No mapa do conjunto de propriedades, você também deve incluir todas as seguintes configurações à medida que elas aparecem abaixo:

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

   Você pode encontrar os valores usados nessas chamadas de macro olhando em Atldb.h para os IDs e valores da propriedade (se Atldb.h difere da documentação on-line, Atldb.h substitui a documentação).

   > [!NOTE]
   > Muitas das `VARIANT_FALSE` `VARIANT_TRUE` configurações são exigidas pelos modelos OLE DB; a especificação oLE DB diz que eles podem ser lidos/gravar, mas os modelos OLE DB só podem suportar um valor.

   **Se você implementar iRowsetChangeImpl**

   Se você `IRowsetChangeImpl`implementar, você deve definir as seguintes propriedades no seu provedor. Essas propriedades são usadas principalmente para `ICommandProperties::SetProperties`solicitar interfaces através de .

   - `DBPROP_IRowsetChange`: Definir isso `DBPROP_IRowsetChange`configura automaticamente .

   - `DBPROP_UPDATABILITY`: Uma máscara de bit especificando `IRowsetChange` `SetData`os `DeleteRows`métodos suportados em: , ou `InsertRow`.

   - `DBPROP_CHANGEINSERTEDROWS`: O `IRowsetChange::DeleteRows` consumidor `SetData` pode ligar ou para linhas recém-inseridas.

   - `DBPROP_IMMOBILEROWS`: O conjunto de linhas não reordenará as linhas inseridas ou atualizadas.

   **Se você implementar iRowsetUpdateImpl**

   Se você `IRowsetUpdateImpl`implementar, você deve definir as seguintes propriedades no `IRowsetChangeImpl` seu provedor, além de definir todas as propriedades para listadas anteriormente:

   - `DBPROP_IRowsetUpdate`.

   - `DBPROP_OWNINSERT`: Deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_OWNUPDATEDELETE`: Deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_OTHERINSERT`: Deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_OTHERUPDATEDELETE`: Deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_REMOVEDELETED`: Deve ser READ_ONLY e VARIANT_TRUE.

   - `DBPROP_MAXPENDINGROWS`.

   > [!NOTE]
   > Se você suportar notificações, você também pode ter algumas outras propriedades; ver a `IRowsetNotifyCP` seção sobre esta lista.

## <a name="writing-to-the-data-source"></a><a name="vchowwritingtothedatasource"></a>Escrevendo para a Fonte de Dados

Para ler a partir da `Execute` fonte de dados, ligue para a função. Para escrever na fonte de `FlushData` dados, ligue para a função. (Em um sentido geral, flush significa salvar modificações que você faz em uma tabela ou índice para disco.)

```cpp
FlushData(HROW, HACCESSOR);
```

Os argumentos de alça de linha (HROW) e alça do acessório (HACCESSOR) permitem especificar a região para gravar. Normalmente, você escreve um único campo de dados de cada vez.

O `FlushData` método escreve dados no formato em que foi armazenado originalmente. Se você não substituir essa função, o provedor funcionará corretamente, mas as alterações não serão liberadas para o armazenamento de dados.

### <a name="when-to-flush"></a>Quando para Flush

Os modelos do provedor chamam FlushData sempre que os dados precisam ser gravados no armazenamento de dados; isso geralmente (mas nem sempre) ocorre como resultado de chamadas para as seguintes funções:

- `IRowsetChange::DeleteRows`

- `IRowsetChange::SetData`

- `IRowsetChange::InsertRows`(se houver novos dados para inserir na linha)

- `IRowsetUpdate::Update`

### <a name="how-it-works"></a>Como funciona

O consumidor faz uma chamada que requer um flush (como Atualização) e esta chamada é passada para o provedor, que sempre faz o seguinte:

- Chamadas `SetDBStatus` sempre que você tem um valor de status vinculado.

- Verifica bandeiras de coluna.

- Chama `IsUpdateAllowed`.

Essas três etapas ajudam a fornecer segurança. Em seguida, `FlushData`o provedor chama .

### <a name="how-to-implement-flushdata"></a>Como implementar flushdata

Para `FlushData`implementar, você precisa levar em conta vários problemas:

Certificando-se de que o armazenamento de dados pode lidar com alterações.

Manuseio de valores NUUTOs.

### <a name="handling-default-values"></a>Manipulação de valores padrão.

Para implementar `FlushData` seu próprio método, você precisa:

- Vá para sua aula de rowset.

- Na classe rowset colocar a declaração de:

   ```cpp
   HRESULT FlushData(HROW, HACCESSOR)
   {
      // Insert your implementation here and return an HRESULT.
   }
   ```

- Fornecer uma `FlushData`implementação de .

Uma boa `FlushData` implementação das lojas apenas as linhas e colunas que são realmente atualizadas. Você pode usar os parâmetros HROW e HACCESSOR para determinar a linha e a coluna atuais que estão sendo armazenadas para otimização.

Normalmente, o maior desafio é trabalhar com seu próprio armazenamento de dados nativo. Se possível, tente:

- Mantenha o método de escrever no seu armazenamento de dados o mais simples possível.

- Lidar com valores NULL (opcional, mas aconselhado).

- Lidar com os valores padrão (opcional, mas aconselhado).

A melhor coisa a fazer é ter valores reais especificados em seu armazenamento de dados para valores NULOS e padrão. É melhor se você puder extrapolar esses dados. Caso não, é aconselhável não permitir valores NULOS e padrão.

O exemplo a `FlushData` seguir mostra `RUpdateRowset` como `UpdatePV` é implementado na classe na amostra (ver Rowset.h no código da amostra):

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

### <a name="handling-changes"></a>Alterações de manuseio

Para que seu provedor lide com as alterações, primeiro você precisa garantir que seu armazenamento de dados (como um arquivo de texto ou arquivo de vídeo) tenha facilidades que permitam que você faça alterações nele. Se isso não acontecer, você deve criar esse código separadamente do projeto do provedor.

### <a name="handling-null-data"></a>Manipulação de dados NULOS

É possível que um usuário final envie dados NULL. Quando você escreve valores NULL para campos na fonte de dados, pode haver problemas potenciais. Imagine um aplicativo de tomada de pedidos que aceita valores para a cidade e o código postal; poderia aceitar ambos os valores, mas não nenhum dos dois, porque nesse caso a entrega seria impossível. Portanto, você tem que restringir certas combinações de valores NULL em campos que fazem sentido para sua aplicação.

Como desenvolvedor do provedor, você tem que considerar como você armazenará esses dados, como você lerá esses dados do armazenamento de dados e como você especificará isso para o usuário. Especificamente, você deve considerar como alterar o status dos dados do conjunto de linhas na fonte de dados (por exemplo, DataStatus = NULL). Você decide qual o valor a devolver quando um consumidor acessa um campo contendo um valor NULL.

Veja o código na amostra UpdatePV; ilustra como um provedor pode lidar com dados NULL. No UpdatePV, o provedor armazena dados NULL escrevendo a string "NULL" no armazenamento de dados. Quando ele lê dados NULL do armazenamento de dados, ele vê essa string e, em seguida, esvazia o buffer, criando uma seqüência NULL. Ele também tem uma `IRowsetImpl::GetDBStatus` substituição na qual retorna DBSTATUS_S_ISNULL se esse valor de dados estiver vazio.

### <a name="marking-nullable-columns"></a>Marcando colunas anuladas

Se você também implementar conjuntos `IDBSchemaRowsetImpl`de linhas de esquema (ver), sua implementação deve especificar no conjunto de linhas DBSCHEMA_COLUMNS (geralmente marcado no provedor por CxxxSchemaColSchemaRowset) que a coluna é anulada.

Você também precisa especificar que todas as colunas anuladas `GetColumnInfo`contêm o valor DBCOLUMNFLAGS_ISNULLABLE em sua versão do .

Na implementação dos modelos OLE DB, se você não marcar as colunas como anuladas, o provedor assume que eles devem conter um valor e não permitirá que o consumidor envie valores nulos.

O exemplo a `CommonGetColInfo` seguir mostra como a função é implementada no CUpdateCommand (ver UpProvRS.cpp) no UpdatePV. Observe como as colunas têm essa DBCOLUMNFLAGS_ISNULLABLE para colunas anuladas.

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

Assim como acontece com os dados NULL, você tem a responsabilidade de lidar com a alteração dos valores padrão.

O padrão `FlushData` `Execute` e é retornar S_OK. Portanto, se você não substituir essa função, as alterações parecem ter sucesso (S_OK serão devolvidas), mas elas não serão transmitidas para o armazenamento de dados.

Na `UpdatePV` amostra (em Rowset.h), o `SetDBStatus` método lida com os valores padrão da seguinte forma:

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

### <a name="column-flags"></a>Bandeiras da coluna

Se você suportar valores padrão em suas colunas, você \<precisará\>defini-los usando metadados na classe de provedor, classe SchemaRowset class. Defina `m_bColumnHasDefault = VARIANT_TRUE`.

Você também tem a responsabilidade de definir as bandeiras de coluna, que são especificadas usando o tipo enumerado DBCOLUMNFLAGS. As bandeiras da coluna descrevem as características da coluna.

Por exemplo, `CUpdateSessionColSchemaRowset` na `UpdatePV` classe em (em Session.h), a primeira coluna é configurada desta forma:

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

Este código especifica, entre outras coisas, que a coluna suporta um valor padrão de 0, que ele é gravável, e que todos os dados da coluna têm o mesmo comprimento. Se você quiser que os dados em uma coluna tenham comprimento variável, você não definiria este sinalizador.

## <a name="see-also"></a>Confira também

[Criando um provedor OLE DB](creating-an-ole-db-provider.md)
