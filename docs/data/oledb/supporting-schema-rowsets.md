---
title: Dando suporte a conjuntos de linhas do esquema
ms.date: 11/04/2016
helpviewer_keywords:
- schema rowsets
- OLE DB consumer templates, schema rowsets
- OLE DB providers, schema rowsets
- OLE DB, schema rowsets
ms.assetid: 71c5e14b-6e33-4502-a2d9-a1dc6d6e9ba0
ms.openlocfilehash: f8c96021b93a35ae9fd10503e78401bbac8abeb7
ms.sourcegitcommit: 943c792fdabf01c98c31465f23949a829eab9aad
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2018
ms.locfileid: "51264886"
---
# <a name="supporting-schema-rowsets"></a>Dando suporte a conjuntos de linhas do esquema

Conjuntos de linhas de esquema permitem que os consumidores obter informações sobre um armazenamento de dados sem saber sua estrutura subjacente ou o esquema. Por exemplo, um armazenamento de dados pode ter tabelas organizadas em uma hierarquia definida pelo usuário, portanto, não haveria nenhuma maneira de garantir o conhecimento do esquema, exceto por leitura. (Como outro exemplo, os assistentes do Visual C++ usam conjuntos de linhas de esquema para gerar acessadores para o consumidor.) Para permitir que o consumidor fazer isso, o objeto de sessão do provedor expõe métodos sobre o [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686) interface. Em aplicativos do Visual C++, você deve usar o [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) classe para implementar `IDBSchemaRowset`.

`IDBSchemaRowsetImpl` dá suporte aos seguintes métodos:

- [CheckRestrictions](../../data/oledb/idbschemarowsetimpl-checkrestrictions.md) verifica a validade de restrições em relação a um conjunto de linhas de esquema.

- [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md) implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.

- [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) Especifica quais restrições você oferece suporte em um conjunto de linhas de esquema específico.

- [IDBSchemaRowset:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) retorna um conjunto de linhas de esquema (herdado de interface).

- [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) retorna uma lista de conjuntos de linhas de esquema acessível pelo `IDBSchemaRowsetImpl::GetRowset` (herdado de interface).

## <a name="atl-ole-db-provider-wizard-support"></a>Suporte do Assistente de provedor ATL OLE DB

O **ATL OLE DB Provider Wizard** cria três classes de esquema no arquivo de cabeçalho de sessão:

- **C**<em>ShortName</em>**SessionTRSchemaRowset**

- **C**<em>ShortName</em>**SessionColSchemaRowset**

- **C**<em>ShortName</em>**SessionPTSchemaRowset**

Essas classes respondem às solicitações do consumidor de informações de esquema; Observe que a especificação OLE DB exige que esses conjuntos de linhas de três esquema suporte:

- **C**<em>ShortName</em>**SessionTRSchemaRowset** trata as solicitações de informações da tabela (as linhas de esquema DBSCHEMA_TABLES).

- **C**<em>ShortName</em>**SessionColSchemaRowset** trata as solicitações de informações de coluna (as linhas de esquema DBSCHEMA_COLUMNS). O assistente fornece exemplos de implementações para essas classes, que retornam informações de esquema para um provedor DOS.

- **C**<em>ShortName</em>**SessionPTSchemaRowset** trata as solicitações de informações de esquema sobre o tipo de provedor (o esquema de linhas DBSCHEMA_PROVIDER_TYPES). A implementação padrão fornecida pelo assistente retornará S_OK.

Você pode personalizar essas classes para manipular informações de esquema apropriadas para seu provedor:

- Na **C**<em>ShortName</em>**SessionTRSchemaRowset**, você deve preencher os campos de descrição, tabela e catálogo (`trData.m_szType`, `trData.m_szTable`e `trData.m_szDesc`). O exemplo gerado pelo assistente usa apenas uma linha (tabela). Outros provedores podem retornar mais de uma tabela.

- Na **C**<em>ShortName</em>**SessionColSchemaRowset**, você passa o nome da tabela como um `DBID`.

## <a name="setting-restrictions"></a>Restrições de configuração

Um conceito importante no suporte do conjunto de linhas de esquema é a configuração restrições, você pode fazer usando `SetRestrictions`. As restrições permitem que os consumidores buscar somente as linhas correspondentes (por exemplo, localizar todas as colunas na tabela "MyTable"). As restrições são opcionais e, no caso em que nenhum têm suporte (o padrão), todos os dados são sempre retornadas. Para obter um exemplo de um provedor que dá suporte a restrições, consulte o [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) exemplo.

## <a name="setting-up-the-schema-map"></a>Como configurar o mapa de esquema

Configure um mapa de esquema como este Session.h em UpdatePV:

