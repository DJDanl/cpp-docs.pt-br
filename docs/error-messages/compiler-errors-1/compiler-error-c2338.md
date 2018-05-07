---
title: C2338 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2338
dev_langs:
- C++
helpviewer_keywords:
- C2338
ms.assetid: 49bba575-1de4-4963-86c6-ce3226a2ba51
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 156074f20517c1d2e2f4fdb4ac5c54d6cf014276
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2338"></a>C2338 de erro do compilador  
  
> *Mensagem de erro*  
  
Esse erro pode ser causado por um `static_assert` erro durante a compilação. A mensagem é fornecida pelo `static_assert` parâmetros.   
  
Essa mensagem de erro também pode ser gerada por provedores externos para o compilador. Na maioria dos casos, esses erros são relatados por um atributo DLL do provedor, como ATLPROV. Algumas formas comuns dessa mensagem incluem:

> '*atributo*' Atl atributo provedor: erro ATL*número* *mensagem*  
  
> Uso incorreto do atributo '*atributo*'
  
> '*uso*': formato incorreto para o atributo 'uso'  
  
Esses erros geralmente são irrecuperáveis e podem ser seguidos por um erro do compilador fatal.  
  
Para corrigir esses problemas, corrija o uso do atributo. Por exemplo, em alguns casos, os parâmetros de atributo devem ser declarados antes que possam ser usados. Se um número de erro ATL for fornecido, consulte a documentação para esse erro para obter informações mais específicas.  
