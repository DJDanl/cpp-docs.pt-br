---
title: / POGOSAFEMODE (executar PGO no modo de segurança do thread)
ms.date: 03/14/2018
f1_keywords:
- POGOSAFEMODE
ms.openlocfilehash: bbb328bf67d7823305a43f1d61252747cf5ea29e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319714"
---
# <a name="pogosafemode-run-pgo-in-thread-safe-mode"></a>/ POGOSAFEMODE (executar PGO no modo de segurança do thread)

**A opção /POGOSAFEMODE foi preterida a partir do Visual Studio 2015**. Use o [/GENPROFILE: exata](genprofile-fastgenprofile-generate-profiling-instrumented-build.md) e **/GENPROFILE:NOEXACT** opções em vez disso. O **/POGOSAFEMODE** a opção de vinculador Especifica que o build instrumentado é criado para usar o modo thread-safe para captura de dados de perfil durante a Otimização Guiada por perfil (PGO) execuções de treinamento.

## <a name="syntax"></a>Sintaxe

> **/POGOSAFEMODE**

## <a name="remarks"></a>Comentários

Otimização Guiada por perfil (PGO) tem dois modos possíveis durante a fase de criação de perfil: *modo rápido* e *modo de segurança*. Quando a analise está no modo rápido, ele usa uma instrução de incremento para aumentar contadores de dados. A instrução de incremento é mais rápida, mas não é thread-safe. Quando a analise está no modo de segurança, ele usa a instrução de incremento interbloqueados para aumentar contadores de dados. Essa instrução tem a mesma funcionalidade, como a instrução de incremento tem e é thread-safe, mas é mais lento.

O **/POGOSAFEMODE** opção define a compilação instrumentada para usar o modo de segurança. Essa opção só pode ser usado quando preteridas [/LTCG:PGINSTRUMENT](ltcg-link-time-code-generation.md) for especificado, durante a fase de vinculador de instrumentação de PGO.

Por padrão, a criação de perfil de PGO opera no modo rápido. **/ POGOSAFEMODE** é necessário apenas se você deseja usar o modo de segurança.

Para executar a criação de perfil de PGO no modo de segurança, você deve usar **/GENPROFILE: exata** (preferencial), ou usar a variável de ambiente [PogoSafeMode](../environment-variables-for-profile-guided-optimizations.md) ou a opção de vinculador **/POGOSAFEMODE**, dependendo do sistema. Se você estiver executando a criação de perfil em um x64 computador, você deve usar a opção de vinculador. Se você estiver executando a criação de perfil em um x86 computador, você pode usar a opção de vinculador ou definir a variável de ambiente como qualquer valor antes de iniciar o processo de instrumentação de PGO.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. No **geração de código de tempo de vinculação** propriedade, escolha **Otimização Guiada por perfil - instrumento (/: pginstrument)**.

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira o **/POGOSAFEMODE** opção para o **opções adicionais** caixa. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/GENPROFILE e /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)<br/>
[/LTCG](ltcg-link-time-code-generation.md)<br/>
[Otimizações guiadas por perfil](../profile-guided-optimizations.md)<br/>
[Variáveis de ambiente para otimizações guiadas por perfil](../environment-variables-for-profile-guided-optimizations.md)<br/>
