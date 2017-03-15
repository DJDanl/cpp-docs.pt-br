---
title: "Acessando dados XML | Microsoft Docs"
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
  - "Classe CStreamRowset, recuperando dados XML"
  - "Classe CXMLAccessor, recuperando dados XML"
  - "dados [C++], acesso a dados XML"
  - "acesso a dados [C++], dados XML"
  - "conjuntos de linhas [C++], recuperando dados XML"
  - "XML [C++], acessando dados"
ms.assetid: 6b693d55-a554-4846-8118-e8773b79b572
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessando dados XML
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Há dois métodos diferentes de recuperar dados XML de uma fonte de dados: usa um [CStreamRowset](../../data/oledb/cstreamrowset-class.md) e o outro usa [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md).  
  
|Funcionalidade|CStreamRowset|CXMLAccessor|  
|--------------------|-------------------|------------------|  
|Quantidade de dados transferidos|Recupera dados de todas as colunas e linhas imediatamente.|Recupera dados de todas as colunas mas apenas uma linha de cada vez.  Você deve navegar nas linhas usando os métodos como `MoveNext`.|  
|Formatando a cadeia de caracteres|SQL Server formata a cadeia de caracteres XML e a envia para o consumidor.|Recupera dados do conjunto de linhas no seu formato nativo \(solicitações que o envio do provedor ele como cadeias de caracteres Unicode\) e depois criará a cadeia de caracteres que contém os dados no formato XML.|  
|Controle sobre a formatação|Você tiver algum nível de controle sobre como a cadeia de caracteres XML é formatada definir algumas propriedades específicas do SQL Server 2000.|Você não tem nenhum controle sobre o formato de cadeia de caracteres XML gerada.|  
  
 Quando `CStreamRowset` fornecer uma maneira eficiente mais total de recuperação de dados em formato XML, só tem suporte no SQL Server 2000.  
  
## Recuperando dados XML usando CStreamRowset  
 Você especifica [CStreamRowset](../../data/oledb/cstreamrowset-class.md) como o conjunto de linhas em sua declaração de `CCommand` ou de `CTable` .  Você pode usá\-lo com seu próprio acessador ou nenhum acessador, por exemplo:  
  
```  
CCommand<CAccessor<CMyAccessor>, CStreamRowset> myCmd;  
```  
  
 \- ou \-  
  
```  
CCommand<CNoAccessor, CStreamRowset> myCmd;  
```  
  
 Normalmente quando você chama `CCommand::Open` \(que especifica, por exemplo, `CRowset` como a classe de `TRowset` \), obtém um ponteirode `IRowset`.  `ICommand::Execute` retorna um ponteirode `IRowset`, que é armazenado no membro de `m_spRowset` do objeto de `CRowset` .  Métodos como `MoveFirst`, `MoveNext`, e o uso de `GetData` esse ponteiro recuperar os dados.  
  
 Por outro lado, quando você chama `CCommand::Open` \(mas `CStreamRowset` especificar como a classe de `TRowset` \), `ICommand::Execute` retorna um ponteiro de `ISequentialStream` , que é armazenado no membro de dados de `m_spStream` de [CStreamRowset](../../data/oledb/cstreamrowset-class.md).  Você usa o método de `Read` \(para recuperar os dados de cadeia de caracteres Unicode\) em formato XML.  Por exemplo:  
  
```  
myCmd.m_spStream->Read()  
```  
  
 SQL Server 2000 executa a formatação XML e retorna todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.  
  
 Para obter um exemplo que usa o método de `Read` , consulte “adicionar o suporte a XML para o consumidor” em [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md).  
  
> [!NOTE]
>  O suporte a XML que usa `CStreamRowset` funciona com o SQL Server 2000 e só requer o provedor OLE DB para SQL Server 2000 \(instalado com o MDAC\).  
  
## Recuperando dados XML usando CXMLAccessor  
 [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md) permite acessar dados de uma fonte de dados como dados de cadeia de caracteres quando você não tem conhecimento do esquema do repositório de dados.  `CXMLAccessor` funciona como `CDynamicStringAccessorW` exceto que o converte todos os dados antigos que acessaram do repositório de dados marcados como dados \(\) em formato XML.  Os nomes da marca XML correspondam aos nomes de coluna do repositório de dados do mais próximo possível.  
  
 Use `CXMLAccessor` como faria com qualquer outra classe do acessador, passando o como um parâmetro do modelo a `CCommand` ou a `CTable`:  
  
```  
CTable<CXMLAccessor, CRowset> rs;  
```  
  
 Use [GetXMLRowData](../Topic/CXMLAccessor::GetXMLRowData.md) para recuperar dados da linha de cada vez na tabela, e navegar nas linhas usando os métodos como `MoveNext`, por exemplo:  
  
```  
// Open data source, session, and rowset  
hr = rs.MoveFirst();  
while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )  
{  
    CStringW strRowData;  
    myCmd.GetXMLRowData(strRowData);  
  
    printf_s( "%S\n", strRowData );  
  
    hr = rs.MoveNext();  
}  
```  
  
 Você pode usar [GetXMLColumnData](../Topic/CXMLAccessor::GetXMLColumnData.md) para recuperar informações de coluna \(tipo de dados\) como dados formatados de cadeia de caracteres.  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)