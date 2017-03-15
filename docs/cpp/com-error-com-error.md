---
title: "_com_error::_com_error | Microsoft Docs"
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
  - "_com_error._com_error"
  - "_com_error::_com_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método _com_error"
ms.assetid: 0a69e46c-caab-49ef-b091-eee401253ce6
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::_com_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Constrói um objeto `_com_error`.  
  
## Sintaxe  
  
```  
  
      _com_error(  
   HRESULT hr,  
   IErrorInfo* perrinfo = NULL,  
   bool fAddRef=false  
) throw( );  
_com_error(  
   const _com_error& that   
) throw( );  
```  
  
#### Parâmetros  
 `hr`  
 Informações de `HRESULT`.  
  
 `perrinfo`  
 Objeto **IErrorInfo**.  
  
 **bool fAddRef\=false**  
 Faz com que o construtor chame AddRef em uma interface **IErrorInfo** não nula.  Isso oferece a contagem de referência correta no caso comum onde a propriedade da interface é passada para o objeto `_com_error`, como:  
  
```  
throw _com_error(hr, perrinfo);  
```  
  
 Se você não quiser que seu código transfira a propriedade para o objeto `_com_error`, e `AddRef` for necessário para deslocar **Release** no destruidor `_com_error`, construa o objeto desta forma:  
  
```  
_com_error err(hr, perrinfo, true);  
```  
  
 `that`  
 Um objeto `_com_error` existente.  
  
## Comentários  
 O primeiro construtor cria um novo objeto dado um `HRESULT` e um objeto **IErrorInfo** opcional.  O segundo cria uma cópia de um objeto `_com_error` existente.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)