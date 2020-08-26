---
title: '&lt;iomanip&gt;'
ms.date: 11/04/2016
f1_keywords:
- iomanip/std::<iomanip>
- <iomanip>
helpviewer_keywords:
- iomanip header
ms.assetid: 3681c346-4763-4037-bba4-cf0dc3447974
ms.openlocfilehash: f3f6c4886d22c7cd12b29950c114fbcde8905c28
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845738"
---
# <a name="ltiomanipgt"></a>&lt;iomanip&gt;

Inclua o cabeçalho padrão \<iomanip> de `iostreams` para definir vários manipuladores que usam um único argumento cada.

## <a name="syntax"></a>Sintaxe

```cpp
#include <iomanip>
```

## <a name="remarks"></a>Comentários

Cada um desses manipuladores retorna um tipo não especificado, chamado `T1` por meio do `T10` , que sobrecarrega o `basic_istream` \<**Elem**, **Tr**> `::` [operador>>](../standard-library/istream-operators.md#op_gt_gt) e o `basic_ostream` \<**Elem**, **Tr**> `::` [operador<<](../standard-library/ostream-operators.md#op_lt_lt).

### <a name="manipulators"></a>Manipuladores

|Nome|Descrição|
|-|-|
|[get_money](../standard-library/iomanip-functions.md#iomanip_get_money)|Obtém um valor monetário, que pode estar no formato internacional.|
|[get_time](../standard-library/iomanip-functions.md#iomanip_get_time)|Obtém uma hora em uma estrutura de horas usando um formato especificado.|
|[put_money](../standard-library/iomanip-functions.md#iomanip_put_money)|Fornece um valor monetário, que pode estar no formato internacional.|
|[put_time](../standard-library/iomanip-functions.md#iomanip_put_time)|Fornece uma hora em uma estrutura de horas e uma cadeia de caracteres de formato para ser usada.|
|[aspas](../standard-library/iomanip-functions.md#quoted)|Permite o ciclo conveniente de cadeias de caracteres, com operadores de inserção e extração.|
|[resetiosflags](../standard-library/iomanip-functions.md#resetiosflags)|Limpa os sinalizadores especificados.|
|[SetBase](../standard-library/iomanip-functions.md#setbase)|Define a base para inteiros.|
|[setfill](../standard-library/iomanip-functions.md#setfill)|Define o caractere que será usado para preencher espaços em uma exibição justificada à direita.|
|[setiosflags](../standard-library/iomanip-functions.md#setiosflags)|Define os sinalizadores especificados.|
|[setprecision](../standard-library/iomanip-functions.md#setprecision)|Define a precisão dos valores de ponto flutuante.|
|[setw](../standard-library/iomanip-functions.md#setw)|Especifica a largura do campo de exibição.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
