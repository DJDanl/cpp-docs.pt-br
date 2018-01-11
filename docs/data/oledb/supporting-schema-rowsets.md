---
title: Suporte a conjuntos de linhas de esquema | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- schema rowsets
- OLE DB consumer templates, schema rowsets
- OLE DB providers, schema rowsets
- OLE DB, schema rowsets
ms.assetid: 71c5e14b-6e33-4502-a2d9-a1dc6d6e9ba0
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b981af06f48834eef59103b872b8b07e75cd0065
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="supporting-schema-rowsets"></a>Dando suporte a conjuntos de linhas do esquema
Conjuntos de linhas de esquema permitem que os consumidores obter informações sobre um repositório de dados sem conhecer sua estrutura subjacente ou esquema. Por exemplo, um repositório de dados pode ter tabelas organizadas em uma hierarquia definida pelo usuário, portanto, não haveria nenhuma maneira de garantir o conhecimento sobre o esquema, exceto por leitura. (Como outro exemplo, observe que os assistentes do Visual C++ usam conjuntos de linhas de esquema para gerar acessadores para o consumidor.) Para permitir que o consumidor fazer isso, o objeto de sessão do provedor expõe métodos no [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) interface. Em aplicativos do Visual C++, você deve usar o [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) classe para implementar **IDBSchemaRowset**.  
  
 `IDBSchemaRowsetImpl`dá suporte aos seguintes métodos:  
  
-   [CheckRestrictions](../../data/oledb/idbschemarowsetimpl-checkrestrictions.md) verifica a validade de restrições em relação a um conjunto de linhas de esquema.  
  
-   [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md) implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.  
  
-   [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) Especifica as restrições de suporte em um conjunto de linhas de esquema específico.  
  
-   [IDBSchemaRowset:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) retorna um conjunto de linhas de esquema (herdado de interface).  
  
-   [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) retorna uma lista de conjuntos de linhas de esquema acessível por `IDBSchemaRowsetImpl::GetRowset` (herdado de interface).  
  
## <a name="atl-ole-db-provider-wizard-support"></a>Suporte do Assistente de provedor ATL OLE DB  
 O OLE DB Provider assistente ATL cria três classes de esquema no arquivo de cabeçalho de sessão:  
  
-   **C** *ShortName* **SessionTRSchemaRowset**  
  
-   **C** *ShortName* **SessionColSchemaRowset**  
  
-   **C** *ShortName* **SessionPTSchemaRowset**  
  
 Essas classes respondem às solicitações do consumidor de informações de esquema; Observe que a especificação OLE DB requer que esses conjuntos de linhas de três esquema suporte:  
  
-   **C** *ShortName* **SessionTRSchemaRowset** lida com solicitações de informações da tabela (o `DBSCHEMA_TABLES` de linhas de esquema).  
  
-   **C** *ShortName* **SessionColSchemaRowset** trata solicitações para obter informações de coluna (o **DBSCHEMA_COLUMNS** linhas de esquema). O assistente fornece exemplos de implementações para essas classes, que retornam informações de esquema para um provedor DOS.  
  
-   **C** *ShortName* **SessionPTSchemaRowset** trata solicitações para obter informações de esquema sobre o tipo de provedor (o **DBSCHEMA_PROVIDER_TYPES** linhas de esquema). Retorna a implementação padrão fornecida pelo Assistente de `S_OK`.  
  
 Você pode personalizar essas classes para lidar com informações sobre o esquema apropriado para seu provedor:  
  
-   Em **C***ShortName***SessionTRSchemaRowset**, você deve preencher os campos de descrição de catálogo e tabela (**trData.m_szType**, **trData.m_szTable**, e **trData.m_szDesc**). O exemplo geradas pelo assistente usa apenas uma linha (tabela). Outros provedores podem retornar mais de uma tabela.  
  
-   Em **C***ShortName***SessionColSchemaRowset**, passe o nome da tabela como um **DBID**.  
  
## <a name="setting-restrictions"></a>Restrições de configuração  
 Um conceito importante no suporte do conjunto de linhas de esquema é definir restrições, que deverá ser feito usando `SetRestrictions`. Restrições permitem que os consumidores de busca somente as linhas correspondentes (por exemplo, localize todas as colunas na tabela "MyTable"). Restrições são opcionais e, no caso em que nenhum têm suporte (o padrão), todos os dados sempre é retornado. Para obter um exemplo de um provedor que dá suporte a restrições, consulte o [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) exemplo.  
  
## <a name="setting-up-the-schema-map"></a>Configurando o mapa de esquema  
 Configure um mapa de esquema como esse Session.h em UpdatePV:  
  
