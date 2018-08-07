---
title: 'operador&lt; operador (Microsoft:: wrl) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator<
dev_langs:
- C++
ms.assetid: bfae0e1c-1648-482b-99c2-3217d62aba46
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2de0d40a4b506da2cec36719b8fa2fe9c22108d8
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604207"
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
  
### <a name="parameters"></a>Parâmetros  
 *a*  
 O objeto à esquerda.  
  
 *b*  
 O objeto à direita.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o endereço de *um* é menor que o endereço do *b*; caso contrário, **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)