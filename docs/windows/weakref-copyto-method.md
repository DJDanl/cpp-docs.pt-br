---
title: 'Método Weakref: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::CopyTo
dev_langs:
- C++
helpviewer_keywords:
- CopyTo method
ms.assetid: f83de6da-b3d4-41a6-9845-cd725ecf3b75
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 817d984e995e7ac33ba80f978a282a8c0bac3e4f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890629"
---
# <a name="weakrefcopyto-method"></a>Método WeakRef::CopyTo
Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT CopyTo(  
   REFIID riid,  
   _Deref_out_ IInspectable** ptr  
);  
  
template<typename U>  
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)