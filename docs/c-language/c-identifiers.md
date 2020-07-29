---
title: Identificadores C
ms.date: 11/04/2016
helpviewer_keywords:
- identifiers, C
- naming identifiers
- identifiers
- symbols, C identifiers
- identifiers, case sensitivity
- symbols, case sensitivity
ms.assetid: d02edbbc-85a0-4118-997b-84ee6b972eb6
ms.openlocfilehash: d68eb690a19f57555d9d757a2f058692ea1a40c3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223740"
---
# <a name="c-identifiers"></a>Identificadores C

Os "identificadores" ou "símbolos" são os nomes que você fornece para variáveis, tipos, funções e rótulos em seu programa. Os nomes de identificadores devem ser diferentes na ortografia e nas maiúsculas e minúsculas de todas as palavras-chave. Você não pode usar palavras-chave (no C ou Microsoft) como identificadores; elas são reservadas para uso especial. Você cria um identificador especificando-o na declaração de variável, tipo ou função. Neste exemplo, `result` é um identificador para uma variável de inteiro, e `main` e `printf` são nomes de identificadores para funções.

```
#include <stdio.h>

int main()
{
    int result;

    if ( result != 0 )
        printf_s( "Bad file handle\n" );
}
```

Após a declaração, você pode usar o identificador em instruções de programa posteriores para fazer referência ao valor associado.

Um tipo especial de identificador, chamado de rótulo de instrução, pode ser usado em **`goto`** instruções. (Declarações são descritas em [Declarações e tipos](../c-language/declarations-and-types.md) Rótulos de instrução são descritos em [Instruções goto e rotuladas](../c-language/goto-and-labeled-statements-c.md).)

## <a name="syntax"></a>Sintaxe

*identificador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Não dígito*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier* *nondigit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier* *digit*

*nondigit*: uma destas opções<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**_ a b c d e f g h i j k l mn o p q r s t u v w x y z**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**A B C D E F G H I J K L MN O P Q R S T U V W X Y Z**

*digit*: uma destas opções<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**0 1 2 3 4 5 6 7 8 9**

O primeiro caractere do nome de identificador deve ser `nondigit` (ou seja, o primeiro caractere deve ser um sublinhado ou letra maiúscula ou minúscula). Permite seis caracteres ANSI significativos em um nome de identificador externo e 31 para nomes (dentro de uma função) de identificadores internos. Os identificadores externos (declarados no escopo global ou declarados com a classe de armazenamento **`extern`** ) podem estar sujeitos a restrições de nomenclatura adicionais, pois esses identificadores precisam ser processados por outros softwares, como vinculadores.

**Específico da Microsoft**

Ainda que o ANSI permita 6 caracteres significativos em nomes de identificadores externos e 31 para nomes (dentro de uma função) de identificadores internos, o compilador do C da Microsoft permite 247 caracteres em um nome de identificador interno ou externo. Se você não tiver preocupado com compatibilidade de ANSI, pode alterar esse padrão para um número menor ou maior usando a opção /H (restringe o comprimento dos nomes externos).

**FINAL específico da Microsoft**

O compilador do C considerará as letras maiúsculas e minúsculas como caracteres distintos. Esse recurso, chamado de "diferenciação de maiúsculas e minúsculas" permite que você crie identificadores distintos que têm a mesma ortografia mas maiúsculas e minúsculas diferentes para uma ou mais letras. Por exemplo, cada um dos seguintes identificadores é exclusivo:

```
add
ADD
Add
aDD
```

**Específico da Microsoft**

Não selecione nomes dos identificadores que comecem com dois sublinhados ou com um sublinhado seguido por uma letra maiúscula. O padrão ANSI C permite que os nomes dos identificadores que começam com essas combinações de caracteres sejam reservados para uso pelo compilador. Os identificadores com escopo no nível de arquivo não devem ser nomeados com um sublinhado e uma letra minúscula como as duas primeiras letras. Os nomes de identificadores que começam com esses caracteres também são reservados. Por convenção, a Microsoft usa um sublinhado e uma letra maiúscula para iniciar nomes de macro e sublinhados duplos para nomes de palavras-chave específicos da Microsoft. Para evitar conflitos de nomenclatura, sempre selecione nomes do identificador que não comecem com um ou os dois sublinhados, ou os nomes que comecem com um sublinhado seguido por uma letra maiúscula.

**FINAL específico da Microsoft**

Os exemplos a seguir são identificadores válidos em conformidade com restrições de nome de ANSI ou Microsoft:

```
j
count
temp1
top_of_page
skip12
LastNum
```

**Específico da Microsoft**

Ainda que os identificadores nos arquivos de origem tenham diferenciação de maiúsculas e minúsculas por padrão, os símbolos nos arquivos de objeto não são. O Microsoft C trata os identificadores em uma unidade de compilação com diferenciação de maiúsculas e minúsculas.

O vinculador da Microsoft faz diferenciação de maiúsculas e minúsculas. Você deve especificar todos os identificadores consistentemente de acordo com maiúsculas e minúsculas.

O "conjunto de caracteres de origem" é o conjunto de caracteres válidos que podem aparecer nos arquivos de origem. Para o Microsoft C, o conjunto de origem é o conjunto de caracteres ASCII padrão. O conjunto de caracteres de origem e o conjunto de caracteres de execução incluem os caracteres ASCII usados como sequências de escape. Consulte [Constantes de caractere](../c-language/c-character-constants.md) para obter informações sobre o conjunto de caracteres de execução.

**FINAL específico da Microsoft**

Um identificador tem “escopo”, que é a região de programa em que é conhecido, e “vinculação”, que determina se o mesmo nome em outro escopo faz referência ao mesmo identificador. Esses tópicos são explicados em [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md).

## <a name="see-also"></a>Confira também

[Elementos de C](../c-language/elements-of-c.md)
