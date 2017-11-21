---
title: "Compilador (nível 1) de aviso C4124 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4124
dev_langs: C++
helpviewer_keywords: C4124
ms.assetid: c08c3a65-9584-47a1-a147-44f00c4b230e
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3de13cb50444530fc0917330771b693f60a7e5f5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4124"></a>Compilador C4124 de aviso (nível 1)
fastcall com verificação de pilha é ineficiente  
  
 O `__fastcall` palavra-chave foi usado com verificação de pilha habilitado.  
  
 O `__fastcall` convenção gera código mais rápido, mas a verificação de pilha faz com que o código mais lento. Ao usar `__fastcall`, desativar a verificação de pilha com o **check_stack** pragma ou /Gs.  
  
 Esse aviso é emitido apenas para a primeira função declarada sob essas condições.