---
title: /MANIFESTDEPENDENCY (especificar dependências de manifesto)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.AdditionalManifestDependencies
helpviewer_keywords:
- MANIFESTDEPENDENCY linker option
- /MANIFESTDEPENDENCY linker option
- -MANIFESTDEPENDENCY linker option
ms.assetid: e4b68313-33a2-4c3e-908e-ac2b9f7d6a73
ms.openlocfilehash: 43239efe70cc555d1a7e03c5d67e99e40ccd480e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492705"
---
# <a name="manifestdependency-specify-manifest-dependencies"></a>/MANIFESTDEPENDENCY (especificar dependências de manifesto)

```
/MANIFESTDEPENDENCY:manifest_dependency
```

## <a name="remarks"></a>Comentários

/MANIFESTDEPENDENCY permite especificar atributos que serão colocados na \<seção > de dependência do arquivo de manifesto.

Consulte [/manifest (criar manifesto do assembly lado a lado)](manifest-create-side-by-side-assembly-manifest.md) para obter informações sobre como criar um arquivo de manifesto.

Para obter mais informações sobre \<a seção > de dependência do arquivo de manifesto, consulte [arquivos de configuração](/windows/win32/SbsCs/publisher-configuration-files)do Publicador.

As informações do/MANIFESTDEPENDENCY podem ser passadas para o vinculador de uma das duas maneiras:

- Diretamente na linha de comando (ou em um arquivo de resposta) com/MANIFESTDEPENDENCY.

- Por meio do [Comentário](../../preprocessor/comment-c-cpp.md) pragma.

O exemplo a seguir mostra um comentário/MANIFESTDEPENDENCY passado por meio de pragma,

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

Os mesmos comentários do/MANIFESTDEPENDENCY podem ser passados na linha de comando da seguinte maneira:

```cmd
"/manifestdependency:type='Win32' name='Test.Research.SampleAssembly' version='6.0.0.0' processorArchitecture='X86' publicKeyToken='0000000000000000' language='*'\"
```

O vinculador coletará comentários do/MANIFESTDEPENDENCY, eliminará entradas duplicadas e, em seguida, adicionará a cadeia de caracteres XML resultante ao arquivo de manifesto.  Se o vinculador encontrar entradas conflitantes, o arquivo de manifesto será corrompido e o aplicativo não será iniciado (uma entrada poderá ser adicionada ao log de eventos, indicando a origem da falha).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de Propriedade do**arquivo de manifesto** do**vinculador** > de **Propriedades** > de configuração.

1. Modifique a propriedade **adicional dependências de manifesto** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalManifestDependencies%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
