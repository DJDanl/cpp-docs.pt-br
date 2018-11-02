---
title: /LN (criar módulo MSIL)
ms.date: 11/04/2016
f1_keywords:
- /LN
helpviewer_keywords:
- -LN compiler option [C++]
- /LN compiler option [C++]
ms.assetid: 4f38f4f4-3176-4caf-8200-5c7585dc1ed3
ms.openlocfilehash: d8253dacbfa57f84a3eee05ffa0f8f9879f6b009
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536923"
---
# <a name="ln-create-msil-module"></a>/LN (criar módulo MSIL)

Especifica que um manifesto do assembly não deve ser inserido no arquivo de saída.

## <a name="syntax"></a>Sintaxe

```
/LN
```

## <a name="remarks"></a>Comentários

Por padrão, **/LN** não está em vigor (um manifesto do assembly é inserido no arquivo de saída).

Quando **/LN** for usado, um dos [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) opções também devem ser usadas.

É chamado de um programa gerenciado que não tem um assembly de metadados no manifesto do módulo. Se você compilar com [/c (compilar sem vinculação)](../../build/reference/c-compile-without-linking.md) e **/LN**, especifique [/NOASSEMBLY (criar um módulo de MSIL)](../../build/reference/noassembly-create-a-msil-module.md) na fase de vinculador para criar o arquivo de saída.

Você talvez queira criar módulos para adotar uma abordagem baseada em componente criação de assemblies.  Ou seja, você pode criar tipos e compilá-los em módulos.  Em seguida, você pode gerar um assembly de um ou mais módulos.  Para obter mais informações sobre como criar assemblies de módulos, consulte [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md) ou [Al.exe (Assembly Linker)](/dotnet/framework/tools/al-exe-assembly-linker).

A extensão de arquivo padrão para um módulo é. netmodule.

Em versões do Visual C++ antes do Visual C++ 2005, um módulo foi criado com **/clr:noAssembly**.

O vinculador do Visual C++ aceita arquivos. netmodule como entrada e o arquivo de saída produzido pelo vinculador será um assembly ou. netmodule com nenhuma dependência de tempo de execução em qualquer um dos netmodules que eram de entrada para o vinculador.  Para obter mais informações, consulte [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

- Especificar [/NOASSEMBLY (criar um módulo de MSIL)](../../build/reference/noassembly-create-a-msil-module.md) na fase de vinculador para criar o arquivo de saída.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Essa opção do compilador não pode ser alterada programaticamente.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)