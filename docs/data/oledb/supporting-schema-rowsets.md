---
title: "Dando suporte a conjuntos de linhas do esquema | Microsoft Docs"
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
  - "Modelos de consumidor OLE DB, conjuntos de linhas do esquema"
  - "Provedores OLE DB, conjuntos de linhas do esquema"
  - "OLE DB, conjuntos de linhas do esquema"
  - "conjuntos de linhas do esquema"
ms.assetid: 71c5e14b-6e33-4502-a2d9-a1dc6d6e9ba0
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dando suporte a conjuntos de linhas do esquema
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os conjuntos de linhas de esquema permitem que os consumidores obtenham informações sobre um repositório de dados sem conhecer sua estrutura subjacente, ou o esquema.  Por exemplo, um repositório de dados pode não ter as tabelas organizadas em uma hierarquia definida pelo usuário, então será nenhuma forma de assegurar o conhecimento de esquema exceto ler. \(Como outro exemplo, observe que os assistentes do Visual C\+\+ usam conjuntos de linhas de esquema para gerar acessadores para o consumidor.\) Para permitir que o consumidor faça isso, as expõe métodos do objeto de sessão do provedor em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) a interface.  Em aplicativos do Visual C\+\+, você usa a classe de [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) para implementar **IDBSchemaRowset**.  
  
 `IDBSchemaRowsetImpl` oferece suporte aos seguintes métodos:  
  
-   [CheckRestrictions](../../data/oledb/idbschemarowsetimpl-checkrestrictions.md) verifica a validade das restrições em um conjunto de linhas de esquema.  
  
-   [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md) implementa uma função do designer do objeto COM para o objeto especificado pelo parâmetro do modelo.  
  
-   [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) especifica que as restrições você dão suporte em um conjunto de linhas de esquema específico.  
  
-   [IDBSchemaRowset::GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) retorna um conjunto de linhas de esquema \(herdado da interface\).  
  
-   [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) retorna uma lista de conjuntos de linhas de esquema acessíveis por `IDBSchemaRowsetImpl::GetRowset` \(herdado da interface\).  
  
## Suporte do assistente do provedor OLE DB de ATL  
 O assistente do provedor OLE DB de ATL cria três classes do esquema no arquivo de cabeçalho session:  
  
-   **C** *nome curto* **SessionTRSchemaRowset**  
  
-   **C** *nome curto* **SessionColSchemaRowset**  
  
-   **C** *nome curto* **SessionPTSchemaRowset**  
  
 Essas classes responde a solicitações de consumidor para informações de esquema; observe que a especificação do OLE DB requer que esses três conjuntos de linhas de esquema sejam com suporte:  
  
-   Trata solicitações de**C***nome curto*de**SessionTRSchemaRowset** para as informações da tabela \(o conjunto de linhas de esquema de `DBSCHEMA_TABLES` \).  
  
-   Trata solicitações de**C***nome curto*de**SessionColSchemaRowset** para informações de coluna \(o conjunto de linhas de esquema de **DBSCHEMA\_COLUMNS** \).  As implementações de exemplo do assistente para fontes dessas classes, que retornam informações de esquema para um provedor de OS.  
  
-   Trata solicitações de**C***nome curto*de**SessionPTSchemaRowset** para informações de esquema sobre o tipo de provedor \(o conjunto de linhas de esquema de **DBSCHEMA\_PROVIDER\_TYPES** \).  A implementação padrão fornecida pelo assistente retorna `S_OK`.  
  
 Você pode personalizar essas classes para manipular informações de esquema apropriado para seu provedor:  
  
-   Em **C***nome curto***SessionTRSchemaRowset**, você deve completar o catálogo, a tabela, e os campos de descrição \(**trData.m\_szType**, **trData.m\_szTable**, e **trData.m\_szDesc**\).  O exemplo script MDX usa somente uma linha \(tabela\).  Outros provedores podem retornar mais de uma tabela.  
  
-   Em **C***nome curto***SessionColSchemaRowset**, você passa o nome de tabela como **DBID**.  
  
## Limitações de configuração  
 Um conceito importante o suporte do conjunto de linhas de esquema está definindo restrições, que é feito usando `SetRestrictions`.  As restrições permitem que os consumidores busquem apenas linhas correspondentes \(por exemplo, para localizar todas as colunas na tabela “MyTable”\).  As restrições são opcionais e, nos casos em que não há suporte \(o padrão\), todos os dados são retornados.  Para obter um exemplo de um provedor que dê suporte a restrições, consulte o exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) .  
  
## Configurando o mapa de esquema  
 Configurar um mapa de esquema como neste Session.h em UpdatePV:  
  
