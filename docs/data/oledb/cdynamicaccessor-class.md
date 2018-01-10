---
title: Classe CDynamicAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CDynamicAccessor
- ATL::CDynamicAccessor
- CDynamicAccessor
dev_langs: C++
helpviewer_keywords: CDynamicAccessor class
ms.assetid: 374b13b7-1f09-457d-9e6b-df260ff4d178
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f88c3eff9c8160a0e322c93dacf6985dc7b8a20b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicaccessor-class"></a>Classe CDynamicAccessor
Permite que você acesse uma fonte de dados quando você não possui conhecimento do esquema do banco de dados (estrutura do banco de dados).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDynamicAccessor : public CAccessorBase  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddBindEntry](../../data/oledb/cdynamicaccessor-addbindentry.md)|Adiciona uma entrada de associação às colunas de saída ao substituir o acessador padrão.|  
|[CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)|Cria e inicializa o `CDynamicAccessor` objeto.|  
|[Fechar](../../data/oledb/cdynamicaccessor-close.md)|Desvincula todas as colunas, libera a memória alocada e libera o [IAccessor](https://msdn.microsoft.com/en-us/library/ms719672.aspx) ponteiro de interface na classe.|  
|[GetBookmark](../../data/oledb/cdynamicaccessor-getbookmark.md)|Recupera o indicador da linha atual.|  
|[GetBlobHandling](../../data/oledb/cdynamicaccessor-getblobhandling.md)|Recupera o BLOB de tratamento de valor para a linha atual.|  
|[GetBlobSizeLimit](../../data/oledb/cdynamicaccessor-getblobsizelimit.md)|Recupera o tamanho máximo do BLOB em bytes.|  
|[GetColumnCount](../../data/oledb/cdynamicaccessor-getcolumncount.md)|Recupera o número de colunas no conjunto de linhas.|  
|[GetColumnFlags](../../data/oledb/cdynamicaccessor-getcolumnflags.md)|Recupera as características da coluna.|  
|[GetColumnInfo](../../data/oledb/cdynamicaccessor-getcolumninfo.md)|Recupera os metadados da coluna.|  
|[GetColumnName](../../data/oledb/cdynamicaccessor-getcolumnname.md)|Recupera o nome de uma coluna especificada.|  
|[GetColumnType](../../data/oledb/cdynamicaccessor-getcolumntype.md)|Recupera o tipo de dados de uma coluna especificada.|  
|[GetLength](../../data/oledb/cdynamicaccessor-getlength.md)|Recupera o comprimento máximo possível de uma coluna em bytes.|  
|[GetOrdinal](../../data/oledb/cdynamicaccessor-getordinal.md)|Recupera o índice da coluna recebe um nome de coluna.|  
|[GetStatus](../../data/oledb/cdynamicaccessor-getstatus.md)|Recupera o status de uma coluna especificada.|  
|[GetValue](../../data/oledb/cdynamicaccessor-getvalue.md)|Recupera os dados do buffer.|  
|[SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md)|Define o BLOB de tratamento de valor para a linha atual.|  
|[SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md)|Define o tamanho máximo do BLOB em bytes.|  
|[SetLength](../../data/oledb/cdynamicaccessor-setlength.md)|Define o comprimento da coluna em bytes.|  
|[SetStatus](../../data/oledb/cdynamicaccessor-setstatus.md)|Define o status de uma coluna especificada.|  
|[SetValue](../../data/oledb/cdynamicaccessor-setvalue.md)|Armazena os dados no buffer.|  
  
## <a name="remarks"></a>Comentários  
 Use `CDynamicAccessor` métodos para obter informações de coluna como nomes de coluna, contagem de colunas, tipo de dados e assim por diante. Você, em seguida, usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução.  
  
 As informações de coluna são armazenadas em um buffer que é criado e gerenciado por esta classe. Obter dados do buffer usando [GetValue](../../data/oledb/cdynamicaccessor-getvalue.md).  
  
 Para obter uma discussão e exemplos de como usar as classes de acessador dinâmico, consulte [usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../../data/oledb/caccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)