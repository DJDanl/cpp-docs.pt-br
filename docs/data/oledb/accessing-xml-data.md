---
title: Acessando dados XML | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- data access [C++], XML data
- XML [C++], accessing data
- CXMLAccessor class, retrieving XML data
- data [C++], XML data access
- rowsets [C++], retrieving XML data
- CStreamRowset class, retrieving XML data
ms.assetid: 6b693d55-a554-4846-8118-e8773b79b572
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d7db1d790ca9caeea6bd9c7853139f59ffa0ab6c
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808713"
---
# <a name="accessing-xml-data"></a>Acessando dados XML

Há dois métodos separados de recuperar dados XML de uma fonte de dados: uma usa [CStreamRowset](../../data/oledb/cstreamrowset-class.md) e outra que usa [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md).  
  
|Funcionalidade|CStreamRowset|CXMLAccessor|  
|-------------------|-------------------|------------------|  
|Quantidade de dados transferidos|Recupera dados de todas as colunas e linhas ao mesmo tempo.|Recupera dados de todas as colunas, mas apenas uma linha por vez. Você deve navegar linhas usando métodos como `MoveNext`.|  
|A cadeia de caracteres de formatação|SQL Server formata a cadeia de caracteres XML e envia-os para o consumidor.|Recupera dados do conjunto de linhas em seu formato nativo (solicitações que o provedor de enviá-lo como cadeias de caracteres Unicode) e, em seguida, cria a cadeia de caracteres que contém os dados em formato XML.|  
|Controle sobre a formatação|Você tem algum nível de controle sobre como a cadeia de caracteres XML é formatada, definindo algumas propriedades específicas do SQL Server 2000.|Você não tem controle sobre o formato da cadeia de caracteres XML gerada.|  
  
Enquanto `CStreamRowset` fornece a maneira mais eficiente geral de recuperação de dados em formato XML, ele só tem suporte pelo SQL Server 2000.  
  
## <a name="retrieving-xml-data-using-cstreamrowset"></a>Recuperando dados XML usando CStreamRowset  

Você especifica [CStreamRowset](../../data/oledb/cstreamrowset-class.md) como o tipo de conjunto de linhas no seu `CCommand` ou `CTable` declaração. Você pode usá-lo com seu próprios acessador ou nenhum acessador, por exemplo:  
  
```cpp  
CCommand<CAccessor<CMyAccessor>, CStreamRowset> myCmd;  
```  
  
-ou-  
  
```cpp  
CCommand<CNoAccessor, CStreamRowset> myCmd;  
```  
  
Normalmente quando você chama `CCommand::Open` (especificando, por exemplo, `CRowset` como o `TRowset` classe), ele obtém uma `IRowset` ponteiro. `ICommand::Execute` Retorna um `IRowset` ponteiro, que é armazenado em de `m_spRowset` membro do `CRowset` objeto. Métodos como `MoveFirst`, `MoveNext`, e `GetData` usar esse ponteiro para recuperar os dados.  
  
Por outro lado, quando você chama `CCommand::Open` (mas especificar `CStreamRowset` como o `TRowset` classe), `ICommand::Execute` retorna um `ISequentialStream` ponteiro, que é armazenado no `m_spStream` membro de dados de [CStreamRowset](../../data/oledb/cstreamrowset-class.md). Você, em seguida, usar o `Read` método para recuperar os dados (cadeia de caracteres Unicode) em formato XML. Por exemplo:  
  
```cpp  
myCmd.m_spStream->Read()  
```  
  
SQL Server 2000 faz a formatação XML e retorna todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.  
  
Para obter um exemplo usando o `Read` método, consulte "Adicionando suporte de XML para o consumidor" na [implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md).  
  
> [!NOTE]
> Suporte a XML usando `CStreamRowset` funciona apenas com o SQL Server 2000 e exige que você tenha o provedor OLE DB para SQL Server 2000 (instalado com o MDAC).  
  
## <a name="retrieving-xml-data-using-cxmlaccessor"></a>Recuperando dados XML usando CXMLAccessor  

[CXMLAccessor](../../data/oledb/cxmlaccessor-class.md) permite que você acesse dados de uma fonte de dados como dados de cadeia de caracteres quando você não possui conhecimento do esquema do repositório de dados. `CXMLAccessor` funciona como `CDynamicStringAccessorW` , exceto que o primeiro converte todos os dados acessados do armazenamento de dados como XML formatado (marcados) dados. Os nomes de marca XML correspondem aos nomes de coluna do repositório de dados mais próximo possível.  
  
Use `CXMLAccessor` como faria com qualquer outra classe de acessador, passá-lo como um parâmetro de modelo `CCommand` ou `CTable`:  
  
```cpp  
CTable<CXMLAccessor, CRowset> rs;  
```  
  
Use [GetXMLRowData](../../data/oledb/cxmlaccessor-getxmlrowdata.md) para recuperar dados de tabela uma linha por vez e navegar linhas usando métodos como `MoveNext`, por exemplo:  
  
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
  
Você pode usar [GetXMLColumnData](../../data/oledb/cxmlaccessor-getxmlcolumndata.md) para recuperar as informações de coluna (tipo de dados) como dados de cadeia de caracteres formatada em XML.  
  
## <a name="see-also"></a>Consulte também  

[Usando acessadores](../../data/oledb/using-accessors.md)