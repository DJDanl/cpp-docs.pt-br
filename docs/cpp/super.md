---
title: Super | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __super_cpp
dev_langs:
- C++
helpviewer_keywords:
- __super keyword [C++]
ms.assetid: f0957c31-9256-405b-b402-cad182404b5f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b9caa3d08140887da45916b931b6a4850358db16
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942353"
---
# <a name="super"></a>__super
**Seção específica da Microsoft**  
  
 Permite que você indique explicitamente que está chamando uma implementação da classe base para uma função que está substituindo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
__super::member_function();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Todos os métodos acessíveis da classe base são considerados durante a fase de resolução de sobrecarga e a função que fornece a melhor correspondência é a chamada.  
  
 **Super** só pode aparecer dentro do corpo de uma função de membro.  
  
 **Super** não pode ser usado com o uso de uma declaração. Ver [usando a declaração](../cpp/using-declaration.md) para obter mais informações.  
  
 Com a introdução da [atributos](../windows/cpp-attributes-reference.md) que injetam código, seu código pode conter uma ou mais classes base cujos nomes você talvez não saiba, mas que contêm métodos que você deseja chamar.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
// deriv_super.cpp  
// compile with: /c  
struct B1 {  
   void mf(int) {}  
};  
  
struct B2 {  
   void mf(short) {}  
  
   void mf(char) {}  
};  
  
struct D : B1, B2 {  
   void mf(short) {  
      __super::mf(1);   // Calls B1::mf(int)  
      __super::mf('s');   // Calls B2::mf(char)  
   }  
};  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)