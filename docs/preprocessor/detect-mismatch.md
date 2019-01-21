---
title: detect_mismatch
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.detect_mismatch
- detect_mismatch_CPP
helpviewer_keywords:
- pragmas, detect_mismatch
- detect_mismatch pragma
ms.assetid: ddb13ac9-0e2f-40ce-be69-7e44c04f5a12
ms.openlocfilehash: fb6f147f1591f010298e84cb28f05b40dafaeb63
ms.sourcegitcommit: 22f7c4a9b4fc2158fb5283810f15275803cafe10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/21/2019
ms.locfileid: "54417623"
---
# <a name="detectmismatch"></a>detect_mismatch
Coloca um registro em um objeto. O vinculador verifica possíveis incompatibilidades nesses registros.

## <a name="syntax"></a>Sintaxe

```
#pragma detect_mismatch("name", "value")
```

## <a name="remarks"></a>Comentários

Ao vincular o projeto, o vinculador lança um erro `LNK2038` se o projeto contiver dois objetos que tenham o mesmo `name` mas dois `value`diferentes. Use este pragma para impedir que os arquivos de objeto inconsistentes sejam vinculados.

O nome e o valor são literais de cadeia de caracteres e obedecem às regras de literais de cadeia de caracteres em relação aos caracteres de escape e a concatenação. Eles diferenciam maiusculas de minúsculas e não pode conter uma vírgula, o sinal de igual, aspas, ou o **nulo** caractere.

## <a name="example"></a>Exemplo

Este exemplo cria dois arquivos que têm números de versão diferentes para o mesmo rótulo da versão.

```cpp
// pragma_directive_detect_mismatch_a.cpp
#pragma detect_mismatch("myLib_version", "9")
int main ()
{
   return 0;
}

// pragma_directive_detect_mismatch_b.cpp
#pragma detect_mismatch("myLib_version", "1")
```

Se você criar ambos os arquivos usando a linha de comando `cl pragma_directive_detect_mismatch_a.cpp pragma_directive_detect_mismatch_b.cpp`, receberá o erro `LNK2038`.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
