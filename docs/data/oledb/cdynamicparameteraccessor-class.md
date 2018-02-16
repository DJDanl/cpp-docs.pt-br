---
title: Classe CDynamicParameterAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CDynamicParameterAccessor
- ATL::CDynamicParameterAccessor
- CDynamicParameterAccessor
dev_langs:
- C++
helpviewer_keywords:
- CDynamicParameterAccessor class
ms.assetid: 5f22626e-e80d-491f-8b3b-cedc50331960
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6c0bf234bd0f8a3de96c545e2bbdfe492822d627
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdynamicparameteraccessor-class"></a>Classe CDynamicParameterAccessor
Semelhante ao [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) mas obtém as informações de parâmetro a ser definido chamando o [ICommandWithParameters](https://msdn.microsoft.com/en-us/library/ms712937.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CDynamicParameterAccessor : public CDynamicAccessor  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-cdynamicparameteraccessor.md)|O construtor.|  
|[GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md)|Recupera os dados de parâmetro do buffer.|  
|[GetParamCount](../../data/oledb/cdynamicparameteraccessor-getparamcount.md)|Recupera o número de parâmetros no acessador.|  
|[GetParamIO](../../data/oledb/cdynamicparameteraccessor-getparamio.md)|Determina se o parâmetro especificado é um parâmetro de entrada ou saído.|  
|[GetParamLength](../../data/oledb/cdynamicparameteraccessor-getparamlength.md)|Recupera o comprimento do parâmetro especificado armazenado no buffer.|  
|[GetParamName](../../data/oledb/cdynamicparameteraccessor-getparamname.md)|Recupera o nome de um parâmetro especificado.|  
|[GetParamStatus](../../data/oledb/cdynamicparameteraccessor-getparamstatus.md)|Recupera o status do parâmetro especificado armazenado no buffer.|  
|[GetParamString](../../data/oledb/cdynamicparameteraccessor-getparamstring.md)|Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|  
|[GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md)|Recupera o tipo de dados de um parâmetro especificado.|  
|[SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md)|Define o buffer usando os dados de parâmetro.|  
|[SetParamLength](../../data/oledb/cdynamicparameteraccessor-setparamlength.md)|Define o comprimento do parâmetro especificado armazenado no buffer.|  
|[SetParamStatus](../../data/oledb/cdynamicparameteraccessor-setparamstatus.md)|Define o status do parâmetro especificado armazenado no buffer.|  
|[SetParamString](../../data/oledb/cdynamicparameteraccessor-setparamstring.md)|Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|  
  
## <a name="remarks"></a>Comentários  
 O provedor deve oferecer suporte `ICommandWithParameters` para o consumidor usar essa classe.  
  
 As informações de parâmetro são armazenadas em um buffer criadas e gerenciadas por essa classe. Obter dados de parâmetro do buffer usando [GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md) e [GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).  
  
 Para obter um exemplo demonstram como usar essa classe para executar um procedimento armazenado do SQL Server e obter os valores de parâmetro de saída, consulte o artigo da Base de dados de Conhecimento Q058860, "como: executar um procedimento armazenado usando CDynamicParameterAccessor." Artigos da Base de dados de Conhecimento estão disponíveis na documentação do MSDN Library Visual Studio ou em [http://support.microsoft.com/](http://support.microsoft.com).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../../data/oledb/caccessor-class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)