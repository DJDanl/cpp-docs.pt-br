---
title: "Criando um provedor atualizável | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, updatable
- notifications, support in providers
- OLE DB providers, creating
ms.assetid: bdfd5c9f-1c6f-4098-822c-dd650e70ab82
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e243c7198b479bed226d4bd035297a12fc877de6
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="creating-an-updatable-provider"></a>Criando um provedor atualizável
Atualizável ou provedores que podem ser atualizada pela linguagem Visual C++ (gravar) no repositório de dados. Este tópico discute como criar provedores atualizáveis usando modelos OLE DB.  
  
 Este tópico pressupõe que você esteja iniciando com um provedor viável. Há duas etapas para criar um provedor atualizável. Primeiro você deve decidir como o provedor fará alterações ao repositório de dados; Especificamente, se as alterações devem ser feita imediatamente ou adiada até que um comando de atualização é emitido. A seção "[fazer provedores atualizáveis](#vchowmakingprovidersupdatable)" descreve as alterações e configurações que você precisa fazer no código do provedor.  
  
 Em seguida, você deve verificar se que seu provedor contém todas as funcionalidades para dar suporte a qualquer coisa que o consumidor pode solicitar dele. Se o consumidor deseja atualizar o armazenamento de dados, o provedor deve conter código que mantém os dados para o armazenamento de dados. Por exemplo, você pode usar a biblioteca de tempo de execução de C ou MFC para executar essas operações em sua fonte de dados. A seção "[gravando para a fonte de dados](#vchowwritingtothedatasource)" descreve como gravar a fonte de dados, lidar com **nulo** e valores padrão e definir os sinalizadores de coluna.  
  
> [!NOTE]
>  UpdatePV é um exemplo de um provedor atualizável. UpdatePV é o mesmo que MyProv, mas com suporte atualizável.  
  
##  <a name="vchowmakingprovidersupdatable"></a> Tornando provedores atualizáveis  
 Para fazer com que um provedor atualizável para entender as operações que você deseja que o provedor para executar o repositório de dados e como você deseja que o provedor para executar essas operações. Especificamente, o principal problema é se atualizações para o repositório de dados a ser feita imediatamente ou adiada (em lotes) até que um comando de atualização é emitido.  
  
 Você deve primeiramente decidir se deve herdar de `IRowsetChangeImpl` ou `IRowsetUpdateImpl` em sua classe de conjunto de linhas. Dependendo de qual deles você optar por implementar, a funcionalidade dos três métodos será afetada: `SetData`, **InsertRows**, e `DeleteRows`.  
  
-   Se você herdar de [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md), chamar esses três métodos imediatamente altera o repositório de dados.  
  
-   Se você herdar de [IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md), os métodos adiar as alterações ao repositório de dados até que você chame **atualização**, `GetOriginalData`, ou **desfazer**. Se a atualização envolver várias alterações, elas são executadas em modo de lote (Observe que o envio em lote de alterações pode adicionar uma sobrecarga de memória consideráveis).  
  
 Observe que `IRowsetUpdateImpl` deriva de `IRowsetChangeImpl`. Portanto, `IRowsetUpdateImpl` permite alterar o recurso de mais capacidade de lote.  
  
#### <a name="to-support-updatability-in-your-provider"></a>Para dar suporte a atualização no provedor  
  
1.  Em sua classe de conjunto de linhas, herdam `IRowsetChangeImpl` ou `IRowsetUpdateImpl`. Essas classes fornecem interfaces apropriadas para o repositório de dados de alteração:  
  
     **Adicionando IRowsetChange**  
  
     Adicionar `IRowsetChangeImpl` para sua cadeia de herança usando este formulário:  
  
    ```  
    IRowsetChangeImpl< rowset-name, storage-name >  
    ```  
  
     Também adicione `COM_INTERFACE_ENTRY(IRowsetChange)` para o `BEGIN_COM_MAP` seção em sua classe de conjunto de linhas.  
  
     **Adicionando IRowsetUpdate**  
  
     Adicionar `IRowsetUpdate` para sua cadeia de herança usando este formulário:  
  
    ```  
    IRowsetUpdateImpl< rowset-name, storage>  
    ```  
  
    > [!NOTE]
    >  Você deve remover o `IRowsetChangeImpl` linha de sua cadeia de herança. Esta uma exceção à diretiva mencionada anteriormente deve incluir o código para `IRowsetChangeImpl`.  
  
