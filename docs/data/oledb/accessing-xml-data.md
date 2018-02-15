---
title: Acessando dados XML | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d9379abfd27f4dd8297864160f35367da0727935
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="accessing-xml-data"></a>Acessando dados XML
Há dois métodos separados de recuperar dados XML de uma fonte de dados: uma usa [CStreamRowset](../../data/oledb/cstreamrowset-class.md) e outra que usa [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md).  
  
|Funcionalidade|CStreamRowset|CXMLAccessor|  
|-------------------|-------------------|------------------|  
|Quantidade de dados transferidos|Recupera dados de todas as colunas e linhas de uma vez.|Recupera dados de todas as colunas, mas apenas uma linha por vez. Você deve navegar linhas usando métodos como `MoveNext`.|  
|A cadeia de caracteres de formatação|Formatos de cadeia de caracteres XML do SQL Server e o envia para o consumidor.|Recupera dados do conjunto de linhas em seu formato nativo (solicitações que o provedor de enviá-los como cadeias de caracteres Unicode) e, em seguida, cria a cadeia de caracteres que contém os dados em formato XML.|  
|Controle sobre a formatação|Você tem algum nível de controle sobre como a cadeia de caracteres XML está formatada por definir algumas propriedades específicas do SQL Server 2000.|Você não tem controle sobre o formato da cadeia de caracteres XML gerado.|  
  
 Enquanto `CStreamRowset` fornece uma maneira mais eficiente gerais de recuperação de dados em formato XML, somente há suporte para o SQL Server 2000.  
  
## <a name="retrieving-xml-data-using-cstreamrowset"></a>Recuperando dados XML usando CStreamRowset  
 Especificar [CStreamRowset](../../data/oledb/cstreamrowset-class.md) como o tipo de conjunto de linhas no seu `CCommand` ou `CTable` declaração. Você pode usá-lo com seus próprios acessadores ou nenhum acessador, por exemplo:  
  
```  
CCommand<CAccessor<CMyAccessor>, CStreamRowset> myCmd;  
```  
  
 -ou-  
  
```  
CCommand<CNoAccessor, CStreamRowset> myCmd;  
```  
  
 Normalmente quando você chama `CCommand::Open` (especificando, por exemplo, `CRowset` como o `TRowset` classe), ele obtém uma `IRowset` ponteiro. `ICommand::Execute` Retorna um `IRowset` ponteiro, que é armazenado no `m_spRowset` membro o `CRowset` objeto. Métodos como `MoveFirst`, `MoveNext`, e `GetData` usar esse ponteiro para recuperar os dados.  
  
 Por outro lado, quando você chama `CCommand::Open` (mas especificar `CStreamRowset` como o `TRowset` classe), `ICommand::Execute` retorna um `ISequentialStream` ponteiro, que é armazenado no `m_spStream` membro de dados de [CStreamRowset](../../data/oledb/cstreamrowset-class.md). Você usa o `Read` método para recuperar os dados (cadeia de caracteres Unicode) em formato XML. Por exemplo:  
  
```  
myCmd.m_spStream->Read()  
```  
  
 SQL Server 2000 executa a formatação XML e retorna todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.  
  
 Para um exemplo usando o `Read` método, consulte "Adicionando suporte de XML para o consumidor" [implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md).  
  
> [!NOTE]
>  Suporte a XML usando `CStreamRowset` funciona apenas com o SQL Server 2000 e requer que você tenha o provedor OLE DB para SQL Server 2000 (instalado com o MDAC).  
  
## <a name="retrieving-xml-data-using-cxmlaccessor"></a>Recuperando dados XML usando CXMLAccessor  
 [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md) permite que você acesse dados de uma fonte de dados como dados de cadeia de caracteres quando você não possui conhecimento do esquema do repositório de dados. `CXMLAccessor` funciona como `CDynamicStringAccessorW` exceto que o primeiro converte todos os dados acessados do armazenamento de dados como XML formatado dados (marcados). Os nomes de marca XML corresponderem nomes de coluna do repositório de dados possível.  
  
 Use `CXMLAccessor` como você faria com qualquer outra classe de acessador, passando-o como um parâmetro de modelo para `CCommand` ou `CTable`:  
  
```  
CTable<CXMLAccessor, CRowset> rs;  
```  
  
 Use [GetXMLRowData](../../data/oledb/cxmlaccessor-getxmlrowdata.md) para recuperar dados de tabela uma linha por vez e navegue linhas usando métodos como `MoveNext`, por exemplo:  
  
```  
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