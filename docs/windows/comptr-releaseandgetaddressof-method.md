---
title: "M&#233;todo ComPtr::ReleaseAndGetAddressOf | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::ReleaseAndGetAddressOf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ReleaseAndGetAddressOf"
ms.assetid: 3751dcb4-d50e-432c-89e4-e736be34d434
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ComPtr::ReleaseAndGetAddressOf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Libera a interface associada a este ComPtr e recupera o endereço do membro de dados de [ptr\_](../windows/comptr-ptr-data-member.md) , que contém um ponteiro para a interface que foi liberada.  
  
## Sintaxe  
  
```  
T** ReleaseAndGetAddressOf();  
```  
  
## Valor de retorno  
 O endereço do membro de dados de [ptr\_](../windows/comptr-ptr-data-member.md) desse ComPtr.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)   
 [Membro de dados ComPtr::ptr\_](../windows/comptr-ptr-data-member.md)