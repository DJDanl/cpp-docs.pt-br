---
title: Conjuntos de caracteres
ms.date: 05/06/2019
helpviewer_keywords:
- Character sets
- basic source character set (C++)
- universal character names
- basic execution character set (C++)
ms.assetid: 379a2af6-6422-425f-8352-ef0bca6c0d74
ms.openlocfilehash: 92d60e3383abd7e3b3fa2d689958cf02a9b91e75
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222523"
---
# <a name="character-sets"></a>Conjuntos de caracteres

O texto de um programa C++ é armazenado em arquivos de origem que usam uma codificação de caracteres em particular. O padrão de C++ especifica um caractere de origem básicos definidas para arquivos de origem e um caractere de execução básico definidas para arquivos compilados. O Microsoft C++ compilador (MSVC) permite que um conjunto de caracteres específica de localidade a ser usado nos arquivos de origem adicionais e arquivos compilados.

## <a name="character-sets"></a>Conjuntos de caracteres

O padrão de C++ especifica um *conjunto de caracteres de origem básicos* que podem ser usados nos arquivos de origem. Para representar caracteres fora esse conjunto, os caracteres adicionais podem ser especificados usando um *nome de caractere universal*. Quando compilado, o *conjunto de caracteres de execução básico* e *conjunto de caractere largo de execução básico* representam os caracteres e cadeias de caracteres que podem aparecer em um programa. A implementação do MSVC permite caracteres adicionais no código-fonte e código compilado.

### <a name="basic-source-character-set"></a>Conjunto de caracteres de origem básicos

O *conjunto de caracteres de origem básicos* consiste em 96 caracteres que podem ser usadas em arquivos de origem. Esse conjunto inclui o caractere de espaço, tabulação horizontal, tabulação vertical, avanço e caracteres de controle de nova linha, e esse conjunto de caracteres de gráficos:

`a b c d e f g h i j k l m n o p q r s t u v w x y z`

`A B C D E F G H I J K L M N O P Q R S T U V W X Y Z`

`0 1 2 3 4 5 6 7 8 9`

`_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '`

**Seção específica da Microsoft**

MSVC inclui o `$` caractere como um membro do conjunto de caracteres de origem básicos. MSVC também permite que um conjunto de caracteres a ser usado nos arquivos de origem, com base na codificação de arquivo adicionais. Por padrão, o Visual Studio armazena arquivos de origem usando a página de código padrão. Quando os arquivos de origem são salvos usando uma página de código específica de localidade ou uma página de código Unicode, MSVC permite que você use qualquer um dos caracteres da página de código em seu código-fonte, exceto para os códigos de controle não são explicitamente permitidos no caractere de origem básicos definido. Por exemplo, você pode colocar caracteres japoneses em comentários, identificadores ou literais de cadeia de caracteres, se você salvar o arquivo usando uma página de código japonesa. MSVC não permite que as sequências de caracteres que não podem ser convertidas em caracteres multibyte válidos ou pontos de código Unicode. Dependendo das opções do compilador, não todos os permitidos caracteres podem aparecer em identificadores. Para obter mais informações, consulte [Identificadores](../cpp/identifiers-cpp.md).

**Fim da seção específica da Microsoft**

### <a name="universal-character-names"></a>Nomes de caracteres universais

Como programas C++ podem usar vários outros caracteres além daqueles especificados no conjunto de caracteres de origem básicos, você pode especificar esses caracteres de uma maneira portátil usando *nomes de caracteres universais*. Um nome de caractere universal consiste em uma sequência de caracteres que representam um ponto de código Unicode.  Eles têm duas formas. Use `\UNNNNNNNN` para representar um ponto de código Unicode do formulário U + NNNNNNNN, onde NNNNNNNN é o número de ponto de código hexadecimal de oito dígitos. Use quatro dígitos `\uNNNN` para representar um ponto de código Unicode do formulário U + 0000NNNN.

Nomes de caracteres universais podem ser usados em identificadores em literais de cadeia de caracteres e caracteres. Um nome de caractere universal não pode ser usado para representar um ponto de código alternativo no intervalo 0xD800 0xDFFF. Em vez disso, use o ponto de código desejada; o compilador gera automaticamente qualquer substitutos necessários. Restrições adicionais se aplicam aos nomes de caractere universal que podem ser usados em identificadores. Para obter mais informações, consulte [identificadores](../cpp/identifiers-cpp.md) e [cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md).

**Seção específica da Microsoft**

O Microsoft C++ compilador trata um caractere no formulário de nome de caractere universal e formulário literal alternadamente. Por exemplo, você pode declarar um identificador com formato de nome de caractere universal e usá-lo no formulário literal:

```cpp
auto \u30AD = 42; // \u30AD is 'キ'
if (キ == 42) return true; // \u30AD and キ are the same to the compiler
```

O formato de caracteres estendidos na área de transferência do Windows é específico para as configurações de localidade do aplicativo. Recortar e colar esses caracteres no seu código de outro aplicativo podem introduzir as codificações de caractere inesperado. Isso pode resultar em erros de análise sem motivo aparente no seu código. É recomendável que você defina seu código-fonte codificação do arquivo para uma página de código Unicode antes de colar caracteres estendidos. Também recomendamos que você use um IME ou o aplicativo de mapa de caracteres para gerar caracteres estendidos.

**Fim da seção específica da Microsoft**

### <a name="basic-execution-character-set"></a>Conjunto de caracteres de execução básico

O *conjunto de caracteres de execução básico* e o *conjunto de caractere largo de execução básico* consistem em todos os caracteres no conjunto de caracteres de origem básicos e os caracteres de controle que representam alerta, BACKSPACE, retorno de carro e o caractere nulo. O *conjunto de caracteres de execução* e *conjunto de caractere largo de execução* são subconjuntos dos conjuntos de básico. Eles incluem os caracteres de origem definido pela implementação fora do conjunto de caracteres de origem básicos. O conjunto de caracteres de execução tem uma representação específica de localidade.