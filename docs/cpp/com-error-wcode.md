---
title: "_com_error::WCode | Microsoft Docs"
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
  - "_com_error.WCode"
  - "_com_error::WCode"
  - "WCode"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método WCode"
ms.assetid: f3b21852-f8ea-4e43-bff1-11c2d35454c4
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::WCode
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Recupera o código de erro de 16 bits mapeado para o `HRESULT` encapsulado.  
  
## Sintaxe  
  
```  
  
WORD WCode ( ) const throw( );  
  
```  
  
## Valor de retorno  
 Se `HRESULT` estiver dentro do intervalo 0x80040200 a 0x8004FFFF, o método **WCode** retorna `HRESULT` menos 0x80040200; caso contrário, ele retorna zero.  
  
## Comentários  
 O método **WCode** é usado para desfazer um mapeamento que acontece no código de suporte COM.  O wrapper de um método ou propriedade **dispinterface** chama uma rotina de suporte que empacota os argumentos e chama **IDispatch::Invoke**.  No retorno, se uma falha `HRESULT` of `DISP_E_EXCEPTION` é retornada, as informações de erro são recuperadas da estrutura **EXCEPINFO** passada a **IDispatch::Invoke**.  O código de erro pode ser um valor de 16 bits armazenado no membro `wCode` da estrutura **EXCEPINFO** ou um valor de 32 bits completo no membro **scode** da estrutura **EXCEPINFO**.  Se `wCode` de 16 bits for retornado, deve primeiramente ser mapeado para uma falha de 32 bits `HRESULT`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_com\_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)   
 [\_com\_error::WCodeToHRESULT](../Topic/_com_error::WCodeToHRESULT.md)   
 [Classe \_com\_error](../cpp/com-error-class.md)