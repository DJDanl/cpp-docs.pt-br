---
title: Operações CString básicas
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects, basic operations
- string literals, CString operations
- literal strings, CString operations
- CString objects
- string comparison, CString operations
- characters, accessing in CStrings
ms.assetid: 41db66b2-9427-4bb3-845a-9b6869159a6c
ms.openlocfilehash: fa46e82f19d87c49f652779d0e86e78549935965
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220893"
---
# <a name="basic-cstring-operations"></a>Operações CString básicas

Este tópico explica as seguintes operações básicas de [CString](../atl-mfc-shared/reference/cstringt-class.md) :

- [Criando objetos CString a partir de cadeias de caracteres literais C padrão](#_core_creating_cstring_objects_from_standard_c_literal_strings)

- [Acessando caracteres individuais em uma CString](#_core_accessing_individual_characters_in_a_cstring)

- [Concatenando dois objetos CString](#_core_concatenating_two_cstring_objects)

- [Comparando objetos CString](#_core_comparing_cstring_objects)

- [Convertendo objetos CString](#_core_converting_cstring_objects)

`Class CString`baseia-se na [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)do modelo de classe. `CString`é um **`typedef`** de `CStringT` . Mais exatamente, `CString` é uma **`typedef`** *especialização explícita* do `CStringT` , que é uma maneira comum de usar um modelo de classe para definir uma classe. As classes definidas da mesma forma são `CStringA` e `CStringW` .

`CString`, `CStringA` e `CStringW` são definidos em atlstr. h. `CStringT`é definido em CStringT. h.

`CString`, `CStringA` e `CStringW` cada um Obtém um conjunto de métodos e operadores definidos pelo `CStringT` para uso com os dados de cadeia de caracteres aos quais eles dão suporte. Alguns dos métodos duplicados e, em alguns casos, superam os serviços de cadeia de caracteres das bibliotecas de tempo de execução do C.

Observação: `CString` é uma classe nativa. Para uma classe de cadeia de caracteres que é para uso em um projeto gerenciado C++/CLI, use `System.String` .

## <a name="creating-cstring-objects-from-standard-c-literal-strings"></a><a name="_core_creating_cstring_objects_from_standard_c_literal_strings"></a>Criando objetos CString a partir de cadeias de caracteres literais C padrão

Você pode atribuir cadeias de caracteres literais em estilo C `CString` como você pode atribuir um `CString` objeto a outro.

- Atribua o valor de uma cadeia de caracteres literal C a um `CString` objeto.

   [!code-cpp[NVC_ATLMFC_Utilities#183](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_1.cpp)]

- Atribua o valor de um `CString` para outro `CString` objeto.

   [!code-cpp[NVC_ATLMFC_Utilities#184](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_2.cpp)]

   O conteúdo de um `CString` objeto é copiado quando um `CString` objeto é atribuído a outro. Portanto, as duas cadeias de caracteres não compartilham uma referência para os valores reais que compõem a cadeia de caracteres. Para obter mais informações sobre como usar `CString` objetos como valores, consulte a [semântica de CString](../atl-mfc-shared/cstring-semantics.md).

   > [!NOTE]
   > Para escrever seu aplicativo para que ele possa ser compilado para Unicode ou para ANSI, cadeias de caracteres literais de código usando a macro _T. Para obter mais informações, consulte [suporte a MBCS (conjunto de caracteres multibyte) e Unicode](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).

## <a name="accessing-individual-characters-in-a-cstring"></a><a name="_core_accessing_individual_characters_in_a_cstring"></a>Acessando caracteres individuais em uma CString

Você pode acessar caracteres individuais em um `CString` objeto usando os `GetAt` métodos e `SetAt` . Você também pode usar o elemento de matriz, ou subscrito, Operator ([]) em vez de `GetAt` para obter caracteres individuais. (Isso se assemelha a acessar elementos de matriz por índice, como nas cadeias de estilo C padrão.) Os valores de índice para `CString` caracteres são baseados em zero.

## <a name="concatenating-two-cstring-objects"></a><a name="_core_concatenating_two_cstring_objects"></a>Concatenando dois objetos CString

Para concatenar dois `CString` objetos, use os operadores de concatenação (+ ou + =), da seguinte maneira.

[!code-cpp[NVC_ATLMFC_Utilities#185](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_3.cpp)]

Pelo menos um argumento para os operadores de concatenação (+ ou + =) deve ser um `CString` objeto, mas você pode usar uma cadeia de caracteres constante (por exemplo, `"big"` ) ou um **`char`** (por exemplo, ' x ') para o outro argumento.

## <a name="comparing-cstring-objects"></a><a name="_core_comparing_cstring_objects"></a>Comparando objetos CString

O `Compare` método e o operador = = `CString` são equivalentes. `Compare`, **Operator = =** e `CompareNoCase` são MBCS e com reconhecimento de Unicode; `CompareNoCase` também não diferencia maiúsculas de minúsculas. O `Collate` método de `CString` é sensível à localidade e geralmente é mais lento do que `Compare` . Use `Collate` apenas onde você deve obedecer às regras de classificação conforme especificado pela localidade atual.

A tabela a seguir mostra as funções de comparação de [CString](../atl-mfc-shared/reference/cstringt-class.md) disponíveis e suas funções Unicode/MBCS-portátil equivalentes na biblioteca de tempo de execução do C.

|Função CString|Função MBCS|Função Unicode|
|----------------------|-------------------|----------------------|
|`Compare`|`_mbscmp`|`wcscmp`|
|`CompareNoCase`|`_mbsicmp`|`_wcsicmp`|
|`Collate`|`_mbscoll`|`wcscoll`|

O `CStringT` modelo de classe define os operadores relacionais (<, \<=, > =, >, = = e! =), que estão disponíveis para uso pelo `CString` . Você pode comparar dois `CStrings` usando esses operadores, conforme mostrado no exemplo a seguir.

[!code-cpp[NVC_ATLMFC_Utilities#186](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_4.cpp)]

## <a name="converting-cstring-objects"></a><a name="_core_converting_cstring_objects"></a>Convertendo objetos CString

Para obter informações sobre como converter objetos CString em outros tipos de cadeia de caracteres, consulte [como converter entre vários tipos de cadeia de caracteres](../text/how-to-convert-between-various-string-types.md).

## <a name="using-cstring-with-wcout"></a>Usando CString com wcout

Para usar um CString com `wcout` , você deve converter explicitamente o objeto em um `const wchar_t*` , conforme mostrado no exemplo a seguir:

```cpp
CString cs("meow");

wcout << (const wchar_t*) cs << endl;
```

Sem a conversão, `cs` é tratado como um **`void*`** e `wcout` imprime o endereço do objeto. Esse comportamento é causado por interações sutis entre dedução de argumento de modelo e resolução de sobrecarga que estão em si estão corretas e em conformidade com o padrão C++.

## <a name="see-also"></a>Confira também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)<br/>
[Especialização de modelo](../cpp/template-specialization-cpp.md)<br/>
[Como converter entre vários tipos de cadeia de caracteres](../text/how-to-convert-between-various-string-types.md)
