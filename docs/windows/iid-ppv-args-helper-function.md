---
title: "Fun&#231;&#227;o IID_PPV_ARGS_Helper | Microsoft Docs"
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
  - "client/IID_PPV_ARGS_Helper"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função IID_PPV_ARGS_Helper"
ms.assetid: afee9b23-8df1-4575-903f-e9ba748418f0
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o IID_PPV_ARGS_Helper
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Verifica se o tipo de argumento especificado deriva da interface de `IUnknown` .  
  
> [!IMPORTANT]
>  Essa especialização de modelo da suporte à infraestrutura de WRL e não se destina a ser usada diretamente no seu código.  Use. [IID\_PPV\_ARGS](http://msdn.microsoft.com/library/windows/desktop/ee330727.aspx)  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
void** IID_PPV_ARGS_Helper(  
   _Inout_ Microsoft::WRL::Details::ComPtrRef<T> pp  
);  
```  
  
#### Parâmetros  
 `T`  
 O tipo de argumento `pp`.  
  
 `pp`  
 Um ponteiro dois indireto.  
  
## Valor de retorno  
 O argumento `pp` é convertido em um ponteiro\-à\-um\- ponteiro para `void`.  
  
## Comentários  
 Um erro de tempo de compilação será gerado se o parâmetro `T` do modelo não se deriva de `IUnknown`.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
## Consulte também  
 [Reference \(Windows Runtime Library\)](http://msdn.microsoft.com/pt-br/00000000-0000-0000-0000-000000000000)