---
title: Passagem de argumento CString
ms.date: 11/04/2016
helpviewer_keywords:
- strings [C++], as function input/output
- argument passing [C++]
- arguments [C++], passing
- functions [C++], strings as input/output
- argument passing [C++], C strings
- passing arguments, C strings
- CString objects, passing arguments
- string arguments
ms.assetid: a67bebff-edf1-4cf4-bbff-d1cc6a901099
ms.openlocfilehash: 53977eb47520a20571a2d5ba8aa105c567ff40d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317928"
---
# <a name="cstring-argument-passing"></a>Passagem de argumento CString

Este artigo explica como passar objetos [CString](../atl-mfc-shared/reference/cstringt-class.md) `CString` para funções e como retornar objetos de funções.

## <a name="cstring-argument-passing-conventions"></a><a name="_core_cstring_argument.2d.passing_conventions"></a>Convenções de aprovação de argumentos do CString

Quando você define uma interface de classe, você deve determinar a convenção de aprovação de argumentos para suas funções de membro. Existem algumas regras padrão para `CString` passar e devolver objetos. Se você seguir as regras descritas em [Strings como Entradas de função](#_core_strings_as_function_inputs) e [strings como saídas de função,](#_core_strings_as_function_outputs)você terá um código eficiente e correto.

## <a name="strings-as-function-inputs"></a><a name="_core_strings_as_function_inputs"></a>Cordas como entradas de função

A maneira mais eficiente e `CString` segura de usar um `CString` objeto nas chamadas funções é passar um objeto para a função. Apesar do `CString` nome, um objeto não armazena uma string internamente como uma seqüência de estilo C que tem um exterminador nulo. Em vez `CString` disso, um objeto mantém um controle cuidadoso do número de caracteres que possui. Ter `CString` fornecido um ponteiro LPCTSTR para uma seqüência de seqüência sumida é uma pequena quantidade de trabalho que pode se tornar significativa se o seu código tiver que fazê-lo constantemente. O resultado é temporário porque `CString` qualquer alteração no conteúdo invalida cópias antigas do ponteiro LPCTSTR.

Faz sentido, em alguns casos, fornecer uma seqüência de estilo C. Por exemplo, pode haver uma situação em que uma chamada função é escrita em C e não suporta objetos. Neste caso, coordeno o `CString` parâmetro para LPCTSTR, e a função receberá uma seqüência de terminação nula no estilo C. Você também pode ir na `CString` outra direção `CString` e criar um objeto usando o construtor que aceita um parâmetro de string estilo C.

Se o conteúdo da seqüência for alterado por uma `CString` função,`CString&`declare o parâmetro como uma referência não constante ( ).

## <a name="strings-as-function-outputs"></a><a name="_core_strings_as_function_outputs"></a>Cordas como saídas de função

Normalmente, você `CString` pode devolver `CString` objetos de funções porque os objetos seguem semântica de valor como tipos primitivos. Para retornar uma seqüência somente `CString` de`const CString&`leitura, use uma referência constante (). O exemplo a seguir `CString` ilustra o uso de parâmetros e tipos de retorno:

[!code-cpp[NVC_ATLMFC_Utilities#197](../atl-mfc-shared/codesnippet/cpp/cstring-argument-passing_1.cpp)]

[!code-cpp[NVC_ATLMFC_Utilities#198](../atl-mfc-shared/codesnippet/cpp/cstring-argument-passing_2.cpp)]

## <a name="see-also"></a>Confira também

[Cordas (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)
