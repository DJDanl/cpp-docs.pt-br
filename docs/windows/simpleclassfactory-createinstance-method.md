---
title: 'Método simpleclassfactory:: CreateInstance | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::SimpleClassFactory::CreateInstance
dev_langs:
- C++
helpviewer_keywords:
- CreateInstance method
ms.assetid: 17b7947a-2608-49d9-b730-fef76501c9bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d9dfb783a8e002f249d5f6b4cc0a45193669efb3
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42603107"
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
Deve ser **nullptr**; caso contrário, o valor retornado é CLASS_E_NOAGGREGATION.

SimpleClassFactory não dá suporte a agregação. Se havia suporte para a agregação e o objeto que está sendo criado fazia parte de uma agregação *pUnkOuter* seria um ponteiro para o controle `IUnknown` interface da agregação.

*riid*  
ID do objeto para criar a interface.

*ppvObject*  
Quando essa operação for concluída, ponteiro para uma instância do objeto especificado o *riid* parâmetro.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` é definido, um erro de asserção será emitido se a classe base especificada no parâmetro de modelo de classe não é derivada da [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurada com o ClassicCom ou WinRtClassicComMix [ RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)