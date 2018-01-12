---
title: Classe marshal_context | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: marshal_context
dev_langs: C++
helpviewer_keywords: marshal_context class [C++]
ms.assetid: 241b0cf6-4ca4-4812-aaee-d671c11dc034
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9b59dfa82563a0c115f521bb881411981a30efc9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="marshalcontext-class"></a>Classe marshal_context
Essa classe converte dados entre ambientes gerenciados e nativos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class marshal_context  
```  
  
## <a name="remarks"></a>Comentários  
 Use o `marshal_context` classe para conversões de dados que exigem um contexto. Consulte [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais conversões exigem um contexto e qual arquivo marshaling deve ser incluído. O resultado de empacotamento quando você usar um contexto é válido somente até o `marshal_context` objeto é destruído. Para preservar seu resultado, você deve copiar os dados.  
  
 O mesmo `marshal_context` podem ser usados para várias conversões de dados. Reutilizar o contexto dessa maneira não afetará os resultados de marshaling de chamadas anteriores.  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >  
  
 **Namespace:** msclr::interop  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de Marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md)   
 [marshal_as](../dotnet/marshal-as.md)