---
title: Classe RoInitializeWrapper | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper
dev_langs: C++
ms.assetid: 4055fbe0-63a7-4c06-b5a0-414fda5640e5
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8b94db5e54089fa91c3b79c185df8b366de07c38
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="roinitializewrapper-class"></a>Classe RoInitializeWrapper
Inicializa o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class RoInitializeWrapper  
```  
  
## <a name="remarks"></a>Comentários  
 RoInitializeWrapper é uma conveniência que inicializa o tempo de execução do Windows e retorna um HRESULT que indica se a operação foi bem-sucedida.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor RoInitializeWrapper::RoInitializeWrapper](../windows/roinitializewrapper-roinitializewrapper-constructor.md)|Inicializa uma nova instância da classe RoInitializeWrapper.|  
|[Destruidor RoInitializeWrapper::~RoInitializeWrapper](../windows/roinitializewrapper-tilde-roinitializewrapper-destructor.md)|Destrói a instância atual da classe RoInitializeWrapper.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador RoInitializeWrapper::HRESULT()](../windows/roinitializewrapper-hresult-parens-operator.md)|Recupera o HRESULT produzido pelo construtor RoInitializeWrapper.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `RoInitializeWrapper`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)