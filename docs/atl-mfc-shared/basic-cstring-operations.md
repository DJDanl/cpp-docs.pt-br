---
title: Operações CString básicas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CString objects, basic operations
- string literals, CString operations
- literal strings, CString operations
- CString objects
- string comparison, CString operations
- characters, accessing in CStrings
ms.assetid: 41db66b2-9427-4bb3-845a-9b6869159a6c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ab2c857451e399e56e69d79240d4ace023a8b301
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46424073"
---
# <a name="basic-cstring-operations"></a>Operações CString básicas

Este tópico explica o seguinte basic [CString](../atl-mfc-shared/reference/cstringt-class.md) operações:

- [Criando objetos CString do padrão C cadeias de caracteres literais](#_core_creating_cstring_objects_from_standard_c_literal_strings)

- [Acessando caracteres individuais em um CString](#_core_accessing_individual_characters_in_a_cstring)

- [Concatenação de dois objetos CString](#_core_concatenating_two_cstring_objects)

- [Comparando objetos CString](#_core_comparing_cstring_objects)

- [Convertendo objetos CString](#_core_converting_cstring_objects)

`Class CString` é baseado no modelo de classe [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md). `CString` é um **typedef** de `CStringT`. Mais exatamente, `CString` é um **typedef** de uma *especialização explícita* de `CStringT`, que é uma maneira comum de usar um modelo de classe para definir uma classe. São classes definidas da mesma forma `CStringA` e `CStringW`.

`CString`, `CStringA`, e `CStringW` são definidos no atlstr. h. `CStringT` é definido em cstringt. h.

`CString`, `CStringA`, e `CStringW` cada um obtém um conjunto de métodos e operadores definidos pelo `CStringT` para uso com os dados de cadeia de caracteres que eles oferecem suporte. Alguns dos métodos duplicados e, em alguns casos, ultrapassam os serviços de cadeia de caracteres das bibliotecas de tempo de execução C.

Observação: `CString` é uma classe nativa. Para uma classe de cadeia de caracteres que é para uso em uma C + + c++ CLI gerenciados projeto, use `System.String`.

##  <a name="_core_creating_cstring_objects_from_standard_c_literal_strings"></a> Criando objetos CString de cadeias de caracteres Literal C padrão

Você pode atribuir cadeias de caracteres de literais de C-style para um `CString` exatamente como você pode atribuir uma `CString` objeto para outro.

- Atribua o valor de uma cadeia de caracteres literal C para um `CString` objeto.

   [!code-cpp[NVC_ATLMFC_Utilities#183](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_1.cpp)]

- Atribua o valor de um `CString` para outro `CString` objeto.

   [!code-cpp[NVC_ATLMFC_Utilities#184](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_2.cpp)]

   O conteúdo de um `CString` objeto são copiadas quando um `CString` objeto é atribuído a outro. Portanto, duas cadeias de caracteres não compartilham uma referência para os caracteres reais que formam a cadeia de caracteres. Para obter mais informações sobre como usar `CString` objetos como valores, consulte [semântica de CString](../atl-mfc-shared/cstring-semantics.md).

   > [!NOTE]
   > Para escrever seu aplicativo para que ele pode ser compilado para Unicode ou ANSI, cadeias de caracteres de literais de código usando a macro t. Para obter mais informações, consulte [suporte a Unicode e conjunto de caracteres Multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).

##  <a name="_core_accessing_individual_characters_in_a_cstring"></a> Acessando caracteres individuais em um CString

Você pode acessar os caracteres individuais em uma `CString` objeto usando o `GetAt` e `SetAt` métodos. Você também pode usar o elemento ou subscrito, operador de matriz ([]), em vez de `GetAt` obter caracteres individuais. (Isso é semelhante a acessar elementos da matriz por índice, como em cadeias de caracteres de estilo C padrão.) Indexar valores para `CString` caracteres são baseados em zero.

##  <a name="_core_concatenating_two_cstring_objects"></a> Concatenação de dois objetos CString

Para concatenar duas `CString` objetos, use os operadores de concatenação (+ ou + =), da seguinte maneira.

[!code-cpp[NVC_ATLMFC_Utilities#185](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_3.cpp)]

Pelo menos um argumento para os operadores de concatenação (+ ou + =) deve ser um `CString` objeto, mas você pode usar uma cadeia de caracteres constante (por exemplo, `"big"`) ou um **char** (por exemplo, ' x') para o outro argumento.

##  <a name="_core_comparing_cstring_objects"></a> Comparando objetos CString

O `Compare` método e o operador de = = `CString` são equivalentes. `Compare`, **operador = =**, e `CompareNoCase` reconhecem MBCS e Unicode; `CompareNoCase` também diferencia maiusculas de minúsculas. O `Collate` método de `CString` é sensível à localidade e costuma ser mais lento do que `Compare`. Use `Collate` apenas onde você deve concordar com a classificação de regras conforme especificado pela localidade atual.

A tabela a seguir mostra o disponíveis [CString](../atl-mfc-shared/reference/cstringt-class.md) funções de comparação e suas funções Unicode/MBCS-portable equivalentes na biblioteca de tempo de execução C.

|Função de CString|Função MBCS|Função Unicode|
|----------------------|-------------------|----------------------|
|`Compare`|`_mbscmp`|`wcscmp`|
|`CompareNoCase`|`_mbsicmp`|`_wcsicmp`|
|`Collate`|`_mbscoll`|`wcscoll`|

O `CStringT` modelo de classe define os operadores relacionais (<, \<=, > =, >, = =, e! =), que estão disponíveis para uso por `CString`. Você pode comparar dois `CStrings` usando esses operadores, conforme mostrado no exemplo a seguir.

[!code-cpp[NVC_ATLMFC_Utilities#186](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_4.cpp)]

##  <a name="_core_converting_cstring_objects"></a> Convertendo objetos CString

Para obter informações sobre como converter objetos CString para outros tipos de cadeia de caracteres, consulte [como: converter entre vários tipos de cadeia de caracteres](../text/how-to-convert-between-various-string-types.md).

## <a name="using-cstring-with-wcout"></a>Usando CString com wcout

Para usar um CString com `wcout` é necessário converter explicitamente o objeto a ser um `const wchar_t*` conforme mostrado no exemplo a seguir:

```
CString cs("meow");

    wcout <<(const wchar_t*) cs <<endl;

```

Sem a conversão `cs` é tratado como uma `void*` e `wcout` imprime o endereço do objeto. Esse comportamento é causado pelas interações sutis entre o modelo dedução e sobrecarga de resolução do argumento que são eles próprios correto e compatível com o padrão C++.

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)<br/>
[Especialização de modelo](../cpp/template-specialization-cpp.md)<br/>
[Como converter entre diversos tipos de cadeias de caracteres](../text/how-to-convert-between-various-string-types.md)

