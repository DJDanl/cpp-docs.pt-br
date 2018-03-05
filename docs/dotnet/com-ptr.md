---
title: 'com:: PTR | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ptr
dev_langs:
- C++
helpviewer_keywords:
- com::ptr
ms.assetid: ee302e3c-8fed-4875-a372-2e55003718d3
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 91c50379ae6514aa482cf4ee33eb7ff83fccc7b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptr"></a>com::ptr
Um wrapper para um objeto COM que pode ser usado como um membro de uma classe CLR. O wrapper também automatiza o gerenciamento de tempo de vida do objeto COM, liberando referências de propriedade no objeto quando seu destruidor é chamado. Semelhante a [classe CComPtr](../atl/reference/ccomptr-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <msclr\com\ptr.h>  
```  
  
## <a name="remarks"></a>Comentários  
 [com:: PTR classe](../dotnet/com-ptr-class.md) é definido no \<msclr\com\ptr.h > arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)