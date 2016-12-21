---
title: "Criando um provedor atualiz&#225;vel | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "notificações, suporte em provedores"
  - "Provedores OLE DB, criando"
  - "Provedores OLE DB, atualizável"
ms.assetid: bdfd5c9f-1c6f-4098-822c-dd650e70ab82
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um provedor atualiz&#225;vel
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ 6.0 oferece suporte somente provedores somente leitura.  Visual C\+\+ .NET oferece suporte aos provedores atualizáveis ou os provedores que podem atualizar \(gravação\) o repositório de dados.  Este tópico discute como criar os provedores atualizáveis que usam modelos OLE DB.  
  
 Este tópico pressupõe que você esteja iniciando com um provedor de executáveis.  Há duas etapas para criar um provedor atualizável.  Você deve primeiramente decidir como o provedor fará alterações ao repositório de dados; especificamente, se as alterações devem ser feitas imediatamente ou adiado até que um comando de atualização é emitido.  A seção “[Fazendo provedores atualizáveis](#vchowmakingprovidersupdatable)” descreve as alterações e as configurações que você precisa fazer no código do provedor.  
  
 Em seguida, você deve verificar se seu provedor contém toda a funcionalidade para dar suporte a qualquer coisa que o consumidor pode solicitar delas.  Se o consumidor deseja atualizar o armazenamento de dados, o provedor precisa conter código que persiste dados no repositório de dados.  Por exemplo, você pode usar a biblioteca de tempo de execução C ou o MFC para executar essas operações na fonte de dados.  A seção “[Gravada na fonte de dados](#vchowwritingtothedatasource)” descreve como gravar à fonte de dados, negócios com **nulo** e valores padrão, e sinalizadores de coluna de cluster.  
  
> [!NOTE]
>  UpdatePV é um exemplo de um provedor atualizável.  UpdatePV é o mesmo que MyProv mas com suporte atualizável.  
  
##  <a name="vchowmakingprovidersupdatable"></a> Fazendo provedores atualizáveis  
 A chave para fazer um provedor é atualizável compreendendo operações que você deseja que o provedor para execução no repositório de dados e como você deseja que o provedor para realizar essas operações.  Especificamente, o tema é importante se as atualizações no repositório de dados devem ser feitas imediatamente ou adiado \(processado em lotes\) até que um comando de atualização é emitido.  
  
 Você deve primeiramente decidir se herdar de `IRowsetChangeImpl` ou `IRowsetUpdateImpl` no conjunto de linhas classifica.  Dependendo de qual desses você optar por implementar, a funcionalidade de três métodos será afetada: `SetData`, **InsertRows**, e `DeleteRows`.  
  
-   Se você herda de [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md), chamar esses três métodos altera imediatamente o repositório de dados.  
  
-   Se você herda de [IRowsetUpdateImpl](../Topic/IRowsetUpdateImpl%20Class.md), os métodos adiam alterações ao repositório de dados até que você chame **Atualizar**, `GetOriginalData`, ou **Desfazer**.  Se a atualização envolve várias alterações, são executadas no modo de lote \(observe que o processamento em lotes alterações pode adicionar a sobrecarga considerável de memória\).  
  
 Observe que se `IRowsetUpdateImpl` deriva de `IRowsetChangeImpl`.  Assim, `IRowsetUpdateImpl` oferece o recurso de alteração mais o recurso de lote.  
  
#### Para oferecer suporte à atualização do provedor  
  
1.  Em sua classe do conjunto de linhas, herde de `IRowsetChangeImpl` ou de `IRowsetUpdateImpl`.  Essas classes fornecem interfaces apropriadas para alterar o repositório de dados:  
  
     **Adicionando IRowsetChange**  
  
     Adicionar `IRowsetChangeImpl` a sua cadeia de herança usando esta forma:  
  
    ```  
    IRowsetChangeImpl< rowset-name, storage-name >  
    ```  
  
     Adicionar `COM_INTERFACE_ENTRY(IRowsetChange)` a seção de `BEGIN_COM_MAP` em sua classe do conjunto de linhas.  
  
     **Adicionando IRowsetUpdate**  
  
     Adicionar `IRowsetUpdate` a sua cadeia de herança usando esta forma:  
  
    ```  
    IRowsetUpdateImpl< rowset-name, storage>  
    ```  
  
    > [!NOTE]
    >  Você deve remover a linha de `IRowsetChangeImpl` de sua cadeia de herança.  Esta uma exceção à política mencionada anteriormente deve incluir o código para `IRowsetChangeImpl`.  
  
2.  Adicione o seguinte ao mapa COM \(**BEGIN\_COM\_MAP… END\_COM\_MAP**\):  
  
    |Se você implementa|Adicionar um COM o mapa|  
    |------------------------|-----------------------------|  
    |`IRowsetChangeImpl`|`COM_INTERFACE_ENTRY(IRowsetChange)`|  
    |`IRowsetUpdateImpl`|`COM_INTERFACE_ENTRY(IRowsetChange)COM_INTERFACE_ENTRY(IRowsetUpdate)`|  
  
3.  Em seu comando, adicione o seguinte ao seu o conjunto de propriedades \(**BEGIN\_PROPSET\_MAP… END\_PROPSET\_MAP**\):  
  
    |Se você implementa|Adicionar ao conjunto de propriedades|  
    |------------------------|-------------------------------------------|  
    |`IRowsetChangeImpl`|`PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)`|  
    |`IRowsetUpdateImpl`|`PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)`|  
  
4.  Em seu mapa do conjunto de propriedades, você também deve incluir todas as configurações a seguir como eles aparecem abaixo:  
  
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
  
     Você pode localizar os valores usados nessas chamadas macro examinando em Atldb.h para os IDs de propriedade e valores \(se Atldb.h difere da documentação online, Atldb.h substitui a documentação\).  
  
    > [!NOTE]
    >  Muitas das configurações de **VARIANT\_FALSE** e de `VARIANT_TRUE` são solicitadas pelos modelos OLE DB; a especificação OLE DB diz que podem ser leitura\/gravação, mas os modelos OLE DB só podem dar suporte a um valor.  
  
     **Se você implementa IRowsetChangeImpl**  
  
     Se você implementa `IRowsetChangeImpl`, você deve definir as seguintes propriedades do provedor.  Essas propriedades são usadas para solicitar interfaces com **ICommandProperties::SetProperties**.  
  
    -   `DBPROP_IRowsetChange`: Definir isso define automaticamente **DBPROP\_IRowsetChange**.  
  
    -   `DBPROP_UPDATABILITY`: Uma máscara de bits que especifica os métodos com suporte em `IRowsetChange`: `SetData`, `DeleteRows`, ou `InsertRow`.  
  
    -   `DBPROP_CHANGEINSERTEDROWS`: O consumidor pode chamar **IRowsetChange::DeleteRows** ou `SetData` para linhas recentemente inseridas.  
  
    -   `DBPROP_IMMOBILEROWS`: O conjunto de linhas não reorganizará linhas inseridas ou atualizadas.  
  
     **Se você implementa IRowsetUpdateImpl**  
  
     Se você implementa `IRowsetUpdateImpl`, você deve definir as seguintes propriedades do provedor, além de definir todas as propriedades de `IRowsetChangeImpl` listado anteriormente:  
  
    -   `DBPROP_IRowsetUpdate`.  
  
    -   `DBPROP_OWNINSERT`: Devem ser READ\_ONLY AND VARIANT\_TRUE.  
  
    -   `DBPROP_OWNUPDATEDELETE`: Devem ser READ\_ONLY AND VARIANT\_TRUE.  
  
    -   `DBPROP_OTHERINSERT`: Devem ser READ\_ONLY AND VARIANT\_TRUE.  
  
    -   `DBPROP_OTHERUPDATEDELETE`: Devem ser READ\_ONLY AND VARIANT\_TRUE.  
  
    -   `DBPROP_REMOVEDELETED`: Devem ser READ\_ONLY AND VARIANT\_TRUE.  
  
    -   `DBPROP_MAXPENDINGROWS`.  
  
        > [!NOTE]
        >  Se você oferece suporte a notificações, você também pode ter quaisquer outras propriedades também; consulte a seção em `IRowsetNotifyCP` para essa lista.  
  
     Por exemplo de como as propriedades, consulte o mapa do conjunto de propriedades em **CUpdateCommand** \(em Rowset.h\) em [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f).  
  
##  <a name="vchowwritingtothedatasource"></a> Gravada na fonte de dados  
 Para ler da fonte de dados, chame a função de **Executar** .  Para gravar na fonte de dados, chame a função de `FlushData` . \(No sentido geral, a liberação significa salvar alterações feitas em uma tabela ou um índice no disco.\)  
  
```  
FlushData(HROW, HACCESSOR);  
```  
  
 Os argumentos do identificador de linha \(*HROW*\) e do identificador do acessador \(*HACCESSOR*\) permitem que você especifique a região para gravação.  Normalmente, você escreve um único campo de dados de cada vez.  
  
 O método de `FlushData` grava dados no formato em que foi armazenado originalmente.  Se você não substitui essa função, o provedor funcionará corretamente mas as alterações não serão liberadas no repositório de dados.  
  
### Quando se liberar  
 Os modelos do provedor chamam `FlushData` sempre que os dados precisam ser gravados no repositório de dados; isso geralmente \(mas não sempre\) ocorre no resultado das chamadas às seguintes funções:  
  
-   **IRowsetChange::DeleteRows**  
  
-   **IRowsetChange::SetData**  
  
-   **IRowsetChange::InsertRows** \(se há novos dados a ser inserido na linha\)  
  
-   **IRowsetUpdate::Update**  
  
### Como funciona  
 O consumidor faz uma chamada que requer uma liberação \(como **Atualizar**\) e essa chamada é passado ao provedor, que sempre faz o seguinte:  
  
-   Chama `SetDBStatus` sempre que você tenha um valor de status associado \(consulte *referência de desenvolvedores do OLE DB*, capítulo 6, *Partes de dados: Status*\).  
  
-   Verifica sinalizadores de coluna.  
  
-   Chama `IsUpdateAllowed`.  
  
 Essas três etapas ajudam a fornecer segurança.  No provedor chamará `FlushData`.  
  
### Como implementar FlushData  
 Para implementar `FlushData`, você precisa levar em consideração vários problemas:  
  
-   Assegurando que o repositório de dados pode controlar as alterações.  
  
-   Valores de **nulo** de manipulação.  
  
-   Valores padrão de manipulação.  
  
 Para implementar seu próprio método de `FlushData` , você precisa:  
  
-   Vá para a sua classe do conjunto de linhas.  
  
-   No conjunto de linhas classe coloca a declaração de:  
  
```  
HRESULT FlushData(HROW, HACCESSOR)  
{  
    // Insert your implementation here and return an HRESULT.  
}  
```  
  
-   Fornecer uma implementação de `FlushData`.  
  
 Uma boa implementação de `FlushData` armazena apenas as linhas e as colunas que são atualizadas de fato.  Você pode usar os parâmetros *de HROW* e *de HACCESSOR* para determinar a linha e a coluna atuais que estão armazenadas para a otimização.  
  
 Normalmente, o desafio o maior estiver trabalhando com seu próprio repositório de dados nativo.  Se possível, tente:  
  
-   Manter o método de gravação ao seu repositório de dados tão simples quanto possível.  
  
-   Valores de **nulo** do identificador \(opcional mas recomendado\).  
  
-   Valores padrão do identificador \(opcional mas recomendado\).  
  
 É a melhor a fazer é ter valores reais especificados no repositório de dados para **nulo** e valores padrão.  É melhor se você puder extrapolar esses dados.  Caso contrário, é recomendado não permitir **nulo** e valores padrão.  
  
 O exemplo a seguir mostra como `FlushData` é implementado na classe de `RUpdateRowset` no exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) \(consulte Rowset.h no código de exemplo\):  
  
```  
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
  
### Controlando alterações  
 Para que o provedor trata alterações, você precisa verificar se seu repositório de dados \(como um arquivo de texto ou um arquivo de exibição\) tem as instalações que lhe permitem fazer alterações nele.  Se não fizer isso, você deve criar esse código separadamente do projeto do provedor.  
  
### Manipulando dados NULL  
 É possível que um usuário final enviará dados de **nulo** .  Quando você grava valores de **nulo** os campos na fonte de dados, pode haver problemas potenciais.  Imagine um aplicativo de tomada que aceita valores da cidade e o código postal; não pode aceitar um ou ambos os valores, mas não nesse caso, porque a entrega é impossível.  Você precisa como consequência restringir determinadas combinações de valores de **nulo** nos campos que fazem sentido para seu aplicativo.  
  
 Como desenvolvedor do provedor, você deve considerar como você armazenará os dados, como você leia os dados do repositório de dados, e de como você especifica ao usuário.  Especificamente, você deve considerar como alterar o status dos dados de dados na fonte de dados \(por exemplo, DataStatus \= **nulo**\) do conjunto de linhas.  Você decide o valor a ser retornado quando um consumidor acessa um campo que contém um valor de **nulo** .  
  
 Examine o código no exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) ; ilustra como um provedor pode manipular dados de **nulo** .  Em UpdatePV, o provedor armazena dados de **nulo** escrevendo a cadeia de caracteres “NULL” no repositório de dados.  Ao ler dados de **nulo** do repositório de dados, consulta essa cadeia de caracteres e vazias no buffer, criando uma cadeia de caracteres de **nulo** .  Também tem uma substituição de `IRowsetImpl::GetDBStatus` em que retorna **DBSTATUS\_S\_ISNULL** se o valor de dados está vazia.  
  
### Marcando colunas que permitem valor nulo  
 Se você também implementa conjuntos de linhas de esquema \(consulte `IDBSchemaRowsetImpl`\), sua implementação deverá especificar no conjunto de linhas de **DBSCHEMA\_COLUMNS** \(marcado normalmente no provedor por **C***xxx***SchemaColSchemaRowset**\) que a coluna é anulável.  
  
 Você também precisa especificar que todas as colunas que permitem valor nulo contém o valor de **DBCOLUMNFLAGS\_ISNULLABLE** na versão de `GetColumnInfo`.  
  
 Na implementação de modelos OLE DB, se você não marcar como colunas que permitem valor nulo, o provedor supõe que devem conter um valor e não permitirão que o consumidor o enviar valores nulos.  
  
 O exemplo a seguir mostra como a função de **CommonGetColInfo** é implementada em **CUpdateCommand** \(consulte UpProvRS.cpp\) em UpdatePV.  Observe que as colunas têm esse **DBCOLUMNFLAGS\_ISNULLABLE** para colunas que permitem valor nulo.  
  
```  
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
  
### Valores padrão  
 Como dados de **nulo** , você tem responsabilidade tratar alterar os valores padrão.  
  
 A opção de `FlushData` e de **Executar** é retornar `S_OK`.  Em virtude disso, se substituir essa função, as alterações parecem ter êxito \(`S_OK` será retornado\), mas não serão transmitidas ao repositório de dados.  
  
 No exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) \(em Rowset.h\), o método de `SetDBStatus` trata valores padrão como segue:  
  
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
  
### Sinalizadores de coluna  
 Se você aceita valores padrão nas colunas, você precisa defina\-o que usa metadados na classe de**\>SchemaRowset***da classe do provedor*de **\<**.  Definir o *m\_bColumnHasDefault* \= o `VARIANT_TRUE`.  
  
 Você também tem responsabilidade definir os sinalizadores de coluna, que são especificadas usando o tipo enumerado de **DBCOLUMNFLAGS** .  Os sinalizadores de coluna a seguir descrevem as características da coluna.  
  
 Por exemplo, na classe de `CUpdateSessionColSchemaRowset` em [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) \(em Session.h\), a primeira coluna é configurada esta forma:  
  
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
  
 Este código especifica, entre outros coisas, que a coluna suporta um valor padrão de 0, que é graváveis e, que todos os dados da coluna têm o mesmo tamanho.  Se você deseja que os dados em uma coluna para que o comprimento variável, não compraram esse sinalizador.  
  
## Consulte também  
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)