---
title: Dando suporte a conjuntos de linhas do esquema
ms.date: 11/04/2016
helpviewer_keywords:
- schema rowsets
- OLE DB consumer templates, schema rowsets
- OLE DB providers, schema rowsets
- OLE DB, schema rowsets
ms.assetid: 71c5e14b-6e33-4502-a2d9-a1dc6d6e9ba0
ms.openlocfilehash: 1ad1a91e8a79238eee773d92a756b0238e8901d5
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707497"
---
# <a name="supporting-schema-rowsets"></a>Dando suporte a conjuntos de linhas do esquema

Os conjuntos de linhas do esquema permitem aos consumidores obter informações sobre um armazenamento de dados sem conhecer sua estrutura subjacente, ou esquema. Por exemplo, um armazenamento de dados pode ter tabelas organizadas em uma hierarquia definida pelo usuário. Desse modo, não há como garantir o conhecimento do esquema, a não ser lendo ele. (Um outro exemplo são os assistentes do Visual C++ que usam conjuntos de linhas do esquema de modo a gerar acessadores para o consumidor.) Para permitir que o consumidor faça isso, o objeto de sessão do provedor expõe métodos na interface [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)). Em aplicativos Visual C++, use a classe [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) para implementar `IDBSchemaRowset`.

`IDBSchemaRowsetImpl` são compatíveis com os seguintes métodos:

- [CheckRestrictions](../../data/oledb/idbschemarowsetimpl-checkrestrictions.md) verifica a validade das restrições em relação a um conjunto de linhas do esquema.

- [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md) implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro do modelo.

- [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) especifica quais restrições você permite em um determinado conjunto de linhas do esquema.

- [IDBSchemaRowset::GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) retorna um conjunto de linhas do esquema (herdado da interface).

- [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) retorna uma lista de conjuntos de linhas do esquema acessível por `IDBSchemaRowsetImpl::GetRowset` (herdado da interface).

## <a name="atl-ole-db-provider-wizard-support"></a>Suporte ao Assistente de Provedor OLE DB da ATL

::: moniker range="vs-2019"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

O **Assistente de Provedor OLE DB da ATL** cria três classes de esquema no arquivo de cabeçalho da sessão:

- **C**<em>ShortName</em>**SessionTRSchemaRowset**

- **C**<em>ShortName</em>**SessionColSchemaRowset**

- **C**<em>ShortName</em>**SessionPTSchemaRowset**

Essas classes respondem às solicitações do consumidor por informações do esquema. Observe que a especificação OLE DB exige que esses três conjuntos de linhas do esquema sejam suportados:

- **C**<em>ShortName</em>**SessionTRSchemaRowset** trata das solicitações por informações de tabela (o conjunto de linhas do esquema DBSCHEMA_TABLES).

- **C**<em>ShortName</em>**SessionColSchemaRowset** trata das solicitações por informações de coluna (o conjunto de linhas do esquema DBSCHEMA_COLUMNS). O assistente fornece amostra de implementações para essas classes, que retornam informações do esquema para um provedor DOS.

- **C**<em>ShortName</em>**SessionPTSchemaRowset** trata das solicitações por informações de esquema sobre o tipo de provedor (o conjunto de linhas do esquema DBSCHEMA_PROVIDER_TYPES). A implementação padrão fornecida pelo assistente retorna S_OK.

Você pode personalizar essas classes para tratar de informações apropriadas do esquema para seu provedor:

- Em **C**<em>ShortName</em>**SessionTRSchemaRowset**, você deve preencher os campos de catálogo, tabela e descrição (`trData.m_szType`, `trData.m_szTable` e `trData.m_szDesc`). O exemplo gerado pelo assistente usa apenas uma linha (tabela). Outros provedores podem retornar mais de uma tabela.

- Em **C**<em>ShortName</em>**SessionColSchemaRowset**, você passa o nome da tabela como um `DBID`.

::: moniker-end

## <a name="setting-restrictions"></a>Configurando restrições

Um conceito importante no suporte do conjunto de linhas do esquema é a configuração de restrições, que você pode fazer usando `SetRestrictions`. As restrições permitem que os consumidores busquem somente as linhas correspondentes (por exemplo, encontrar todas as colunas na tabela "MyTable"). As restrições são opcionais e, no caso em que nenhuma seja suportada (o padrão), todos os dados sempre serão retornados. Para obter um exemplo de um provedor que são compatíveis com as restrições, consulte a amostra [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV).

## <a name="setting-up-the-schema-map"></a>Configurando o mapa do esquema

Configure um mapa do esquema como este em Session.h em UpdatePV:

