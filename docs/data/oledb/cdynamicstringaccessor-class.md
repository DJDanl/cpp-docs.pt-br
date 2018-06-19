---
title: Classe CDynamicStringAccessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicStringAccessor
dev_langs:
- C++
helpviewer_keywords:
- CDynamicStringAccessor class
ms.assetid: 138dc4de-c7c3-478c-863e-431e48249027
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1b8888bdac7d605ce1832ef7074955fab4893b33
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097592"
---
# <a name="cdynamicstringaccessor-class"></a>Classe CDynamicStringAccessor
Permite que você acesse uma fonte de dados quando você não possui conhecimento do esquema do banco de dados (estrutura do banco de dados).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      template< typename BaseType, DBTYPEENUM OleDbType >  
class CDynamicStringAccessorT : public CDynamicAccessor  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetString](../../data/oledb/cdynamicstringaccessor-getstring.md)|Recupera os dados da coluna especificada como uma cadeia de caracteres.|  
|[SetString](../../data/oledb/cdynamicstringaccessor-setstring.md)|Define os dados da coluna especificada como uma cadeia de caracteres.|  
  
## <a name="remarks"></a>Comentários  
 Enquanto [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) solicita os dados no formato nativo, o provedor relatado `CDynamicStringAccessor` solicita que o provedor de buscar todos os dados acessados a partir do repositório de dados como dados de cadeia de caracteres. Isso é especialmente útil para tarefas simples que não exigem o cálculo de valores no repositório de dados, como exibir ou imprimir o conteúdo do repositório de dados.  
  
 O tipo nativo dos dados da coluna no repositório de dados não é importante; como o provedor pode suportar a conversão de dados, ele fornecerá os dados no formato de cadeia de caracteres. Se o provedor não oferece suporte para a conversão de tipo de dados nativo para uma cadeia de caracteres (que não é comum), a chamada de solicitação retornará o valor de sucesso **DB_S_ERRORSOCCURED**, e o status para a coluna correspondente será indicar um problema de conversão com **DBSTATUS_E_CANTCONVERTVALUE**.  
  
 Use `CDynamicStringAccessor` métodos para obter informações de coluna. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução.  
  
 As informações de coluna são armazenadas em um buffer criadas e gerenciadas por essa classe. Obter dados do buffer usando [GetString](../../data/oledb/cdynamicstringaccessor-getstring.md), ou armazená-lo para o buffer usando [SetString](../../data/oledb/cdynamicstringaccessor-setstring.md).  
  
 Para obter uma discussão e exemplos de como usar as classes de acessador dinâmico, consulte [usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../../data/oledb/caccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)   
 [Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)   
 [Classe CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)