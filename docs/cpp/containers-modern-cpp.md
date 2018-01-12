---
title: "Contêineres (C++ moderno) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 6e10b758-e928-4827-9c3f-86cafe54bf5b
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ffad61c015c38d808b35ebffd98f74733d0997de
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="containers-modern-c"></a>Contêineres (C++ moderno)  
  
Por padrão, usam [vetor](../standard-library/vector-class.md) como o contêiner sequencial preferencial em C++. Isso é equivalente a `List<T>` em linguagens .NET.  
  
```cpp  
vector<string> apples;  
apples.push_back("Granny Smith");  
```  
  
Use [mapa](../standard-library/map-class.md) (não `unordered_map`) como o contêiner de associação padrão. Use [definir](../standard-library/set-class.md), [multimap](../standard-library/multimap-class.md), e [multiset](../standard-library/multiset-class.md) degenerado & vários casos.  
  
```cpp  
map<string, string> apple_color;  
// ...  
apple_color["Granny Smith"] = "Green";  
```  
  
Quando for necessário otimizar o desempenho, considere o uso de:  
  
1.  O [matriz](../standard-library/array-class-stl.md) quando incorporação é importante, por exemplo, como um membro de classe de tipo.  
  
2.  Não ordenados associativos contêineres como [unordered_map] ((... /Standard-Library/unordered-map-class.MD). Eles têm o elemento de menor sobrecarga e pesquisa de tempo constante, mas eles podem ser mais difícil de usar de forma correta e eficiente.  
  
3.  Classificados `vector`. Para obter mais informações, consulte [Algoritmos](../cpp/algorithms-modern-cpp.md).  
  
Não use matrizes de estilo C. Para APIs mais antigos que precisam de acesso aos dados direto, usar os métodos de acessador como `f(vec.data(), vec.size());` em vez disso.  
  
Para obter mais informações sobre contêineres, consulte [contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
