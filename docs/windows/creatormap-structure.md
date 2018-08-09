---
title: Estrutura CreatorMap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreatorMap
- implements/Microsoft::WRL::Details::CreatorMap
dev_langs:
- C++
helpviewer_keywords:
- CreatorMap structure
ms.assetid: 94e40927-90c3-4107-bca3-3ad2dc4beda9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 173b41c6d36d36b7d8a0f4e7b024e845eec6ae4a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650499"
---
# <a name="creatormap-structure"></a>Estrutura CreatorMap
Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
struct CreatorMap;  
```  
  
## <a name="remarks"></a>Comentários  
 Contém informações sobre como inicializar, registrar e cancelar o registro de objetos.  
  
 **CreatorMap** contém as seguintes informações:  
  
-   Como inicializar, registrar e cancelar o registro de objetos.  
  
-   Como comparar os dados de ativação, dependendo de uma fábrica COM ou tempo de execução do Windows clássico.  
  
-   Informações sobre o nome de cache e o servidor de fábrica para uma interface.  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados CreatorMap::activationId](../windows/creatormap-activationid-data-member.md)|Representa uma ID de objeto é identificada por uma ID de classe do COM clássico ou um nome de tempo de execução do Windows.|  
|[Membro de dados CreatorMap::factoryCache](../windows/creatormap-factorycache-data-member.md)|Armazena o ponteiro para o cache de fábrica para o **CreatorMap**.|  
|[Membro de dados CreatorMap::factoryCreator](../windows/creatormap-factorycreator-data-member.md)|Cria uma fábrica para especificado **CreatorMap**.|  
|[Membro de dados CreatorMap::serverName](../windows/creatormap-servername-data-member.md)|Armazena o nome do servidor para o **CreatorMap**.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CreatorMap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)