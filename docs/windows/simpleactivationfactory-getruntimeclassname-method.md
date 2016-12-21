---
title: "M&#233;todo SimpleActivationFactory::GetRuntimeClassName | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::SimpleActivationFactory::GetRuntimeClassName"
dev_langs: 
  - "C++"
ms.assetid: 3aa07487-9a42-46f8-8893-37ba6315e50b
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SimpleActivationFactory::GetRuntimeClassName
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o nome da classe de tempo de execução de uma instância da classe especificada pelo parâmetro do modelo da classe de `Base` .  
  
## Sintaxe  
  
```  
STDMETHOD(  
   GetRuntimeClassName  
)(_Out_ HSTRING* runtimeName);  
```  
  
#### Parâmetros  
 `runtimeName`  
 Quando esta operação concluir, o nome da classe de tempo de execução.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Se o \_\_WRL\_STRICT é definido, um erro é emitido declarar se a classe especificada pelo parâmetro do modelo da classe de `Base` não é derivada de [RuntimeClass](../windows/runtimeclass-class.md), ou não configurado com o valor de enumeração WinRt ou de WinRtClassicComMix [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)