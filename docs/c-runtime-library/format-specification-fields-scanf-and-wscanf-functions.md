---
title: 'Campos de especificação de formato: funções scanf e wscanf'
ms.date: 11/04/2016
ms.topic: reference
ms.custom: contperfq1
helpviewer_keywords:
- width, specifications in scanf function
- scanf format specifications
- scanf width specifications
- scanf type field characters
- type fields, scanf function
- format specification fields for scanf function
- type fields
ms.assetid: 7e95de1b-0b71-4de3-9f81-c9560c78e039
ms.openlocfilehash: 4be7aa5e0790f0124890ee981ffd58e3027ea59b
ms.sourcegitcommit: 111ee74772d7f308d3414b5d42cbc1e90287f081
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2020
ms.locfileid: "88659325"
---
# <a name="format-specification-fields-scanf-and-wscanf-functions"></a>Campos de especificação de formato: funções scanf e wscanf

As informações aqui se aplicam a toda a família de funções `scanf`, incluindo as versões seguras e descreve os símbolos usados para informar as funções `scanf` como analisar o fluxo de entrada, como o fluxo de entrada `stdin` para `scanf`, em valores inseridos em variáveis de programa.

Uma especificação de formato tem a seguinte forma:

`%`[`*`] [[width](../c-runtime-library/scanf-width-specification.md)] [{[h &#124; l &#124; ll &#124; I64 &#124; L](../c-runtime-library/scanf-width-specification.md)}][type](../c-runtime-library/scanf-type-field-characters.md)

O argumento `format` especifica a interpretação da entrada e pode conter um ou mais dos seguintes:

- Caracteres de espaço em branco: em branco (' '); tabulação ('\t') ou nova linha ('\n'). Um caractere de espaço em branco faz com que `scanf` leia, mas não armazene todos os caracteres de espaço em branco consecutivos na entrada, até o próximo caractere que não seja de espaço em branco. Um caractere de espaço em branco no formato corresponde a qualquer número (incluindo 0) e combinação de caracteres de espaço em branco na entrada.

- Caracteres que não são de espaço em branco, exceto pelo sinal de porcentagem (`%`). Um caractere que não é de espaço em branco faz com que `scanf` leia, mas não armazene um caractere que não seja de espaço em branco correspondente. Se o próximo caractere no fluxo de entrada não for correspondente, `scanf` será encerrado.

- Especificações de formato, introduzidas pelo sinal de porcentagem (`%`). Uma especificação de formato faz com que `scanf` leia e converta caracteres na entrada em valores de um tipo especificado. O valor é atribuído a um argumento na lista de argumentos.

O formato é lido da esquerda para a direita. Caracteres fora das especificações de formato devem corresponder à sequência de caracteres no fluxo de entrada; os caracteres correspondentes no fluxo de entrada são verificados, mas não armazenados. Se um caractere no fluxo de entrada estiver em conflito com a especificação de formato, `scanf` será encerrado e o caractere será deixado no fluxo de entrada como se não tivesse sido lido.

Quando a primeira especificação de formato é encontrada, o valor do primeiro campo de entrada é convertido de acordo com essa especificação e é armazenado no local especificado pelo primeiro `argument`. A segunda especificação de formato faz com que o segundo campo de entrada seja convertido e armazenado no segundo `argument` e assim por diante, até o final da cadeia de caracteres de formato.

Um campo de entrada é definido como todos os caracteres até o primeiro caractere de espaço em branco (espaço, tabulação ou nova linha), até o primeiro caractere que não possa ser convertido de acordo com a especificação de formato ou até que a largura do campo (se especificada) seja atingida. Se houver muitos argumentos para as especificações fornecidas, os argumentos extra serão avaliados, mas ignorados. Os resultados serão imprevisíveis se não houver argumentos suficientes para a especificação de formato.

Cada campo da especificação de formato é um caractere único ou um número indicando uma opção de formato específico. O caractere `type`, que aparece após o último campo de formato opcional, determina se o campo de entrada é interpretado como um caractere, uma cadeia de caracteres ou um número.

A especificação de formato mais simples contém apenas o sinal de porcentagem e um caractere `type` (por exemplo, `%s`). Se um sinal de porcentagem (`%`) for seguido por um caractere sem nenhum significado, como um caractere de controle de formato, esse caractere e os caracteres seguintes (até o sinal de porcentagem seguinte) serão tratados como uma simples sequência de caracteres, ou seja, uma sequência de caracteres que deve corresponder à entrada. Por exemplo, para especificar que um caractere de sinal de porcentagem deve ser inserido, use `%%`.

Um asterisco (`*`) após o sinal de porcentagem suprime a atribuição do próximo campo de entrada, o que é interpretado como um campo do tipo especificado. O campo é verificado, mas não armazenado.

As versões seguras (aquelas com o sufixo `_s`) da família de funções `scanf` exigem que um parâmetro de tamanho do buffer seja passado imediatamente após cada parâmetro do tipo `c`, `C`, `s`, `S` ou `[`. Para obter mais informações sobre as versões seguras da família de funções `scanf`, consulte [scanf_s, scanf_s_l, wscanf_s, wscanf_s_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md).

## <a name="see-also"></a>Veja também

[Especificação de largura scanf](../c-runtime-library/scanf-width-specification.md)<br/>
[Caracteres de campo do tipo scanf](../c-runtime-library/scanf-type-field-characters.md)<br/>
[scanf, _scanf_l, wscanf, _wscanf_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)
