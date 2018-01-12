---
title: RC4093 de aviso do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: RC4093
dev_langs: C++
helpviewer_keywords: RC4093
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4d21cbba379e72675b8957be58dc712b83673947
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-warning-rc4093"></a>Aviso RC4093 (compilador de recurso)
sem escape newline em constante de caractere no código inativo  
  
 A expressão de constante de um `#if`, `#elif`, **#ifdef**, ou **#ifndef** diretiva de pré-processamento é avaliada como zero, tornando o código que segue inativo. Em que o código inativo, um caractere de nova linha aparece dentro de um conjunto de aspas simples ou duplas.  
  
 Todo o texto até o próximo aspas duplas foi considerado dentro de uma constante de caractere.