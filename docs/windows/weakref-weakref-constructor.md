---
title: 'Construtor weakref:: Weakref | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::WeakRef
dev_langs:
- C++
helpviewer_keywords:
- WeakRef, constructor
ms.assetid: 589f87e0-8dcc-4e82-aab2-f2f66f1ec47c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: eafbddea6ae651d74d8f33be8efa58c25a8a0d3d
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39641467"
---
# <a name="weakrefweakref-constructor"></a>Construtor WeakRef::WeakRef
Inicializa uma nova instância dos **WeakRef** classe.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *ptr*  
 Um ponteiro, referência ou referência rvalue a um objeto existente que inicializa o atual **WeakRef** objeto.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa vazia **WeakRef** objeto. O segundo construtor inicializa um **WeakRef** objeto de um ponteiro para o `IWeakReference` interface. O terceiro construtor inicializa um **WeakRef** objeto a partir de uma referência a um `ComPtr<IWeakReference>` objeto. O quartos e quintas construtores inicializam um **WeakRef** objeto de outro **WeakRef** objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)