---
title: 'Construtor weakref:: Weakref | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::WeakRef
dev_langs:
- C++
helpviewer_keywords:
- WeakRef, constructor
ms.assetid: 589f87e0-8dcc-4e82-aab2-f2f66f1ec47c
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c215006412a1ab882792546e575b6f448529a652
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="weakrefweakref-constructor"></a>Construtor WeakRef::WeakRef
Inicializa uma nova instância da classe WeakRef.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WeakRef();  
WeakRef(  
   decltype(__nullptr)  
);  
  
WeakRef(  
   _In_opt_ IWeakReference* ptr  
);  
  
WeakRef(  
   const ComPtr<IWeakReference>& ptr  
);  
  
WeakRef(  
   const WeakRef& ptr  
);  
  
WeakRef(  
   _Inout_ WeakRef&& ptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ptr`  
 Um ponteiro, referência ou referência de rvalue para um objeto existente que inicializa o objeto WeakRef atual.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa um objeto WeakRef vazio. O segundo construtor inicializa um objeto de WeakRef de um ponteiro para a interface IWeakReference. O terceiro construtor inicializa um objeto de WeakRef de uma referência a um ComPtr\<IWeakReference > objeto. Os quarto e quinto construtores inicializa um objeto de WeakRef de outro objeto WeakRef.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)