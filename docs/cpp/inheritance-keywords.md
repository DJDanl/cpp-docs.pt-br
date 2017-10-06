---
title: "Palavras-chave de herança | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- __single_inheritance keyword [C++]
- declaring derived classes
- keywords [C++], inheritance keywords
- __multiple_inheritance keyword [C++]
- __virtual_inheritance keyword [C++]
- inheritance, declaring derived classes
- derived classes, declaring
- inheritance, keywords
ms.assetid: bb810f56-7720-4fea-b8b6-9499edd141df
caps.latest.revision: 9
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
ms.openlocfilehash: 6286d8e3082f0a4a3ce3e00fb3de1ad4ca41589a
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="inheritance-keywords"></a>Palavras-chave de herança
**Seção específica da Microsoft**  
  
```  
  
class [__single_inheritance] class-name;class [__multiple_inheritance] class-name;class [__virtual_inheritance] class-name;  
```  
  
 em que:  
  
 *nome de classe*  
 O nome da classe que está sendo declarada.  
  
 O C++ permite que você declare um ponteiro para um membro de classe antes da definição da classe. Por exemplo:  
  
```  
class S;  
int S::*p;  
```  
  
 No código acima, `p` é declarado como um ponteiro para membro de inteiro da classe S. No entanto, `class S` tem ainda não foi definido neste código; ele só foi declarado. Quando o compilador encontrar esse ponteiro, ele fará uma representação generalizada do ponteiro. O tamanho de representação depende do modelo de herança especificado. Há quatro maneiras de especificar um modelo de herança para o compilador:  
  
-   No IDE em **representação de ponteiro para membro**  
  
-   Na linha de comando usando o [/vmg](../build/reference/vmb-vmg-representation-method.md) alternar  
  
-   Usando o [pointers_to_members](../preprocessor/pointers-to-members.md) pragma  
  
-   Usando as palavras-chave de herança `__single_inheritance`, `__multiple_inheritance` e `__virtual_inheritance`. Essa técnica controla o modelo de herança com base em classes.  
  
    > [!NOTE]
    >  Se você sempre declara um ponteiro para um membro de uma classe depois de defini-la, você não precisa usar qualquer uma dessas opções.  
  
 A declaração de um ponteiro para um membro de uma classe antes da definição de classe afeta o tamanho e a velocidade do arquivo executável resultante. Quanto mais complexa a herança usada por uma classe, maior é o número de bytes necessários para representar um ponteiro para um membro da classe e maior é o código necessário interpretar o ponteiro. A herança única é a menos complexa, e a herança virtual é a mais complexa.  
  
 Se o exemplo anterior for alterado para:  
  
```  
class __single_inheritance S;  
int S::*p;  
```  
  
 independentemente das opções de linha de comando ou dos pragmas, os ponteiros para os membros de `class S` usarão a menor representação possível.  
  
> [!NOTE]
>  A mesma declaração de encaminhamento de uma representação de ponteiro para membro de classe deve ocorrer em cada unidade de tradução que declarar ponteiros para membros daquela classe, e a declaração deve ocorrer antes que os ponteiros para os membros sejam declarados.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)
