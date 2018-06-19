---
title: par (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::pair
dev_langs:
- C++
helpviewer_keywords:
- pair class [STL/CLR]
ms.assetid: 3326b4d9-a52a-49e5-8103-9aa5e8b352de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2d05dceaa763f8d0e33ccc86e783f66447c48b76
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33160817"
---
# <a name="pair-stlclr"></a>par (STL/CLR)
A classe de modelo descreve um objeto que encapsula um par de valores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value1,  
    typename Value2>  
    ref class pair;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Value1  
 O tipo do primeiro valor encapsulado.  
  
 Value2  
 O tipo do segundo valor quebrado.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[pair::first_type (STL/CLR)](../dotnet/pair-first-type-stl-clr.md)|O tipo do primeiro valor encapsulado.|  
|[pair::second_type (STL/CLR)](../dotnet/pair-second-type-stl-clr.md)|O tipo do segundo valor encapsulado.|  
  
|Objeto de membro|Descrição|  
|-------------------|-----------------|  
|[pair::first (STL/CLR)](../dotnet/pair-first-stl-clr.md)|O primeiro valor armazenado.|  
|[pair::second (STL/CLR)](../dotnet/pair-second-stl-clr.md)|O segundo valor armazenado.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[pair::pair (STL/CLR)](../dotnet/pair-pair-stl-clr.md)|Constrói um objeto do par.|  
|[pair::swap (STL/CLR)](../dotnet/pair-swap-stl-clr.md)|Alterna o conteúdo de dois pares.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[pair::operator= (STL/CLR)](../dotnet/pair-operator-assign-stl-clr.md)|Substitui o armazenado par de valores.|  
  
## <a name="remarks"></a>Comentários  
 O objeto armazena um par de valores. Você pode usar essa classe de modelo para combinar dois valores em um único objeto. Observe que `cliext::pair` (descrita aqui) armazena apenas os tipos gerenciados; para armazenar um par de não gerenciado tipos usam `std::pair`, declarado em `<utility>`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/utilitário >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [make_pair (STL/CLR)](../dotnet/make-pair-stl-clr.md)