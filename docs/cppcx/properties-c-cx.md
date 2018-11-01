---
title: Propriedades (C++/CX)
ms.date: 01/22/2017
ms.assetid: 64c7bc56-3191-4cd5-bdf4-476d07d285d5
ms.openlocfilehash: a4aadb853ac26d353cbee5f7c0c81436a4c1dfc9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50609386"
---
# <a name="properties-ccx"></a>Propriedades (C++/CX)

Tipos de tempo de execução do Windows expõem dados públicos como propriedades. O código de cliente acessa a propriedade como um datamember público. Internamente, a propriedade é implementada como um bloco que contém um método acessador get, um método acessador set ou ambos. Usando os métodos acessadores, você pode executar ações adicionais antes ou depois de recuperar o valor, por exemplo, você pode disparar um evento ou executar verificações de validação.

### <a name="remarks"></a>Comentários

O valor de uma propriedade está contido em uma variável particular — conhecida como *repositório de backup*— que é do mesmo tipo da propriedade. Uma propriedade pode conter um acessador set, que atribui um valor ao repositório de backup, e um acessador get que recupera o valor do repositório de backup. A propriedade será somente leitura se fornecer um acessador get, somente gravação se fornecer um acessador set, e leitura/gravação (modificável) se fornecer ambos os acessadores.

Uma propriedade *trivial* é uma propriedade de leitura/gravação para a qual o compilador implementa automaticamente os acessadores e o repositório de backup. Você não tem acesso à implementação do compilador. No entanto, você pode declarar uma propriedade personalizada e declarar explicitamente seus acessadores e repositório de backup. Em um acessador, você pode executar qualquer lógica que seja necessária, como validar a entrada para o acessador set, calcular um valor com base no valor da propriedade, acessar um banco de dados ou disparar um evento quando a propriedade for alterada.

Quando uma classe de referência C++/CX é instanciada, sua memória é inicializada do zero antes que seu construtor seja chamado; no entanto, são atribuídos valores de zero padrão a todas as propriedades ou nullptr no ponto de declaração.

### <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra como declarar e acessar uma propriedade. A primeira propriedade, `Name`, é conhecida como *trivial* porque o compilador gera automaticamente um acessador `set` , um acessador `get` e um repositório de backup.

A segunda propriedade, `Doctor`, é uma propriedade somente leitura porque especifica um *bloco property* que declara explicitamente apenas um acessador `get` . Como o bloco property é declarado, você deve declarar explicitamente um repositório de backup; ou seja, a variável String^ particular `doctor_`. Geralmente, uma propriedade somente leitura retorna apenas o valor do repositório de backup. Apenas a própria classe pode definir o valor do armazenamento de backup, normalmente no construtor.

A terceira propriedade, `Quantity`, é uma propriedade de leitura-gravação porque declara um bloco property que declara tanto um acessador `set` quanto um acessador `get` .

O acessador `set` executa um teste de validade definido pelo usuário no valor atribuído. E, diferentemente do C#, aqui o nome *valor* é apenas o identificador do parâmetro no acessador `set` ; não é uma palavra-chave. Se o *valor* não for maior que zero, será gerada a Platform::InvalidArgumentException. Caso contrário, o repositório de backup, `quantity_`, será atualizado com o valor atribuído.

Observe que uma propriedade não pode ser inicializada em uma lista de membros. Naturalmente, você pode inicializar variáveis de armazenamento de backup em uma lista de membros.

[!code-cpp[cx_properties#01](../cppcx/codesnippet/CPP/cx_properties/class1.h#01)]

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)