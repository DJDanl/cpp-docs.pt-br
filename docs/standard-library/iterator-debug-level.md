---
title: "_ITERATOR_DEBUG_LEVEL | Microsoft Docs"
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
  - "_ITERATOR_DEBUG_LEVEL"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_ITERATOR_DEBUG_LEVEL"
ms.assetid: 718549cd-a9a9-4ab3-867b-aac00b321e67
caps.latest.revision: 6
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ITERATOR_DEBUG_LEVEL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A macro de `_ITERATOR_DEBUG_LEVEL` \(IDL\) substitui e combina a funcionalidade de macros de [\_SECURE\_SCL](../standard-library/secure-scl.md) \(LCC\) e de [\_HAS\_ITERATOR\_DEBUGGING](../Topic/_HAS_ITERATOR_DEBUGGING.md) \(ESCONDIDO\).  
  
## Valores macro  
 As tabelas a seguir resumem os valores para macros de `_SECURE_SCL` e de `_HAS_ITERATOR_DEBUGGING` e, finalmente como esses valores são substituídos pela macro de `_ITERATOR_DEBUG_LEVEL` .  
  
 A seção a seguir descreve os possíveis valores de LCC e macros de ESCONDIDOS.  
  
 SCL\=0  
 Desabilita verificaram iteradores.  
  
 SCL\=1  
 Habilita verificou iteradores.  
  
 HID\=0  
 Depuração de iterador de desabilita em construções de depuração.  
  
 HID\=1  
 Habilita a depuração de iterador em construções de depuração.  HID não pode ser habilitado em construções de versão.  
  
 A tabela a seguir descreve como os valores macro de IDL substituem a LCC e os valores macro ESCONDIDOS.  
  
|Modo de compilação|Novo macro|Macros antigos|Descrição|  
|------------------------|----------------|--------------------|---------------|  
|**Depurar**||||  
||IDL\=0|SCL\=0, HID\=0|Desabilita verificaram iteradores e desabilita a depuração de iterador.|  
||IDL\=1|SCL\=1, HID\=0|Verificou iteradores habilita e desabilita a depuração de iterador.|  
||IDL\=2 \(padrão\)|SCL\= \(não se aplica\), HID\=1|Por padrão, habilita a depuração de iterador; os iteradores verificados não são pertinentes.|  
|**Versão**||||  
||IDL\=0 \(padrão\)|SCL\=0|Por padrão, desabilita verificaram iteradores.|  
||IDL\=1|SCL\=1|Habilita verificado; iteradores a depuração de iterador não é relevante.|  
  
## Comentários  
 No modo de versão, um erro é emitido se você especificar. IDL\=2.  
  
 Como macros de `_SECURE_SCL` e de `_HAS_ITERATOR_DEBUGGING` dão suporte à funcionalidade semelhante, os usuários são frequentemente incertos que macro e macro valor a ser usado em uma situação específico.  Para resolver esse problema, recomendamos que você use apenas a macro de `_ITERATOR_DEBUG_LEVEL` .  
  
## Consulte também  
 [Bibliotecas seguras: Biblioteca Padrão C\+\+](../standard-library/safe-libraries-cpp-standard-library.md)