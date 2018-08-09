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
ms.openlocfilehash: b0f4645a6008b954833bf282971a0d3912e1d598
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39653138"
---
# <a name="asweak-function"></a>Função AsWeak
Recupera uma referência fraca a uma instância especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T>  
HRESULT AsWeak(  
   _In_ T* p,  
   _Out_ WeakRef* pWeak  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Um ponteiro para o tipo do parâmetro *p*.  
  
 *p*  
 Uma instância de um tipo.  
  
 *pWeak*  
 Quando essa operação for concluída, um ponteiro para uma referência fraca ao parâmetro *p*.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK, se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica a causa da falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)