```  
BEGIN_SCHEMA_MAP(CUpdateSession)  
    SCHEMA_ENTRY(DBSCHEMA_TABLES, CUpdateSessionTRSchemaRowset)  
    SCHEMA_ENTRY(DBSCHEMA_COLUMNS, CUpdateSessionColSchemaRowset)  
    SCHEMA_ENTRY(DBSCHEMA_PROVIDER_TYPES, CUpdateSessionPTSchemaRowset)  
END_SCHEMA_MAP()  
```  
  
 Para dar suporte a **IDBSchemaRowset**, você deve oferecer suporte `DBSCHEMA_TABLES`, **DBSCHEMA\_COLUMNS**, e **DBSCHEMA\_PROVIDER\_TYPES**.  Você pode adicionar conjuntos de linhas de esquema adicionais como desejar.  
  
 Declare uma classe do conjunto de linhas de esquema com um método de `Execute` como `CUpdateSessionTRSchemaRowset` em UpdatePV:  
  
```  
class CUpdateSessionTRSchemaRowset :   
    public CSchemaRowsetImpl < CUpdateSessionTRSchemaRowset,   
                              CTABLESRow, CUpdateSession >  
...  
// Execute looks like this; what pointers does the consumer use?  
    HRESULT Execute(DBROWCOUNT* pcRowsAffected,   
                    ULONG cRestrictions, const VARIANT* rgRestrictions)  
```  
  
 Observe que `CUpdateSession` herda de `IDBSchemaRowsetImpl`, assim que tem todos os métodos de manipulação de restrição.  Usando `CSchemaRowsetImpl`, declarar três classes filho \(listadas no mapa de esquema acima\): `CUpdateSessionTRSchemaRowset`, `CUpdateSessionColSchemaRowset`, e `CUpdateSessionPTSchemaRowset`.  Cada uma dessas classes filho tem um método de `Execute` que trata o conjunto respectivo de restrições \(critérios de pesquisa\).  Cada método de `Execute` compara os valores dos parâmetros de `cRestrictions` e de `rgRestrictions` .  Consulte a descrição desses parâmetros em [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).  
  
 Para obter mais informações sobre limitações do que correspondem a um conjunto de linhas de esquema específico, consulte a tabela de conjuntos de linhas de esquema GUIDs em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx)*na referência do programador do* OLE DB em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)].  
  
 Por exemplo, se você oferece suporte à restrição de **TABLE\_NAME** em `DBSCHEMA_TABLES`, proceda da seguinte forma:  
  
 Primeiro, pesquisar `DBSCHEMA_TABLES` e uma consulta que da suporte a quatro restrições \(em sequência\).  
  
|Limitação do conjunto de linhas de esquema|Valor da restrição|  
|------------------------------------------------|------------------------|  
|**TABLE\_CATALOG**|0x1 binário \(1\)|  
|**TABLE\_SCHEMA**|0x2 binário \(10\)|  
|**TABLE\_NAME**|0x4 binário \(100\)|  
|**TABLE\_TYPE**|0x8 binário \(1000\)|  
  
 Em seguida, observe que há um bit para cada restrição.  Como você quiser oferecer suporte somente **TABLE\_NAME** , você retornaria 0x4 no elemento de `rgRestrictions` .  Se você **TABLE\_CATALOG** suporte e **TABLE\_NAME**, você retornaria 0x5 binário \(101\).  
  
 Por padrão, a implementação retorna 0 \(não oferece suporte a nenhuma restrições\) para qualquer solicitação.  UpdatePV é um exemplo de um provedor que dê suporte a restrições.  
  
### Exemplo  
 Esse código é obtido do exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) .  UpdatePv oferece suporte a três conjuntos de linhas de esquema necessários: `DBSCHEMA_TABLES`, **DBSCHEMA\_COLUMNS**, e **DBSCHEMA\_PROVIDER\_TYPES**.  Como exemplo de como implementar o suporte do esquema do provedor, este tópico apresenta implementar o conjunto de linhas de **DBSCHEMA\_TABLE** .  
  
> [!NOTE]
>  O código de exemplo pode ser diferente do que é listado aqui; você deve considerar o código de exemplo como a versão mais atualizada.  
  
 A primeira etapa para adicionar suporte ao esquema é determinar restrições que você deve dar suporte.  Para determinar quais restrições estão disponíveis para o conjunto de linhas de esquema, verifique a especificação OLE DB para a definição de **IDBSchemaRowset**.  Depois da definição principal, você vê uma tabela que contém o nome do conjunto de linhas de esquema, o número de restrições, e as colunas de restrição.  Selecione o conjunto de linhas de esquema que você deseja dar suporte a e anote o número de restrições e de colunas de restrição.  Por exemplo, `DBSCHEMA_TABLES` suporte a quatro restrições \(**TABLE\_CATALOG**, **TABLE\_SCHEMA**, **TABLE\_NAME**, e **TABLE\_TYPE**\):  
  
