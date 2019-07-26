---
title: '&lt;string_view&gt;'
ms.date: 04/18/2019
helpviewer_keywords:
- string_view header
ms.assetid: a2fb9d00-d7ae-4170-bfea-2dc337aa37cf
ms.openlocfilehash: 47924c3d6bd1a2f45cdbac648f4f563c57ce8939
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459111"
---
# <a name="ltstringviewgt"></a>&lt;string_view&gt;

Define o modelo `basic_string_view` de classe e os tipos e operadores relacionados. (Requer a opção de compilação [std: c++ 17](../build/reference/std-specify-language-standard-version.md) ou posterior.)

## <a name="syntax"></a>Sintaxe

```cpp
#include <string_view>
```

## <a name="remarks"></a>Comentários

A família string_view de especializações de modelo fornece uma maneira eficiente de passar um identificador não proprietário, com exceção segura e somente leitura para os dados de caractere de qualquer objeto como cadeia de caracteres com o primeiro elemento da sequência na posição zero. Um parâmetro de função do `string_view` tipo (que é um typedef `basic_string_view<char>`para) `std::string`pode aceitar argumentos como **Char\*** , ou qualquer outra classe semelhante à de cadeia de caracteres, para a `string_view`qualumaconversãoimplícitaé definido. Da mesma forma, um `wstring_view`parâmetro `u16string_view` de `u32string_view` ou pode aceitar qualquer tipo de cadeia de caracteres para o qual uma conversão implícita é definida. Para obter mais informações, consulte [classe basic_string_view](../standard-library/basic-string-view-class.md).

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[string_view](../standard-library/string-view-typedefs.md#string_view)|Uma especialização do modelo `basic_string_view` de classe com elementos do tipo **Char**.|
|[wstring_view](../standard-library/string-view-typedefs.md#wstring_view)|Uma especialização do modelo `basic_string_view` de classe com elementos do tipo **wchar_t**.|
|[u16string_view](../standard-library/string-view-typedefs.md#u16string_view)|Uma especialização do modelo `basic_string_view` de classe com elementos do tipo. `char16_t`|
|[u32string_view](../standard-library/string-view-typedefs.md#u32string_view)|Uma especialização do modelo `basic_string_view` de classe com elementos do tipo. `char32_t`|

### <a name="operators"></a>Operadores

Os \<operadores de > string_view podem `string_view` comparar objetos com objetos de qualquer tipo de cadeia de caracteres conversível.

|Operador|Descrição|
|-|-|
|[operator!=](../standard-library/string-view-operators.md#op_neq)|Testa se o objeto à esquerda do operador é diferente do objeto à direita.|
|[operator==](../standard-library/string-view-operators.md#op_eq_eq)|Testa se o objeto à esquerda do operador é igual ao objeto à direita.|
|[operator<](../standard-library/string-view-operators.md#op_lt)|Testa se o objeto no lado esquerdo do operador é menor do que o objeto no lado direito.|
|[operator<=](../standard-library/string-view-operators.md#op_lt_eq)|Testa se o objeto à esquerda do operador é menor que ou igual ao objeto à direita.|
|[operator<\<](../standard-library/string-view-operators.md#op_lt_lt)|Uma função de modelo que insere `string_view` um em um fluxo de saída.|
|[operator>](../standard-library/string-view-operators.md#op_gt)|Testa se o objeto no lado esquerdo do operador é maior que o objeto no lado direito.|
|[operator>=](../standard-library/string-view-operators.md#op_gt_eq)|Testa se o objeto à esquerda do operador é maior que ou igual ao objeto à direita.|

### <a name="literals"></a>Literais

|Operador|Descrição|
|-|-|
|[sv](../standard-library/string-view-operators.md#op_sv)|Constrói um `string_view`, `wstring_view`, `u16string_view`ou dependendodotipodeliteraldecadeiadecaracteresaoqualeleéanexado.`u32string_view`|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_string_view](../standard-library/basic-string-view-class.md)|Um modelo de classe que fornece uma exibição somente leitura em uma sequência de objetos de tipo caractere arbitrários.|
|[hash](string-view-hash.md)|Objeto de função que produz um valor de hash para um string_view.|

## <a name="requirements"></a>Requisitos

- **Cabeçalho:** \<> string_view

- **Namespace:** std

- **Opção do compilador:** std: c++ 17 (ou posterior)

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
