---
title: 'Cdynamicparameteraccessor:: Setparamstring | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CDynamicParameterAccessor.SetParamString
- ATL::CDynamicParameterAccessor::SetParamString
- SetParamString
- CDynamicParameterAccessor::SetParamString
- CDynamicParameterAccessor.SetParamString
dev_langs: C++
helpviewer_keywords: SetParamString method
ms.assetid: 77a38d23-7e33-4e5a-bda6-c12c4c3fe2e4
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 75d6e9887b609349a092bb67e55508ca1429387b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicparameteraccessorsetparamstring"></a>CDynamicParameterAccessor::SetParamString
Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      bool SetParamString(   
   DBORDINAL nParam,   
   const CHAR* pString,   
   DBSTATUS status = DBSTATUS_S_OK    
) throw( );  
bool SetParamString(   
   DBORDINAL nParam,   
   const WCHAR* pString,   
   DBSTATUS status = DBSTATUS_S_OK    
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 `pString`  
 [in] Um ponteiro para o ANSI (**CHAR**) ou Unicode (**WCHAR**) dados do parâmetro especificado de cadeia de caracteres. Consulte `DBSTATUS` no OLEDB.  
  
 *status*  
 [in] O `DBSTATUS` status do parâmetro especificado. Para obter informações sobre `DBSTATUS` valores, consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE*, ou procurar `DBSTATUS` no OLEDB.  
  
## <a name="remarks"></a>Comentários  
 Retorna **true** em caso de sucesso ou **false** em caso de falha.  
  
 `SetParamString`falhará se você tentar definir uma cadeia de caracteres que é maior do que o tamanho máximo especificado para `pString`.  
  
 Use `SetParamString` para definir dados de parâmetro de cadeia de caracteres no buffer. Use [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para definir os dados que não sejam parâmetro no buffer.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)