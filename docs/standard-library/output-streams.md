---
title: Fluxos de Saída
ms.date: 11/04/2016
helpviewer_keywords:
- output streams
ms.assetid: b49410e3-5caa-4153-9d0d-c4266408dc83
ms.openlocfilehash: c64c46acca405f948e8314fb23944682adf09c43
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50511105"
---
# <a name="output-streams"></a>Fluxos de Saída

Um objeto de fluxo de saída é um destino de bytes. As três classes de fluxo de saída mais importantes são `ostream`, `ofstream` e `ostringstream`.

A classe `ostream`, por meio da classe derivada `basic_ostream`, dá suporte os objetos de fluxo predefinidos:

- saída padrão `cout`

- Erro padrão `cerr` com buffer limitado

- `clog` semelhante ao `cerr`, mas com buffer completo

Objetos raramente são construídos de `ostream`; objetos predefinidos geralmente são usados. Em alguns casos, você pode reatribuir objetos predefinidos após a inicialização do programa. A classe `ostream`, que pode ser configurada para a operação com buffer ou sem buffer, é mais adequada para saída de modo de texto sequencial. Toda a funcionalidade da classe base, `ios`, está incluída em `ostream`. Se você construir um objeto da classe `ostream`, deverá especificar um objeto `streambuf` para o construtor.

A classe `ofstream` dá suporte à saída de arquivo de disco. Se você precisar de um disco somente saída, construa um objeto da classe `ofstream`. Você pode especificar se objetos `ofstream` aceitam dados no modo de texto ou binários ao construir o objeto `ofstream` ou ao chamar a função membro `open` do objeto. Muitas opções de formatação e funções membro se aplicam aos objetos `ofstream` e toda a funcionalidade das classes base `ios` e `ostream` estão incluídas.

Se você especificar um nome de arquivo no construtor, esse arquivo é aberto automaticamente quando o objeto é construído. Caso contrário, você pode usar a função membro `open` depois de invocar o construtor padrão.

Assim como a função de tempo de execução `sprintf_s`, a classe `ostringstream` dá suporte a saídas para cadeias de caracteres na memória. Para criar uma cadeia de caracteres na memória usando a formatação de fluxo de E/S, construa um objeto da classe `ostringstream`.

## <a name="in-this-section"></a>Nesta seção

[Construindo objetos de fluxo de saída](../standard-library/constructing-output-stream-objects.md)

[Usando operadores de inserção e controlando o formato](../standard-library/using-insertion-operators-and-controlling-format.md)

[Funções de membro de fluxo de arquivo de saída](../standard-library/output-file-stream-member-functions.md)

[Efeitos do armazenamento em buffer](../standard-library/effects-of-buffering.md)

[Arquivos de saída binários](../standard-library/binary-output-files.md)

[Sobrecarregando o operador << para as suas próprias classes](../standard-library/overloading-the-output-operator-for-your-own-classes.md)

[Elaborando os próprios manipuladores sem argumentos](../standard-library/writing-your-own-manipulators-without-arguments.md)

## <a name="see-also"></a>Consulte também

[ofstream](../standard-library/basic-ofstream-class.md)<br/>
[ostringstream](../standard-library/basic-ostringstream-class.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
