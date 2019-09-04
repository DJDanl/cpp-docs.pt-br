---
title: Pragmas region, endregion
ms.date: 08/29/2019
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
ms.openlocfilehash: 4a01e04582ac81d678aa0702945c62ee974a4428
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222381"
---
# <a name="region-endregion-pragmas"></a>Pragmas region, endregion

`#pragma region`permite especificar um bloco de código que você pode expandir ou recolher ao usar o [recurso de estrutura de tópicos](/visualstudio/ide/outlining) do Editor de Visual Studio Code.

## <a name="syntax"></a>Sintaxe

> **região de #pragma** *nome* do\
> **#pragma** fim da região *Comentário*

### <a name="parameters"></a>Parâmetros

*mente*\
Adicional Um comentário a ser exibido no editor de código.

*nomes*\
Adicional O nome da região. Esse nome é exibido no editor de código.

## <a name="remarks"></a>Comentários

`#pragma endregion`marca o final de um `#pragma region` bloco.

Um `#region` bloco deve ser terminado por uma `#pragma endregion` diretiva.

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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
