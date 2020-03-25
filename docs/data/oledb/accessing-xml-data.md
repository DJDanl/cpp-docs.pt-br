---
title: Acessando dados XML
ms.date: 10/18/2018
helpviewer_keywords:
- data access [C++], XML data
- XML [C++], accessing data
- CXMLAccessor class, retrieving XML data
- data [C++], XML data access
- rowsets [C++], retrieving XML data
- CStreamRowset class, retrieving XML data
ms.assetid: 6b693d55-a554-4846-8118-e8773b79b572
ms.openlocfilehash: be4225003211449a98d3fbe5fd686b9b8058a651
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212271"
---
# <a name="accessing-xml-data"></a>Acessando dados XML

Há dois métodos separados para recuperar dados XML de uma fonte de dados: uma usa [CStreamRowset](../../data/oledb/cstreamrowset-class.md) e a outra usa [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md).

|Funcionalidade|CStreamRowset|CXMLAccessor|
|-------------------|-------------------|------------------|
|Quantidade de dados transferidos|Recupera dados de todas as colunas e linhas ao mesmo tempo.|Recupera dados de todas as colunas, mas apenas uma linha por vez. Você deve navegar pelas linhas usando métodos como `MoveNext`.|
|Formatando a cadeia de caracteres|SQL Server formata a cadeia de caracteres XML e a envia para o consumidor.|Recupera dados do conjunto de linhas em seu formato nativo (solicita que o provedor o envie como cadeias de caracteres Unicode) e, em seguida, cria a cadeia de caracteres que contém os dados no formato XML.|
|Controle sobre a formatação|Você tem algum nível de controle sobre como a cadeia de caracteres XML é formatada definindo algumas SQL Server propriedades específicas do 2000.|Você não tem controle sobre o formato da cadeia de caracteres XML gerada.|

Embora `CStreamRowset` forneça uma maneira mais eficiente geral de recuperar dados em formato XML, há suporte apenas para o SQL Server 2000.

## <a name="retrieving-xml-data-using-cstreamrowset"></a>Recuperando dados XML usando CStreamRowset

Você especifica [CStreamRowset](../../data/oledb/cstreamrowset-class.md) como o tipo de conjunto de linhas em sua declaração de `CCommand` ou `CTable`. Você pode usá-lo com seu próprio acessador ou sem acessador, por exemplo:

```cpp
CCommand<CAccessor<CMyAccessor>, CStreamRowset> myCmd;
```

-ou-

```cpp
CCommand<CNoAccessor, CStreamRowset> myCmd;
```

Normalmente, quando você chama `CCommand::Open` (especificando, por exemplo, `CRowset` como a classe `TRowset`), ele obtém um ponteiro de `IRowset`. `ICommand::Execute` retorna um ponteiro de `IRowset`, que é armazenado no membro `m_spRowset` do objeto `CRowset`. Métodos como `MoveFirst`, `MoveNext`e `GetData` usam esse ponteiro para recuperar os dados.

Por outro lado, quando você chama `CCommand::Open` (mas especifica `CStreamRowset` como a classe `TRowset`), `ICommand::Execute` retorna um ponteiro de `ISequentialStream`, que é armazenado no membro de dados `m_spStream` de [CStreamRowset](../../data/oledb/cstreamrowset-class.md). Em seguida, você usa o método `Read` para recuperar os dados (cadeia de caracteres Unicode) no formato XML. Por exemplo:

```cpp
myCmd.m_spStream->Read()
```

SQL Server 2000 faz a formatação XML e retorna todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.

Para obter um exemplo usando o método `Read`, consulte **adicionando suporte a XML ao consumidor para** [implementar um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md).

> [!NOTE]
> O suporte a XML usando o `CStreamRowset` funciona somente com o SQL Server 2000 e requer que você tenha o provedor de OLE DB para SQL Server 2000 (instalado com o MDAC).

## <a name="retrieving-xml-data-using-cxmlaccessor"></a>Recuperando dados XML usando CXMLAccessor

O [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md) permite que você acesse dados de uma fonte de dados como dados de cadeia de caracteres quando você não tem conhecimento do esquema do repositório de dados. `CXMLAccessor` funciona como `CDynamicStringAccessorW`, exceto que o primeiro converte todos os dados acessados do armazenamento de dados como dados formatados em XML (marcados). Os nomes de marca XML correspondem aos nomes de coluna do armazenamento de dados o mais próximo possível.

Use `CXMLAccessor` como faria com qualquer outra classe de acessador, passando-a como um parâmetro de modelo para `CCommand` ou `CTable`:

```cpp
CTable<CXMLAccessor, CRowset> rs;
```

Use [GetXMLRowData](../../data/oledb/cxmlaccessor-getxmlrowdata.md) para recuperar dados da tabela uma linha por vez e navegar pelas linhas usando métodos como `MoveNext`, por exemplo:

```cpp
// Open data source, session, and rowset
hr = rs.MoveFirst();

while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )
{
    CStringW strRowData;
    myCmd.GetXMLRowData(strRowData);

    printf_s( "%S\n", strRowData );

    hr = rs.MoveNext();
}
```

Você pode usar [GetXMLColumnData](../../data/oledb/cxmlaccessor-getxmlcolumndata.md) para recuperar as informações de coluna (tipo de dados) como dados de cadeia de caracteres XML formatados.

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
