---
title: "Fun&#231;&#227;o de retorno de chamada para CDC::GrayString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "Callback Function for CDC::GrayString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções de retorno de chamada, para CDC::GrayString"
ms.assetid: 5217e183-df48-426b-931b-6245022ca36f
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de retorno de chamada para CDC::GrayString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

*OutputFunc* é um espaço reservado para o nome da função de aplicativo fornecido de retorno de chamada.  
  
## Sintaxe  
  
```  
  
      BOOL CALLBACK EXPORT OutputFunc(   
   HDC hDC,   
   LPARAM lpData,   
   int nCount    
);  
```  
  
#### Parâmetros  
 `hDC`  
 Identifica um contexto do dispositivo de memória com pelo menos um bitmap de largura e altura especificada por `nWidth` e por `nHeight` a `GrayString`.  
  
 `lpData`  
 Aponta para a cadeia de caracteres a ser desenhada.  
  
 `nCount`  
 Especifica o número de caracteres à saída.  
  
## Valor de retorno  
 O valor de retorno de função de retorno de chamada deve ser **Verdadeiro** para indicar êxito; se não for **Falso**.  
  
## Comentários  
 A função de retorno de chamada*OutputFunc*\(\) deve chamar uma imagem em relação às coordenadas \(0,0\) ao invés de \(*x*, *y\)*.  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GrayString](../Topic/CDC::GrayString.md)