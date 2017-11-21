---
title: 'Construtor hstring:: Hstring | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HString::HString
dev_langs: C++
ms.assetid: 6da12785-ed01-4720-a004-667db60298f1
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a598b6a4b0e1b6077e2232131814192ef0a81863
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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