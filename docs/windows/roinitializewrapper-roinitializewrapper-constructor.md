---
title: 'Construtor roinitializewrapper:: Roinitializewrapper | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper
dev_langs: C++
ms.assetid: c6f7fb07-14af-4574-9135-cea164607f30
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 88ef0885c49ba7ba28afe40aea25a74eb55d46e9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="roinitializewrapperroinitializewrapper-constructor"></a>Construtor RoInitializeWrapper::RoInitializeWrapper
Inicializa uma nova instância da classe RoInitializeWrapper.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
RoInitializeWrapper(   RO_INIT_TYPE flags)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `flags`  
 Uma das enumerações RO_INIT_TYPE, que especifica o suporte fornecido pelo tempo de execução do Windows.  
  
## <a name="remarks"></a>Comentários  
 A classe RoInitializeWrapper invoca Windows::Foundation::Initialize (*sinalizadores*).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)