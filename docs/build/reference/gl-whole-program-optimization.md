---
title: /GL (otimização de todo o programa)
ms.date: 11/04/2016
f1_keywords:
- /gl
- VC.Project.VCCLWCECompilerTool.WholeProgramOptimization
helpviewer_keywords:
- /GL compiler option [C++]
- whole program optimizations and C++ compiler
- -GL compiler option [C++]
- GL compiler option [C++]
ms.assetid: 09d51e2d-9728-4bd0-b5dc-3b8284aca1d1
ms.openlocfilehash: 6251209dac74a504bb0635f0c544c39935090a42
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292127"
---
# <a name="gl-whole-program-optimization"></a>/GL (otimização de todo o programa)

Habilita a otimização de todo o programa.

## <a name="syntax"></a>Sintaxe

```
/GL[-]
```

## <a name="remarks"></a>Comentários

Otimização de todo o programa permite que o compilador execute otimizações com informações sobre todos os módulos no programa. Sem otimização de todo o programa, as otimizações são executadas em uma base de módulo (compiland).

Otimização de todo o programa está desativado por padrão e deve ser habilitada explicitamente. No entanto, também é possível desabilitá-la com explicitamente **/GL-**.

Com informações sobre todos os módulos, o compilador pode:

- Otimize o uso de registros entre limites de função.

- Fazer um trabalho melhor de controlar as modificações de dados globais, permitindo uma redução no número de cargas e armazenamentos.

- Fazer um trabalho melhor de desreferenciar o possível conjunto de itens modificados por um ponteiro, reduzindo o número de cargas e armazenamentos de acompanhamento.

- Embutir uma função em um módulo, mesmo quando a função é definida em outro módulo.

arquivos. obj produzido com **/GL** não estarão disponíveis para esses utilitários do vinculador como [EDITBIN](editbin-reference.md) e [DUMPBIN](dumpbin-reference.md).

Se você compilar seu programa com **/GL** e [/c](c-compile-without-linking.md), você deve usar a opção de vinculador /LTCG para criar o arquivo de saída.

[/Zi](z7-zi-zi-debug-information-format.md) não pode ser usado com **/GL**

O formato dos arquivos produzidos com **/GL** na versão atual podem não ser legíveis por versões subsequentes do Visual C++. Você não deve fornecer um arquivo. lib composto de arquivos. obj que foram gerados com **/GL** , a menos que você está disposto a enviar cópias do arquivo. lib para todas as versões do Visual C++ você espera que os usuários usem, agora e no futuro.

arquivos. obj produzido com **/GL** e arquivos de cabeçalho pré-compilado não devem ser usados para criar um arquivo. lib, a menos que o arquivo. lib será vinculado no mesmo computador que produziu o **/GL** arquivo. obj. Serão necessárias informações de arquivo de cabeçalho pré-compilado do arquivo. obj em tempo de vinculação.

Para obter mais informações sobre as otimizações disponíveis com e as limitações de otimização do programa completo, consulte [/LTCG](ltcg-link-time-code-generation.md).  **/GL** também o torna disponível de Otimização Guiada por perfil; consulte /LTCG.  Ao compilar para otimizações e se deseja que a função de ordenação de suas otimizações guiadas por perfil guiada por perfil, você deve compilar com [/Gy](gy-enable-function-level-linking.md) ou uma opção de compilador que implica /Gy.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Ver [/LTCG (geração de código Link-time)](ltcg-link-time-code-generation.md) para obter informações sobre como especificar **/GL** no ambiente de desenvolvimento.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WholeProgramOptimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
