---
title: "M&#233;todo FtmBase::DisconnectObject | Microsoft Docs"
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
  - "ftm/Microsoft::WRL::FtmBase::DisconnectObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método DisconnectObject"
ms.assetid: 33253eec-3a65-4e72-8525-0249245a4790
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo FtmBase::DisconnectObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Libera forçadamente todas as conexões externas a um objeto.  O servidor do objeto chama a implementação do objeto desse método antes de desligar.  
  
## Sintaxe  
  
```  
STDMETHODIMP DisconnectObject(  
   __in DWORD dwReserved  
) override;  
```  
  
#### Parâmetros  
 `dwReserved`  
 Reservado para uso futuro; devem ser zero.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)