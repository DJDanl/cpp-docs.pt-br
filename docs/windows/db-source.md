---
title: db_source | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.db_source
dev_langs: C++
helpviewer_keywords: db_source attribute
ms.assetid: 0ec8bbf7-ade2-4899-bf4c-8608b92779bc
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 18c4a4af3f8df4e3af5f6aae8f6643db553c7373
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dbsource"></a>db_source
Cria uma conexão com uma fonte de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ db_source(   
   db_source,   
   name,   
   hresult   
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *db_source*  
 A cadeia de conexão usada para se conectar à fonte de dados. Para o formato da cadeia de caracteres de conexão, consulte [cadeias de caracteres de Conexão e Links de dados](https://msdn.microsoft.com/en-us/library/ms718376.aspx) no Microsoft Data Access Components (MDAC) SDK.  
  
 *nome* (opcional)  
 Quando você usa `db_source` em uma classe, *nome* é uma instância de um objeto de fonte de dados que tem o `db_source` atributo aplicado a ele (veja exemplo 1). Quando você usa `db_source` embutido na implementação de um método *nome* é uma variável (local para o método) que pode ser usada para acessar os dados de origem (consulte o exemplo 2). Transmita esse *nome* para o `source_name` parâmetro **db_command** para associar a fonte de dados com um comando.  
  
 `hresult` (opcional)  
 Identifica a variável que receberá o `HRESULT` deste comando de banco de dados. Se a variável não existir, ele será automaticamente introduzido pelo atributo.  
  
## <a name="remarks"></a>Comentários  
 `db_source`cria um [CDataSource](../data/oledb/cdatasource-class.md) e um [CSession](../data/oledb/csession-class.md) objeto, que juntas representam uma conexão com uma fonte de dados do consumidor OLE DB.  
  
 Quando você usa `db_source` em uma classe, o `CSession` objeto se torna um membro da classe.  
  
 Quando você usa `db_source` em um método, o código injetado será executado no escopo do método e o `CSession` será criado como uma variável local.  
  
 `db_source`Adiciona as propriedades da fonte de dados para uma classe ou dentro de um método. Ele é usado em conjunto com **db_command** (que usa o `db_source` *nome* parâmetro como seu `source_name` parâmetro).  
  
 Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador irá renomear a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome atribuído a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivado de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as classes.  
  
 Para obter um exemplo desse atributo usado em um aplicativo, consulte os exemplos de [AtlAgent](http://msdn.microsoft.com/en-us/52bef5da-c1a0-4223-b4e6-9e464b6db409) e [MultiRead](http://msdn.microsoft.com/en-us/5a2a915a-77dc-492f-94b2-1b809995dd5e).  
  
## <a name="example"></a>Exemplo  
 Este exemplo chama `db_source` em uma classe para criar uma conexão à fonte de dados `ds` usando o banco de dados Northwind. `ds`é um identificador para a fonte de dados, que pode ser usado internamente para o `CMyCommand` classe.  
  
```  
// db_source_1.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[  
  db_source(L"my_connection_string", name="ds"),  
  db_command(L"select * from Products")  
]  
class CMyCommand {};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, membro, o método, o local|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   
