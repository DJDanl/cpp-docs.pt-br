---
title: range_adapter (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::range_adapter
dev_langs:
- C++
helpviewer_keywords:
- range_adapter class [STL/CLR]
ms.assetid: 3fbe2a65-1216-46a0-a182-422816b80cfb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1a5b8a02856d7739867e3cf9f76f866a1e84efca
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="rangeadapter-stlclr"></a>range_adapter (STL/CLR)
Uma classe de modelo que encapsula um par de iteradores que são usadas para implementar várias interfaces de classe biblioteca BCL (Base). Você pode usar o range_adapter para manipular um intervalo STL/CLR como se fosse uma coleção de BCL.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Iter>  
    ref class range_adapter  
        :   public  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<Value>,  
        System::Collections::Generic::ICollection<Value>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 iter  
 O tipo associado os iteradores encapsulados.  
  
## <a name="members"></a>Membros  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[range_adapter::range_adapter (STL/CLR)](../dotnet/range-adapter-range-adapter-stl-clr.md)|Constrói um objeto de adaptador.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[range_adapter::operator= (STL/CLR)](../dotnet/range-adapter-operator-assign-stl-clr.md)|Substitui o par iterador armazenado.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.Collections.IEnumerable>|Itera por meio de elementos na coleção.|  
|<xref:System.Collections.ICollection>|Mantém um grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Itera por meio de elementos com tipo na coleção.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantém um grupo de elementos com tipo.|  
  
## <a name="remarks"></a>Comentários  
 O range_adapter armazena um par de iteradores, que por sua vez delimitar uma sequência de elementos. O objeto implementa as interfaces BCL quatro que lhe permitem percorrer os elementos, em ordem. Você pode usar essa classe de modelo para manipular os intervalos semelhante a BCL contêineres STL/CLR.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext adaptador >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [collection_adapter (STL/CLR)](../dotnet/collection-adapter-stl-clr.md)   
 [make_collection (STL/CLR)](../dotnet/make-collection-stl-clr.md)