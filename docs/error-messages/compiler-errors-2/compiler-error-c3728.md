---
title: C3728 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3728
dev_langs: C++
helpviewer_keywords: C3728
ms.assetid: 6b510cb1-887f-4fcd-9a1f-3bb720417ed1
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d20a0772a38dadc5956e1d174a23ecb0a8593647
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3728"></a>C3728 de erro do compilador
'event': evento não tem um método raise  
  
 Os metadados são criados com um idioma, como c#, que não permitem que um evento deve ser gerado de fora da classe na qual ela foi definida, foi incluído com o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva e um programa do Visual C++ usando a programação de CLR tentou Gere o evento.  
  
 Para gerar um evento em um programa desenvolvido em uma linguagem como c#, a classe que contém o evento deve também definir um método público que gera o evento.