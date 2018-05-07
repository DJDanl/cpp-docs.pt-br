---
title: 'com:: PTR | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- ptr
dev_langs:
- C++
helpviewer_keywords:
- com::ptr
ms.assetid: ee302e3c-8fed-4875-a372-2e55003718d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f3c4e3bb91e161f9176bcf6964fc843d4e4bd707
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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