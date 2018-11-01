---
title: /Gm (habilitar recompilação manual)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.MinimalRebuild
- /Gm
- /FD
- VC.Project.VCCLWCECompilerTool.MinimalRebuild
helpviewer_keywords:
- /Gm compiler option [C++]
- minimal rebuild
- enable minimal rebuild compiler option [C++]
- Gm compiler option [C++]
- -Gm compiler option [C++]
ms.assetid: d8869ce0-d2ea-40eb-8dae-6d2cdb61dd59
ms.openlocfilehash: 2a5bc4008ab9376367b3a32040c2a4a70147187f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50570398"
---
# <a name="gm-enable-minimal-rebuild"></a>/Gm (habilitar recompilação manual)

Habilita recompilação mínima, que determina se os arquivos de origem C++ que incluem definições de classe C++ alteradas (armazenadas nos arquivos de cabeçalho (.h)) precisam ser recompilados.

## <a name="syntax"></a>Sintaxe

```
/Gm
```

## <a name="remarks"></a>Comentários

O compilador armazena as informações de dependência entre arquivos de origem e definições de classe no arquivo .idb do projeto durante a primeira compilação. (Informações sobre dependência dizem que arquivo de origem depende da definição de classe, e qual arquivo. h a definição está localizado em.) As compilações subsequentes usam as informações armazenadas no arquivo. IDB para determinar se um arquivo de origem precisa ser compilado, mesmo se ele inclui um arquivo. h modificado.

> [!NOTE]
>  A recompilação mínima conta com definições de classe que não mudem entre os arquivos incluídos. As definições de classe devem ser globais para um projeto (deve haver apenas uma definição de uma determinada classe), pois as informações de dependência no arquivo .idb são criadas para todo o projeto. Se você tiver mais de uma definição para uma classe no seu projeto, desabilite a recompilação mínima.

Como o vinculador incremental não oferece suporte a metadados do Windows incluídos em arquivos. obj usando a [/ZW (compilação de tempo de execução do Windows)](../../build/reference/zw-windows-runtime-compilation.md) opção, o **/Gm** opção é incompatível com  **/ZW**.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **geração de código** página de propriedades.

1. Modificar a **habilitar recompilação mínima** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.MinimalRebuild%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)