```cpp
BEGIN_SCHEMA_MAP(CUpdateSession)
    SCHEMA_ENTRY(DBSCHEMA_TABLES, CUpdateSessionTRSchemaRowset)
    SCHEMA_ENTRY(DBSCHEMA_COLUMNS, CUpdateSessionColSchemaRowset)
    SCHEMA_ENTRY(DBSCHEMA_PROVIDER_TYPES, CUpdateSessionPTSchemaRowset)
END_SCHEMA_MAP()
```

Para dar suporte a `IDBSchemaRowset`, você deve dar suporte a DBSCHEMA_TABLES, DBSCHEMA_COLUMNS e DBSCHEMA_PROVIDER_TYPES. É possível adicionar mais conjuntos de linhas do esquema a seu critério.

Declare uma classe do conjunto de linhas do esquema com um método `Execute`, como `CUpdateSessionTRSchemaRowset` em `UpdatePV`:

```cpp
class CUpdateSessionTRSchemaRowset :
    public CSchemaRowsetImpl < CUpdateSessionTRSchemaRowset,
                              CTABLESRow, CUpdateSession >
...
// Execute looks like this; what pointers does the consumer use?
    HRESULT Execute(DBROWCOUNT* pcRowsAffected,
                    ULONG cRestrictions, const VARIANT* rgRestrictions)
```

`CUpdateSession` é herdado de `IDBSchemaRowsetImpl`. Portanto, ele tem todos os métodos de tratamento de restrição. Usando `CSchemaRowsetImpl`, declare as três classes filho (listadas no mapa do esquema acima): `CUpdateSessionTRSchemaRowset`, `CUpdateSessionColSchemaRowset` e `CUpdateSessionPTSchemaRowset`. Cada uma dessas classes filho tem um método `Execute` que trata do seu respectivo conjunto de restrições (critérios de pesquisa). Cada método `Execute` compara os valores dos parâmetros *cRestrictions* e *rgRestrictions*. Consulte a descrição desses parâmetros em [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).

