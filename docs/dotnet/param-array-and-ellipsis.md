---
title: Matriz de parâmetros e reticências | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- function overloading, argument matching
ms.assetid: 492e3f6c-1c4c-4e0c-a358-72f2d39c30be
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2caf6415fdbceb506b736e209c6e7e384b567c5a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384371"
---
# <a name="param-array-and-ellipsis"></a>Matriz de parâmetros e reticências

Precedência da matriz param para resolver as chamadas de função sobrecarregada foi alterado de extensões gerenciadas para C++ para Visual C++.

No Managed Extensions e a nova sintaxe, não há nenhum suporte explícito para a matriz de parâmetros que dão suporte a c# e Visual Basic. Em vez disso, um sinalizadores uma matriz comum com um atributo, da seguinte maneira:

```
void Trace1( String* format, [ParamArray]Object* args[] );
void Trace2( String* format, Object* args[] );
```

Embora esses dois têm a mesma aparência a `ParamArray` atributo marcas isso para c# ou em outras linguagens CLR como uma matriz, levando a um número variável de elementos com cada invocação. A alteração no comportamento em programas entre extensões gerenciadas e a nova sintaxe é na resolução de uma função sobrecarregada definida no qual uma instância declara uma elipse e um segundo declara um `ParamArray` atributo, como no exemplo a seguir fornecido pelo Artur Laksberg.

```
int fx(...); // 1
int fx( [ParamArray] Int32[] ); // 2
```

Nas extensões gerenciadas, no botão de reticências foi atribuído a precedência sobre o atributo que é razoável, pois o atributo não é um aspecto formal da linguagem. No entanto, na nova sintaxe, agora há suporte para a matriz de parâmetros diretamente dentro da linguagem e ela tem precedência sobre o botão de reticências porque ele é mais fortemente tipado. Assim, no Managed Extensions, a chamada

```
fx( 1, 2 );
```

Resolve `fx(...)` enquanto estiver na nova sintaxe, ele resolve para o `ParamArray` instância. Sobre a possibilidade de que o comportamento do seu programa depende da invocação da instância do botão de reticências em relação ao `ParamArray`, você precisará modificar a assinatura ou a chamada.

## <a name="see-also"></a>Consulte também

[Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)