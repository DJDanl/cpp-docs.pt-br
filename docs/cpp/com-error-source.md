---
title: "_com_error::Source | Microsoft Docs"
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
  - "_com_error.Source"
  - "_com_error::Source"
  - "source"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Source"
ms.assetid: 55353741-fabc-4b0c-9787-b5a69bb189f2
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::Source
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função **IErrorInfo::GetSource**.  
  
## Sintaxe  
  
```  
  
_bstr_t Source() const;  
  
```  
  
## Valor de retorno  
 Retorna o resultado de **IErrorInfo::GetSource** para o objeto **IErrorInfo** registrado no objeto `_com_error`.  O BSTR resultante é encapsulado em um objeto `_bstr_t`.  Se nenhum **IErrorInfo** estiver registrado, retornará um `_bstr_t` vazio.  
  
## Comentários  
 Qualquer falha ao chamar o método **IErrorInfo::GetSource** é ignorada.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)