---
title: "M&#233;todo WeakRef::CopyTo | Microsoft Docs"
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
  - "client/Microsoft::WRL::WeakRef::CopyTo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CopyTo"
ms.assetid: f83de6da-b3d4-41a6-9845-cd725ecf3b75
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo WeakRef::CopyTo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.  
  
## Sintaxe  
  
```  
HRESULT CopyTo(  
   REFIID riid,  
   _Deref_out_ IInspectable** ptr  
);  
  
template<  
   typename U  
>  
HRESULT CopyTo(  
   _Deref_out_ U** ptr  
);  
  
HRESULT CopyTo(  
   _Deref_out_ IWeakReference** ptr  
);  
```  
  
#### Parâmetros  
 `U`  
 Ponteiro de uma interface IInspectable. Um erro será emitido se `U` não é derivado de IInspectable.  
  
 `riid`  
 Uma ID de interface. Um erro será emitido se `riid` não é derivado de **IWeakReference**.  
  
 `ptr`  
 Um ponteiro indireto duplamente IInspectable ou IWeakReference.  
  
## Valor de retorno  
 S\_OK se for bem\-sucedida; Caso contrário, um HRESULT que descreve a falha. Para obter mais informações, consulte comentários.  
  
## Comentários  
 Um valor de retorno de S\_OK significa que a operação foi bem\-sucedida, mas não indica se a referência fraca foi resolvida para uma referência forte. Se for retornado S\_OK, testar esse parâmetro `p` é uma ótima referência; ou seja, o parâmetro `p` não é igual a `nullptr`.  
  
 A partir do SDK do Windows 10, esse método não define a instância de WeakRef `nullptr` se não foi possível obter a referência fraca, portanto você deve evitar erro de verificação de código que verifica o WeakRef para `nullptr`. Em vez disso, verifique `ptr` para `nullptr`.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)