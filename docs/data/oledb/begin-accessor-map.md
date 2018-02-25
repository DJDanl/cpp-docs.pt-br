---
title: BEGIN_ACCESSOR_MAP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- BEGIN_ACCESSOR_MAP
dev_langs:
- C++
helpviewer_keywords:
- BEGIN_ACCESSOR_MAP macro
ms.assetid: e6d6e3a4-62fa-4e49-8c53-caf8c9d20091
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0fd9684d3ab428ffa2e874f781208812d1ad12fc
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="beginaccessormap"></a>BEGIN_ACCESSOR_MAP
Marca o início das entradas do mapa de acessador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
BEGIN_ACCESSOR_MAP(x, num)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro de usuário.  
  
 *num*  
 [in] O número de acessadores neste mapa de acessador.  
  
## <a name="remarks"></a>Comentários  
 No caso de vários acessadores em um conjunto de linhas, você precisa especificar `BEGIN_ACCESSOR_MAP` no início e no uso de `BEGIN_ACCESSOR` macro cada acessador individuais. O `BEGIN_ACCESSOR` macro é concluída com o `END_ACCESSOR` macro. O mapa de acessador for concluído com o `END_ACCESSOR_MAP` macro.  
  
 Se você tiver apenas um acessador no registro do usuário, use a macro [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md).  
  
## <a name="example"></a>Exemplo  

 ```cpp  
class CArtistsAccessor
{
public:
// Data Elements
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];
   short m_nAge;

// Output binding map
BEGIN_ACCESSOR_MAP(CArtistsAccessor, 2)
   BEGIN_ACCESSOR(0, true)
      COLUMN_ENTRY(1, m_szFirstName)
      COLUMN_ENTRY(2, m_szLastName)
   END_ACCESSOR()
   BEGIN_ACCESSOR(1, false) // Not an auto accessor
      COLUMN_ENTRY(3, m_nAge)
   END_ACCESSOR()
END_ACCESSOR_MAP()

   HRESULT OpenDataSource()
   {
      CDataSource _db;
      _db.Open();
      return m_session.Open(_db);
   }

   void CloseDataSource()
   {
      m_session.Close();
   }

   CSession m_session;

   DEFINE_COMMAND_EX(CArtistsAccessor, L" \
   SELECT \
      FirstName, \
      LastName, \
      Age \
      FROM Artists")
};
 ```

  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [END_ACCESSOR](../../data/oledb/end-accessor.md)   
 [END_ACCESSOR_MAP](../../data/oledb/end-accessor-map.md)