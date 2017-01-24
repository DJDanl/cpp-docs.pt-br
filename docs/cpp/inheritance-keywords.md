---
title: "Palavras-chave de heran&#231;a | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__multiple_inheritance"
  - "__single_inheritance_cpp"
  - "__virtual_inheritance_cpp"
  - "__virtual_inheritance"
  - "__multiple_inheritance_cpp"
  - "__single_inheritance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __multiple_inheritance [C++]"
  - "Palavra-chave __single_inheritance [C++]"
  - "Palavra-chave __virtual_inheritance [C++]"
  - "declarando classes derivadas"
  - "classes derivadas, declarando"
  - "herança, declarando classes derivadas"
  - "herança, palavras-chave"
  - "palavras-chave [C++], palavras-chave de herança"
ms.assetid: bb810f56-7720-4fea-b8b6-9499edd141df
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Palavras-chave de heran&#231;a
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
```  
  
class [__single_inheritance] class-name; class [__multiple_inheritance] class-name; class [__virtual_inheritance] class-name;  
```  
  
 onde,  
  
 *nome de classe*  
 O nome da classe que está sendo declarada.  
  
 O C\+\+ permite que você declare um ponteiro para um membro de classe antes da definição da classe.  Por exemplo:  
  
```  
class S;  
int S::*p;  
```  
  
 No código acima, `p` é declarado como um ponteiro para o membro inteiro da classe. S.  No entanto, `class S` ainda não foi definida neste código; ela foi apenas declarada.  Quando o compilador encontrar esse ponteiro, ele fará uma representação generalizada do ponteiro.  O tamanho de representação depende do modelo de herança especificado.  Há quatro maneiras de especificar um modelo de herança para o compilador:  
  
-   No IDE, em **Pointer\-to\-member representation**  
  
-   Na linha de comando, usando a opção [\/vmg](../build/reference/vmb-vmg-representation-method.md)  
  
-   Usando o pragma [pointers\_to\_members](../Topic/pointers_to_members.md)  
  
-   Usando as palavras\-chave de herança `__single_inheritance`, `__multiple_inheritance` e `__virtual_inheritance`.  Essa técnica controla o modelo de herança com base em classes.  
  
    > [!NOTE]
    >  Se você sempre declara um ponteiro para um membro de uma classe depois de defini\-la, você não precisa usar qualquer uma dessas opções.  
  
 A declaração de um ponteiro para um membro de uma classe antes da definição de classe afeta o tamanho e a velocidade do arquivo executável resultante.  Quanto mais complexa a herança usada por uma classe, maior é o número de bytes necessários para representar um ponteiro para um membro da classe e maior é o código necessário interpretar o ponteiro.  A herança única é a menos complexa, e a herança virtual é a mais complexa.  
  
 Se o exemplo anterior for alterado para:  
  
```  
class __single_inheritance S;  
int S::*p;  
```  
  
 independentemente das opções de linha de comando ou dos pragmas, os ponteiros para os membros de `class S` usarão a menor representação possível.  
  
> [!NOTE]
>  A mesma declaração de encaminhamento de uma representação de ponteiro para membro de classe deve ocorrer em cada unidade de tradução que declarar ponteiros para membros daquela classe, e a declaração deve ocorrer antes que os ponteiros para os membros sejam declarados.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)