---
title: /PROFILE (criador de perfil das ferramentas de desempenho)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.Profile
helpviewer_keywords:
- -PROFILE linker option
- /PROFILE linker option
ms.assetid: e676baa1-5063-47a3-a357-ba0d1f0d1699
ms.openlocfilehash: 23cbccba9a8ec839252d553cc5cbafd37e66bbf9
ms.sourcegitcommit: 14b292596bc9b9b883a9c58cd3e366b282a1f7b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2019
ms.locfileid: "60124766"
---
# <a name="profile-performance-tools-profiler"></a>/PROFILE (criador de perfil das ferramentas de desempenho)

Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho.

## <a name="syntax"></a>Sintaxe

```
/PROFILE
```

## <a name="remarks"></a>Comentários

/ PERFIL implica que as seguintes opções do vinculador:

- [/OPT:REF](opt-optimizations.md)

- /OPT:NOICF

- [/INCREMENTAL:NO](incremental-link-incrementally.md)

- [/FIXED:NO](fixed-fixed-base-address.md)

/ PERFIL faz com que o vinculador gerar uma seção de realocação na imagem do programa.  Uma seção de realocação permite que o criador de perfil transformar a imagem de programa para obter dados de perfil.

**/ PERFIL** só está disponível apenas nas versões Enterprise (desenvolvimento de equipe).  Para obter mais informações sobre o PREfast, consulte [análise de código para visão geral do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar a **perfil** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.Profile%2A>.

### <a name="to-set-this-linker-option-within-visual-studio-cmake-project"></a>Para definir essa opção de vinculador dentro do projeto do CMake do Visual Studio

**CMake** projeto não tem um **páginas de propriedade**, as opções de vinculador podem ser definidas pela modificação a cmakelists. txt.

1. Abra o cmakelists. txt no diretório raiz do projeto.

1. Adicione o código a seguir. Para obter detalhes, consulte [CMake referências](https://cmake.org/cmake/help/v3.0/command/set_target_properties.html)

1. Recompile sua solução.

```
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/PROFILE")
```

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)

