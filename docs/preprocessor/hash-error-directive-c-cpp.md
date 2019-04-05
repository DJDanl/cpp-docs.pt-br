---
title: '#Erro de diretiva (C/C++)'
ms.date: 11/04/2016
f1_keywords:
- '#error'
helpviewer_keywords:
- '#error directive'
- preprocessor, directives
- error directive (#error directive)
ms.assetid: d550a802-ff19-4347-9597-688935d23b2b
ms.openlocfilehash: dc229a8eae6938cba32787ecbec6a5aa6a17ab47
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037838"
---
# <a name="error-directive-cc"></a>Diretiva #error (C/C++)
O **#error** diretiva emite uma mensagem de erro especificado pelo usuário em tempo de compilação e finaliza a compilação.

## <a name="syntax"></a>Sintaxe

```
#errortoken-string
```

## <a name="remarks"></a>Comentários

A mensagem de erro que esta política emite inclui o *token de cadeia de caracteres* parâmetro. O *token de cadeia de caracteres* parâmetro não está sujeito à expansão de macro. Essa política é mais útil durante o pré-processamento para notificar o desenvolvedor de uma inconsistência do programa ou de uma violação de restrição. O exemplo a seguir demonstra o processamento do erro durante pré-processamento:

```
#if !defined(__cplusplus)
#error C++ compiler required.
#endif
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)