---
title: /USEPROFILE (dados de uso PGO com /ltcg)
ms.date: 03/14/2018
f1_keywords:
- USEPROFILE
ms.openlocfilehash: 7bc0033ae5ef512cbd2e2063c5cb9bd9b061c180
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816523"
---
# <a name="useprofile-run-pgo-in-thread-safe-mode"></a>/USEPROFILE (executar PGO no modo de segurança do thread)

Essa opção de vinculador junto com [/LTCG (geração de código Link-time](ltcg-link-time-code-generation.md) informa o vinculador para compilar usando dados de treinamento de Otimização Guiada por perfil (PGO).

## <a name="syntax"></a>Sintaxe

> **/USEPROFILE**[**:**{**AGGRESSIVE**|**PGD=**_filename_}]

### <a name="arguments"></a>Arguments

**AGGRESSIVE**<br/>
Esse argumento opcional especifica que as otimizações de velocidade agressiva devem ser usadas durante a geração de código otimizado.

**PGD**=*filename*<br/>
Especifica um nome de arquivo de base para o arquivo. PGD. Por padrão, o vinculador usa o nome do arquivo executável base com uma extensão. PGD.

## <a name="remarks"></a>Comentários

O **/USEPROFILE** opção de vinculador é usada junto com **/LTCG** para gerar ou atualizar uma compilação otimizada com base nos dados de treinamento de PGO. É o equivalente do preteridas **/LTCG:PGUPDATE** e **/LTCG:PGOPTIMIZE** opções.

Opcional **AGRESSIVA** argumento desabilita relacionadas ao tamanho heurística para tentar otimizar a velocidade. Isso pode resultar em otimizações que substancialmente aumentam o tamanho de seu executável e não podem aumentar a velocidade resultante. Você deve criar o perfil e comparar os resultados do uso e não usando **AGRESSIVA**. Esse argumento deve ser especificado explicitamente. ele não está habilitado por padrão.

O **PGD** argumento especifica um nome opcional para o arquivo de PGD de dados de treinamento usar as mesmas que na [/GENPROFILE ou /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md). É o equivalente do preteridas **/PGD.** alternar. Por padrão, ou se nenhum *filename* for especificado, um arquivo. PGD que tem o mesmo nome base como o executável é usado.

O **/USEPROFILE** a opção de vinculador é nova no Visual Studio 2015.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. No **geração de código de tempo de vinculação** propriedade, escolha **Use geração de código de tempo de vinculação (/ LTCG)**.

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/USEPROFILE** opção e argumentos opcionais para o **opções adicionais** caixa. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/GENPROFILE e /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/LTCG](ltcg-link-time-code-generation.md)<br/>
[Otimizações guiadas por perfil](../profile-guided-optimizations.md)<br/>
[Variáveis de ambiente para otimizações guiadas por perfil](../environment-variables-for-profile-guided-optimizations.md)<br/>
