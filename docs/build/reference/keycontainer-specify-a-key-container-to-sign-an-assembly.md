---
title: /KEYCONTAINER (especificar um contêiner de chave para assinar um assembly)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.KeyContainer
- /keycontainer
helpviewer_keywords:
- KEYCONTAINER linker option
- /KEYCONTAINER linker option
- -KEYCONTAINER linker option
ms.assetid: 94882d12-b77a-49c7-96d0-18a31aee001e
ms.openlocfilehash: 96d2f5fed0e450224f82ee909cea9d56082505fb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62291607"
---
# <a name="keycontainer-specify-a-key-container-to-sign-an-assembly"></a>/KEYCONTAINER (especificar um contêiner de chave para assinar um assembly)

```
/KEYCONTAINER:name
```

## <a name="arguments"></a>Arguments

*name*<br/>
Contêiner que contém a chave. Coloque a cadeia de caracteres entre aspas duplas ("") se ele contiver um espaço.

## <a name="remarks"></a>Comentários

O vinculador cria um assembly assinado, inserindo uma chave pública no manifesto do assembly e assinando o assembly definitivo com a chave privada. Para gerar um arquivo de chave, digite [sn -k](/dotnet/framework/tools/sn-exe-strong-name-tool) *filename* na linha de comando. **sn -i** instala o par de chaves no contêiner.

Se você compilar com [/LN](ln-create-msil-module.md), o nome do arquivo de chave será mantido no módulo e incorporado no assembly que é criado quando você compila um assembly que inclui uma referência explícita para o módulo, por meio de [#using](../../preprocessor/hash-using-directive-cpp.md), ou ao vincular com [/ASSEMBLYMODULE](assemblymodule-add-a-msil-module-to-the-assembly.md).

Você também pode passar suas informações de criptografia para o compilador com [/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md). Use [/DELAYSIGN](delaysign-partially-sign-an-assembly.md) se você quiser um assembly parcialmente assinado. Ver [Assemblies de nome forte (assinatura de Assembly) (C++/CLI)](../../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md) para obter mais informações sobre como assinar um assembly.

Outras opções de vinculador que afetam a geração de assembly são:

- [/ASSEMBLYDEBUG](assemblydebug-add-debuggableattribute.md)

- [/ASSEMBLYLINKRESOURCE](assemblylinkresource-link-to-dotnet-framework-resource.md)

- [/ASSEMBLYMODULE](assemblymodule-add-a-msil-module-to-the-assembly.md)

- [/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md)

- [/NOASSEMBLY](noassembly-create-a-msil-module.md)

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
