---
title: 'Crestrictions:: Open | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CRestrictions.Open
- ATL::CRestrictions::Open
- ATL.CRestrictions.Open
- CRestrictions::Open
dev_langs:
- C++
helpviewer_keywords:
- Open method
ms.assetid: 0aff0cc3-543a-47d2-8d6b-ebb36926b6db
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8039d55312687cc28be27f2ed7726b9bda1b44aa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="crestrictionsopen"></a>CRestrictions::Open
Retorna um resultado definido de acordo com as restrições de fornecido pelo usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Open(const CSession& session,  
   LPCTSTR lpszParam 1 = NULL,  
   LPCTSTR lpszParam 2 = NULL,  
   LPCTSTR lpszParam 3 = NULL,  
   LPCTSTR lpszParam 4 = NULL,  
   LPCTSTR lpszParam 5 = NULL,  
   LPCTSTR lpszParam 6 = NULL,  
   LPCTSTR lpszParam 7 = NULL,  
   bool bBind = true);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `session`  
 [in] Especifica um objeto de sessão existente, usado para se conectar à fonte de dados.  
  
 *lpszParam*  
 [in] Especifica as restrições no conjunto de linhas de esquema.  
  
 `bBind`  
 [in] Especifica se deve associar o mapa de coluna automaticamente. O padrão é **true**, que faz com que o mapa de coluna a ser associado automaticamente. Configuração `bBind` para **false** impede que a associação automática do mapa de coluna para que você pode vincular manualmente. (Associação manual é de especial interesse para os usuários OLAP).  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valores.  
  
## <a name="remarks"></a>Comentários  
 Você pode especificar um máximo de sete restrições em um conjunto de linhas de esquema.  
  
 Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) para obter informações sobre as restrições definidas em cada conjunto de linhas de esquema.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRestrictions](../../data/oledb/crestrictions-class.md)   
 [Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)