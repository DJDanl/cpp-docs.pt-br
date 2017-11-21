---
title: C3552 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3552
dev_langs: C++
helpviewer_keywords: C3552
ms.assetid: 83401524-1bf1-44c0-8aca-a6eb35c4224c
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 54526c39a928cc534ba815ef8fda802db85f4020
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3552"></a>C3552 de erro do compilador
'typename': um tipo de retorno especificado tardia não pode conter 'auto'  
  
 Se você usar o `auto` palavra-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno tardia especificado. No entanto, você não pode usar outro `auto` palavra-chave para especificar o tipo de retorno de tardia especificado. Por exemplo, o fragmento de código a seguir gera erro C3552.  
  
 `auto myFunction->auto; // C3552`