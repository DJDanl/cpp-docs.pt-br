---
title: '&lt;ios&gt;'
ms.date: 11/04/2016
f1_keywords:
- <ios>
- ios/std::<ios>
helpviewer_keywords:
- ios header
ms.assetid: d3d4c161-2f37-4f04-93cc-0a2a89984a9c
ms.openlocfilehash: 8ba03e5ab5dd90a6f29e08b01576803a00f0bd24
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845478"
---
# <a name="ltiosgt"></a>&lt;ios&gt;

Define vários tipos e funções básicas para a operação de iostreams. Esse cabeçalho normalmente é incluído para você por outros cabeçalhos iostreams; dificilmente você o incluirá diretamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<ios>

**Namespace:** std

> [!NOTE]
> A \<ios> biblioteca usa a `#include <iosfwd>` instrução.

## <a name="remarks"></a>Comentários

Um grande grupo de funções são manipuladores. Um manipulador declarado em \<ios> altera os valores armazenados em seu objeto Argument da classe [ios_base](../standard-library/ios-base-class.md). Outros manipuladores executam ações em fluxos controlados por objetos de um tipo derivado dessa classe, como uma especialização de um dos modelos de classe [basic_istream](../standard-library/basic-istream-class.md) ou [basic_ostream](../standard-library/basic-ostream-class.md). Por exemplo, [noskipws](../standard-library/ios-functions.md#noskipws)(**Str**) limpa o sinalizador de formato `ios_base::skipws` no objeto `str` , que pode ser de um desses tipos.

Também é possível chamar um manipulador inserindo-o em um fluxo de saída ou extraindo-o de um fluxo de entrada, devido às operações especiais de inserção e extração fornecidas para as classes derivadas de `ios_base`. Por exemplo:

```cpp
istr>> noskipws;
```

chama [noskipws](../standard-library/ios-functions.md#noskipws)(**istr**).

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|[Cisco](../standard-library/ios-typedefs.md#ios)|Dá suporte à classe ios da biblioteca iostream antiga.|
|[streamoff](../standard-library/ios-typedefs.md#streamoff)|Dá suporte a operações internas.|
|[streampos](../standard-library/ios-typedefs.md#streampos)|Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.|
|[streamsize](../standard-library/ios-typedefs.md#streamsize)|Especifica o tamanho do fluxo.|
|[wios](../standard-library/ios-typedefs.md#wios)|Dá suporte à classe wios da biblioteca iostream antiga.|
|[wstreampos](../standard-library/ios-typedefs.md#wstreampos)|Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.|

### <a name="manipulators"></a>Manipuladores

|Nome|Descrição|
|-|-|
|[boolalpha](../standard-library/ios-functions.md#boolalpha)|Especifica que variáveis do tipo [bool](../cpp/bool-cpp.md) aparecem como **`true`** ou **`false`** no fluxo.|
|[dez](../standard-library/ios-functions.md#dec)|Especifica que variáveis inteiras aparecem em notação de base 10.|
|[defaultfloat](../standard-library/ios-functions.md#ios_defaultfloat)|Configura os sinalizadores de um objeto `ios_base` para usar um formato de exibição padrão para valores do tipo float.|
|[fixado](../standard-library/ios-functions.md#fixed)|Especifica que um número de ponto flutuante é exibido em notação de decimal fixo.|
|[hex](../standard-library/ios-functions.md#hex)|Especifica que variáveis inteiras aparecem em notação de base 16.|
|[hexfloat](../standard-library/ios-functions.md#hexfloat)|
|[interno](../standard-library/ios-functions.md#internal)|Faz com que o sinal de um número seja justificado à esquerda e o número seja justificado à direita.|
|[mantida](../standard-library/ios-functions.md#left)|Faz com que um texto que não é tão largo quanto a largura de saída apareça no fluxo alinhado à margem esquerda.|
|[noboolalpha](../standard-library/ios-functions.md#noboolalpha)|Especifica que variáveis do tipo [bool](../cpp/bool-cpp.md) apareçam como 1 ou 0 no fluxo.|
|[noshowbase](../standard-library/ios-functions.md#noshowbase)|Desativa a indicação da base da notação em que um número é exibido.|
|[noshowpoint](../standard-library/ios-functions.md#noshowpoint)|Exibe somente a parte de número inteiro de números de ponto flutuante cuja parte fracionária é zero.|
|[noshowpos](../standard-library/ios-functions.md#noshowpos)|Faz com que números positivos não recebam sinalização explícita.|
|[noskipws](../standard-library/ios-functions.md#noskipws)|Faz com que espaços sejam lidos pelo fluxo de entrada.|
|[nounitbuf](../standard-library/ios-functions.md#nounitbuf)|Faz com que a saída seja armazenada em buffer e processada quando o buffer estiver cheio.|
|[nouppercase](../standard-library/ios-functions.md#nouppercase)|Especifica que dígitos hexadecimais e o expoente em notação científica apareçam em letras minúsculas.|
|[Outubro](../standard-library/ios-functions.md#oct)|Especifica que variáveis inteiras aparecem em notação de base 8.|
|[Certo](../standard-library/ios-functions.md#right)|Faz com que um texto que não é tão largo quanto a largura de saída apareça no fluxo alinhado à margem direita.|
|[científica](../standard-library/ios-functions.md#scientific)|Faz com que números de ponto flutuante sejam exibidos usando notação científica.|
|[showbase](../standard-library/ios-functions.md#showbase)|Indica a base da notação em que um número é exibido.|
|[showpoint](../standard-library/ios-functions.md#showpoint)|Exibe a parte de número inteiro de um número de ponto flutuante e os dígitos à direita do ponto decimal, mesmo quando a parte fracionária for zero.|
|[showpos](../standard-library/ios-functions.md#showpos)|Faz com que números positivos recebam sinalização explícita.|
|[skipws](../standard-library/ios-functions.md#skipws)|Faz com que espaços não sejam lidos pelo fluxo de entrada.|
|[unitbuf](../standard-library/ios-functions.md#unitbuf)|Faz com que a saída seja processada quando o buffer não estiver vazio.|
|[letras maiúsculas](../standard-library/ios-functions.md#uppercase)|Especifica que dígitos hexadecimais e o expoente em notação científica apareçam em letras maiúsculas.|

### <a name="error-reporting"></a>Relatório de Erros

|Nome|Descrição|
|-|-|
|[io_errc](../standard-library/ios-functions.md#io_errc)||
|[is_error_code_enum](../standard-library/ios-functions.md#is_error_code_enum)||
|[iostream_category](../standard-library/ios-functions.md#iostream_category)||
|[make_error_code](../standard-library/ios-functions.md#make_error_code)||
|[make_error_condition](../standard-library/ios-functions.md#make_error_condition)||

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[basic_ios](../standard-library/basic-ios-class.md)|O modelo de classe descreve as funções de armazenamento e membro comuns a fluxos de entrada (do modelo de classe [basic_istream](../standard-library/basic-istream-class.md)) e fluxos de saída (do modelo de classe [basic_ostream](../standard-library/basic-ostream-class.md)) que dependem dos parâmetros do modelo.|
|[fpos](../standard-library/fpos-class.md)|O modelo de classe descreve um objeto que pode armazenar todas as informações necessárias para restaurar um indicador de posição de arquivo arbitrário dentro de qualquer fluxo.|
|[ios_base](../standard-library/ios-base-class.md)|A classe descreve as funções membro e de armazenamento comuns aos fluxos de entrada e de saída que não dependem dos parâmetros do modelo.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
