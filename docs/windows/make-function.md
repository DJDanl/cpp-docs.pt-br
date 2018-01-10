---
title: "Função make | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Make
dev_langs: C++
helpviewer_keywords: Make function
ms.assetid: 66704143-df99-4a95-904d-ed99607e1034
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: aac2a50e3c50941d607dea32c9f7c9eecde8e589
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="make-function"></a>Função Make
Inicializa a classe de tempo de execução do Windows especificada. Use esta função para criar uma instância de um componente que é definido no mesmo módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7,  
   typename TArg8,  
   typename TArg9  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3,  
   TArg4 &&arg4,  
   TArg5 &&arg5,  
   TArg6 &&arg6,  
   TArg7 &&arg7,  
   TArg8 &&arg8,  
   TArg9 &&arg9  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7,  
   typename TArg8  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3,  
   TArg4 &&arg4,  
   TArg5 &&arg5,  
   TArg6 &&arg6,  
   TArg7 &&arg7,  
   TArg8 &&arg8  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3,  
   TArg4 &&arg4,  
   TArg5 &&arg5,  
   TArg6 &&arg6,  
   TArg7 &&arg7  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3,  
   TArg4 &&arg4,  
   TArg5 &&arg5,  
   TArg6 &&arg6  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3,  
   TArg4 &&arg4,  
   TArg5 &&arg5  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3,  
   TArg4 &&arg4  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2,  
   TArg3 &&arg3  
);  
template <  
   typename T,  
   typename TArg1,  
   typename TArg2  
>  
ComPtr<T> Make(  
   TArg1 &&arg1,  
   TArg2 &&arg2  
);  
template <  
   typename T,  
   typename TArg1  
>  
ComPtr<T> Make(  
   TArg1 &&arg1  
);  
template <  
   typename T  
>  
ComPtr<T> Make();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe especificada pelo usuário que herda de `WRL::RuntimeClass`.  
  
 `TArg1`  
 Tipo de argumento 1 que é passado para a classe de tempo de execução especificado.  
  
 `TArg2`  
 Tipo de argumento 2 que é passado para a classe de tempo de execução especificado.  
  
 `TArg3`  
 Tipo de argumento 3 que é passado para a classe de tempo de execução especificado.  
  
 `TArg4`  
 Tipo de argumento 4 que é passado para a classe de tempo de execução especificado.  
  
 `TArg5`  
 Tipo de argumento 5 é passado para a classe de tempo de execução especificado.  
  
 `TArg6`  
 Tipo de argumento 6 que é passado para a classe de tempo de execução especificado.  
  
 `TArg7`  
 Tipo de argumento 7 que é passado para a classe de tempo de execução especificado.  
  
 `TArg8`  
 Tipo de argumento 8 que é passado para a classe de tempo de execução especificado.  
  
 `TArg9`  
 Tipo de argumento 9 que é passado para a classe de tempo de execução especificado.  
  
 `arg1`  
 Argumento 1 que é passado para a classe de tempo de execução especificado.  
  
 `arg2`  
 Argumento 2 que é passado para a classe de tempo de execução especificado.  
  
 `arg3`  
 Argumento 3 que é passado para a classe de tempo de execução especificado.  
  
 `arg4`  
 Argumento de 4 que é passado para a classe de tempo de execução especificado.  
  
 `arg5`  
 Argumento 5 que é passado para a classe de tempo de execução especificado.  
  
 `arg6`  
 Argumento 6 que é passado para a classe de tempo de execução especificado.  
  
 `arg7`  
 Argumento 7 que é passado para a classe de tempo de execução especificado.  
  
 `arg8`  
 Argumento 8 que é passado para a classe de tempo de execução especificado.  
  
 `arg9`  
 Argumento 9 que é passado para a classe de tempo de execução especificado.  
  
## <a name="return-value"></a>Valor de retorno  
 Um `ComPtr<T>` objeto se for bem-sucedida; caso contrário, `nullptr`.  
  
## <a name="remarks"></a>Comentários  
 Consulte [como: instanciar componentes WRL diretamente](../windows/how-to-instantiate-wrl-components-directly.md) para conhecer as diferenças entre esta função e [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md)e para obter um exemplo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)