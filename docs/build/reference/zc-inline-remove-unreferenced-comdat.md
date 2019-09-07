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
ms.openlocfilehash: f0c0d9a4e5e5f52d239f1a8591006b3d9e369778
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740105"
---
# <a name="zcinline-remove-unreferenced-comdat"></a>/Zc:inline (remover COMDAT não referenciado)

Remove funções não referenciadas ou dados que sejam COMDATs ou que tenham apenas vínculo interno. Quando **/Zc: inline** é especificado, o compilador exige que as unidades de tradução que usam dados embutidos ou funções embutidas também devem incluir as definições para os dados ou funções.

## <a name="syntax"></a>Sintaxe

> **/Zc:inline**[ **-** ]

## <a name="remarks"></a>Comentários

Quando **/Zc: inline** é especificado, o compilador não emite informações de símbolo para funções ou dados COMDAT não referenciados ou para funções ou dados que têm somente vínculo interno. Essa otimização simplifica parte do trabalho executado pelo vinculador em builds de versão ou quando a opção de vinculador [/OPT: REF](opt-optimizations.md) é especificada. Ao realizar essa otimização, o compilador pode reduzir significativamente o tamanho do arquivo .obj e aumentar as velocidades do vinculador. Essa opção de compilador não é habilitada quando as otimizações estão desabilitadas ([/OD](od-disable-debug.md)) ou quando [/GL (otimização do programa inteiro)](gl-whole-program-optimization.md) é especificada.

Por padrão, essa opção está desativada ( **/Zc: inline-** ) em compilações de linha de comando. A opção [/permissive-](permissive-standards-conformance.md) não habilita **/Zc: inline**. Em projetos do MSBuild, a opção é definida pelas **Propriedades** > de configuração**CC++/**  > **Language** > **remover código não referenciado e** propriedade de dados, que é definida como **Sim** por os.

Se **/Zc: inline** for especificado, o compilador aplicará o requisito do c++ 11 que todas as funções `inline` declaradas deverão ter uma definição disponível na mesma unidade de tradução se forem usadas. Quando a opção não é especificada, o compilador da Microsoft permite o código não compatível que invoca funções declaradas `inline` mesmo que nenhuma definição esteja visível. Para obter mais informações, consulte o padrão do C++11, nas seções 3.2 e 7.1.2. Essa opção do compilador foi introduzida no Visual Studio 2013 Atualização 2.

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

void main() {
   Example example;
   example.inline_call(); // normal call when definition unavailable
}
```

Quando **/Zc: inline** está habilitado, o mesmo código causa um erro [LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md) , pois o compilador não emite um corpo de código não embutido para `Example::inline_call` , no exemplo. obj. Isso faz a chamada não embutida em `main` mencionar um símbolo externo indefinido.

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

Para obter mais informações sobre problemas de conformidade C++no Visual, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de **Propriedades** >  > configuração**C/C++** **idioma** .

1. Modifique a propriedade **remover código e dados não referenciados** e escolha **OK**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
