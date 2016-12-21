---
title: "Fun&#231;&#227;o ActivationFactoryCallback | Microsoft Docs"
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
  - "module/Microsoft::WRL::Details::ActivationFactoryCallback"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função ActivationFactoryCallback"
ms.assetid: dd40c79b-1273-4f2a-8c24-ae9926fb4fd9
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o ActivationFactoryCallback
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
inline HRESULT STDAPICALLTYPE ActivationFactoryCallback(  
   HSTRING activationId,  
   IActivationFactory **ppFactory  
);  
```  
  
#### Parâmetros  
 `activationId`  
 Identificador para uma cadeia de caracteres que especifica um nome de classe de tempo de execução.  
  
 `ppFactory`  
 Quando esta operação concluir, uma fábrica de ativação que corresponde ao parâmetro `activationId`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que descreve a falha.  A falha provável HRESULTs é CLASS\_E\_CLASSNOTAVAILABLE e E\_INVALIDARG.  
  
## Comentários  
 Obtém a fábrica de ativação para a ID especificada de ativação  
  
 Tempo de Execução do chama esta função de retorno de chamada para solicitar um objeto especificado pelo nome da classe de tempo de execução.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)