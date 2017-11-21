---
title: Estrutura FactoryCache | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Details::FactoryCache
dev_langs: C++
helpviewer_keywords: FactoryCache structure
ms.assetid: 624544e6-0989-47f6-a3e9-edb60e1ee6d4
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: fbb6b32fbd34794c13d2f4b7dc75e242464bc7b9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="factorycache-structure"></a>Estrutura FactoryCache
Oferece suporte à infraestrutura de biblioteca de modelos C++ do Windows em tempo de execução e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct FactoryCache;  
```  
  
## <a name="remarks"></a>Comentários  
 Contém o local de uma fábrica de classe e um valor que identifica um registrado wrt ou objeto de classe COM.  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados FactoryCache::cookie](../windows/factorycache-cookie-data-member.md)|Contém um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrado e é posteriormente usado para cancelar o registro do objeto.|  
|[Membro de dados FactoryCache::factory](../windows/factorycache-factory-data-member.md)|Aponta para uma fábrica de classes de tempo de execução do Windows ou COM.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `FactoryCache`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)