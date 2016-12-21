---
title: "Classe CDynamicAccessor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL.CDynamicAccessor"
  - "ATL::CDynamicAccessor"
  - "CDynamicAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDynamicAccessor"
ms.assetid: 374b13b7-1f09-457d-9e6b-df260ff4d178
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CDynamicAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite acessar uma fonte de dados quando você não tem conhecimento do esquema de base de dados \(a estrutura subjacente do base de dados\).  
  
## Sintaxe  
  
```  
class CDynamicAccessor : public CAccessorBase  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[AddBindEntry](../../data/oledb/cdynamicaccessor-addbindentry.md)|Adiciona uma entrada de associação para as colunas de saída ao substituir o acessador padrão.|  
|[CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)|Cria uma instância e inicializa o objeto de `CDynamicAccessor` .|  
|[Fechar](../../data/oledb/cdynamicaccessor-close.md)|Desassocia todas as colunas, o liberará memória alocada, e libera o ponteiro de interface de [IAccessor](https://msdn.microsoft.com/en-us/library/ms719672.aspx) na classe.|  
|[GetBookmark](../../data/oledb/cdynamicaccessor-getbookmark.md)|Recupera o indexador da linha atual.|  
|[GetBlobHandling](../../data/oledb/cdynamicaccessor-getblobhandling.md)|Recupera o valor de manipulação de BLOB para a linha atual.|  
|[GetBlobSizeLimit](../../data/oledb/cdynamicaccessor-getblobsizelimit.md)|Recupera o tamanho máximo do BLOB em bytes.|  
|[GetColumnCount](../../data/oledb/cdynamicaccessor-getcolumncount.md)|Recupera o número de colunas no conjunto de linhas.|  
|[GetColumnFlags](../../data/oledb/cdynamicaccessor-getcolumnflags.md)|Recupera as características da coluna.|  
|[GetColumnInfo](../../data/oledb/cdynamicaccessor-getcolumninfo.md)|Recupera os metadados da coluna.|  
|[GetColumnName](../Topic/CDynamicAccessor::GetColumnName.md)|Recupera o nome de uma coluna especificada.|  
|[GetColumnType](../../data/oledb/cdynamicaccessor-getcolumntype.md)|Recupera o tipo de dados de uma coluna especificada.|  
|[GetLength](../../data/oledb/cdynamicaccessor-getlength.md)|Recupera o comprimento máximo possível de uma coluna em bytes.|  
|[GetOrdinal](../../data/oledb/cdynamicaccessor-getordinal.md)|Recupera o índice de coluna recebe um nome de coluna.|  
|[GetStatus](../../data/oledb/cdynamicaccessor-getstatus.md)|Recupera o status de uma coluna especificada.|  
|[GetValue](../../data/oledb/cdynamicaccessor-getvalue.md)|Recupera os dados de buffer.|  
|[SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md)|Define o valor de manipulação de BLOB para a linha atual.|  
|[SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md)|Define o tamanho máximo do BLOB em bytes.|  
|[SetLength](../../data/oledb/cdynamicaccessor-setlength.md)|Define o comprimento da coluna em bytes.|  
|[SetStatus](../Topic/CDynamicAccessor::SetStatus.md)|Define o status de uma coluna especificada.|  
|[SetValue](../../data/oledb/cdynamicaccessor-setvalue.md)|Armazena os dados no buffer.|  
  
## Comentários  
 Use os métodos de `CDynamicAccessor` para obter informações como nomes de coluna, contagem de coluna da coluna, tipo de dados, e assim por diante.  Você usa essas informações de coluna para criar dinamicamente em tempo de execução um acessador.  
  
 As informações de coluna é armazenada em um buffer que é criada e gerenciada por essa classe.  Obtenha dados do buffer usando [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md).  
  
 Para obter uma discussão e exemplos de usar as classes dinâmicas do acessador, consulte [Usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).  
  
## Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../Topic/CAccessor%20Class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)