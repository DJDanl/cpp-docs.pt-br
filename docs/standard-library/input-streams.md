---
title: Fluxos de entrada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- reading data [C++], from input streams
- data [C++], reading from input stream
- input streams
- input stream objects
ms.assetid: f14d8954-8f8c-4c3c-8b99-14ddb3683f94
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d3dff2e0bb0ee070b8b90ca3896d7bf8114ca918
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="input-streams"></a>Fluxos de entrada

Um objeto de fluxo de entrada é uma fonte de bytes. As três classes de fluxo de entrada mais importantes são [istream](../standard-library/basic-istream-class.md), [ifstream](../standard-library/basic-ifstream-class.md) e [istringstream](../standard-library/basic-istringstream-class.md).

A classe `istream` é mais adequada para entrada de modo de texto sequencial. É possível configurar objetos da classe `istream` para operações armazenadas em buffer ou não. Toda a funcionalidade da classe base, `ios`, está incluída em `istream`. Raramente você construirá objetos da classe `istream`. Em vez disso, normalmente você usará o objeto `cin` predefinido, que na realidade é um objeto da classe [ostream](../standard-library/basic-ostream-class.md). Em alguns casos, é possível atribuir `cin` a outros objetos de fluxo após a inicialização do programa.

A classe `ifstream` dá suporte à entrada de arquivo de disco. Se você precisar de um arquivo de disco somente de entrada, construa um objeto da classe `ifstream`. É possível especificar dados binários ou em modo de texto. Se você especificar um nome de arquivo no construtor, o arquivo será aberto automaticamente quando o objeto for construído. Caso contrário, você pode usar a função `open` depois de invocar o construtor padrão. Muitas opções de formatação e funções membro se aplicam a objetos `ifstream`. Toda a funcionalidade das classes base `ios` e `istream` está incluída em `ifstream`.

Assim como a função de biblioteca `sscanf_s`, a classe `istringstream` dá suporte a entrada de cadeias de caracteres na memória. Para extrair dados de uma matriz de caracteres com um terminador nulo, aloque e inicialize a cadeia de caracteres e construa um objeto da classe `istringstream`.

## <a name="in-this-section"></a>Nesta seção

[Construindo objetos de fluxo de entrada](../standard-library/constructing-input-stream-objects.md)

[Usando operadores de extração](../standard-library/using-extraction-operators.md)

[Testando erros de extração](../standard-library/testing-for-extraction-errors.md)

[Manipuladores de fluxo de entrada](../standard-library/input-stream-manipulators.md)

[Funções membro de fluxo de entrada](../standard-library/input-stream-member-functions.md)

[Sobrecarregando o operador >> para suas próprias classes](../standard-library/overloading-the-input-operator-for-your-own-classes.md)

## <a name="see-also"></a>Consulte também

[Programação de iostream](../standard-library/iostream-programming.md)<br/>
