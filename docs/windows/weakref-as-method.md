---
title: "M&#233;todo WeakRef::As | Microsoft Docs"
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
  - "client/Microsoft::WRL::WeakRef::As"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método As"
ms.assetid: 7173da62-b3fe-44d6-aea4-1aa97e69b221
caps.latest.revision: 6
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo WeakRef::As
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o parâmetro de ponteiro ComPtr especificado para representar a interface especificada.  
  
## Sintaxe  
  
```  
  
template<  
   typename U  
>  
HRESULT As(  
   _Out_ ComPtr<U>* ptr  
);  
  
template<  
   typename U  
>  
HRESULT As(  
   _Out_ Details::ComPtrRef<ComPtr<U>> ptr  
);  
```  
  
#### Parâmetros  
 `U`  
 Uma ID de interface.  
  
 `ptr`  
 Quando essa operação for concluída, um objeto que representa o parâmetro `U`.  
  
## Valor de retorno  
  
-   S\_OK se essa operação for bem\-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou, e `ptr` é definido como `nullptr`.  
  
-   S\_OK se essa operação for bem\-sucedida, mas o objeto WeakRef atual já foi liberado. Parâmetro `ptr` é definido como `nullptr`.  
  
-   S\_OK se essa operação for bem\-sucedida, mas o objeto WeakRef atual não é derivado do parâmetro `U`. Parâmetro `ptr` é definido como `nullptr`.  
  
## Comentários  
 Um erro será emitido se parâmetro `U` é IWeakReference ou não é derivado de IInspectable.  
  
 O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo é uma especialização de auxiliar interno, que oferece suporte a recursos da linguagem C\+\+, como o [automático](../cpp/auto-cpp.md) palavra\-chave de dedução de tipo.  
  
 A partir do SDK do Windows 10, esse método não define a instância de WeakRef `nullptr` se não foi possível obter a referência fraca, portanto você deve evitar código de verificação de erro que verifica o WeakRef para `nullptr`. Em vez disso, verifique o HRESULT retornado para determinar se o método foi bem\-sucedido, ou marque `ptr` para `nullptr`.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)