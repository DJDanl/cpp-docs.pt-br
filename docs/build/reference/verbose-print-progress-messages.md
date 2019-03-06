---
title: /VERBOSE (imprimir mensagens de progresso)
ms.date: 11/04/2016
f1_keywords:
- /verbose
- VC.Project.VCLinkerTool.ShowProgress
helpviewer_keywords:
- -VERBOSE linker option
- linking [C++], session progress information
- Print Progress Messages linker option
- linker [C++], output dependency information
- /VERBOSE linker option
- dependencies [C++], dependency information in linker output
- VERBOSE linker option
ms.assetid: 9c347d98-4c37-4724-a39e-0983934693ab
ms.openlocfilehash: 290d2e5c5c5a87042ee805cdaed90cce4418a389
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423742"
---
# <a name="verbose-print-progress-messages"></a>/VERBOSE (imprimir mensagens de progresso)

```
/VERBOSE[:{ICF|INCR|LIB|REF|SAFESEH|UNUSEDLIBS}]
```

## <a name="remarks"></a>Comentários

O vinculador envia informações sobre o progresso da sessão de vinculação para o **saída** janela. Na linha de comando, as informações são enviadas para a saída padrão e podem ser redirecionadas para um arquivo.

|Opção|Descrição|
|------------|-----------------|
|/VERBOSE|Exibe detalhes sobre o processo de vinculação.|
|/VERBOSE:ICF|Exibir informações sobre a atividade do vinculador que resulta do uso de [/OPT: ICF](../../build/reference/opt-optimizations.md).|
|/VERBOSE:INCR|Exibe informações sobre o processo de vinculação incremental.|
|/VERBOSE:LIB|Exibe mensagens de progresso que indicam apenas as bibliotecas pesquisadas.<br /><br /> As informações exibidas inclui o processo de pesquisa de biblioteca e lista cada nome de biblioteca e objeto (com o caminho completo), o símbolo que está sendo resolvido da biblioteca e uma lista de objetos que referenciam o símbolo.|
|/VERBOSE:REF|Exibe informações sobre a atividade do vinculador que resulta do uso de [/OPT: REF](../../build/reference/opt-optimizations.md).|
|/VERBOSE:SAFESEH|Exibe informações sobre os módulos que não são compatíveis com tratamento processamento de exceção segura [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md) não for especificado.|
|/VERBOSE:UNUSEDLIBS|Exibe informações sobre quaisquer arquivos de biblioteca que são usados quando a imagem é criada.|

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Expanda o **vinculador** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Adicione a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ShowProgress%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
