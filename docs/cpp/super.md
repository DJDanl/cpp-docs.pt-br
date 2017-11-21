---
title: Super | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: __super_cpp
dev_langs: C++
helpviewer_keywords: __super keyword [C++]
ms.assetid: f0957c31-9256-405b-b402-cad182404b5f
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6dd4e24b36811a96e0d09ae58e7573d57065e2fc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="super"></a>__super
**Seção específica da Microsoft**  
  
 Permite que você indique explicitamente que está chamando uma implementação da classe base para uma função que está substituindo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
__super::  
member_function  
();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Todos os métodos acessíveis da classe base são considerados durante a fase de resolução de sobrecarga e a função que fornece a melhor correspondência é a chamada.  
  
 `__super` só pode aparecer no corpo de uma função membro.  
  
 `__super` não pode ser usado com uma declaração de uso. Consulte [usando declaração](../cpp/using-declaration.md) para obter mais informações.  
  
 Com a introdução de [atributos](../windows/cpp-attributes-reference.md) que injetar código, seu código pode conter uma ou mais classes base cujos nomes talvez não saiba mas que contêm métodos que você deseja chamar.  
  
## <a name="example"></a>Exemplo  
  
```  
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