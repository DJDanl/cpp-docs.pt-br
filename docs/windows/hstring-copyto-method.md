---
title: 'Método hstring:: CopyTo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: a1fd2ef0-e175-4c18-927b-550e02a89e43
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 65d8e259b74bcdffbf11c6c96172d918f9db1b50
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570867"
---
# <a name="hstringcopyto-method"></a>Método HString::CopyTo
Copia o atual **HString** objeto para um objeto HSTRING.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT CopyTo(  
   _Out_ HSTRING *str  
   ) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *str*  
 O HSTRING que recebe a cópia.  
  
## <a name="remarks"></a>Comentários  
 Este método chama o [WindowsDuplicateString](http://msdn.microsoft.com/library/br224634.aspx) função.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)