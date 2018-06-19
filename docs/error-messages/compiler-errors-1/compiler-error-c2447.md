---
title: C2447 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2447
dev_langs:
- C++
helpviewer_keywords:
- C2447
ms.assetid: d1bd6e9a-ee42-4510-ae5e-6b0378f7b931
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c2f0f72bc1278792853e1886e302f4410fdbe2d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33197033"
---
# <a name="compiler-error-c2447"></a>C2447 de erro do compilador
“{”: cabeçalho de função ausente (lista formal antiga?)  
  
 O compilador encontrou uma chave de abertura inesperada no escopo global. Na maioria dos casos, isso é causado por um cabeçalho malformado, uma declaração posicionada incorretamente ou por um ponto-e-vírgula disperso. Para resolver esse problema, verifique se a chave de abertura segue um cabeçalho de função formado corretamente e não é precedida de uma declaração ou um ponto-e-vírgula disperso.  
  
 Esse erro também pode ser causado por uma lista de argumentos formais em linguagem C antiga. Para resolver esse problema, refatore a lista de argumentos para usar um estilo moderno, ou seja, incluído entre parênteses.  
  
 O exemplo a seguir gera C2447:  
  
```  
// C2447.cpp  
int c;  
{}       // C2447  
```