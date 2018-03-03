---
title: db_table | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc-attr.db_table
dev_langs:
- C++
helpviewer_keywords:
- db_table attribute
ms.assetid: ff9eb957-4e6d-4175-afcc-fd8ea916cec0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 37dd6fd80a0d18f1b9d93f5299fca797238a509f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dbtable"></a>db_table
Abre uma tabela de banco de dados OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ db_table(   
   db_table,   
   name,   
   source_name,   
   hresult   
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *db_table*  
 Uma cadeia de caracteres especificando o nome de uma tabela de banco de dados (por exemplo, "produtos").  
  
 *nome* (opcional)  
 O nome do identificador que você usa para trabalhar com a tabela. Você deve especificar esse parâmetro se você quiser retornar mais de uma linha de resultados. **db_table** gera uma variável com especificado *nome* que pode ser usado para percorrer o conjunto de linhas ou executar várias consultas de ação.  
  
 *source_name* (opcional)  
 O `CSession` variável ou instância de uma classe que tem o `db_source` atributo aplicado a ele no qual o comando é executado. Consulte [db_source](../windows/db-source.md).  
  
 `hresult` (opcional)  
 Identifica a variável que receberá o `HRESULT` deste comando de banco de dados. Se a variável não existir, ele será automaticamente introduzido pelo atributo.  
  
## <a name="remarks"></a>Comentários  
 **db_table** cria um [CTable](../data/oledb/ctable-class.md) objeto, que é usado por um consumidor OLE DB para abrir uma tabela. Você pode usar esse atributo apenas no nível de classe; Você não pode usá-lo embutido. Use **db_column** para associar colunas de tabela para variáveis; use **db_param** delimitar (define o tipo de parâmetro e, portanto em) de parâmetros.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador irá renomear a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome atribuído a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivado de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as classes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir abre a tabela de produtos para uso por `CProducts`.  
  
```  
// db_table.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[ db_table(L"dbo.Products") ]  
class CProducts {  
   [ db_column("1") ] LONG m_ProductID;  
};  
```  
  
 Para obter um exemplo desse atributo usado em um aplicativo, consulte os exemplos de [AtlAgent](http://msdn.microsoft.com/en-us/52bef5da-c1a0-4223-b4e6-9e464b6db409) e [MultiRead](http://msdn.microsoft.com/en-us/5a2a915a-77dc-492f-94b2-1b809995dd5e).  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   
