---
title: propriedade (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- property_cpp
dev_langs:
- C++
helpviewer_keywords:
- property __declspec keyword
- __declspec keyword [C++], property
ms.assetid: f3b850ba-bf48-4df7-a1d6-8259d97309ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c4673101d41b896ed3fc19aa1998aa9329064b41
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409061"
---
# <a name="property-c"></a>property (C++)
**Seção específica da Microsoft**  
  
 Esse atributo pode ser aplicado a “membros de dados virtuais” não estáticos em uma definição de classe ou estrutura. O compilador trata esses “membros de dados virtuais” como membros de dados alterando suas referências em chamadas de função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
   __declspec( property( get=get_func_name ) ) declarator  
   __declspec( property( put=put_func_name ) ) declarator  
   __declspec( property( get=get_func_name, put=put_func_name ) ) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 Quando o compilador vê um membro de dados declarado com esse atributo à direita de um operador de seleção de membro ("**.**"ou"**->**"), ele converte a operação de um `get` ou `put` função, dependendo se essa expressão for um l-value ou um valor r. Nos contextos mais complicados, como "`+=`", uma regravação é executada fazendo `get` e `put`.  
  
 Esse atributo também pode ser usado na declaração de uma matriz vazia em uma definição de classe ou estrutura. Por exemplo:  
  
```cpp 
__declspec(property(get=GetX, put=PutX)) int x[];  
```  
  
 A instrução anterior indica que `x[]` pode ser usado com um ou mais índices da matriz. Nesse caso, `i=p->x[a][b]` será transformado em `i=p->GetX(a, b)`, e `p->x[a][b] = i` será transformado em `p->PutX(a, b, i);`  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="example"></a>Exemplo  
  
```cpp 
// declspec_property.cpp  
struct S {  
   int i;  
   void putprop(int j) {   
      i = j;  
   }  
  
   int getprop() {  
      return i;  
   }  
  
   __declspec(property(get = getprop, put = putprop)) int the_prop;  
};  
  
int main() {  
   S s;  
   s.the_prop = 5;  
   return s.the_prop;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)