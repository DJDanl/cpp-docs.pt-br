---
title: /Zc:inline (remover COMDAT não referenciado)
ms.date: 03/01/2018
f1_keywords:
- /Zc:inline
- VC.Project.VCCLCompilerTool.RemoveUnreferencedCodeData
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Zc compiler options (C++)
- /Zc:inline
ms.assetid: a4c94224-1d73-4bea-a9d5-4fa73dc924df
ms.openlocfilehash: 6855773c6ec807a7488fa5604ddee7fd43983135
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50441230"
---
# <a name="zcinline-remove-unreferenced-comdat"></a>/Zc:inline (remover COMDAT não referenciado)

Remove funções não referenciadas ou dados que sejam COMDATs ou que tenham apenas vínculo interno. Quando **/ZC: inline** for especificado, o compilador exige que as unidades de tradução que usam dados ou funções embutidas também devem incluir as definições para as funções ou dados.

## <a name="syntax"></a>Sintaxe

> **/Zc:inline**[**-**]

## <a name="remarks"></a>Comentários

Quando **/ZC: inline** for especificado, o compilador não emite informações de símbolo para funções COMDAT não referenciadas ou dados, ou para funções ou dados que tenham apenas vínculo interno. Essa otimização simplifica parte do trabalho realizado pelo vinculador em compilações de versão ou quando a opção de vinculador [/OPT: REF](../../build/reference/opt-optimizations.md) for especificado. Ao realizar essa otimização, o compilador pode reduzir significativamente o tamanho do arquivo .obj e aumentar as velocidades do vinculador. Essa opção do compilador não é habilitada quando as otimizações estão desabilitadas ([/Od](../../build/reference/od-disable-debug.md)) ou quando [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md) for especificado.

Por padrão, essa opção está desativada (**/Zc:inline-**). O [/permissive--](permissive-standards-conformance.md) opção não permite **/ZC: inline**.

Se **/ZC: inline** for especificado, o compilador impõe o requisito c++11 de que todas as funções declaradas `inline` deve ter uma definição disponível na mesma unidade de tradução, se eles forem usados. Quando a opção não for especificada, o compilador da Microsoft permite que o código de em não conformidade que invoca as funções declaradas `inline` , mesmo se nenhuma definição estiver visível. Para obter mais informações, consulte o padrão do C++11, nas seções 3.2 e 7.1.2. Essa opção do compilador foi introduzida no Visual Studio 2013 Atualização 2.

Para usar o **/ZC: inline** opção, atualize o código fora de conformidade.

Este exemplo mostra como o uso fora de conformidade de uma declaração de função embutida sem uma definição ainda compila e vincula-se quando o padrão **/Zc:inline-** opção é usada:

```cpp
// example.h
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp
#pragma once

class Example {
public:
   inline void inline_call(); // declared but not defined inline
   void normal_call();
   Example() {};
};
```

```cpp
// example.cpp
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp
#include <stdio.h>
#include "example.h"

void Example::inline_call() {
   printf("inline_call was called.\n");
}

void Example::normal_call() {
   printf("normal_call was called.\n");
   inline_call(); // with /Zc:inline-, inline_call forced into .obj file
}
```

```cpp
// zcinline.cpp
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp
#include "example.h"

void main() {
   Example example;
   example.inline_call(); // normal call when definition unavailable
}
```

Quando **/ZC: inline** estiver habilitada, o mesmo código causa um [LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md) erro, porque o compilador não emite um corpo de código não embutido para `Example::inline_call` em example. Isso faz a chamada não embutida em `main` mencionar um símbolo externo indefinido.

Para resolver esse erro, é possível remover a palavra-chave `inline` da declaração de `Example::inline_call`, mover a definição de `Example::inline_call` para o arquivo de cabeçalho ou mover a implementação de `Example` para main.cpp. O próximo exemplo move a definição para o arquivo de cabeçalho, onde ele permanece visível para qualquer chamador com o cabeçalho.

```cpp
// example2.h
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp
#pragma once
#include <stdio.h>

class Example2 {
public:
   inline void inline_call() {
      printf("inline_call was called.\n");
   }
   void normal_call();
   Example2() {};
};
```

```cpp
// example2.cpp
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp
#include "example2.h"

void Example2::normal_call() {
   printf("normal_call was called.\n");
   inline_call();
}
```

```cpp
// zcinline2.cpp
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp
#include "example2.h"

void main() {
   Example2 example2;
   example2.inline_call(); // normal call when definition unavailable
}
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **idioma** página de propriedades.

1. Modificar a **remover dados e código não referenciado** propriedade e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
