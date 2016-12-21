---
title: "Fun&#231;&#227;o Make | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::Make"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função Make"
ms.assetid: 66704143-df99-4a95-904d-ed99607e1034
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o Make
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa a classe especificada de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  Use esta função para criar uma instância de um componente que é definido no módulo.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `T`  
 Uma classe especificada pelo usuário que herde de `WRL::RuntimeClass`.  
  
 `TArg1`  
 Tipo de argumento 1 que é passado para a classe especificada de tempo de execução.  
  
 `TArg2`  
 Tipo de argumento 2 que é passado para a classe especificada de tempo de execução.  
  
 `TArg3`  
 Tipo de argumento 3 que é passado para a classe especificada de tempo de execução.  
  
 `TArg4`  
 Tipo de argumento 4 que é passado para a classe especificada de tempo de execução.  
  
 `TArg5`  
 Tipo de argumento 5 que é passado para a classe especificada de tempo de execução.  
  
 `TArg6`  
 Tipo de argumento 6 que é passado para a classe especificada de tempo de execução.  
  
 `TArg7`  
 Tipo de argumento 7 que é passado para a classe especificada de tempo de execução.  
  
 `TArg8`  
 Tipo de argumento 8 que é passado para a classe especificada de tempo de execução.  
  
 `TArg9`  
 Tipo de argumento 9 que é passado para a classe especificada de tempo de execução.  
  
 `arg1`  
 Argumento 1 que é passado para a classe especificada de tempo de execução.  
  
 `arg2`  
 Argumento 2 que é passado para a classe especificada de tempo de execução.  
  
 `arg3`  
 Argumento 3 que é passado para a classe especificada de tempo de execução.  
  
 `arg4`  
 Argumento 4 que é passado para a classe especificada de tempo de execução.  
  
 `arg5`  
 Argumento 5 que é passado para a classe especificada de tempo de execução.  
  
 `arg6`  
 Argumento 6 que é passado para a classe especificada de tempo de execução.  
  
 `arg7`  
 Argumento 7 que é passado para a classe especificada de tempo de execução.  
  
 `arg8`  
 Argumento 8 que é passado para a classe especificada de tempo de execução.  
  
 `arg9`  
 Argumento 9 que é passado para a classe especificada de tempo de execução.  
  
## Valor de retorno  
 Um objeto de `ComPtr<T>` se bem\-sucedido; caso contrário, `nullptr`.  
  
## Comentários  
 Consulte [Como instanciar componentes WRL diretamente](../windows/how-to-instantiate-wrl-components-directly.md) para conhecer as diferenças entre esses função e [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md), e para obter um exemplo.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)