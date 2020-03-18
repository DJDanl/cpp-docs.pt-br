---
title: /GL (otimização de todo o programa)
ms.date: 11/04/2016
f1_keywords:
- /gl
helpviewer_keywords:
- /GL compiler option [C++]
- whole program optimizations and C++ compiler
- -GL compiler option [C++]
- GL compiler option [C++]
ms.assetid: 09d51e2d-9728-4bd0-b5dc-3b8284aca1d1
ms.openlocfilehash: 875865a32dcb80cb8a6d8fa53646260f3d9413a5
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439659"
---
# <a name="gl-whole-program-optimization"></a>/GL (otimização de todo o programa)

Habilita a otimização de todo o programa.

## <a name="syntax"></a>Sintaxe

```
/GL[-]
```

## <a name="remarks"></a>Comentários

A otimização completa do programa permite que o compilador execute otimizações com informações sobre todos os módulos do programa. Sem a otimização completa do programa, as otimizações são executadas em uma base por módulo (compiland).

A otimização completa do programa é desativada por padrão e deve ser habilitada explicitamente. No entanto, também é possível desabilitá-lo explicitamente com **/GL-** .

Com informações sobre todos os módulos, o compilador pode:

- Otimizar o uso de registros entre limites de função.

- Realize um trabalho melhor de controle de modificações em dados globais, permitindo uma redução no número de cargas e armazenamentos.

- Realize um trabalho melhor de controlar o possível conjunto de itens modificados por uma desreferência de ponteiro, reduzindo os números de cargas e armazenamentos.

- Embutir uma função em um módulo, mesmo quando a função é definida em outro módulo.

os arquivos. obj produzidos com o **/GL** não estarão disponíveis para esses utilitários vinculadores como [EDITBIN](editbin-reference.md) e [DUMPBIN](dumpbin-reference.md).

Se você compilar seu programa com **/GL** e [/c](c-compile-without-linking.md), deverá usar a opção de vinculador/LTCG para criar o arquivo de saída.

[/Zi](z7-zi-zi-debug-information-format.md) não pode ser usado com **/GL**

O formato dos arquivos produzidos com **/GL** na versão atual pode não ser legível por versões subsequentes do Visual C++. Você não deve enviar um arquivo. lib composto por arquivos. obj que foram produzidos com **/GL** , a menos que você esteja disposto a enviar cópias do arquivo. lib para todas as versões C++ do Visual que espera que os usuários usem, agora e no futuro.

arquivos. obj produzidos com **/GL** e arquivos de cabeçalho pré-compilados não devem ser usados para criar um arquivo. lib, a menos que o arquivo. lib seja vinculado no mesmo computador que produziu o arquivo **/GL** . obj. As informações do arquivo de cabeçalho pré-compilado do arquivo. obj serão necessárias no momento do link.

Para obter mais informações sobre as otimizações disponíveis com o e as limitações da otimização completa do programa, consulte [/LTCG](ltcg-link-time-code-generation.md).  **/GL** também torna a otimização guiada por perfil disponível; consulte/LTCG.  Ao compilar para otimizações guiadas por perfil e se você quiser ordenação de função de suas otimizações guiadas por perfil, você deve compilar com [/GY](gy-enable-function-level-linking.md) ou uma opção de compilador que implica/GY.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Consulte [/LTCG (geração de código de tempo de vinculação)](ltcg-link-time-code-generation.md) para obter informações sobre como especificar **/GL** no ambiente de desenvolvimento.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WholeProgramOptimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
