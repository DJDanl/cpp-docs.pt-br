---
title: adaptador (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- <cliext/adapter>
dev_langs:
- C++
helpviewer_keywords:
- <adapter> header [STL/CLR]
- adapter [STL/CLR]
- <cliext/adapter> header [STL/CLR]
ms.assetid: 71ce7e51-42b6-4f70-9595-303791a97677
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 6af58f1afff80a2f829e6726948279ef75b0cf5d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33104510"
---
# <a name="adapter-stlclr"></a>adapter (STL/CLR)
O cabeçalho STL/CLR `<cliext/adapter>` especifica duas classes de modelo (`collection_adapter` e `range_adapter`) e a função de modelo `make_collection`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <cliext/adapter>  
```  
  
## <a name="remarks"></a>Comentários  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[collection_adapter (STL/CLR)](../dotnet/collection-adapter-stl-clr.md)|Encapsula a coleção de biblioteca BCL (Base Class) como um intervalo.|  
|[range_adapter (STL/CLR)](../dotnet/range-adapter-stl-clr.md)|Ajusta o intervalo como uma coleção de BCL.|  
  
|Função|Descrição|  
|--------------|-----------------|  
|[make_collection (STL/CLR)](../dotnet/make-collection-stl-clr.md)|Cria um adaptador de intervalo usando um par iterador.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext adaptador >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)