```  
void SetRestrictions(ULONG cRestrictions, GUID* rguidSchema,   
   ULONG* rgRestrictions)  
{  
    for (ULONG l=0; l<cRestrictions; l++)  
    {  
        if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))  
            rgRestrictions[l] = 0x0C;  
        else if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_COLUMNS))  
                 rgRestrictions[l] = 0x04;  
             else if (InlineIsEqualGUID(rguidSchema[l],  
                                        DBSCHEMA_PROVIDER_TYPES))  
                      rgRestrictions[l] = 0x00;  
   }  
}  
```  
  
 Um bit representa cada coluna de restrição.  Se você quiser oferecer suporte a uma restrição \(isto é, você pode consultar por eles\), definir o bit a 1.  Se não desejar oferecer suporte a uma restrição, definir o bit como zero.  A linha de código acima, UpdatePV oferece suporte às restrições de **TABLE\_NAME** e de **TABLE\_TYPE** no conjunto de linhas de `DBSCHEMA_TABLES` .  Essas são as terceira máscara de bits \(100\) e a quarta máscara de bits \(1000\) restrições.  Consequentemente, a máscara de bits para UpdatePv é 1100 \(ou\): 0x0C  
  
```  
if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))  
    rgRestrictions[l] = 0x0C;  
```  
  
 A seguinte função de `Execute` é semelhante aos em conjuntos de linhas normais.  Você tem três argumentos: `pcRowsAffected`, `cRestrictions`, e `rgRestrictions`.  A variável de `pcRowsAffected` é um parâmetro de saída que o provedor pode retornar a contagem de linhas no conjunto de linhas de esquema.  O parâmetro de `cRestrictions` é um parâmetro de entrada que contém o número de restrições passadas pelo consumidor do provedor.  O parâmetro de `rgRestrictions` é uma matriz de valores de **VARIANT** que contêm os valores de restrição.  
  
```  
HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG cRestrictions,   
                const VARIANT* rgRestrictions)  
```  
  
 A variável de `cRestrictions` se baseia no número total de restrições para um conjunto de linhas de esquema, independentemente de se o provedor oferece suporte às.  Como UpdatePv oferece suporte a duas restrições \(o terceiro e quarto o\), esse código procura apenas um valor de `cRestrictions` maior ou igual a três.  
  
 O valor da restrição de **TABLE\_NAME** é armazenado em `rgRestrictions[2]` \(novamente, a terceira restrição em uma matriz baseada em zero é 2\).  Você precisa verifica se a restrição não é `VT_EMPTY` para suporte de fato.  Observe que **VT\_NULL** não é igual a `VT_EMPTY`.  **VT\_NULL** especifica um valor válido da restrição.  
  
 A definição de UpdatePv de um nome de tabela é um nome de caminho totalmente qualificado para um arquivo de texto.  Extrair o valor da restrição e tente abrir o arquivo para assegurar que o arquivo realmente existe.  Se o arquivo não existir, retornar `S_OK`.  Esse pode ser um bit para trás mas o que o código seja realmente o consumidor é dizendo que não havia nenhuma tabela com suporte pelo nome especificado.  O retorno de `S_OK` significa que o código executado corretamente.  
  
```  
USES_CONVERSION;  
enum {  
            sizeOfszFile = 255  
};  
CTABLESRow  trData;  
FILE        *pFile = NULL;  
TCHAR       szFile[ sizeOfszFile ];  
errcode     err = 0;  
  
// Handle any restrictions sent to us. This only handles  
// the TABLE_NAME & TABLE_TYPE restictions (the 3rd and 4th   
// restrictions in DBSCHEMA_TABLES...look in IDBSchemaRowsets   
// in part 2 of the prog. ref) so your restrictions are 0x08 & 0x04   
// for a total of (0x0C)  
if (cRestrictions >= 3 && rgRestrictions[2].vt != VT_EMPTY)  
{  
    CComBSTR bstrName = rgRestrictions[2].bstrVal;  
    if ((rgRestrictions[2].vt == VT_BSTR) && (bstrName != (BSTR)NULL))  
    {  
        // Check to see if the file exists  
        _tcscpy_s(&szFile[0], sizeOfszFile, OLE2T(bstrName));  
        if (szFile[0] == _T('\0') ||   
           ((err = _tfopen(&pFile, &szFile[0], _T("r"))) == 0))  
        {  
            return S_OK;// Their restriction was invalid return no data  
        }  
        else  
        {  
            fclose(pFile);  
        }  
    }  
}  
```  
  
 Oferecer suporte a quarta restrição \(**TABLE\_TYPE**\) é semelhante à terceira restrição.  Verifique que o valor não é `VT_EMPTY`.  Essa restrição retorna somente o tipo de tabela, **TABELA**.  Para determinar os valores válidos para `DBSCHEMA_TABLES`, procure no apêndice B *de referência do programador de OLE* DB na seção do conjunto de linhas de **TABELAS** .  
  
