---
title: 'Método: Getaddressof | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::GetAddressOf
dev_langs:
- C++
ms.assetid: 6050decf-5f99-49f0-9497-1c8192c485ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7d4804373045d12c2e251e2de61b7aefd52ec916
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874662"
---
# <a name="hstringgetaddressof-method"></a>Método HString::GetAddressOf
Recupera um ponteiro para o identificador HSTRING subjacente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HSTRING* GetAddressOf() throw()  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o identificador HSTRING subjacente.  
  
## <a name="remarks"></a>Comentários  
 Após essa operação, o valor de cadeia de caracteres do identificador HSTRING subjacente é destruído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)