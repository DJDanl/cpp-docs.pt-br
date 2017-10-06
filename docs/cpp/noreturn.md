---
title: noreturn | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- noreturn_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], noreturn
- noreturn __declspec keyword
ms.assetid: 9c6517e5-22d7-4051-9974-3d2200ae4d1d
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 45de52c2c3c0b60a62bf19e38854c53e841ed500
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="noreturn"></a>noreturn
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Esse atributo `__declspec` diz ao compilador que uma função não retorna. Como consequência, o compilador sabe que o código que segue uma chamada para um **__declspec(noreturn)** função está inacessível.  
  
 Se o compilador encontra uma função com um caminho de controle que não retorna um valor, ele gera um aviso (C4715) ou uma mensagem de erro (C2202). Se o caminho de controle não pode ser acessado devido a uma função que nunca retorna, você pode usar **__declspec(noreturn)** para evitar este aviso ou erro.  
  
> [!NOTE]
>  Adicionando **__declspec(noreturn)** para uma função que deve retornar pode resultar em um comportamento indefinido.  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, o **else** cláusula não contém uma instrução return.  Declarando `fatal` como **__declspec(noreturn)** evita uma mensagem de erro ou aviso.  
  
```  
// noreturn2.cpp  
__declspec(noreturn) extern void fatal () {}  
  
int main() {  
   if(1)  
     return 1;  
   else if(0)  
     return 0;  
   else  
     fatal();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
