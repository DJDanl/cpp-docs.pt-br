---
title: nullptr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: nullptr_cpp
dev_langs: C++
helpviewer_keywords: nullptr keyword [C++]
ms.assetid: e9d80ea6-2506-4eb5-b47b-2349df085832
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e9d032653b004e0960922efee59924ab120793fd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nullptr"></a>nullptr
Designa uma constante do ponteiro nulo do tipo `std::nullptr_t`, que é convertido em qualquer tipo bruto de ponteiro.  Embora você possa usar a palavra-chave `nullptr` sem incluir nenhum cabeçalho, se o código dela usar o tipo `std::nullptr_t`, você deve defini-lo incluindo o cabeçalho `<cstddef>`.  
  
> [!NOTE]
>  A palavra-chave `nullptr` também é definida em C++/CLI para os aplicativos de código gerenciado e não é intercambiável com a palavra-chave do padrão ISO C++. Se seu código pode ser compilado usando o [/clr](../build/reference/clr-common-language-runtime-compilation.md) , em seguida, use a opção de compilador, que tem como alvo o código gerenciado, `__nullptr` em qualquer linha de código em que você deve assegurar que o compilador usa a interpretação de C++ nativo. Para obter mais informações, consulte [nullptr](../windows/nullptr-cpp-component-extensions.md).  
  
## <a name="remarks"></a>Comentários  
 Evite usar `NULL` ou zero (`0`) como constante do ponteiro nulo; `nullptr` é menos vulnerável ao uso indevido e funciona melhor na maioria das situações.  Por exemplo, com `func(std::pair<const char *, double>)`, chamar `func(std::make_pair(NULL, 3.14))` causa um erro do compilador.  A macro NULL expande para `0`, para que a chamada `std::make_pair(0, 3.14)` retorne `std::pair<int, double>`, que não é conversível para o tipo de parâmetro `std::pair<const char *, double>` de func().  Chamar `func(std::make_pair(nullptr, 3.14))` resulta em uma compilação bem-sucedida porque `std::make_pair(nullptr, 3.14)` retorna `std::pair<std::nullptr_t, double>`, que é convertido em `std::pair<const char *, double>`.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [nullptr](../windows/nullptr-cpp-component-extensions.md)