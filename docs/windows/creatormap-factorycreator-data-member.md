---
title: 'Membro de dados creatormap:: Factorycreator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::CreatorMap::factoryCreator
dev_langs:
- C++
helpviewer_keywords:
- factoryCreator data member
ms.assetid: c9aac363-8f38-4cfd-9605-1e6ac74c5097
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 29a88c34502404de13bd3b93d13c60470e2882ea
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650710"
---
# <a name="creatormapfactorycreator-data-member"></a>Membro de dados CreatorMap::factoryCreator
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HRESULT (*factoryCreator)(  
   unsigned int* currentflags,  
   const CreatorMap* entry,  
   REFIID iidClassFactory,  
 IUnknown** factory);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *currentflags*  
 Um dos [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.  
  
 *entry*  
 Um CreatorMap.  
  
 *iidClassFactory*  
 A ID de interface de uma fábrica de classes.  
  
 *fábrica*  
 Quando a operação for concluída, o endereço de uma fábrica de classes.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Cria uma fábrica para o CreatorMap especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura CreatorMap](../windows/creatormap-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)