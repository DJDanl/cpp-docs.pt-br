---
title: /Zc:inline (remover COMDAT não referenciado)
ms.date: 09/05/2019
f1_keywords:
- /Zc:inline
- VC.Project.VCCLCompilerTool.RemoveUnreferencedCodeData
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Zc compiler options (C++)
- /Zc:inline
ms.assetid: a4c94224-1d73-4bea-a9d5-4fa73dc924df
ms.openlocfilehash: 290252262254521c024d7b0d6355472199d1f55d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218956"
---
# <a name="zcinline-remove-unreferenced-comdat"></a>/Zc:inline (remover COMDAT não referenciado)

Remove dados ou funções não referenciadas que são COMDATs ou que só têm vínculo interno. Em **/Zc: inline**, o compilador Especifica que as unidades de tradução com dados embutidos ou funções também devem incluir suas definições.

## <a name="syntax"></a>Sintaxe

> **/Zc: embutido**[ **-** ]

## <a name="remarks"></a>Comentários

Quando **/Zc: inline** é especificado, o compilador não emite informações de símbolo para funções ou dados COMDAT não referenciados. Ou, para dados ou funções que têm somente vínculo interno. Essa otimização simplifica parte do trabalho que o vinculador faz em compilações de versão ou quando você especifica a opção de vinculador [/OPT: REF](opt-optimizations.md) . Essa otimização do compilador pode reduzir significativamente o tamanho do arquivo. obj e melhorar as velocidades do vinculador. A opção do compilador não é habilitada quando você desabilita otimizações ([/OD](od-disable-debug.md)). Ou, quando você especifica [/GL (otimização do programa inteiro)](gl-whole-program-optimization.md).

Por padrão, essa opção está desativada (**/Zc: inline-**) em compilações de linha de comando. A opção [/permissive-](permissive-standards-conformance.md) não habilita **/Zc: inline**. Em projetos do MSBuild, a opção é definida pelas **Propriedades de configuração**  >  linguagem**C/C++**  >  **Language**  >  **remover código não referenciado e** propriedade de dados, que é definida como **Sim** por padrão.

Se **/Zc: inline** for especificado, o compilador aplicará o requisito do c++ 11 que todas as funções declaradas **`inline`** deverão ter uma definição disponível na mesma unidade de tradução se forem usadas. Quando a opção não é especificada, o compilador da Microsoft permite o código não compatível que invoca funções declaradas **`inline`** mesmo que nenhuma definição esteja visível. Para obter mais informações, consulte o padrão do C++11, nas seções 3.2 e 7.1.2. Essa opção do compilador foi introduzida no Visual Studio 2013 Atualização 2.

Para usar a opção **/Zc: inline** , atualize o código sem conformidade.

Este exemplo mostra como o uso não compatível de uma declaração de função embutida sem uma definição ainda é compilado e links quando a opção **/Zc: inline** padrão é usada:

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

int main() {
   Example example;
   example.inline_call(); // normal call when definition unavailable
}
```

Quando **/Zc: inline** está habilitado, o mesmo código causa um erro [LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md) , pois o compilador não emite um corpo de código não embutido para, `Example::inline_call` no exemplo. obj. Isso faz com que a chamada não embutida em `main` para referenciar um símbolo externo indefinido.

Para resolver esse erro, você pode remover a **`inline`** palavra-chave da declaração de `Example::inline_call` , mover a definição de `Example::inline_call` para o arquivo de cabeçalho ou mover a implementação de `Example` para Main. cpp. O próximo exemplo move a definição para o arquivo de cabeçalho, onde ele permanece visível para qualquer chamador com o cabeçalho.

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

int main() {
   Example2 example2;
   example2.inline_call(); // normal call when definition unavailable
}
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**página de propriedades de  >  **linguagem C/C++** Properties  >  **Language** .

1. Modifique a propriedade **remover código e dados não referenciados** e escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)<br/>
