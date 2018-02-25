---
title: SET_PARAM_TYPE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- SET_PARAM_TYPE
dev_langs:
- C++
helpviewer_keywords:
- SET_PARAM_TYPE macro
ms.assetid: 85979070-2d55-4c67-94b1-9b9058babc59
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0c2355b69be471f2f644a0126533bf17c4702cdc
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="setparamtype"></a>SET_PARAM_TYPE
Especifica `COLUMN_ENTRY` macros que seguem o `SET_PARAM_TYPE` macro de entrada, saída ou entrada/saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
SET_PARAM_TYPE(type)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 [in] O tipo a ser definido para o parâmetro.  
  
## <a name="remarks"></a>Comentários  
 Provedores oferecem suporte apenas tipos de entrada/saída parâmetros que são suportados pela fonte de dados subjacente. O tipo é uma combinação de um ou mais **DBPARAMIO** valores (consulte [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) no *referência do programador DB OLE*):  
  
-   **DBPARAMIO_NOTPARAM** o acessador não tem parâmetros. Normalmente, você define **eParamIO** para esse valor em acessadores de linha para lembrar o usuário que parâmetros são ignorados.  
  
-   **DBPARAMIO_INPUT** um parâmetro de entrada.  
  
-   **DBPARAMIO_OUTPUT** um parâmetro de saída.  
  
-   **DBPARAMIO_INPUT &#124; DBPARAMIO_OUTPUT** o parâmetro é uma entrada e um parâmetro de saída.  
  
## <a name="example"></a>Exemplo  
```
cpp  
class CArtistsProperty
{
public:
   short m_nReturn;
   short m_nAge;
   TCHAR m_szFirstName[21];
   TCHAR m_szLastName[31];

BEGIN_PARAM_MAP(CArtistsProperty)
   SET_PARAM_TYPE(DBPARAMIO_OUTPUT)
   COLUMN_ENTRY(1, m_nReturn)
   SET_PARAM_TYPE(DBPARAMIO_INPUT)
   COLUMN_ENTRY(2, m_nAge)
END_PARAM_MAP()

BEGIN_COLUMN_MAP(CArtistsProperty)
   COLUMN_ENTRY(1, m_szFirstName)
   COLUMN_ENTRY(2, m_szLastName)
END_COLUMN_MAP()

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

   DEFINE_COMMAND_EX(CArtistsProperty, L" \
      { ? = SELECT Age FROM Artists WHERE Age < ? }")
};
``` 
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor do OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)