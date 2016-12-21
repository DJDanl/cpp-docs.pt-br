---
title: "M&#233;todo ComPtr::CopyTo | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::CopyTo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CopyTo"
ms.assetid: 8801bc49-6db4-4393-a55f-a701ae3b8718
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ComPtr::CopyTo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Copia o atual ou para a interface especificada associada a este ComPtr especificado para o ponteiro.  
  
## Sintaxe  
  
```  
HRESULT CopyTo(  
   _Deref_out_ InterfaceType** ptr  
);  
  
HRESULT CopyTo(  
   REFIID riid,  
   _Deref_out_ void** ptr  
) const;  
template<  
   typename U  
>  
  
HRESULT CopyTo(  
   _Deref_out_ U** ptr  
) const;  
```  
  
#### Parâmetros  
 `U`  
 Um nome de tipo.  
  
 `ptr`  
 Quando esta operação concluir, um ponteiro para a interface solicitada.  
  
 `riid`  
 Uma ID de interface  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que indica como a operação implícita de QueryInterface falhou.  
  
## Comentários  
 A primeira função retorna uma cópia de um ponteiro para a interface associada a este ComPtr.  Esta função sempre retorna S\_OK.  
  
 A segunda função executa uma operação de QueryInterface na interface associada a este ComPtr para a interface especificada pelo parâmetro de `riid` .  
  
 A terceira função executa uma operação de QueryInterface na interface associada a este ComPtr para a interface subjacente do parâmetro de `U` .  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)