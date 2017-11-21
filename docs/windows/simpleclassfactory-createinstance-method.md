---
title: "Método Simpleclassfactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::SimpleClassFactory::CreateInstance
dev_langs: C++
helpviewer_keywords: CreateInstance method
ms.assetid: 17b7947a-2608-49d9-b730-fef76501c9bc
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: aaffaf02c7db9c311f3f06e18e0194089d79e430
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="simpleclassfactorycreateinstance-method"></a>Método SimpleClassFactory::CreateInstance

Cria uma instância da interface especificada.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD( CreateInstance )(
   _Inout_opt_ IUnknown* pUnkOuter,
   REFIID riid,
   _Deref_out_ void** ppvObject
);
```

### <a name="parameters"></a>Parâmetros

*pUnkOuter*  
Deve ser `nullptr`; caso contrário, o valor de retorno é CLASS_E_NOAGGREGATION.

SimpleClassFactory não dá suporte a agregação. Se havia suporte para a agregação e o objeto que está sendo criado fazia parte de uma agregação, `pUnkOuter` seria um ponteiro para a interface de controle IUnknown do agregado.

*riid*  
ID do objeto para criar a interface.

*ppvObject*  
Quando essa operação for concluída, ponteiro para uma instância do objeto especificado pelo `riid` parâmetro.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Se &#95; &#95; WRL_STRICT #95; &#95; é definido, um erro de asserção é emitido se a classe base especificada no parâmetro de modelo de classe não é derivada de [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurado com o ClassicCom ou WinRtClassicComMix [RuntimeClassType ](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft:: wrl

## <a name="see-also"></a>Consulte também

[Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)