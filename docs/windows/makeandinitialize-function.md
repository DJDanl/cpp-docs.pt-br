---
title: "Função MakeAndInitialize | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::MakeAndInitialize
dev_langs: C++
ms.assetid: 71ceeb12-d2a2-4317-b010-3dcde1b39467
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a97796fa9b13e95cc446f04d7338dd91350c1c26
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="makeandinitialize-function"></a>Função MakeAndInitialize
Inicializa a classe de tempo de execução do Windows especificada. Use esta função para criar uma instância de um componente que é definido no mesmo módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
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
typename TArg9> HRESULT MakeAndInitialize(_Outptr_result_nullonfailure_ I** ppvObject, TArg1 &&arg1, TArg2 &&arg2, TArg3 &&arg3, TArg4 &&arg4, TArg5 &&arg5, TArg6 &&arg6, TArg7 &&arg7, TArg8 &&arg8, TArg9 &&arg9) throw()  
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
 Um valor `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Consulte [como: instanciar componentes WRL diretamente](../windows/how-to-instantiate-wrl-components-directly.md) para conhecer as diferenças entre esta função e [Microsoft::WRL::Make](../windows/make-function.md)e para obter um exemplo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)