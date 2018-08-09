---
title: db_accessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.db_accessor
dev_langs:
- C++
helpviewer_keywords:
- db_accessor attribute
ms.assetid: ec407a9f-24d7-4822-96d4-7cc6a0301815
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 727e67ad5bceb396da98463b77fb75f2f99154b3
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650005"
---
# <a name="dbaccessor"></a>db_accessor
Grupos `db_column` atributos que participam de `IAccessor`-com base em associação.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ db_accessor(   
   num,   
   auto   
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *num*  
 Especifica o número de acessador (um índice de inteiro baseado em zero). Você deve especificar números de acessador aumentar ordem, usando inteiros ou valores definidos.  
  
 *auto*  
 Um valor booliano que especifica se o acessador é automaticamente recuperado (TRUE) ou não recuperados (FALSE).  
  
## <a name="remarks"></a>Comentários  
 **db_accessor** define o acessador de OLE DB subjacente para subsequentes `db_column` e `db_param` atributos dentro da mesma classe ou função. **db_accessor** utilizável no nível do membro e é usado ao grupo `db_column` atributos que participam do OLE DB `IAccessor`-com base em associação. Ele é usado em conjunto com qualquer um de `db_table` ou `db_command` atributos. Chamar esse atributo é semelhante a chamar o [BEGIN_ACCESSOR](../data/oledb/begin-accessor.md) e [END_ACCESSOR](../data/oledb/end-accessor.md) macros.  
  
 **db_accessor** gera um conjunto de linhas e associá-lo para os mapas de acessador correspondente. Se você não chamar **db_accessor**acessador 0 será gerado automaticamente e todas as associações de coluna serão mapeadas para este bloco de acessador.  
  
 **db_accessor** grupos associações de coluna em um ou mais acessadores de banco de dados. Para uma discussão sobre os cenários em que você precisa usar vários acessadores, consulte [usando vários acessadores em um conjunto de linhas](../data/oledb/using-multiple-accessors-on-a-rowset.md). Consulte também "Usuário registro suporte para vários acessadores" na [registros de usuário](../data/oledb/user-records.md).  
  
 Quando o provedor do consumidor de atributo se aplica a esse atributo a uma classe, o compilador renomeará a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivada de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa **db_accessor** às colunas de grupo na tabela Orders do banco de dados Northwind para dois acessadores. Acessador 0 é um acessador automática e acessador 1 não é.  
  
```cpp  
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
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Blocos de atributo|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   