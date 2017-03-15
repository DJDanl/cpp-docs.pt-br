---
title: "M&#233;todo SimpleActivationFactory::ActivateInstance | Microsoft Docs"
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
  - "module/Microsoft::WRL::SimpleActivationFactory::ActivateInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ActivateInstance"
ms.assetid: 4f836e51-5a6c-4bad-b871-9f25199298b4
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SimpleActivationFactory::ActivateInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma instância da interface especificada.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   ActivateInstance  
)(_Deref_out_ IInspectable **ppvObject);  
```  
  
#### Parâmetros  
 `ppvObject`  
 Quando esta operação concluir, ponteiro para uma instância do objeto especificado pelo parâmetro do modelo da classe de `Base` .  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Se o \_\_WRL\_STRICT é definido, um erro é emitido declarar se a classe base especificada no parâmetro do modelo da classe não é derivada de [RuntimeClass](../windows/runtimeclass-class.md), ou não configurado com o valor de enumeração WinRt ou de WinRtClassicComMix [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)