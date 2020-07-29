---
title: Namespaces
ms.date: 11/04/2016
helpviewer_keywords:
- union keyword [C], tags
- enumeration tags
- structure tags
- names [C++], declared elements
- name spaces [C++]
- tags, structure tags
- union keyword [C]
ms.assetid: b4bda1d1-cb5e-4f60-ac2b-29af93d8a9a2
ms.openlocfilehash: 28036219464e96ae20733473dedb4fab63f6de38
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218813"
---
# <a name="name-spaces"></a>Namespaces

O compilador configura os “name spaces” para distinguir entre os identificadores usados para tipos diferentes de itens. Os nomes em cada name space devem ser exclusivos para evitar conflitos, mas um nome idêntico pode aparecer em mais de um name space. Isso significa que você pode usar o mesmo identificador de dois ou mais itens diferentes, contanto que os itens estejam em name spaces diferentes. O compilador pode resolver referências com base no contexto sintático do identificador no programa.

> [!NOTE]
> Não confunda a noção limitada de um name space em C com o recurso “namespace” em C++. Consulte [Namespaces](../cpp/namespaces-cpp.md), na referência da linguagem C++ para obter mais informações.

Esta lista descreve os name spaces usados em C.

Rótulos de instrução Rótulos de instrução nomeados fazem parte das instruções. As definições de rótulos de instrução são sempre seguidas por dois-pontos, mas não fazem parte dos **`case`** Rótulos. Os usos de rótulos de instrução sempre seguem imediatamente a palavra-chave **`goto`** . Os rótulos de instrução não precisam ser diferentes de outros nomes ou nomes de rótulo em outras funções.

Marcas de estrutura, União e enumeração essas marcas fazem parte dos especificadores de tipo de estrutura, União e enumeração e, se presentes, sempre seguem imediatamente as palavras reservadas **`struct`** , **`union`** ou **`enum`** . Os nomes de marcas devem ser diferentes de todas as outras marcas de estrutura, enumeração e união com a mesma visibilidade.

Membros de estruturas ou uniões Os nomes de membros são alocados em namespaces associados a cada tipo de estrutura e união. Ou seja, o mesmo identificador pode ser um nome de componente em várias estruturas ou uniões ao mesmo tempo. As definições de nomes de componente sempre ocorrem dentro dos especificadores do tipo estrutura ou união. Os usos de nomes de componentes sempre seguem imediatamente os operadores de seleção de Membros ( **->** e **.**). O nome de um membro deve ser exclusivo dentro da estrutura ou da união, mas não precisa ser diferente de outros nomes no programa, inclusive os nomes dos membros de estruturas e uniões diferentes ou o nome da própria estrutura.

Identificadores comuns Todos os outros nomes ficam em um namespace que inclui variáveis, funções (incluindo parâmetros formais e variáveis locais) e constantes de enumeração. Os nomes de identificadores têm visibilidade aninhada, para que você possa redefini-los nos blocos.

Nomes Typedef Os nomes Typedef não podem ser usados como identificadores no mesmo escopo.

Por exemplo, como as marcas de estrutura, os membros de estrutura e os nomes de variável estão em três name spaces diferentes, os três itens nomeados `student` neste exemplo não estão em conflito. O contexto de cada item permite a interpretação correta de cada ocorrência de `student` no programa. (Para obter informações sobre estruturas, consulte [Declarações de estrutura](../c-language/structure-declarations.md).)

```C
struct student {
   char student[20];
   int class;
   int id;
   } student;
```

Quando `student` aparece após a **`struct`** palavra-chave, o compilador o reconhece como uma marca de estrutura. Quando `student` aparece depois de um operador de seleção de membro ( **->** ou **.**), o nome refere-se ao membro da estrutura. Em outros contextos, `student` se refere à variável da estrutura. Porém, sobrecarregar a marca name space não é recomendado porque obscurece o significado.

## <a name="see-also"></a>Confira também

[Estrutura do programa](../c-language/program-structure.md)
