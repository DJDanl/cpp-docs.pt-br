---
title: "Estrutura PAINTSTRUCT | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "PAINTSTRUCT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura PAINTSTRUCT"
ms.assetid: 81ce4993-3e89-43b2-8c98-7946f1314d24
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura PAINTSTRUCT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `PAINTSTRUCT` contém informações que pode ser usada para pintar a área do cliente de uma janela.  
  
## Sintaxe  
  
```  
  
      typedef struct tagPAINTSTRUCT {  
   HDC hdc;  
   BOOL fErase;  
   RECT rcPaint;  
   BOOL fRestore;  
   BOOL fIncUpdate;  
   BYTE rgbReserved[16];  
} PAINTSTRUCT;  
```  
  
#### Parâmetros  
 *hdc*  
 Identifica o contexto de exibição a ser usado pintando.  
  
 *fErase*  
 Especifica se o plano de fundo precisa ser redesenhado.  Não será 0 se o aplicativo redesenhar o plano de fundo.  O aplicativo é responsável para desenhar o plano de fundo o se uma classe do windows é criada sem uma escova em segundo plano \(consulte a descrição do membro de **hbrBackground** da estrutura de [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]\).  
  
 *rcPaint*  
 Especifica os cantos direitos à esquerda e inferior superiores do retângulo em que paint são solicitadas.  
  
 *fRestore*  
 Membro reservado.  É usado internamente pelo windows.  
  
 *fIncUpdate*  
 Membro reservado.  É usado internamente pelo windows.  
  
 *rgbReserved \[16\]*  
 Membro reservado.  Um bloco de memória reservado usado internamente pelo windows.  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CPaintDC::m\_ps](../Topic/CPaintDC::m_ps.md)