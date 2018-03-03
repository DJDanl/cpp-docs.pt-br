---
title: db_accessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc-attr.db_accessor
dev_langs:
- C++
helpviewer_keywords:
- db_accessor attribute
ms.assetid: ec407a9f-24d7-4822-96d4-7cc6a0301815
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5faa84773fbf1fe15fd0223c97f0361f1215b149
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dbaccessor"></a>db_accessor
Grupos de **db_column** atributos que participam `IAccessor`-com base em associação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ db_accessor(   
   num,   
   auto   
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *num*  
 Especifica o número de acessador (um índice de inteiro baseado em zero). Você deve especificar números de acessador aumentar ordem, usando números inteiros ou valores definidos.  
  
 *auto*  
 Um valor booleano que especifica se o acessador é recuperado automaticamente (**TRUE**) ou não recuperados (**FALSE**).  
  
## <a name="remarks"></a>Comentários  
 **db_accessor** define o acessador de OLE DB subjacente para subsequentes **db_column** e **db_param** atributos dentro da mesma classe ou função. **db_accessor** é utilizável em nível de membro e é usado para o grupo **db_column** atributos que participam de OLE DB `IAccessor`-com base em associação. Ele é usado em conjunto com o o **db_table** ou **db_command** atributos. Chamar esse atributo é semelhante a chamar o [BEGIN_ACCESSOR](../data/oledb/begin-accessor.md) e [END_ACCESSOR](../data/oledb/end-accessor.md) macros.  
  
 **db_accessor** gera um conjunto de linhas e associa-o aos mapas de acessador correspondente. Se você não chama **db_accessor**acessador 0 será gerado automaticamente e todas as associações de coluna serão mapeadas para este bloco de acessador.  
  
 **db_accessor** grupos associações de coluna em um ou mais acessadores de banco de dados. Para uma discussão sobre os cenários em que você precisa usar vários acessadores, consulte [usando vários acessadores em um conjunto de linhas](../data/oledb/using-multiple-accessors-on-a-rowset.md). Consulte também "Usuário registro suporte para vários acessadores" na [registros de usuário](../data/oledb/user-records.md).  
  
 Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador irá renomear a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome atribuído a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivado de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as classes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa **db_accessor** para agrupar as colunas na tabela do banco de dados Northwind em dois acessadores. Acessador 0 é um acessador automática e acessador 1 não é.  
  
```  
// cpp_attr_ref_db_accessor.cpp  
// compile with: /LD /link /OPT:NOREF  
#define _ATL_ATTRIBUTES  
#include <atlbase.h>  
#include <atldbcli.h>  
  
[ db_command(L"SELECT LastName, FirstName FROM Orders") ]  
class CEmployees {  
public:  
   [ db_accessor(0, TRUE) ];  
   [ db_column("1") ] LONG m_OrderID;  
   [ db_column("2") ] TCHAR m_CustomerID[6];  
   [ db_column("4") ] DBTIMESTAMP m_OrderDate;   
  
   [ db_accessor(1, FALSE) ];  
   [ db_column("8") ] CURRENCY m_Freight;  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Blocos de atributo|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   
