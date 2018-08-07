---
title: 'Método deferrableeventargs:: Getdeferral | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: ef6dc7c5-b0be-4b85-8507-d3fd97f2185d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 13cd6b361fccc49de6142a0640ff96dbab3cb92c
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571198"
---
# <a name="deferrableeventargsgetdeferral-method"></a>Método DeferrableEventArgs::GetDeferral
Obtém uma referência para o [adiamento](http://go.microsoft.com/fwlink/p/?linkid=526520) objeto que representa um evento adiado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HRESULT GetDeferral([out, retval] Windows::Foundation::IDeferral** result)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *resultado*  
 Um ponteiro que fará referência a [adiamento](http://go.microsoft.com/fwlink/p/?linkid=526520) objeto quando a chamada é concluída.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de código, consulte [classe DeferrableEventArgs](../windows/deferrableeventargs-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)