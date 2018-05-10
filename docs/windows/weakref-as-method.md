---
title: 'Método Weakref: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::As
dev_langs:
- C++
helpviewer_keywords:
- As method
ms.assetid: 7173da62-b3fe-44d6-aea4-1aa97e69b221
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 70e694b4c86194402f48d335aac353e48c3de79a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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