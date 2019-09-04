---
title: '#Diretiva error (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#error'
helpviewer_keywords:
- '#error directive'
- preprocessor, directives
- error directive (#error directive)
ms.assetid: d550a802-ff19-4347-9597-688935d23b2b
ms.openlocfilehash: bfb5c18f20319e6e6d345f28d3e1850714334b71
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216113"
---
# <a name="error-directive-cc"></a>Diretiva de #error (CC++/)

A diretiva **#error** emite uma mensagem de erro especificada pelo usuário no momento da compilação e, em seguida, encerra a compilação.

## <a name="syntax"></a>Sintaxe

> **#error** *cadeia de caracteres de token*

## <a name="remarks"></a>Comentários

A mensagem de erro que essa diretiva emite inclui o parâmetro *token-String* . O parâmetro *de cadeia de caracteres de token* não está sujeito à expansão de macro. Essa diretiva é mais útil durante o pré-processamento, para notificar o desenvolvedor de uma inconsistência de programa ou a violação de uma restrição. O exemplo a seguir demonstra o processamento do erro durante pré-processamento:

```cpp
#if !defined(__cplusplus)
#error C++ compiler required.
#endif
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
