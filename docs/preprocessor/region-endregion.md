---
title: region, endregion
ms.date: 10/18/2018
f1_keywords:
- vc-pragma.endregion
- endregion_CPP
- region_CPP
- vc-pragma.region
helpviewer_keywords:
- pragmas, region
- pragmas, endregion
- endregion pragma
- region pragma
ms.assetid: c697f807-622f-4796-851b-68a42bbecd84
ms.openlocfilehash: c73a90aa2be83d643b74dde4645081e89da3ff73
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037919"
---
# <a name="region-endregion"></a>region, endregion

`#pragma region` permite que você especifique um bloco de código que você pode expandir ou recolher ao usar o [recurso de estrutura de tópicos](/visualstudio/ide/outlining) do Editor de código do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
#pragma region name
#pragma endregion comment
```

### <a name="parameters"></a>Parâmetros

*comment*<br/>
(Opcional) Um comentário que será exibido no editor de códigos.

*name*<br/>
(Opcional) O nome da região.  Esse nome será exibido no editor de códigos.

## <a name="remarks"></a>Comentários

`#pragma endregion` marca o fim de um `#pragma region` bloco.

Um `#region` bloco deverá ser encerrado com `#pragma endregion`.

## <a name="example"></a>Exemplo

```cpp
// pragma_directives_region.cpp
#pragma region Region_1
void Test() {}
void Test2() {}
void Test3() {}
#pragma endregion Region_1

int main() {}
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)