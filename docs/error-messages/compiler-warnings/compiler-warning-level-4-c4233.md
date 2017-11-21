---
title: "Compilador (nível 4) de aviso C4233 | Microsoft Docs"
ms.custom: 
ms.date: 10/25/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4233
dev_langs: C++
helpviewer_keywords: C4233
ms.assetid: 9aa51fc6-8ef3-43b5-bafb-c9333cf60de3
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 16e32686451ba7ce0c9a633878f1158a8457163a
ms.sourcegitcommit: 69632887f7a85f4841c49b4c1353d3144927a52c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/11/2017
---
# <a name="compiler-warning-level-4-c4233"></a>Compilador C4233 de aviso (nível 4)

> extensão não padrão usada: '*palavra-chave*' palavra-chave só tem suportada em C++, não em C

O compilador compilados seu código-fonte como C em vez de C++, e você usou uma palavra-chave que só é válida em C++. O compilador compila o arquivo de origem como C, se a extensão do arquivo de origem é. c ou se você usar [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md).

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema do aviso de nível 4 C4233, adicione esta linha ao seu arquivo de código de origem:

```cpp
#pragma warning(4:4233)
```