```  
// TABLE_TYPE restriction:  
if (cRestrictions >=4 && rgRestrictions[3].vt != VT_EMPTY)  
{  
    CComBSTR bstrType = rgRestrictions[3].bstrVal;  
    if ((rgRestrictions[3].vt == VT_BSTR) && (bstrType != (BSTR)NULL))  
    {  
        // This is kind of a blind restriction.  
        // This only actually supports  
        // TABLES so if you get anything else,   
        // just return an empty rowset.  
        if (_tcscmp(_T("TABLE"), OLE2T(bstrType)) != 0)  
            return S_OK;  
    }  
}  
```  
  
 É aí que você realmente cria uma entrada de linha para o conjunto de linhas.  `trData` variável corresponde a **CTABLESRow**, uma estrutura definida em modelos do provedor OLE DB.  **CTABLESRow** corresponde à definição do conjunto de linhas de **TABELAS** no apêndice B da especificação OLE DB.  Você tem apenas uma linha a ser adicionado como você só pode oferecer suporte a uma tabela de cada vez.  
  
```  
// Bring over the data:  
wcspy_s(trData.m_szType, OLESTR("TABLE"), 5);  
wcspy_s(trData.m_szDesc, OLESTR("The Directory Table"), 19);  
wcsncpy_s(trData.m_szTable, T2OLE(szFile), _TRUNCATE());  
```  
  
 UpdatePV define apenas três colunas: **TABLE\_NAME**, **TABLE\_TYPE**, e **DESCRIÇÃO**.  Você deve anote as colunas para as quais você retorna informações, porque você precisa essas informações quando você implementa `GetDBStatus`:  
  
```  
    _ATLTRY  
    {  
        m_rgRowData.Add(trData);  
    }  
    _ATLCATCHALL()  
    {  
        return E_OUTOFMEMORY;  
    }  
    //if (!m_rgRowData.Add(trData))  
    //    return E_OUTOFMEMORY;  
    *pcRowsAffected = 1;  
    return S_OK;  
}  
```  
  
 A função de `GetDBStatus` é muito importante para a operação correta do conjunto de linhas de esquema.  Como você não retorna dados para cada coluna no conjunto de linhas de **TABELAS** , você precisa especificar que as colunas que retornam dados para e que não faz.  
  
```  
virtual DBSTATUS GetDBStatus(CSimpleRow* , ATLCOLUMNINFO* pColInfo)  
{  
    ATLASSERT(pColInfo != NULL);  
  
    switch(pColInfo->iOrdinal)  
    {  
    case 3:     // TABLE_NAME  
    case 4:     // TABLE_TYPE  
    case 6:     // DESCRIPTION  
        return DBSTATUS_S_OK;  
        break;  
    default:  
        return DBSTATUS_S_ISNULL;  
    break;  
    }  
}  
```  
  
 Como sua função de `Execute` retorna dados para **TABLE\_NAME**, **TABLE\_TYPE**, e campos de **DESCRIÇÃO** do conjunto de linhas de **TABELAS** , você pode examinar no apêndice B da especificação OLE DB e determinar \(contando de cima para baixo\) que são os ordinais 3, 4 e 6.  Para cada uma dessas colunas, **DBSTATUS\_S\_OK**de retorno.  Para todas as outras colunas, **DBSTATUS\_S\_ISNULL**de retorno.  É importante retornar esse status, como um consumidor não pode entender o valor que você retorna é **nulo** ou algo mais.  Além disso, observe que **nulo** não é equivalente vazio.  
  
 Para obter mais informações sobre a interface do conjunto de linhas de esquema OLE DB, consulte a interface de [IDBSchemaRowset](../../data/oledb/idbschemarowsetimpl-class.md) na referência do programador de OLE DB.  
  
 Para obter informações sobre como os consumidores podem usar métodos de **IDBSchemaRowset** , consulte [Obtendo metadados com conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md).  
  
 Para obter um exemplo de um provedor que dê suporte a conjuntos de linhas de esquema, consulte o exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) .  
  
## Consulte também  
 [Técnicas de provedor avançadas](../Topic/Advanced%20Provider%20Techniques.md)