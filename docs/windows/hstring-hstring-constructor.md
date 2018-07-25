---
title: 'Construtor hstring:: Hstring | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::HString
dev_langs:
- C++
ms.assetid: 6da12785-ed01-4720-a004-667db60298f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a3188e137d3a39fb26ca4151f72073306038e46f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876872"
---
# <a name="hstringhstring-constructor"></a>Construtor HString::HString
Inicializa uma nova instância da classe HString.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HString(HSTRING hstr = nullptr) throw();  
HString(HString&& other) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hstr`  
 Um identificador HSTRING.  
  
 `other`  
 Um objeto HString existente.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa um novo objeto de HString está vazio.  
  
 O segundo construtor inicializa um novo objeto de HString para o valor existente `other` parâmetro e, em seguida, destrói o `other` parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)