```  
BEGIN_SCHEMA_MAP(CUpdateSession)  
    SCHEMA_ENTRY(DBSCHEMA_TABLES, CUpdateSessionTRSchemaRowset)  
    SCHEMA_ENTRY(DBSCHEMA_COLUMNS, CUpdateSessionColSchemaRowset)  
    SCHEMA_ENTRY(DBSCHEMA_PROVIDER_TYPES, CUpdateSessionPTSchemaRowset)  
END_SCHEMA_MAP()  
```  
  
 Para dar suporte a **IDBSchemaRowset**, você deve dar suporte `DBSCHEMA_TABLES`, **DBSCHEMA_COLUMNS**, e **DBSCHEMA_PROVIDER_TYPES**. Você pode adicionar conjuntos de linhas de esquema adicionais a seu critério.  
  
 Declarar uma classe de conjunto de linhas de esquema com um `Execute` método como `CUpdateSessionTRSchemaRowset` em UpdatePV:  
  
```  
class CUpdateSessionTRSchemaRowset :   
    public CSchemaRowsetImpl < CUpdateSessionTRSchemaRowset,   
                              CTABLESRow, CUpdateSession >  
...  
// Execute looks like this; what pointers does the consumer use?  
    HRESULT Execute(DBROWCOUNT* pcRowsAffected,   
                    ULONG cRestrictions, const VARIANT* rgRestrictions)  
```  
  
 Observe que `CUpdateSession` herda de `IDBSchemaRowsetImpl`; portanto, tem restrição métodos de manipulação. Usando `CSchemaRowsetImpl`, declare três classes filhas (listados no mapa de esquema acima): `CUpdateSessionTRSchemaRowset`, `CUpdateSessionColSchemaRowset`, e `CUpdateSessionPTSchemaRowset`. Cada uma dessas classes filho tem um `Execute` método que trata seu respectivo conjunto de restrições (critérios de pesquisa). Cada `Execute` método compara os valores de `cRestrictions` e `rgRestrictions` parâmetros. Consulte a descrição desses parâmetros no [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).  
  
 Para obter mais informações sobre quais restrições correspondem a um conjunto de linhas de esquema específico, consulte a tabela de linhas de esquema GUIDs em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no SDK do Windows.  
  
 Por exemplo, se você tem suporte a **TABLE_NAME** restrição `DBSCHEMA_TABLES`, você deve fazer o seguinte:  
  
 Primeiro, pesquisar `DBSCHEMA_TABLES` e ele oferece suporte a quatro restrições (em ordem).  
  
|Restrição de conjunto de linhas de esquema|Valor de restrição|  
|-------------------------------|-----------------------|  
|**TABLE_CATALOG**|0x1 (binário 1)|  
|**TABLE_SCHEMA**|0x2 (binário 10)|  
|**TABLE_NAME**|0x4 (binário 100)|  
|**TABLE_TYPE**|0x8 (binário 1000)|  
  
 Em seguida, observe que há um bit para cada restrição. Como você deseja dar suporte **TABLE_NAME** somente retornaria 0x4 no `rgRestrictions` elemento. Se você tem suporte **TABLE_CATALOG** e **TABLE_NAME**, retornaria 0x5 (101 binário).  
  
 Por padrão, a implementação retorna 0 (não dá suporte a todas as restrições) para qualquer solicitação. UpdatePV é um exemplo de um provedor que dá suporte a restrições.  
  
### <a name="example"></a>Exemplo  
 Esse código é obtido a [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) exemplo. UpdatePv oferece suporte os três conjuntos de linhas de esquema obrigatório: `DBSCHEMA_TABLES`, **DBSCHEMA_COLUMNS**, e **DBSCHEMA_PROVIDER_TYPES**. Como um exemplo de como implementar o suporte do esquema no seu provedor, este tópico apresenta a implementação de **DBSCHEMA_TABLE** conjunto de linhas.  
  
> [!NOTE]
>  O código de exemplo pode ser diferente do que está listado aqui. Você deve considerar o código de exemplo como a versão mais atualizada.  
  
 É a primeira etapa na adição de suporte de esquema determinar quais restrições que você pretende dar suporte. Para determinar quais restrições estão disponíveis para o conjunto de linhas de esquema, consulte a especificação OLE DB para a definição de **IDBSchemaRowset**. Após a definição principal, você vê uma tabela que contém o nome do conjunto de linhas de esquema, o número de restrições e as colunas de restrição. Selecione o conjunto de linhas de esquema que você deseja dar suporte e anote o número de restrições e colunas de restrição. Por exemplo, `DBSCHEMA_TABLES` dá suporte a quatro restrições (**TABLE_CATALOG**, **TABLE_SCHEMA**, **TABLE_NAME**, e **TABLE_TYPE** ):  
  
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
  
 Um bit representa cada coluna de restrição. Se você deseja dar suporte a uma restrição (ou seja, você pode consultar por ele), definir esse bit para 1. Se você não deseja dar suporte a uma restrição, defina esse bit para zero. Na linha de código acima, UpdatePV oferece suporte a **TABLE_NAME** e **TABLE_TYPE** restrições o `DBSCHEMA_TABLES` conjunto de linhas. Essas são as restrições de (máscara de bits 1000) quarta e o terceiro (máscara de bits 100). Portanto, a máscara de bits para UpdatePv é 1100 (ou 0x0C):  
  
