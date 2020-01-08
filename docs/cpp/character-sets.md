---
title: Tokens e conjuntos de caracteres
ms.date: 12/10/2019
helpviewer_keywords:
- Tokens (C++)
- Character sets
- basic source character set (C++)
- universal character names
- basic execution character set (C++)
ms.assetid: 379a2af6-6422-425f-8352-ef0bca6c0d74
ms.openlocfilehash: 1f6dbe2faa6348d61ec00b411cc35e8ef5ceb57a
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301607"
---
# <a name="tokens-and-character-sets"></a>Tokens e conjuntos de caracteres

O texto de um C++ programa consiste em tokens e *espaços em branco*. Um token é o menor elemento de um programa em C/C++ que é significativo para o compilador. O C++ analisador reconhece esses tipos de tokens:

- [Palavras-chave](../cpp/keywords-cpp.md)
- [Identificadores](../cpp/identifiers-cpp.md)
- [Literais de ponteiro, numéricos e boolianos](../cpp/numeric-boolean-and-pointer-literals-cpp.md)
- [Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md)
- [Literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md)
- [Operadores](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
- [Pontuadores](../cpp/punctuators-cpp.md)

Os tokens são geralmente separados por um *espaço em branco*, que pode ser um ou mais:

- Em branco
- Tabulações horizontais ou verticais
- Novas linhas
- Feeds de formulário
- Comments

## <a name="basic-source-character-set"></a>Conjunto de caracteres de origem básico

O C++ padrão especifica um *conjunto de caracteres de origem básico* que pode ser usado em arquivos de origem. Para representar caracteres fora desse conjunto, caracteres adicionais podem ser especificados usando um nome de *caractere universal*. A implementação de MSVC permite caracteres adicionais. O *conjunto de caracteres de origem básico* consiste em 96 caracteres que podem ser usados em arquivos de origem. Esse conjunto inclui o caractere de espaço, a guia horizontal, a guia vertical, o feed de formulário e os caracteres de controle de nova linha e esse conjunto de caracteres gráficos:

`a b c d e f g h i j k l m n o p q r s t u v w x y z`

`A B C D E F G H I J K L M N O P Q R S T U V W X Y Z`

`0 1 2 3 4 5 6 7 8 9`

`_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '`

**Seção específica da Microsoft**

MSVC inclui o caractere `$` como um membro do conjunto de caracteres de origem básico. O MSVC também permite que um conjunto adicional de caracteres seja usado em arquivos de origem, com base na codificação do arquivo. Por padrão, o Visual Studio armazena arquivos de origem usando a página de código padrão. Quando os arquivos de origem são salvos usando um código de página específico de localidade ou uma página de código Unicode, o MSVC permite que você use qualquer um dos caracteres de uma dessas páginas em seu código-fonte, com exceção dos códigos de controle não explicitamente permitidos no conjunto de caracteres de origem básico. Por exemplo, você pode colocar caracteres japoneses em comentários, identificadores ou literais de cadeia de caracteres se salvar o arquivo usando uma página de código japonesa. MSVC não permite sequências de caracteres que não podem ser convertidas em caracteres multibyte válidos ou pontos de código Unicode. Dependendo das opções do compilador, nem todos os caracteres permitidos podem aparecer em identificadores. Para obter mais informações, consulte [Identificadores](../cpp/identifiers-cpp.md).

**Fim da seção específica da Microsoft**

### <a name="universal-character-names"></a>Nomes de caracteres universais

Como C++ os programas podem usar muito mais caracteres do que aqueles especificados no conjunto de caracteres de origem básico, você pode especificar esses caracteres de forma portátil usando *nomes de caracteres universais*. Um nome de caractere universal consiste em uma sequência de caracteres que representa um ponto de código Unicode.  Elas usam duas formas. Use `\UNNNNNNNN` para representar um ponto de código Unicode no formato U + NNNNNNNN, em que NNNNNNNN é o número de ponto de código hexadecimal de oito dígitos. Use `\uNNNN` de quatro dígitos para representar um ponto de código Unicode do formulário U + 0000NNNN.

Os nomes de caracteres universais podem ser usados em identificadores e em literais de cadeia de caracteres e caracteres. Um nome de caractere universal não pode ser usado para representar um ponto de código substituto no intervalo 0xD800-0xDFFF. Em vez disso, use o ponto de código desejado; o compilador gera automaticamente quaisquer substitutos necessários. Restrições adicionais se aplicam aos nomes de caracteres universais que podem ser usados em identificadores. Para obter mais informações, consulte [identificadores](../cpp/identifiers-cpp.md) e [cadeias de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md).

**Seção específica da Microsoft**

O compilador C++ da Microsoft trata um caractere em forma de nome de caractere universal e formulário literal de forma intercambiável. Por exemplo, você pode declarar um identificador usando o formato de nome de caractere universal e usá-lo no formato literal:

```cpp
auto \u30AD = 42; // \u30AD is 'キ'
if (キ == 42) return true; // \u30AD and キ are the same to the compiler
```

O formato dos caracteres estendidos na área de transferência do Windows é específico para as configurações de localidade do aplicativo. Recortar e colar esses caracteres em seu código de outro aplicativo pode introduzir codificações de caracteres inesperadas. Isso pode resultar na análise de erros sem nenhuma causa visível no código. Recomendamos que você defina a codificação do arquivo de origem para uma página de código Unicode antes de colar os caracteres estendidos. Também recomendamos que você use um IME ou o aplicativo de mapa de caracteres para gerar caracteres estendidos.

**Fim da seção específica da Microsoft**

### <a name="execution-character-sets"></a>Conjuntos de caracteres de execução

Os *conjuntos de caracteres de execução* representam os caracteres e as cadeias que podem aparecer em um programa compilado. Esses conjuntos de caracteres consistem em todos os caracteres permitidos em um arquivo de origem e também os caracteres de controle que representam alerta, backspace, retorno de carro e o caractere nulo. O conjunto de caracteres de execução tem uma representação específica de localidade.
