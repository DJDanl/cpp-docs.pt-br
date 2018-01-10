---
title: 'operador&lt; operador (Microsoft:: wrl) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::operator<
dev_langs: C++
ms.assetid: bfae0e1c-1648-482b-99c2-3217d62aba46
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fca41cae7c8fdadd215b049228da0b87788d2717
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="operatorlt-operator-microsoftwrl"></a>operador&lt; operador (Microsoft:: wrl)
Determina se o endereço de um objeto é menor que outro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<class T, class U>  
bool operator<(const ComPtr<T>& a, const ComPtr<U>& b) throw();  
template<class T, class U>  
bool operator<(const Details::ComPtrRef<ComPtr<T>>& a, const Details::ComPtrRef<ComPtr<U>>& b) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `a`  
 O objeto à esquerda.  
  
 `b`  
 O objeto à direita.  
  
## <a name="return-value"></a>Valor de retorno  
 `true`Se o endereço do `a` é menor que o endereço do `b`; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)