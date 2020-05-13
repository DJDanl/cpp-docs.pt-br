---
title: Palavras-chave de herança
ms.date: 11/04/2016
f1_keywords:
- __multiple_inheritance
- __single_inheritance_cpp
- __virtual_inheritance_cpp
- __virtual_inheritance
- __multiple_inheritance_cpp
- __single_inheritance
helpviewer_keywords:
- __single_inheritance keyword [C++]
- declaring derived classes [C++]
- keywords [C++], inheritance keywords
- __multiple_inheritance keyword [C++]
- __virtual_inheritance keyword [C++]
- inheritance, declaring derived classes
- derived classes [C++], declaring
- inheritance, keywords
ms.assetid: bb810f56-7720-4fea-b8b6-9499edd141df
ms.openlocfilehash: f0aae655540b4d3f9130d9840d77e0abcf270cc2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374097"
---
# <a name="inheritance-keywords"></a>Palavras-chave de herança

**Específico da Microsoft**

```
class [__single_inheritance] class-name;
class [__multiple_inheritance] class-name;
class [__virtual_inheritance] class-name;
```

onde:

*nome de classe*<br/>
O nome da classe que está sendo declarada.

O C++ permite que você declare um ponteiro para um membro de classe antes da definição da classe. Por exemplo:

```cpp
class S;
int S::*p;
```

No código acima, `p` é declarado como um ponteiro para membro inteiro da classe S. No `class S` entanto, ainda não foi definido neste código; só foi declarado. Quando o compilador encontrar esse ponteiro, ele fará uma representação generalizada do ponteiro. O tamanho de representação depende do modelo de herança especificado. Há quatro maneiras de especificar um modelo de herança para o compilador:

- No IDE sob **representação pointer-to-member**

- Na linha de comando usando o interruptor [/vmg](../build/reference/vmb-vmg-representation-method.md)

- Usando o pragma [pointers_to_members](../preprocessor/pointers-to-members.md)

- Usando as palavras-chave de herança **__single_inheritance,** **__multiple_inheritance**e **__virtual_inheritance**. Essa técnica controla o modelo de herança com base em classes.

    > [!NOTE]
    >  Se você sempre declara um ponteiro para um membro de uma classe depois de defini-la, você não precisa usar qualquer uma dessas opções.

A declaração de um ponteiro para um membro de uma classe antes da definição de classe afeta o tamanho e a velocidade do arquivo executável resultante. Quanto mais complexa a herança usada por uma classe, maior é o número de bytes necessários para representar um ponteiro para um membro da classe e maior é o código necessário interpretar o ponteiro. A herança única é a menos complexa, e a herança virtual é a mais complexa.

Se o exemplo anterior for alterado para:

```cpp
class __single_inheritance S;
int S::*p;
```

independentemente das opções de linha de comando ou dos pragmas, os ponteiros para os membros de `class S` usarão a menor representação possível.

> [!NOTE]
> A mesma declaração de encaminhamento de uma representação de ponteiro para membro de classe deve ocorrer em cada unidade de tradução que declarar ponteiros para membros daquela classe, e a declaração deve ocorrer antes que os ponteiros para os membros sejam declarados.

Para compatibilidade com as versões anteriores, **_single_inheritance,** **_multiple_inheritance**e **_virtual_inheritance** são sinônimos de **__single_inheritance,** **__multiple_inheritance**e **__virtual_inheritance,** a menos que a opção de compilação [/Za \(Disable extensões de idioma)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
