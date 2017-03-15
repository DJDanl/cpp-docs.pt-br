---
title: RC4093 de aviso do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC4093
dev_langs:
- C++
helpviewer_keywords:
- RC4093
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 35edfceafcaa8f9e6ebc3b8d68282f5a4ccc68cd
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-warning-rc4093"></a>Aviso RC4093 (compilador de recurso)
sem escape newline em constante de caractere no código inativo  
  
 A expressão constante de um `#if`, `#elif`, **#ifdef**, ou **#ifndef** diretiva de pré-processador avaliada como zero, tornando o código que segue inativo. Dentro daquele código inativo, um caractere de nova linha aparece dentro de um conjunto de aspas simples ou duplas.  
  
 Todo o texto até a próxima marca de aspas duplas foi considerado dentro de uma constante de caractere.
