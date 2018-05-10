---
title: _SCL_SECURE_NO_WARNINGS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
dev_langs:
- C++
helpviewer_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
ms.assetid: ef0ddea9-7c62-4b53-8b64-5f4fd369776f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ec02ce5aab3d8a7f95ec9020fe3e2a00c1f5bef7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="sclsecurenowarnings"></a>_SCL_SECURE_NO_WARNINGS

Chamar qualquer um dos métodos potencialmente não seguros na biblioteca padrão C++ resulta em [C4996 de aviso do compilador (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Para desabilitar esse aviso, defina a macro **_SCL_SECURE_NO_WARNINGS** no seu código:

```cpp
#define _SCL_SECURE_NO_WARNINGS
```

Se você usar cabeçalhos pré-compilados, colocar esta diretiva no seu arquivo de cabeçalho pré-compilado antes de você incluir qualquer biblioteca de tempo de execução do C ou cabeçalhos de biblioteca padrão. Se você colocá-lo em um arquivo de código de origem individuais antes de incluir o arquivo de cabeçalho pré-compilado, ele será ignorado pelo compilador.

## <a name="remarks"></a>Comentários

Outras maneiras de desabilitar o aviso C4996 incluem:

- Usando a opção do compilador [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md):

   > Cl /D_SCL_SECURE_NO_WARNINGS [outras opções do compilador] cpp

- Usando a opção do compilador [/w](../build/reference/compiler-option-warning-level.md):

   > Cl /wd4996 [outras opções do compilador] cpp

- Usando a diretiva [#pragma warning](../preprocessor/warning.md):

   ```cpp
   #pragma warning(disable:4996)
   ```

Além disso, você pode alterar manualmente o nível de aviso C4996 com a opção do compilador **/w\<l>\<n>**. Por exemplo, para definir o aviso C4996 como nível 4:

> Cl /w44996 [outras opções do compilador] cpp

Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](../build/reference/compiler-option-warning-level.md).

## <a name="see-also"></a>Consulte também

[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)<br/>
