---
title: "Estrutura ArgTraits | Microsoft Docs"
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
  - "event/Microsoft::WRL::Details::ArgTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ArgTraits"
ms.assetid: 58ae4115-c1bc-48c8-b01b-e60554841c30
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ArgTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template<  
   typename TMemberFunction  
>  
struct ArgTraits;  
template<  
   typename TDelegateInterface  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(void)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3, TArg4)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3, TArg4, TArg5)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3, TArg4, TArg5, TArg6)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7)>;  
template<  
   typename TDelegateInterface,  
   typename TArg1,  
   typename TArg2,  
   typename TArg3,  
   typename TArg4,  
   typename TArg5,  
   typename TArg6,  
   typename TArg7,  
   typename TArg8  
>  
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8)>;  
template<  
   typename TDelegateInterface,  
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
struct ArgTraits<HRESULT (STDMETHODCALLTYPE TDelegateInterface::*)(TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8, TArg9)>;  
```  
  
#### Parâmetros  
 `TMemberFunction`  
 O parâmetro de Typename para uma estrutura de ArgTraits que não pode corresponder alguns invoca a assinatura do método.  
  
 `TDelegateInterface`  
 Uma interface de delegação.  
  
 `TArg1`  
 O tipo do primeiro argumento do método invocar.  
  
 `TArg2`  
 O tipo do segundo argumento do método invocar.  
  
 `TArg3`  
 O tipo do terceiro argumento do método invocar.  
  
 `TArg4`  
 O tipo de argumento de chamar o método.  
  
 `TArg5`  
 O tipo do quinto argumento do método invocar.  
  
 `TArg6`  
 O tipo do sexto argumento do método invocar.  
  
 `TArg7`  
 O tipo do sétimo argumento do método invocar.  
  
 `TArg8`  
 O tipo de argumento oitavo do método invocar.  
  
 `TArg9`  
 O tipo do nono argumento do método invocar.  
  
## Comentários  
 A estrutura de `ArgTraits` declara uma interface especificada de delegação e uma função de membro anônima que tenha um número especificado de parâmetros.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`Arg1Type`|O typedef para TArg1.|  
|`Arg2Type`|O typedef para TArg2.|  
|`Arg3Type`|O typedef para TArg3.|  
|`Arg4Type`|O typedef para TArg4.|  
|`Arg5Type`|O typedef para TArg5.|  
|`Arg6Type`|O typedef para TArg6.|  
|`Arg7Type`|O typedef para TArg7.|  
|`Arg8Type`|O typedef para TArg8.|  
|`Arg9Type`|O typedef para TArg9.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante ArgTraits::args](../windows/argtraits-args-constant.md)|Mantém a contagem do número de parâmetros no método invocar de uma interface de delegação.|  
  
## Hierarquia de Herança  
 `ArgTraits`  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)