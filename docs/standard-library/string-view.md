---
title: '&lt;string_view&gt;'
description: Visão geral de `basic_string_view` que se refere a uma sequência contígua constante de objetos do tipo caractere.
ms.date: 9/4/2020
helpviewer_keywords:
- string_view header
ms.assetid: a2fb9d00-d7ae-4170-bfea-2dc337aa37cf
ms.openlocfilehash: f74f6c5855f71b0df46f585e874002cdb4308e42
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039905"
---
# <a name="ltstring_viewgt"></a>&lt;string_view&gt;

Define o modelo de classe `basic_string_view` e os tipos e operadores relacionados. (Requer a opção de compilação [std: c++ 17](../build/reference/std-specify-language-standard-version.md) ou posterior.)

## <a name="syntax"></a>Sintaxe

```cpp
#include <string_view>
```

## <a name="remarks"></a>Comentários

A `string_view` família de especializações de modelo fornece uma maneira eficiente de passar um identificador não proprietário, de exceção segura e somente leitura para os dados de caractere de qualquer objeto como cadeia de caracteres com o primeiro elemento da sequência na posição zero. Um parâmetro de função do tipo `string_view` (que é um typedef para `basic_string_view<char>` ) pode aceitar argumentos como `std::string` , `char*` ou qualquer outra classe semelhante à de cadeia de caracteres, para a qual uma conversão implícita `string_view` é definida. Da mesma forma, um parâmetro de `wstring_view` `u16string_view` ou `u32string_view` pode aceitar qualquer tipo de cadeia de caracteres para o qual uma conversão implícita é definida. Para obter mais informações, consulte [classe basic_string_view](../standard-library/basic-string-view-class.md).

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[string_view](../standard-library/string-view-typedefs.md#string_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo **`char`** .|
|[wstring_view](../standard-library/string-view-typedefs.md#wstring_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo **`wchar_t`** .|
|[u16string_view](../standard-library/string-view-typedefs.md#u16string_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo **`char16_t`** .|
|[u32string_view](../standard-library/string-view-typedefs.md#u32string_view)|Uma especialização do modelo de classe `basic_string_view` com elementos do tipo **`char32_t`** .|

### <a name="operators"></a>Operadores

Os \<string_view> operadores podem comparar `string_view` objetos com objetos de qualquer tipo de cadeia de caracteres conversível.

|Operador|Descrição|
|-|-|
|[operador! =](../standard-library/string-view-operators.md#op_neq)|Testa se o objeto à esquerda do operador é diferente do objeto à direita.|
|[operador = =](../standard-library/string-view-operators.md#op_eq_eq)|Testa se o objeto à esquerda do operador é igual ao objeto à direita.|
|[<do operador ](../standard-library/string-view-operators.md#op_lt)|Testa se o objeto no lado esquerdo do operador é menor do que o objeto no lado direito.|
|[<do operador =](../standard-library/string-view-operators.md#op_lt_eq)|Testa se o objeto à esquerda do operador é menor que ou igual ao objeto à direita.|
|[<do operador \<](../standard-library/string-view-operators.md#op_lt_lt)|Uma função de modelo que insere um `string_view` em um fluxo de saída.|
|[>do operador ](../standard-library/string-view-operators.md#op_gt)|Testa se o objeto no lado esquerdo do operador é maior que o objeto no lado direito.|
|[>do operador =](../standard-library/string-view-operators.md#op_gt_eq)|Testa se o objeto à esquerda do operador é maior que ou igual ao objeto à direita.|

### <a name="literals"></a>Literais

|Operador|Descrição|
|-|-|
|[SV](../standard-library/string-view-operators.md#op_sv)|Constrói um `string_view` , `wstring_view` , `u16string_view` ou `u32string_view` dependendo do tipo de literal de cadeia de caracteres ao qual ele é anexado.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_string_view](../standard-library/basic-string-view-class.md)|Um modelo de classe que fornece uma exibição somente leitura em uma sequência de objetos de tipo caractere arbitrários.|
|[hash](string-view-hash.md)|Objeto de função que produz um valor de hash para um string_view.|

## <a name="requirements"></a>Requisitos

- **Cabeçalho:**\<string_view>

- **Namespace:** std

- **Opção do compilador:** [std: c++ 17](../build/reference/std-specify-language-standard-version.md) ou posterior.

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
