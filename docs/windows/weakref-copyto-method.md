---
title: "Método Weakref: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::CopyTo
dev_langs:
- C++
helpviewer_keywords:
- CopyTo method
ms.assetid: f83de6da-b3d4-41a6-9845-cd725ecf3b75
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5b0114a9768fbea12a5b98f51911267cb24b0b43
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="weakrefcopyto-method"></a>Método WeakRef::CopyTo
Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT CopyTo(  
   REFIID riid,  
   _Deref_out_ IInspectable** ptr  
);  
  
template<  
   typename U  
>  
HRESULT CopyTo(  
   _Deref_out_ U** ptr  
);  
  
HRESULT CopyTo(  
   _Deref_out_ IWeakReference** ptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `U`  
 Uma interface IInspectable do ponteiro. Um erro é emitido se `U` não é derivado de IInspectable.  
  
 `riid`  
 Uma ID de interface. Um erro é emitido se `riid` não é derivado de **IWeakReference**.  
  
 `ptr`  
 Um ponteiro indireto duplamente IInspectable ou IWeakReference.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que descreve a falha. Para obter mais informações, consulte Comentários.  
  
## <a name="remarks"></a>Comentários  
 Um valor de retorno de S_OK significa que essa operação foi bem-sucedida, mas não indica se a referência fraca foi resolvida para uma referência forte. Se for retornado S_OK, esse parâmetro de teste `p` é um forte referência; ou seja, o parâmetro `p` não é igual a `nullptr`.  
  
 A partir do SDK do Windows 10, esse método não define a instância de WeakRef `nullptr` se não foi possível obter a referência fraca, portanto você deve evitar erro ao verificar o código que verifica a WeakRef para `nullptr`. Em vez disso, verifique `ptr` para `nullptr`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)