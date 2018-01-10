---
title: "Matriz de parâmetros e reticências | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: function overloading, argument matching
ms.assetid: 492e3f6c-1c4c-4e0c-a358-72f2d39c30be
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f6d256fd48d8c9f206619e6baa9a50a0278d30c3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="param-array-and-ellipsis"></a>Matriz de parâmetros e reticências
Precedência da matriz de parâmetro para a resolução de chamadas de função sobrecarregada foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Em extensões gerenciadas e a nova sintaxe, não há nenhum suporte explícito para a matriz de parâmetro c# e Visual Basic oferecem suporte ao. Em vez disso, um sinalizadores uma matriz simples com um atributo, da seguinte maneira:  
  
```  
void Trace1( String* format, [ParamArray]Object* args[] );  
void Trace2( String* format, Object* args[] );  
```  
  
 Embora ambos têm a mesma aparência o `ParamArray` atributo marcas isso para c# ou outras linguagens CLR como uma matriz de colocar um número variável de elementos com cada chamada. A alteração no comportamento em programas entre extensões gerenciadas e a nova sintaxe é na resolução de uma função sobrecarregada definida no qual uma instância declara um botão de reticências e um segundo declara um `ParamArray` atributo, como no exemplo a seguir fornecido pelo Artur Laksberg.  
  
```  
int fx(...); // 1  
int fx( [ParamArray] Int32[] ); // 2  
```  
  
 Em extensões gerenciadas, no botão de reticências foi atribuído a precedência sobre o atributo que é razoável, já que o atributo não é um aspecto formal do idioma. No entanto, a nova sintaxe, agora há suporte para a matriz de parâmetro diretamente no idioma e ele tem precedência sobre a elipse porque ele é mais fortemente tipado. Assim, no Managed Extensions, a chamada  
  
```  
fx( 1, 2 );  
```  
  
 resolve para `fx(...)` enquanto a nova sintaxe, ele resolve para o `ParamArray` instância. Sobre a possibilidade de que o comportamento do seu programa depende da invocação da instância reticências em relação a `ParamArray`, você precisará modificar a assinatura ou a chamada.  
  
## <a name="see-also"></a>Consulte também  
 [Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)