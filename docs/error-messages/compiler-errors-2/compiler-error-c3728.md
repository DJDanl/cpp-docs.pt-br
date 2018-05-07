---
title: C3728 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3728
dev_langs:
- C++
helpviewer_keywords:
- C3728
ms.assetid: 6b510cb1-887f-4fcd-9a1f-3bb720417ed1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bae204db616db9e7d7e04cfd62d53374b0793aa9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3728"></a>C3728 de erro do compilador
'event': evento não tem um método raise  
  
 Os metadados são criados com um idioma, como c#, que não permitem que um evento deve ser gerado de fora da classe na qual ela foi definida, foi incluído com o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva e um programa do Visual C++ usando a programação de CLR tentou Gere o evento.  
  
 Para gerar um evento em um programa desenvolvido em uma linguagem como c#, a classe que contém o evento deve também definir um método público que gera o evento.