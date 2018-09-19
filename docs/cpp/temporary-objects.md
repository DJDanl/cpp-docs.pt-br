---
title: Objetos temporários | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- temporary objects
- objects [C++], temporary
ms.assetid: 4c8cec02-391e-4225-9bc6-06d150201412
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3aea9e17d17008642f9421beb47be38cac401132
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46071302"
---
# <a name="temporary-objects"></a>Objetos temporários

Em alguns casos, é necessário que o compilador crie objetos temporários. Esses objetos temporários podem ser criados pelos seguintes motivos:

- Para inicializar uma **const** referência com um inicializador de um tipo diferente do tipo subjacente da referência que está sendo inicializado.

- Para armazenar o valor de retorno de uma função que retorna um tipo definido pelo usuário. Esses temporários só serão criados quando o programa não copia o valor de retorno para um objeto. Por exemplo:

    ```cpp
    UDT Func1();    //  Declare a function that returns a user-defined
                    //   type.

    ...

    Func1();        //  Call Func1, but discard return value.
                    //  A temporary object is created to store the return
                    //   value.
    ```

     Como o valor de retorno não é copiado a outro objeto, um objeto temporário será criado. Um caso comum mais comum onde os temporários são criados é durante a avaliação de uma expressão onde as funções sobrecarregadas do operador devem ser chamadas. Essas funções sobrecarregadas do operador retornam um tipo definido pelo usuário que geralmente não é copiado a outro objeto.

     Considere a expressão `ComplexResult = Complex1 + Complex2 + Complex3`. A expressão `Complex1 + Complex2` é avaliada, e o resultado é armazenado em um objeto temporário. Em seguida, a expressão *temporária* `+ Complex3` é avaliada, e o resultado é copiado para `ComplexResult` (o supondo que o operador de atribuição não seja sobrecarregado).

- Para armazenar o resultado de uma conversão em um tipo definido pelo usuário. Quando um objeto de um determinado tipo é convertido explicitamente em um tipo definido pelo usuário, o novo objeto é criado como um objeto temporário.

Os objetos temporários têm um tempo de vida definido pelo ponto de criação e pelo ponto em que são destruídos. Qualquer expressão que cria mais de um objeto temporário acaba destruindo-os na ordem inversa da qual foram criados. Os pontos em que a destruição ocorre são mostrados na tabela a seguir.

### <a name="destruction-points-for-temporary-objects"></a>Pontos de destruição para objetos temporários

|Motivo temporário criado|Ponto de destruição|
|------------------------------|-----------------------|
|Resultado da avaliação de expressão|Todos os temporaries criados como resultado da avaliação da expressão são destruídos no final da instrução de expressão (ou seja, em que o ponto e vírgula), ou no final das expressões de controle para **para**, **se**, **enquanto**, **fazer**, e **alternar** instruções.|
|Inicializando **const** referências|Se um inicializador não for um valor l do mesmo tipo da referência que está sendo inicializada, um temporário do tipo de objeto subjacente será criada e inicializada com a expressão de inicialização. Esse objeto temporário será destruído imediatamente depois que o objeto de referência ao qual está associado é destruído.|