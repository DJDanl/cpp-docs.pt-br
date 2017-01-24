---
title: "Fun&#231;&#227;o de retorno de chamada para CDC::SetAbortProc | Microsoft Docs"
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
  - "Callback Function for CDC::SetAbortProc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções de retorno de chamada, para CDC::SetAbortProc"
ms.assetid: daa36d5d-15de-40fc-8d37-a865d06c4710
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de retorno de chamada para CDC::SetAbortProc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O nome *AbortFunc* é um espaço reservado para o nome da função de aplicativo fornecido.  
  
## Sintaxe  
  
```  
  
      BOOL CALLBACK EXPORT AbortFunc(   
   HDC hPr,   
   int code    
);  
```  
  
#### Parâmetros  
 *hPr*  
 Identifica o contexto do dispositivo.  
  
 `code`  
 Especifica se um erro ocorreu.  Será 0 se nenhum erro ocorreu.  É **SP\_OUTOFDISK** se o gerenciador de cópia está fora de espaço em disco e mais espaço em disco se tornará disponível se o aplicativo espera.  Se `code` é **SP\_OUTOFDISK**, o aplicativo não precisa cancelar o trabalho de cópia.  Se não fizer, deve produzir ao gerenciador de cópia chamando a função do windows de **PeekMessage** ou de **GetMessage** .  
  
## Valor de retorno  
 O valor de retorno da função de manipulador aborto\- for diferente de zero se o trabalho de cópia é continuar, e 0 se for cancelado.  
  
## Comentários  
 O nome real deve ser exportado como descrito na seção comentários de [CDC::SetAbortProc](../Topic/CDC::SetAbortProc.md).  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::SetAbortProc](../Topic/CDC::SetAbortProc.md)