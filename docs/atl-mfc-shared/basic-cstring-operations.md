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
ms.openlocfilehash: 68947dc37e5398ac7caa4754e9af40223cec7bf2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317956"
---
# <a name="basic-cstring-operations"></a>Operações CString básicas

Este tópico explica as seguintes operações básicas [do CString:](../atl-mfc-shared/reference/cstringt-class.md)

- [Criando objetos CString a partir de strings literais padrão C](#_core_creating_cstring_objects_from_standard_c_literal_strings)

- [Acessando caracteres individuais em um CString](#_core_accessing_individual_characters_in_a_cstring)

- [Concatenando dois objetos CString](#_core_concatenating_two_cstring_objects)

- [Comparando objetos CString](#_core_comparing_cstring_objects)

- [Conversão de objetos CString](#_core_converting_cstring_objects)

`Class CString`é baseado no modelo de classe [CStringT Class](../atl-mfc-shared/reference/cstringt-class.md). `CString`é um **typedef** de `CStringT`. Mais exatamente, `CString` é um **typedef** de uma *especialização explícita* de , que é uma maneira comum de usar um modelo de `CStringT`classe para definir uma classe. Classes igualmente `CStringA` definidas são e `CStringW`.

`CString`, `CStringA`e `CStringW` são definidos em atlstr.h. `CStringT`é definido em cstringt.h.

`CString`, `CStringA`e `CStringW` cada um obter um conjunto dos `CStringT` métodos e operadores definidos por para uso com os dados de string que eles suportam. Alguns dos métodos duplicam e, em alguns casos, superam os serviços de string das bibliotecas de tempo de execução C.

Nota: `CString` é uma classe nativa. Para uma classe de strings que é para uso em `System.String`um projeto gerenciado pela C++/CLI, use .

## <a name="creating-cstring-objects-from-standard-c-literal-strings"></a><a name="_core_creating_cstring_objects_from_standard_c_literal_strings"></a>Criando objetos CString a partir de strings literais padrão C

Você pode atribuir strings literais `CString` estilo C a `CString` um assim como você pode atribuir um objeto a outro.

- Atribuir o valor de uma seqüência literal C a um `CString` objeto.

   [!code-cpp[NVC_ATLMFC_Utilities#183](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_1.cpp)]

- Atribuir o valor `CString` de `CString` um para outro objeto.

   [!code-cpp[NVC_ATLMFC_Utilities#184](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_2.cpp)]

   O conteúdo `CString` de um objeto `CString` é copiado quando um objeto é atribuído a outro. Portanto, as duas cordas não compartilham uma referência aos caracteres reais que compõem a seqüência. Para obter mais informações `CString` sobre como usar objetos como valores, consulte [CString Semantics](../atl-mfc-shared/cstring-semantics.md).

   > [!NOTE]
   > Para escrever sua aplicação para que ele possa ser compilado para Unicode ou para ANSI, código strings literais usando a macro _T. Para obter mais informações, consulte [o suporte ao Conjunto de Caracteres Unicode e Multibytes (MBCS).](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md)

## <a name="accessing-individual-characters-in-a-cstring"></a><a name="_core_accessing_individual_characters_in_a_cstring"></a>Acessando caracteres individuais em um CString

Você pode acessar caracteres individuais em um `CString` objeto usando os `GetAt` métodos e `SetAt` métodos. Você também pode usar o elemento matriz, ou subscrito, operador ( [ ] ) em vez de `GetAt` obter caracteres individuais. (Isso se assemelha a acessar elementos de matriz por índice, como nas strings padrão estilo C.) Os valores de índice para `CString` caracteres são baseados em zero.

## <a name="concatenating-two-cstring-objects"></a><a name="_core_concatenating_two_cstring_objects"></a>Concatenando dois objetos CString

Para concatenar dois `CString` objetos, use os operadores de concatenação (+ ou +=), da seguinte forma.

[!code-cpp[NVC_ATLMFC_Utilities#185](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_3.cpp)]

Pelo menos um argumento para os operadores de concatenação `CString` (+ ou +=) deve ser `"big"`um objeto, mas você pode usar uma seqüência de caracteres constante (por exemplo, ) ou um **char** (por exemplo, 'x') para o outro argumento.

## <a name="comparing-cstring-objects"></a><a name="_core_comparing_cstring_objects"></a>Comparando objetos CString

O `Compare` método e o `CString` operador == para são equivalentes. `Compare`, **operador==** `CompareNoCase` , e estão cientes de MBCS e Unicode; `CompareNoCase` também é insensível a casos. O `Collate` método `CString` de é sensível ao local `Compare`e muitas vezes é mais lento do que . Use `Collate` somente onde você deve cumprir as regras de classificação conforme especificado pelo local atual.

A tabela a seguir mostra as funções de comparação [CString](../atl-mfc-shared/reference/cstringt-class.md) disponíveis e suas funções portáteis Unicode/MBCS equivalentes na biblioteca de tempo de execução C.

|Função CString|Função MBCS|Função Unicode|
|----------------------|-------------------|----------------------|
|`Compare`|`_mbscmp`|`wcscmp`|
|`CompareNoCase`|`_mbsicmp`|`_wcsicmp`|
|`Collate`|`_mbscoll`|`wcscoll`|

O `CStringT` modelo de classe define os operadores relacionais (<, \<=, >=, >, `CString`==, e !=), que estão disponíveis para uso por . Você pode `CStrings` comparar dois usando esses operadores, como mostrado no exemplo a seguir.

[!code-cpp[NVC_ATLMFC_Utilities#186](../atl-mfc-shared/codesnippet/cpp/basic-cstring-operations_4.cpp)]

## <a name="converting-cstring-objects"></a><a name="_core_converting_cstring_objects"></a>Conversão de objetos CString

Para obter informações sobre a conversão de objetos CString para outros tipos de strings, consulte [Como: Converter entre vários tipos de strings](../text/how-to-convert-between-various-string-types.md).

## <a name="using-cstring-with-wcout"></a>Usando CString com wcout

Para usar um `wcout` CString com você, o `const wchar_t*` objeto deve lançar explicitamente o objeto para um como mostrado no exemplo a seguir:

```cpp
CString cs("meow");

wcout << (const wchar_t*) cs << endl;
```

Sem o `cs` gesso, `void*` é `wcout` tratado como um e imprime o endereço do objeto. Esse comportamento é causado por interações sutis entre a dedução do argumento do modelo e a resolução de sobrecarga que estão em si corretas e em conformidade com o padrão C++.

## <a name="see-also"></a>Confira também

[Cordas (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Classe Cstringt](../atl-mfc-shared/reference/cstringt-class.md)<br/>
[Especialização de modelo](../cpp/template-specialization-cpp.md)<br/>
[Como converter entre diversos tipos de cadeias de caracteres](../text/how-to-convert-between-various-string-types.md)
