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
ms.openlocfilehash: 96b77ec87e3219206d353f56293fc201c46f5d7e
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39568765"
---
# <a name="hstringhstring-constructor"></a>Construtor HString::HString
Inicializa uma nova instância dos **HString** classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HString(HSTRING hstr = nullptr) throw();  
HString(HString&& other) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *HSTR*  
 Um identificador de HSTRING.  
  
 *other*  
 Um existente **HString** objeto.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa uma nova **HString** objeto que está vazio.  
  
 O segundo construtor inicializa uma nova **HString** objeto para o valor de existente *outras* parâmetro e, em seguida, destrói o *outros* parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)