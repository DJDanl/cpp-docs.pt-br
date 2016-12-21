---
title: "Fun&#231;&#227;o de retorno da chamada (Biblioteca em Tempo de Execu&#231;&#227;o C++ do Tempo de Execu&#231;&#227;o do Windows) | Microsoft Docs"
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
  - "event/Microsoft::WRL::Callback"
dev_langs: 
  - "C++"
ms.assetid: afb15d25-3230-44f7-b321-e17c54872943
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de retorno da chamada (Biblioteca em Tempo de Execu&#231;&#227;o C++ do Tempo de Execu&#231;&#227;o do Windows)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um objeto cuja função de membro é um método de retorno de chamada.  
  
## Sintaxe  
  
```  
template<  
   typename TDelegateInterface,  
   typename TCallback  
>  
ComPtr<TDelegateInterface> Callback(  
   TCallbackcallback  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)()  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3,  
   TArg4)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3,  
   TArg4,  
   TArg5)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3,  
   TArg4,  
   TArg5,  
   TArg6)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3,  
   TArg4,  
   TArg5,  
   TArg6,  
   TArg7)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7,  
   typename TArg8  
>  
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3,  
   TArg4,  
   TArg5,  
   TArg6,  
   TArg7,  
   TArg8)  
);  
template<  
   typename TDelegateInterface,  
   typename TCallbackObject,  
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
ComPtr<TDelegateInterface> Callback(  
   _In_ TCallbackObject *object,  
   _In_ HRESULT (TCallbackObject::* method)(TArg1,  
   TArg2,  
   TArg3,  
   TArg4,  
   TArg5,  
   TArg6,  
   TArg7,  
   TArg8,  
   TArg9)  
);  
```  
  
#### Parâmetros  
 `TDelegateInterface`  
 Um parâmetro do modelo que especifica a interface do representante a ser chamado quando um evento ocorrer.  
  
 `TCallback`  
 Um parâmetro de modelo que especifica o tipo de um objeto que representa um objeto e sua função de membro de retorno de chamada.  
  
 `TCallbackObject`  
 Um parâmetro do modelo que especifica o objeto cuja função de membro é o método a ser chamado quando um evento ocorrer.  
  
 `TArg1`  
 Um parâmetro de modelo que especifica o tipo do primeiro argumento do método de retorno de chamada.  
  
 `TArg2`  
 Um parâmetro de modelo que especifica o tipo do segundo argumento do método de retorno de chamada.  
  
 `TArg3`  
 Um parâmetro de modelo que especifica o tipo do terceiro argumento do método de retorno de chamada.  
  
 `TArg4`  
 Um parâmetro de modelo que especifica o tipo do quarto argumento do método de retorno de chamada.  
  
 `TArg5`  
 Um parâmetro de modelo que especifica o tipo do quinto argumento do método de retorno de chamada.  
  
 `TArg6`  
 Um parâmetro de modelo que especifica o tipo do sexto argumento do método de retorno de chamada.  
  
 `TArg7`  
 Um parâmetro de modelo que especifica o tipo do sétimo argumento do método de retorno de chamada.  
  
 `TArg8`  
 Um parâmetro de modelo que especifica o tipo do oitavo argumento do método de retorno de chamada.  
  
 `TArg9`  
 Um parâmetro de modelo que especifica o tipo do nono argumento do método de retorno de chamada.  
  
 `callback`  
 Um objeto que representa o objeto de retorno de chamada e sua função de membro.  
  
 `object`  
 O objeto cuja função de membro é chamada quando um evento ocorre.  
  
 `method`  
 A função de membro a ser chamada quando um evento ocorrer.  
  
## Valor de retorno  
 Um objeto cuja função de membro é o método de retorno especificado.  
  
## Comentários  
 A base de um objeto representante deve ser IUnknown, não IInspectable.  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)