```  
if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))  
    rgRestrictions[l] = 0x0C;  
```  
  
 O seguinte `Execute` função é semelhante aos conjuntos de linhas normais. Você tem três argumentos: `pcRowsAffected`, `cRestrictions`, e `rgRestrictions`. O `pcRowsAffected` variável é um parâmetro de saída que o provedor pode retornar a contagem de linhas no conjunto de linhas de esquema. O `cRestrictions` parâmetro é um parâmetro de entrada que contém o número de restrições passada pelo consumidor para o provedor. O `rgRestrictions` parâmetro é uma matriz de **VARIANT** valores que contêm os valores de restrição.  
  
```  
HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG cRestrictions,   
                const VARIANT* rgRestrictions)  
```  
  
 O `cRestrictions` variável baseia-se no número total de restrições para um conjunto de linhas de esquema, independentemente se o provedor oferece suporte a eles. Como UpdatePv oferece suporte a duas restrições (o terceiro e quarto), esse código procura somente um `cRestrictions` valor maior que ou igual a 3.  
  
 O valor para o **TABLE_NAME** restrição é armazenada no `rgRestrictions[2]` (novamente, a terceira restrição em uma matriz com base em zero é 2). Você precisa verificar se a restrição não é `VT_EMPTY` para realmente suportá-lo. Observe que **VT_NULL** não é igual a `VT_EMPTY`. **VT_NULL** Especifica um valor de restrição válida.  
  
 A definição de UpdatePv de um nome de tabela é um nome de caminho totalmente qualificado para um arquivo de texto. Extrair o valor de restrição e, em seguida, tentar abrir o arquivo para garantir que o arquivo existe de verdade. Se o arquivo não existir, retornar `S_OK`. Isso pode parecer um pouco com versões anteriores, mas o código que realmente está informando o consumidor é que não houve nenhuma tabela com suporte pelo nome especificado. O `S_OK` retorno significa que o código seja executado corretamente.  
  
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
  
 Suporte a restrição quarta (**TABLE_TYPE**) é semelhante para a restrição de terceira. Verifique se o valor não é `VT_EMPTY`. Essa restrição só retorna o tipo de tabela, **tabela**. Para determinar os valores válidos para o `DBSCHEMA_TABLES`, procure no Apêndice B do *referência do programador de DB OLE* no **tabelas** seção de conjunto de linhas.  
  
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
  
 Isso é onde você realmente cria uma entrada de linha para o conjunto de linhas. A variável `trData` corresponde à **CTABLESRow**, uma estrutura definida nos modelos de provedor do OLE DB. **CTABLESRow** corresponde do **tabelas** definição de conjunto de linhas no Apêndice B da especificação OLE DB. Você tem apenas uma linha para adicionar porque você suporta apenas uma tabela por vez.  
  
```  
// Bring over the data:  
wcspy_s(trData.m_szType, OLESTR("TABLE"), 5);  
wcspy_s(trData.m_szDesc, OLESTR("The Directory Table"), 19);  
wcsncpy_s(trData.m_szTable, T2OLE(szFile), _TRUNCATE());  
```  
  
 UpdatePV define apenas três colunas: **TABLE_NAME**, **TABLE_TYPE**, e **descrição**. Você deve fazer uma nota das colunas para o qual retornar informações, pois você precisará dessas informações quando você implementa `GetDBStatus`:  
  
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
  
 O `GetDBStatus` função é muito importante para o funcionamento correto do conjunto de linhas de esquema. Porque você não retorna dados para cada coluna de **tabelas** conjunto de linhas, você precisa especificar quais colunas devem retornar dados para e que você não fizer isso.  
  
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
  
 Porque o `Execute` função retorna dados para o **TABLE_NAME**, **TABLE_TYPE**, e **descrição** os campos do **tabelas**conjunto de linhas, você pode pesquisar no Apêndice B da especificação OLE DB e determinar (pela contagem de cima para baixo) que são números ordinais 3, 4 e 6. Para cada uma dessas colunas, retornar **DBSTATUS_S_OK**. Para todas as outras colunas, retornar **DBSTATUS_S_ISNULL**. É importante retornar a este status, porque um consumidor talvez não compreenda o que é o valor que você retornar **nulo** ou algo mais. Observe que, novamente, **nulo** não é equivalente ao vazio.  
  
 Para obter mais informações sobre a interface de conjunto de linhas de esquema OLE DB, consulte o [IDBSchemaRowset](../../data/oledb/idbschemarowsetimpl-class.md) interface OLE DB do programador de referência.  
  
 Para obter informações sobre como usar os consumidores **IDBSchemaRowset** métodos, consulte [obtendo metadados com conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md).  
  
 Para obter um exemplo de um provedor que dá suporte a conjuntos de linhas de esquema, consulte o [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) exemplo.  
  
## <a name="see-also"></a>Consulte também  
 [Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)