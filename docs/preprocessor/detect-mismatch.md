---
title: Pragma detect_mismatch
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.detect_mismatch
- detect_mismatch_CPP
helpviewer_keywords:
- pragmas, detect_mismatch
- detect_mismatch pragma
ms.assetid: ddb13ac9-0e2f-40ce-be69-7e44c04f5a12
ms.openlocfilehash: 6e247b3f251bce47710a3380fb295597314a3bd8
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222388"
---
# <a name="detect_mismatch-pragma"></a>Pragma detect_mismatch

Coloca um registro em um objeto. O vinculador verifica possíveis incompatibilidades nesses registros.

## <a name="syntax"></a>Sintaxe

> **#pragma detect_mismatch (** "*Name*" **,** "*Value*" **)**

## <a name="remarks"></a>Comentários

Quando você vincular o projeto, o vinculador lançará um erro [LNK2038](../error-messages/tool-errors/linker-tools-error-lnk2038.md) se o projeto contiver dois objetos com o mesmo *nome* , mas cada um tiver um *valor*diferente. Use este pragma para impedir que os arquivos de objeto inconsistentes sejam vinculados.

O *nome* e o *valor* são literais de cadeia de caracteres e obedecem às regras para literais de cadeia de caracteres em relação a caracteres de escape e concatenação. Eles diferenciam maiúsculas de minúsculas e não podem conter uma vírgula, sinal de igual, aspas ou caractere **nulo** .

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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
