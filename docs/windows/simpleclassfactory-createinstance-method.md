---
title: "M&#233;todo SimpleClassFactory::CreateInstance | Microsoft Docs"
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
  - "module/Microsoft::WRL::SimpleClassFactory::CreateInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateInstance"
ms.assetid: 17b7947a-2608-49d9-b730-fef76501c9bc
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SimpleClassFactory::CreateInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma instância da interface especificada.  
  
## Sintaxe  
  
```  
  
STDMETHOD(  
   CreateInstance  
)  
   (_Inout_opt_ IUnknown* pUnkOuter,   
   REFIID riid,   
   _Deref_out_ void** ppvObject);  
```  
  
#### Parâmetros  
 `pUnkOuter`  
 Deve ser `nullptr`; caso contrário, o valor de retorno será CLASS\_E\_NOAGGREGATION.  
  
 SimpleClassFactory não oferece suporte à agregação.  Se a agregação foi suporte e o objeto que está sendo criado fazia parte de uma agregação, `pUnkOuter` seria um ponteiro para a interface IUnknown de controle de agregação.  
  
 `riid`  
 ID da interface do objeto a ser criado.  
  
 `ppvObject`  
 Quando esta operação for concluída, o ponteiro para uma instância do objeto especificado pelo parâmetro de `riid` .  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Se o \_\_WRL\_STRICT é definido, um erro é emitido declarar se a classe base especificada no parâmetro do modelo da classe não é derivada de [RuntimeClass](../windows/runtimeclass-class.md), ou não configurado com o valor de enumeração ClassicCom ou de WinRtClassicComMix [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe SimpleClassFactory](../windows/simpleclassfactory-class.md)