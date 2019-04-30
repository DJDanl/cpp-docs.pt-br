---
title: '&lt;string_view&gt;'
ms.date: 04/18/2019
helpviewer_keywords:
- string_view header
ms.assetid: a2fb9d00-d7ae-4170-bfea-2dc337aa37cf
ms.openlocfilehash: 8952416cf37fc4d8d281d6ced9b8264495ec3799
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346974"
---
# <a name="ltstringviewgt"></a>&lt;string_view&gt;

Define o modelo de classe `basic_string_view` e relacionadas a tipos e operadores. (Requer a opção de compilador [/std: c + + 17](../build/reference/std-specify-language-standard-version.md) ou posterior.)

## <a name="syntax"></a>Sintaxe

```cpp
#include <string_view>
```

## <a name="remarks"></a>Comentários

A família de string_view de especializações de modelo fornece uma maneira eficiente de passar um identificador somente leitura, à prova de exceções, não proprietário para os dados de caracteres de qualquer objeto de cadeia de caracteres semelhante com o primeiro elemento da sequência na posição zero. Um parâmetro de função do tipo `string_view` (que é um typedef para `basic_string_view<char>`) podem aceitar argumentos como `std::string`, **char\***, ou qualquer outra classe de tipo de cadeia de caracteres de caracteres estreitos para os quais implícito a conversão em `string_view` está definido. Da mesma forma, um parâmetro de `wstring_view`, `u16string_view` ou `u32string_view` pode aceitar qualquer tipo de cadeia de caracteres para o qual uma conversão implícita é definida. Para obter mais informações, consulte [basic_string_view classe](../standard-library/basic-string-view-class.md).

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[string_view](../standard-library/string-view-typedefs.md#string_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo **char**.|
|[wstring_view](../standard-library/string-view-typedefs.md#wstring_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo **wchar_t**.|
|[u16string_view](../standard-library/string-view-typedefs.md#u16string_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo `char16_t`.|
|[u32string_view](../standard-library/string-view-typedefs.md#u32string_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo `char32_t`.|

### <a name="operators"></a>Operadores

O \<string_view > operadores podem comparar `string_view` objetos em objetos de qualquer podem ser convertidas em tipos de cadeia de caracteres.

|Operador|Descrição|
|-|-|
|[operator!=](../standard-library/string-view-operators.md#op_neq)|Testa se o objeto à esquerda do operador é diferente do objeto à direita.|
|[operator==](../standard-library/string-view-operators.md#op_eq_eq)|Testa se o objeto à esquerda do operador é igual ao objeto à direita.|
|[operator<](../standard-library/string-view-operators.md#op_lt)|Testa se o objeto no lado esquerdo do operador é menor que o objeto no lado direito.|
|[operator<=](../standard-library/string-view-operators.md#op_lt_eq)|Testa se o objeto à esquerda do operador é menor que ou igual ao objeto à direita.|
|[operator<\<](../standard-library/string-view-operators.md#op_lt_lt)|Uma função de modelo que insere um `string_view` em um fluxo de saída.|
|[operator>](../standard-library/string-view-operators.md#op_gt)|Testa se o objeto no lado esquerdo do operador é maior do que para o objeto no lado direito.|
|[operator>=](../standard-library/string-view-operators.md#op_gt_eq)|Testa se o objeto à esquerda do operador é maior que ou igual ao objeto à direita.|

### <a name="literals"></a>Literais

|Operador|Descrição|
|-|-|
|[sv](../standard-library/string-view-operators.md#op_sv)|Constrói uma `string_view`, `wstring_view`, `u16string_view`, ou `u32string_view` dependendo do tipo de cadeia de caracteres literal ao qual ele é acrescentado.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_string_view](../standard-library/basic-string-view-class.md)|Um modelo de classe que fornece uma exibição somente leitura em uma sequência de objetos arbitrários do tipo caractere.|
|[hash](string-view-hash.md)|Objeto de função que produz um valor de hash para um string_view.|

## <a name="requirements"></a>Requisitos

- **Cabeçalho:** \<string_view >

- **Namespace:** std

- **Opção de compilador:** /std: c + + 17 (ou posterior)

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
