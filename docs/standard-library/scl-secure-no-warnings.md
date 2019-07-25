---
title: _SCL_SECURE_NO_WARNINGS
ms.date: 11/04/2016
f1_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
helpviewer_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
ms.assetid: ef0ddea9-7c62-4b53-8b64-5f4fd369776f
ms.openlocfilehash: d19d47fe7120301740e1431765fc6edbeaa48c60
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68448201"
---
# <a name="sclsecurenowarnings"></a>_SCL_SECURE_NO_WARNINGS

Chamar qualquer um dos métodos potencialmente inseguros na C++ biblioteca padrão resulta no [aviso do compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Para desabilitar esse aviso, defina a macro _SCL_SECURE_NO_WARNINGS em seu código:

```cpp
#define _SCL_SECURE_NO_WARNINGS
```

Se você usar cabeçalhos pré-compilados, coloque essa diretiva em seu arquivo de cabeçalho pré-compilado antes de incluir uma biblioteca de tempo de execução C ou cabeçalhos de biblioteca padrão. Se você colocá-lo em um arquivo de código-fonte individual antes de incluir o arquivo de cabeçalho pré-compilado, ele será ignorado pelo compilador.

## <a name="remarks"></a>Comentários

Outras maneiras de desabilitar o aviso C4996 incluem:

- Usando a opção do compilador [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md):

   > CL/D_SCL_SECURE_NO_WARNINGS [outras opções de compilador] MyFile. cpp

- Usando a opção do compilador [/w](../build/reference/compiler-option-warning-level.md):

   > CL/wd4996 [outras opções de compilador] MyFile. cpp

- Usando a diretiva [#pragma warning](../preprocessor/warning.md):

   ```cpp
   #pragma warning(disable:4996)
   ```

Além disso, você pode alterar manualmente o nível de aviso C4996 com a opção do compilador **/w\<l>\<n>** . Por exemplo, para definir o aviso C4996 como nível 4:

> CL/w44996 [outras opções de compilador] MyFile. cpp

Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](../build/reference/compiler-option-warning-level.md).

## <a name="see-also"></a>Consulte também

[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)
