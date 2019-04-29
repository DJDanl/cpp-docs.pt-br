---
title: /DELAYSIGN (assinar parcialmente um assembly)
ms.date: 11/04/2016
f1_keywords:
- /delaysign
- VC.Project.VCLinkerTool.DelaySign
helpviewer_keywords:
- /DELAYSIGN linker option
- DELAYSIGN linker option
- -DELAYSIGN linker option
ms.assetid: 15244d30-3ecb-492f-a408-ffe81f38de20
ms.openlocfilehash: 65585b856627ad9fda5a8f8bfad6ad81fef0f81c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293830"
---
# <a name="delaysign-partially-sign-an-assembly"></a>/DELAYSIGN (assinar parcialmente um assembly)

```
/DELAYSIGN[:NO]
```

## <a name="arguments"></a>Arguments

**NÃO**<br/>
Especifica que o assembly não deve ser parcialmente assinado.

## <a name="remarks"></a>Comentários

Use **/DELAYSIGN** se você apenas deseja colocar a chave pública no assembly. O padrão é **/delaysign: no**.

O **/DELAYSIGN** opção não tem nenhum efeito a menos que usado com [/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) ou [/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md).

Quando você solicita um assembly totalmente assinado, o compilador usa o hash no arquivo que contém o manifesto (metadados de assembly) e sinaliza esse hash com a chave particular. A assinatura digital resultante é armazenada no arquivo que contém o manifesto. Quando um assembly é assinado com atraso, o vinculador computa e não armazena a assinatura, mas reserva espaço no arquivo para que a assinatura pode ser adicionada depois.

Por exemplo, usando **/DELAYSIGN** permite que um testador coloque o assembly no cache global. Após o teste, é possível assinar completamente o assembly, colocando a chave privada no assembly.

Ver [Assemblies de nome forte (assinatura de Assembly) (C++/CLI)](../../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md) e [Assinando um Assembly com atraso](/dotnet/framework/app-domains/delay-sign-assembly) para obter mais informações sobre como assinar um assembly.

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