```cpp
BEGIN_SCHEMA_MAP(CUpdateSession)
    SCHEMA_ENTRY(DBSCHEMA_TABLES, CUpdateSessionTRSchemaRowset)
    SCHEMA_ENTRY(DBSCHEMA_COLUMNS, CUpdateSessionColSchemaRowset)
    SCHEMA_ENTRY(DBSCHEMA_PROVIDER_TYPES, CUpdateSessionPTSchemaRowset)
END_SCHEMA_MAP()
```

Para dar suporte a `IDBSchemaRowset`, você deve dar suporte a DBSCHEMA_TABLES, DBSCHEMA_COLUMNS e DBSCHEMA_PROVIDER_TYPES. Você pode adicionar conjuntos de linhas de esquema adicionais a seu critério.

Declarar uma classe de conjunto de linhas de esquema com um `Execute` método, como `CUpdateSessionTRSchemaRowset` em `UpdatePV`:

```cpp
class CUpdateSessionTRSchemaRowset :
    public CSchemaRowsetImpl < CUpdateSessionTRSchemaRowset,
                              CTABLESRow, CUpdateSession >
...
// Execute looks like this; what pointers does the consumer use?
    HRESULT Execute(DBROWCOUNT* pcRowsAffected,
                    ULONG cRestrictions, const VARIANT* rgRestrictions)
```

`CUpdateSession` herda de `IDBSchemaRowsetImpl`, portanto, ele tem todas as a restrição de métodos de manipulação. Usando o `CSchemaRowsetImpl`, declare as três classes filho (listadas no mapa de esquema acima): `CUpdateSessionTRSchemaRowset`, `CUpdateSessionColSchemaRowset`, e `CUpdateSessionPTSchemaRowset`. Cada uma dessas classes filho tem um `Execute` método que manipula seu respectivo conjunto de restrições (critérios de pesquisa). Cada `Execute` método compara os valores da *cRestrictions* e *rgRestrictions* parâmetros. Consulte a descrição desses parâmetros na [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).

Para obter mais informações sobre quais restrições correspondem a um conjunto de linhas de esquema específico, consulte a tabela de GUIDs do conjunto de linhas de esquema no [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686) na **referência do programador DB OLE** no SDK do Windows .

Por exemplo, se você compatível com a restrição TABLE_NAME DBSCHEMA_TABLES, você faria o seguinte:

Primeiro, pesquisar DBSCHEMA_TABLES e veja que ele oferece suporte a restrições de quatro (em ordem).

|Restrição de conjunto de linhas de esquema|Valor de restrição|
|-------------------------------|-----------------------|
|TABLE_CATALOG|0x1 (binário 1)|
|TABLE_SCHEMA|0x2 (10 binário)|
|TABLE_NAME|0x4 (100 binário)|
|TABLE_TYPE|0x8 (1000 binário)|

Em seguida, há um bit para cada restrição. Como você deseja dar suporte apenas a TABLE_NAME, retornaria 0x4 no `rgRestrictions` elemento. Se você tiver suporte TABLE_CATALOG e TABLE_NAME, retornaria 0x5 (101 binário).

Por padrão, a implementação retorna 0 (não dá suporte a quaisquer restrições) para qualquer solicitação. UpdatePV é um exemplo de um provedor que dá suporte a restrições.

### <a name="example"></a>Exemplo

Esse código é retirado do [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) exemplo. `UpdatePv` dá suporte a três conjuntos de linhas de esquema obrigatório: DBSCHEMA_TABLES, DBSCHEMA_COLUMNS e DBSCHEMA_PROVIDER_TYPES. Como um exemplo de como implementar o suporte a esquema no seu provedor, este tópico apresenta Implementando o conjunto de linhas DBSCHEMA_TABLE.

> [!NOTE]
> O código de exemplo pode ser diferente daquele que está listado aqui. Você deve considerar o código de exemplo como a versão mais recente.

É a primeira etapa na adição de suporte de esquema determinar quais restrições você pretende dar suporte. Para determinar quais restrições estão disponíveis para seu conjunto de linhas de esquema, veja a especificação OLE DB para a definição de `IDBSchemaRowset`. Após a definição principal, você deve ver uma tabela que contém o nome do conjunto de linhas de esquema, o número de restrições e colunas de restrição. Selecione o conjunto de linhas de esquema que você deseja dar suporte e anote o número de restrições e colunas de restrição. Por exemplo, o DBSCHEMA_TABLES dá suporte a quatro restrições (TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME e TABLE_TYPE):

```cpp
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

Um bit representa cada coluna de restrição. Se você quiser dar suporte a uma restrição (ou seja, você pode consultar por ele), definir esse bit como 1. Se você não quiser para dar suporte a uma restrição, defina esse bit como zero. Da linha de código acima, `UpdatePV` dá suporte as restrições TABLE_NAME e TABLE_TYPE no conjunto de linhas DBSCHEMA_TABLES. Esses são o terceiro (máscara de bits 100) e o quartas restrições de (máscara de bits 1000). Portanto, a máscara de bits para `UpdatePv` é 1100 (ou 0x0C):

```cpp
if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))
    rgRestrictions[l] = 0x0C;
