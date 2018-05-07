---
title: 'Cdynamicaccessor:: SetStatus | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicAccessor::SetStatus
- ATL::CDynamicAccessor::SetStatus
- CDynamicAccessor.SetStatus
- ATL.CDynamicAccessor.SetStatus
dev_langs:
- C++
helpviewer_keywords:
- SetStatus method
ms.assetid: 6db82694-e87d-4bf8-a7e3-5765cf6abff9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7bf0fd390699d83261cf52651a3dc16613fa70d2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdynamicaccessorsetstatus"></a>CDynamicAccessor::SetStatus
Define o status da coluna especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool SetStatus(DBORDINAL nColumn,   
   DBSTATUS status)throw();  

bool SetStatus(const CHAR* pColumnName,   
   DBSTATUS status) throw();  

bool SetStatus(const WCHAR* pColumnName,   
   DBSTATUS status) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nColumn`  
 [in] O número da coluna. Coluna de números começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.  
  
 *status*  
 [in] O status da coluna. Consulte [DBSTATUS](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE* para obter mais informações.  
  
 `pColumnName`  
 [in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o status de coluna especificada é definido com êxito. Caso contrário, essa função retorna **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [CDynamicAccessor::GetStatus](../../data/oledb/cdynamicaccessor-getstatus.md)