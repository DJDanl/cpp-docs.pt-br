---
title: Função AsWeak | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::AsWeak
dev_langs:
- C++
helpviewer_keywords:
- AsWeak function
ms.assetid: a6f10cfc-c1d6-4761-adb9-1a119cc99913
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 039d210e9a204c485e2f44c39ea87b4d35089d88
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="asweak-function"></a>Função AsWeak
Recupera uma referência fraca a uma instância especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
HRESULT AsWeak(  
   _In_ T* p,  
   _Out_ WeakRef* pWeak  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um ponteiro para o tipo de parâmetro `p`.  
  
 `p`  
 Uma instância de um tipo.  
  
 `pWeak`  
 Quando essa operação for concluída, um ponteiro para uma referência fraca a parâmetro `p`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK, se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica a causa da falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)