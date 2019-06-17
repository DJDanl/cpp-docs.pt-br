---
title: /VERBOSE (imprimir mensagens de progresso)
ms.date: 06/13/2019
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
ms.openlocfilehash: bbf7b5966c741535f26202979cbfd71f839cc537
ms.sourcegitcommit: e79188287189b76b34eb7e8fb1bfe646bdb586bc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/14/2019
ms.locfileid: "67141662"
---
# <a name="verbose-print-progress-messages"></a>/VERBOSE (imprimir mensagens de progresso)

Produz mensagens de progresso durante o processo de link.

## <a name="syntax"></a>Sintaxe

> **/VERBOSE**\[ **:** {**CLR**|**ICF**|**INCR**|**LIB**|**REF**|**SAFESEH**|**UNUSEDDELAYLOAD**|**UNUSEDLIBS**}\]

## <a name="remarks"></a>Comentários

O vinculador envia informações sobre o progresso da sessão de vinculação para o **saída** janela. Na linha de comando, as informações são enviadas para a saída padrão em podem ser redirecionadas para um arquivo.

| Opção | Descrição |
| ------------ | ----------------- |
| /VERBOSE | Exibe detalhes sobre o processo de vinculação. |
| /VERBOSE: CLR | Exibe informações sobre a atividade do vinculador específica para objetos e metadados compilado usando [/clr](clr-common-language-runtime-compilation.md). |
| /VERBOSE:ICF | Exibe informações sobre a atividade do vinculador que resulta do uso de [/OPT: ICF](opt-optimizations.md). |
| /VERBOSE:INCR | Exibe informações sobre o processo de vinculação incremental. |
| /VERBOSE:LIB | Exibe mensagens de progresso que indicam apenas as bibliotecas pesquisadas.<br/> As informações exibidas incluem o processo de pesquisa de biblioteca. Ele lista cada nome de biblioteca e objeto (com o caminho completo), o símbolo sendo resolvido da biblioteca e uma lista de objetos que referenciam o símbolo. |
| /VERBOSE:REF | Exibe informações sobre a atividade do vinculador que resulta do uso de [/OPT: REF](opt-optimizations.md). |
| /VERBOSE:SAFESEH | Exibe informações sobre os módulos que são incompatíveis com tratamento quando de exceções estruturado segura [/SAFESEH](safeseh-image-has-safe-exception-handlers.md) não for especificado. |
| /VERBOSE:UNUSEDDELAYLOAD | Exibe informações sobre qualquer atraso DLLs carregadas que não tenham nenhum símbolo usado quando a imagem é criada. |
| /VERBOSE:UNUSEDLIBS | Exibe informações sobre quaisquer arquivos de biblioteca que são usados quando a imagem é criada. |

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Adicione a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ShowProgress%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
