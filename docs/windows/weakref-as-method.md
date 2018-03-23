---
title: 'Método Weakref: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::As
dev_langs:
- C++
helpviewer_keywords:
- As method
ms.assetid: 7173da62-b3fe-44d6-aea4-1aa97e69b221
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 034664c91af422aed26f27b924827238b26a9134
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="weakrefas-method"></a>Método WeakRef::As
Define o parâmetro de ponteiro ComPtr especificado para representar a interface especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template<typename U>  
HRESULT As(  
   _Out_ ComPtr<U>* ptr  
);  
  
template<typename U>  
HRESULT As(  
   _Out_ Details::ComPtrRef<ComPtr<U>> ptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `U`  
 Uma ID de interface.  
  
 `ptr`  
 Quando essa operação for concluída, um objeto que representa o parâmetro `U`.  
  
## <a name="return-value"></a>Valor de retorno  
  
-   S_OK se essa operação for bem-sucedida; Caso contrário, o HRESULT que indica o motivo da falha na operação, e `ptr` é definido como `nullptr`.  
  
-   S_OK se essa operação for bem-sucedida, mas o objeto WeakRef atual já foi liberado. Parâmetro `ptr` é definido como `nullptr`.  
  
-   S_OK se essa operação for bem-sucedida, mas o objeto WeakRef atual não é derivado do parâmetro `U`. Parâmetro `ptr` é definido como `nullptr`.  
  
## <a name="remarks"></a>Comentários  
 Um erro é emitido se parâmetro `U` é IWeakReference ou não é derivado de IInspectable.  
  
 O primeiro modelo é o formulário que você deve usar em seu código. O segundo é uma especialização de auxiliar interno, que dá suporte a recursos de linguagem do C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.  
  
 A partir do SDK do Windows 10, esse método não define a instância de WeakRef `nullptr` se não foi possível obter a referência fraca, portanto você deve evitar código de verificação que verifica a WeakRef para `nullptr`. Em vez disso, verifique `ptr` para `nullptr`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)