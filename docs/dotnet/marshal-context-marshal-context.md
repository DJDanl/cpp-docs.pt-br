---
title: marshal_context::marshal_context | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- msclr::interop::marshal_context::marshal_context
- marshal_context::marshal_context
- msclr.interop.marshal_context.marshal_context
- marshal_context.marshal_context
dev_langs: C++
helpviewer_keywords: marshal_context class [C++], operations
ms.assetid: 5f08c895-60b0-4f72-97ff-7ae37c68e853
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a91b4f1c5f30711c46550dabb4369e380214fce1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="marshalcontextmarshalcontext"></a>marshal_context::marshal_context
Constrói uma `marshal_context` objeto a ser usado para conversão de dados entre tipos de dados gerenciado e nativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
marshal_context();  
```  
  
## <a name="remarks"></a>Comentários  
 Algumas conversões de dados exigem um contexto de marshaling. Consulte [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais traduções exigem um contexto e qual arquivo marshaling deve ser incluído em seu aplicativo.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [marshal_context::marshal_as](../dotnet/marshal-context-marshal-as.md).  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >  
  
 **Namespace:** msclr::interop  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de Marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md)   
 [marshal_as](../dotnet/marshal-as.md)   
 [Classe marshal_context](../dotnet/marshal-context-class.md)