---
title: Estrutura CreatorMap | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreatorMap
- implements/Microsoft::WRL::Details::CreatorMap
dev_langs: C++
helpviewer_keywords: CreatorMap structure
ms.assetid: 94e40927-90c3-4107-bca3-3ad2dc4beda9
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a941f052527b3617772bcb18b2092fdc35ea3a22
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creatormap-structure"></a>Estrutura CreatorMap
Oferece suporte à infraestrutura de biblioteca de modelos C++ do Windows em tempo de execução e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CreatorMap;  
```  
  
## <a name="remarks"></a>Comentários  
 Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.  
  
 CreatorMap contém as seguintes informações:  
  
-   Como inicializar, registrar e cancelar o registro de objetos.  
  
-   Como comparar dados de ativação, dependendo de uma fábrica clássico COM ou tempo de execução do Windows.  
  
-   Informações sobre o nome de servidor e de cache de fábrica para uma interface.  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados CreatorMap::activationId](../windows/creatormap-activationid-data-member.md)|Representa uma ID de objeto é identificada por uma ID de classe do COM clássico ou um nome de tempo de execução do Windows.|  
|[Membro de dados CreatorMap::factoryCache](../windows/creatormap-factorycache-data-member.md)|Armazena o ponteiro para o cache de fábrica para o CreatorMap.|  
|[Membro de dados CreatorMap::factoryCreator](../windows/creatormap-factorycreator-data-member.md)|Cria uma fábrica para o CreatorMap especificado.|  
|[Membro de dados CreatorMap::serverName](../windows/creatormap-servername-data-member.md)|Armazena o nome do servidor para o CreatorMap.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CreatorMap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)