2.  Adicione o seguinte para o mapa COM (**BEGIN_COM_MAP... END_COM_MAP**):  
  
    |Se você implementar|Adicionar ao mapa de COM|  
    |----------------------|--------------------|  
    |`IRowsetChangeImpl`|`COM_INTERFACE_ENTRY(IRowsetChange)`|  
    |`IRowsetUpdateImpl`|`COM_INTERFACE_ENTRY(IRowsetChange)COM_INTERFACE_ENTRY(IRowsetUpdate)`|  
  
3.  Em seu comando, adicione o seguinte ao seu mapa de conjunto de propriedade (**BEGIN_PROPSET_MAP... END_PROPSET_MAP**):  
  
    |Se você implementar|Adicionar ao mapa de conjunto de propriedade|  
    |----------------------|-----------------------------|  
    |`IRowsetChangeImpl`|`PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)`|  
    |`IRowsetUpdateImpl`|`PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)`|  
  
4.  Em seu mapa de conjunto de propriedade, você também deve incluir todas as configurações a seguir como aparecem abaixo:  
  
    ```  
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
  
     Você pode encontrar os valores usados essas chamadas de macro examinando Atldb.h para as IDs de propriedade e valores (se Atldb.h difere a documentação online, Atldb.h substitui a documentação).  
  
    > [!NOTE]
    >  Muitas do **VARIANT_FALSE** e `VARIANT_TRUE` configurações forem necessárias para os modelos OLE DB; a especificação OLE DB diz que podem ser leitura/gravação, mas os modelos OLE DB só podem oferecer suporte a um valor.  
  
     **Se você implementar IRowsetChangeImpl**  
  
     Se você implementar `IRowsetChangeImpl`, você deve definir as propriedades a seguir no seu provedor. Essas propriedades são usadas principalmente para solicitar interfaces por **icommandproperties:: SetProperties**.  
  
    -   `DBPROP_IRowsetChange`: Isso automaticamente configuração define **DBPROP_IRowsetChange**.  
  
    -   `DBPROP_UPDATABILITY`: Um bitmask que especifica os métodos com suporte em `IRowsetChange`: `SetData`, `DeleteRows`, ou `InsertRow`.  
  
    -   `DBPROP_CHANGEINSERTEDROWS`: O consumidor pode chamar **IRowsetChange:: DeleteRows** ou `SetData` para linhas recentemente inseridas.  
  
    -   `DBPROP_IMMOBILEROWS`: O conjunto de linhas não reorganizará as linhas inseridas ou atualizadas.  
  
     **Se você implementar IRowsetUpdateImpl**  
  
     Se você implementar `IRowsetUpdateImpl`, você deve definir as propriedades a seguir no seu provedor, além para definir todas as propriedades para `IRowsetChangeImpl` listados anteriormente:  
  
    -   `DBPROP_IRowsetUpdate`.  
  
    -   `DBPROP_OWNINSERT`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    -   `DBPROP_OWNUPDATEDELETE`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    -   `DBPROP_OTHERINSERT`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    -   `DBPROP_OTHERUPDATEDELETE`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    -   `DBPROP_REMOVEDELETED`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    -   `DBPROP_MAXPENDINGROWS`.  
  
        > [!NOTE]
        >  Se você der suporte a notificações, você também pode ter algumas outras propriedades também; Consulte a seção sobre `IRowsetNotifyCP` desta lista.  
  
     Por exemplo de como as propriedades são definidas, consulte a propriedade de conjunto de mapa **CUpdateCommand** (em Rowset.h) em [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f).  
  
##  <a name="vchowwritingtothedatasource"></a> Gravando para a fonte de dados  
 Para ler a fonte de dados, chame o **Execute** função. Para gravar a fonte de dados, chame o `FlushData` função. (Em termos gerais, liberação meios para salvar as modificações feitas para uma tabela ou índice em disco).  
  
```  
FlushData(HROW, HACCESSOR);  
```  
  
 O identificador de linha (*HROW*) e o identificador do acessador (*HACCESSOR*) argumentos permitem que você especifique a região para gravação. Normalmente, você escreve um único campo de dados por vez.  
  
 O `FlushData` método grava dados no formato em que foi originalmente armazenado. Se essa função não substituir, seu provedor funcione corretamente, mas as alterações não serão liberadas para o repositório de dados.  
  
### <a name="when-to-flush"></a>Quando você liberar  
 A chamada de modelos de provedor `FlushData` sempre que dados precisam ser gravados no armazenamento de dados; isso normalmente (mas nem sempre) ocorre como resultado de chamadas para as funções a seguir:  
  
-   **IRowsetChange::DeleteRows**  
  
-   **IRowsetChange::SetData**  
  
-   **IRowsetChange::InsertRows** (se há novos dados a ser inserido na linha)  
  
-   **IRowsetUpdate::Update**  
  
### <a name="how-it-works"></a>Como ele funciona  
 O consumidor faz uma chamada que requer uma liberação (como **atualização**) e esta chamada é passada para o provedor, que sempre faz o seguinte:  
  
-   Chamadas `SetDBStatus` sempre que você tiver um valor de status associado (consulte *OLE DB programadores referência*, capítulo 6, *partes de dados: Status*).  
  
-   Verifica se os sinalizadores de coluna.  
  
-   Chama `IsUpdateAllowed`.  
  
 Essas três etapas ajudam a fornecer segurança. Em seguida, chama o provedor `FlushData`.  
  
### <a name="how-to-implement-flushdata"></a>Como implementar FlushData  
 Para implementar `FlushData`, você precisa levar em consideração vários problemas:  
  
-   Certificando-se de que o repositório de dados pode manipular as alterações.  
  
-   Tratamento de **nulo** valores.  
  
-   Lidar com valores padrão.  
  
 Para implementar seu próprio `FlushData` método, você precisa:  
  
-   Vá para sua classe de conjunto de linhas.  
  
-   No conjunto de linhas classe colocar a declaração de:  
  
```  
HRESULT FlushData(HROW, HACCESSOR)  
{  
    // Insert your implementation here and return an HRESULT.  
}  
```  
  
-   Forneça uma implementação de `FlushData`.  
  
 Uma implementação válida de `FlushData` armazena apenas as linhas e colunas que na verdade são atualizadas. Você pode usar o *HROW* e *HACCESSOR* parâmetros para determinar a linha atual e a coluna que está sendo armazenado para otimização.  
  
 Normalmente, o maior desafio está trabalhando com seu próprio repositório de dados nativos. Se possível, tente:  
  
-   Manter o método de gravação para o repositório de dados mais simple possível.  
  
-   Tratar **nulo** valores (opcionais, mas aconselhados).  
  
-   Lidar com valores padrão (opcionais, mas aconselhados).  
  
 A melhor maneira de fazer é ter os valores reais especificados em seu armazenamento de dados para **nulo** e os valores padrão. É melhor se você pode extrapolar esses dados. Se não, é recomendável não permitir **nulo** e os valores padrão.  
  
 A exemplo a seguir mostra como `FlushData` é implementado no `RUpdateRowset` classe no [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) exemplo (consulte Rowset.h no código de exemplo):  
  
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
  
### <a name="handling-changes"></a>Controlando alterações  
 Provedor controlar as alterações, você primeiro precisa certificar-se de que seu armazenamento de dados (como um arquivo de texto ou um arquivo de vídeo) possui recursos que permitem a você fazer alterações nele. Se não estiver, você deve criar esse código separadamente do projeto de provedor.  
  
### <a name="handling-null-data"></a>Manipulação de dados nulos  
 É possível que um usuário final enviará **nulo** dados. Quando você escreve **nulo** valores para os campos na fonte de dados, pode haver problemas em potencial. Imagine um aplicativo de ordem de assumir que aceita valores para cidade e o CEP; ele pode aceitar um ou ambos os valores, mas não nenhuma porque nesse caso seria impossível entrega. Portanto, você precisa restringir determinadas combinações de **nulo** valores nos campos que fazem sentido para o seu aplicativo.  
  
 Como desenvolvedor do provedor, você deve considerar como você armazenará os dados, como você lerá dados do armazenamento de dados e como especificar que para o usuário. Especificamente, você deve considerar como alterar o status do conjunto de linhas de dados na fonte de dados data (por exemplo, DataStatus = **nulo**). Decidir qual valor de retorno quando um consumidor acessa um campo contendo um **nulo** valor.  
  
 Examine o código do [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) exemplo; ele ilustra como um provedor pode tratar **nulo** dados. Em UpdatePV, o provedor armazena **nulo** dados escrevendo a cadeia de caracteres "NULL" no repositório de dados. Quando lê **nulo** repositório de dados, ele vê essa cadeia de caracteres e esvazia o buffer, criando um **nulo** cadeia de caracteres. Ele também tem uma substituição de `IRowsetImpl::GetDBStatus` em que ele retorna **DBSTATUS_S_ISNULL** se esse valor de dados está vazio.  
  
### <a name="marking-nullable-columns"></a>Marcar colunas anuláveis  
 Se você implementar também conjuntos de linhas de esquema (consulte `IDBSchemaRowsetImpl`), sua implementação deverá especificar o **DBSCHEMA_COLUMNS** conjunto de linhas (geralmente marcado no provedor por **C***xxx*** SchemaColSchemaRowset**) que a coluna é anulável.  
  
 Você também precisa especificar que todas as colunas anuláveis contêm o **DBCOLUMNFLAGS_ISNULLABLE** valor na sua versão do `GetColumnInfo`.  
  
 A implementação de modelos OLE DB, se você não marcar colunas como anuláveis, o provedor supõe que eles devem conter um valor e não permitirá que o consumidor enviar valores nulos.  
  
 A exemplo a seguir mostra como o **CommonGetColInfo** função é implementada no **CUpdateCommand** (consulte UpProvRS.cpp) em UpdatePV. Observe como as colunas têm isso **DBCOLUMNFLAGS_ISNULLABLE** para colunas anuláveis.  
  
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
 Assim como acontece com **nulo** dados, você tem a responsabilidade de lidar com valores padrão de alteração.  
  
 O padrão de `FlushData` e **Execute** deve retornar `S_OK`. Portanto, se você não substituir essa função, as alterações parecem bem-sucedidos (`S_OK` será retornado), mas eles não serão transmitidos para o repositório de dados.  
  
 No [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) exemplo (em Rowset.h), o `SetDBStatus` método trata os valores padrão da seguinte maneira:  
  
```  
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
 Se você der suporte a valores padrão em colunas, você precisa configurá-lo usando os metadados no  **\< ***classe de provedor***> Conjunto_de_linhas_de_esquema** classe. Set *m_bColumnHasDefault* = `VARIANT_TRUE`.  
  
 Você também tem a responsabilidade de definir os sinalizadores de coluna, que são especificados usando o **DBCOLUMNFLAGS** tipo enumerado. Os sinalizadores de coluna descrevem as características da coluna.  
  
 Por exemplo, o `CUpdateSessionColSchemaRowset` classe em [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) (no Session.h), a primeira coluna é configurada dessa forma:  
  
```  
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
  
 Esse código especifica, entre outras coisas, a coluna dá suporte a um valor padrão de 0, que seja gravável, e se todos os dados na coluna tem o mesmo tamanho. Se você deseja que os dados em uma coluna com comprimento variável, você definiria não esse sinalizador.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)