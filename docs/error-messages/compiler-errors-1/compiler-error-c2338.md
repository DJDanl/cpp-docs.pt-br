---
title: C2338 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2338
dev_langs:
- C++
helpviewer_keywords:
- C2338
ms.assetid: 49bba575-1de4-4963-86c6-ce3226a2ba51
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0171654bde5b056a7e6695ea5fbbe84edb62f83
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
