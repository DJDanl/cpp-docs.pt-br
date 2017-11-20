---
title: Namespaces | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- union keyword [C], tags
- enumeration tags
- structure tags
- names [C++], declared elements
- name spaces [C++]
- tags, structure tags
- union keyword [C]
ms.assetid: b4bda1d1-cb5e-4f60-ac2b-29af93d8a9a2
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ba0a5fcce92c0d8afe19e3b98d2ba20e1d22d6a4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="name-spaces"></a>Namespaces
O compilador configura os “name spaces” para distinguir entre os identificadores usados para tipos diferentes de itens. Os nomes em cada name space devem ser exclusivos para evitar conflitos, mas um nome idêntico pode aparecer em mais de um name space. Isso significa que você pode usar o mesmo identificador de dois ou mais itens diferentes, contanto que os itens estejam em name spaces diferentes. O compilador pode resolver referências com base no contexto sintático do identificador no programa.  
  
> [!NOTE]
>  Não confunda a noção limitada de um name space em C com o recurso “namespace” em C++. Consulte [Namespaces](../cpp/namespaces-cpp.md), na *referência da linguagem C++* para obter mais informações.  
  
 Esta lista descreve os name spaces usados em C.  
  
 Rótulos de instrução  
 Os rótulos de instrução nomeados são parte de instruções. As definições de rótulos de instrução sempre são seguidas por dois pontos, mas não fazem parte dos rótulos **case**. O uso dos rótulos de instrução sempre ocorre imediatamente após a palavra-chave `goto`. Os rótulos de instrução não precisam ser diferentes de outros nomes ou nomes de rótulo em outras funções.  
  
 Marcas de estrutura, união e enumeração  
 Essas marcas fazem parte de especificadores do tipo estrutura, união e enumeração e, se estiverem presentes, ocorrem sempre imediatamente após as palavras reservadas `struct`, **union** ou `enum`. Os nomes de marcas devem ser diferentes de todas as outras marcas de estrutura, enumeração e união com a mesma visibilidade.  
  
 Membros de estruturas ou uniões  
 Os nomes de membros são alocados em name spaces associados a cada tipo de estrutura e união. Ou seja, o mesmo identificador pode ser um nome de componente em várias estruturas ou uniões ao mesmo tempo. As definições de nomes de componente sempre ocorrem dentro dos especificadores do tipo estrutura ou união. O uso de nomes de componente sempre ocorre imediatamente após os operadores de seleção de membros (**->** e **.**). O nome de um membro deve ser exclusivo dentro da estrutura ou da união, mas não precisa ser diferente de outros nomes no programa, inclusive os nomes dos membros de estruturas e uniões diferentes ou o nome da própria estrutura.  
  
 Identificadores comuns  
 Todos os outros nomes ficam em um name space que inclui variáveis, funções (incluindo parâmetros formais e variáveis locais) e constantes de enumeração. Os nomes de identificadores têm visibilidade aninhada, para que você possa redefini-los nos blocos.  
  
 Nomes Typedef  
 Os nomes Typedef não podem ser usados como identificadores no mesmo escopo.  
  
 Por exemplo, como as marcas de estrutura, os membros de estrutura e os nomes de variável estão em três name spaces diferentes, os três itens nomeados `student` neste exemplo não estão em conflito. O contexto de cada item permite a interpretação correta de cada ocorrência de `student` no programa. (Para obter informações sobre estruturas, consulte [Declarações de estrutura](../c-language/structure-declarations.md).)  
  
```  
struct student {  
   char student[20];  
   int class;  
   int id;  
   } student;  
```  
  
 Quando `student` aparece após a palavra-chave de `struct`, o compilador o reconhece como uma marca de estrutura. Quando `student` aparece após um operador de seleção de membros (**->** ou **.**), o nome faz referência ao membro da estrutura. Em outros contextos, `student` se refere à variável da estrutura. Porém, sobrecarregar a marca name space não é recomendado porque obscurece o significado.  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura do Programa](../c-language/program-structure.md)