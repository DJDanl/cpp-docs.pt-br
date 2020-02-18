---
title: /PROFILE (criador de perfil das ferramentas de desempenho)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.Profile
helpviewer_keywords:
- -PROFILE linker option
- /PROFILE linker option
ms.assetid: e676baa1-5063-47a3-a357-ba0d1f0d1699
ms.openlocfilehash: 678816ce455d2a982ff8218becd805a0b2cdd896
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77416040"
---
# <a name="profile-performance-tools-profiler"></a>/PROFILE (criador de perfil das ferramentas de desempenho)

Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho.

## <a name="syntax"></a>Sintaxe

```
/PROFILE
```

## <a name="remarks"></a>Comentários

/PROFILE implica nas seguintes opções de vinculador:

- [/OPT: REF](opt-optimizations.md)

- /OPT: NOICF

- [/INCREMENTAL: NÃO](incremental-link-incrementally.md)

- [/FIXED: NÃO](fixed-fixed-base-address.md)

/PROFILE faz com que o vinculador gere uma seção de realocação na imagem do programa.  Uma seção de realocação permite que o profiler transforme a imagem do programa para obter dados de perfil.

**/Profile** só está disponível em versões empresariais (desenvolvimento de equipe).  Para obter mais informações sobre o PREfast, consulte [análise de códigoC++ para C/visão geral](/cpp/code-quality/code-analysis-for-c-cpp-overview).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o nó **Vinculador**.

1. Selecione a página de propriedades **Avançado**.

1. Modifique a propriedade do **perfil** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.Profile%2A>.

### <a name="to-set-this-linker-option-within-visual-studio-cmake-project"></a>Para definir essa opção de vinculador no projeto CMake do Visual Studio

O projeto **CMake** não tem **páginas de propriedades**, as opções do vinculador podem ser definidas modificando o CMakeLists. txt.

1. Abra o CMakeLists. txt no diretório raiz do projeto.

1. Adicione o código abaixo. Para obter detalhes, consulte [referências de CMake](https://cmake.org/cmake/help/v3.0/command/set_target_properties.html)

1. Recompile a solução.

```
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/PROFILE")
```

## <a name="see-also"></a>Consulte Também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)

