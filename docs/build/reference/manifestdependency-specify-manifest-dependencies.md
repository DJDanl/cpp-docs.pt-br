---
title: -MANIFESTDEPENDENCY (especificar dependências de manifesto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.AdditionalManifestDependencies
dev_langs:
- C++
helpviewer_keywords:
- MANIFESTDEPENDENCY linker option
- /MANIFESTDEPENDENCY linker option
- -MANIFESTDEPENDENCY linker option
ms.assetid: e4b68313-33a2-4c3e-908e-ac2b9f7d6a73
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5b82bd32bec0e665f815563ccea2ee05f6ae5172
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315412"
---
# <a name="manifestdependency-specify-manifest-dependencies"></a>/MANIFESTDEPENDENCY (especificar dependências de manifesto)

```
/MANIFESTDEPENDENCY:manifest_dependency
```

## <a name="remarks"></a>Comentários

/MANIFESTDEPENDENCY permite especificar atributos que serão colocados no \<dependência > seção do arquivo de manifesto.

Ver [/MANIFEST (criar Side-by-Side manifesto do Assembly)](../../build/reference/manifest-create-side-by-side-assembly-manifest.md) para obter informações sobre como criar um arquivo de manifesto.

Para obter mais informações sobre o \<dependência > seção do arquivo de manifesto, consulte [arquivos de configuração de publicador](/windows/desktop/SbsCs/publisher-configuration-files).

Informações de /MANIFESTDEPENDENCY podem ser passadas para o vinculador em uma das duas maneiras:

- Diretamente na linha de comando (ou em um arquivo de resposta) com /MANIFESTDEPENDENCY.

- Por meio de [comentário](../../preprocessor/comment-c-cpp.md) pragma.

O exemplo a seguir mostra um comentário /MANIFESTDEPENDENCY passado por meio do pragma,

```cpp
#pragma comment(linker, "\"/manifestdependency:type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*'\"")
```

que resulta na seguinte entrada no arquivo de manifesto:

```xml
<dependency>
  <dependentAssembly>
    <assemblyIdentity type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*' />
  </dependentAssembly>
</dependency>
```

Os mesmos comentários /MANIFESTDEPENDENCY podem ser passados na linha de comando da seguinte maneira:

```cmd
"/manifestdependency:type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*'\"
```

O vinculador coletar comentários /MANIFESTDEPENDENCY, eliminar entradas duplicadas e, em seguida, adicione a cadeia de caracteres XML resultante para o arquivo de manifesto.  Se o vinculador localiza entradas conflitantes, o arquivo de manifesto serão corrompidos e o aplicativo falhará ao iniciar (uma entrada pode ser adicionada ao log de eventos, que indica a origem da falha).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **o arquivo de manifesto** página de propriedades.

1. Modificar a **dependências de manifesto adicionais** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalManifestDependencies%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)