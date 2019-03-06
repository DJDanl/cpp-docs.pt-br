---
title: /ASSEMBLYLINKRESOURCE (Link para recurso do .NET Framework)
ms.date: 11/04/2016
f1_keywords:
- /ASSEMBLYLINKRESOURCE
- VC.Project.VCLinkerTool.AssemblyLinkResource
helpviewer_keywords:
- -ASSEMBLYLINKRESOURCE linker option
- ASSEMBLYLINKRESOURCE linker option
- /ASSEMBLYLINKRESOURCE linker option
ms.assetid: 8b6ad184-1b33-47a4-8513-4803cf915b64
ms.openlocfilehash: d2970f4e6d94cfa2e6315eeff85eb71a30dc032a
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422423"
---
# <a name="assemblylinkresource-link-to-net-framework-resource"></a>/ASSEMBLYLINKRESOURCE (Link para recurso do .NET Framework)

```
/ASSEMBLYLINKRESOURCE:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
O arquivo de recurso do .NET Framework ao qual você deseja vincular do assembly.

## <a name="remarks"></a>Comentários

A opção /ASSEMBLYLINKRESOURCE cria um link para um recurso do .NET Framework no arquivo de saída; o arquivo de recurso não é colocado no arquivo de saída. [/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md) insere um arquivo de recurso no arquivo de saída.

Recursos vinculados são públicos no assembly quando criado com a opção de vinculador.

/ASSEMBLYLINKRESOURCE requer que a compilação incluir [/clr](../../build/reference/clr-common-language-runtime-compilation.md); [/LN](../../build/reference/ln-create-msil-module.md) ou [/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md) não é permitido com /ASSEMBLYLINKRESOURCE.

Se *filename* é um arquivo de recursos do .NET Framework criado, por exemplo, por [Resgen.exe](/dotnet/framework/tools/resgen-exe-resource-file-generator) ou no ambiente de desenvolvimento, ele pode ser acessado com membros no **Resources** namespace. Para obter mais informações, consulte [System.Resources.ResourceManager](/dotnet/api/system.resources.resourcemanager). Para todos os outros recursos, use o **GetManifestResource** \* métodos de **Reflection** classe para acessar o recurso em tempo de execução.

*nome de arquivo* pode ser qualquer formato de arquivo. Por exemplo, você talvez queira fazer uma parte DLL nativa do assembly, para que possa ser instalado no Cache de Assembly Global e acessado no código gerenciado no assembly.

Outras opções de vinculador que afetam a geração de assembly são:

- [/ASSEMBLYDEBUG](../../build/reference/assemblydebug-add-debuggableattribute.md)

- [/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)

- [/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)

- [/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)

- [/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)

- [/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)

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
