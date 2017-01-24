---
title: "Fun&#231;&#227;o MakeAndInitialize | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::MakeAndInitialize"
dev_langs: 
  - "C++"
ms.assetid: 71ceeb12-d2a2-4317-b010-3dcde1b39467
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o MakeAndInitialize
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa a classe especificada de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  Use esta função para criar uma instância de um componente que é definido no módulo.  
  
## Sintaxe  
  
```cpp  
template <typename T, typename I,   
typename TArg1,   
typename TArg2,   
typename TArg3,   
typename TArg4,   
typename TArg5,   
typename TArg6,   
typename TArg7,   
typename TArg8,   
typename TArg9> HRESULT MakeAndInitialize(_Outptr_result_nullonfailure_ I** ppvObject, TArg1 &&arg1, TArg2 &&arg2, TArg3 &&arg3, TArg4 &&arg4, TArg5 &&arg5, TArg6 &&arg6, TArg7 &&arg7, TArg8 &&arg8, TArg9 &&arg9) throw()  
  
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
 Um valor `HRESULT`.  
  
## Comentários  
 Consulte [Como instanciar componentes WRL diretamente](../windows/how-to-instantiate-wrl-components-directly.md) para conhecer as diferenças entre esses função e [Microsoft::WRL::Make](../windows/make-function.md), e para obter um exemplo.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)