Saiba mais sobre quais restrições correspondem a um determinado conjunto de linhas do esquema n.a tabela de GUIDs do conjunto de linhas do esquema em [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na **Referência do programador do OLE DB** no SDK do Windows.

Por exemplo, se você deu suporte à restrição TABLE_NAME em DBSCHEMA_TABLES, você fará o seguinte:

Primeiramente, pesquise DBSCHEMA_TABLES e veja que ele é compatível com quatro restrições (em ordem).

|Restrição do conjunto de linhas do esquema|Valor de restrição|
|-------------------------------|-----------------------|
|TABLE_CATALOG|0x1 (binário 1)|
|TABLE_SCHEMA|0x2 (binário 10)|
|TABLE_NAME|0x4 (binário 100)|
|TABLE_TYPE|0x8 (binário 1000)|

Em seguida, há um bit para cada restrição. Como você deseja dar suporte apenas a TABLE_NAME, o retorno seria 0x4 no elemento `rgRestrictions`. Se você tivesse dado suporte a TABLE_CATALOG e TABLE_NAME, o retorno seria 0x5 (binário 101).

Por padrão, a implementação retorna 0 (não é compatível com quaisquer restrições) para qualquer solicitação. UpdatePV é um exemplo de provedor que é compatível com as restrições.

### <a name="example"></a>Exemplo

Esse código foi extraído da amostra [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV). `UpdatePv` é compatível com três conjuntos de linhas do esquema obrigatórios: DBSCHEMA_TABLES, DBSCHEMA_COLUMNS e DBSCHEMA_PROVIDER_TYPES. Como um exemplo de como implementar o suporte ao esquema no seu provedor, este tópico apresenta a implementação do conjunto de linhas DBSCHEMA_TABLE.

> [!NOTE]
> O código de exemplo pode ser diferente do que está listado aqui. Você deve considerar o código de exemplo como a versão mais recente.

A primeira etapa na adição de suporte do esquema é determinar a quais restrições você pretende dar suporte. Para determinar quais restrições estão disponíveis para seu conjunto de linhas do esquema, veja a especificação OLE DB para a definição de `IDBSchemaRowset`. Seguindo a definição principal, você vê uma tabela contendo o nome do conjunto de linhas do esquema, o número de restrições e as colunas de restrição. Selecione o conjunto de linhas do esquema ao qual deseja dar suporte e anote o número de restrições e colunas de restrição. Por exemplo, DBSCHEMA_TABLES dá suporte a quatro restrições (TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME e TABLE_TYPE):

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

Um bit representa cada coluna de restrição. Se quiser dar suporte a uma restrição (ou seja, você pode consultá-la), defina esse bit como 1. Se não quiser dar suporte a uma restrição, defina esse bit como zero. Na linha de código acima, `UpdatePV` é compatível com as restrições TABLE_NAME e TABLE_TYPE no conjunto de linhas DBSCHEMA_TABLES. Essa são a terceira (bitmask 100) e a quarta restrições (bitmask 1000). Portanto, a bitmask para `UpdatePv` é 1100 (ou 0x0C):

```cpp
if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))
    rgRestrictions[l] = 0x0C;
```

A seguinte função `Execute` é semelhante as do conjuntos de linhas regulares. Você tem três argumentos: *pcRowsAffected*, *cRestrictions* e *rgRestrictions*. A variável *pcRowsAffected* é um parâmetro de saída que o provedor pode retornar a contagem de linhas no conjunto de linhas do esquema. O parâmetro *cRestrictions* é um parâmetro de entrada que contém o número de restrições passadas pelo consumidor ao provedor. O parâmetro *rgRestrictions* é uma matriz de valores de VARIANTE que mantêm os valores de restrição.

```cpp
HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG cRestrictions,
                const VARIANT* rgRestrictions)
```

A variável *cRestrictions* se baseia no número total de restrições para um conjunto de linhas do esquema, independentemente de o provedor ser ou não compatível com elas. Como UpdatePv é compatível com duas restrições (a terceira e quarta), esse código procura apenas por um valor *cRestrictions* maior que ou igual a três.

O valor para a restrição TABLE_NAME é armazenado em *rgRestrictions[2]* (novamente, a terceira restrição em uma matriz de base zero é 2). Verifique se a restrição não é VT_EMPTY para dar suporte verdadeiro a ela. Observe que VT_NULL não é igual a VT_EMPTY. VT_NULL especifica um valor de restrição válido.

A definição `UpdatePv` de um nome de tabela é um nome de caminho totalmente qualificado para um arquivo de texto. Extraia o valor de restrição e, em seguida, tente abrir o arquivo para garantir que ele existe de verdade. Se o arquivo não existir, retorne S_OK. Isso pode parecer um pouco retrógrado, mas o que o código está realmente informando ao consumidor é que não houve tabelas suportadas pelo nome especificado. O retorno S_OK significa que o código foi executado corretamente.

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

O suporte à quarta restrição (TABLE_TYPE) é semelhante à terceira restrição. Verifique se o valor não é VT_EMPTY. Essa restrição retorna apenas o tipo de tabela, TABLE. A fim de determinar os valores válidos para DBSCHEMA_TABLES, examine o **Apêndice B** da **Referência do programador do OLE DB** na seção do conjunto de linhas TABLES.

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

Esse é o lugar em que você cria de fato uma entrada de linha para o conjunto de linhas. A variável `trData` corresponde à `CTABLESRow`, uma estrutura definida nos modelos de provedor OLE DB. `CTABLESRow` corresponde à definição do conjunto de linhas TABLES no **Apêndice B** da especificação do OLE DB. Você tem apenas uma linha para adicionar, pois só é possível dar suporte a uma tabela por vez.

```cpp
// Bring over the data:
wcspy_s(trData.m_szType, OLESTR("TABLE"), 5);

wcspy_s(trData.m_szDesc, OLESTR("The Directory Table"), 19);

wcsncpy_s(trData.m_szTable, T2OLE(szFile), _TRUNCATE());
```

`UpdatePV` define somente três colunas: TABLE_NAME, TABLE_TYPE e DESCRIPTION. Anote as colunas para as quais você retorna informações, pois essa informação será necessária na implementação de `GetDBStatus`:

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

A função `GetDBStatus` é importante para a operação correta do conjunto de linhas do esquema. Como você não retorna dados para cada coluna no conjunto de linhas TABLES, é preciso especificar para quais colunas os dados serão e não serão retornados.

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

Como sua função `Execute` retorna dados para os campos TABLE_NAME, TABLE_TYPE e DESCRIPTION no conjunto de linhas TABLES, você pode examinar o **Apêndice B** da especificação OLE DB e determinar (contando de cima para baixo) que são os ordinais 3, 4 e 6. Para cada uma dessas colunas, retorne DBSTATUS_S_OK. Para todas as outras colunas, retorne DBSTATUS_S_ISNULL. É importante retornar esse status, pois um consumidor talvez não reconheça que o valor que você retorna é NULL ou outra coisa. Novamente, observe que NULL não é equivalente a vazio.

Saiba mais sobre a interface do conjunto de linhas do esquema OLE DB na interface [IDBSchemaRowset](../../data/oledb/idbschemarowsetimpl-class.md) na **Referência do programador do OLE DB**.

Saiba mais sobre como os consumidores podem usar métodos `IDBSchemaRowset` em [Obtenção de metadados com conjuntos de linhas do esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md).

Para obter um exemplo de um provedor que é compatível com restrições de esquema, consulte a amostra [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV).

## <a name="see-also"></a>Consulte também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)
