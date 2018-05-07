---
title: RC4093 de aviso do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC4093
dev_langs:
- C++
helpviewer_keywords:
- RC4093
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e9cca3c2a139e1109746f3a690cfb3f31509a9fe
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-compiler-warning-rc4093"></a>Aviso RC4093 (compilador de recurso)
sem escape newline em constante de caractere no código inativo  
  
 A expressão de constante de um `#if`, `#elif`, **#ifdef**, ou **#ifndef** diretiva de pré-processamento é avaliada como zero, tornando o código que segue inativo. Em que o código inativo, um caractere de nova linha aparece dentro de um conjunto de aspas simples ou duplas.  
  
 Todo o texto até o próximo aspas duplas foi considerado dentro de uma constante de caractere.