---
title: /ASSEMBLYMODULE (adicionar um módulo MSIL ao assembly)
ms.date: 11/04/2016
f1_keywords:
- /assemblymodule
- VC.Project.VCLinkerTool.AddModuleNamesToAssembly
helpviewer_keywords:
- ASSEMBLYMODULE linker option
- assemblies [C++], adding modules to
- assemblies [C++]
- /ASSEMBLYMODULE linker option
- -ASSEMBLYMODULE linker option
ms.assetid: 67357da8-e4b6-49fd-932c-329a5777f143
ms.openlocfilehash: 728e8a84ff8d1afac99f99dbb975c7fd9360bcc1
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57815249"
---
# <a name="assemblymodule-add-a-msil-module-to-the-assembly"></a>/ASSEMBLYMODULE (adicionar um módulo MSIL ao assembly)

```
/ASSEMBLYMODULE:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
O módulo que você deseja incluir neste assembly.

## <a name="remarks"></a>Comentários

A opção /ASSEMBLYMODULE permite que você adicione uma referência a um assembly de módulo. Informações de tipo no módulo não estará disponíveis para o programa assembly que adicionou a referência de módulo. No entanto, as informações de tipo no módulo estará disponíveis para qualquer programa que faz referência ao assembly.

Use [#using](../../preprocessor/hash-using-directive-cpp.md) para adicionar uma referência a um assembly de módulo e disponibilizar informações de tipo do módulo para o programa de assembly.

Por exemplo, considere o seguinte cenário:

1. Criar um módulo com [/LN](ln-create-msil-module.md).

1. Use /ASSEMBLYMODULE em um projeto diferente para incluir o módulo na compilação atual, que criará um assembly. Este projeto não fará referência para o módulo com `#using`.

1. Qualquer projeto que faz referência a esse assembly agora também pode usar tipos do módulo.

Outras opções de vinculador que afetam a geração de assembly são:

- [/ASSEMBLYDEBUG](assemblydebug-add-debuggableattribute.md)

- [/ASSEMBLYLINKRESOURCE](assemblylinkresource-link-to-dotnet-framework-resource.md)

- [/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md)

- [/DELAYSIGN](delaysign-partially-sign-an-assembly.md)

- [/NOASSEMBLY](noassembly-create-a-msil-module.md)

- [/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)

- [/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md)

O vinculador MSVC aceita arquivos. netmodule como entrada e o arquivo de saída produzido pelo vinculador será um assembly ou. netmodule com nenhuma dependência de tempo de execução em qualquer um dos netmodules que eram de entrada para o vinculador.  Para obter mais informações, consulte [arquivos. netmodule como entrada de vinculador](netmodule-files-as-linker-input.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **entrada** página de propriedades.

1. Modificar a **Adicionar módulo ao Assembly** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AddModuleNamesToAssembly%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
