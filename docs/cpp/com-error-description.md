---
title: "_com_error::Description | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_error.Description"
  - "_com_error::Description"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Description"
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::Description
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função **IErrorInfo::GetDescription**.  
  
## Sintaxe  
  
```  
  
_bstr_t Description( ) const;  
  
```  
  
## Valor de retorno  
 Retorna o resultado de **IErrorInfo::GetDescription** para o objeto **IErrorInfo** registrado no objeto `_com_error`.  O `BSTR` resultante é encapsulado em um objeto `_bstr_t`.  Se nenhum **IErrorInfo** estiver registrado, retornará um `_bstr_t` vazio.  
  
## Comentários  
 Chama a função **IErrorInfo::GetDescription**  e recupera **IErrorInfo** registrado no objeto `_com_error`.  Qualquer falha ao chamar o método **IErrorInfo::GetDescription** é ignorada.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)