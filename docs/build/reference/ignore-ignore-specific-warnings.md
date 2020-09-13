---
title: /IGNORE (Ignorar os Avisos Específicos)
ms.date: 11/04/2016
f1_keywords:
- /OVERWRITE
helpviewer_keywords:
- /IGNORE linker option
ms.assetid: 37e77387-8838-4697-898f-d376ac641124
ms.openlocfilehash: 4ed87a1a12bea189f56545cf5256351a29977643
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040256"
---
# <a name="ignore-ignore-specific-warnings"></a>/IGNORE (Ignorar os Avisos Específicos)

```
/IGNORE:warning[,warning]
```

## <a name="parameters"></a>Parâmetros

*warning*<br/>
O número de avisos do vinculador para suprimir, no intervalo de 4000 a 4999.

## <a name="remarks"></a>Comentários

Por padrão, o LINK relata todos os avisos. Especifique **/ignore:** `warning` para instruir o vinculador a suprimir um número de aviso específico. Para ignorar diversos avisos, separe os números de aviso com vírgulas.

O vinculador não permite que alguns avisos sejam ignorados. Esta tabela lista os avisos que não são suprimidos por **/ignore**:

| Aviso do Vinculador | Mensagem |
|--------------------|-|
|LNK4017|A instrução `keyword` não é suportada para a plataforma de destino; ignorada|
|[LNK4044](../../error-messages/tool-errors/linker-tools-warning-lnk4044.md)|opção não reconhecida "`option`"; ignorada|
|LNK4062|' `option` ' não compatível com a `architecture` máquina de destino ' '; opção ignorada|
|[LNK4075](../../error-messages/tool-errors/linker-tools-warning-lnk4075.md)|Ignorando "`option1`" devido a especificação "`option2`"|
|[LNK4086](../../error-messages/tool-errors/linker-tools-warning-lnk4086.md)|O ponto de entrada "`function`" não é __stdcall com "`number`" bytes de argumentos; a imagem pode não ser executada|
|LNK4088|Imagem sendo gerada devido a opção /FORCE; a imagem pode não ser executada|
|[LNK4105](../../error-messages/tool-errors/linker-tools-warning-lnk4105.md)|nenhum argumento especificado com a opção "`option`"; ignorando o comutador|
|LNK4203|Erro ao ler o banco de dados do programa "`filename`"; vinculando objeto como se não houvesse informações de depuração|
|[LNK4204](../../error-messages/tool-errors/linker-tools-warning-lnk4204.md)|' `filename` ' não contém informações de depuração para o módulo de referência; vinculação de objeto quando sem informação de depuração|
|[LNK4205](../../error-messages/tool-errors/linker-tools-warning-lnk4205.md)|' `filename` ' não tem informações de depuração atuais para o módulo de referência; vinculação de objeto quando sem informação de depuração|
|[LNK4206](../../error-messages/tool-errors/linker-tools-warning-lnk4206.md)|As informações sobre o tipo pré-compilado não foram encontradas; "`filename`" não vinculado ou substituído; vinculando objeto como se não houvesse informações de depuração|
|LNK4207|' `filename` ' Compiled/YC/Yu/Z7; não é possível criar PDB; recompile com/Zi; vinculação de objeto quando sem informação de depuração|
|LNK4208|Formato de PDB incompatível no "`filename`"; excluir e recompilar; vinculando objeto como se não houvesse informações de depuração|
|LNK4209|depurando informações corrompidas; recompilar módulo; vinculando objeto como se não houvesse informações de depuração|
|[LNK4224](../../error-messages/tool-errors/linker-tools-warning-lnk4224.md)|`option` não é mais suportado; ignorado|
|LNK4228|' `option` ' inválido para uma DLL; ignorado|
|[LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)|Diretiva inválida /`directive` encontrada; ignorada|

Em geral, os avisos do vinculador que não podem ser ignorados representam falhas de compilação, erros de linha de comando ou erros de configuração que devem ser corrigidos.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Na pasta do **vinculador** , selecione a página de propriedades de **linha de comando** .

1. Modifique a propriedade **Opções adicionais** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.
