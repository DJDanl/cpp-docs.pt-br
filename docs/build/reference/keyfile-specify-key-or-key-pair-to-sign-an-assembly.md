---
title: -KEYFILE (especificar chave ou par de chaves para assinar um Assembly) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /keyfile
- VC.Project.VCLinkerTool.KeyFile
dev_langs:
- C++
helpviewer_keywords:
- /KEYFILE linker option
- -KEYFILE linker option
- KEYFILE linker option
ms.assetid: 9b71f8c0-541c-4fe5-a0c7-9364f42ecb06
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f43609e14d4e081f39c43cb8e548b8b6ac7923a1
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701268"
---
# <a name="keyfile-specify-key-or-key-pair-to-sign-an-assembly"></a>/KEYFILE (especificar chave ou par de chaves para assinar um assembly)

```
/KEYFILE:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
Arquivo que contém a chave. Coloque a cadeia de caracteres entre aspas duplas ("") se ele contiver um espaço.

## <a name="remarks"></a>Comentários

O vinculador insere a chave pública no manifesto do assembly e, em seguida, assina o assembly final com a chave privada. Para gerar um arquivo de chave, digite [sn -k](/dotnet/framework/tools/sn-exe-strong-name-tool) *filename* na linha de comando. Um assembly assinado é considerado como tendo um nome forte.

Se você compilar com [/LN](../../build/reference/ln-create-msil-module.md), o nome do arquivo de chave será mantido no módulo e incorporado no assembly que é criado quando você compila um assembly que inclui uma referência explícita para o módulo, por meio de [#using](../../preprocessor/hash-using-directive-cpp.md), ou ao vincular com [/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md).

Você também pode passar suas informações de criptografia para o vinculador com [/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md). Use [/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md) se você quiser um assembly parcialmente assinado. Ver [Assemblies de nome forte (assinatura de Assembly) (C + + / CLI)](../../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md) para obter mais informações sobre como assinar um assembly.

No caso de ambos **/KEYFILE** e **/KEYCONTAINER** são especificados (pela opção de linha de comando ou pelo atributo personalizado), o vinculador tentará primeiro o contêiner de chave. Se isso ocorrer, o assembly será assinado com as informações no contêiner de chaves. Se o vinculador não localizar o contêiner de chave, ele tentará o arquivo especificado com /keyfile. Se isso ocorrer, o assembly será assinado com as informações no arquivo de chave e as informações da chave serão instaladas no contêiner de chaves (semelhante a sn -i), de forma que, na próxima compilação, o contêiner de chaves será válido.

Observe que um arquivo de chave pode conter somente a chave pública.

Ver [criando e usando Assemblies nomes fortes](/dotnet/framework/app-domains/create-and-use-strong-named-assemblies) para obter mais informações sobre como assinar um assembly.

Outras opções de vinculador que afetam a geração de assembly são:

- [/ASSEMBLYDEBUG](../../build/reference/assemblydebug-add-debuggableattribute.md)

- [/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)

- [/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)

- [/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)

- [/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)