```

O seguinte `Execute` função é semelhante em conjuntos de linhas regulares. Você tem três argumentos: *pcRowsAffected*, *cRestrictions*, e *rgRestrictions*. O *pcRowsAffected* variável é um parâmetro de saída que o provedor pode retornar a contagem de linhas no conjunto de linhas de esquema. O *cRestrictions* parâmetro é um parâmetro de entrada que contém o número de restrições passada pelo consumidor para o provedor. O *rgRestrictions* parâmetro é uma matriz de valores de VARIANTE que mantêm os valores de restrição.

```cpp
HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG cRestrictions,
                const VARIANT* rgRestrictions)
```

O *cRestrictions* variável é baseada no número total de restrições para um conjunto de linhas de esquema, independentemente se o provedor oferece suporte a eles. Como UpdatePv oferece suporte a duas restrições (a terceira e quarta), esse código procura apenas por um *cRestrictions* valor maior que ou igual a três.

O valor para a restrição TABLE_NAME é armazenado no *rgRestrictions [2]* (novamente, a terceira restrição em uma matriz de base zero é 2). Verifique que a restrição não VT_EMPTY realmente dar suporte a ela. Observe que VT_NULL não é igual a VT_EMPTY. VT_NULL Especifica um valor de restrição válida.

O `UpdatePv` definição de um nome de tabela é um nome de caminho totalmente qualificado para um arquivo de texto. Extraia o valor de restrição e, em seguida, tente abrir o arquivo para garantir que o arquivo, na verdade, existe. Se o arquivo não existir, retorne S_OK. Isso pode parecer um pouco para trás, mas o código que realmente está informando o consumidor é que não havia nenhuma tabela com suporte pelo nome especificado. O retorno S_OK significa que o código seja executado corretamente.

```cpp
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

Dar suporte a restrição de quarto (TABLE_TYPE) é semelhante a restrição de terceiro. Verifique se o valor não é VT_EMPTY. Essa restrição só retorna o tipo de tabela, a tabela. Para determinar os valores válidos para o DBSCHEMA_TABLES, examine **Apêndice B** da **referência do programador DB OLE** na seção de conjunto de linhas de tabelas.

```cpp
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

Isso é onde você realmente criar uma entrada de linha para o conjunto de linhas. A variável `trData` corresponde à `CTABLESRow`, uma estrutura definida nos modelos de provedor do OLE DB. `CTABLESRow` corresponde à definição de conjunto de linhas de tabelas no **Apêndice B** da especificação do OLE DB. Você tem apenas uma linha para adicionar o porque você pode apenas dá suporte a uma tabela por vez.

```cpp
// Bring over the data:
wcspy_s(trData.m_szType, OLESTR("TABLE"), 5);

wcspy_s(trData.m_szDesc, OLESTR("The Directory Table"), 19);

wcsncpy_s(trData.m_szTable, T2OLE(szFile), _TRUNCATE());
```

`UpdatePV` Define somente três colunas: TABLE_NAME, TABLE_TYPE e descrição. Tome nota das colunas para as quais você retornar informações, pois você precisará dessas informações quando você implementa `GetDBStatus`:

```cpp
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

O `GetDBStatus` função é importante para a operação correta do conjunto de linhas de esquema. Porque você não retorna dados para cada coluna no conjunto de linhas de tabelas, você precisa especificar quais colunas devem retornar dados para e o que você não fizer isso.

```cpp
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

Porque seu `Execute` função retorna dados para os campos TABLE_NAME, TABLE_TYPE e a descrição do conjunto de linhas de tabelas, você pode examinar **Apêndice B** da especificação do OLE DB e determinar (pela contagem de cima para baixo) que elas ordinais 3, 4 e 6. Para cada uma dessas colunas, retorne DBSTATUS_S_OK. Para todas as outras colunas, retorne DBSTATUS_S_ISNULL. É importante retornar esse status, porque um consumidor talvez não compreenda o valor que você retornar é nulo ou alguma outra coisa. Novamente, observe que NULL não é equivalente a vazio.

Para obter mais informações sobre a interface de conjunto de linhas de esquema OLE DB, consulte a [IDBSchemaRowset](../../data/oledb/idbschemarowsetimpl-class.md) interface na **referência do programador DB OLE**.

Para obter informações sobre como os consumidores podem utilizar `IDBSchemaRowset` métodos, consulte [obtendo metadados com conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md).

Para obter um exemplo de um provedor que dá suporte a conjuntos de linhas de esquema, consulte o [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) exemplo.

## <a name="see-also"></a>Consulte também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)
